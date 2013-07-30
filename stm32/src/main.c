#include "../stm32f10x_conf.h"

#include "rcc.h"
#include "uart_debug.h"
#include "led_debug.h"
#include "delay.h"
#include "motor.h"
#include "reed.h"


int main() {
    rcc_config();

    led_debug_config();
    motor_config();
    reed_config();
    
    led_blue_off();
    led_green_off();
    
    uint8_t i;
  
    while(1) {
        // forward
        motor_forward();
        led_blue_on();
        reed_delay_left();
        
        // stop
        motor_stop();
        led_blue_off();
        bigDelay();
        bigDelay();
        bigDelay();

        // backward
        motor_back();
        led_green_on();
        reed_delay_right();
        
        // stop
        motor_stop();
        led_green_off();
        bigDelay();
        bigDelay();
        bigDelay();
    }  

}

