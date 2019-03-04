#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
#include "sw1.h"

#define SW1 0x10

void sw1_setup()
{
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
	while( (SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R5) == 0);

	// Set Digital Enable for button
	GPIO_PORTF_DEN_R |= SW1;
	// Set Pull-Up Enable; GPIO_PORTF_PDR_R for Pull Down Enable
	GPIO_PORTF_PUR_R |= SW1;
}

bool sw1_read()
{
	if( GPIO_PORTF_DATA_R & SW1)
		return false;
	else
		return true;	
}
