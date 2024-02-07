/************************************************************************************************************
 * 																											*
 * Assembly source file that implements the stm32f0xx_adc_driver.h interface								*
 * 																											*
 * @author:Kananelo Chabeli																					*
 * 																											*
 * @version: 05-Feb-2024																					*
 * 																											*		
 * **********************************************************************************************************
 * */

.text

.globl, ADC_Configure
.type function, ADC_Configure


ADC_Configure:
	
	@Step 1: Enabling ADC clock
		
		ldr r1, =0x4002100 					@load the base address of RCC peripheral(for enabling ADC and GPIO clocks)
		ldr r2, [r1, #0x20]					@load the value of RCC_APB2ENR register
		orr r2, #0x0200 					@Enable clock for ADC peripheral
		str r2, [r1, #0x20]					@Store the result back to memory

	@Step 2: Configuring ADC's CFGR1 based on the data in the ADC_Params (passed as argument)

		ldr r1, =0x40012400 				@load the base address of the ADC peripheral

		ldb r2, [r0, #0]					@load the value of ADC_Params.conv_mode

		ldb r3, [r0, #1]					@load the value of ADC_Params.data_res

		ldb r4, [r0, #2]					@load the value of ADC_Params.data_align

		ldb r5, [r0, #3]					@load the value of ADC_Params.scan_dir

		cmp r2, #0x02 						@check to see if ADC_Params.conv_mode == 0x2, if so, enable DISCONT mode

		beq DISCONT_EN	

		lsl r2, #13 						@shift r2 by 13 to left the CONT bit of ADC_CFGR1 register

Cont_CFGR1:

DISCONT_EN:
	lsl r1, #16 							@ shift r2 to left by 16 to set DISCEN bit of ADC_CFGR1 register
	b Cont_CFGR1							@Branch bank and proceed with the configuration.

