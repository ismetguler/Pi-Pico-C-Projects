#include <stdio.h>
#include "pico/stdlib.h"

// --- YENİ PİNLERİMİZ ---
const uint LED_PIN = 16;    // GP16 (Sağ Alt Köşe)
const uint BTN_PIN = 17;    // GP17 (Onun Yanı)

volatile bool butona_basildi = false;
absolute_time_t baslangic_zamani;

// Zil Çalınca (Butona Basınca) Çalışacak Fonksiyon
void buton_kesmesi(uint gpio, uint32_t events) {
    absolute_time_t bitis_zamani = get_absolute_time();
    int64_t fark = absolute_time_diff_us(baslangic_zamani, bitis_zamani);

    // Ekrana sonucu bas
    printf("\n>>> REFLEKS SUREN: %lld milisaniye! <<<\n", fark / 1000);
    
    butona_basildi = true;
    gpio_put(LED_PIN, 0); // LED'i söndür
}

int main() {
    stdio_init_all();
    
    // --- KRİTİK NOKTA: BAĞLANTI BEKLEME ---
    sleep_ms(2500); // 2.5 saniye bekle ki USB otursun
    printf("--- SISTEM BASLATILDI ---\n");

    // 1. LED Ayarı (GP16)
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 0);

    // 2. Buton Ayarı (GP17)
    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);

    // 3. Interrupt Kurulumu
    gpio_set_irq_enabled_with_callback(BTN_PIN, GPIO_IRQ_EDGE_FALL, true, &buton_kesmesi);

    printf("Oyun Hazir! Bekle...\n");

    while (true) {
        // Rastgele bekleme (3 saniye)
        sleep_ms(3000); 

        printf("\n!!! LED YANDI! BAS !!!\n");
        
        // Zamanı başlat ve LED'i yak
        baslangic_zamani = get_absolute_time();
        gpio_put(LED_PIN, 1);
        butona_basildi = false;

        // Basılana kadar bekle
        while (!butona_basildi) {
            sleep_ms(10); 
        }

        printf("Tebrikler! 2 saniye sonra tekrar basliyor...\n");
        sleep_ms(2000);
    }
}