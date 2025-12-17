#include "uart.h"

void init_SCB3(void){
    //Config pin7.1 as UART TX (Strong Drive):
    HSIOM_PORT_SEL7 = (HSIOM_PORT_SEL7 & ~(0xFu << 4)) | (0x9u << 4);
    GPIO_PRT7_PC    = (GPIO_PRT7_PC    & ~(0x7u << 3)) | (0x6u << 3);

    //P7.0 -> SCB3 UART RX (High-Z)
    HSIOM_PORT_SEL7 = (HSIOM_PORT_SEL7 & ~(0xFu << 0)) | (0x9u << 0);
    GPIO_PRT7_PC    = (GPIO_PRT7_PC    & ~(0x7u << 0)) | (0x2u << 0);

    // Configure UART with block DISABLED
    SCB3_CTRL = (2 << 24)   // UART mode
              | (15u << 0); // OVS = 16

    SCB3_UART_CTRL = 0;//(1 << 16);  // Loopback enabled

    // TX Control: Enable + 8-bit data width + LSB first
    SCB3_TX_CTRL = (1 << 0)      // Enable TX (bit 0)
                 | (7u << 1)     // Data width bits (bits 1-4): 7 = 8 bits
                 | (0 << 8);     // LSB first (bit 8 = 0)

    // RX Control: Enable + 8-bit data width + LSB first  
    SCB3_RX_CTRL = (1 << 0)      // Enable RX (bit 0)
                 | (7u << 1)     // Data width bits (bits 1-4): 7 = 8 bits
                 | (0 << 8);     // LSB first (bit 8 = 0)

    // Clear FIFOs
    SCB3_TX_FIFO_CTRL = (1 << 16);
    SCB3_RX_FIFO_CTRL = (1 << 16);
    
    for(volatile int i = 0; i < 100; i++);
    
    SCB3_TX_FIFO_CTRL = (0 << 0);
    SCB3_RX_FIFO_CTRL = (0 << 0);

    // Enable the block
    SCB3_CTRL |= (1 << 31);
}

void uart_send(char c){
    while ((SCB3_TX_FIFO_STATUS & 0x1Fu) >= 8);
    SCB3_TX_FIFO_WR = (uint32_t)c;
}

