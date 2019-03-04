#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "timer.h"
#include "rgb.h"
#include "sw1.h"

#define THRESHHOLD_LONG 2000 // ~2 sekunder
#define THRESHHOLD_DOUBLE_CLICK 300 // ~.3 sekunder
#define BTN_DBOUNCE_COUNT 3
#define NUM_COLORS 8

#define FALSE 0
#define TRUE 1

uint8_t colors[] = {RGB_COLOR_NONE,RGB_COLOR_GREEN,RGB_COLOR_BLUE,RGB_COLOR_CYAN,
			RGB_COLOR_RED,RGB_COLOR_YELLOW,RGB_COLOR_MEGANTA, RGB_COLOR_WHITE};
int8_t direction = 0x1;
int8_t color=0;

void color_change();

int main(void) 
{

	rgb_setup();
	sw1_setup();


 	// Setup timer
	__asm("cpsid i");
	timer_setup();
	__asm("cpsie i");

	//rgb_set_color(RGB_COLOR_GREEN);


	uint8_t btn_cnt=0;

	uint32_t btn_time=timer_get();
	uint32_t btn_holdtime;

	uint32_t btn_prev_time = 0;
	
	uint8_t auto_mode = FALSE;
	uint8_t valid_click = FALSE;
	uint32_t cnt_prev=0;
	uint8_t has_cleared = TRUE;

	while(1)
	{
		while(cnt_prev == timer_get());
		cnt_prev = timer_get();
		if( sw1_read() )
		{
			btn_cnt++;
			valid_click = ( (btn_cnt >= BTN_DBOUNCE_COUNT) && (has_cleared==TRUE) )?TRUE:FALSE;
		} else
		{
			btn_cnt=0;
			has_cleared = TRUE;
		}

		if (valid_click)
		{
			has_cleared = FALSE;
			valid_click = FALSE;
			btn_time=timer_get();
			
			do
			{
				btn_holdtime = timer_get() - btn_time;
			} while( sw1_read() && (btn_holdtime<=THRESHHOLD_LONG));

			// Long press
			if( btn_holdtime >= THRESHHOLD_LONG )
			{
				auto_mode = TRUE;
			}
			//Double click
			else if( ( timer_get() - btn_prev_time ) < THRESHHOLD_DOUBLE_CLICK )
			{
				direction ^= 0x1;
			}

			// Single press
			else
			{
				btn_prev_time=timer_get();
				auto_mode = FALSE;
				color_change();
			}
		}
		else if (auto_mode && (timer_get()%200==0))
		{
			color_change();
		}
	}
	return 0;
}

void color_change()
{
	if (direction)
	{
		++color;
		color%=NUM_COLORS;
	} else
	{
		color--;
		if (color<0)
			color=NUM_COLORS-1;
	}
	rgb_set_color(colors[color]);	
}
