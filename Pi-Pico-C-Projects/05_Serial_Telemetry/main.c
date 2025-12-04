#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

int main() {
    stdio_init_all(); // Haberleşmeyi aç

    adc_init(); // ADC'yi aç
    adc_gpio_init(26); // GP26 pinini analog yap
    adc_select_input(0); // 0. kanalı (GP26) seç

    printf("Sistem Baslatiliyor...\n");
    sleep_ms(1000);
    printf("Roket Hazir!\n");

    while (true) {
        uint16_t ham_veri = adc_read(); // Oku
        
        // Voltaj hesabı: (Okunan / 4095) * 3.3V
        float voltaj = ham_veri * 3.3f / 4095;

        // Ekrana yazdır
        printf("Sensor: %d  -  Voltaj: %.2f V\n", ham_veri, voltaj);

        sleep_ms(500); // Yarım saniye bekle
    }
}