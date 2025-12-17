#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "user_cfg.h"
//#include "tcpwm.h"

#define NVIC_IPR7 (*(volatile uint32_t*)0xE000E41C)

//ADC Macros
#define SAR_CTRL (*(volatile uint32_t*)0x403A0000)
#define SAR_SAMPLE_CTRL (*(volatile uint32_t*)0x403A0004)
#define SAR_SAMPLE_TIME01 (*(volatile uint32_t*)0x403A0010)
#define SAR_SAMPLE_TIME23 (*(volatile uint32_t*)0x403A0014)
#define SAR_CHAN_EN (*(volatile uint32_t*)0x403A0020)
#define SAR_START_CTRL (*(volatile uint32_t*)0x403A0024)
#define SAR_CHAN_CONFIG0 (*(volatile uint32_t*)0x403A0080)
#define SAR_CHAN_CONFIG1 (*(volatile uint32_t*)0x403A0084)
#define SAR_CHAN_CONFIG2 (*(volatile uint32_t*)0x403A0088)
#define SAR_CHAN_CONFIG3 (*(volatile uint32_t*)0x403A008C)
#define SAR_CHAN_RESULT0 (*(volatile uint32_t*)0x403A0180)
#define SAR_CHAN_RESULT1 (*(volatile uint32_t*)0x403A0184)
#define SAR_CHAN_RESULT2 (*(volatile uint32_t*)0x403A0188)
#define SAR_CHAN_RESULT3 (*(volatile uint32_t*)0x403A018C)
#define SAR_MUX_SWITCH0 (*(volatile uint32_t*)0x403A0300)
#define SAR_INTR (*(volatile uint32_t*)0x403A0210)
#define SAR_INTR_MASK (*(volatile uint32_t*)0x403A0218)

void peri_clk_config_ADC(void);
void init_ADC(void);
uint16_t read_ADC(void);
