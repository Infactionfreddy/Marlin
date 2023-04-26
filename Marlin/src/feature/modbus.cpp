
#include "modbus.h"

#define modbus_serial Serial3
#define master_mode 1

modbus::modbus()
{
  modbus_serial.begin(19200);
  Modbus.begin(id,modbus_serial);
}

void modbus::slave(uint16_t modbus_id)
{

}
void modbus::master(uint16_t modbus_id){

}





