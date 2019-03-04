#include <stdint.h>
#include <inc/tm4c123gh6pm.h>
#include "rgb.h"

#define RGB_PINS 0x0E

void rgb_setup(void)
{
	// Enable PORTF
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
	// Wait for PORTF to be accesable
	while((SYSCTL_PRGPIO_R & SYSCTL_RCGCGPIO_R5)==0);
	// Set Direction; Input Output
	GPIO_PORTF_DIR_R |= RGB_PINS;
	// Set Digital Enable 
	GPIO_PORTF_DEN_R |= RGB_PINS;
	// Disable pullup
	GPIO_PORTF_PUR_R &= ~RGB_PINS;
}

void rgb_set_color(uint32_t color)
{
	// Turn off LEDs 
	GPIO_PORTF_DATA_R &= ~RGB_PINS;
	// Write new color
	GPIO_PORTF_DATA_R |= color & RGB_PINS;
}

