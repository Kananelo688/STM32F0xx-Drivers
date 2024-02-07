/************************************************************************************************************
 *Assembly source file that implements some if the functions defined in the stm32f0xx_gpio_driver.h interface
 *
 *
 *@author: Kananelo
 *@version: 06/02/2024
 *
 ***/



 .text

 .globl, GPIO_Set_Pin_AF 			@declare the symbol 'GPIO_Set_Pin_AF', as global
 .type function, GPIO_Set_Pin_AF	@declare the type of the symbol as function

/*
	Function declaration: The function sets the alternate function of the given GPIO port pin

	the function takes as the argument, GPIO base (passed in r0), GPIO_Pin_Number (passed in r1), and
	Alternate function number (passed in r2.), the value of the alternate function must be between 0 and 7, inclusive.
*/

 GPIO_Set_Pin_AF:

 	mov r3, #8 						@load value 8 into r3
 	cmp r1, r3						@check if pin number if less than 8 to greater than or equal to 8
 	bge Init_AFH					@breach to Init_AFL low if PIN<7 to initialize GPIO_AFHR register
 	ldr r4, [r0, #0x20]				@load the current value of the GPIOx_AFHR
 
 set_AF:
 	lsl r1, #2 						@multiply the pin number by 4 (shifting to the left by 2)
 	lsl r2, r1 						@shift the AF number by  the pin number * 4 (set set the appropriate pin)
 	orr r4,r2 						@perform orr with the current value of AFLR or AFHR
 	//STORE REGISTER

Init_AFH:
	ldr r4, [r0, #0x24] 			@load the current value GPIO_AFHR register into r4
	sub r2, r3						@subtract 8 (in r8), from r2 (pin number)
	