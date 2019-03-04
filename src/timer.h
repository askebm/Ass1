/*****************************************************************************
* University of Southern Denmark
* Embedded Programming (EMP)
*
* MODULENAME.: timer.h
*
* PROJECT....: Ass1
*
* DESCRIPTION: This module handles the systick timer interrupt and defines the behavior when this gets called.
*
* Change Log:
******************************************************************************
* Date    Id    Change
* YYMMDD
* --------------------
* 190302  KA    Module created.
*
*****************************************************************************/
#ifndef _TIMER
#define _TIMER

/***************************** Include files *******************************/

/*****************************    Defines    *******************************/

/********************** External declaration of Variables ******************/

/*****************************   Constants   *******************************/

/*************************  Function interfaces ****************************/
void timer_setup();
/*****************************************************************************
*   Input    : Nothing
*   Output   : Nothing
*   Function : To setup the necessary pins and values for the systick timer. The period being 1ms.
******************************************************************************/

uint32_t timer_get();
/*****************************************************************************
*   Input    : Nothing
*   Output   : Outputs the absolute time.
*   Function : This function returns the absolute time.
******************************************************************************/

void timer_handler();
/*****************************************************************************
*   Input    : Nothing
*   Output   : Nothing
*   Function : The interrupt handler for systick, which increments a counter.
******************************************************************************/


/****************************** End Of Module *******************************/
#endif // _TIMER
