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

#pragma once

#include "opentx.h"
#include "bitmaps.h"
#include "static.h"

class BitmapBuffer;

class EdgeTxTheme
{
 public:
  EdgeTxTheme();

  static EdgeTxTheme *instance();

  virtual void load();
  void update();

  void setBackgroundImageFileName(const char *fileName);

 protected:
  static EdgeTxTheme *_instance;

  char backgroundImageFileName[FF_MAX_LFN + 1];

  const BitmapBuffer *backgroundBitmap = nullptr;
};

class HeaderDateTime : public Window
{
 public:
  HeaderDateTime(Window* parent, int x, int y);

  void setColor(uint32_t color);

  static LAYOUT_VAL(HDR_DATE_WIDTH, 45, 45)
  static LAYOUT_VAL(HDR_DATE_HEIGHT, 12, 12)
  static LAYOUT_VAL(HDR_DATE_LINE2, 15, 15)

 protected:
  lv_obj_t *date = nullptr;
  lv_obj_t *time = nullptr;
  int8_t lastMinute = -1;

  void checkEvents() override;
};

class HeaderIcon : public StaticIcon
{
 public:
  HeaderIcon(Window *parent, EdgeTxIcon icon);
};

class UsbSDConnected : public Window
{
 public:
  UsbSDConnected();

  static LAYOUT_VAL(HDR_DATE_Y, 6, 6)

 protected:
  HeaderDateTime* dateTime = nullptr;
};
