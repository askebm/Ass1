#include <stdint.h>
#include <inc/tm4c123gh6pm.h>
#include "rgb.h"

#define GPIO_PORTF_SW1 0x10 //PF4
#define NVIC_PORTF_BIT 0x40000000 //BIT 30

void sw1_interrupt_setup(void)
{
	// GPIOIM Enables interrupt in GPIO
	// GPIOIS Interrupt sense
	// GPIOIBE Interupt Bothe edges
	// GPIOIEV Intterupt event
	// GPIOAFSEL Alternate function select
	
	// Enable Port F
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF;
	
	// Burn at least 3 cycles
	int dummy;
	dummy = SYSCTL_RCGC2_R;

	// SW1 as input
	GPIO_PORTF_DIR_R &= ~GPIO_PORTF_SW1;

	// Not alternate function
	GPIO_PORTF_AFSEL_R &= ~GPIO_PORTF_SW1;

	// Digital enable
	GPIO_PORTF_DEN_R |= GPIO_PORTF_SW1;

//	GPIO_PORTF_PCTL_R &= ~0x000F0000; // configure PF4 as GPIO

	 // Disable Analog functionalitet
	GPIO_PORTF_AMSEL_R = 0;

	// Is not open drain
	GPIO_PORTF_ODR_R &= ~GPIO_PORTF_SW1;

	// Is edge sensitive
	GPIO_PORTF_IS_R &= ~GPIO_PORTF_SW1;

	// Is not both sides
	GPIO_PORTF_IBE_R &= ~GPIO_PORTF_SW1;

	// Trigger on Rising edge og High level
	GPIO_PORTF_IEV_R &= ~GPIO_PORTF_SW1;
	
	// Interrupt clear
	GPIO_PORTF_ICR_R |=GPIO_PORTF_SW1;
	
	// Mux SW1 to interrupt
	GPIO_PORTF_IM_R |= GPIO_PORTF_SW1;

	//NVIC enable interrupt
	NVIC_EN0_R |= NVIC_PORTF_BIT;
}

volatile uint16_t cnt_sw1=0;
void sw1_int_handler(void)
{
	rgb_set_color(RGB_COLOR_BLUE);
	cnt_sw1++;	
}

uint16_t sw1_get_cnt(void)
{
	return cnt_sw1;
}
