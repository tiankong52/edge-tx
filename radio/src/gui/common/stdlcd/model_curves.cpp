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

#include "opentx.h"

#if defined(GVARS_IN_CURVES_SCREEN)
  #warning "define still not added to CMakeLists.txt"
  #define CURVE_SELECTED() (sub >= 0 && sub < MAX_CURVES)
  #define GVAR_SELECTED()  (sub >= MAX_CURVES)
#else
  #define CURVE_SELECTED() (sub >= 0)
#endif

void drawCurve(coord_t offset)
{
  drawFunction(applyCurrentCurve, offset);

  CurveHeader & crv = g_model.curves[s_currIdxSubMenu];
  for (uint8_t i = 0; i < crv.points + 5; i++) {
    point_t point = getPoint(i);
    lcdDrawFilledRect(point.x - 1 - offset, point.y - 1, 3, 3, SOLID, FORCE); // do markup square
  }
}

void menuModelCurvesAll(event_t event)
{
  uint8_t old_editMode = s_editMode;

#if defined(GVARS_IN_CURVES_SCREEN)
  SIMPLE_MENU(STR_MENUCURVES, menuTabModel, MENU_MODEL_CURVES, HEADER_LINE+MAX_CURVES+MAX_GVARS);
#else
  SIMPLE_MENU(STR_MENUCURVES, menuTabModel, MENU_MODEL_CURVES, HEADER_LINE+MAX_CURVES);
#endif

  int8_t sub = menuVerticalPosition - HEADER_LINE;

  switch (event) {
#if defined(ROTARY_ENCODER_NAVIGATION)
    case EVT_ROTARY_BREAK:
#endif
#if !defined(PCBTARANIS)
    case EVT_KEY_FIRST(KEY_RIGHT):
#endif
    case EVT_KEY_FIRST(KEY_ENTER):
      if (CURVE_SELECTED() && !READ_ONLY()) {
        s_currIdxSubMenu = sub;
        s_currSrcRaw = MIXSRC_NONE;
        pushMenu(menuModelCurveOne);
      }
      break;
  }

  for (uint8_t i=0; i<LCD_LINES-1; i++) {
    coord_t y = MENU_HEADER_HEIGHT + 1 + i*FH;
    uint8_t k = i + menuVerticalOffset;
    LcdFlags attr = (sub == k ? INVERS : 0);
#if defined(GVARS_IN_CURVES_SCREEN)
    if (k >= MAX_CURVES) {
      drawStringWithIndex(0, y, STR_GV, k-MAX_CURVES+1);
      if (GVAR_SELECTED()) {
        if (attr && s_editMode>0) attr |= BLINK;
        lcdDrawNumber(10*FW, y, GVAR_VALUE(k-MAX_CURVES, -1), attr);
        if (attr) g_model.gvars[k-MAX_CURVES] = checkIncDec(event, g_model.gvars[k-MAX_CURVES], -1000, 1000, EE_MODEL);
      }
    }
    else
#endif
    {
      drawStringWithIndex(0, y, STR_CV, k+1, attr);
      CurveHeader & crv = g_model.curves[k];
      editName(4*FW, y, crv.name, sizeof(crv.name), 0, 0, 0, old_editMode);
#if LCD_W >= 212
      lcdDrawNumber(11*FW, y, 5+crv.points, LEFT);
      lcdDrawText(lcdLastRightPos, y, STR_PTS, 0);
#endif
    }
  }

  if (CURVE_SELECTED()) {
    s_currIdxSubMenu = sub;
#if LCD_W >= 212
    drawCurve(23);
#else
    drawCurve(10);
#endif
  }
}

static const char* _curve_types[] = {"Diff","Expo","Func","Cstm"};

void editCurveRef(coord_t x, coord_t y, CurveRef & curve, event_t event, LcdFlags flags)
{
  coord_t x1 = x;
  LcdFlags flags1 = flags;
  if (flags & RIGHT) {
    x1 -= 9*FW;
    flags1 -= RIGHT;
  }
  else {
    x += 5*FW;
  }

  uint8_t active = (flags & INVERS);

  if (menuHorizontalPosition == 0) {
    flags = flags & RIGHT;
  }
  else {
    flags1 = 0;
  }

  lcdDrawTextAtIndex(x1, y, _curve_types, curve.type, flags1);

  if (active && menuHorizontalPosition==0) {
    CHECK_INCDEC_MODELVAR_ZERO(event, curve.type, CURVE_REF_CUSTOM);
    if (checkIncDec_Ret) curve.value = 0;
  }
  switch (curve.type) {
    case CURVE_REF_DIFF:
    case CURVE_REF_EXPO:
      curve.value = GVAR_MENU_ITEM(x, y, curve.value, -100, 100, LEFT | flags, 0, event);
      break;
    case CURVE_REF_FUNC:
      lcdDrawTextAtIndex(x, y, STR_VCURVEFUNC, curve.value, flags);
      if (active && menuHorizontalPosition==1) CHECK_INCDEC_MODELVAR_ZERO(event, curve.value, CURVE_BASE-1);
      break;
    case CURVE_REF_CUSTOM:
      drawCurveName(x, y, curve.value, flags);
      if (active && menuHorizontalPosition == 1) {
        if (event == EVT_KEY_LONG(KEY_ENTER) && curve.value != 0) {
          s_currIdxSubMenu = abs(curve.value) - 1;
          pushMenu(menuModelCurveOne);
        }
        else {
          CHECK_INCDEC_MODELVAR(event, curve.value, -MAX_CURVES, MAX_CURVES);
        }
      }
      break;
  }
}

void drawFunction(FnFuncP fn, uint8_t offset)
{
  lcdDrawVerticalLine(CURVE_CENTER_X - offset, CURVE_CENTER_Y-CURVE_SIDE_WIDTH, CURVE_SIDE_WIDTH * 2 + 1, 0xee);
  lcdDrawHorizontalLine(CURVE_CENTER_X - CURVE_SIDE_WIDTH - offset, CURVE_CENTER_Y, CURVE_SIDE_WIDTH * 2 + 1, 0xbb);

  coord_t prev_yv = (coord_t) - 1;

  for (int xv = -CURVE_SIDE_WIDTH; xv <= CURVE_SIDE_WIDTH; xv++) {
    coord_t yv = (LCD_H - 1) - (((uint16_t)RESX + fn(xv * (RESX/CURVE_SIDE_WIDTH))) / 2 * (LCD_H - 1) / RESX);
    if (prev_yv != (coord_t) - 1) {
      if (abs((int8_t)yv-prev_yv) <= 1) {
        lcdDrawPoint(CURVE_CENTER_X + xv - offset - 1, prev_yv, FORCE);
      }
      else {
        uint8_t tmp = (prev_yv < yv ? 0 : 1);
        lcdDrawSolidVerticalLine(CURVE_CENTER_X + xv - offset - 1, yv + tmp, prev_yv - yv);
      }
    }
    prev_yv = yv;
  }
}

void drawCursor(FnFuncP fn, uint8_t offset)
{
  int x512 = getValue(s_currSrcRaw);
  if (s_currSrcRaw >= MIXSRC_FIRST_TELEM) {
    if (s_currScale > 0)
      x512 = (x512 * 1024) / convertTelemValue(s_currSrcRaw - MIXSRC_FIRST_TELEM + 1, s_currScale);
    drawSensorCustomValue(LCD_W - FW - offset, 6 * FH, (s_currSrcRaw - MIXSRC_FIRST_TELEM) / 3, x512, 0);
  }
  else {
    lcdDrawNumber(LCD_W - FW - offset, 6*FH, calcRESXto1000(x512), RIGHT | PREC1);
  }
  x512 = limit(-1024, x512, 1024);
  int y512 = fn(x512);
  y512 = limit(-1024, y512, 1024);
  lcdDrawNumber(CURVE_CENTER_X - FWNUM - offset, 1*FH, calcRESXto1000(y512), RIGHT | PREC1);

  x512 = CURVE_CENTER_X + x512/(RESX / CURVE_SIDE_WIDTH);
  y512 = (LCD_H - 1) - ((y512 + RESX) / 2) * (LCD_H - 1) / RESX;
  
  lcdDrawSolidVerticalLine(x512 - offset, y512-3, 3 * 2 + 1);
  lcdDrawSolidHorizontalLine(x512 - 3 - offset, y512, 3 * 2 + 1);
}
