


/*****************************************************************************
* University of Southern Denmark
* Embedded Programming (EMP)
*
* MODULENAME.: emp.h
*
* PROJECT....: EMP
*
* DESCRIPTION: Test.
*
* Change Log:
******************************************************************************
* Date    Id    Change
* YYMMDD
* --------------------
* 050128  KA    Module created.
*
*****************************************************************************/

#ifndef _RGB_H
#define _RGB_H

/***************************** Include files *******************************/

/*****************************    Defines    *******************************/
#define RGB_COLOR_NONE    0x0
#define RGB_COLOR_GREEN   0x8
#define RGB_COLOR_BLUE    0x4
#define RGB_COLOR_CYAN    0xC
#define RGB_COLOR_RED     0x2
#define RGB_COLOR_YELLOW  0xA
#define RGB_COLOR_MEGANTA 0x6
#define RGB_COLOR_WHITE   0xE

/********************** External declaration of Variables ******************/

/*****************************   Constants   *******************************/

/*************************  Function interfaces ****************************/
void rgb_setup(void);

/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Test function
******************************************************************************/

void rgb_set_color(uint32_t);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Test function
******************************************************************************/

/****************************** End Of Module *******************************/
#endif
