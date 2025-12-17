#ifndef __CY_SYSTICK_H
#define __CY_SYSTICK_H

#include <stdint.h>

#define CYREG_CM0P_SYST_CSR     0xE000E010
#define CYREG_CM0P_SYST_RVR     0xE000E014
#define CYREG_CM0P_SYST_CVR     0xE000E018
#define CYREG_CM0P_ICSR         0xE000ED04 /* Write a 1 to Bit-25 to Clear Pending Interrupt */

void SysTick_Config(uint32_t count);
void SysTick_Acknowledge_Interrupt(void);

#endif