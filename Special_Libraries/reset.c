#include "reset.h"
#include <stdint.h>

/*******************************************************************************
* Function Name: CySoftwareReset
****************************************************************************//**
*
*  Forces a software reset of the device.
*
*******************************************************************************/
void CySoftwareReset(void)
{
    /***************************************************************************
    * Setting the system reset request bit. The vector key value must be written
    * to the register, otherwise the register write is unpredictable.
    ***************************************************************************/

    CY_SYS_AIRCR_REG = (CY_SYS_AIRCR_REG & (uint32_t)(~CY_SYS_AIRCR_VECTKEY_MASK)) |
                            CY_SYS_AIRCR_VECTKEY | CY_SYS_AIRCR_SYSRESETREQ;
}

/*******************************************************************************
* Function Name: CySysGetResetReason
****************************************************************************//**
*
*  Reports the cause for the latest reset(s) that occurred in the system. All
*  the bits in the RES_CAUSE register assert when the corresponding reset cause
*  occurs and must be cleared by the firmware. These bits are cleared by the
*  hardware only during XRES, POR, or a detected brown-out.
*
*  \param reason: bits in the RES_CAUSE register to clear.
*   CY_SYS_RESET_WDT       - WDT caused a reset
*   CY_SYS_RESET_PROTFAULT - Occured protection violation that requires reset
*   CY_SYS_RESET_SW        - Cortex-M0 requested a system reset.
*
* \return
*  Status. Same enumerated bit values as used for the reason parameter.
*
*******************************************************************************/

uint32_t CySysGetResetReason(uint32_t reason)
{
    uint32_t returnStatus;

    reason &= (CY_SYS_RESET_WDT | CY_SYS_RESET_PROTFAULT | CY_SYS_RESET_SW);
    returnStatus = CY_SYS_RES_CAUSE_REG &
                  (CY_SYS_RESET_WDT | CY_SYS_RESET_PROTFAULT | CY_SYS_RESET_SW);
    CY_SYS_RES_CAUSE_REG = reason;

    return (returnStatus);
}
