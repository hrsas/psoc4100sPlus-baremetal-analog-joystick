#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "user_cfg.h"
#include "adc.h"
//Timer macros
#define TCPWM_CTRL (*(volatile uint32_t*)0x40200000)
#define TCPWM_CMD (*(volatile uint32_t*)0x40200008)

#define TCPWM_CNT2_CTRL (*(volatile uint32_t*)0x40200180)
#define TCPWM_CNT2_TR_CTRL0 (*(volatile uint32_t*)0x402001A0)
#define TCPWM_CNT2_TR_CTRL2 (*(volatile uint32_t*)0x402001A8)
#define TCPWM_CNT2_COUNTER (*(volatile uint32_t*)0x40200188)
#define TCPWM_CNT2_PERIOD (*(volatile uint32_t*)0x40200194)
#define TCPWM_CNT2_CC (*(volatile uint32_t*)0x4020018C)
#define TCPWM_CNT2_CC_BUFF (*(volatile uint32_t*)0x40200190)
#define TCPWM_CNT2_INTR_MASK (*(volatile uint32_t*)0x402001B8)
#define TCPWM_CNT2_INTR (*(volatile uint32_t*)0x402001B0)

#define TCPWM_CNT3_CTRL (*(volatile uint32_t*)0x402001C0)
#define TCPWM_CNT3_TR_CTRL0 (*(volatile uint32_t*)0x402001E0)
#define TCPWM_CNT3_TR_CTRL2 (*(volatile uint32_t*)0x402001E8)
#define TCPWM_CNT3_COUNTER (*(volatile uint32_t*)0x402001C8)
#define TCPWM_CNT3_PERIOD (*(volatile uint32_t*)0x402001D4)
#define TCPWM_CNT3_CC (*(volatile uint32_t*)0x402001CC)
#define TCPWM_CNT3_CC_BUFF (*(volatile uint32_t*)0x402001D0)
#define TCPWM_CNT3_INTR_MASK (*(volatile uint32_t*)0x402001F8)
#define TCPWM_CNT3_INTR (*(volatile uint32_t*)0x402001F0)

#define TCPWM_CNT5_CTRL (*(volatile uint32_t*)0x40200240)
#define TCPWM_CNT5_TR_CTRL0 (*(volatile uint32_t*)0x40200260)
#define TCPWM_CNT5_TR_CTRL2 (*(volatile uint32_t*)0x40200268)
#define TCPWM_CNT5_COUNTER (*(volatile uint32_t*)0x40200248)
#define TCPWM_CNT5_PERIOD (*(volatile uint32_t*)0x40200254)
#define TCPWM_CNT5_CC (*(volatile uint32_t*)0x4020024C)
#define TCPWM_CNT5_CC_BUFF (*(volatile uint32_t*)0x40200250)
#define TCPWM_CNT5_INTR_MASK (*(volatile uint32_t*)0x40200278)
#define TCPWM_CNT5_INTR (*(volatile uint32_t*)0x40200270)

//Clock macros
#define CLK_SELECT (*(volatile uint32_t*)0x40030028)
#define CLK_IMO_CONFIG (*(volatile uint32_t*)0x40030030)
#define CLK_IMO_SELECT (*(volatile uint32_t*)0x40030F08)

//Peripheral-Clock macros
#define PERI_DIV_CMD (*(volatile uint32_t*)0x40010000)

#define PERI_PCLK_CTL9 (*(volatile uint32_t*)0x40010124)
#define PERI_PCLK_CTL0 (*(volatile uint32_t*)0x40010100)
#define PERI_PCLK_CTL3 (*(volatile uint32_t*)0x4001010C)
#define PERI_PCLK_CTL11 (*(volatile uint32_t*)0x4001012C)
#define PERI_PCLK_CTL18 (*(volatile uint32_t*)0x40010148)

#define PERI_DIV_16_CTL0 (*(volatile uint32_t*)0x40010300)
#define PERI_DIV_16_CTL1 (*(volatile uint32_t*)0x40010304)
#define PERI_DIV_16_CTL3 (*(volatile uint32_t*)0x4001030C)
#define PERI_PCLK_CTL8 (*(volatile uint32_t*)0x40010120)

void clock_config(void);
void peri_clk_config_UART(void);
void peri_clk_config_ADC(void);
void peri_clk_config_TCPWM(void);
void init_tcpwm0(void);
