#include <inc/tm4c123gh6pm.h>
#include <stdint.h>
#include "timer1a.h"

#define RELOAD_VALUE 0xFFFFFFFF

void timer1a_setup()
{
	// RCGCTIMER or RCGCWTIMER
	SYSCTL_RCGCTIMER_R |= SYSCTL_RCGCTIMER_R1;
	// Disable timer on GPTMCTL
	TIMER1_CTL_R &= ~(TIMER_CTL_TAEN);
	// Write config CPTMCFG
	TIMER1_CFG_R |= TIMER_CFG_32_BIT_TIMER;
	// Config TnMR in GPTMTnMR
	TIMER1_TAMR_R |= TIMER_TAMR_TAMR_PERIOD;
	// Set reload value in GPTMTnILR
	TIMER1_TAILR_R = RELOAD_VALUE;
	// If interrupt set bits in GPTMIMR
	
}

uint32_t timer1a_get()
{
	return TIMER1_TAV_R;
}
