#include "usart.h"
#include "sys.h"
#include "lcd12864.h"


void GPIO_Configuration(void);

void loop(void){
	int t=0;
	char buf[24],buf2[24];
	float last=0;
	while(1){
		LCD_WriteCommand(LCD_GOTO_LINE1);
		LCD_Print(buf);
		LCD_WriteCommand(LCD_GOTO_LINE2);
		sprintf(buf2,"%.3f",NOW);
		LCD_Print(buf2);
		LCD_WriteCommand(LCD_GOTO_LINE3);
		LCD_Print("LCD12864÷°¬ ≤‚ ‘");
		LCD_WriteCommand(LCD_GOTO_LINE4);
		LCD_Print("LCD12864÷°¬ ≤‚ ‘");
		t++;
		if(t%60==0){
			sprintf(buf,"%.3ffps",60./(NOW-last));
			last=NOW;
		}
	}
}

int main(void)
{
	delay_init();
	uart_init(115200);
	GPIO_Configuration();
	
	LCD_Init();
	loop();
}

void GPIO_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC , ENABLE); 						 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
  GPIO_Init(GPIOC, &GPIO_InitStructure);
}
