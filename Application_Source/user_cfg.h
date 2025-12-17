#ifndef USER_CFG_H
#define USER_CFG_H
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "./../Device_Drivers/GPIO/gpio.h"
#include "./../Special_Libraries/reset.h"
#include "./../Special_Libraries/cmsis_gcc.h"
#include "./../Device_Drivers/CLOCK/Sys_Clock.h"
#include "./../Device_Drivers/SYSTICK/systick.h"
//#include "./../Device_Drivers/TIMER/timer.h"

//MACRO DECLARATIONS
#define CY_SET_REG32(addr, value)       (*((uint32_t *)(addr)) = (uint32_t)(value))
#define CYREG_GPIO_PRT2_DR      0x40040200u
#define CYREG_GPIO_PRT2_PC      0x40040208u

#define CYREG_GPIO_PRT3_DR      0x40040300u
#define CYREG_GPIO_PRT3_PC      0x40040308u

#define CYREG_GPIO_PRT1_DR      0x40040100u
#define CYREG_GPIO_PRT1_PC      0x40040108u

#define CYREG_GPIO_PRT5_DR      0x40040500u
#define CYREG_GPIO_PRT5_PC      0x40040508u

#define HSIOM_SEL_GPIO          0u
#define HSIOM_SEL_PWM           8u

#define CYREG_SRSSLT_CLK_SELECT 0x40030028

#define CYBSP_TIMER_INPUT_DISABLED 0x7U

//Variables that I define:

//NVIC macros
#define NVIC_ISER (*(volatile uint32_t*)0xE000E100)
#define NVIC_ICPR (*(volatile uint32_t*)0xE000E280)
#define NVIC_ISPR (*(volatile uint32_t*)0xE000E200)
#define NVIC_IPR4 (*(volatile uint32_t*)0xE000E410)
#define NVIC_IPR5 (*(volatile uint32_t*)0xE000E414)

extern const cy_stc_gpio_pin_config_t MT1_P2_1_config;
extern const cy_stc_gpio_pin_config_t MT2_P1_5_config;
extern const cy_stc_gpio_pin_config_t LED8_P1_6_config;
extern const cy_stc_gpio_pin_config_t SW2_P3_7_config;
extern const cy_stc_gpio_pin_config_t USERLED_P3_4_config;
extern const cy_stc_gpio_pin_config_t PWM_P1_2_config;
extern const cy_stc_gpio_pin_config_t LED13_P5_7_config;

//extern const cy_stc_tcpwm_counter_config_t TIMER2_config;
//extern const cy_stc_tcpwm_counter_config_t TIMER0_config;
//extern const cy_stc_tcpwm_pwm_config_t USER_PWM_config;

extern void Delay(int32_t);
extern void init_peri_Clock_Config();
extern void timer_Delay_uS(uint32_t delay_uS);

void clock_config(void);
void peri_clk_config(void);
void LED_PWM(void);
void mydelay(uint32_t);

void clock_config(void);
#endif