#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "user_cfg.h"
#include "adc.h"
#include "uart.h"
#include "tcpwm.h"
#include "gpio.h"

volatile uint16_t chanresult = 0;
volatile bool adc_done = false;

typedef enum {
    DIR_LEFT  = 'L',
    DIR_RIGHT = 'R',
    DIR_NONE  = 'C'
} dir_t;

static dir_t last_dir = DIR_NONE;

dir_t get_direction(uint16_t adc)
{
    if (adc < 1848)
        return DIR_LEFT;
    else if (adc > 2248)
        return DIR_RIGHT;
    else
        return DIR_NONE;
}

int main()
{  
    clock_config();

	init_gpio();
    peri_clk_config_ADC();
	peri_clk_config_TCPWM();
	peri_clk_config_UART();

	init_ADC();
	init_tcpwm0();
	init_SCB3();
    enable_irq();

    for(;;)
    {
		if(adc_done == true){
			adc_done = false;
			dir_t curr = get_direction(chanresult);
			if(curr != last_dir){
				uart_send(curr);
				uart_send('\n');
				last_dir = curr;
			}
		}
    }
    return 0;
}


