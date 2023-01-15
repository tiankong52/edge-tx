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

#ifndef _MODEL_LOGICAL_SWITCHES_H
#define _MODEL_LOGICAL_SWITCHES_H

#include "tabsgroup.h"

class ModelLogicalSwitchesPage: public PageTab {
public:
    ModelLogicalSwitchesPage();

    virtual void build(FormWindow * window) override;

protected:
    int8_t focusIndex = -1;
    int8_t prevFocusIndex = -1;
    bool isRebuilding = false;
    Button* addButton = nullptr;

    void rebuild(FormWindow * window);
    void newLS(FormWindow * window, bool pasteLS);
    void plusPopup(FormWindow * window);
};

#endif //_MODEL_LOGICAL_SWITCHES_H
