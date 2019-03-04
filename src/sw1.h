/*****************************************************************************
* University of Southern Denmark
* Embedded Programming (EMP)
*
* MODULENAME.: emp.c
*
* PROJECT....: EMP
*
* DESCRIPTION: See module specification file (.h-file).
*
* Change Log:
*****************************************************************************
* Date    Id    Change
* YYMMDD
* --------------------
* 190302  KA    Module created.
*
*****************************************************************************/
#ifndef _SW1_H
#define _SW1_H
/***************************** Include files *******************************/
#include <stdbool.h>
/*****************************    Defines    *******************************/

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/



void sw1_setup();
/*****************************************************************************
*   Input    : Nothing
*   Output   : Nothing
*   Function : To setup the necessary pins and values for sw1
******************************************************************************/
bool sw1_read();
/*****************************************************************************
*   Input    : Nothing
*   Output   : Nothing
*   Function : To figure out rather or not the switch is on or off.
******************************************************************************/

/****************************** End Of Module *******************************/
#endif // _SW1_H
