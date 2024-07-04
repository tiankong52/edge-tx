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

#include "gtest/gtest.h"
#include "gtests.h"
#include "telemetry/telemetry.h"

#if defined(CROSSFIRE)

uint8_t createCrossfireChannelsFrame(uint8_t * frame, int16_t * pulses);
TEST(Crossfire, createCrossfireChannelsFrame)
{
  int16_t pulsesStart[MAX_TRAINER_CHANNELS];
  uint8_t crossfire[CROSSFIRE_FRAME_MAXLEN];

  memset(crossfire, 0, sizeof(crossfire));
  for (int i=0; i<MAX_TRAINER_CHANNELS; i++) {
    pulsesStart[i] = -1024 + (2048 / MAX_TRAINER_CHANNELS) * i;
  }

  createCrossfireChannelsFrame(crossfire, pulsesStart);

  // TODO check
}

TEST(Crossfire, crc8)
{
  uint8_t frame[] = { 0x00, 0x0C, 0x14, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x01, 0x03, 0x00, 0x00, 0x00, 0xF4 };
  uint8_t crc = crc8(&frame[2], frame[1]-1);
  ASSERT_EQ(frame[frame[1]+1], crc);
}

#if defined(HARDWARE_EXTERNAL_MODULE)
#include "pulses/crossfire.h"

struct crsf_frame_test {
  void* ctx = nullptr;

  uint8_t buffer[TELEMETRY_RX_PACKET_SIZE];
  uint8_t len = 0;

  crsf_frame_test()
  {
    ctx = CrossfireDriver.init(EXTERNAL_MODULE);
    if (!luaInputTelemetryFifo) {
      luaInputTelemetryFifo =
          new Fifo<uint8_t, LUA_TELEMETRY_INPUT_FIFO_SIZE>();
      assert(luaInputTelemetryFifo != nullptr);
    } else {
      luaInputTelemetryFifo->clear();
    }
  }

  template<unsigned Len>
  void process(uint8_t (&frame)[Len]) {
    CrossfireDriver.processFrame(ctx, frame, Len, buffer, &len);    
  }

  ~crsf_frame_test()
  {
    if (ctx != nullptr) {
      CrossfireDriver.deinit(ctx);
    }
  }
};

static uint8_t incomplete_frame[] = {
    // first frame
    0xEA, 0x14, 0xFF, 0x11, 0xFD, 0x05, 0x00, 0x00, 0x13, 0x01, 0x01,
    0x2A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x5D, 0x98, 0xB4,
    // second frame
    0xEA, 0x21, 0xFF, 0x1E, 0xFD, 0x12, 0x00, 0x00, 0x14, 0x01, 0x01,
    0x4A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x8F, 0xC2, 0x35, 0x3F, 0xFD, 0xC7, 0xD1, 0x3C, 0x4C, 0x01, 0x92,
    0x3F, 0x31,
    // incomplete third frame
    0xEA, 0x1F, 0xFF, 0x1C, 0xFD, 0x10, 0x00,
};

static uint8_t cont_frame[] = {
    0x00, 0x15, 0x01, 0x01, 0x24, 0x00, 0x00, 0x35, 0x7D, 0xF2, 0x40,
    0xE8, 0x03, 0xE8, 0x03, 0xDC, 0x05, 0xDC, 0x05, 0xE1, 0x05, 0xE1,
    0x05, 0x2A, 0xFE, 0x5F,
    //next trailing packet start
    0xEA, 0x0A, 0x0B
};

TEST(Crossfire, frameParser_incompleteFrames)
{
  crsf_frame_test ft;
  if (!ft.ctx) return;
  
  ft.process(incomplete_frame);
  EXPECT_EQ(ft.len, 7);
  EXPECT_EQ(ft.buffer[0], 0xEA);
  EXPECT_EQ(ft.buffer[1], 0x1F);

  ft.process(cont_frame);
  EXPECT_EQ(ft.len, 3);
  EXPECT_EQ(ft.buffer[0], 0xEA);
  EXPECT_EQ(ft.buffer[1], 0x0A);

  uint8_t* lua_buffer = luaInputTelemetryFifo->buffer();
  EXPECT_EQ(luaInputTelemetryFifo->size(), 0x14 + 0x21 + 0x1F);

  unsigned offset = 0;
  EXPECT_EQ(lua_buffer[offset], 0x14);
  offset += 0x14;
  
  EXPECT_EQ(lua_buffer[offset], 0x21);
  offset += 0x21;

  EXPECT_EQ(lua_buffer[offset], 0x1F);
  EXPECT_EQ(lua_buffer[offset + 0x1F - 1], 0xFE);
}

static uint8_t length_error[] = {
    0x2A, 0xFE, 0x5F, 0x00,
};

static uint8_t length_error2[] = {
    // first frame
    0xEA, 0x09, 0xFF, 0x11, 0xFD, 0x05, 0x00, 0x00, 0x13, 0x01, 0x8C,
    // 2nd incomplete frame
    0x2A, 0xFE, 0x5F, 0x00,
};

static uint8_t length_error3[] = {
    // first frame
    0xEA, 0x09, 0xFF, 0x11, 0xFD, 0x05, 0x00, 0x00, 0x13, 0x01, 0x8C,
    // 2nd invalid, too long frame, also truncated 
    0x2A, 0xFE, 0x5F, 0x00,
    // third valid frame
    0xEA, 0x09, 0xFF, 0x11, 0xFD, 0x05, 0x00, 0x00, 0x13, 0x01, 0x8C,
};


TEST(Crossfire, frameParser_length)
{
  crsf_frame_test ft;
  if (!ft.ctx) return;

  uint8_t* lua_buffer = luaInputTelemetryFifo->buffer();

  // Check that a frame that is too big is rejected even if incomplete
  ft.process(length_error);
  EXPECT_EQ(ft.len, 0);

  // Check that a frame that is too big is rejected if positioned
  // after a complete frame
  ft.process(length_error2);
  EXPECT_EQ(ft.len, 0);

  // the first complete frame should have been processed
  EXPECT_EQ(luaInputTelemetryFifo->size(), 0x09);

  ft.process(length_error3);
  EXPECT_EQ(ft.len, 0);

  // only the first frame has been processed, as the rest
  // of the input buffer is thrown away due to length error
  EXPECT_EQ(luaInputTelemetryFifo->size(), 0x09 + 0x09);

  // check first frame
  unsigned offset = 0;
  EXPECT_EQ(lua_buffer[offset], 0x09);
  offset += 0x09;

  // check second frame
  EXPECT_EQ(lua_buffer[offset], 0x09);
  EXPECT_EQ(lua_buffer[offset + 0x09 - 1], 0x01);
}

static uint8_t invalid_frames[] = {
    // first frame
    0xEA, 0x14, 0xFF, 0x11, 0xFD, 0x05, 0x00, 0x00, 0x13, 0x01, 0x01,
    0x2A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x5D, 0x98, 0xB4,
};

static uint8_t invalid_frames2[] = {
    // random bytes
    0x00, 0x35, 0xA4,
};

static uint8_t invalid_frames3[] = {
    // second frame
    0xEA, 0x21, 0xFF, 0x1E, 0xFD, 0x12, 0x00, 0x00, 0x14, 0x01, 0x01,
    0x4A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x8F, 0xC2, 0x35, 0x3F, 0xFD, 0xC7, 0xD1, 0x3C, 0x4C, 0x01, 0x92,
    0x3F, 0x31,
    // invalid CRC frame
    0xEA, 0x02, 0x00, 0x01,
    // third frame
    0xEA, 0x1F, 0xFF, 0x1C, 0xFD, 0x10, 0x00,0x00, 0x15, 0x01, 0x01, 0x24, 0x00, 0x00, 0x35, 0x7D, 0xF2, 0x40,
    0xE8, 0x03, 0xE8, 0x03, 0xDC, 0x05, 0xDC, 0x05, 0xE1, 0x05, 0xE1,
    0x05, 0x2A, 0xFE, 0x5F,
};

TEST(Crossfire, frameParser_badFrames)
{
  //check if frameParser correctly skips bad frames (too long, bad CRC) and does't lose following packets 
  crsf_frame_test ft;
  if (!ft.ctx) return;

  ft.process(invalid_frames);
  EXPECT_EQ(ft.len,0);

  ft.process(invalid_frames2);
  EXPECT_EQ(ft.len,0);

  ft.process(invalid_frames3);
  EXPECT_EQ(ft.len,0);

  uint8_t* lua_buffer = luaInputTelemetryFifo->buffer();
  EXPECT_EQ(luaInputTelemetryFifo->size(), 0x14 + 0x21 + 0x1F);

  unsigned offset = 0;
  EXPECT_EQ(lua_buffer[offset], 0x14);
  offset += 0x14;
  
  EXPECT_EQ(lua_buffer[offset], 0x21);
  offset += 0x21;

  EXPECT_EQ(lua_buffer[offset], 0x1F);
  EXPECT_EQ(lua_buffer[offset + 0x1F - 1], 0xFE);
}

static uint8_t jumboFrame1[]={
  0xEA, 0x3E, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFB
};
static uint8_t jumboFrame2[]={ //jumbo frame 2 
  0x8D, 0xEA, 0x3D, 0xFE, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x57
};

TEST(Crossfire, frameParser_multipleJumboFrames)
{
  crsf_frame_test ft;
  if (!ft.ctx) return;

  ft.process(jumboFrame1);
  EXPECT_EQ(ft.len, 63);
  EXPECT_EQ(ft.buffer[0], 0xEA);
  EXPECT_EQ(ft.buffer[1], 0x3E);

  ft.process(jumboFrame2);
  EXPECT_EQ(ft.len,0);

  uint8_t* lua_buffer = luaInputTelemetryFifo->buffer();
  EXPECT_EQ(luaInputTelemetryFifo->size(), 62 + 61);

  unsigned offset = 0;
  EXPECT_EQ(lua_buffer[offset], 0x3E);
  EXPECT_EQ(lua_buffer[offset + 0x3E - 1], 0xFB);

  EXPECT_EQ(lua_buffer[offset], 0x3E);
  offset += 0x3E;
  
  EXPECT_EQ(lua_buffer[offset], 0x3D);
  EXPECT_EQ(lua_buffer[offset + 0x3D - 1], 0xF0);
}
#endif // HARDWARE_EXTERNAL_MODULE
#endif

