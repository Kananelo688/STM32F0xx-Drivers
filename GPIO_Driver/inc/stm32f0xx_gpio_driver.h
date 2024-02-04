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
#define GPIO_AR00  					(uint8_t) 0x00
#define GPIO_AR01  					(uint8_t) 0x01
#define GPIO_AR02  					(uint8_t) 0x02
#define GPIO_AR03  					(uint8_t) 0x03
#define GPIO_AR04  					(uint8_t) 0x04
#define GPIO_AR05  					(uint8_t) 0x05
#define GPIO_AR06  					(uint8_t) 0x06
#define GPIO_AR07  					(uint8_t) 0x07

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
	uint16_t				LCKR; 			/*GPIO LOCK REGISTER 					ADDRESS OFFSET 0x1C			*/
	uint16_t			__Reserved3;		/*			RESERVED 												*/
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


#endif
