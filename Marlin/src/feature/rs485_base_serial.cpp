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

#include "../inc/MarlinConfig.h"
#include "rs485_base_serial.h"


#if HAS_RS485_SERIAL


void rs485_init(){
  //SERIAL_ECHOLNPGM("M485 WORK !!");
  
}

#ifdef HAS_FLOWCONTROLL
void preTransmission()
{
  #ifdef HAS_SINGLE_PIN
  digitalWrite(FLOW_PIN,1);
  #else
  digitalWrite(RE_NEG_PIN, 1);
  digitalWrite(DE_PIN, 1);
  #endif
}

void postTransmission()
{
  #ifdef HAS_SINGLE_PIN
  digitalWrite(FLOW_PIN,0);
  #else
  digitalWrite(RE_NEG_PIN, 0);
  digitalWrite(DE_PIN, 0);
  #endif

}
#endif

rs485_serial::rs485_serial()
{

};
int rs485_serial::init(){
    //RS485_SERIAL.begin(57600);
    //RS485SERIAL.begin(RS485_ID,RS485_SERIAL);


    #if HAS_FLOWCONTROLL
    RS485SERIAL.preTransmission(preTransmission);
    RS485SERIAL.postTransmission(postTransmission);
    #endif
    //SERIAL_ECHOLNPGM("M485 WORK !!");

};




#endif

