#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "user_cfg.h"
#include "gpio.h"
#include "adc.h"

//UART macros
#define SCB3_CTRL (*(volatile uint32_t*)0x40270000)
#define SCB3_UART_CTRL (*(volatile uint32_t*)0x40270040)
#define SCB3_UART_TX_CTRL (*(volatile uint32_t*)0x40270044)
#define SCB3_TX_CTRL (*(volatile uint32_t*)0x40270200)
#define SCB3_RX_CTRL (*(volatile uint32_t*)0x40270300)
#define SCB3_TX_FIFO_CTRL (*(volatile uint32_t*)0x40270204)
#define SCB3_RX_FIFO_CTRL (*(volatile uint32_t*)0x40270304)
#define SCB3_TX_FIFO_STATUS (*(volatile uint32_t*)0x40270208)
#define SCB3_RX_FIFO_STATUS (*(volatile uint32_t*)0x40270308)
#define SCB3_TX_FIFO_WR (*(volatile uint32_t*)0x40270240)
#define SCB3_RX_FIFO_RD (*(volatile uint32_t*)0x40270340)
#define SCB3_INTR_TX (*(volatile uint32_t*)0x40270F80)

void init_SCB3(void);
void uart_send(char);
void peri_clk_config_UART(void);

