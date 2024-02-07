/**
 * source file that has main function which tests GPIO driver functions
 * 
 * */

#include "stm32f0xx_drivers.h"

#include "stm32f0xx_gpio_driver.h"

uint32_t slave = 0x203201DF;

int main(void)
{

	RCC_AHB_Clock_Enable(RCC_AHBENR_GPIOBEN);
	RCC_AHB_Clock_Enable(RCC_AHBENR_GPIOAEN);


	GPIO_Set_Pin_Mode(GPIOB, GPIO_PIN_0, GPIO_OUTPUT_MODE);
	GPIO_Set_Pin_Mode(GPIOA, GPIO_PIN_0, GPIO_INPUT_MODE);

	GPIO_Set_Pin_Resistor(GPIOA,GPIO_PIN_0, GPIO_PULL_UP);


	while(1)
	{

		if(!GPIO_Get_State(GPIOA, GPIO_PIN_0)){

			GPIO_Toggle_Pin(GPIOB,GPIO_PIN_0);
		}
	}

	return 0;
}