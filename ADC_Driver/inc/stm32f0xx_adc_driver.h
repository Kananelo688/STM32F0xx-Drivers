/************************************************************************************************************
 * 																											*
 * An STM32F0XX driver for Analog-Digital-Converter peripheral.												*
 * 																											*
 * @author: Kananelo Chabeli																				*	
 * @version: 05/02/2024																						*
 *																											*
 * ********************************************************************************************************** 
 * */

#ifndef STM32F0XX_ADC_DRIVER_H

#define STM32F0XX_ADC_DRIVER_H



/************************************************************************************************************
 *									INCLUDES																*
 ************************************************************************************************************  
 **/

#include "stm32f0xx_drivers.h"
#include "stm32f0xx_gpio_driver.h"

/************************************************************************************************************
 * 									ADC BASEADDRESS															*
 ************************************************************************************************************
 */

#define ADC_BASE 					0x40012400U

/************************************************************************************************************
 * 									ADC INPUT CHANNELS	NUMBERS							 					*
 ************************************************************************************************************
 */

#define ADC_IN0							0x00U						
#define ADC_IN1 						0x01U 	
#define ADC_IN2 						0x02U 	
#define ADC_IN3 						0x03U 	
#define ADC_IN4 						0x04U 	
#define ADC_IN5 						0x05U 	
#define ADC_IN6 						0x06U 	
#define ADC_IN7 						0x07U 	
#define ADC_IN8 						0x08U 	
#define ADC_IN9 						0x09U 	
#define ADC_IN10 						0x0AU 	
#define ADC_IN11 						0x0BU 	
#define ADC_IN12 						0x0CU 	
#define ADC_IN13 						0x0DU 	
#define ADC_IN14 						0x0EU 	
#define ADC_IN15 						0x0FU 	
#define ADC_IN16 						0x10U 	
#define ADC_IN17 						0x11U 	
#define ADC_IN18 						0x12U 	

/************************************************************************************************************
 * 									ADC CONVERSION MODES								 					*
 ************************************************************************************************************
 */

#define ADC_SINGLE_CONV 				0x00U
#define ADC_CONT_CONV					0x01U
#define ADC_DISCONT_CONV 				0x02U	

/************************************************************************************************************
 * 									ADC DATA AlIGNMENT									 					*
 ************************************************************************************************************
 */

#define ADC_RIGHT_ALIGN 				0x00U
#define ADC_LEFT_ALIGN					0x01U 		

/************************************************************************************************************
 * 									ADC EXTERNAL TRIGGERS	 							 					*
 ************************************************************************************************************
 */

#define ADC_TRIG0 						0x00U
#define ADC_TRIG1 						0x01U
#define ADC_TRIG2 						0x02U
#define ADC_TRIG3 						0x03U
#define ADC_TRIG4 						0x04U
#define ADC_TRIG5 						0x05U
#define ADC_TRIG6 						0x06U
#define ADC_TRIG7 						0x07U

/************************************************************************************************************
 * 									ADC RESOLUTIONS			 							 					*
 ************************************************************************************************************
 */

#define ADC_12BIT_RES					0x00U
#define ADC_10BIT_RES 					0x01U
#define ADC_8BIT_RES					0x02U
#define ADC_6BIT_RES 					0x03U

/************************************************************************************************************
 * 									ADC STYPEDEFS															*
 ************************************************************************************************************
 */

typedef uint8_t ADC_Conversion_Mode;
typedef uint8_t ADC_Alignment;
typedef uint8_t ADC_Resolution;
typedef uint8_t ADC_Trigger;

/************************************************************************************************************
 * 									ADC STRUCTURE DECLARATION												*
 ************************************************************************************************************
 */

typedef struct
{
	uint16_t ISR; 					/*ADC Interrupt and  Status Register 				ADDRESS OFFSET 0x00 */
	uint16_t __RESERVED__0;			/* RESERVED ADDRESS 													*/
	uint16_t IER; 					/*ADC Interrupt Enable Register 					ADDRESS OFFSET 0x04 */
	uint16_t __RESERVED__1;			/* RESERVED ADDRESS 													*/
	uint32_t CR;					/*ADC Control Register 								ADDRESS OFFSET 0x08 */
	uint32_t CFGR1;					/*ADC configuration register 1 						ADDRESS OFFSET 0x0C */
	uint32_t CFGR2;					/*ADC configuration register 2 						ADDRESS OFFSET 0x10 */
	uint16_t SMPR; 					/*ADC Sampling Time Register 						ADDRESS OFFSET 0x14 */	
	uint16_t __RESERVED__2;			/* RESERVED ADDRESS 													*/
	uint32_t __RESERVED__3[2];		/*RESERVED ADDRESSES 0x18 and 0x1C										*/
	uint32_t TR; 					/*ADC watchdog threshold register 					ADDRESS OFFSET 0x20 */
	uint32_t __RESERVED__4;			/* RESERVED ADDRESS 		0x24										*/
	uint32_t CHSELR;				/*ADC Channel Selection Register 					ADDRESS OFFSET 0x28 */
	uint32_t __RESERVED__6[5];		/*RESERVED ADDRESS SPACE: 0x2C-0x3F(5 words) 							*/
	uint16_t DR; 					/*ADC Data Register 								ADDRESS OFFSET 0x40 */
	uint16_t __RESERVED__7;			/* RESERVED ADDRESS 													*/
	uint32_t __RESERVED__8[0xB1];	/*RESERVED ADDRESS SPACE: 0x44 - 0x307(177 words) 						*/
	uint32_t CCR;					/*ADC Common configuration register 				ADDRESS OFFSET 0x308*/


}ADC_Typedef;


/************************************************************************************************************
 * 										 							 										*
 * A structure that defines the paramaters of the ADC. This structure must be initialised before calling	*
 * ADC_Config function. The structure has the following data members:										*
 * 																											*
 * conv_mode - ADC's conversion mode. must be either ADC_SINGLE_CONV, ADC_CONT_CONV or ADC_DISCONT_CONV		*
 * 																											*
 * data_res - Specifies ADC's resolution. Must be one of ADC_12BIT_RES, ADC_10BIT_RES, ADC_8BIT_RES or 		*
 * 				ADC_6BIT_RES.																				*
 * 																											*
 * data_align - Specifies how data should be aligned. Must be either ADC_RIGHT_ALIGN or ADC_LEFT_ALIGN	  	*
 * 																											*
 * scan_dir - specifies the directio of scanning thr selected channels. (@see data sheet )					*	
 * 																											*
 * chnnel_num - Specifies the number of channels to be scanned. It must be in the range [1, 19], and 		*
 * "channels" must be a pointer to array of channel numbers which are tobe scanned. 						*
 * 																											*
 * channels - a pointer to the array of uint8_t integers that provide channel numbers to be scanned. 		* 
 * 																											*
 ************************************************************************************************************
 */

typedef struct
{
	ADC_Conversion_Mode conv_mode;

	ADC_Resolution data_res;

	ADC_Alignment data_align;

	 uint8_t scan_dir;

	uint8_t channel_num;

	uint8_t* channels;

}ADC_Params;

/************************************************************************************************************
 * 									ADC STRUCTURE POINTERS													*
 ************************************************************************************************************
 */

#define ADC 			((ADC_Typedef*)			ADC_BASE)


/************************************************************************************************************
 * 									FUCNTION PROTOTYPES 													*
 ************************************************************************************************************
 */


/************************************************************************************************************
 * 									ADC_Enable																*
 *																											*
 * @brief: Enables ADC by settig the ADEN Bit in ADC_CR register. 											*
 * 																											*
 * @params: None																							*
 * 																											*
 * @return: None																							* 
 * 																											*																									*
 ************************************************************************************************************
 *  */

void ADC_Enable(void);

/************************************************************************************************************
 * 									ADC_Start																*
 *																											*
 * @brief: Starts ADC by settig the ADSTART Bit in ADC_CR register. 										*
 * 																											*
 * @params: None																							*
 * 																											*
 * @return: None																							* 
 * 																											*																										*
 ************************************************************************************************************
 *  */
 void ADC_Start(void);

/************************************************************************************************************
 * 									ADC_Read_Data															*
 *																											*
 * @brief: waitd for the conversion to be done and returns the value int the Data register 					*
 * 																											*
 * @params: None																							*
 * 																											*
 * @return: 16 bit that represents the value of the ADC_DR register											* 
 * 																											*																											*
 ************************************************************************************************************
 *  */
 uint16_t ADC_Read_Data(void);
 
/************************************************************************************************************
 * 									ADC_Stop																*
 *																											*
 * @brief: Stops ADC by settig the ADSTP Bit in ADC_CR register. 											*
 * 																											*
 * @params: None																							*
 * 																											*
 * @return: None																							* 
 * 																											** 																											*
 ************************************************************************************************************
 *  */
__attribute__((always_inline)) static inline void ADC_Stop(void)
{
	ADC -> CR |= 0x10;
}

/************************************************************************************************************
 * 									ADC_Start																*
 *																											*
 * @brief: Enables ADC by settig the ADSTART Bit in ADC_CR register. 										*
 * 																											*
 * @params: None																							*
 * 																											*
 * @return: None																							* 
 * 																											* * 																											*
 ************************************************************************************************************
 *  */
__attribute__((always_inline)) static inline void ADC_Disable(void)
{
	ADC -> CR |= 0x02;
}

/************************************************************************************************************
 * 									ADC_Configure															*
 *																											*
 * @brief: Configures the ADC based on the given parameters, which are described by ADC_Params structure 	*
 * 			This structure should instantiated before the call to the this fuction. @see ADC_Params			*
 * 																											*
 * @params: <params>	and ADC_Params structure pointer that describes the paramter of the ADC. 		    * 																											*
 * 																											*
 * @return: None																							* 
 *																											*
 ************************************************************************************************************
 **/

void ADC_Configure(ADC_Params* params);


#endif