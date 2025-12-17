#include "tcpwm.h"
#define TIMER_PERIOD  20000u

void clock_config(void){
    CLK_IMO_SELECT = (0 & 0x7); //IMO = 24MHz
    CLK_IMO_CONFIG = (1 << 31); //Enable IMO
    CLK_SELECT = (0 & 0x3); //Select IMO as source to HFCLK
}

void init_tcpwm0(void){
    /*TIMER 2 - INTERRUPT*/
	NVIC_IPR4 = (1 << 30); //Timer 2 IRQn=19 Priority  1 set
    NVIC_ICPR |= (1<<19); //NVIC Clear Pending IRQs
    NVIC_ISER |= (1 << 19); //NVIC_EnableIRQ 19 
    
    /*TIMER 2 - INIT*/
    TCPWM_CTRL &=~ (1<< 2); //Disable Timer 2  in TCPWM_CTRL Register
    TCPWM_CNT2_COUNTER = 0; //Clear the counter register of  TCPWM2 TCPWM_CNT2_COUNTER Register
    TCPWM_CNT2_TR_CTRL2 = 0; //Clear the  register of  TCPWM2 TCPWM_CNT2_TR_CTRL2 Register
	TCPWM_CNT2_PERIOD  = (TIMER_PERIOD-1); //Set the Period Register of TCPWM2 TCPWM_CNT2_PERIOD Register
	TCPWM_CNT2_CTRL |= (0 << 24); //Mode configuration of for TCPWM2, TCPWM_CNT2_CTRL Regsiter 
	TCPWM_CNT2_INTR_MASK |= (1 << 0); // Set  interrupt mask  by enabling the Interrupt in TCPWM_CNT2_INTR_MASK Register for TCPWM2
	TCPWM_CNT2_INTR |= (1<<0); //Clear any previoius interrupt in  interrupt register in TCPWM_CNT2_INTR Register of TCPWM2 
    TCPWM_CTRL |= (1<< 2); //Enable Timer 2  in TCPWM_CTRL Register
    TCPWM_CMD = (1 << 26); //Triger start Timer 2  in TCPWM_CMD Register
}

void tcpwm_interrupts_2_IRQHandler(void){
    TCPWM_CNT2_INTR |= (1<<0); //clear interrupt  interrupt in TCPWM_CNT2_INTR
    SAR_START_CTRL = (0x1<<0);
    /* Toggle the LED */
    //GPIO_PRT1_DR_INV |= (1<<4); //Toggle the LED on P1.4 by inverting in GPIO_PRT1_DR_INV Register 
}

void peri_clk_config_TCPWM(void)
{
    //TIMER 2 TIMER- CLOCK
    PERI_DIV_CMD = (1<<30) | (1 << 6) | (3 << 0); // Disable the Divider using PERI_DIV_CMD 

    PERI_DIV_16_CTL3 = (24 - 1) << 8 ; //Set the divider value in PERI_DIV_16_CTL3, We are configuring Divider 3 

    PERI_DIV_CMD |= (1<<31) |(3<<14) |(63<<8) |(1<<6) | (3 << 0); //Enable the divder 31:bit, Keep 3 at 15:14 and 63 13:8 this selects the HFCLK as reference , Select 16 bit divider 7:6, and Select the divider no 3 using 5:0;

    PERI_PCLK_CTL8 = (1<<6)|(3<<0); // Specify Divider type 7:6 and Selected Divider 3:0 in register PERI_PCLK_CTL8 TCPWM2 is PERIPHERAL 8
}

void peri_clk_config_ADC(void)
{
	PERI_DIV_CMD = (1<<30)|(1<<6)|(1<<0); // Disable the Divider 1 using PERI_DIV_CMD 
	PERI_DIV_16_CTL1 = (2 - 1) << 8 ; //Set the divider value in PERI_DIV_16_CTL1, We are configuring Divider 1 to 12MHz
	PERI_DIV_CMD |= (1<<31) |(3<<14) |(63<<8) |(1<<6)|(1<<0); //PERI_DIV_CMD 
	PERI_PCLK_CTL18 = (1<<6)|(1<<0); // Specify Divider type 7:6 and Selected Divider 3:0 (Divider 1) in register PERI_PCLK_CTL18 ADC is PERIPHERAL 18
}

void peri_clk_config_UART(void)
{
    PERI_DIV_CMD = (1 << 30) | (1<<6) | (0<<0); //Disable Divider-0, 16 int type
    PERI_DIV_16_CTL0 = (12u) << 8; //HFCLK = 12MHz
    PERI_DIV_CMD |= (1 << 31) | (3 << 14) | (63 << 8) | (1<<6) | (0<<0); //Enable Divider-0, 16 int type

    PERI_PCLK_CTL3 = (1<<6) | (0 << 0); //Route Divider-0 of 16 int type to peripheral-3 for SCB3
}