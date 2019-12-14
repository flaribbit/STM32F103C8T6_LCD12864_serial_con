#include "sys.h"

//static u8 fac_us=0;							//us延时倍乘数
//static u8 fac_ms=0;							//us延时倍乘数	
int sysms=0;

void delay_init()
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);	//选择外部时钟HCLK/8
	SysTick->LOAD=9000;
	SysTick->CTRL|=SysTick_CTRL_TICKINT_Msk;//开启中断
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk;	//开启倒数
	//fac_us=SystemCoreClock/8000000;		//为系统时钟的1/8
	//fac_ms=(u16)fac_us*1000;					//非OS下,代表每个ms需要的systick时钟数
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
