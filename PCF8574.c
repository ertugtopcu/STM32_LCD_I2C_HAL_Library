
#ifdef __cplusplus
extern "C" {
#endif
#include "PCF8574.h"


void PCF8574_Write_Pin(I2C_HandleTypeDef *hi2c , uint8_t pin , pin_status pin_stat)
{    uint8_t Datas[2];
	 uint8_t GPIO_State;
	 GPIO_State = PCF8574_Read_Port(hi2c);
	if( pin_stat == RESET_PIN){
		pin = ~pin;
	    Datas[0] = pin & GPIO_State;
	    Datas[1] = pin & GPIO_State;
		HAL_I2C_Master_Transmit(hi2c,I2C_WRITE_ADDR, Datas , 2, I2C_TIMEOUT);
	}
	else if( pin_stat == SET_PIN) {
		Datas[0] = pin | GPIO_State;
		Datas[1] = pin | GPIO_State;
		HAL_I2C_Master_Transmit(hi2c,I2C_WRITE_ADDR, Datas , 2, I2C_TIMEOUT);
	}
}
bool PCF8574_Read_Pin(I2C_HandleTypeDef *hi2c ,uint8_t pin)
{   uint8_t Data;
	HAL_I2C_Master_Receive(hi2c, I2C_READ_ADDR, &Data , 1, I2C_TIMEOUT);
	if((Data & pin) == SET_PIN)
		return true;
	else
		return false;
}
void PCF8574_Write_Port(I2C_HandleTypeDef *hi2c , uint8_t port)
{	uint8_t Datas[2] = {port,port};
	HAL_I2C_Master_Transmit(hi2c, I2C_WRITE_ADDR, Datas, 2, I2C_TIMEOUT);
}
uint8_t PCF8574_Read_Port(I2C_HandleTypeDef *hi2c)
{   uint8_t port;
    HAL_I2C_Master_Receive(hi2c, I2C_READ_ADDR, &port, 1, I2C_TIMEOUT);
	return port;
}

#ifdef __cplusplus
}
#endif
