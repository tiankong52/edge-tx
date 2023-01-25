/*
 * Copyright (C) EdgeTx
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

#include "stm32_softserial_driver.h"
#include <string.h>

// constant bitlen, timer frequency is computed
// to reach the required baudrate
#define BITLEN 16

#if 0
#include "stm32_exti_driver.h"

// getTmr2MHz()
#include "timers_driver.h"

// RX state
static uint8_t rxBitCount;
static uint8_t rxByte;

// RX FIFO
static volatile uint8_t rxRidx;
static volatile uint8_t rxWidx;
static uint8_t *rxBuffer;
static uint32_t rxBufLen;

// single bit length expresses in half us
static uint16_t bitLength;
static uint16_t probeTimeFromStartBit;

static const stm32_softserial_port* _softserialPort;

static void _softserial_exti()
{
  if (rxBitCount == 0) {

    // enable timer counter
    auto TIMx = _softserialPort->TIMx;
    LL_TIM_SetAutoReload(TIMx, probeTimeFromStartBit);
    LL_TIM_EnableCounter(TIMx);
    
    // disable start bit interrupt
    LL_EXTI_DisableIT_0_31(_softserialPort->EXTI_Line);
  }
}

static void _softserial_set_timings(uint32_t baudrate)
{
  switch(baudrate) {
    case 115200:
      bitLength = 17;
      probeTimeFromStartBit = 25;
      break;
    case 57600:
      bitLength = 35;
      probeTimeFromStartBit = 48;
      break;
    default:
      bitLength = 2000000 / baudrate; // because of 0,5 us tick
      probeTimeFromStartBit = 3000000 / baudrate;
  }
}

static inline void _fifo_clear()
{
  rxWidx = 0;
  rxRidx = 0;
}

static void _softserial_init_rx(const stm32_softserial_port* port, const etx_serial_init* params)
{
  rxBitCount = 0;
  rxBuffer = port->buffer.buffer;
  rxBufLen = port->buffer.length;
  _fifo_clear();
  
  _softserial_set_timings(params->baudrate);

  // configure bit sample timer
  LL_TIM_InitTypeDef timInit;
  LL_TIM_StructInit(&timInit);

  timInit.Prescaler = port->TIM_Prescaler;

  // enable_tim_clock(port->TIMx);
  LL_TIM_Init(port->TIMx, &timInit);

  NVIC_SetPriority(port->TIM_IRQn, 0);
  NVIC_EnableIRQ(port->TIM_IRQn);

  // init TELEMETRY_RX_GPIO_PIN
  LL_GPIO_InitTypeDef pinInit;
  LL_GPIO_StructInit(&pinInit);

  pinInit.Pin = port->GPIO_Pin;
  pinInit.Mode = LL_GPIO_MODE_INPUT;
  pinInit.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  pinInit.Pull = LL_GPIO_PULL_DOWN;

  LL_GPIO_Init(port->GPIOx, &pinInit);

  // TODO: telemetryInitDirPin();
  // -> should be done outside this driver!

  // Connect EXTI line to TELEMETRY RX pin
  LL_SYSCFG_SetEXTISource(port->EXTI_Port, port->EXTI_SysLine);

  // Configure EXTI for raising edge (start bit; assuming inverted serial)
  _softserialPort = port;
  stm32_exti_enable(port->EXTI_Line, LL_EXTI_TRIGGER_RISING, _softserial_exti);
}

static void _softserial_deinit_gpio(const stm32_softserial_port* port)
{
  // Reconfigure pin as input
  LL_GPIO_InitTypeDef pinInit;
  LL_GPIO_StructInit(&pinInit);

  pinInit.Pin = port->GPIO_Pin;
  pinInit.Mode = LL_GPIO_MODE_INPUT;
  LL_GPIO_Init(port->GPIOx, &pinInit);
}

static void _softserial_deinit_rx(const stm32_softserial_port* port)
{
  stm32_exti_disable(port->EXTI_Line);
  NVIC_DisableIRQ(port->TIM_IRQn);
  LL_TIM_DeInit(port->TIMx);
}

static void _softserial_init_tx(const stm32_softserial_port* port, const etx_serial_init* params)
{
  _softserial_set_timings(params->baudrate);
  _softserialPort = nullptr;

  LL_GPIO_InitTypeDef pinInit;
  LL_GPIO_StructInit(&pinInit);

  pinInit.Pin = port->GPIO_Pin;
  pinInit.Mode = LL_GPIO_MODE_OUTPUT;
  pinInit.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  pinInit.Pull = LL_GPIO_PULL_UP; // really ???

  LL_GPIO_Init(port->GPIOx, &pinInit);
}

static void* stm32_softserial_init(void* hw_def, const etx_serial_init* params)
{
  auto port = (const stm32_softserial_port*)hw_def;
  if (params->rx_enable) {
    _softserial_init_rx(port, params);
  } else {
    _softserial_init_tx(port, params);
  }

  return hw_def;
}

static void stm32_softserial_deinit(void* ctx)
{
  auto port = (const stm32_softserial_port*)ctx;

  if (port == _softserialPort) {
    _softserial_deinit_rx(port);
  }

  _softserial_deinit_gpio(port);
  _softserialPort = nullptr;
}

#define _WAIT_LOOP(len)                           \
  {                                               \
    while ((uint16_t)(getTmr2MHz() - time) < len) \
      ;                                           \
    time += len;                                  \
  }

static void stm32_softserial_send_byte(void* ctx, uint8_t byte)
{
  auto port = (const stm32_softserial_port*)ctx;
  uint16_t time;
  uint32_t i;
  
  __disable_irq();
  time = getTmr2MHz();
  LL_GPIO_SetOutputPin(port->GPIOx, port->GPIO_Pin);

  _WAIT_LOOP(bitLength);

  for (i = 0; i < 8; i++) {
    if (byte & 1) {
      LL_GPIO_ResetOutputPin(port->GPIOx, port->GPIO_Pin);
    }
    else {
      LL_GPIO_SetOutputPin(port->GPIOx, port->GPIO_Pin);
    }
    byte >>= 1 ;

    _WAIT_LOOP(bitLength);
  }
  LL_GPIO_ResetOutputPin(port->GPIOx, port->GPIO_Pin);
  __enable_irq(); // No need to wait for the stop bit to complete

  _WAIT_LOOP(bitLength);
}

static inline bool _fifo_full()
{
  return ((rxWidx + 1) & (rxBufLen - 1)) == rxRidx;
}

static inline void _fifo_push(uint8_t c)
{
  rxWidx = (rxWidx + 1) & (rxBufLen - 1);
  rxBuffer[rxWidx] = c;
}

static int stm32_softserial_get_byte(void* ctx, uint8_t* data)
{
  if (rxWidx == rxRidx) return 0;

  *data = rxBuffer[rxRidx];
  rxRidx = (rxWidx + 1) & (rxBufLen - 1);
  
  return 1;
}

void stm32_softserial_timer_isr(const stm32_softserial_port* port)
{
  auto TIMx = port->TIMx;
  LL_TIM_ClearFlag_UPDATE(TIMx);

  if (rxBitCount < 8) {
    if (rxBitCount == 0) {
      LL_TIM_SetAutoReload(TIMx, bitLength);
      rxByte = 0;
    }
    else {
      rxByte >>= 1;
    }

    if (LL_GPIO_IsInputPinSet(port->GPIOx, port->GPIO_Pin) == 0)
      rxByte |= 0x80;

    ++rxBitCount;
  }
  else if (rxBitCount == 8) {

    if (!_fifo_full()) _fifo_push(rxByte);
    rxBitCount = 0;

    // disable timer
    LL_TIM_DisableCounter(TIMx);

    // re-enable start bit interrupt
    LL_EXTI_EnableIT_0_31(port->EXTI_Line);
  }  
}

static void stm32_softserial_clear_rx_buffer(void* ctx)
{
  rxWidx = 0;
  rxRidx = 0;
}
#endif

static inline void _set_level(stm32_softserial_tx_state* st, uint8_t v)
{
  *st->pulse_ptr++ = v - 1;
}

// TODO:
// - support for different word len / stop bit(s) / parity config
// - now: only 8N1 and 8E2
//
// max 11 changes 0 10 10 10 10 P 1
static void _conv_byte_8e2(stm32_softserial_tx_state* st, uint8_t b)
{
  bool lev = 0;
  uint8_t parity = 1;

  uint8_t len = BITLEN;               // max val: 10*16 < 256
  for (uint8_t i = 0; i <= 9; i++) {  // 8Bits + 1Parity

    bool nlev = b & 1;                // lsb first
    parity = parity ^ (uint8_t)nlev;

    if (lev == nlev) {
      len += BITLEN;
    } else {
      _set_level(st, len);
      len = BITLEN;
      lev = nlev;
    }

    b = (b >> 1) | 0x80;         // shift in ones for stop bit and parity
    if (i == 7) b = b ^ parity;  // lowest bit is one from previous line
  }

  // enlarge the last bit to be two stop bits long
  _set_level(st, len + BITLEN);

  // update size
  --st->serial_size;
}

static void _conv_byte_8n1(stm32_softserial_tx_state* st, uint8_t b)
{
  bool lev = 0;
  uint8_t len = BITLEN;               // max val: 10*16 < 256
  for (uint8_t i = 0; i <= 8; i++) {  // 8Bits

    bool nlev = b & 1;                // lsb first
    if (lev == nlev) {
      len += BITLEN;
    } else {
      _set_level(st, len);
      len = BITLEN;
      lev = nlev;
    }

    b = (b >> 1) | 0x80;         // shift in ones for stop bit
  }

  // write the last bit
  _set_level(st, len);

  // update size
  --st->serial_size;
}


// PXX1 PWM is encoded as a PWM signal
// with a fixed ON phase of 9us and a variable OFF phase
// depending on whether the bit is SET or RESET.
//
#define PXX1_FREQ      1000000 /* 1 MHz */
#define PXX1_PWM_ON    9  /* 9us */
#define PXX1_BIT_ZERO  16 /* 0 = 16us */
#define PXX1_BIT_ONE   24 /* 1 = 24us */

static void _conv_byte_pxx1(stm32_softserial_tx_state* st, uint8_t b)
{
  uint32_t bits = st->serial_size < 8 ? st->serial_size : 8;

  for (uint8_t i = 0; i < bits; i++) {
    // MSB first
    if (b & 0x80)
      _set_level(st, PXX1_BIT_ONE);
    else
      _set_level(st, PXX1_BIT_ZERO);

    // next bit
    b <<= 1;
  }

  st->serial_size -= bits;
}

// stm32_pulse_timer_t based TX implementation
static void* stm32_softserial_init(void* hw_def, const etx_serial_init* params)
{
  auto port = (const stm32_softserial_tx_port*)hw_def;

  // Init state
  auto st = port->st;
  memset(port->st, 0, sizeof(stm32_softserial_tx_state));

  uint32_t freq = params->baudrate * 16;
  bool polarity = true;
  uint32_t ocmode = LL_TIM_OCMODE_TOGGLE;
  uint32_t cmp_val = 0;

  switch(params->encoding) {

  case ETX_Encoding_8N1:
    st->conv_byte = _conv_byte_8n1;
    break;

  case ETX_Encoding_8E2:
    st->conv_byte = _conv_byte_8e2;
    break;

  case ETX_Encoding_PXX1_PWM:
    st->conv_byte = _conv_byte_pxx1;
    freq = PXX1_FREQ;
    polarity = false;
    ocmode = LL_TIM_OCMODE_PWM1;
    cmp_val = PXX1_PWM_ON;
    break;

  default:
    return nullptr;
  }

  // prevent dividing by 0 in stm32_pulse_init()
  if (freq == 0) return nullptr;

  // Use a variable timer frequency to keep bitlen constant (16)
  auto tim = port->tim;
  stm32_pulse_init(tim, freq);

  // TODO: polarity?
  stm32_pulse_config_output(tim, polarity, ocmode, cmp_val);

  return hw_def;
}

static void stm32_softserial_deinit(void* ctx)
{
  auto port = (const stm32_softserial_tx_port*)ctx;
  stm32_pulse_deinit(port->tim);
}

static void stm32_softserial_send_byte(void* ctx, uint8_t byte)
{
  // TODO
}

static uint16_t _fill_pulses(stm32_softserial_tx_state* st)
{
  st->pulse_ptr = st->pulse_buffer;
  bool is_pxx1 = (st->conv_byte == _conv_byte_pxx1);

  uint32_t size = st->serial_size;

  // PXX1 uses a # bits rather than bytes
  if (is_pxx1) {
    // 
    size = (size + 7) / 8;
    if (size > STM32_SOFTSERIAL_MAX_PULSES_TRANSITIONS / 8) // 12
      size = STM32_SOFTSERIAL_MAX_PULSES_TRANSITIONS / 8;   // 12
  } else if (size > STM32_SOFTSERIAL_BUFFERED_PULSES) {
    size = STM32_SOFTSERIAL_BUFFERED_PULSES;
  }

  for (uint8_t i = 0; i < size; i++) {
    st->conv_byte(st, *st->serial_data++);
  }

  uint16_t length = st->pulse_ptr - st->pulse_buffer;
  if (st->serial_size == 0) {
    // 
    // insert an additional period in case the number of transitions
    // is odd, as we need an even number of toggles to return
    // to the idle polarity at the end of the pulse train.
    //
    if ((length & 1) && !is_pxx1) {
      *st->pulse_ptr++ = 255;
      length++;
    } else {
      *(st->pulse_ptr - 1) = 255;
    }
  }

  return length;
}

static bool stm32_softserial_dma_tc_isr(void* ctx)
{
  auto port = (const stm32_softserial_tx_port*)ctx;
  auto tim = port->tim;
  auto st = port->st;

  if (!st->serial_size)
    return false;

  uint16_t length = _fill_pulses(st);
  LL_DMA_SetDataLength(tim->DMAx, tim->DMA_Stream, length);
  LL_DMA_EnableStream(tim->DMAx, tim->DMA_Stream);

  return true;
}

static void stm32_softserial_send_buffer(void* ctx, const uint8_t* data, uint32_t size)
{
  auto port = (const stm32_softserial_tx_port*)ctx;
  auto timer = port->tim;
  if (!stm32_pulse_if_not_running_disable(timer))
    return;

  // transform serial payload into timer pulses/length
  auto st = port->st;
  st->serial_data = data;
  st->serial_size = size;

  auto length = _fill_pulses(st);

  if (st->serial_size > 0 && timer->DMA_TC_CallbackPtr) {
    auto closure = timer->DMA_TC_CallbackPtr;
    closure->cb = stm32_softserial_dma_tc_isr;
    closure->ctx = ctx;
  }
  
  // Start DMA request and re-enable timer
  const void* pulses = st->pulse_buffer;

  // TODO: save polarity and encoding
  bool polarity = true;
  uint32_t ocmode = LL_TIM_OCMODE_TOGGLE;
  uint32_t cmp_val = 0;

  // dirty hack...
  if (st->conv_byte == _conv_byte_pxx1) {
    polarity = false;
    ocmode = LL_TIM_OCMODE_PWM1;
    cmp_val = PXX1_PWM_ON;
  }

  stm32_pulse_set_polarity(timer, polarity);
  stm32_pulse_start_dma_req(timer, pulses, length, ocmode, cmp_val);
}

const etx_serial_driver_t STM32SoftSerialTxDriver = {
  .init = stm32_softserial_init,
  .deinit = stm32_softserial_deinit,
  .sendByte = stm32_softserial_send_byte,
  .sendBuffer = stm32_softserial_send_buffer,
  .waitForTxCompleted = nullptr, // TODO
  .enableRx = nullptr, // TODO: combine with EXTI / Timer implementation? (S.PORT INV RX)
  .getByte = nullptr,
  .clearRxBuffer = nullptr, // TODO: same as enableRx
  .getBaudrate = nullptr,
  .setReceiveCb = nullptr,
  .setBaudrateCb = nullptr,
};
