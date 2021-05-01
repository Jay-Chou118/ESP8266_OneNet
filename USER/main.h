#ifndef __MAIN_H_
#define __MAIN_H_

#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "beep.h"
#include "dht11.h"
#include "esp8266.h"
#include "onenet.h"

#include <string.h>
#include <stdio.h>


extern u8 temperature_H;  	    	
extern u8 temperature_L;  	    
extern u8 humidity_H;
extern u8 humidity_L;

typedef struct
{
	_Bool beep_data;
	
}BEEP_DATA;

extern BEEP_DATA beep ;

typedef struct
{
	float temperature;
	float humidity;

}DHT11_DATA;

extern DHT11_DATA dht11 ;


#endif
