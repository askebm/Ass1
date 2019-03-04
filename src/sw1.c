/*****************************************************************************
* University of Southern Denmark
* Embedded Programming (EMP)
*
* MODULENAME.: sw1.c
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
* 190302  All    Module created.
*
*****************************************************************************/

/***************************** Include files *******************************/
#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
#include "sw1.h"
/*****************************    Defines    *******************************/
#define SW1 0x10
/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/
void sw1_setup()
/*****************************************************************************
*   Input    : Nothing
*   Output   : Nothing
*   Function : To set up the necessary pins and values for sw1
******************************************************************************/
{
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
	while( (SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R5) == 0 );

	// Set Digital Enable for button
	GPIO_PORTF_DEN_R |= SW1;
	// Set Pull-Up Enable; GPIO_PORTF_PDR_R for Pull Down Enable
	GPIO_PORTF_PUR_R |= SW1;
}

bool sw1_read()
/*****************************************************************************
*   Input    : Nothing
*   Output   : The state, is the switch on, then return TRUE, otherwise return FALSE.
*   Function : To figure out rather or not the switch is on or off.
******************************************************************************/
{
	if ( GPIO_PORTF_DATA_R & SW1 )
		return false;
	else
		return true;
}
/****************************** End Of Module *******************************/
