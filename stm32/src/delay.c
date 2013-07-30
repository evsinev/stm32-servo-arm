#include "delay.h"
#include "../stm32f10x_conf.h"

// Функция задержки
void delay() {
  volatile uint32_t i;
  for (i=1; i != 0xFFFF; i++)
    ;
 }

void bigDelay() {
  for (int i=1; i != 40; i++) {
    delay();
  }
}


