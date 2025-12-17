#include "adc.h"
extern uint16_t chanresult;
extern bool adc_done;

void init_ADC(void){

	NVIC_IPR7 |= (2 << 14); //SAR ADC IRQn=25 Priority  2 set
    NVIC_ICPR |= (1 << 25); //NVIC Clear Pending IRQs
    NVIC_ISER |= (1 << 25); //NVIC_EnableIRQ 25

    SAR_CTRL |= ((0x6 << 4) | //Vref sel, select the Vref source, here its VDDA/2
				(0x1 << 7) | //Enable bypass capacitor
				(0x7 << 9) | //Neg sel, select SAR Vref as Vneg value
				(0x1 << 30)| //Disable the switch
				(0x1 << 31)); //Enable ADC

	// SAR_MUX_SWITCH0 -> select Vplus to P2.1
	SAR_MUX_SWITCH0 = (0x1<<1u);  //Close switch between P2.1 to Vplus

	SAR_SAMPLE_CTRL |= (0x0 << 1) | //Makes it right aligned
					   (0x0 << 2) | //Unsigned
					   (0x0 << 16); //Monoshot mode
	
	SAR_SAMPLE_TIME01 |= (0xA); //Set SAMPLE_TIME0 to 10, here its 0.83us, which is less than 10RC (RC = 1k x 10pF)
	
	SAR_CHAN_CONFIG0 =  (0x1 << 0)  | // Select pin1 of port2 to PIN_ADDR
						(0x0 << 4) | //Select port2
						(0x0 << 9) | //Use the max resolution (12-bit)
						(0x0 << 12); //Select Time window - 0 as Tacq time
	SAR_INTR_MASK = (1 << 0); //Enable EOS intr
	SAR_CHAN_EN = (0x1<<0); //Enable Channel - 0 
}

// uint16_t read_ADC(void){
//     SAR_START_CTRL = (0x1<<0);  //Set FW_TRIGGER to 1 to start ADC Conversion

// 	while( (SAR_INTR & 0x1) != 0x1) //Wait till EOS becomes 1
//     { }

// 	return (uint16_t)(SAR_CHAN_RESULT0 & 0xFFF);  //Read the 12-bit result
// }

void pass_0_interrupt_sar_IRQHandler(void)
{
    if ((SAR_INTR)& 0x1)
    {
        // Read ADC result
        chanresult =(uint16_t)((SAR_CHAN_RESULT0) & 0xFFF);

        adc_done = true;
		SAR_INTR = 0x1;
    }
}