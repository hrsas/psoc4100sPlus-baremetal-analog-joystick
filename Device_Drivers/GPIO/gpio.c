#include <stdint.h>
#include "gpio.h"

void GPIO_write(GPIO_PRT_Type* base, uint32_t pinNum, uint32_t value)
{
    /* Thread-safe: Directly access the pin registers instead of base->OUT */
    if(0UL == value)
    {
        GPIO_PRT_OUT_CLR(base) = CY_GPIO_DR_MASK << pinNum;
    }
    else
    {
        GPIO_PRT_OUT_SET(base) = CY_GPIO_DR_MASK << pinNum;
    }
}

uint32_t GPIO_Read(GPIO_PRT_Type* base, uint32_t pinNum)
{
    return (GPIO_PRT_IN(base) >> (pinNum)) & CY_GPIO_PS_MASK;
}


void GPIO_Set(GPIO_PRT_Type* base, uint32_t pinNum)
{

    GPIO_PRT_OUT_SET(base) = CY_GPIO_DR_MASK << pinNum;
}

void GPIO_Clr(GPIO_PRT_Type* base, uint32_t pinNum)
{
    GPIO_PRT_OUT_CLR(base) = CY_GPIO_DR_MASK << pinNum;
}

void GPIO_Inv(GPIO_PRT_Type* base, uint32_t pinNum)
{

    GPIO_PRT_OUT_INV(base) = CY_GPIO_DR_MASK << pinNum;
}

void gpio_init(GPIO_PRT_Type* base, const cy_stc_gpio_prt_config_t *config)
{
        uint32_t portNum;
        HSIOM_PRT_Type* baseHSIOM;

        portNum = ((uint32_t)(base) - 0x40040000UL) / 0x00000100UL;
        baseHSIOM = (HSIOM_PRT_Type*)(0x40020000UL + (0x00000100UL * portNum));

        (((GPIO_PRT_Type*)(base))->DR)              = config->dr;
        (((GPIO_PRT_Type*)(base))->PC)             = config->pc;
        (((GPIO_PRT_Type*)(base))->PC2)             = config->pc2;
        (((HSIOM_PRT_Type *)(baseHSIOM))->PORT_SEL)  = config->selActive;
}

void GPIO_Pin_Init(GPIO_PRT_Type *base, uint32_t pinNum, const cy_stc_gpio_pin_config_t *config, uint8_t hsiom)
{
        GPIO_write(base, pinNum, config->outVal);
        GPIO_SetDrivemode(base, pinNum, config->driveMode);
        GPIO_SetHSIOM(base, pinNum, hsiom);

        GPIO_SetInterruptEdge(base, pinNum, config->intEdge);
        GPIO_SetVtrip(base, config->vtrip);
        GPIO_SetSlewRate(base, config->slewRate);
}

void GPIO_SetHSIOM(const GPIO_PRT_Type* base, uint32_t pinNum, uint8_t value)
{
    uint32_t portNum;
    uint32_t tempReg;
    HSIOM_PRT_Type* portAddrHSIOM;

    portNum = ((uint32_t)(base) - 0x40040000UL) / 0x00000100UL;
    portAddrHSIOM = (HSIOM_PRT_Type*)(0x40020000UL + (0x00000100UL * portNum));

    tempReg = (((HSIOM_PRT_Type *)(portAddrHSIOM))->PORT_SEL) & ~(CY_GPIO_HSIOM_MASK << (pinNum << CY_GPIO_HSIOM_OFFSET));
    (((HSIOM_PRT_Type *)(portAddrHSIOM))->PORT_SEL) = tempReg | (( (uint32_t) value & CY_GPIO_HSIOM_MASK) << (pinNum << CY_GPIO_HSIOM_OFFSET));
}

void GPIO_SetDrivemode(GPIO_PRT_Type* base, uint32_t pinNum, uint32_t value)
{
    uint32_t tempReg;
    uint32_t pinLoc;

    pinLoc = pinNum * CY_GPIO_DRIVE_MODE_OFFSET;
    tempReg = ((((GPIO_PRT_Type*)(base))->PC) & ~(CY_GPIO_PC_DM_MASK << pinLoc));
    (((GPIO_PRT_Type*)(base))->PC) = tempReg | ((value & CY_GPIO_PC_DM_MASK) << pinLoc);

    tempReg = ((((GPIO_PRT_Type*)(base))->PC2) & ~(CY_GPIO_PC_DM_IBUF_MASK << pinNum));
    (((GPIO_PRT_Type*)(base))->PC2) = tempReg | (((value & CY_GPIO_DM_VAL_IBUF_DISABLE_MASK) >> CY_GPIO_DRIVE_MODE_OFFSET) << pinNum);
}

void GPIO_SetInterruptEdge(GPIO_PRT_Type* base, uint32_t pinNum, uint32_t value)
{
    uint32_t tempReg;
    uint32_t pinLoc;

    pinLoc = pinNum << 0x1u;
    tempReg = (((GPIO_PRT_Type*)(base))->INTR_CFG) & ~(0x3u << pinLoc);
    (((GPIO_PRT_Type*)(base))->INTR_CFG) = tempReg | ((value & 0x3u) << pinLoc);
}

void GPIO_SetVtrip(GPIO_PRT_Type* base, uint32_t value)
{
    uint32_t tempReg;

    tempReg = (((GPIO_PRT_Type*)(base))->PC) & ~(0x1u << 24u);
    (((GPIO_PRT_Type*)(base))->PC) = tempReg | ((value & 0x1u) << 24);

}

void GPIO_SetSlewRate(GPIO_PRT_Type* base, uint32_t value)
{
    uint32_t tempReg;

    tempReg = (((GPIO_PRT_Type*)(base))->PC) & ~(0x1u << 25u);
    (((GPIO_PRT_Type*)(base))->PC) = tempReg | ((value & 0x1u) << 25);

}

void GPIO_ClearInterrupt(GPIO_PRT_Type* base, uint32_t pinNum)
{
    /* Any INTR MMIO registers AHB clearing must be preceded with an AHB read access */
    (void)(((GPIO_PRT_Type*)(base))->INTR);

    (((GPIO_PRT_Type*)(base))->INTR) = (0x01UL) << pinNum;

    /* This read ensures that the initial write has been flushed out to the hardware */
    (void)(((GPIO_PRT_Type*)(base))->INTR);
}


