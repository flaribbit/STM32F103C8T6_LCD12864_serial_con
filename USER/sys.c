#include "sys.h"

//static u8 fac_us=0;							//us��ʱ������
//static u8 fac_ms=0;							//us��ʱ������	
int sysms=0;

void delay_init()
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);	//ѡ���ⲿʱ��HCLK/8
	SysTick->LOAD=9000;
	SysTick->CTRL|=SysTick_CTRL_TICKINT_Msk;//�����ж�
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk;	//��������
	//fac_us=SystemCoreClock/8000000;		//Ϊϵͳʱ�ӵ�1/8
	//fac_ms=(u16)fac_us*1000;					//��OS��,����ÿ��ms��Ҫ��systickʱ����
}

void SysTick_Handler(void)
{	
	sysms++;
}

void delay_ms(int ms){
	int t0=sysms;
	while(sysms-t0<ms);
}

void delay_us(int us){
	us*=9;
	while(us--);
}

void delay(float t){
	float t0=NOW;
	while(NOW-t0<t);
}
