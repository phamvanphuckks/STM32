#ifndef __STM32F051R8T6_H__
#define __STM32F051R8T6_H__


#define write_reg(addr, value)					*((unsigned long int*)(addr)) = value 
#define read_reg(addr, mask)					*((unsigned long int*)(addr)) & (mask)

/*
	1, start address
	2, address offeset
*/

/*CLOCK*/
#define BASE_ADDR_RCC					0x40021000u
#define RCC_AHBENR						(BASE_ADDR_RCC + 0x14u)

/*GPIO*/
#define BASE_ADDR_GPIOC				0x48000800u 
#define BASE_ADDR_GPIOA				0x48000000u 

#define GPIOC_MODER		  			(BASE_ADDR_GPIOC + 0x00u)
#define GPIOA_MODER					(BASE_ADDR_GPIOA + 0x00u)

#define GPIO_MODER_INPUT			0x00u
#define GPIO_MODER_OUTPUT			0x01u
#define GPIO_MODER_ALTERNATE		0x02u
#define GPIO_MODER_ANALOG			0x03u

#define GPIO_BSRR 					(BASE_ADDR_GPIOC + 0x18u)
#define GPIOA_PUPDR					(BASE_ADDR_GPIOA + 0x0Cu)

#define GIPOA_IDR					(BASE_ADDR_GPIOA + 0x10u)

/*BUTTON*/
#define BUTTON_PIN					0


/*Led 3 : PC9*/

#define LD3_PIN		9




#endif