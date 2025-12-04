#include <stdio.h>
#include "pico/stdlib.h"

int main() {
  gpio_init(0);//0.pini uyandır.
  gpio_set_dir(0,GPIO_OUT);//pinin yönünü out yaptık

  gpio_init(1);//1.pini uyandır.
  gpio_set_dir(1,GPIO_IN);//pinin yönünü in yaptık buton
  gpio_pull_up(1);//direnç verdik 3.3V

  while(true){
    if(gpio_get(1)==0){//eğer ki butona basarsa gnd 0 olur yanar
      gpio_put(0,1);
      } 
    else{
      gpio_put(0,0);
    }
    }
 }