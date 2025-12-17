#define RESET_H
#include <stdint.h>

#define CYREG_CM0P_AIRCR                0xe000ed0cu
#define CY_SYS_AIRCR_REG                (*(uint32_t *) CYREG_CM0P_AIRCR)
#define CY_SYS_AIRCR_VECTKEY_SHIFT      (16u)
#define CY_SYS_AIRCR_VECTKEY            ((uint32_t)((uint32_t)0x05FAu << CY_SYS_AIRCR_VECTKEY_SHIFT))
#define CY_SYS_AIRCR_VECTKEY_MASK       ((uint32_t)((uint32_t)0xFFFFu << CY_SYS_AIRCR_VECTKEY_SHIFT))
/* System Reset Request */
#define CY_SYS_AIRCR_SYSRESETREQ_SHIFT  (2u)
#define CY_SYS_AIRCR_SYSRESETREQ        ((uint32_t)((uint32_t)1u << CY_SYS_AIRCR_SYSRESETREQ_SHIFT))

#define CYREG_RES_CAUSE                 0x40030054u
#define CY_SYS_RES_CAUSE_REG            (*(uint32_t *) CYREG_RES_CAUSE)
/* CySysGetResetReason() */
#define CY_SYS_RESET_WDT_SHIFT          (0u)
#define CY_SYS_RESET_PROTFAULT_SHIFT    (3u)
#define CY_SYS_RESET_SW_SHIFT           (4u)

#define CY_SYS_RESET_WDT                ((uint32_t)1u << CY_SYS_RESET_WDT_SHIFT      )
#define CY_SYS_RESET_PROTFAULT          ((uint32_t)1u << CY_SYS_RESET_PROTFAULT_SHIFT)
#define CY_SYS_RESET_SW                 ((uint32_t)1u << CY_SYS_RESET_SW_SHIFT       )
void CySoftwareReset(void);
uint32_t CySysGetResetReason(uint32_t reason);