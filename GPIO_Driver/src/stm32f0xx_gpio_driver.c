/************************************************************************************************************
 *Assembly source file that implements some if the functions defined in the stm32f0xx_gpio_driver.h interface
 *
 *
 *@author: Kananelo
 *@version: 06/02/2024
 *
 ***/



 #include "stm32f0xx_gpio_driver.h"


/****************************************************************************************************************
 * 																												*
 * 							GPIO_Set_Pin_AF																		*
 * 																												*
 * @brief: takes in the GPIO_Typedef structure pointer , pin number and GPIO speed and sets theE  AF of thE pin *
 *																												*
 * @params: <gpio> - a pointer to GPIO_Typedef structure 														* 
 * 																												*
 * 			<pin> an 8-bit number that represent the GPIO port pin number for which its AF is to be set 		*
 * 																												*
 * 			<speed> an 8-bit number that represents the speed to set the GPIO port pin.			 				*
 * 																												*
 * @returns: None																								*
 * 																												*
 **************************************************************************************************************** 
 **/

void GPIO_Set_Pin_AF
(GPIO_Typedef* gpio,const GPIO_Pin_Number pin,const GPIO_AF function)
{
	if(pin <= GPIO_PIN_7){
		
		if(function == GPIO_AF00){

			gpio -> AFRL &= ~(0x0F<<pin*4);
			return;
		}

		gpio -> AFRL |= (function << pin*4);
	}
	else 
	{
		if(function == GPIO_AF00){

			gpio -> AFRH &= ~(0x0F<<(pin-GPIO_PIN_8)*4);
			return;
		}

		gpio -> AFRH |= (function << (pin-GPIO_PIN_8)*4);
	}
}