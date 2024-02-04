/**
*****************************************************************************************************************
*	Linker script for STM32f0xx micro-controlletrs. The script can be modified by adding more sections.			*
*	The script can be modified on the FLALH and SRAM sizes for other microcontrollers							*
*																												*
*	Author: Kananelo Chabeli																					*	
*****************************************************************************************************************
*/

/****************************************************************************************************************
 *									ENTRY COMMAND																*		
 *																												*
 *	The ENTRY command is used if the debugger is to be used.It tells the debugger the entry point to the program* 
 *	For most cases, the entry point is Reset_Handler.															*
 ****************************************************************************************************************			
*/

ENTRY(Reset_Handler)

/****************************************************************************************************************
 *									MEMORY COMMAND 																*
 *																												*
 *MEMORY Command tells the linker about the memory region present in the target  processor as well as 			*
 *how much is for each region.																					*
 *																												*
 *The memory regions defined in this command are used in other parts of the linker. For our purpose. 			*
 *we only need to specify two memory regions FLASH, which is where the code is downloaded, and SRAM which is 	*
 *non-volatile memory hold variables and data,during execution of the program. 									*
 ****************************************************************************************************************				
*/

MEMORY{
		
	/*FLASH memory of  STM32F4 is 512KB, and read-only and contians executable code.*/
	FLASH(rx): ORIGIN = 0x08000000, LENGTH = 32K 

	/*SRAM is of total of 128KB, and is readbale, writtable and executable.*/

	SRAM(rwx): ORIGIN = 0x20000000, LENGTH = 8K 

}

/****************************************************************************************************************
 *								SECTIONS COMMAND																*
 *																												*
 *SECTIONS Command is the command that tells the linker how merge different sections of the input files to 		*
 *produce the final executable.																					*
 ****************************************************************************************************************
*/

SECTIONS
{

/*.text of the final elf file contains all code and initialized data from the different input file. 
It is stored in FLASH*/
	.text : {

		*(.isr_vector) /*merges all section of input files that have .isr_vectors*/
		*(.text) /*merges .text of all input files*/
		*(.text.*)
		. = ALIGN(4); /* Align the location counter*/
		_etext = .; /*define the linker symbols, that marks the boundry of the end of .text section*/

	}> FLASH /*VMA and LDA of the .text section is FLASH*/

	.data : {/*Contains initialised and static global variables of all input files*/
		
		_sdata = .; /*linker symbol that marks the start of the .data section of the final executable*/

		*(.data) /*merges all .data sections of input files*/

		. = ALIGN(4); /*Align the location counter by 4 bytes*/
		_edata = .;

	}>SRAM /*VMA is SRAM*/ AT> FLASH /*LDA is FLASH*/

	.bss : { /*Contains the merges unitialised variables of the input files*/

		_sbss = .;

		*(.bss)
		*(.COMMON)

		. = ALIGN(4); /*Align the location counter by 4 bytes*/

		_ebss = .;
	} > SRAM /*LDA and VMA is SRAM*/

	
}