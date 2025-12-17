#include <stdint.h>
#define GPIO_H

/* following defines should be used for structure members */
#define     __IM     volatile const      /*! Defines 'read only' structure member permissions */
#define     __OM     volatile            /*! Defines 'write only' structure member permissions */
#define     __IOM    volatile            /*! Defines 'read / write' structure member permissions */

typedef struct {
  __IOM uint32_t DR;                            /*!< 0x00000000 Port output data register */
   __IM uint32_t PS;                            /*!< 0x00000004 Port IO pad state register */
  __IOM uint32_t PC;                            /*!< 0x00000008 Port configuration register */
  __IOM uint32_t INTR_CFG;                      /*!< 0x0000000C Port interrupt configuration register */
  __IOM uint32_t INTR;                          /*!< 0x00000010 Port interrupt status register */
  __IOM uint32_t SIO;                           /*!< 0x00000014 Port SIO configuration register */
  __IOM uint32_t PC2;                           /*!< 0x00000018 Port configuration register 2 */
   __IM uint32_t RESERVED[2];
  __IOM uint32_t MSC_ANA;                       /*!< 0x00000024 Port MSCLP AMUX enable */
   __IM uint32_t RESERVED1[6];
  __IOM uint32_t DR_SET;                        /*!< 0x00000040 Port output data set register */
  __IOM uint32_t DR_CLR;                        /*!< 0x00000044 Port output data clear register */
  __IOM uint32_t DR_INV;                        /*!< 0x00000048 Port output data invert register */
  __IOM uint32_t DS;                            /*!< 0x0000004C Port drive strength register */
  __IOM uint32_t FILT_CONFIG;                   /*!< 0x00000050 IO filter config register */
   __IM uint32_t RESERVED2[11];
  __IOM uint32_t VREFGEN;                       /*!< 0x00000080 Reference generator configuration register */
   __IM uint32_t RESERVED3[31];
} GPIO_PRT_Type;  
/** This structure is used to initialize a port of GPIO pins */
typedef struct
{
    uint32_t dr;             /**< Initial output data for the IO pins in the port */
    uint32_t intrCfg;        /**< Port pin interrupt edge detection configuration */
    uint32_t pc;             /**< Port pin drive modes configuration */
    uint32_t pc2;            /**< Port pin input buffer state configuration */
    uint32_t selActive;      /**< HSIOM selection for port pins*/
} cy_stc_gpio_prt_config_t;

typedef struct
{
    uint32_t outVal;         /**< Pin output state */
    uint32_t driveMode;      /**< Drive mode */
    uint32_t intEdge;        /**< Interrupt Edge type */
    uint32_t vtrip;          /**< Input buffer voltage trip type */
    uint32_t slewRate;       /**< Output buffer slew rate */
} cy_stc_gpio_pin_config_t;

typedef struct {
  __IOM uint32_t PORT_SEL;                      /*!< 0x00000000 Port selection register */
   __IM uint32_t RESERVED[63];
} HSIOM_PRT_Type;  

#define GPIO_PRT_OUT_CLR(base)             (((GPIO_PRT_Type*)(base))->DR_CLR)
#define GPIO_PRT_OUT_SET(base)             (((GPIO_PRT_Type*)(base))->DR_SET)
#define GPIO_PRT_OUT_INV(base)             (((GPIO_PRT_Type*)(base))->DR_INV)
#define GPIO_PRT_IN(base)                  (((GPIO_PRT_Type*)(base))->PS)

/* GPIO Masks */
#define CY_GPIO_HSIOM_MASK                     (0x0FUL)   /**< HSIOM selection mask */
#define CY_GPIO_DR_MASK                        (0x01UL)   /**< Single pin mask for DR register */
#define CY_GPIO_PS_MASK                        (0x01UL)   /**< Single pin mask for PS register */
#define CY_GPIO_PC_DM_MASK                     (0x07UL)   /**< Single pin mask for drive mode in PC register */
#define CY_GPIO_PC_DM_IBUF_MASK                (0x01UL)   /**< Single pin mask for input buffer state in PC2 register */
#define CY_GPIO_DM_VAL_IBUF_DISABLE_MASK       (0x08UL)   /**< The input buffer disable mask for the Pin Drive mode value */

/* Offsets */
#define CY_GPIO_HSIOM_OFFSET                   (2UL)      /**< Offset for HSIOM */
#define CY_GPIO_DRIVE_MODE_OFFSET              (3UL)      /**< Offset for Drive mode */

void GPIO_write(GPIO_PRT_Type* base, uint32_t pinNum, uint32_t value);

void GPIO_Set(GPIO_PRT_Type* base, uint32_t pinNum);

void GPIO_Clr(GPIO_PRT_Type* base, uint32_t pinNum);

void GPIO_Inv(GPIO_PRT_Type* base, uint32_t pinNum);

void gpio_init(GPIO_PRT_Type* base, const cy_stc_gpio_prt_config_t *config);

void GPIO_Pin_Init(GPIO_PRT_Type *base, uint32_t pinNum, const cy_stc_gpio_pin_config_t *config, uint8_t hsiom);

void GPIO_SetHSIOM(const GPIO_PRT_Type* base, uint32_t pinNum, uint8_t value);

void GPIO_SetDrivemode(GPIO_PRT_Type* base, uint32_t pinNum, uint32_t value);

uint32_t GPIO_Read(GPIO_PRT_Type* base, uint32_t pinNum);

void GPIO_SetInterruptEdge(GPIO_PRT_Type* base, uint32_t pinNum, uint32_t value);

void GPIO_SetVtrip(GPIO_PRT_Type* base, uint32_t value);

void GPIO_SetSlewRate(GPIO_PRT_Type* base, uint32_t value);

void GPIO_ClearInterrupt(GPIO_PRT_Type* base, uint32_t pinNum);
