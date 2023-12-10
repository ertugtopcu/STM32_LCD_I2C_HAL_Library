#ifndef PCF8574_H
#define PCF8574_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include <stdbool.h>
#include <stdint.h>
// Address select pin define
#define A0	'H'
#define A1  'H'
#define A2	'H'

#if   A2 == 'L' && A1 == 'L' && A0 == 'L'
#define I2C_WRITE_ADDR	(uint8_t)0x40
#define I2C_READ_ADDR	(uint8_t)0x41
#elif A2 == 'L' && A1 == 'L' && A0 == 'H'
#define I2C_WRITE_ADDR	(uint8_t)0x42
#define I2C_READ_ADDR	(uint8_t)0x43
#elif A2 == 'L' && A1 == 'H' && A0 == 'L'
#define I2C_WRITE_ADDR	(uint8_t)0x44
#define I2C_READ_ADDR	(uint8_t)0x45
#elif A2 == 'L' && A1 == 'H' && A0 == 'H'
#define I2C_WRITE_ADDR	(uint8_t)0x46
#define I2C_READ_ADDR	(uint8_t)0x47
#elif A2 == 'H' && A1 == 'L' && A0 == 'L'
#define I2C_WRITE_ADDR	(uint8_t)0x48
#define I2C_READ_ADDR	(uint8_t)0x49
#elif A2 == 'H' && A1 == 'L' && A0 == 'H'
#define I2C_WRITE_ADDR	(uint8_t)0x4A
#define I2C_READ_ADDR	(uint8_t)0x4B
#elif A2 == 'H' && A1 == 'H' && A0 == 'L'
#define I2C_WRITE_ADDR	(uint8_t)0x4C
#define I2C_READ_ADDR	(uint8_t)0x4D
#else
#define I2C_WRITE_ADDR	(uint8_t)0x4E
#define I2C_READ_ADDR	(uint8_t)0x4F
#endif

typedef enum {
	RESET_PIN = 0,
	SET_PIN
}pin_status;

//GPIO Pin Define
#define I2C_TIMEOUT 100
#define P0			(uint8_t)0b00000001
#define P1			(uint8_t)0b00000010
#define P2			(uint8_t)0b00000100
#define P3			(uint8_t)0b00001000
#define P4			(uint8_t)0b00010000
#define P5			(uint8_t)0b00100000
#define P6			(uint8_t)0b01000000
#define P7			(uint8_t)0b10000000

void PCF8574_Write_Pin(I2C_HandleTypeDef *hi2c,uint8_t pin , pin_status pin_stat);
bool PCF8574_Read_Pin(I2C_HandleTypeDef *hi2c ,uint8_t pin);
uint8_t PCF8574_Read_Port(I2C_HandleTypeDef *hi2c);
void PCF8574_Write_Port(I2C_HandleTypeDef *hi2c , uint8_t port);

#ifdef __cplusplus
}
#endif
#endif


