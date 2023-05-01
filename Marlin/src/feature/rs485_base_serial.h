/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2023 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include "../inc/MarlinConfigPre.h"
#ifndef rs485_base_serial_H
#define rs485_base_serial_H
//#include <ModbusMaster.h>

//#include "rs485.h"

//ModbusMaster RS485SERIAL;

#define RS485_SEND_BUFFER_SIZE 32

#define RS485_ID RS485_ADRESS
#ifdef FLOWCONTROLL
  #define HAS_FLOWCONTROLL 1
  #ifdef SINGLE_PIN
  #define HAS_SINGLE_PIN 1
  #endif
#endif

void rs485_init();

class rs485_serial
{
private:
  // data
public:
  rs485_serial();

  int init();
  //~rs485_serial();
};

//extern rs485_serial RS485;

#endif
