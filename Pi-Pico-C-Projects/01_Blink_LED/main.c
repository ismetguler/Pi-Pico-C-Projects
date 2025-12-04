#include <stdio.h>
#include "pico/stdlib.h"

int main() {
  gpio_init(0);//0.pini uyandır.
  gpio_set_dir(0,GPIO_OUT);//pinin yönünü out yaptık

  while(true){
    gpio_put(0,1);//3.3V ver demek. (hangi pin,0 kapalı 1 açık).
    sleep_ms(500);
    
    gpio_put(0,0);
    sleep_ms(500);
    }
 }