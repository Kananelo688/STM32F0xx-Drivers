/****************************************************************************************************************
 * 																												*
 * STM32F0xx GPIO driver headef file that define MACROS, Strucure and Functions that are typically used with	*	
 * GPIO peripheral development.																					*
 * 																												*
 * 																												*
 * @author: Kananelo Chabeli																					*
 * @version: 04-Feb-2024																						*
 * 																												*
 * **************************************************************************************************************
 * */

#ifndef STM32F0XX_GPIO_H

#define STM32F0XX_GPIO_H


/****************************************************************************************************************
 * 												INCLUDES														*						
 ****************************************************************************************************************
 **/

#include <stdint.h>

/****************************************************************************************************************
 * 												GPIO BASE ADDRESSES												*
 **************************************************************************************************************** 
 **/

#define GPIOA_BASE 					0x48000000U
#define GPIOB_BASE 					0x48000400U
#define GPIOC_BASE 					0x48000800U
#define GPIOD_BASE 					0x48000C00U
#define GPIOE_BASE 					0x48001000U
#define GPIOF_BASE					0x48001400U

/****************************************************************************************************************
 * 										GPIO PIN NUMBERS														*
 **************************************************************************************************************** 
 **/
#define GPIO_PIN_0 					(uint8_t) 0x00
#define GPIO_PIN_1 					(uint8_t) 0x01
#define GPIO_PIN_2 					(uint8_t) 0x02
#define GPIO_PIN_3 					(uint8_t) 0x03
#define GPIO_PIN_4 					(uint8_t) 0x04
#define GPIO_PIN_5 					(uint8_t) 0x05
#define GPIO_PIN_6 					(uint8_t) 0x06
#define GPIO_PIN_7 					(uint8_t) 0x07
#define GPIO_PIN_8 					(uint8_t) 0x08
#define GPIO_PIN_9 					(uint8_t) 0x09
#define GPIO_PIN_10 				(uint8_t) 0x0A
#define GPIO_PIN_11					(uint8_t) 0x0B
#define GPIO_PIN_12					(uint8_t) 0x0C
#define GPIO_PIN_13 				(uint8_t) 0x0D
#define GPIO_PIN_14					(uint8_t) 0x0E
#define GPIO_PIN_15					(uint8_t) 0x0F

/****************************************************************************************************************
 * 									GPIO ALTERNATE FUNCTIONS													*
 **************************************************************************************************************** 
 **/
#define GPIO_AF00  					(uint8_t) 0x00
#define GPIO_AF01  					(uint8_t) 0x01
#define GPIO_AF02  					(uint8_t) 0x02
#define GPIO_AF03  					(uint8_t) 0x03
#define GPIO_AF04  					(uint8_t) 0x04
#define GPIO_AF05  					(uint8_t) 0x05
#define GPIO_AF06  					(uint8_t) 0x06
#define GPIO_AF07  					(uint8_t) 0x07

/****************************************************************************************************************
 * 									GPIO PORT PIN MODES															*
 **************************************************************************************************************** 
 **/

#define GPIO_INPUT_MODE					0x00U
#define GPIO_OUTPUT_MODE				0X01U
#define GPIO_ALTERNATE_MODE				0x02U
#define GPIO_ANALOG_MODE				0x03U

/****************************************************************************************************************
 * 									GPIO PORT PIN SPEEDS														*
 **************************************************************************************************************** 
 **/

#define GPIO_LOW_SPEED 					0x00U
#define GPIO_MEDIUM_SPEED				0x01U
#define GPIO_HIGH_SPEED					0x03U

/****************************************************************************************************************
 * 									GPIO PORT PIN TYPES															*
 **************************************************************************************************************** 
 **/
#define GPIO_PUSH_PULL					0x00U
#define GPIO_OPEN_DRAIN 				0x01U

/****************************************************************************************************************
 * 									GPIO PORT PIN RESISTORS														*
 **************************************************************************************************************** 
 **/

#define GPIO_PULL_UP					0x01U
#define GPIO_PULL_DOWN					0x02U

/****************************************************************************************************************
 * 									GPIO PORT PIN RESISTORS														*
 **************************************************************************************************************** 
 **/

#define GPIO_ON 						0x01U
#define GPIO_OFF 						0x00U

/****************************************************************************************************************
 * 									GPIO DRIVER TYPEDEFS														*
 **************************************************************************************************************** 
 **/

typedef uint8_t GPIO_Pin_Number;
typedef uint8_t GPIO_Mode;
typedef uint8_t GPIO_Speed;
typedef uint8_t GPIO_Type;
typedef uint8_t GPIO_AF;
typedef uint8_t GPIO_Resistor;
typedef uint8_t GPIO_State;
/****************************************************************************************************************
 * 									GPIO STRUCTURE DECLARATION													*
 **************************************************************************************************************** 
 * */
typedef struct
{
	uint32_t 				MODER; 			/*GPIO MODE REGISTER 					ADDRESS OFFSET 0x00			*/
	uint16_t				OTYPER; 		/*GPIO OUTPUT TYPE REGISTER 			ADDRESS OFFSET 0x04			*/				
	uint16_t			__Reserved0; 		/*			RESERVED 												*/
	uint32_t				OSPEEDR;		/*GPIO OUTPUT SPEED REGISTER 			ADDRESS OFFSET 0x08			*/
	uint32_t				PUPDR; 			/*GPIO PULL UP PULL DOWN REGISTER		ADDRESS OFFSET 0x0C			*/		
	uint16_t				IDR; 			/*GPIO INPUT DATA REGISTER 			 	ADDRESS OFFSET 0x10			*/
	uint16_t			__Reserved1;		/*			RESERVED 												*/
	uint16_t				ODR; 			/*GPIO OUTPUT DATA REGISTER 			ADDRESS OFFSET 0X14			*/
	uint16_t			__Reserved2;		/*			RESERVED 												*/
	uint32_t				BSRR; 			/*GPIO BIT SET/RESET REGISTER 			ADDRESS OFFSET 0x18			*/
	uint32_t				LCKR; 			/*GPIO LOCK REGISTER 					ADDRESS OFFSET 0x1C			*/
	uint32_t 				AFRL; 			/*GPIO ALTERNATE FUNCTION LOW REGISTER  ADDRESS OFFSET 0x20			*/
	uint32_t 				AFRH; 			/*GPIO ALTERNATE FUNCTION HIGH REGISTER ADDRESS OFFSET 0x24			*/
	uint16_t				BRR; 			/*GPIO BIT RESET REGISTER 				ADDRESS OFFSET 0x28			*/
	uint16_t			__Reserved4;		/*			RESERVED 												*/


} GPIO_Typedef;

/****************************************************************************************************************
 * 									GPIO POINTERS																*
 **************************************************************************************************************** 								
 * */


#define GPIOA ((GPIO_Typedef*) GPIOA_BASE)
#define GPIOB ((GPIO_Typedef*) GPIOB_BASE)
#define GPIOC ((GPIO_Typedef*) GPIOC_BASE)
#define GPIOD ((GPIO_Typedef*) GPIOD_BASE)
#define GPIOE ((GPIO_Typedef*) GPIOE_BASE)
#define GPIOF ((GPIO_Typedef*) GPIOF_BASE)

/****************************************************************************************************************
 * 									FUNCTION PROTOTYPES															*
 **************************************************************************************************************** 
 **/


/****************************************************************************************************************
 * 																												*
 * 							GPIO_Set_Pin_Mode()																	*
 * 																												*
 * @brief: takes in the GPIO_Typedef structure pointer , pin number and GPIO mode and sets the mode of that pin *
 *																												*
 * @params: <gpio> - a pointer to GPIO_Typedef structure for which its pin is to be set to given mode 			* 
 * 																												*
 * 			<pin> an 8-bit number that represent the GPIO port pin number for which its MODE is to be set 		*
 * 																												*
 * 			<mode> an 8-bit number that represents the mode to set the GPIO port pin. IT must be one of 		*
 * 					GPIO_INPUT_MODE, GPIO_OUTPUT_MODE, GPIO_ALTERNAT_MODE or GPIO_ANALOG_MODE 					*
 * 																												*
 * @returns: None																								*
 * 																												*
 **************************************************************************************************************** 
 **/

__attribute__((always_inline)) static inline void GPIO_Set_Pin_Mode
(GPIO_Typedef* gpio,GPIO_Pin_Number pin, GPIO_Mode mode)

{
	if(mode == GPIO_INPUT_MODE){
		 gpio -> MODER &= ~(0x03<< 2* pin);
		 return ;
	}

	gpio -> MODER |= mode << 2*pin;
}

/****************************************************************************************************************
 * 																												*
 * 							GPIO_Set_Pin_Speed																	*
 * 																												*
 * @brief: takes in the GPIO_Typedef structure pointer , pin number and GPIO speed and sets the speed of th pin *
 *																												*
 * @params: <gpio> - a pointer to GPIO_Typedef structure 														* 
 * 																												*
 * 			<pin> an 8-bit number that represent the GPIO port pin number for which its speed is to be set 		*
 * 																												*
 * 			<speed> an 8-bit number that represents the speed to set the GPIO port pin. IT must be one of 		*
 * 					GPIO_LOW_SPEED, GPIO_MEDIUM_SPEED, or  GPIO_HIGH_SPEED 					 					*
 * 																												*
 * @returns: None																								*
 * 																												*
 **************************************************************************************************************** 
 **/

__attribute__((always_inline)) static inline void GPIO_Set_Pin_Speed
(GPIO_Typedef* gpio,GPIO_Pin_Number pin, GPIO_Speed speed)

{
		if(speed== GPIO_LOW_SPEED){

			gpio ->OSPEEDR &= ~(0x03<< 2* pin);
			return;
		}

		gpio -> OSPEEDR |= speed << 2* pin;
}

/****************************************************************************************************************
 * 																												*
 * 							GPIO_Set_Pin_Type																	*
 * 																												*
 * @brief: takes in the GPIO_Typedef structure pointer , pin number and GPIO type  and sets th type   of th pin *
 *																												*
 * @params: <gpio> - a pointer to GPIO_Typedef structure 														* 
 * 																												*
 * 			<pin> an 8-bit number that represent the GPIO port pin number for which its type is to be set 		*
 * 																												*
 * 			<speed> an 8-bit number that represents the type to set the GPIO port pin. It must be one of 		*
 * 					GPIO_PULL_UP, or GPIO_PULL_DOWN	 					 					 					*
 * 																												*
 * @returns: None																								*
 * 																												*
 **************************************************************************************************************** 
 **/

__attribute__((always_inline)) static inline void GPIO_Set_Pin_Type
(GPIO_Typedef* gpio,GPIO_Pin_Number pin, GPIO_Type type)
{

	if(type == GPIO_PUSH_PULL){

		gpio -> OTYPER &= (0x01<< pin);
	}
	 gpio -> OTYPER |= type <<pin;
}

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

 __attribute__((always_inline)) static inline void GPIO_Set_Pin_AF 
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

/****************************************************************************************************************
 * 																												*
 * 							GPIO_Set_Pin_Resistor																*
 * 																												*
 * @brief: takes in the GPIO_Typedef structure pointer , pin number and GPIO resistor.				    		*
 *																												*
 * @params: <gpio> - a pointer to GPIO_Typedef structure 														* 
 * 																												*
 * 			<pin> an 8-bit number that represent the GPIO port pin number for which its speed is to be set 		*
 * 																												*
 * 			<speed> an 8-bit number that represents the resistorr to set the GPIO port pin. 					*					 					*
 * 																												*
 * @returns: None																								*
 * 																												*
 **************************************************************************************************************** 
 **/

__attribute__((always_inline)) static inline void GPIO_Set_Pin_Resistor
(GPIO_Typedef* gpio,const GPIO_Pin_Number pin, const GPIO_Resistor res)
{
	gpio -> PUPDR |= res << pin *2 ;
}

/************************************************************************************************************
 * 								GPIO_Toggle_Pin																*
 * 																											*
 * @brief: toggles the given GPIO pin.																		*
 * 																											*
 * @param gpio- the pointer to GPIO_Typedef for the GPIO being accessed.									*
 * 																											*
 * @param pin - the GPIO port pin number which is to be toggled.											*
 * 																											*
 * @retval: None																							*
 * 																											*
 * **********************************************************************************************************
 * */

__attribute__((always_inline)) static inline void GPIO_Toggle_Pin(GPIO_Typedef* gpio, GPIO_Pin_Number pin){

	gpio -> ODR ^= 1 << pin;
}

/************************************************************************************************************
 * 								GPIO_Get_State																*
 * 																											*
 * @brief: Returns the GPIO_State of the given GPIO_Pin_Number												*
 * 																											*
 * @param gpio- the pointer to GPIO_Typedef for the GPIO being accessed.									*
 * 																											*
 * @param pin - the GPIO port pin number whose state is returned											*
 * 																											*
 * @retval: GPIO_State - either GPIO_ON or GPIO_OFF depending of the value of GPIO_IDR						*
 * 																											*
 * **********************************************************************************************************
 * */
__attribute__((always_inline)) static inline GPIO_State GPIO_Get_State(GPIO_Typedef* gpio, GPIO_Pin_Number pin)
{

	if(gpio->IDR & 0x01<<pin) return GPIO_ON;

	return GPIO_OFF;

}


#endif
