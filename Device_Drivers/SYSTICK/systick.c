#include "SysTick.h"

void SysTick_Config(uint32_t count)
{
    /* 
	  Configure the SYSTICK TIMER to generate interrupts every N seconds,
	  Clock Frequency is 24MHz. Determine N from 24MHz and count.
	*/
	  *((uint32_t *)CYREG_CM0P_SYST_RVR) = count;

	/* Clear any spurious SYSTICK interrupt */
	uint32_t systick_word = *((uint32_t *)CYREG_CM0P_ICSR);
    systick_word          = systick_word | 0x02000000;
    *((uint32_t *)CYREG_CM0P_ICSR) = systick_word;
	
	/* Set the SYSTICK Clock and Enable interrupt generation */
	*((uint32_t *)CYREG_CM0P_SYST_CSR) = 0x7;
}

void SysTick_Acknowledge_Interrupt(void)
{
  /* Clear the interrupt */
  uint32_t systick_word = *((uint32_t *)CYREG_CM0P_ICSR);
  systick_word          = systick_word | 0x02000000;
  *((uint32_t *)CYREG_CM0P_ICSR) = systick_word;

}