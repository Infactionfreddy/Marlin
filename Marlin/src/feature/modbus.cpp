
#include "modbus.h"

#define modbus_serial Serial3
#define master_mode 1
//#define flowcontrol
#define single_pin
#ifndef RX_PIN
#define RX_PIN 0
#define MAX485_RE_NEG 0
#define MAX485_DE 0
#endif
#ifdef flowcontrol
void preTransmission()
{
  #ifdef single_pin
  digitalWrite(RX_PIN,1);
  #else
  digitalWrite(MAX485_RE_NEG, 1);
  digitalWrite(MAX485_DE, 1);
  #endif
}

void postTransmission()
{
  #ifdef single_pin
  digitalWrite(RX_PIN,1);
  #else
  digitalWrite(MAX485_RE_NEG, 0);
  digitalWrite(MAX485_DE, 0);
  #endif

}
#endif
modbus::modbus()
{
  modbus_serial.begin(19200);
  ModbusSerial.begin(id,modbus_serial);
  #ifdef flowcontrol
  ModbusSerial.preTransmission(preTransmission);
  ModbusSerial.postTransmission(postTransmission);
  #endif


}

void modbus::slave(uint16_t modbus_id)
{

}
void modbus::master(uint16_t modbus_id){

}
void modbus::transmission(){

}




