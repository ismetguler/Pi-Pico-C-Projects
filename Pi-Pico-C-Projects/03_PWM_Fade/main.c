#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h" // PWM Kütüphanesi
int main() {
  
  gpio_set_function(0,GPIO_FUNC_PWM);// GP0 pinini PWM moduna alıyoruz.
  uint slice_num=pwm_gpio_to_slice_num(0);
  pwm_set_enabled(slice_num,true);

  int parlaklik=0;
  int degisim=500;
  while(true){
    pwm_set_gpio_level(0,parlaklik);

    parlaklik=parlaklik+degisim;
      //Eğer parlaklık tepeye çıktıya veya en aşağı indiyse tersine çevir.
      if(parlaklik>=65000 || parlaklik<=0){
      degisim=degisim*-1;//Yön değiştir.    
    }
    //Biraz bekletmek için.
    sleep_ms(5);
    }
 }