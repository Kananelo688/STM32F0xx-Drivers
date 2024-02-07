/************************************************************************************************************
 * 																											*
 * C source file that implements the stm32f0xx_adc_driver.h interface										*
 * 																											*
 * @author:Kananelo Chabeli																					*
 * 																											*
 * @version: 05-Feb-2024																					*
 * 																											*		
 * **********************************************************************************************************
 * */

/************************************************************************************************************
 * 											INCLUDES														*
 * **********************************************************************************************************
 * */

#include "stm32f0xx_adc_driver.h"


/************************************************************************************************************
 * 										FUNCTION DEFINITIONS												*
 ************************************************************************************************************ 
 * */

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

void ADC_Configure(ADC_Params* params){

	uint8_t flags = 0; //integer for flags
	
	RCC_APB2_Clock_Enable(RCC_APB2ENR_ADCEN); 	//Enable Clock

	for(int i=0; i < params -> channel_num; i++)
	{
		if(params->channels[i] <= GPIO_PIN_7){

			RCC_AHB_Clock_Enable(RCC_AHBENR_GPIOAEN); //Enable clock for GPIOA
			GPIO_Set_Pin_Mode(GPIOA,params->channels[i], GPIO_ANALOG_MODE); //Set the Mode of the pin to ANALOG
		
		}else if (params->channels[i] == GPIO_PIN_8 || params->channels[i] == GPIO_PIN_9){

			RCC_AHB_Clock_Enable(RCC_AHBENR_GPIOBEN); //Enable clock for GPIOB
			GPIO_Set_Pin_Mode(GPIOB, params->channels[i], GPIO_ANALOG_MODE);
		
		}else if ( params->channels[i] <= GPIO_PIN_15){
			
			RCC_AHB_Clock_Enable(RCC_AHBENR_GPIOCEN); // Enable clock GPIOC
			GPIO_Set_Pin_Mode(GPIOC, params->channels[i], GPIO_ANALOG_MODE); //Set the PIN mode to ANALOG

		}else {

			// channel is from timer trigger : TO DO
		}

		ADC -> CHSELR |= 1<<params->channels[i]; //select the channel in the channel selection register.
	}

	ADC -> CFGR1 |= (params -> data_res << 0x03) | (params -> data_align << 0x05) | (params -> scan_dir << 0x02);

	if (params -> conv_mode == ADC_DISCONT_CONV)

		 {
			ADC -> CFGR1 |= (0x01 << 16);
		} //set discontnuous mode

	else {
		ADC -> CFGR1 |= params -> conv_mode << 13;
	} // Set the conversion mode if its either single or continuous.
}
 void ADC_Start(void)
{

	while(!((ADC->CR) & (0x01))); //wait for ADC to be Ready. before starting the conversion.
	ADC -> CR |= 0x04 ;
	ADC -> ISR |= 0x01; // Clear ADRDY Flag.

}


void ADC_Enable(void)
{
		ADC -> CR|= 0x01;
}

 uint16_t ADC_Read_Data(void)
{
	while(!((ADC->ISR) & (0x01<<0x02))); // Wait for ADC to comple the ongoing conversion. 		
	ADC -> ISR |= 0x01<<0x02; // Clear EOC_Bit
	return ADC -> DR; // read the DR (this will also clear EOC bit in the ADC_ISR register)
}
