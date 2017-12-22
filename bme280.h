#ifndef _BSP_bme280_H_
#define _BSP_bme280_H_

#include <stm32f4xx.h>
#include <rtthread.h>
#include "i2c.h"

#ifdef __cplusplus
	extern "C" {
#endif






typedef enum {  
    BMP280_T_MODE_SKIP = 0x0,   /*skipped*/  
    BMP280_T_MODE_1,            /*x1*/  
    BMP280_T_MODE_2,            /*x2*/  
    BMP280_T_MODE_3,            /*x4*/  
    BMP280_T_MODE_4,            /*x8*/  
    BMP280_T_MODE_5             /*x16*/  
} BMP280_T_OVERSAMPLING;  
  
typedef enum {  
    BMP280_SLEEP_MODE = 0x0,  
    BMP280_FORCED_MODE,  
    BMP280_NORMAL_MODE  
} BMP280_WORK_MODE;  
  
typedef enum {  
    BMP280_P_MODE_SKIP = 0x0,   /*skipped*/  
    BMP280_P_MODE_1,            /*x1*/  
    BMP280_P_MODE_2,            /*x2*/  
    BMP280_P_MODE_3,            /*x4*/  
    BMP280_P_MODE_4,            /*x8*/  
    BMP280_P_MODE_5             /*x16*/  
} BMP280_P_OVERSAMPLING;  
  
typedef enum {  
    BMP280_FILTER_OFF = 0x0,    /*filter off*/  
    BMP280_FILTER_MODE_1,       /*0.223*ODR*/  
    BMP280_FILTER_MODE_2,       /*0.092*ODR*/  
    BMP280_FILTER_MODE_3,       /*0.042*ODR*/  
    BMP280_FILTER_MODE_4        /*0.021*ODR*/  
} BMP280_FILTER_COEFFICIENT;  
  
typedef enum {  
    BMP280_T_SB1 = 0x0,     /*0.5ms*/  
    BMP280_T_SB2,           /*62.5ms*/  
    BMP280_T_SB3,           /*125ms*/  
    BMP280_T_SB4,           /*250ms*/  
    BMP280_T_SB5,           /*500ms*/  
    BMP280_T_SB6,           /*1000ms*/  
    BMP280_T_SB7,           /*2000ms*/  
    BMP280_T_SB8,           /*4000ms*/  
} BMP280_T_SB; 

typedef struct bmp280 bmp280_t;
struct bmp280 {
	   i2c_bus_t 					*i2c;
	
    uint16_t T1;  
    int16_t T2;  
    int16_t T3;  
	
		uint16_t P1;  
    int16_t P2;  
    int16_t P3;  
    int16_t P4;  
    int16_t P5;  
    int16_t P6;  
    int16_t P7;  
    int16_t P8;  
    int16_t P9; 
     
	  uint8_t H1;
	  int16_t  H2;
	  uint8_t H3;
	  int16_t  H4;
	  int16_t  H5;
		uint8_t  H6;
    	
    
		int32_t 					temperature,ut;
		uint32_t 					pressure,up;
		uint32_t					humidity,uh;

		int32_t (*check_device)(bmp280_t *bmp);
		int32_t (*init)(bmp280_t *bmp);
		int32_t (*read_reg)(bmp280_t *bmp, uint8_t reg, uint8_t *val);
		int32_t (*write_reg)(bmp280_t *bmp, uint8_t reg, uint8_t val);
		int32_t (*get_cal_param)(bmp280_t *bmp);
		int32_t (*read_data)(bmp280_t *bmp);	
};
extern bmp280_t bmp280;
int32_t bmp280_register(bmp280_t *bmp, i2c_bus_t *i2c);
#ifdef __cplusplus
}
#endif

#endif