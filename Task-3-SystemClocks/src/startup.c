#include "startup.h"

uint32_t SystemInit() {
    RCC_DeInit();
    RCC_HSEConfig(RCC_HSE_ON);
    while ( (RCC->CR & RCC_CR_PLLRDY) == 0 ) {
        __NOP();
    }
    RCC_PLLConfig(RCC_PLLSource_HSE, 8, 336, 4, 7);
    RCC_PLLCmd(ENABLE);

    RCC_WaitForPLLSturtUp();

    RCC_HCLKConfig(RCC_SYSCLK_Div4);
    RCC_PCLK1Config(RCC_HCLK_Div1);
    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

    return ENABLE;
}
