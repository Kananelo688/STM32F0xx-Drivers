/**
 * 
 * source file with 
 * */


#include "stm32f0xx_adc_driver.h"


uint8_t chnls[]={ADC_IN6, ADC_IN5};

int main(void)
{
	ADC_Params params= {
		.conv_mode	 	= ADC_CONT_CONV,
		.data_res 		= ADC_8BIT_RES,
		.data_align		= ADC_RIGHT_ALIGN,
		.channel_num = 2,
		.channels = chnls
	};

	RCC_APB2_Clock_Enable(RCC_APB2ENR_ADCEN); 

	RCC_AHB_Clock_Enable(RCC_AHBENR_GPIOBEN);

	GPIO_Set_Pin_Mode(GPIOB,GPIO_PIN_0, GPIO_OUTPUT_MODE);
	GPIO_Set_Pin_Mode(GPIOB,GPIO_PIN_1, GPIO_OUTPUT_MODE);
	GPIO_Set_Pin_Mode(GPIOB,GPIO_PIN_2, GPIO_OUTPUT_MODE);
	GPIO_Set_Pin_Mode(GPIOB,GPIO_PIN_3, GPIO_OUTPUT_MODE);
	GPIO_Set_Pin_Mode(GPIOB,GPIO_PIN_4, GPIO_OUTPUT_MODE);
	GPIO_Set_Pin_Mode(GPIOB,GPIO_PIN_5, GPIO_OUTPUT_MODE);
	GPIO_Set_Pin_Mode(GPIOB,GPIO_PIN_6, GPIO_OUTPUT_MODE);
	GPIO_Set_Pin_Mode(GPIOB,GPIO_PIN_7, GPIO_OUTPUT_MODE);

	ADC_Configure(&params);

	ADC_Enable();

	ADC_Start();


	while(1){

		GPIOB -> ODR = ADC_Read_Data();
	}

	return 0;
}