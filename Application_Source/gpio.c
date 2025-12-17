#include "gpio.h"

void init_gpio(void){
    /* Configure P2.1 for ADC*/
    GPIO_PRT2_PC &= ~(0x7 << 3); // clear drive mode of P2.1 to analog mode

	/* Configure P2.2 for LED*/
    GPIO_PRT2_DR = (1<<2); // Set default output value of P2.2 to 1
    GPIO_PRT2_PC |= (0x6 << 6); // set drive mode of P2.2 to strong drive mode -> GPIO2.2.PC
	HSIOM_PORT_SEL2 &= ~(0xF << 8u); // Clear HSIOM_PORT_SEL2 pin 2 -> SW GPIO
}