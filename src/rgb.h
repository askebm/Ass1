/*****************************************************************************
* University of Southern Denmark
* Embedded Programming (EMP)
*
* MODULENAME.: rgb.h
*
* PROJECT....: Ass1
*
* DESCRIPTION: Control RGB LEDs
*
* Change Log:
******************************************************************************
* Date    Id    Change
* YYMMDD
* --------------------
* 190302  ALL    Module created.
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
*   Function : Setup RGB colors
******************************************************************************/

void rgb_set_color(uint32_t);
/*****************************************************************************
*   Input    : Color
*   Output   : -
*   Function : Set color of RGB LEDs
******************************************************************************/

/****************************** End Of Module *******************************/
#endif
