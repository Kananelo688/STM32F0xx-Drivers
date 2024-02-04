/*
*****************************************************************************************************************
 * STM32F051 Start up file.The start up file does the following:								                *
 *								1. Creates a Vector table										                *
 *								2. Initialise .data and .bss section							                *
 *								3. Call main()													                *
 * 							 																	                *	
 *																								                *
 *Author: Kananelo Chabeli																		                *
 * **************************************************************************************************************
*/

/****************************************************************************************************************
 *                                  INCLUDES                                                                    *        
 **************************************************************************************************************** 
 */
#include <stdint.h>

/****************************************************************************************************************
 *                                  DEFINES                                                                     *        
 **************************************************************************************************************** 
 */

#define SRAM_START 0x20000000U //address where the SRAM start in STM32F4
#define SRAM_SIZE (8U*1024U) //128KB(Size of the SRAM)
#define SRAM_END  ((SRAM_START)+ (SRAM_SIZE)-1)
#define STACK_START  SRAM_END

/****************************************************************************************************************
 *                                  EXTERNAL VARIABLES                                                          *        
 **************************************************************************************************************** 
 */

extern uint32_t _etext;                 /*linker symbol that marks end of the .text section of the final .elf   */
extern uint32_t _edata;                 /*linker symbol that marks end of the .data section of the final .elf   */
extern uint32_t _sdata;                 /*linker symbol that marks start of the .data section of the final .elf */
extern uint32_t _ebss;                  /*linker symbol that marks end of the .bss section of the final .elf    */
extern uint32_t _sbss;                  /*linker symbol that marks start of the .bss section of the final .elf  */

/****************************************************************************************************************
 *                                 FUNCTION PROTOTYPES                                                          *        
 **************************************************************************************************************** 
 */

void Reset_Handler										(void);

int main                                                (void);

/**
 * **************************************************************************************************************
 * The following function declaration illustrate the use of the function attributes weak&alias                  *
 * 		1. WEAK: let's the programmer to override the already defineed weak function with the                   *
 * 					same name.																                    *
 * 		2. ALIAS: Let's the programmer to provide alias name for the function, The function                     *
 * 					will be replaced with the alias function code. 							                    *
 * **************************************************************************************************************
 */


void NMI_Handler 										(void) __attribute__((weak,alias ("Default_Handler")));
void HardFault_Handler 									(void) __attribute__((weak,alias ("Default_Handler")));
void SVC_Handler 										(void) __attribute__((weak,alias ("Default_Handler")));
void PendSV_Handler 									(void) __attribute__((weak,alias ("Default_Handler")));
void SysTick_Handler 									(void) __attribute__((weak,alias ("Default_Handler")));
void WWDG_IRQHandler 									(void) __attribute__((weak,alias ("Default_Handler")));
void PVD_VDDIO2_IRQHandler 								(void) __attribute__((weak,alias ("Default_Handler")));
void RTC_IRQHandler 									(void) __attribute__((weak,alias ("Default_Handler")));
void FLASH_IRQHandler 									(void) __attribute__((weak,alias ("Default_Handler")));
void RCC_CRS_IRQHandler 								(void) __attribute__((weak,alias ("Default_Handler")));
void EXTI0_1_IRQHandler 								(void) __attribute__((weak,alias ("Default_Handler")));
void EXTI2_3_IRQHandler 								(void) __attribute__((weak,alias ("Default_Handler")));
void EXTI4_15_IRQHandler								(void) __attribute__((weak,alias ("Default_Handler")));
void TSC_IRQHandler										(void) __attribute__((weak,alias ("Default_Handler")));
void DMA_CH1_IRQHandler 								(void) __attribute__((weak,alias ("Default_Handler")));
void DMA_CH2_3_DMA2_CH1_2_IRQHandler					(void) __attribute__((weak,alias ("Default_Handler")));
void DMA_CH4_5_6_7_DMA2_CH3_4_5_IRQHandler				(void) __attribute__((weak,alias ("Default_Handler")));
void ADC_COMP_IRQHandler								(void) __attribute__((weak,alias ("Default_Handler")));
void TIM1_BRK_COMP_TRG_COM_IRQHandler					(void) __attribute__((weak,alias ("Default_Handler")));
void TIM1_CC_IRQHandler 								(void) __attribute__((weak,alias ("Default_Handler")));
void TIM2_IRQHandler									(void) __attribute__((weak,alias ("Default_Handler")));
void TIM3_IRQHandler 									(void) __attribute__((weak,alias ("Default_Handler")));
void TIM6_DAC_IRQHandler 								(void) __attribute__((weak,alias ("Default_Handler")));
void TIM7_IRQHandler 									(void) __attribute__((weak,alias ("Default_Handler")));
void TIM14_IRQHandler									(void) __attribute__((weak,alias ("Default_Handler")));
void TIM15_IRQHandler									(void) __attribute__((weak,alias ("Default_Handler")));
void TIM16_IRQHandler									(void) __attribute__((weak,alias ("Default_Handler")));
void TIM17_IRQHandler									(void) __attribute__((weak,alias ("Default_Handler")));
void I2C1_IRQHandler									(void) __attribute__((weak,alias ("Default_Handler")));
void I2C2_IRQHandler									(void) __attribute__((weak,alias ("Default_Handler")));
void SPI1_IRQHandler									(void) __attribute__((weak,alias ("Default_Handler")));
void SPI2_IRQHandler									(void) __attribute__((weak,alias ("Default_Handler")));
void USART1_IRQHandler									(void) __attribute__((weak,alias ("Default_Handler")));
void USART2_IRQHandler									(void) __attribute__((weak,alias ("Default_Handler")));
void USART3_4_5_6_7_8_IRQHandler						(void) __attribute__((weak,alias ("Default_Handler")));
void CEC_CAN_IRQHandler									(void) __attribute__((weak,alias ("Default_Handler")));
void USB_IRQHandler										(void) __attribute__((weak,alias ("Default_Handler")));


/**
 * **************************************************************************************************************
 * Vector Table: The following array is the vector table which was made hand-in-hand with       				*
 * 				 the datasheet of STM32F0xx microcontrollers. The reversed space on the vector	      			*
 * 				 table is marked by 0 																			*
 * Note: Because this is an array od ints, compiler would place this is .data section. However, 				*
 * The vector table need to be place at some specific address as specified by the STM32. The 					*
 * section attibute is used here to instruct the compiler to create a different section called 					*
 * '.isr_vector', and place this array in that section.															*
 * **************************************************************************************************************
 * */

uint32_t*  vectors[]  __attribute__((section (".isr_vector")))= {
    

    (uint32_t*) STACK_START, 							/*ADDRESS 0x00000000*/ 								
    (uint32_t*) &Reset_Handler, 						/*ADDRESS 0x00000004*/
    (uint32_t*) &NMI_Handler, 							/*ADDRESS 0x00000008*/
    (uint32_t*) &HardFault_Handler,						/*ADDRESS 0x0000000C*/
    0,													/*ADDRESS 0x00000010*/
    0,													/*ADDRESS 0x00000014*/
    0,													/*ADDRESS 0x00000018*/
    0,													/*ADDRESS 0x0000001C*/
    0,													/*ADDRESS 0x00000020*/
    0,													/*ADDRESS 0x00000024*/
    0,													/*ADDRESS 0x00000028*/
    (uint32_t*) &SVC_Handler,							/*ADDRESS 0x0000002C*/
    0,													/*ADDRESS 0x00000030*/
    0,													/*ADDRESS 0x00000034*/
    (uint32_t*) &PendSV_Handler,						/*ADDRESS 0x00000038*/
    (uint32_t*) &SysTick_Handler,						/*ADDRESS 0x0000003C*/
    (uint32_t*) &WWDG_IRQHandler,						/*ADDRESS 0x00000040*/
    (uint32_t*) &PVD_VDDIO2_IRQHandler,					/*ADDRESS 0x00000044*/
    (uint32_t*) &RTC_IRQHandler,						/*ADDRESS 0x00000048*/
    (uint32_t*) &FLASH_IRQHandler,						/*ADDRESS 0x0000004C*/
    (uint32_t*) &RCC_CRS_IRQHandler,					/*ADDRESS 0x00000050*/
    (uint32_t*) &EXTI0_1_IRQHandler,					/*ADDRESS 0x00000054*/
    (uint32_t*) &EXTI2_3_IRQHandler,					/*ADDRESS 0x00000058*/
    (uint32_t*) &EXTI4_15_IRQHandler,					/*ADDRESS 0x0000005C*/
    (uint32_t*) &TSC_IRQHandler,						/*ADDRESS 0x00000060*/	
    (uint32_t*) &DMA_CH1_IRQHandler,					/*ADDRESS 0x00000064*/
    (uint32_t*) &DMA_CH2_3_DMA2_CH1_2_IRQHandler,		/*ADDRESS 0x00000068*/
    (uint32_t*) &DMA_CH4_5_6_7_DMA2_CH3_4_5_IRQHandler,	/*ADDRESS 0x0000006C*/
    (uint32_t*) &ADC_COMP_IRQHandler,					/*ADDRESS 0x00000070*/
    (uint32_t*) &TIM1_BRK_COMP_TRG_COM_IRQHandler,		/*ADDRESS 0x00000074*/
    (uint32_t*) &TIM1_CC_IRQHandler,					/*ADDRESS 0x00000078*/
    (uint32_t*) &TIM2_IRQHandler, 						/*ADDRESS 0x0000007C*/
    (uint32_t*) &TIM3_IRQHandler, 						/*ADDRESS 0x00000080*/
    (uint32_t*) &TIM6_DAC_IRQHandler, 					/*ADDRESS 0x00000084*/
    (uint32_t*) &TIM7_IRQHandler, 						/*ADDRESS 0x00000088*/
    (uint32_t*) &TIM14_IRQHandler, 						/*ADDRESS 0x0000008C*/
    (uint32_t*) &TIM15_IRQHandler, 						/*ADDRESS 0x00000090*/
    (uint32_t*) &TIM16_IRQHandler, 						/*ADDRESS 0x00000094*/
    (uint32_t*) &TIM17_IRQHandler, 						/*ADDRESS 0x00000098*/
    (uint32_t*) &I2C1_IRQHandler,						/*ADDRESS 0x0000009C*/
    (uint32_t*) &I2C2_IRQHandler,						/*ADDRESS 0x000000A0*/
    (uint32_t*) &SPI1_IRQHandler,						/*ADDRESS 0x000000A4*/
    (uint32_t*) &SPI2_IRQHandler,						/*ADDRESS 0x000000A8*/
    (uint32_t*) &USART1_IRQHandler,						/*ADDRESS 0x000000AC*/
    (uint32_t*) &USART2_IRQHandler,						/*ADDRESS 0x000000B0*/
    (uint32_t*) &USART3_4_5_6_7_8_IRQHandler,			/*ADDRESS 0x000000B4*/
    (uint32_t*) &CEC_CAN_IRQHandler,					/*ADDRESS 0x000000B8*/
    (uint32_t*) &USB_IRQHandler							/*ADDRESS 0x000000BC*/
};
/****************************************************************************************************************
 *                           RESET HANDLER                                                                      *        
 **************************************************************************************************************** 
 */
void Reset_Handler(void){

    __asm("ldr      r0,=    _etext"); /*Load address where the .data section starts in FLASH*/
    __asm("ldr      r1, =   _sdata");  /*Load address where .data section starts in SRAM    */
    __asm("ldr      r2, =   _edata"); /*Load address where .data ends in SRAM               */

    __asm("ldr      r3, = 0x01");       /*Load 1 into r2                                    */

    __asm("data_loop:");            /*Loop and copy initialised data from flash into SRAM   */
    __asm("ldrb r4, [r0]");         /*load byte from flash*/
    __asm("cmp      r2, r1");       /*Check if _sdata == _edata                             */
    __asm("beq  _init_bss");         /*If so, jump to code thta initialised the .bss section */
   
    __asm("strb     r4, [r1]");      /*Otherwise copy data from flash (r0), into flash (r1)  */
    __asm("add      r0, r3");        /*incremet _etext                                       */
    __asm("add      r1,r3");        /*increment _sdata*/
    __asm("b data_loop"); 
   
    __asm("_init_bss:");        /*Initialized .bss section                                   */
    __asm("ldr      r0, = _sbss"); /*load start address of .bss section                      */
    __asm("ldr      r1, =_ebss"); /*Load end of .bss section                                 */

    __asm("ldrb      r2, = 0x00"); /*Loading the byte 0 into r2 */

    __asm("_bss_loop:");
    
    __asm("cmp      r1,     r0");
    __asm("beq Rst_rtn");
    __asm("strb    r2,      [r0]");
    __asm("add      r0,     r3");     /*incement _sbss*/
    __asm("b    _bss_loop");
    __asm("Rst_rtn:");      /*Returning put of the reset handler*/
    __asm("bl   main");       /*Call main*/
    __asm("bx       lr");         /*Return from the function*/
}

/****************************************************************************************************************
 *                                  DEFAULT_HANDLER                                                             *        
 **************************************************************************************************************** 
 */

void Default_Handler(void){
	while(1);
}