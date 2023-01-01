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

#include "page.h"
#include "form.h"
#include "curve.h"

class CurveEdit;
class FormGridLayout;
class StaticText;
class TextButton;
class FormBuilder;

class CurveDataEdit : public Window
{
  friend class CurveEdit;

  public:
    CurveDataEdit(Window * parent, const rect_t & rect, uint8_t index);
    ~CurveDataEdit();

    void setCurveEdit(CurveEdit* _curveEdit);

    void build();
    void buildSettings();
    void buildList();
    void buildEdit();
    void update();

    void showEdit(uint8_t point);
    void hideEdit();

    void onEvent(event_t event) override;

  protected:
    uint8_t index;
    FormBuilder* form = nullptr;
    CurveEdit * curveEdit;
    StaticText* pointNText;
    StaticText* pointXText;
    StaticText* pointYText;
    TextButton* pointButtons[17];
    TextButton* decX1;
    TextButton* incX1;
    TextButton* decX2;
    TextButton* incX2;
    Window* editWindow = nullptr;
    Window* mainWindow = nullptr;
    Window* pointsWindow = nullptr;
    bool isEditing;
    bool symmetry;

    void setX(int8_t chg);
    void setY(int8_t chg);
    void symmetryAdjust();

    void setPointText();
    void setPointsListText(uint8_t n);
};

class CurveEdit: public FormField
{
  public:
    CurveEdit(Window * parent, const rect_t & rect, uint8_t index);
    static void SetCurrentSource(uint32_t source);

    void deleteLater(bool detach = true, bool trash = true) override
    {
      if (_deleted)
        return;

      preview.deleteLater(true, false);

      FormField::deleteLater(detach, trash);
    }

    void updatePreview();

    void checkEvents(void) override;

    void showCurrent(bool state) { showEdit = state; }

    uint8_t getCurrent() const { return current; }
    uint8_t getCurvePointsCount() const;
    int8_t getX(uint8_t n) const;
    int8_t getX() const { return getX(current); }
    int8_t getY(uint8_t n) const;
    int8_t getY() const { return getY(current); }
    bool isCustomCurve() const;
    bool isEditableX() const;

    bool setCurrent(uint8_t n);
    void selectPoint(int8_t chg);
    void setX(int8_t chg);
    void setY(int8_t chg);
    void setX(uint8_t n, int8_t value);
    void setY(uint8_t n, int8_t value);

   protected:
    Curve preview;
    uint8_t index;
    uint8_t current;
    bool showEdit;
    static mixsrc_t currentSource;
    static bool lockSource;
};

class CurveDataEdit : public Window
{
  public:
    CurveDataEdit(Window * parent, const rect_t & rect, uint8_t index);

    void setCurveEdit(CurveEdit* _curveEdit)
    {
      curveEdit = _curveEdit;
      update();
    }

    void update();

  protected:
    uint8_t index;
    CurveEdit * curveEdit;
    NumberEdit* numEditX[16];

    void curvePointsRow(FormWindow::Line* parent, int start, int count, int curvePointsCount, bool isCustom);
};

class CurveEditWindow : public Page
{
  public:
    CurveEditWindow(uint8_t index);

  protected:
    uint8_t index;
    CurveEdit * curveEdit = nullptr;
    CurveDataEdit * curveDataEdit = nullptr;

    void buildHeader(Window * window);
    void buildBody(FormWindow * window);
};
