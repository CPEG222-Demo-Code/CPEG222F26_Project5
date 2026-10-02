// ****************************************************************
// * Authors: T. LUM and R. MARTIN
// * CPEG222 Demo Program5, 9/28/2026
// * NucleoF446ZE CMSIS STM32F4xx example Proj5
// * Sends text to the OLED display using SPI
// ****************************************************************
#include "stm32f4xx.h"
#include "OLED.h"
#include <stdint.h>

void delay_ms(uint32_t ms);

int main(void){
    OLED_Init();
    SH1106_RenderFullScreenLogo();
    delay_ms(4000);
    OLED_Clear();
    OLED_Print(0, 0, "CPEG222-F26 OLED Test");
    OLED_Print(1, 0, "<demo date here>");
    OLED_Print(3, 0, "<your name here>");
    while(1){
        // Main loop
    }   
    return 0;// Program should never reach here due to infinite loop
}
void delay_ms(uint32_t ms){
    for(uint32_t i = 0; i < ms * 1000; i++){
        __NOP();
    }
}