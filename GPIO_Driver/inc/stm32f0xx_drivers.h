/****************************************************************************************************************
 * 																												*
 * An Interface for STM32F0xx microcontroller driver development. The header file contains MACROS and structures*
 * that are usable across other drivers such as EXTI usable by GPIO_Driver, and well function prototypes used by*
 * other drivers.																								*
 * 																												*			
 * Some peripherals that are general for the STM32F0xx microcontrollers are defined here and functions are 		*	
 * implemented in "stm32f0xx_drivers.c" source file.															*
 * 																												*	
 * @author: Kananelo Chabeli																					*
 * @version: 04-Feb-2024																						*
 * **************************************************************************************************************
 * */

#ifndef STM32F0XX_DRIVERS_H

#define STM32F0XX_DRIVERS_H


/****************************************************************************************************************
 * 											INCLUDES															*
 * **************************************************************************************************************					
 * */

#include <stdint.h>

/****************************************************************************************************************
 * 											DEFINES																*
 * **************************************************************************************************************
 * */

#define RCC_BASE 		0x40021000U				/*Reset and Clock Control peripheral base address				*/
#define SYSCFG_BASE 	0x40010000U				/*System Configuration peripheral base address 					*/
#define EXTI_BASE 		0x40010400U				/*Extended interrupt controller peripheral base address         */
#define DMA_BASE 		0x40020000U				/*DMA peripheral base address									*/

// Bit positions of peripheral on the RCC_AHBENR register

#define DMA_POSITION		0
#define DMA2_POSITION		1
#define SRAM_POSITION		2
#define FLITF_POSITION		4
#define CRC_POSITION		6
#define GPIOA_POSITION		17
#define GPIOB_POSITION		18
#define GPIOC_POSITION		19
#define GPIOD_POSITION		20
#define GPIOE_POSITION		21
#define GPIOF_POSITION		22
#define TSC_POSITION		24

//Bit positions of peripherals on the RCC_APB1ENR register

#define TIM2_POSITION		0
#define TIM3_POSITON		1
#define TIM6_POSITION		4
#define TIM7_POSITION		5
#define TIM14_POSITION 		8
#define WWDG_POSITION		11
#define SPI2_POSITION		14
#define USART2_POSITION		17
#define USART3_POSITION		18
#define USART4_POSITION		19
#define USART5_POSITION		20
#define I2C1_POSITION		21
#define I2C2_POSITION		22
#define USB_POSITON			23
#define CAN_POSITON			25
#define CRS_POSITON			27
#define PWR_POSITION		28
#define DAC_POSITION		29
#define CEC_POSITION		30

//Bit positions of peripherals on the RCC_APB2ENR

#define SYSCFG_POSITION	 	0
#define USART6_POSITION		5
#define USART7_POSITION		6
#define USART8_POSITION		7
#define ADC_POSITION		9
#define TIM14_POSITION		11
#define SPI1_POSITION		12
#define USART1_POSITION		14
#define TIM15_POSITION		16
#define TIM16_POSITION 		17
#define TIM17_POSITION		18
#define DBG_POSITION		22



/****************************************************************************************************************
 * 							RCC PERIPHERAL STUCTURE DECLARATION 												*
 * **************************************************************************************************************
 * */

typedef struct 
{
	uint32_t CR; 						/*	CLOCK CONTROL REGISTER						ADDRESS OFFSET 0x00 	*/
	uint32_t CFGR; 						/*	CLOCK CONFIGURATION REGISTER				ADDRESS OFFSET 0x04		*/
	uint32_t CIR; 						/*	CLOCK INTERRUPT REGISTER 					ADDRESS OFFSET 0X08		*/
	uint32_t APB2RSTR; 					/*	APB PERIPHERAL RESET REGISTER 2 			ADDRESS OFFSET 0X0C		*/
	uint32_t APB1RSTR; 					/*	APB PERIPHERAL RESET REGISTER 1 			ADDRESS OFFSET 0X10		*/
	uint32_t AHBENR; 					/*	AHB CLOCK ENABLE REGISTER 					ADDRESS OFFSET 0X14		*/
	uint32_t APB2ENR; 					/*	APB CLOCK ENABLE REGISTER 2 				ADDRESS OFFSET 0X18		*/
	uint32_t APB1ENR; 					/*	APB CLOCK ENABLE REGISTER 1 				ADDRESS OFFSET 0X1C		*/
	uint32_t BDCR; 						/*	RTC DOMAIN CONTROL REGISTER 				ADDRESS OFFSET 0X20		*/
	uint32_t CSR; 						/*	CLOCK OR STATUS REGISTER 					ADDRESS OFFSET 0X24		*/
	uint32_t AHBRSTR; 					/*	AHB PERIPHERAL RESET REGISTER 				ADDRESS OFFSET 0X28		*/
	uint8_t CFGR2; 						/*	CLOCK CONFIGURATION REGISTER 2 				ADDRESS OFFSET 0X2C		*/
	uint8_t 	__RESERVED0__;
	uint16_t	__RESERVED1__;
	uint32_t CFGR3; 					/*	CLOCK CONFIGURATION REGISTER 3 				ADDRESS OFFSET 0X30 	*/
	uint32_t CR2; 						/*	CLOCK CONTROL REGISTRER 2 					ADDRESS OFFSET 0X34		*/

} RCC_Typedef;

/****************************************************************************************************************
 * 							SYSCFG PERIPHERAL STRUCTURE DECLARATION												*
 * **************************************************************************************************************
 * */

typedef struct
{
	uint32_t CFGR1; 					/*SYSTEM CONFIGURATIO REGISTER 1 				ADDRESS OFFSET 0x00 	*/
	uint32_t __RESEREVD0__;
	uint16_t EXTICR1; 					/*EXTERNAL INTERRUPT CONFIGURATION REGISTER 1 	ADDRESS OFFSET 0x08		*/
	uint16_t __RESERVED1__;
	uint16_t EXTICR2; 					/*EXTERNAL INTERRUPT CONFIGURATION REGISTER 2 	ADDRESS OFFSET 0x0C 	*/
	uint16_t __RESERVED2__;
	uint16_t EXTICR3; 					/*EXTERNAL INTERRUPT CONFIGURATION REGISTER 3 	ADDRESS OFFSET 0x10 	*/
	uint16_t __RESERVED3__;
	uint16_t EXTICR4; 					/*EXTERNAL INTERRUPT CONFIGURATION REGISTER 4 	ADDRESS OFFSET 0x14 	*/
	uint16_t __RESERVED4__; 
	uint16_t CFGR2; 					/*SYSCFG CONFIGURATION REGISTER 2 				ADDRESS OFFSET 0x18 	*/
	uint16_t __RESERVED5__;
	uint32_t __RESERVED6__[24];			/*Reserved: 0x1C-0x7C													*/
	uint16_t ITLINE0; 					/*INTERRUPT LINE 0 STATUS REGISTER 				ADDRESS OFFSET 0x80		*/
	uint16_t __RESERVED7__; 
	uint16_t ITLINE1; 					/*INTERRUPT LINE 1 STATUS REGISTER 				ADDRESS OFFSET 0x84		*/
	uint16_t __RESERVED8__; 
	uint16_t ITLINE2; 					/*INTERRUPT LINE 2 STATUS REGISTER 				ADDRESS OFFSET 0x88		*/
	uint16_t __RESERVED9__; 
	uint16_t ITLINE3; 					/*INTERRUPT LINE 3 STATUS REGISTER 				ADDRESS OFFSET 0x8C		*/
	uint16_t __RESERVED10__; 
	uint16_t ITLINE4; 					/*INTERRUPT LINE 4 STATUS REGISTER 				ADDRESS OFFSET 0x90		*/
	uint16_t __RESERVED11__; 
	uint16_t ITLINE5;					/*INTERRUPT LINE 5 STATUS REGISTER 				ADDRESS OFFSET 0x94		*/
	uint16_t __RESERVED12__; 
	uint16_t ITLINE6;					/*INTERRUPT LINE 6 STATUS REGISTER 				ADDRESS OFFSET 0x98		*/	
	uint16_t __RESERVED13__; 
	uint16_t ITLINE7; 					/*INTERRUPT LINE 7 STATUS REGISTER 				ADDRESS OFFSET 0x9C		*/
	uint16_t __RESERVED14__; 
	uint16_t ITLINE8; 					/*INTERRUPT LINE 8 STATUS REGISTER 				ADDRESS OFFSET 0xA0		*/
	uint16_t __RESERVED15__; 
	uint16_t ITLINE9; 					/*INTERRUPT LINE 9 STATUS REGISTER 				ADDRESS OFFSET 0xA4		*/
	uint16_t __RESERVED16__; 
	uint16_t ITLINE10; 					/*INTERRUPT LINE 10 STATUS REGISTER 			ADDRESS OFFSET 0xA8		*/
	uint16_t __RESERVED17__; 
	uint16_t ITLINE11; 					/*INTERRUPT LINE 11 STATUS REGISTER 			ADDRESS OFFSET 0xAC		*/
	uint16_t __RESERVED18__; 
	uint16_t ITLINE12;					/*INTERRUPT LINE 12 STATUS REGISTER 			ADDRESS OFFSET 0xB0		*/
	uint16_t __RESERVED19__; 
	
	uint16_t ITLINE13;					/*INTERRUPT LINE 13 STATUS REGISTER 			ADDRESS OFFSET 0xB4		*/
	uint16_t __RESERVED20__; 
	uint16_t ITLINE14;					/*INTERRUPT LINE 14 STATUS REGISTER 			ADDRESS OFFSET 0xB8		*/
	uint16_t __RESERVED21__; 
	uint16_t ITLINE15;					/*INTERRUPT LINE 15 STATUS REGISTER 			ADDRESS OFFSET 0xBC		*/
	uint16_t __RESERVED22__; 
	uint16_t ITLINE16;					/*INTERRUPT LINE 16 STATUS REGISTER 			ADDRESS OFFSET 0xC0 	*/
	uint16_t __RESERVED23__; 
	uint16_t ITLINE17;					/*INTERRUPT LINE 17 STATUS REGISTER 			ADDRESS OFFSET 0xC4		*/
	uint16_t __RESERVED24__; 
	uint16_t ITLINE18;					/*INTERRUPT LINE 18 STATUS REGISTER 			ADDRESS OFFSET 0xC8		*/
	uint16_t __RESERVED25__; 
	uint16_t ITLINE19;					/*INTERRUPT LINE 19 STATUS REGISTER 			ADDRESS OFFSET 0xCC 	*/
	uint16_t __RESERVED26__; 
	uint16_t ITLINE20;					/*INTERRUPT LINE 20 STATUS REGISTER 			ADDRESS OFFSET 0xD0		*/
	uint16_t __RESERVED27__; 
	uint16_t ITLINE21;					/*INTERRUPT LINE 21 STATUS REGISTER 			ADDRESS OFFSET 0xD4 	*/
	uint16_t __RESERVED28__; 
	uint16_t ITLINE22;					/*INTERRUPT LINE 22 STATUS REGISTER 			ADDRESS OFFSET 0xD8 	*/
	uint16_t __RESERVED30__; 
	uint16_t ITLINE23;					/*INTERRUPT LINE 23 STATUS REGISTER 			ADDRESS OFFSET 0xDC		*/
	uint16_t __RESERVED31__; 
	uint16_t ITLINE24;					/*INTERRUPT LINE 24 STATUS REGISTER 			ADDRESS OFFSET 0xE0 	*/
	uint16_t __RESERVED32__; 
	uint16_t ITLINE25;					/*INTERRUPT LINE 25 STATUS REGISTER 			ADDRESS OFFSET 0xE4     */
	uint16_t __RESERVED33__; 
	
	uint16_t ITLINE26;					/*INTERRUPT LINE 26 STATUS REGISTER 			ADDRESS OFFSET 0xE8     */
	uint16_t __RESERVED34__; 
	uint16_t ITLINE27;					/*INTERRUPT LINE 27 STATUS REGISTER 			ADDRESS OFFSET 0xEC     */
	uint16_t __RESERVED35__; 
	uint16_t ITLINE28;					/*INTERRUPT LINE 28 STATUS REGISTER 			ADDRESS OFFSET 0xF0 	*/
	uint16_t __RESERVED36__; 
	uint16_t ITLINE29;					/*INTERRUPT LINE 29 STATUS REGISTER 			ADDRESS OFFSET 0xF4		*/
	uint16_t __RESERVED37__; 
	uint16_t ITLINE30;					/*INTERRUPT LINE 30 STATUS REGISTER 			ADDRESS OFFSET 0xF8		*/
	uint16_t __RESERVED38;

} SYSCFG_Typedef;

/****************************************************************************************************************
 * 							EXTI PERIPHERAL STRUCTURE DECLARATION												*
 * **************************************************************************************************************
 * */
typedef struct
{
	uint32_t IMR; 				/*EXTI INTERRUPT MASK REGISTER 						ADDRESS OFFSET 0x00 		*/
	uint32_t EMR; 				/*EXTI EVENT MASK REGISTER 							ADDRESS OOFSET 0x04			*/
	uint32_t RTSR; 				/*EXTI RISING TRIGGER SELECTRION REGISTER 			ADDRESS OFFSET 0x08			*/
	uint32_t FTSR; 				/*EXTI FALLING STRIGGER SELECTION REGISTER 			ADDRESS OFFSET 0x0C 		*/
	uint32_t SWIER; 			/*EXTI SOFTWARE INTERRUPT EVENT REGISTER 			ADDRESS OFFSET 0x10 		*/
	uint32_t PR; 				/*EXTI PENDING REGISTER 							ADDRESS OFFSET 0x14 		*/

}EXTI_Typedef;

/****************************************************************************************************************
 * 							PERIPHERAL POINTERS																	*
 * **************************************************************************************************************
 * */

#define RCC 					((RCC_Typedef*) 	RCC_BASE)
#define SYSCFG 					((SYSCFG_Typedef*)  SYSCFG_BASE)
#define EXTI 					((EXTI_Typedef*)	EXTI_BASE)

/****************************************************************************************************************
 * 							FUNCTION PROTOTYPES AND INLINE FUNCTION DEFINITIONS									*
 ****************************************************************************************************************
 * */

/****************************************************************************************************************
 * 																												*
 * 									RCC_AHB_Clock_Enable														*
 * 																												*
 * @brief : enables clock for any peripheral connected on the Advanced High speed peripheral Bus (AHB)			*
 * 																												*
 * @params : <postion> and unsigned 8-bit integer that states the bit position of the AHBENR register which is 	*
 * 			to be set to 1(which corresponds to bit positio of the peripheral for which the clock is to be 		*
 * 			enabled).																							*		
 * 																												*
 * @returns: None																								*
 * **************************************************************************************************************
 * */

__attribute__((always_inline)) static inline void RCC_APB_Clock_Enable(uint8_t position)
{
	if(position <= 0x0F) RCC-> AHBENR |= (1<<position); 
}

/****************************************************************************************************************
 * 																												*
 * 									RCC_APB1_Clock_Enable														*
 * 																												*
 * @brief : enables clock for any peripheral connected on the Advanced Peripheral Bus 1 (APB)					*
 * 																												*
 * @params : <postion> and unsigned 8-bit integer that states the bit position of the AHBENR register which is 	*
 * 			to be set to 1(which corresponds to bit positio of the peripheral for which the clock is to be 		*
 * 			enabled).																							*		
 * 																												*
 * @returns: None																								*
 * **************************************************************************************************************
 * */

__attribute__((always_inline)) static inline void RCC_APB1_Clock_Enable(uint8_t position)
{
	if(position <= 0x0F) RCC-> APB1ENR |= (1<<position); 
}

/****************************************************************************************************************
 * 																												*
 * 									RCC_APB2_Clock_Enable														*
 * 																												*
 * @brief : enables clock for any peripheral connected on the Advanced  Peripheral Bus (APB2)					*
 * 																												*
 * @params : <postion> and unsigned 8-bit integer that states the bit position of the AHBENR register which is 	*
 * 			to be set to 1(which corresponds to bit positio of the peripheral for which the clock is to be 		*
 * 			enabled).																							*		
 * 																												*
 * @returns: None																								*
 * **************************************************************************************************************
 * */
__attribute__((always_inline)) static inline void RCC_APB2_Clock_Enable(uint8_t position)
{
	if(position <= 0x0F) RCC-> APB2ENR |= (1<<position); 
}

#endif