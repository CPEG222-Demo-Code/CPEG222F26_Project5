// ****************************************************************
// * Authors: T. LUM and R. MARTIN
// * CPEG222 Demo Program5, 9/28/2026
// * NucleoF446ZE CMSIS STM32F4xx example Proj5
// * Sends text to the OLED display using SPI
// ****************************************************************
#include "stm32f4xx.h"
#include "OLED.h"
#include "SysClock180MHz.h"
#include <stdint.h> // Include stdint.h for uint32_t type
#include <stdio.h> // Include stdio.h for snprintf function

void delay_ms(uint32_t ms); // Function prototype for delay function
char buffer[90];

int main(void){
    OLED_Init();
    SH1106_RenderFullScreenLogo();
    delay_ms(4000); // Delay for 4 seconds to display the logo
    OLED_Clear();
    OLED_Print(0, 0, "CPEG222-F26 OLED Test");
    SystemCoreClockUpdate(); // CMSIS function to update SystemCoreClock variable
    snprintf(buffer, sizeof(buffer), "Intial Clock: %u MHz  ", SystemCoreClock / 1000000U);               
    OLED_Print(5, 0, buffer);
    SystemClock_Config(); // Configure the system clock to 180 MHz
    SystemCoreClockUpdate(); // Update SystemCoreClock variable after clock change
    snprintf(buffer, sizeof(buffer), "Final Clock: %u MHz  ", SystemCoreClock / 1000000U);
    OLED_Print(6, 0, buffer);
    delay_ms(8000); // Delay for 8 seconds to display the clock information
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
    if(SystemCoreClock == 16000000U){
        for(uint32_t i = 0; i < ms * 2000; i++){
            __NOP();
        }
    } else if(SystemCoreClock == 180000000U){
        for(uint32_t i = 0; i < ms * 22500; i++){
            __NOP();
        }
    }
}