#include <stdint.h>
#include <stdbool.h>
#define TIMER_H

/* following defines should be used for structure members */
#define     __IM     volatile const      /*! Defines 'read only' structure member permissions */
#define     __OM     volatile            /*! Defines 'write only' structure member permissions */
#define     __IOM    volatile            /*! Defines 'read / write' structure member permissions */

#define _VAL2FLD(field, value)    (((uint32_t)(value) << field ## _Pos) & field ## _Msk)
#define _FLD2VAL(field, value)    (((uint32_t)(value) & field ## _Msk) >> field ## _Pos)
#define _CLR_SET_FLD32U(reg, field, value) (((reg) & ((uint32_t)(~(field ## _Msk)))) | (_VAL2FLD(field, value)))
#define CY_REG32_CLR_SET(reg, field, value) ((reg) = _CLR_SET_FLD32U((reg), field, (value)))

typedef struct {
  __IOM uint32_t CTRL;                          /*!< 0x00000000 Counter control register */
   __IM uint32_t STATUS;                        /*!< 0x00000004 Counter status register */
  __IOM uint32_t COUNTER;                       /*!< 0x00000008 Counter count register */
  __IOM uint32_t CC;                            /*!< 0x0000000C Counter compare/capture register */
  __IOM uint32_t CC_BUFF;                       /*!< 0x00000010 Counter buffered compare/capture register */
  __IOM uint32_t PERIOD;                        /*!< 0x00000014 Counter period register */
  __IOM uint32_t PERIOD_BUFF;                   /*!< 0x00000018 Counter buffered period register */
   __IM uint32_t RESERVED;
  __IOM uint32_t TR_CTRL0;                      /*!< 0x00000020 Counter trigger control register 0 */
  __IOM uint32_t TR_CTRL1;                      /*!< 0x00000024 Counter trigger control register 1 */
  __IOM uint32_t TR_CTRL2;                      /*!< 0x00000028 Counter trigger control register 2 */
   __IM uint32_t RESERVED1;
  __IOM uint32_t INTR;                          /*!< 0x00000030 Interrupt request register. */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000034 Interrupt set request register. */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000038 Interrupt mask register. */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000003C Interrupt masked request register */
} TCPWM_CNT_Type;   

typedef struct {
  __IOM uint32_t CTRL;                          /*!< 0x00000000 TCPWM control register 0. */
   __IM uint32_t RESERVED;
  __IOM uint32_t CMD;                           /*!< 0x00000008 TCPWM command register. */
   __IM uint32_t INTR_CAUSE;                    /*!< 0x0000000C TCPWM Counter interrupt cause register. */
   __IM uint32_t RESERVED1[60];
        TCPWM_CNT_Type CNT[8];                  /*!< 0x00000100 Timer/Counter/PWM Counter Module */
} TCPWM_Type;   


#define TCPWM_BASE                              0x40200000UL
#define TCPWM                                   ((TCPWM_Type*) TCPWM_BASE)                                        /* 0x40200000 */
#define TCPWM_CNT0                              ((TCPWM_CNT_Type*) &TCPWM->CNT[0])                                /* 0x40200100 */
#define TCPWM_CNT1                              ((TCPWM_CNT_Type*) &TCPWM->CNT[1])                                /* 0x40200140 */
#define TCPWM_CNT2                              ((TCPWM_CNT_Type*) &TCPWM->CNT[2])                                /* 0x40200180 */
#define TCPWM_CNT3                              ((TCPWM_CNT_Type*) &TCPWM->CNT[3])                                /* 0x402001C0 */
#define TCPWM_CNT4                              ((TCPWM_CNT_Type*) &TCPWM->CNT[4])                                /* 0x40200200 */
#define TCPWM_CNT5                              ((TCPWM_CNT_Type*) &TCPWM->CNT[5])                                /* 0x40200240 */
#define TCPWM_CNT6                              ((TCPWM_CNT_Type*) &TCPWM->CNT[6])                                /* 0x40200280 */
#define TCPWM_CNT7                              ((TCPWM_CNT_Type*) &TCPWM->CNT[7])                                /* 0x402002C0 */

#define CY_TCPWM_INT_NONE               (0U) /**< No Interrupt */
#define CY_TCPWM_INT_ON_TC              (1U) /**< Interrupt on Terminal count(TC) */
#define CY_TCPWM_INT_ON_CC              (2U) /**< Interrupt on Compare/Capture(CC) */
#define CY_TCPWM_INT_ON_CC_OR_TC        (3U) /**< Interrupt on TC or CC */

/*******************************************************************************
*                TCPWM
*******************************************************************************/

//#define TCPWM_CTRL(base)                (((TCPWM_Type *)(base))->CTRL)
//#define TCPWM_CMD(base)                 (((TCPWM_Type *)(base))->CMD)

#define TCPWM_CNT_CTRL(base, cntNum)         (((TCPWM_Type *)(base))->CNT[cntNum].CTRL)
#define TCPWM_CNT_CC(base, cntNum)           (((TCPWM_Type *)(base))->CNT[cntNum].CC)
#define TCPWM_CNT_CC_BUFF(base, cntNum)      (((TCPWM_Type *)(base))->CNT[cntNum].CC_BUFF)
#define TCPWM_CNT_COUNTER(base, cntNum)      (((TCPWM_Type *)(base))->CNT[cntNum].COUNTER)
#define TCPWM_CNT_PERIOD(base, cntNum)       (((TCPWM_Type *)(base))->CNT[cntNum].PERIOD)
#define TCPWM_CNT_PERIOD_BUFF(base, cntNum)  (((TCPWM_Type *)(base))->CNT[cntNum].PERIOD_BUFF)
#define TCPWM_CNT_STATUS(base, cntNum)       (((TCPWM_Type *)(base))->CNT[cntNum].STATUS)
#define TCPWM_CNT_INTR(base, cntNum)         (((TCPWM_Type *)(base))->CNT[cntNum].INTR)
#define TCPWM_CNT_INTR_SET(base, cntNum)     (((TCPWM_Type *)(base))->CNT[cntNum].INTR_SET)
#define TCPWM_CNT_INTR_MASK(base, cntNum)    (((TCPWM_Type *)(base))->CNT[cntNum].INTR_MASK)
#define TCPWM_CNT_INTR_MASKED(base, cntNum)  (((TCPWM_Type *)(base))->CNT[cntNum].INTR_MASKED)
#define TCPWM_CNT_TR_CTRL0(base, cntNum)     (((TCPWM_Type *)(base))->CNT[cntNum].TR_CTRL0)
#define TCPWM_CNT_TR_CTRL1(base, cntNum)     (((TCPWM_Type *)(base))->CNT[cntNum].TR_CTRL1)
#define TCPWM_CNT_TR_CTRL2(base, cntNum)     (((TCPWM_Type *)(base))->CNT[cntNum].TR_CTRL2)


/* TCPWM_CNT.CTRL */
#define TCPWM_CNT_CTRL_AUTO_RELOAD_CC_Pos       0UL
#define TCPWM_CNT_CTRL_AUTO_RELOAD_CC_Msk       0x1UL
#define TCPWM_CNT_CTRL_AUTO_RELOAD_PERIOD_Pos   1UL
#define TCPWM_CNT_CTRL_AUTO_RELOAD_PERIOD_Msk   0x2UL
#define TCPWM_CNT_CTRL_PWM_SYNC_KILL_Pos        2UL
#define TCPWM_CNT_CTRL_PWM_SYNC_KILL_Msk        0x4UL
#define TCPWM_CNT_CTRL_PWM_STOP_ON_KILL_Pos     3UL
#define TCPWM_CNT_CTRL_PWM_STOP_ON_KILL_Msk     0x8UL
#define TCPWM_CNT_CTRL_GENERIC_Pos              8UL
#define TCPWM_CNT_CTRL_GENERIC_Msk              0xFF00UL
#define TCPWM_CNT_CTRL_UP_DOWN_MODE_Pos         16UL
#define TCPWM_CNT_CTRL_UP_DOWN_MODE_Msk         0x30000UL
#define TCPWM_CNT_CTRL_ONE_SHOT_Pos             18UL
#define TCPWM_CNT_CTRL_ONE_SHOT_Msk             0x40000UL
#define TCPWM_CNT_CTRL_QUADRATURE_MODE_Pos      20UL
#define TCPWM_CNT_CTRL_QUADRATURE_MODE_Msk      0x300000UL
#define TCPWM_CNT_CTRL_MODE_Pos                 24UL
#define TCPWM_CNT_CTRL_MODE_Msk                 0x7000000UL
/* TCPWM_CNT.STATUS */
#define TCPWM_CNT_STATUS_DOWN_Pos               0UL
#define TCPWM_CNT_STATUS_DOWN_Msk               0x1UL
#define TCPWM_CNT_STATUS_GENERIC_Pos            8UL
#define TCPWM_CNT_STATUS_GENERIC_Msk            0xFF00UL
#define TCPWM_CNT_STATUS_RUNNING_Pos            31UL
#define TCPWM_CNT_STATUS_RUNNING_Msk            0x80000000UL
/* TCPWM_CNT.COUNTER */
#define TCPWM_CNT_COUNTER_COUNTER_Pos           0UL
#define TCPWM_CNT_COUNTER_COUNTER_Msk           0xFFFFUL
/* TCPWM_CNT.CC */
#define TCPWM_CNT_CC_CC_Pos                     0UL
#define TCPWM_CNT_CC_CC_Msk                     0xFFFFUL
/* TCPWM_CNT.CC_BUFF */
#define TCPWM_CNT_CC_BUFF_CC_Pos                0UL
#define TCPWM_CNT_CC_BUFF_CC_Msk                0xFFFFUL
/* TCPWM_CNT.PERIOD */
#define TCPWM_CNT_PERIOD_PERIOD_Pos             0UL
#define TCPWM_CNT_PERIOD_PERIOD_Msk             0xFFFFUL
/* TCPWM_CNT.PERIOD_BUFF */
#define TCPWM_CNT_PERIOD_BUFF_PERIOD_Pos        0UL
#define TCPWM_CNT_PERIOD_BUFF_PERIOD_Msk        0xFFFFUL
/* TCPWM_CNT.TR_CTRL0 */
#define TCPWM_CNT_TR_CTRL0_CAPTURE_SEL_Pos      0UL
#define TCPWM_CNT_TR_CTRL0_CAPTURE_SEL_Msk      0xFUL
#define TCPWM_CNT_TR_CTRL0_COUNT_SEL_Pos        4UL
#define TCPWM_CNT_TR_CTRL0_COUNT_SEL_Msk        0xF0UL
#define TCPWM_CNT_TR_CTRL0_RELOAD_SEL_Pos       8UL
#define TCPWM_CNT_TR_CTRL0_RELOAD_SEL_Msk       0xF00UL
#define TCPWM_CNT_TR_CTRL0_STOP_SEL_Pos         12UL
#define TCPWM_CNT_TR_CTRL0_STOP_SEL_Msk         0xF000UL
#define TCPWM_CNT_TR_CTRL0_START_SEL_Pos        16UL
#define TCPWM_CNT_TR_CTRL0_START_SEL_Msk        0xF0000UL
/* TCPWM_CNT.TR_CTRL1 */
#define TCPWM_CNT_TR_CTRL1_CAPTURE_EDGE_Pos     0UL
#define TCPWM_CNT_TR_CTRL1_CAPTURE_EDGE_Msk     0x3UL
#define TCPWM_CNT_TR_CTRL1_COUNT_EDGE_Pos       2UL
#define TCPWM_CNT_TR_CTRL1_COUNT_EDGE_Msk       0xCUL
#define TCPWM_CNT_TR_CTRL1_RELOAD_EDGE_Pos      4UL
#define TCPWM_CNT_TR_CTRL1_RELOAD_EDGE_Msk      0x30UL
#define TCPWM_CNT_TR_CTRL1_STOP_EDGE_Pos        6UL
#define TCPWM_CNT_TR_CTRL1_STOP_EDGE_Msk        0xC0UL
#define TCPWM_CNT_TR_CTRL1_START_EDGE_Pos       8UL
#define TCPWM_CNT_TR_CTRL1_START_EDGE_Msk       0x300UL
/* TCPWM_CNT.TR_CTRL2 */
#define TCPWM_CNT_TR_CTRL2_CC_MATCH_MODE_Pos    0UL
#define TCPWM_CNT_TR_CTRL2_CC_MATCH_MODE_Msk    0x3UL
#define TCPWM_CNT_TR_CTRL2_OVERFLOW_MODE_Pos    2UL
#define TCPWM_CNT_TR_CTRL2_OVERFLOW_MODE_Msk    0xCUL
#define TCPWM_CNT_TR_CTRL2_UNDERFLOW_MODE_Pos   4UL
#define TCPWM_CNT_TR_CTRL2_UNDERFLOW_MODE_Msk   0x30UL
/* TCPWM_CNT.INTR */
#define TCPWM_CNT_INTR_TC_Pos                   0UL
#define TCPWM_CNT_INTR_TC_Msk                   0x1UL
#define TCPWM_CNT_INTR_CC_MATCH_Pos             1UL
#define TCPWM_CNT_INTR_CC_MATCH_Msk             0x2UL
/* TCPWM_CNT.INTR_SET */
#define TCPWM_CNT_INTR_SET_TC_Pos               0UL
#define TCPWM_CNT_INTR_SET_TC_Msk               0x1UL
#define TCPWM_CNT_INTR_SET_CC_MATCH_Pos         1UL
#define TCPWM_CNT_INTR_SET_CC_MATCH_Msk         0x2UL
/* TCPWM_CNT.INTR_MASK */
#define TCPWM_CNT_INTR_MASK_TC_Pos              0UL
#define TCPWM_CNT_INTR_MASK_TC_Msk              0x1UL
#define TCPWM_CNT_INTR_MASK_CC_MATCH_Pos        1UL
#define TCPWM_CNT_INTR_MASK_CC_MATCH_Msk        0x2UL
/* TCPWM_CNT.INTR_MASKED */
#define TCPWM_CNT_INTR_MASKED_TC_Pos            0UL
#define TCPWM_CNT_INTR_MASKED_TC_Msk            0x1UL
#define TCPWM_CNT_INTR_MASKED_CC_MATCH_Pos      1UL
#define TCPWM_CNT_INTR_MASKED_CC_MATCH_Msk      0x2UL

/* TCPWM.CTRL */
#define TCPWM_CTRL_COUNTER_ENABLED_Pos          0UL
#define TCPWM_CTRL_COUNTER_ENABLED_Msk          0xFFUL
/* TCPWM.CMD */
#define TCPWM_CMD_COUNTER_CAPTURE_Pos           0UL
#define TCPWM_CMD_COUNTER_CAPTURE_Msk           0xFFUL
#define TCPWM_CMD_COUNTER_RELOAD_Pos            8UL
#define TCPWM_CMD_COUNTER_RELOAD_Msk            0xFF00UL
#define TCPWM_CMD_COUNTER_STOP_Pos              16UL
#define TCPWM_CMD_COUNTER_STOP_Msk              0xFF0000UL
#define TCPWM_CMD_COUNTER_START_Pos             24UL
#define TCPWM_CMD_COUNTER_START_Msk             0xFF000000UL
/* TCPWM.INTR_CAUSE */
#define TCPWM_INTR_CAUSE_COUNTER_INT_Pos        0UL
#define TCPWM_INTR_CAUSE_COUNTER_INT_Msk        0xFFUL



//PWM
#define CY_TCPWM_PWM_TR_CTRL2_SET           (0UL) /**< Set define for PWM output signal configuration */
#define CY_TCPWM_PWM_TR_CTRL2_CLEAR         (1UL) /**< Clear define for PWM output signal configuration */
#define CY_TCPWM_PWM_TR_CTRL2_INVERT        (2UL) /**< Invert define for PWM output signal configuration */
#define CY_TCPWM_PWM_TR_CTRL2_NO_CHANGE     (3UL) /**< No change define for PWM output signal configuration */

/** The configuration of PWM output signal in Pseudo Random Mode */
#define CY_TCPWM_PWM_MODE_PR         ((((uint32_t)(CY_TCPWM_PWM_TR_CTRL2_NO_CHANGE) << TCPWM_CNT_TR_CTRL2_CC_MATCH_MODE_Pos) & TCPWM_CNT_TR_CTRL2_CC_MATCH_MODE_Msk) | (((uint32_t)(CY_TCPWM_PWM_TR_CTRL2_NO_CHANGE) << TCPWM_CNT_TR_CTRL2_OVERFLOW_MODE_Pos) & TCPWM_CNT_TR_CTRL2_OVERFLOW_MODE_Msk) | (((uint32_t)(CY_TCPWM_PWM_TR_CTRL2_NO_CHANGE) << TCPWM_CNT_TR_CTRL2_UNDERFLOW_MODE_Pos) & TCPWM_CNT_TR_CTRL2_UNDERFLOW_MODE_Msk))

/** The configuration of PWM output signal for Left alignment */
#define CY_TCPWM_PWM_MODE_LEFT       ((((uint32_t)(CY_TCPWM_PWM_TR_CTRL2_CLEAR) << TCPWM_CNT_TR_CTRL2_CC_MATCH_MODE_Pos) & TCPWM_CNT_TR_CTRL2_CC_MATCH_MODE_Msk) | (((uint32_t)(CY_TCPWM_PWM_TR_CTRL2_SET) << TCPWM_CNT_TR_CTRL2_OVERFLOW_MODE_Pos) & TCPWM_CNT_TR_CTRL2_OVERFLOW_MODE_Msk) | (((uint32_t)(CY_TCPWM_PWM_TR_CTRL2_NO_CHANGE) << TCPWM_CNT_TR_CTRL2_UNDERFLOW_MODE_Pos) & TCPWM_CNT_TR_CTRL2_UNDERFLOW_MODE_Msk))

/** The configuration of PWM output signal for Right alignment */
#define CY_TCPWM_PWM_MODE_RIGHT     ((((uint32_t)(CY_TCPWM_PWM_TR_CTRL2_SET) << TCPWM_CNT_TR_CTRL2_CC_MATCH_MODE_Pos) & TCPWM_CNT_TR_CTRL2_CC_MATCH_MODE_Msk) | (((uint32_t)(CY_TCPWM_PWM_TR_CTRL2_NO_CHANGE) << TCPWM_CNT_TR_CTRL2_OVERFLOW_MODE_Pos) & TCPWM_CNT_TR_CTRL2_OVERFLOW_MODE_Msk) | (((uint32_t)(CY_TCPWM_PWM_TR_CTRL2_CLEAR) << TCPWM_CNT_TR_CTRL2_UNDERFLOW_MODE_Pos) & TCPWM_CNT_TR_CTRL2_UNDERFLOW_MODE_Msk))

/** The configuration of PWM output signal for Center and Asymmetric alignment */
#define CY_TCPWM_PWM_MODE_CNTR_OR_ASYMM   ((((uint32_t)(CY_TCPWM_PWM_TR_CTRL2_INVERT) << TCPWM_CNT_TR_CTRL2_CC_MATCH_MODE_Pos) & TCPWM_CNT_TR_CTRL2_CC_MATCH_MODE_Msk) | (((uint32_t)(CY_TCPWM_PWM_TR_CTRL2_SET) << TCPWM_CNT_TR_CTRL2_OVERFLOW_MODE_Pos) & TCPWM_CNT_TR_CTRL2_OVERFLOW_MODE_Msk) | (((uint32_t)(CY_TCPWM_PWM_TR_CTRL2_CLEAR) << TCPWM_CNT_TR_CTRL2_UNDERFLOW_MODE_Pos) & TCPWM_CNT_TR_CTRL2_UNDERFLOW_MODE_Msk))



/** Counter Timer configuration structure */
typedef struct cy_stc_tcpwm_counter_config
{
    uint32_t    period;             /**< Sets the period of the counter */
    /** Sets the clock prescaler inside the TCWPM block. See \ref group_tcpwm_counter_clk_prescalers */
    uint32_t    clockPrescaler;
    uint32_t    runMode;            /**< Sets the run mode. See \ref group_tcpwm_counter_run_modes */
    uint32_t    countDirection;     /**< Sets the counter direction. See \ref group_tcpwm_counter_direction */
    /** The counter can either compare or capture a value. See \ref group_tcpwm_counter_compare_capture */
    uint32_t    compareOrCapture;
    uint32_t    compare0;           /**< Sets the value for Compare0*/
    uint32_t    compare1;           /**< Sets the value for Compare1*/
    bool        enableCompareSwap;  /**< If enabled, the compare values are swapped each time the comparison is true */
    /** Enabled an interrupt on the terminal count, capture or compare. See \ref group_tcpwm_interrupt_sources */
    uint32_t    interruptSources;
    uint32_t    captureInputMode;   /**< Configures how the capture input behaves. See \ref group_tcpwm_input_modes */
    /** Selects which input the capture uses, the inputs are device-specific. See \ref group_tcpwm_input_selection */
    uint32_t    captureInput;
    uint32_t    reloadInputMode;    /**< Configures how the reload input behaves. See \ref group_tcpwm_input_modes */
    /** Selects which input the reload uses, the inputs are device-specific. See \ref group_tcpwm_input_selection */
    uint32_t    reloadInput;
    uint32_t    startInputMode;     /**< Configures how the start input behaves. See \ref group_tcpwm_input_modes */
    /** Selects which input the start uses, the inputs are device-specific. See \ref group_tcpwm_input_selection */
    uint32_t    startInput;
    uint32_t    stopInputMode;      /**< Configures how the stop input behaves. See \ref group_tcpwm_input_modes */
    /** Selects which input the stop uses, the inputs are device-specific. See \ref group_tcpwm_input_selection */
    uint32_t    stopInput;
    uint32_t    countInputMode;     /**< Configures how the count input behaves. See \ref group_tcpwm_input_modes */
    /** Selects which input the count uses, the inputs are device-specific. See \ref group_tcpwm_input_selection */
    uint32_t    countInput;
}cy_stc_tcpwm_counter_config_t;

typedef struct cy_stc_tcpwm_pwm_config
{
    uint32_t    pwmMode;            /**< Sets the PWM mode. See \ref group_tcpwm_pwm_modes */
    /** Sets the clock prescaler inside the TCWPM block. See \ref group_tcpwm_pwm_clk_prescalers */
    uint32_t     clockPrescaler;
    uint32_t    pwmAlignment;       /**< Sets the PWM alignment. See \ref group_tcpwm_pwm_alignment */
    uint32_t    deadTimeClocks;     /**< The number of dead time-clocks if PWM with dead time is chosen */
    uint32_t    runMode;            /**< Sets the PWM run mode. See \ref group_tcpwm_pwm_run_modes */
    uint32_t    period0;            /**< Sets the period0 of the pwm */
    uint32_t    period1;            /**< Sets the period1 of the pwm */
    bool        enablePeriodSwap;   /**< Enables swapping of period 0 and period 1 on terminal count */
    uint32_t    compare0;           /**< Sets the value for Compare0 */
    uint32_t    compare1;           /**< Sets the value for Compare1 */
    bool        enableCompareSwap;  /**< If enabled, the compare values are swapped on the terminal count */
    /** Enables an interrupt on the terminal count, capture or compare. See \ref group_tcpwm_interrupt_sources */
    uint32_t    interruptSources;
    /** Inverts the PWM output. This field also defines the state of the PWM output while PWM is enabled, but not running. */
    uint32_t    invertPWMOut;
    /** Inverts the PWM_n output. This field also defines the state of the PWM_n output while PWM is enabled, but not running. */
    uint32_t    invertPWMOutN;
    uint32_t    killMode;           /**< Configures the PWM kill modes. See \ref group_tcpwm_pwm_kill_modes */
    uint32_t    swapInputMode;      /**< Configures how the swap input behaves. See \ref group_tcpwm_input_modes */
    /** Selects which input the swap uses. Inputs are device-specific. See \ref group_tcpwm_input_selection */
    uint32_t    swapInput;
    uint32_t    reloadInputMode;    /**< Configures how the reload input behaves. See \ref group_tcpwm_input_modes */
    /** Selects which input the reload uses. The inputs are device-specific. See \ref group_tcpwm_input_selection */
    uint32_t    reloadInput;
    uint32_t    startInputMode;     /**< Configures how the start input behaves. See \ref group_tcpwm_input_modes */
    /** Selects which input the start uses. The inputs are device-specific. See \ref group_tcpwm_input_selection */
    uint32_t    startInput;
    uint32_t    killInputMode;      /**< Configures how the kill input behaves. See \ref group_tcpwm_input_modes */
    /** Selects which input the kill uses. The inputs are device-specific. See \ref group_tcpwm_input_selection */
    uint32_t    killInput;
    uint32_t    countInputMode;     /**< Configures how the count input behaves. See \ref group_tcpwm_input_modes */
    /** Selects which input the count uses. The inputs are device-specific. See \ref group_tcpwm_input_selection */
    uint32_t    countInput;
}cy_stc_tcpwm_pwm_config_t;



//TIMER FUNCTIONS
void TCPWM_Counter_Enable(TCPWM_Type *base, uint32_t cntNum);
void TCPWM_Counter_Init(TCPWM_Type *base, uint32_t cntNum, cy_stc_tcpwm_counter_config_t const *config);
void TCPWM_SetInterrupt(TCPWM_Type *base, uint32_t cntNum,  uint32_t source);
void TCPWM_Counter_SetPeriod(TCPWM_Type *base, uint32_t cntNum,  uint32_t period);
void TCPWM_TriggerStart(TCPWM_Type *base, uint32_t counters);
void TCPWM_ClearInterrupt(TCPWM_Type *base, uint32_t cntNum,  uint32_t source);

void TCPWM_Counter_SetCounter(TCPWM_Type *base, uint32_t cntNum, uint32_t count);
void TCPWM_TriggerStopOrKill(TCPWM_Type *base, uint32_t counters);
uint32_t TCPWM_Counter_GetCounter(TCPWM_Type const  *base, uint32_t cntNum);

//PWM FUNCTIONS
void TCPWM_PWM_Init(TCPWM_Type *base, uint32_t cntNum,  cy_stc_tcpwm_pwm_config_t const *config);
void TCPWM_TriggerReloadOrIndex(TCPWM_Type *base, uint32_t counters);
void TCPWM_PWM_SetCompare0(TCPWM_Type *base, uint32_t cntNum,  uint32_t compare0);
void TCPWM_PWM_SetCompare1(TCPWM_Type *base, uint32_t cntNum,  uint32_t compare1);