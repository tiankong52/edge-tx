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

#include "tabsgroup.h"

class RadioSetupPage: public PageTab {
 public:
  RadioSetupPage();

  void build(Window * window) override;

  static LAYOUT_VAL(NUM_W, 80, 80)
  static LAYOUT_VAL(EDT_X, 220, 144)
  static constexpr coord_t LBL_W = EDT_X - PAD_TINY - PAD_SMALL;
  static LAYOUT_VAL(BTN_COLS, 3, 2)
};

class SetupButtonGroup : public Window
{
 public:
  typedef std::function<void()> PageFct;
  typedef std::pair<const char*, PageFct> PageDef;
  typedef std::list<PageDef> PageDefs;

  SetupButtonGroup(Window* parent, const rect_t& rect, const char* title, int cols, PaddingSize padding, PageDefs pages);

 protected:
};

struct SetupLineDef {
  const char* title;
  std::function<void(Window*, coord_t, coord_t)> createEdit;
};

class SetupLine : public Window
{
 public:
  SetupLine(Window* parent, const rect_t& rect, const char* title, std::function<void(Window*, coord_t, coord_t)> createEdit, coord_t col2);

 protected:
};
