#include "stm32f0xx.h"
#include "stm32f0xx_conf.h"
#include "stm32f0xx_flash.h"
#include "stm32f0xx_gpio.h"
#include "stm32f0xx_rcc.h"

GPIO_InitTypeDef GPIO_Struct ;

void GPIO_Config(void);
void Fn_DELAY_Long(unsigned int _vrui_Time);

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	GPIO_Config();
	while(1)
	{
			GPIO_SetBits(GPIOC, GPIO_Pin_9);
			Fn_DELAY_Long(1000);
			GPIO_ResetBits(GPIOC, GPIO_Pin_9);
			Fn_DELAY_Long(1000);
	}
}

void GPIO_Config(void)
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC,ENABLE);
	GPIO_Struct.GPIO_Pin = GPIO_Pin_9;
	GPIO_Struct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Struct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC , &GPIO_Struct);
}

void Fn_DELAY_Long  (unsigned int _vrui_Time)
{
	unsigned int vrui_i;
	while(_vrui_Time--)
	{
		for(vrui_i = 0; vrui_i < 1000; vrui_i++);
	}
}
