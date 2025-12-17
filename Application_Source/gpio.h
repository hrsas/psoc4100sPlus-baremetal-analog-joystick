#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "user_cfg.h"

//GPIO macros
#define GPIO_PRT1_DR (*(volatile uint32_t*)0x40040100)
#define GPIO_PRT1_PC (*(volatile uint32_t*)0x40040108)
#define GPIO_PRT1_DR_SET (*(volatile uint32_t*)0x40040140)
#define GPIO_PRT1_DR_CLR (*(volatile uint32_t*)0x40040144)

#define GPIO_PRT2_DR (*(volatile uint32_t*)0x40040200)
#define GPIO_PRT2_PC (*(volatile uint32_t*)0x40040208)
#define GPIO_PRT2_DR_SET (*(volatile uint32_t*)0x40040240)
#define GPIO_PRT2_DR_CLR (*(volatile uint32_t*)0x40040244)

#define GPIO_PRT5_DR (*(volatile uint32_t*)0x40040500)
#define GPIO_PRT5_PC (*(volatile uint32_t*)0x40040508)
#define GPIO_PRT5_DR_SET (*(volatile uint32_t*)0x40040540)
#define GPIO_PRT5_DR_CLR (*(volatile uint32_t*)0x40040544)

#define GPIO_PRT7_PC (*(volatile uint32_t*)0x40040708)
#define GPIO_PRT7_DR (*(volatile uint32_t*)0x40040700)

//HSIOM macros
#define HSIOM_PORT_SEL1 (*(volatile uint32_t*)0x40020100)
#define HSIOM_PORT_SEL2 (*(volatile uint32_t*)0x40020200)
#define HSIOM_PORT_SEL5 (*(volatile uint32_t*)0x40020500)
#define HSIOM_PORT_SEL7 (*(volatile uint32_t*)0x40020700)

void init_gpio(void);