#include "stm32f051r8t6.h"

void Init_pin(void)
{
	/*set mode led ld3*/
	unsigned int tmpreg;
	tmpreg = read_reg(GPIOC_MODER,~(0x03 << 18)); 
	tmpreg = tmpreg | (GPIO_MODER_OUTPUT << 18);

	write_reg(GPIOC_MODER, tmpreg);

}

void Turn_on_led(unsigned char pin_number)
{
	write_reg(GPIO_BSRR, 1u << pin_number);
}

void Turn_of_led(unsigned char pin_number)
{
	write_reg(GPIO_BSRR, 1u << (pin_number+16));
}

void delay(unsigned int timeout)
{
    unsigned int t1, t2;
    for (t1 = 0; t1 < timeout; t1++)
    {
        for (t2 = 0; t2 < 0xFFF; t2++)
        {
          asm(" nop");
        }
    }
}

void enable_clock()
{

	unsigned int tmpreg;
	tmpreg = read_reg(RCC_AHBENR,~(1 << 19)); 
	tmpreg = tmpreg | (1 << 19);

	write_reg(RCC_AHBENR,tmpreg);

}

int main()
{
	enable_clock();
	Init_pin();
	while(1)
	{
		Turn_on_led(LD3_PIN);
		delay(0xff);
		Turn_of_led(LD3_PIN);
		delay(0xff);
	}

}
void Reserved_IRQHandler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void NMI_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void HardFault_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void SVC_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void PendSV_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void SysTick_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}
/*************************************************************************************************/
