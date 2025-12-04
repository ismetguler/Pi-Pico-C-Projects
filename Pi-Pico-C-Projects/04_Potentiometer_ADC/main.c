#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h" // PWM Kütüphanesi
#include "hardware/adc.h"
int main() {
  stdio_init_all();

  gpio_set_function(0, GPIO_FUNC_PWM);
  uint slice_num = pwm_gpio_to_slice_num(0);//Burası PWM AYARLARI
  pwm_set_enabled(slice_num, true);
  
  adc_init();
  adc_gpio_init(26);//gp26 pinini analog girişi
  adc_select_input(0);//adcnin 0. kanalı ADC0

  while(true){
    uint16_t okunanDeger=adc_read(); //DegeriOku
    uint16_t ledParlakligi=okunanDeger*16;

    pwm_set_gpio_level(0,ledParlakligi);
    sleep_ms(5);
    }
 }