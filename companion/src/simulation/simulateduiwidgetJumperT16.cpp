/*
 * Copyright (C) OpenTX
 *
 * Based on code named
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

// NOTE: RadioUiAction(NUMBER,...): NUMBER relates to enum EnumKeys in the specific board.h

#include "simulateduiwidget.h"
#include "ui_simulateduiwidgetJumperT16.h"

SimulatedUIWidgetJumperT16::SimulatedUIWidgetJumperT16(SimulatorInterface *simulator, QWidget * parent):
  SimulatedUIWidget(simulator, parent),
  ui(new Ui::SimulatedUIWidgetJumperT16)
{
  RadioUiAction * act;

  ui->setupUi(this);

  // add actions in order of appearance on the help menu

  act = new RadioUiAction(12, QList<int>() << Qt::Key_Up, SIMU_STR_HLP_KEY_UP, SIMU_STR_HLP_ACT_MDL);
  addRadioWidget(ui->leftbuttons->addArea(QRect(50, 70, 80, 35), "JumperT16/left_mdl.png", act));

  act = new RadioUiAction(14, QList<int>() << Qt::Key_Left, SIMU_STR_HLP_KEY_LFT, SIMU_STR_HLP_ACT_SYS);
  addRadioWidget(ui->leftbuttons->addArea(QRect(25, 10, 95, 35), "JumperT16/left_sys.png", act));

  act = new RadioUiAction(13, QList<int>() << Qt::Key_Right, SIMU_STR_HLP_KEY_RGT, SIMU_STR_HLP_ACT_TELE);
  addRadioWidget(ui->leftbuttons->addArea(QRect(50, 190, 80, 35), "JumperT16/left_tele.png", act));

  act = new RadioUiAction(1, QList<int>() << Qt::Key_Down << Qt::Key_Delete << Qt::Key_Escape << Qt::Key_Backspace,
                          SIMU_STR_HLP_KEY_DN % "<br>" % SIMU_STR_HLP_KEYS_EXIT, SIMU_STR_HLP_ACT_RTN);
  addRadioWidget(ui->rightbuttons->addArea(QRect(50, 10, 95, 35), "JumperT16/right_rtn.png", act));

  act = new RadioUiAction(5, QList<int>() << Qt::Key_PageDown, SIMU_STR_HLP_KEY_PGDN, SIMU_STR_HLP_ACT_PGDN);
  addRadioWidget(ui->leftbuttons->addArea(QRect(50, 131, 80, 35), "JumperT16/left_page.png", act));

  m_scrollUpAction = new RadioUiAction(-1, QList<int>() << Qt::Key_Minus, SIMU_STR_HLP_KEY_MIN % "|" % SIMU_STR_HLP_MOUSE_UP, SIMU_STR_HLP_ACT_ROT_LFT);
  m_scrollDnAction = new RadioUiAction(-1, QList<int>() << Qt::Key_Plus << Qt::Key_Equal, SIMU_STR_HLP_KEY_PLS % "|" % SIMU_STR_HLP_MOUSE_DN, SIMU_STR_HLP_ACT_ROT_RGT);
  connectScrollActions();

  m_mouseMidClickAction = new RadioUiAction(2, QList<int>() << Qt::Key_Enter << Qt::Key_Return, SIMU_STR_HLP_KEYS_ACTIVATE, SIMU_STR_HLP_ACT_ROT_DN);
  addRadioWidget(ui->rightbuttons->addArea(QRect(55, 90, 56, 120), "JumperT16/right_ent.png", m_mouseMidClickAction));

  addRadioWidget(ui->leftbuttons->addArea(QRect(10, 252, 30, 30), "JumperT16/left_scrnsht.png", m_screenshotAction));

  m_backlightColors << QColor(47, 123, 227);

  setLcd(ui->lcd);
}

SimulatedUIWidgetJumperT16::~SimulatedUIWidgetJumperT16()
{
  delete ui;
}
