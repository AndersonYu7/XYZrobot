#ifndef SIMPLE_FUNCTION_H
#define SIMPLE_FUNCTION_H

#include <Arduino.h>
#include <EEPROM.h>

// void EERPOM_Update(int _addr, uint8_t _data);
// void EEPROM_Copy(int _addr_org, int _addr_end);
// unsigned int EEPROM_Read_Int(int _addr);
// unsigned long EEPROM_Read_Long(int _addr);
// void EEPROM_Write_Int(int _addr, unsigned int _data);
// void EEPROM_Write_Long(int _addr, unsigned long _data);

class Constant_Timer{
	public:
		boolean Timer_Task(unsigned long _time_zone);
	private:
		unsigned long _last_time;
};

#endif