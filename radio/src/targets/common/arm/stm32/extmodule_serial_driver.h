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

#include <stdint.h>
#include "hal/serial_driver.h"

#define EXTMODULE_USART_IRQ_PRIORITY 6

// Callbacks using intmoduleFifo
void extmoduleFifoReceive(uint8_t data);
void extmoduleFifoError();

// void extmoduleSerialStart();
// void extmoduleInvertedSerialStart(uint32_t baudrate);
// void extmoduleSendBuffer(const uint8_t * data, uint8_t size);
// void extmoduleSendNextFrame();

#if defined(PXX1)
void extmodulePxx1SerialStart();
#endif

extern const etx_serial_driver_t ExtmoduleSerialDriver;
