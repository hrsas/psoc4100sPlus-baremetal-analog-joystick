#include <stdint.h>
#include "./../Special_Libraries/cmsis_gcc.h"

#define SRAM_START  0x20000000U
#define SRAM_SIZE   (16U * 1024U) //16KB
#define SRAM_END    ((SRAM_START) + (SRAM_SIZE))

#define STACK_START    SRAM_END
#define CYREG_WDT_DISABLE_KEY           0x40030038u
#define CY_SYS_WDT_KEY                  ((uint32_t)(0xACED8865u))

extern uint32_t __etext;
extern uint32_t __data_start;
extern uint32_t __data_end;
extern uint32_t _la_data;

extern uint32_t __bss_start__;
extern uint32_t __bss_end__;

extern uint32_t __STACK_START;
extern uint32_t __STACK_END;
extern void _init(void) {;}
/* The static objects constructors initializer */
extern void __libc_init_array(void);

int main(void);

void Reset_handler(void);
//void Reset_handler(void) __attribute__((section(".rand_vector"))) ;
void Default_Handler(void);
void HRDFLT_Handler(void);

void NMI_Handler                        (void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler                  (void) __attribute__ ((weak, alias("HRDFLT_Handler")));
void SVC_Handler                        (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler                     (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler                    (void) __attribute__ ((weak, alias("Default_Handler")));

void ioss_interrupts_gpio_0_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler"))); /* GPIO P0 */
void ioss_interrupts_gpio_1_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler"))); /* GPIO P1 */
void ioss_interrupts_gpio_2_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler"))); /* GPIO P2 */
void ioss_interrupts_gpio_3_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler"))); /* GPIO P3 */
void ioss_interrupt_gpio_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler"))); /* GPIO All Ports */
void lpcomp_interrupt_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler"))); /* LPCOMP trigger interrupt */
void srss_interrupt_wdt_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler"))); /* WDT */
void scb_0_interrupt_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler"))); /* SCB #0 */
void scb_1_interrupt_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler"))); /* SCB #1 */
void scb_2_interrupt_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler"))); /* SCB #2 */
void scb_3_interrupt_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler"))); /* SCB #3 */
void scb_4_interrupt_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler"))); /* SCB #4 */
void pass_0_interrupt_ctbs_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler"))); /* CTBm Interrupt (all CTBms) */
void wco_interrupt_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler"))); /* WCO WDT Interrupt */
void cpuss_interrupt_dma_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler"))); /* DMA Interrupt */
void cpuss_interrupt_spcif_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler"))); /* SPCIF interrupt */
void csd_interrupt_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler"))); /* CSD #0 (Primarily Capsense) */
void tcpwm_interrupts_0_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler"))); /* TCPWM #0, Counter #0 */
void tcpwm_interrupts_1_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler"))); /* TCPWM #0, Counter #1 */
void tcpwm_interrupts_2_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler"))); /* TCPWM #0, Counter #2 */
void tcpwm_interrupts_3_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler"))); /* TCPWM #0, Counter #3 */
void tcpwm_interrupts_4_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler"))); /* TCPWM #0, Counter #4 */
void tcpwm_interrupts_5_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler"))); /* TCPWM #0, Counter #5 */
void tcpwm_interrupts_6_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler"))); /* TCPWM #0, Counter #6 */
void tcpwm_interrupts_7_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler"))); /* TCPWM #0, Counter #7 */
void pass_0_interrupt_sar_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler"))); /* SAR */
void can_interrupt_can_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler"))); /* CAN Interrupt */
void crypto_interrupt_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler"))); /* Crypto Interrupt */

const uint32_t vector[48] __attribute__((section(".isr_vector")))= {
    STACK_START,
    (uint32_t)&Reset_handler,                            /*     Reset Handler */
    (uint32_t)NMI_Handler,                              /* -14 NMI Handler */
    (uint32_t)HardFault_Handler,                        /* -13 Hard Fault Handler */
    (uint32_t)0,                                        /*     Reserved */
    (uint32_t)0,                                        /*     Reserved */
    (uint32_t)0,                                        /*     Reserved */
    (uint32_t)0,                                        /*     Reserved */
    (uint32_t)0,                                        /*     Reserved */
    (uint32_t)0,                                        /*     Reserved */
    (uint32_t)0,                                        /*     Reserved */
    (uint32_t)SVC_Handler,                              /*  -5 SVCall Handler */
    (uint32_t)0,                                        /*     Reserved */
    (uint32_t)0,                                        /*     Reserved */
    (uint32_t)PendSV_Handler,                           /*  -2 PendSV Handler */
    (uint32_t)SysTick_Handler,                          /*  -1 SysTick Handler */

    /* Interrupts */
    (uint32_t)ioss_interrupts_gpio_0_IRQHandler,        /*   0 GPIO P0 */
    (uint32_t)ioss_interrupts_gpio_1_IRQHandler,        /*   1 GPIO P1 */
    (uint32_t)ioss_interrupts_gpio_2_IRQHandler,        /*   2 GPIO P2 */
    (uint32_t)ioss_interrupts_gpio_3_IRQHandler,        /*   3 GPIO P3 */
    (uint32_t)ioss_interrupt_gpio_IRQHandler,           /*   4 GPIO All Ports */
    (uint32_t)lpcomp_interrupt_IRQHandler,              /*   5 LPCOMP trigger interrupt */
    (uint32_t)srss_interrupt_wdt_IRQHandler,            /*   6 WDT */
    (uint32_t)scb_0_interrupt_IRQHandler,               /*   7 SCB #0 */
    (uint32_t)scb_1_interrupt_IRQHandler,               /*   8 SCB #1 */
    (uint32_t)scb_2_interrupt_IRQHandler,               /*   9 SCB #2 */
    (uint32_t)scb_3_interrupt_IRQHandler,               /*  10 SCB #3 */
    (uint32_t)scb_4_interrupt_IRQHandler,               /*  11 SCB #4 */
    (uint32_t)pass_0_interrupt_ctbs_IRQHandler,         /*  12 CTBm Interrupt (all CTBms) */
    (uint32_t)wco_interrupt_IRQHandler,                 /*  13 WCO WDT Interrupt */
    (uint32_t)cpuss_interrupt_dma_IRQHandler,           /*  14 DMA Interrupt */
    (uint32_t)cpuss_interrupt_spcif_IRQHandler,         /*  15 SPCIF interrupt */
    (uint32_t)csd_interrupt_IRQHandler,                 /*  16 CSD #0 (Primarily Capsense) */
    (uint32_t)tcpwm_interrupts_0_IRQHandler,            /*  17 TCPWM #0, Counter #0 */
    (uint32_t)tcpwm_interrupts_1_IRQHandler,            /*  18 TCPWM #0, Counter #1 */
    (uint32_t)tcpwm_interrupts_2_IRQHandler,            /*  19 TCPWM #0, Counter #2 */
    (uint32_t)tcpwm_interrupts_3_IRQHandler,            /*  20 TCPWM #0, Counter #3 */
    (uint32_t)tcpwm_interrupts_4_IRQHandler,            /*  21 TCPWM #0, Counter #4 */
    (uint32_t)tcpwm_interrupts_5_IRQHandler,            /*  22 TCPWM #0, Counter #5 */
    (uint32_t)tcpwm_interrupts_6_IRQHandler,            /*  23 TCPWM #0, Counter #6 */
    (uint32_t)tcpwm_interrupts_7_IRQHandler,            /*  24 TCPWM #0, Counter #7 */
    (uint32_t)pass_0_interrupt_sar_IRQHandler,          /*  25 SAR */
    (uint32_t)can_interrupt_can_IRQHandler,             /*  26 CAN Interrupt */
    (uint32_t)crypto_interrupt_IRQHandler               /*  27 Crypto Interrupt */
};

void Reset_handler(void)
{
    //disable watchdog
    (*(uint32_t *) CYREG_WDT_DISABLE_KEY) = CY_SYS_WDT_KEY;

    //copy .data section to SRAM
    uint32_t size = &__data_end - &__data_start;
    uint32_t *pDst = (uint32_t*)&__data_start;
    uint32_t *pSrc = (uint32_t*)&_la_data;

    for(uint32_t i = 0; i< size; i++)
    {
        *pDst++ = *pSrc++;
    }
    //int the .bss section to zero in SRAM
    size = &__bss_end__ - &__bss_start__;
    pDst = (uint32_t*)&__bss_start__;

    for(uint32_t i = 0; i< size; i++)
    {
        *pDst++ = 0;
    }

    // Init C std libs
    __libc_init_array();
    

    //call main()
    main();

    while (1)
    {
        /* If main returns, make sure we don't return. */
    }
}

/*----------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *----------------------------------------------------------------------------*/
void Default_Handler(void)
{
    while(1);
}

/*----------------------------------------------------------------------------
  Default Handler for Hard Fault
 *----------------------------------------------------------------------------*/
void HRDFLT_Handler(void)
{
    while(1);
}