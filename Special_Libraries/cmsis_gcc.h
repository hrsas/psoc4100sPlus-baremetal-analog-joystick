#define CMSIS_GCC_H
#include <stdint.h>

/* Memory mapping of Core Hardware */
#define NVIC_BASE           (0xE000E100UL)                    /*!< NVIC Base Address */
#define NVIC                ((NVIC_Type      *)     NVIC_BASE     )   /*!< NVIC configuration struct */

#define _BIT_SHIFT(IRQn)         (((((uint32_t)(int32_t)(IRQn))) &  0x03UL) * 8UL)
#define _SHP_IDX(IRQn)           ((((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >> 2UL))
#define _IP_IDX(IRQn)            ((((uint32_t)(int32_t)(IRQn)) >> 2UL))

typedef void (* israddress)(void);   /**< Type of ISR callbacks */

typedef struct
{
  volatile uint32_t ISER;               /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
        uint32_t RESERVED0[31U];
  volatile uint32_t ICER;               /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
        uint32_t RESERVED1[31U];
  volatile uint32_t ISPR;               /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
        uint32_t RESERVED2[31U];
  volatile uint32_t ICPR;               /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
        uint32_t RESERVED3[31U];
        uint32_t RESERVED4[64U];
  volatile uint32_t IP[8U];                 /*!< Offset: 0x300 (R/W)  Interrupt Priority Register */
}  NVIC_Type;

void enable_irq(void);
void NVIC_EnableIRQ(uint32_t IRQn);
void NVIC_ClearPendingIRQ(uint32_t IRQn);
void NVIC_SetPriority(uint32_t IRQn, uint32_t priority);
void NVIC_DisableIRQ(uint32_t IRQn);
