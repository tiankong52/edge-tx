/*
 * Copyright (C) EdgeTX
 *
 * Based on code named
 *   opentx - https://github.com/opentx/opentx
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "dsm2.h"
#include "hal/module_port.h"
#include "mixer_scheduler.h"

#include "opentx.h"

#define DSM2_SEND_BIND                     (1 << 7)
#define DSM2_SEND_RANGECHECK               (1 << 5)


// DSM2 control bits
#define DSM2_CHANS           6
#define FRANCE_BIT           0x10
#define DSMX_BIT             0x08
#define BAD_DATA             0x47

#define DSM2_BITRATE         125000

static void setupPulsesDSM2(uint8_t module, UartMultiPulses* uart)
{
  uint8_t dsmDat[14];

  switch (moduleState[module].protocol) {
    case PROTOCOL_CHANNELS_DSM2_LP45:
      dsmDat[0] = 0x00;
      break;
    case PROTOCOL_CHANNELS_DSM2_DSM2:
      dsmDat[0] = 0x10;
      break;
    default: // DSMX
      dsmDat[0] = 0x10 | DSMX_BIT;
      break;
  }

  if (moduleState[module].mode == MODULE_MODE_BIND) {
    dsmDat[0] |= DSM2_SEND_BIND;
  }
  else if (moduleState[module].mode == MODULE_MODE_RANGECHECK) {
    dsmDat[0] |= DSM2_SEND_RANGECHECK;
  }

  dsmDat[1] = g_model.header.modelId[module]; // DSM2 Header second byte for model match

  for (int i=0; i<DSM2_CHANS; i++) {
    int channel = g_model.moduleData[module].channelsStart+i;
    int value = channelOutputs[channel] + 2*PPM_CH_CENTER(channel) - 2*PPM_CENTER;
    uint16_t pulse = limit(0, ((value*13)>>5)+512, 1023);
    dsmDat[2+2*i] = (i<<2) | ((pulse>>8)&0x03);
    dsmDat[3+2*i] = pulse & 0xff;
  }

  for (int i=0; i<14; i++) {
    uart->sendByte(dsmDat[i]);
  }
}


#define DSMP_BITRATE 115200

static void setupPulsesLemonDSMP(uint8_t module, UartMultiPulses* uart)
{
  static uint8_t pass = 0;

  const auto& md = g_model.moduleData[module];

  uint8_t start_channel = md.channelsStart;
  auto channels = md.getChannelsCount();
  auto flags = md.dsmp.flags & 0x3F;

  // Force setup packet in Bind mode.
  auto module_mode = getModuleMode(module);

  uart->sendByte( 0xAA );
  uart->sendByte( pass );

  // Setup packet
  if (pass == 0) {

    if (module_mode == MODULE_MODE_BIND) {
      flags = DSM2_SEND_BIND | (1 << 6 /* AUTO */);
      channels = 12;
    }
    uart->sendByte( flags );

    uint8_t pwr = 7;
    if (module_mode == MODULE_MODE_RANGECHECK) {
      pwr = 4;
    }
    uart->sendByte( pwr );    
    uart->sendByte( channels );

    // Model number
    uart->sendByte( 1 );

    // Send only 1 single Setup packet
    pass = 1;

  } else {

    uint8_t current_channel = 0;
    if (pass == 2) {
      current_channel += 7;
    }

    // Send channels
    for (int i=0; i<7; i++) {

      if (current_channel < channels) {
        
        uint8_t channel = start_channel + current_channel;
        int value = channelOutputs[channel] + 2*PPM_CH_CENTER(channel) - 2*PPM_CENTER;
        uint16_t pulse;

        // Use 11-bit ?
        if (flags & (1 << 2)) {
          pulse = limit(0, ((value*349)>>9)+1024, 2047) | (current_channel << 11);
        } else {
          pulse = limit(0, ((value*13)>>5)+512, 1023) | (current_channel << 10);
        }

        uart->sendByte( pulse >> 8 );
        uart->sendByte( pulse & 0xFF );
      } else {
        // Outside of announced number of channels:
        // -> send invalid value
        uart->sendByte( 0xFF );
        uart->sendByte( 0xFF );
      }
      current_channel++;
    }
  }

  if (++pass > 2) pass = 1;
  if (channels < 8) pass = 1;

  if (module_mode == MODULE_MODE_BIND) {
    // bind packet is setup
    pass = 0;
  }
  else if (--moduleState[module].counter == 0) {
    // every 100th packet is setup
    pass = 0;
    moduleState[module].counter = 100;
  }
}

etx_serial_init dsmUartParams = {
    .baudrate = 0,
    .parity = ETX_Parity_None,
    .stop_bits = ETX_StopBits_One,
    .word_length = ETX_WordLength_8,
    .rx_enable = false,
};

static void* dsmInit(uint8_t module, uint32_t baudrate,  uint16_t period)
{
  // only external module supported
  if (module == INTERNAL_MODULE) return nullptr;

  etx_serial_init params(dsmUartParams);
  params.baudrate = baudrate;

  auto mod_st = modulePortInitSerial(module, ETX_MOD_PORT_EXTERNAL_SOFT_INV,
                                     ETX_MOD_DIR_TX, &params);

  extmodulePulsesData.multi.initFrame();
  mod_st->user_data = (void*)&extmodulePulsesData.multi;

  // TODO: check telemetry init...

  EXTERNAL_MODULE_ON();
  mixerSchedulerSetPeriod(module, period);

  return (void*)mod_st;
}

static void* dsm2Init(uint8_t module)
{
  return dsmInit(module, DSM2_BITRATE, DSM2_PERIOD);
}

static void* dsmpInit(uint8_t module)
{
  return dsmInit(module, DSMP_BITRATE, 11 * 1000 /* 11ms in us */);
}


static void dsmDeInit(void* ctx)
{
  auto mod_st = (etx_module_state_t*)ctx;
  auto module = modulePortGetModule(mod_st);

  EXTERNAL_MODULE_OFF();
  mixerSchedulerSetPeriod(module, 0);
  modulePortDeInit(mod_st);
}

static void _dsm_send(etx_module_state_t* st, UartMultiPulses* pulses)
{
  auto drv = modulePortGetSerialDrv(st->tx);
  auto ctx = modulePortGetCtx(st->tx);
  drv->sendBuffer(ctx, pulses->getData(), pulses->getSize());
}

static void dsm2SendPulses(void* ctx, int16_t* channels, uint8_t nChannels)
{
  // TODO:
  (void)channels;
  (void)nChannels;

  auto mod_st = (etx_module_state_t*)ctx;
  auto module = modulePortGetModule(mod_st);
  auto pulses = (UartMultiPulses*)mod_st->user_data;

  pulses->initFrame();
  setupPulsesDSM2(module, pulses);

  _dsm_send(mod_st, pulses);
}

static void dsmpSendPulses(void* ctx, int16_t* channels, uint8_t nChannels)
{
  // TODO:
  (void)channels;
  (void)nChannels;

  auto mod_st = (etx_module_state_t*)ctx;
  auto module = modulePortGetModule(mod_st);
  auto pulses = (UartMultiPulses*)mod_st->user_data;

  pulses->initFrame();
  setupPulsesLemonDSMP(module, pulses);

  _dsm_send(mod_st, pulses);
}

// TODO: check telemetry init...
const etx_proto_driver_t DSM2Driver = {
  .protocol = PROTOCOL_CHANNELS_DSM2_LP45,
  .init = dsm2Init,
  .deinit = dsmDeInit,
  .sendPulses = dsm2SendPulses,
  .getByte = nullptr,
  .processData = nullptr,
};

// TODO: check telemetry init...
const etx_proto_driver_t DSMPDriver = {
  .protocol = PROTOCOL_CHANNELS_DSMP,
  .init = dsmpInit,
  .deinit = dsmDeInit,
  .sendPulses = dsmpSendPulses,
  .getByte = nullptr,
  .processData = nullptr,
};
