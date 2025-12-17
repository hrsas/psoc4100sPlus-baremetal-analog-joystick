#include "user_cfg.h"

const cy_stc_gpio_pin_config_t MT1_P2_1_config = 
{
    .outVal = 1,
    .driveMode = 0x06UL,
    .intEdge = 0x00UL,
    .vtrip = 0,
    .slewRate = 0,
};

const cy_stc_gpio_pin_config_t MT2_P1_5_config = 
{
    .outVal = 1,
    .driveMode = 0x06UL,
    .intEdge = 0x00UL,
    .vtrip = 0,
    .slewRate = 0,
};

const cy_stc_gpio_pin_config_t LED8_P1_6_config = 
{
    .outVal = 1,
    .driveMode = 0x06UL,
    .intEdge = 0x00UL,
    .vtrip = 0,
    .slewRate = 0,
};

const cy_stc_gpio_pin_config_t SW2_P3_7_config = 
{
    .outVal = 1,
    .driveMode = 0x02UL, // 1 - HZ, 2 - PU, 3 - PD, 6 - SD
    .intEdge = 0x02UL, // 0 - disabled, 1 - Rising, 2 - Falling, 3 - Both
    .vtrip = 0, //0 - CMOS, 1 - TTL
    .slewRate = 0, //0 - fast, 1 - slow
};

const cy_stc_gpio_pin_config_t USERLED_P3_4_config = 
{
    .outVal = 1,
    .driveMode = 0x06UL, // 1 - HZ, 2 - PU, 3 - PD, 6 - SD
    .intEdge = 0x0UL, // 0 - disabled, 1 - Rising, 2 - Falling, 3 - Both
    .vtrip = 0, //0 - CMOS, 1 - TTL
    .slewRate = 0, //0 - fast, 1 - slow
};

const cy_stc_gpio_pin_config_t PWM_P1_2_config = 
{
    .outVal = 1,
    .driveMode = 0x06UL, // 1 - HZ, 2 - PU, 3 - PD, 6 - SD
    .intEdge = 0x0UL, // 0 - disabled, 1 - Rising, 2 - Falling, 3 - Both
    .vtrip = 0, //0 - CMOS, 1 - TTL
    .slewRate = 0, //0 - fast, 1 - slow
};

const cy_stc_gpio_pin_config_t LED13_P5_7_config = 
{
    .outVal = 1,
    .driveMode = 0x06UL,
    .intEdge = 0x00UL,
    .vtrip = 0,
    .slewRate = 0,
};



/*
#define CYBSP_TIMER_INPUT_DISABLED 0x7U
const cy_stc_tcpwm_counter_config_t TIMER2_config = 
{
    .period = 32768,
    .clockPrescaler = 0, //Prescalar divide by 1
    .runMode = 0u, //0 - Contineous, 1 - OneShot
    .countDirection = 0, //0- Count Up, 1 - Count Down
    .compareOrCapture = 2U, //2- Capture, 0 - Compare mode
    .compare0 = 16384,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = 1U, // (0U) No Interrupt, (1U) Interrupt on Terminal count(TC), (2U) Interrupt on Compare/Capture(CC), (3U) Interrupt on TC or CC
    .captureInputMode = CYBSP_TIMER_INPUT_DISABLED & 0x3U,
    .captureInput = 0, //0 Logic 0, 1- logic 1
    .reloadInputMode = CYBSP_TIMER_INPUT_DISABLED & 0x3U,
    .reloadInput = 0, //0 Logic 0, 1- logic 1
    .startInputMode = CYBSP_TIMER_INPUT_DISABLED & 0x3U,
    .startInput = 0, //0 Logic 0, 1- logic 1
    .stopInputMode = CYBSP_TIMER_INPUT_DISABLED & 0x3U,
    .stopInput = 0, //0 Logic 0, 1- logic 1
    .countInputMode = CYBSP_TIMER_INPUT_DISABLED & 0x3U,
    .countInput = 1u,
};
const cy_stc_tcpwm_counter_config_t TIMER0_config = 
{
    .period = 32768,
    .clockPrescaler = 0, //Prescalar divide by 1
    .runMode = 0u, //0 - Contineous, 1 - OneShot
    .countDirection = 0, //0- Count Up, 1 - Count Down
    .compareOrCapture = 2U, //2- Capture, 0 - Compare mode
    .compare0 = 16384,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = 0U, // (0U) No Interrupt, (1U) Interrupt on Terminal count(TC), (2U) Interrupt on Compare/Capture(CC), (3U) Interrupt on TC or CC
    .captureInputMode = CYBSP_TIMER_INPUT_DISABLED & 0x3U,
    .captureInput = 0, //0 Logic 0, 1- logic 1
    .reloadInputMode = CYBSP_TIMER_INPUT_DISABLED & 0x3U,
    .reloadInput = 0, //0 Logic 0, 1- logic 1
    .startInputMode = CYBSP_TIMER_INPUT_DISABLED & 0x3U,
    .startInput = 0, //0 Logic 0, 1- logic 1
    .stopInputMode = CYBSP_TIMER_INPUT_DISABLED & 0x3U,
    .stopInput = 0, //0 Logic 0, 1- logic 1
    .countInputMode = CYBSP_TIMER_INPUT_DISABLED & 0x3U,
    .countInput = 1u,
};
const cy_stc_tcpwm_pwm_config_t USER_PWM_config = 
{
    .pwmMode = 4U,    //Standard PWM Mode
    .clockPrescaler = 0U, //Divide by 1
    .pwmAlignment = 0U, // 0 = LEFT ALIGH, 1= RIGHT ALIGN, 2U = CENTER ALIGN
    .deadTimeClocks = 0,
    .runMode = 0U, //0 = CONTINUOUS, 1 = One Shot
    .period0 = 10000,
    .period1 = 5000,
    .enablePeriodSwap = false,
    .compare0 = 5000,
    .compare1 = 1000,
    .enableCompareSwap = false,
    .interruptSources = 0U, //0 = No Interrupt, 1 = TC, 2 = CC, 3 = TC & CC
    .invertPWMOut = 0U, //0 = Disable Invert Mode
    .invertPWMOutN = 0U, //0 = Do not invert
    .killMode = 2U, //PWM stops counting on kill
    .swapInputMode = 0x7U & 0x3U,
    .swapInput = 0u,
    .reloadInputMode = 0x7U & 0x3U,
    .reloadInput = 0u,
    .startInputMode = 0x7U & 0x3U,
    .startInput = 0u,
    .killInputMode = 0x7U & 0x3U,
    .killInput = 0u,
    .countInputMode = 0x7U & 0x3U,
    .countInput = 1U,
};

*/