#include "../stm32f10x_conf.h"

#include "rcc.h"
#include "uart_debug.h"
#include "led_debug.h"
#include "delay.h"
#include "motor.h"


int main() {
    rcc_config();

    led_debug_config();
    motor_config();
    
    led_blue_off();
    led_green_off();
    
    uint8_t i;
  
    while(1) {
        // forward
        motor_forward();
        led_blue_on();
        bigDelay();
        
        // stop
        motor_stop();
        led_blue_off();
        bigDelay();

        // backward
        motor_back();
        led_green_on();
        bigDelay();
        
        // stop
        motor_stop();
        led_green_off();
        bigDelay();
    }  

}

