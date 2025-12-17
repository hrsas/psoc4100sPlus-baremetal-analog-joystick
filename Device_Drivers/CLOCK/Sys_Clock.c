#include <stdint.h>
#include "Sys_Clock.h"

void SysClk_PeriphDisableDivider(cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum)
{
        /* specify the divider and disable it */
        PERI_DIV_CMD = PERI_DIV_CMD_DISABLE_Msk            |
              (((uint32_t)(dividerType) << PERI_DIV_CMD_SEL_TYPE_Pos) & PERI_DIV_CMD_SEL_TYPE_Msk) |
              (((uint32_t)(dividerNum) << PERI_DIV_CMD_SEL_DIV_Pos) & PERI_DIV_CMD_SEL_DIV_Msk);
}

void SysClk_PeriphSetDivider(cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum, uint32_t dividerValue)
{
        dividerType = dividerType;
        PERI_DIV_16_CTL[dividerNum] =  ((((PERI_DIV_16_CTL[dividerNum])) & 
                                        ((uint32_t)(~(PERI_DIV_16_CTL_INT16_DIV_Msk)))) | 
                                        ((((uint32_t)(dividerValue) << PERI_DIV_16_CTL_INT16_DIV_Pos) & 
                                        PERI_DIV_16_CTL_INT16_DIV_Msk)));

}

void SysClk_PeriphEnableDivider(cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum)
{
        /* specify the divider, make the reference = clk_peri, and enable the divider */
        PERI_DIV_CMD = PERI_DIV_CMD_ENABLE_Msk             |
                       PERI_DIV_CMD_PA_SEL_TYPE_Msk        |
                       PERI_DIV_CMD_PA_SEL_DIV_Msk         |
              (((uint32_t)(dividerType) << PERI_DIV_CMD_SEL_TYPE_Pos) & PERI_DIV_CMD_SEL_TYPE_Msk) |
              (((uint32_t)(dividerNum) << PERI_DIV_CMD_SEL_DIV_Pos) & PERI_DIV_CMD_SEL_DIV_Msk);
        
        (void)PERI_DIV_CMD; /* dummy read to handle buffered writes */
}

void SysClk_PeriphAssignDivider(en_clk_dst_t periphNum, cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum)
{

        PERI_PCLK_CTL[periphNum] = (((uint32_t)(dividerType) << PERI_PCLK_CTL_SEL_TYPE_Pos) & PERI_PCLK_CTL_SEL_TYPE_Msk) | (((uint32_t)(dividerNum) << PERI_PCLK_CTL_SEL_DIV_Pos) & PERI_PCLK_CTL_SEL_DIV_Msk);
}

void Cy_SysClk_ClkHfSetDivider(uint8_t divider)
{
        CY_REG32_CLR_SET(SRSSLT_CLK_SELECT, SRSSLT_CLK_SELECT_HFCLK_DIV, divider);
}

void Cy_SysClk_ImoEnable(void)
{
   SRSSLT_CLK_IMO_CONFIG = SRSSLT_CLK_IMO_CONFIG_ENABLE_Msk;
}

uint32_t Cy_SysClk_ImoGetFrequency(void)
{
    return ((((((uint32_t)(SRSSLT_CLK_IMO_SELECT) & SRSSLT_CLK_IMO_SELECT_FREQ_Msk) >> SRSSLT_CLK_IMO_SELECT_FREQ_Pos) << 2UL) * 1000000UL) + (uint32_t)24000000UL);
}

void Cy_SysClk_ImoSetFrequency(cy_en_sysclk_imo_freq_t freq)
{

        if ((uint32_t) freq != Cy_SysClk_ImoGetFrequency())
        {
        /* Convert the frequency value in Hz into the SFLASH.IMO_TRIM register index */
        uint32_t locFreq = ((uint32_t)freq - (uint32_t)24000000UL) / 1000000UL;

        /* Set IMO to 24 MHz */
        SRSSLT_CLK_IMO_SELECT = 0UL;

        /* Apply coarse trim */
        SRSSLT_CLK_IMO_TRIM1 = SFLASH_IMO_TRIM_LT(locFreq);

        /* Zero out fine trim */
        SRSSLT_CLK_IMO_TRIM2 = 0UL;

        /* Apply TC trim */
        SRSSLT_CLK_IMO_TRIM3 = SFLASH_IMO_TCTRIM_LT(locFreq);

        /* Convert the SFLASH.IMO_TRIM register index into the frequency bitfield value */
        locFreq >>= 2UL;

        for(int i=0; i<50000; i++); //short delay

        if (0UL != locFreq)
        {
                /* Select nearby intermediate frequency */
                CY_REG32_CLR_SET(SRSSLT_CLK_IMO_SELECT, SRSSLT_CLK_IMO_SELECT_FREQ, locFreq - 1UL);
                for(int i=0; i<50000; i++); //short delay
                CY_REG32_CLR_SET(SRSSLT_CLK_IMO_SELECT, SRSSLT_CLK_IMO_SELECT_FREQ, locFreq);
        }
        }

}