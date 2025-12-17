#include <stdint.h>
#include "timer.h"

void TCPWM_Counter_Init(TCPWM_Type *base, uint32_t cntNum, cy_stc_tcpwm_counter_config_t const *config)
{

        TCPWM_CNT_CTRL(base, cntNum) = ((((uint32_t)(config->clockPrescaler) << TCPWM_CNT_CTRL_GENERIC_Pos) & TCPWM_CNT_CTRL_GENERIC_Msk) |
                                      (((uint32_t)(config->runMode) << TCPWM_CNT_CTRL_ONE_SHOT_Pos) & TCPWM_CNT_CTRL_ONE_SHOT_Msk) |
                                      (((uint32_t)(config->countDirection) << TCPWM_CNT_CTRL_UP_DOWN_MODE_Pos) & TCPWM_CNT_CTRL_UP_DOWN_MODE_Msk) |
                                      (((uint32_t)(config->compareOrCapture) << TCPWM_CNT_CTRL_MODE_Pos) & TCPWM_CNT_CTRL_MODE_Msk) |
                                      (config->enableCompareSwap ? TCPWM_CNT_CTRL_AUTO_RELOAD_CC_Msk : 0UL));

        if (0u == config->countDirection)//Count UP
        {
            TCPWM_CNT_COUNTER(base, cntNum) = 0U;
        }
        else if (1U == config->countDirection) //Count Down
        {
            TCPWM_CNT_COUNTER(base, cntNum) = config->period;
        }
        else
        {
            TCPWM_CNT_COUNTER(base, cntNum) = 1U;
        }

        if (0u == config->compareOrCapture) //Compare
        {
            TCPWM_CNT_CC(base, cntNum) = config->compare0;
            TCPWM_CNT_CC_BUFF(base, cntNum) = config->compare1;
        }

        TCPWM_CNT_PERIOD(base, cntNum) = config->period;

        TCPWM_CNT_TR_CTRL0(base, cntNum) = ((((uint32_t)(config->captureInput) << TCPWM_CNT_TR_CTRL0_CAPTURE_SEL_Pos) & TCPWM_CNT_TR_CTRL0_CAPTURE_SEL_Msk) |
                                            (((uint32_t)(config->reloadInput) << TCPWM_CNT_TR_CTRL0_RELOAD_SEL_Pos) & TCPWM_CNT_TR_CTRL0_RELOAD_SEL_Msk) |
                                            (((uint32_t)(config->startInput) << TCPWM_CNT_TR_CTRL0_START_SEL_Pos) & TCPWM_CNT_TR_CTRL0_START_SEL_Msk) |
                                            (((uint32_t)(config->stopInput) << TCPWM_CNT_TR_CTRL0_STOP_SEL_Pos) & TCPWM_CNT_TR_CTRL0_STOP_SEL_Msk) |
                                            (((uint32_t)(config->countInput) << TCPWM_CNT_TR_CTRL0_COUNT_SEL_Pos) & TCPWM_CNT_TR_CTRL0_COUNT_SEL_Msk));

        TCPWM_CNT_TR_CTRL1(base, cntNum) = (((uint32_t)(config->captureInputMode) << TCPWM_CNT_TR_CTRL1_CAPTURE_EDGE_Pos) & TCPWM_CNT_TR_CTRL1_CAPTURE_EDGE_Msk) |
                                        (((uint32_t)(config->reloadInputMode) << TCPWM_CNT_TR_CTRL1_RELOAD_EDGE_Pos) & TCPWM_CNT_TR_CTRL1_RELOAD_EDGE_Msk) |
                                        (((uint32_t)(config->startInputMode) << TCPWM_CNT_TR_CTRL1_START_EDGE_Pos) & TCPWM_CNT_TR_CTRL1_START_EDGE_Msk) |
                                        (((uint32_t)(config->stopInputMode) << TCPWM_CNT_TR_CTRL1_STOP_EDGE_Pos) & TCPWM_CNT_TR_CTRL1_STOP_EDGE_Msk) |
                                        (((uint32_t)(config->countInputMode) << TCPWM_CNT_TR_CTRL1_COUNT_EDGE_Pos) & TCPWM_CNT_TR_CTRL1_COUNT_EDGE_Msk);

        TCPWM_CNT_INTR_MASK(base, cntNum) = config->interruptSources;

}

void TCPWM_PWM_Init(TCPWM_Type *base, uint32_t cntNum,  cy_stc_tcpwm_pwm_config_t const *config)
{
        TCPWM_CNT_CTRL(base, cntNum) = ((config->enableCompareSwap ? TCPWM_CNT_CTRL_AUTO_RELOAD_CC_Msk : 0UL) |
                                      (config->enablePeriodSwap ? TCPWM_CNT_CTRL_AUTO_RELOAD_PERIOD_Msk : 0UL) |
                                      (((uint32_t)(config->runMode) << TCPWM_CNT_CTRL_ONE_SHOT_Pos) & TCPWM_CNT_CTRL_ONE_SHOT_Msk) |
                                      (((uint32_t)(config->pwmAlignment) << TCPWM_CNT_CTRL_UP_DOWN_MODE_Pos) & TCPWM_CNT_CTRL_UP_DOWN_MODE_Msk) |
                                      (((uint32_t)(config->pwmMode) << TCPWM_CNT_CTRL_MODE_Pos) & TCPWM_CNT_CTRL_MODE_Msk) |
                                      (((uint32_t)((config->invertPWMOut | (config->invertPWMOutN << 1U))) << TCPWM_CNT_CTRL_QUADRATURE_MODE_Pos) & TCPWM_CNT_CTRL_QUADRATURE_MODE_Msk) |
                                      (config->killMode << 2U) |
                                      (((uint32_t)(((5U == config->pwmMode) ? config->deadTimeClocks : config->clockPrescaler)) << TCPWM_CNT_CTRL_GENERIC_Pos) & TCPWM_CNT_CTRL_GENERIC_Msk));

        if (0U == config->pwmAlignment) //Left Align
        {
            TCPWM_CNT_COUNTER(base, cntNum) = 0U; //Up init
            TCPWM_CNT_TR_CTRL2(base, cntNum) = CY_TCPWM_PWM_MODE_LEFT;
        }
        else if (1U == config->pwmAlignment) //Right Align
        {
            TCPWM_CNT_COUNTER(base, cntNum) = config->period0;
            TCPWM_CNT_TR_CTRL2(base, cntNum) = CY_TCPWM_PWM_MODE_RIGHT;
        }
        else
        {
            TCPWM_CNT_COUNTER(base, cntNum) = 1U; //Up DOwn
            TCPWM_CNT_TR_CTRL2(base, cntNum) = CY_TCPWM_PWM_MODE_CNTR_OR_ASYMM;
        }

        TCPWM_CNT_CC(base, cntNum) = config->compare0;
        TCPWM_CNT_CC_BUFF(base, cntNum) = config->compare1;
        TCPWM_CNT_PERIOD(base, cntNum) = config->period0;
        TCPWM_CNT_PERIOD_BUFF(base, cntNum) = config->period1;

        TCPWM_CNT_TR_CTRL0(base, cntNum) = ((((uint32_t)(config->swapInput) << TCPWM_CNT_TR_CTRL0_CAPTURE_SEL_Pos) & TCPWM_CNT_TR_CTRL0_CAPTURE_SEL_Msk) |
                                        (((uint32_t)(config->reloadInput) << TCPWM_CNT_TR_CTRL0_RELOAD_SEL_Pos) & TCPWM_CNT_TR_CTRL0_RELOAD_SEL_Msk) |
                                        (((uint32_t)(config->startInput) << TCPWM_CNT_TR_CTRL0_START_SEL_Pos) & TCPWM_CNT_TR_CTRL0_START_SEL_Msk) |
                                        (((uint32_t)(config->killInput) << TCPWM_CNT_TR_CTRL0_STOP_SEL_Pos) & TCPWM_CNT_TR_CTRL0_STOP_SEL_Msk) |
                                        (((uint32_t)(config->countInput) << TCPWM_CNT_TR_CTRL0_COUNT_SEL_Pos) & TCPWM_CNT_TR_CTRL0_COUNT_SEL_Msk));

        TCPWM_CNT_TR_CTRL1(base, cntNum) = ((((uint32_t)(config->swapInputMode) << TCPWM_CNT_TR_CTRL1_CAPTURE_EDGE_Pos) & TCPWM_CNT_TR_CTRL1_CAPTURE_EDGE_Msk) |
                                        (((uint32_t)(config->reloadInputMode) << TCPWM_CNT_TR_CTRL1_RELOAD_EDGE_Pos) & TCPWM_CNT_TR_CTRL1_RELOAD_EDGE_Msk) |
                                        (((uint32_t)(config->startInputMode) << TCPWM_CNT_TR_CTRL1_START_EDGE_Pos) & TCPWM_CNT_TR_CTRL1_START_EDGE_Msk) |
                                        (((uint32_t)(config->killInputMode) << TCPWM_CNT_TR_CTRL1_STOP_EDGE_Pos) & TCPWM_CNT_TR_CTRL1_STOP_EDGE_Msk) |
                                        (((uint32_t)(config->countInputMode) << TCPWM_CNT_TR_CTRL1_COUNT_EDGE_Pos) & TCPWM_CNT_TR_CTRL1_COUNT_EDGE_Msk));

        TCPWM_CNT_INTR_MASK(base, cntNum) = config->interruptSources;
}


void TCPWM_Counter_Enable(TCPWM_Type *base, uint32_t cntNum)
{
    TCPWM_CTRL(base) |= (1UL << cntNum);
}

void TCPWM_SetInterrupt(TCPWM_Type *base, uint32_t cntNum,  uint32_t source)
{
    TCPWM_CNT_INTR_SET(base, cntNum) = source;
}

void TCPWM_Counter_SetPeriod(TCPWM_Type *base, uint32_t cntNum,  uint32_t period)
{
    TCPWM_CNT_PERIOD(base, cntNum) = period;
}

void TCPWM_TriggerStart(TCPWM_Type *base, uint32_t counters)
{
    TCPWM_CMD(base) = (uint32_t)(counters << TCPWM_CMD_COUNTER_START_Pos);
}

void TCPWM_TriggerReloadOrIndex(TCPWM_Type *base, uint32_t counters)
{
    TCPWM_CMD(base) = (uint32_t)(counters << TCPWM_CMD_COUNTER_RELOAD_Pos);
}

void TCPWM_ClearInterrupt(TCPWM_Type *base, uint32_t cntNum,  uint32_t source)
{
    TCPWM_CNT_INTR(base, cntNum) = source;
    (void)TCPWM_CNT_INTR(base, cntNum);
}

void TCPWM_PWM_SetCompare0(TCPWM_Type *base, uint32_t cntNum,  uint32_t compare0)
{
    TCPWM_CNT_CC(base, cntNum) = compare0;
}

void TCPWM_PWM_SetCompare1(TCPWM_Type *base, uint32_t cntNum,  uint32_t compare1)
{
    TCPWM_CNT_CC_BUFF(base, cntNum) = compare1;
}

//Counter
void TCPWM_Counter_SetCounter(TCPWM_Type *base, uint32_t cntNum, uint32_t count)
{
    TCPWM_CNT_COUNTER(base, cntNum) = count;
}

void TCPWM_TriggerStopOrKill(TCPWM_Type *base, uint32_t counters)
{
    TCPWM_CMD(base) = (uint32_t)(counters << TCPWM_CMD_COUNTER_STOP_Pos);
}

uint32_t TCPWM_Counter_GetCounter(TCPWM_Type const  *base, uint32_t cntNum)
{
    return(TCPWM_CNT_COUNTER(base, cntNum));
}