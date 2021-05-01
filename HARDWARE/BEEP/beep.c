#include "beep.h"
#include "sys.h"





void BEEP_Init(void)
{ 
    GPIO_InitTypeDef GPIO_InitStructure;
 	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //ʹ��PC�˿�ʱ��
	
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				 //LED2-->PC13 �˿�����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
    GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��PC13
    GPIO_SetBits(GPIOA,GPIO_Pin_0);						 ////PC13����ͣ��ر�����LED						
}
