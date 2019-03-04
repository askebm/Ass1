/*****************************************************************************
* University of Southern Denmark
* Embedded Programming (EMP)
*
* MODULENAME.: timer.c
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

/***************************** Include files *******************************/
#include <stdint.h>
#include <inc/tm4c123gh6pm.h>
/*****************************    Defines    *******************************/
#define SYSTICK_RELOAD_VALUE 16000 // ~1 mili second

// Missing definitions in tm4c123gh6pm.h file
#define NVIC_INT_CTRL_PEND_SYST   0x04000000  // Pend a systick int
#define NVIC_INT_CTRL_UNPEND_SYST 0x02000000  // Unpend a systick int

#define SYSTICK_PRIORITY    0x7E
/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/
volatile uint32_t counter=0;


/*****************************   Functions   *******************************/

void timer_handler()
/*****************************************************************************
*   Input    : Nothing
*   Output   : Nothing
*   Function : The interrupt handler for systick, which increments a counter.
******************************************************************************/
{
	counter++;
}

uint32_t timer_get()
/*****************************************************************************
*   Input    : Nothing
*   Output   : Outputs the absolute time.
*   Function : This function returns the absolute time.
******************************************************************************/
{
	return counter;
}

void timer_setup()
/*****************************************************************************
*   Input    : Nothing
*   Output   : Nothing
*   Function : To setup the necessary pins and values for the systick timer. The period being 1ms.
******************************************************************************/
{
  // Disable systick timer
  NVIC_ST_CTRL_R &= ~(NVIC_ST_CTRL_ENABLE);

  // Set current systick counter to reload value
  NVIC_ST_CURRENT_R = SYSTICK_RELOAD_VALUE;
  // Set Reload value, Systick reload register
  NVIC_ST_RELOAD_R = SYSTICK_RELOAD_VALUE;

  // NVIC systick setup, vector number 15
  // Clear pending systick interrupt request
  NVIC_INT_CTRL_R |= NVIC_INT_CTRL_UNPEND_SYST;

  // Set systick priority to 0x10, first clear then set.
  NVIC_SYS_PRI3_R &= ~(NVIC_SYS_PRI3_TICK_M);
  NVIC_SYS_PRI3_R |= (NVIC_SYS_PRI3_TICK_M & (SYSTICK_PRIORITY<<NVIC_SYS_PRI3_TICK_S));

  // Select systick clock source, Use core clock
  NVIC_ST_CTRL_R |= NVIC_ST_CTRL_CLK_SRC;

  // Enable systick interrupt
  NVIC_ST_CTRL_R |= NVIC_ST_CTRL_INTEN;

  // Enable and start timer
  NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE;
}
/****************************** End Of Module *******************************/
