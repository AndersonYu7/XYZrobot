#include "Simple_Function.h"

static unsigned long data_long;
static unsigned long data_sum_long;

// void EERPOM_Update(int _addr, uint8_t _data){
// 	if(EEPROM.read(_addr) != _data) EEPROM.write(_addr, _data);
// }
// void EEPROM_Copy(int _addr_org, int _addr_end){
// 	static uint8_t _temp = 0x00;
// 	_temp = EEPROM.read(_addr_org);
// 	EERPOM_Update(_addr_end, _temp);
// }
// unsigned int EEPROM_Read_Int(int _addr){
// 	data_sum_long = 0;
// 	data_long = EEPROM.read(_addr);
// 	data_sum_long += data_long;
// 	data_long = EEPROM.read(_addr + 1);
// 	data_sum_long += (data_long << 8);
// 	return (unsigned int)data_sum_long;
// }
// unsigned long EEPROM_Read_Long(int _addr){
// 	data_sum_long = 0;
// 	data_long = EEPROM.read(_addr);
// 	data_sum_long += data_long;
// 	data_long = EEPROM.read(_addr + 1);
// 	data_sum_long += (data_long << 8);
// 	data_long = EEPROM.read(_addr + 2);
// 	data_sum_long += (data_long << 16);
// 	data_long = EEPROM.read(_addr + 3);
// 	data_sum_long += (data_long << 24);
// 	return data_sum_long;
// }
// void EEPROM_Write_Int(int _addr, unsigned int _data){
// 	static uint8_t _temp = 0x00;
// 	_temp = (_data & 0x00FF);
// 	EERPOM_Update(_addr, _temp);
// 	_temp = (_data & 0xFF00) >> 8;
// 	EERPOM_Update(_addr + 1, _temp);
// }
// void EEPROM_Write_Long(int _addr, unsigned long _data){
// 	static uint8_t _temp = 0x00;
// 	_temp = (_data & 0x000000FF);
// 	EERPOM_Update(_addr, _temp);
// 	_temp = (_data & 0x0000FF00) >> 8;
// 	EERPOM_Update(_addr + 1, _temp);
// 	_temp = (_data & 0x00FF0000) >> 16;
// 	EERPOM_Update(_addr + 2, _temp);
// 	_temp = (_data & 0xFF000000) >> 24;
// 	EERPOM_Update(_addr + 3, _temp);
// }

boolean Constant_Timer::Timer_Task(unsigned long _time_zone){
	if((millis() - _last_time) >= _time_zone){
		_last_time = millis();
		return true;
	}
	return false;
}