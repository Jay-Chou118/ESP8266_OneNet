#include "main.h"



//const char *topics[] = {"home/garden/fountain"};
//unsigned char  str[] =  {"123"};

int main( void )
{

u8 temperature_H;  	    	
u8 temperature_L;  	    
u8 humidity_H;
u8 humidity_L;

	beep.beep_data = BEEP_OFF ;
	dht11.humidity = temperature_H + temperature_L/100;
	dht11.temperature = humidity_H + humidity_L/100;

	u8 t = 0;
	
	unsigned short timeCount = 0;  //���ͼ������
	unsigned char *dataPtr = NULL;

	
	NVIC_PriorityGroupConfig( NVIC_PriorityGroup_2 );       /* ����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ� */
	Usart1_Init(115200);   	/* ���ڳ�ʼ��Ϊ115200 */
	Usart2_Init(115200);
	delay_init();                                           /* ��ʱ������ʼ�� */
	LED_Init();            
	BEEP_Init();
	DHT11_Init();
	
	ESP8266_Init();

	
	while(OneNet_DevLink())  //����OneNet
		delay_ms(500);
	BEEP = 1;
	delay_ms(250);
	BEEP = 0;
	
	//OneNet_Subscribe(topics,1);
	
	UsartPrintf(USART_DEBUG, "Hardware init OK\r\n");
	
	
	while(1)
	{
		UsartPrintf(USART1,"���Կ�ʼ��\r\n" );
		UsartPrintf(USART1," t = %d ; timeCount = %d\r\n",t,timeCount);	
		//UsartPrintf(USART1,"/r/n���͵�����Ϊ /r/n" );

		//UsartPrintf(USART1,"�¶� �� %d.%d ��\r\nʪ�� �� %d.%d  \r\n"  ,temperature_H,temperature_L,humidity_H,&humidity_L);
		//for(int i = 0;i<3;i++)
		//{
		//	unsigned char ch = (unsigned char)str[i];
		//}

		if(t%10==0)			//ÿ100ms��ȡһ��
		{									  
			DHT11_Read_Data(&temperature_H,&temperature_L,&humidity_H,&humidity_L);	//��ȡ��ʪ��ֵ			
			UsartPrintf(USART1,"�¶� �� %d.%d ��\r\nʪ�� �� %d.%d  \r\n"  ,temperature_H,temperature_L,humidity_H,&humidity_L);
			//LCD_ShowNum(30+40,190,temperature,2,16);	//��ʾ�¶�	   		   
			//LCD_ShowNum(30+40,210,humidity,2,16);		//��ʾʪ��	 	   
		}				   
	 	delay_ms(10);
		t+=20;
		UsartPrintf(USART1," t = %d ; timeCount = %d\r\n",t,timeCount);
		if(t==20)
		{
			t=0;
			UsartPrintf(USART1,"��תLED\r\n");
			LED0=!LED0;
		}
	
		timeCount+=250;
		//delay_ms(2000);
		//timeCount+=250;
		UsartPrintf(USART1," t = %d ; timeCount = %d\r\n",t,timeCount);
		//if(++timeCount >= 500)									//���ͼ��5s
		if(timeCount >= 500)
		{
			UsartPrintf(USART_DEBUG, "OneNet_Publish\r\n");
			
		//	OneNet_Publish("home/garden/fountain", "MQTT Publish Test");
			
			OneNet_SendData();  //����δ��ɣ���ע�����л����.ʵ����û�г������ٶȹ�����
			
			timeCount = 0;
			ESP8266_Clear();
		}
		
		dataPtr = ESP8266_GetIPD(0);
		if(dataPtr != NULL)
			OneNet_RevPro(dataPtr);
	
		delay_ms(10);


		
	}
}




