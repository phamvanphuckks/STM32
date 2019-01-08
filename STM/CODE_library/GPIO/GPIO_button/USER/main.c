#include "stm32f0xx.h"
#include "stm32f0xx_flash.h"
#include "stm32f0xx_gpio.h"
#include "stm32f0xx_rcc.h"

/*trong qua trinh set-up target : co dong USE_STDPRERIPH_DRIVE : de su dung header file stm32f0xx.h*/

GPIO_InitTypeDef GPIO_Struct ;

void GPIO_Config_Button(void);
void Fn_DELAY_Long(unsigned int _vrui_Time);

unsigned char status ;
unsigned char led_status;

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	GPIO_Config_Button();
	while(1)
	{
		/*khi giu la den sang 
			if( (GPIO_ReadInputData(GPIOA) & GPIO_Pin_0) == 1)
			{
				GPIO_SetBits(GPIOC, GPIO_Pin_8);
				Fn_DELAY_Long(1000);
			}
			else
			{
				GPIO_ResetBits(GPIOC, GPIO_Pin_8);
				Fn_DELAY_Long(1000);
			}
			Fn_DELAY_Long(10);
	
		*/

		// khi nhan mot cai den dang tat - sang , sang -tat polling
		// no khong phan duoc khi nao minh nhan - khi nao minh nha
	 // khi chung ta an mot cai den sang la status = 1, bit 1 set 1 trong while hihi
			status = (GPIO_ReadInputData(GPIOA)&GPIO_Pin_0);
			if(1 == status)
			{
				if(led_status == 1)
				{
						GPIO_SetBits(GPIOC, GPIO_Pin_8);
						Fn_DELAY_Long(1000);
						led_status = 0;
				}
				else
				{
						GPIO_ResetBits(GPIOC, GPIO_Pin_8);
						Fn_DELAY_Long(1000);
						led_status = 1;
				}
		 }
		 Fn_DELAY_Long(100);
	}
}
void GPIO_Config_Button(void)
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC|RCC_AHBPeriph_GPIOA,ENABLE);
	GPIO_Struct.GPIO_Pin = GPIO_Pin_8;
	GPIO_Struct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Struct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC , &GPIO_Struct);
	
	GPIO_Struct.GPIO_Pin = GPIO_Pin_0;
	GPIO_Struct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Init(GPIOC, &GPIO_Struct);
}

void Fn_DELAY_Long  (unsigned int _vrui_Time)
{
	unsigned int vrui_i;
	while(_vrui_Time--)
	{
		for(vrui_i = 0; vrui_i < 1000; vrui_i++);
	}
}

