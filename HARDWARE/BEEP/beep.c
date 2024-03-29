#include "beep.h"
#include "sys.h"





void BEEP_Init(void)
{ 
    GPIO_InitTypeDef GPIO_InitStructure;
 	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //使能PC端口时钟
	
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				 //LED2-->PC13 端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
    GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化PC13
    GPIO_SetBits(GPIOA,GPIO_Pin_0);						 ////PC13输出低，关闭所有LED						
}
