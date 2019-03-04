/*****************************************************************************
* University of Southern Denmark
* Embedded Programming (EMP)
*
* MODULENAME.: rgb.c
*
* PROJECT....: Ass1
*
* DESCRIPTION: See module specification file (.h-file).
*
* Change Log:
*****************************************************************************
* Date    Id    Change
* YYMMDD
* --------------------
* 190302  ALL    Module created.
*
*****************************************************************************/

/***************************** Include files *******************************/
#include <stdint.h>
#include <inc/tm4c123gh6pm.h>
#include "rgb.h"
/*****************************    Defines    *******************************/
#define RGB_PINS 0x0E
/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/

void rgb_set_color(uint32_t color)
/*****************************************************************************
*   Input    : Color
*   Output   :
*   Function : Change  color on RGB LEDs
******************************************************************************/
{
	GPIO_PORTF_DATA_R &= ~RGB_PINS;
	GPIO_PORTF_DATA_R |= color & RGB_PINS;
}

void rgb_setup(void)
/*****************************************************************************
*   Input    : 
*   Output   :
*   Function : Setup RGB LEDs
******************************************************************************/
{
	// Enable PORTF
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
	// Wait for PORTF to be accesable
	while((SYSCTL_PRGPIO_R & SYSCTL_RCGCGPIO_R5)==0);
	// Set Direction; Input Output
	GPIO_PORTF_DIR_R |= RGB_PINS;
	// Set Digital Enable 
	GPIO_PORTF_DEN_R |= RGB_PINS;
}
/*****************************************************************************
*   Function : See module specification (.h-file).
*****************************************************************************/

/****************************** End Of Module *******************************/
