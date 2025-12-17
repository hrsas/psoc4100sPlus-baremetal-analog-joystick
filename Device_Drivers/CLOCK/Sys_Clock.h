#include <stdint.h>
#define SYS_CLOCK_H

/* following defines should be used for structure members */
#define     __IM     volatile const      /*! Defines 'read only' structure member permissions */
#define     __OM     volatile            /*! Defines 'write only' structure member permissions */
#define     __IOM    volatile            /*! Defines 'read / write' structure member permissions */

#define PERI_BASE                               0x40010000UL
#define PERI                                    ((PERI_Type*) PERI_BASE)   
#define SRSSLT_BASE                             0x40030000UL
#define SRSSLT                                  ((SRSSLT_Type*) SRSSLT_BASE)                                      /* 0x40030000 */

#define SFLASH_BASE                             0x0FFFF000UL
#define SFLASH                                  ((SFLASH_Type*) SFLASH_BASE)                                      /* 0x0FFFF000 */

#define _VAL2FLD(field, value)    (((uint32_t)(value) << field ## _Pos) & field ## _Msk)
#define _FLD2VAL(field, value)    (((uint32_t)(value) & field ## _Msk) >> field ## _Pos)

#define _CLR_SET_FLD32U(reg, field, value) (((reg) & ((uint32_t)(~(field ## _Msk)))) | (_VAL2FLD(field, value)))
#define CY_REG32_CLR_SET(reg, field, value) ((reg) = _CLR_SET_FLD32U((reg), field, (value)))


/** IMO frequencies */
typedef enum
{
    CY_SYSCLK_IMO_24MHZ = 24000000UL, /**< 24 MHz */
    CY_SYSCLK_IMO_28MHZ = 28000000UL, /**< 28 MHz */
    CY_SYSCLK_IMO_32MHZ = 32000000UL, /**< 32 MHz */
    CY_SYSCLK_IMO_36MHZ = 36000000UL, /**< 36 MHz */
    CY_SYSCLK_IMO_40MHZ = 40000000UL, /**< 40 MHz */
    CY_SYSCLK_IMO_44MHZ = 44000000UL, /**< 44 MHz */
    CY_SYSCLK_IMO_48MHZ = 48000000UL  /**< 48 MHz */
} cy_en_sysclk_imo_freq_t;

typedef enum
{
    CY_SYSCLK_DIV_8_BIT    = 0U, /**< Divider Type is an 8 bit integer divider. Note the divider of this type may be absent on some devices */
    CY_SYSCLK_DIV_16_BIT   = 1U, /**< Divider Type is a 16 bit integer divider. Note the divider of this type may be absent on some devices */
    CY_SYSCLK_DIV_16_5_BIT = 2U, /**< Divider Type is a 16.5 bit fractional divider. Note the divider of this type may be absent on some devices */
    CY_SYSCLK_DIV_24_5_BIT = 3U  /**< Divider Type is a 24.5 bit fractional divider. Note the divider of this type may be absent on some devices */
} cy_en_sysclk_divider_types_t;

/* PERI.DIV_CMD */
#define PERI_DIV_CMD_SEL_DIV_Pos                0UL
#define PERI_DIV_CMD_SEL_DIV_Msk                0x3FUL
#define PERI_DIV_CMD_SEL_TYPE_Pos               6UL
#define PERI_DIV_CMD_SEL_TYPE_Msk               0xC0UL
#define PERI_DIV_CMD_PA_SEL_DIV_Pos             8UL
#define PERI_DIV_CMD_PA_SEL_DIV_Msk             0x3F00UL
#define PERI_DIV_CMD_PA_SEL_TYPE_Pos            14UL
#define PERI_DIV_CMD_PA_SEL_TYPE_Msk            0xC000UL
#define PERI_DIV_CMD_DISABLE_Pos                30UL
#define PERI_DIV_CMD_DISABLE_Msk                0x40000000UL
#define PERI_DIV_CMD_ENABLE_Pos                 31UL
#define PERI_DIV_CMD_ENABLE_Msk                 0x80000000UL

#define PERI_DIV_16_CTL_INT16_DIV_Msk           0xFFFF00UL
#define PERI_DIV_16_CTL_INT16_DIV_Pos           8UL
#define PERI_PCLK_CTL_SEL_TYPE_Pos              6UL
#define PERI_PCLK_CTL_SEL_TYPE_Msk              0xC0UL
#define PERI_PCLK_CTL_SEL_DIV_Pos               0UL
#define PERI_PCLK_CTL_SEL_DIV_Msk               0x3FUL


typedef struct {
  __IOM uint32_t TR_OUT_CTL[128];               /*!< 0x00000000 Trigger control register */
} PERI_TR_GROUP_Type;   

typedef struct {
  __IOM uint32_t DIV_CMD;                       /*!< 0x00000000 Divider command register */
   __IM uint32_t RESERVED[63];
  __IOM uint32_t PCLK_CTL[64];                  /*!< 0x00000100 Programmable clock control register */
  __IOM uint32_t DIV_8_CTL[64];                 /*!< 0x00000200 Divider control register (for 8.0 divider) */
  __IOM uint32_t DIV_16_CTL[64];                /*!< 0x00000300 Divider control register (for 16.0 divider) */
  __IOM uint32_t DIV_16_5_CTL[64];              /*!< 0x00000400 Divider control register (for 16.5 divider) */
  __IOM uint32_t DIV_24_5_CTL[63];              /*!< 0x00000500 Divider control register (for 24.5 divider) */
   __IM uint32_t RESERVED1;
  __IOM uint32_t TR_CTL;                        /*!< 0x00000600 Trigger control register */
   __IM uint32_t RESERVED2[1663];
        PERI_TR_GROUP_Type TR_GROUP[16];        /*!< 0x00002000 Peripheral Interconnect trigger group control registers */
} PERI_Type;  


#define PERI_DIV_CMD                        (((PERI_Type *) PERI)->DIV_CMD)
#define PERI_PCLK_CTL                       (((PERI_Type *) PERI)->PCLK_CTL)
#define PERI_DIV_8_CTL                      (((PERI_Type *) PERI)->DIV_8_CTL)
#define PERI_DIV_16_CTL                     (((PERI_Type *) PERI)->DIV_16_CTL)
#define PERI_DIV_16_5_CTL                   (((PERI_Type *) PERI)->DIV_16_5_CTL)
#define PERI_DIV_24_5_CTL                   (((PERI_Type *) PERI)->DIV_24_5_CTL)

/* Clock Connections */
typedef enum
{
    PCLK_SCB0_CLOCK                 = 0x0000u,  /* scb[0].clock */
    PCLK_SCB1_CLOCK                 = 0x0001u,  /* scb[1].clock */
    PCLK_SCB2_CLOCK                 = 0x0002u,  /* scb[2].clock */
    PCLK_SCB3_CLOCK                 = 0x0003u,  /* scb[3].clock */
    PCLK_SCB4_CLOCK                 = 0x0004u,  /* scb[4].clock */
    PCLK_CSD_CLOCK                  = 0x0005u,  /* csd.clock */
    PCLK_TCPWM_CLOCKS0              = 0x0006u,  /* tcpwm.clocks[0] */
    PCLK_TCPWM_CLOCKS1              = 0x0007u,  /* tcpwm.clocks[1] */
    PCLK_TCPWM_CLOCKS2              = 0x0008u,  /* tcpwm.clocks[2] */
    PCLK_TCPWM_CLOCKS3              = 0x0009u,  /* tcpwm.clocks[3] */
    PCLK_TCPWM_CLOCKS4              = 0x000Au,  /* tcpwm.clocks[4] */
    PCLK_TCPWM_CLOCKS5              = 0x000Bu,  /* tcpwm.clocks[5] */
    PCLK_TCPWM_CLOCKS6              = 0x000Cu,  /* tcpwm.clocks[6] */
    PCLK_TCPWM_CLOCKS7              = 0x000Du,  /* tcpwm.clocks[7] */
    PCLK_PRGIO_CLOCK_PRGIO_1        = 0x000Eu,  /* prgio.clock_prgio_1 */
    PCLK_PRGIO_CLOCK_PRGIO_2        = 0x000Fu,  /* prgio.clock_prgio_2 */
    PCLK_PRGIO_CLOCK_PRGIO_3        = 0x0010u,  /* prgio.clock_prgio_3 */
    PCLK_LCD_CLOCK                  = 0x0011u,  /* lcd.clock */
    PCLK_PASS0_CLOCK_SAR            = 0x0012u   /* pass[0].clock_sar */
} en_clk_dst_t;

typedef struct {
  __IOM uint32_t PWR_CONTROL;                   /*!< 0x00000000 Power Mode Control */
  __IOM uint32_t PWR_KEY_DELAY;                 /*!< 0x00000004 Power System Key&Delay Register */
   __IM uint32_t RESERVED;
  __IOM uint32_t PWR_DDFT_SELECT;               /*!< 0x0000000C Power DDFT Mode Selection Register */
   __IM uint32_t RESERVED1;
  __IOM uint32_t TST_MODE;                      /*!< 0x00000014 Test Mode Control Register */
   __IM uint32_t RESERVED2[4];
  __IOM uint32_t CLK_SELECT;                    /*!< 0x00000028 Clock Select Register */
  __IOM uint32_t CLK_ILO_CONFIG;                /*!< 0x0000002C ILO Configuration */
  __IOM uint32_t CLK_IMO_CONFIG;                /*!< 0x00000030 IMO Configuration */
  __IOM uint32_t CLK_DFT_SELECT;                /*!< 0x00000034 Clock DFT Mode Selection Register */
  __IOM uint32_t WDT_DISABLE_KEY;               /*!< 0x00000038 Watchdog Disable Key Register */
   __IM uint32_t WDT_COUNTER;                   /*!< 0x0000003C Watchdog Counter Register */
  __IOM uint32_t WDT_MATCH;                     /*!< 0x00000040 Watchdog Match Register */
  __IOM uint32_t SRSS_INTR;                     /*!< 0x00000044 SRSS Interrupt Register */
  __IOM uint32_t SRSS_INTR_SET;                 /*!< 0x00000048 SRSS Interrupt Set Register */
  __IOM uint32_t SRSS_INTR_MASK;                /*!< 0x0000004C SRSS Interrupt Mask Register */
   __IM uint32_t RESERVED3;
  __IOM uint32_t RES_CAUSE;                     /*!< 0x00000054 Reset Cause Observation Register */
   __IM uint32_t RESERVED4[940];
  __IOM uint32_t CLK_IMO_SELECT;                /*!< 0x00000F08 IMO Frequency Select Register */
  __IOM uint32_t CLK_IMO_TRIM1;                 /*!< 0x00000F0C IMO Trim Register */
  __IOM uint32_t CLK_IMO_TRIM2;                 /*!< 0x00000F10 IMO Trim Register */
  __IOM uint32_t PWR_PWRSYS_TRIM1;              /*!< 0x00000F14 Power System Trim Register */
  __IOM uint32_t CLK_IMO_TRIM3;                 /*!< 0x00000F18 IMO Trim Register */
} SRSSLT_Type;   


#define SRSSLT_CLK_SELECT                   (((SRSSLT_Type *) SRSSLT)->CLK_SELECT)
#define SRSSLT_CLK_IMO_CONFIG               (((SRSSLT_Type *) SRSSLT)->CLK_IMO_CONFIG)
#define SRSSLT_CLK_IMO_SELECT               (((SRSSLT_Type *) SRSSLT)->CLK_IMO_SELECT)
#define SRSSLT_CLK_IMO_TRIM1                (((SRSSLT_Type *) SRSSLT)->CLK_IMO_TRIM1)
#define SRSSLT_CLK_IMO_TRIM2                (((SRSSLT_Type *) SRSSLT)->CLK_IMO_TRIM2)
#define SRSSLT_CLK_IMO_TRIM3                (((SRSSLT_Type *) SRSSLT)->CLK_IMO_TRIM3)
#define SRSSLT_CLK_SELECT_HFCLK_DIV_Pos         2UL
#define SRSSLT_CLK_SELECT_HFCLK_DIV_Msk         0xCUL
#define SRSSLT_CLK_IMO_CONFIG_ENABLE_Pos        31UL
#define SRSSLT_CLK_IMO_CONFIG_ENABLE_Msk        0x80000000UL
#define SRSSLT_CLK_IMO_SELECT_FREQ_Pos          0UL
#define SRSSLT_CLK_IMO_SELECT_FREQ_Msk          0x7UL

typedef struct {
   __IM uint32_t RESERVED[53];
  __IOM uint8_t  CSDV2_CSD1_ADC_TRIM1;          /*!< 0x000000D4 CSDV2 CSD1 ADC TRIM 1 */
  __IOM uint8_t  CSDV2_CSD1_ADC_TRIM2;          /*!< 0x000000D5 CSDV2 CSD1 ADC TRIM2 */
   __IM uint16_t RESERVED1[55];
  __IOM uint32_t SILICON_ID;                    /*!< 0x00000144 Silicon ID */
   __IM uint32_t RESERVED2[2];
  __IOM uint16_t HIB_KEY_DELAY;                 /*!< 0x00000150 Hibernate wakeup value for PWR_KEY_DELAY */
  __IOM uint16_t DPSLP_KEY_DELAY;               /*!< 0x00000152 DeepSleep wakeup value for PWR_KEY_DELAY */
   __IM uint32_t RESERVED3;
  __IOM uint32_t SWD_LISTEN;                    /*!< 0x00000158 Listen Window Length */
  __IOM uint32_t FLASH_START;                   /*!< 0x0000015C Flash Image Start Address */
  __IOM uint8_t  CSDV2_CSD0_ADC_TRIM1;          /*!< 0x00000160 CSDV2 CSD0 ADC TRIM 1 */
  __IOM uint8_t  CSDV2_CSD0_ADC_TRIM2;          /*!< 0x00000161 CSDV2 CSD0 ADC TRIM2 */
   __IM uint16_t RESERVED4;
  __IOM uint16_t SAR_TEMP_MULTIPLIER;           /*!< 0x00000164 SAR Temperature Sensor Multiplication Factor */
  __IOM uint16_t SAR_TEMP_OFFSET;               /*!< 0x00000166 SAR Temperature Sensor Offset */
   __IM uint16_t RESERVED5[43];
  __IOM uint8_t  IMO_TRIM_USBMODE_24;           /*!< 0x000001BE USB IMO TRIM 24MHz */
  __IOM uint8_t  IMO_TRIM_USBMODE_48;           /*!< 0x000001BF USB IMO TRIM 48MHz */
   __IM uint32_t RESERVED6[3];
  __IOM uint8_t  IMO_TCTRIM_LT[25];             /*!< 0x000001CC IMO TempCo Trim Register (SRSS-Lite) */
  __IOM uint8_t  IMO_TRIM_LT[25];               /*!< 0x000001E5 IMO Frequency Trim Register (SRSS-Lite) */
} SFLASH_Type; 


#define SFLASH_SILICON_ID                   (((SFLASH_Type *) SFLASH)->SILICON_ID)
#define SFLASH_DPSLP_KEY_DELAY              (((SFLASH_Type *) SFLASH)->DPSLP_KEY_DELAY)

#define SFLASH_IMO_TRIM_LT(freq)            ((uint32_t)(((SFLASH_Type *) SFLASH)->IMO_TRIM_LT[(freq)]))
#define SFLASH_IMO_TCTRIM_LT(freq)          ((uint32_t)(((SFLASH_Type *) SFLASH)->IMO_TCTRIM_LT[(freq)]))
#define SFLASH_IMO_STEPSIZE_LT(freq)        ((uint32_t)(((SFLASH_Type *) SFLASH)->IMO_STEPSIZE_LT[(freq)]))

void Cy_SysClk_ClkHfSetDivider(uint8_t divider);
void Cy_SysClk_ImoSetFrequency(cy_en_sysclk_imo_freq_t freq);
uint32_t Cy_SysClk_ImoGetFrequency(void);
void Cy_SysClk_ImoEnable(void);

void SysClk_PeriphDisableDivider(cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum);
void SysClk_PeriphSetDivider(cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum, uint32_t dividerValue);
void SysClk_PeriphEnableDivider(cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum);
void SysClk_PeriphAssignDivider(en_clk_dst_t periphNum, cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum);


