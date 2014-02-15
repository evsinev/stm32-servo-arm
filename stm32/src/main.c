#include "../stm32f10x_conf.h"

#include "rcc.h"
#include "uart_debug.h"
#include "led_debug.h"
#include "delay.h"
#include "motor.h"
#include "reed.h"

void bigDelay() {
  delay(100);
}

int reader_test() {
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

int window_fan() {
    rcc_config();
    delay_config();

    led_debug_config();
    motor_config();

    led_blue_off();
    led_green_off();

    servo_config();
    servo_set_pos(0);
    servo_start();

    u32 i;
    u32 from = 0;
    u32 to = 180;
    u32 delay = 2000;

  while(1) {

    motor_forward();

    led_blue_on();
    led_green_off();
    for(i=from; i<to; i++) {
        servo_set_pos(i);
        delay_ms(delay);
    }

    led_blue_off();
    led_green_on();
    for(i=to; i>from; i--) {
        servo_set_pos(i);
        delay_ms(delay);
    }

    motor_stop();
    delay_ms(10000);
  }
}

int main() {
  return window_fan();
}
