#include "../stm32f10x_conf.h"


#include "uart_debug.h"
#include "led_debug.h"


int main() {
    led_debug_config();
    uart_debug_config();
    
    //led_blue_on();

    RCC_ClocksTypeDef Sys_RCC_Clocks;
    RCC_GetClocksFreq(&Sys_RCC_Clocks);

    debugf("SYSCLK_Frequency : %d Hz\n", Sys_RCC_Clocks.SYSCLK_Frequency);
    debugf("HCLK_Frequency   : %d Hz\n", Sys_RCC_Clocks.HCLK_Frequency);
    debugf("PCLK1_Frequency  : %d Hz\n", Sys_RCC_Clocks.PCLK1_Frequency);
    debugf("PCLK2_Frequency  : %d Hz\n", Sys_RCC_Clocks.PCLK2_Frequency);
    debugf("ADCCLK_Frequency : %d Hz\n", Sys_RCC_Clocks.ADCCLK_Frequency);

    while(1) {
    }
}

