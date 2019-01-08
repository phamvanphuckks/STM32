#include "stm32f051r8t6.h"

void Init_pin(void)
{
	/*set mode led ld3*/
	unsigned int tmpreg;
	tmpreg = read_reg(GPIOC_MODER,~(0x03 << 18)); 
	tmpreg = tmpreg | (GPIO_MODER_OUTPUT << 18);
	
	write_reg(GPIOC_MODER, tmpreg);

}
void Init_button(void)
{
	/*set mode button PA0*/
	unsigned int tmpreg;
	tmpreg = read_reg(GPIOC_MODER,~(0x03 << 0)); 
	tmpreg = tmpreg | (GPIO_MODER_INPUT << 0);
	
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

// chuyen hoa no sang con tro.

void enable_clock()
{

	/*led*/
	unsigned int tmpreg;
	tmpreg = read_reg(RCC_AHBENR,~(1 << 19)); 
	tmpreg = tmpreg | (1 << 19);
	write_reg(RCC_AHBENR,tmpreg);

	/*button*/
	tmpreg = read_reg(RCC_AHBENR,~(1 << 17)); // doc thanh ghi va xoa vi tri thu 17
	tmpreg = tmpreg | (1 << 17); // set len 1
	write_reg(RCC_AHBENR,tmpreg); // ghi vao thanh ghi


}

int main()
{
	enable_clock();
	Init_pin();
	Init_button();

	unsigned int state_idr_reg;
	unsigned int led_state = 0;
	while(1)
	{

		/*polling : kiem tra 1 doi tuong nao do theo chu ki nhat dinh va  lap di lap lai*/
		/*polling : khong biet dc minh dang giu phim hay nha ra hay chua*/
		state_idr_reg = read_reg(GIPOA_IDR, 1 << 0); // chi doc trang thai PA0, con lai se bang 0 het

		if( 1 == state_idr_reg)
		{

			if( 0 == led_state)
			{

				Turn_on_led(LD3_PIN);
				delay(0xff);
				led_state = 1;
			}
			else
			{
				Turn_of_led(LD3_PIN);
				delay(0xff);
				led_state = 0;
			}
		}
	//	delay(0xf);
		
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