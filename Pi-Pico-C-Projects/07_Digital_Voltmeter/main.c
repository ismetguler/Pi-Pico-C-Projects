#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "pico/binary_info.h"
#include "hardware/adc.h"
// --- BURASI DRIVER KISMI ---
// LCD'nin standart adresi genelde 0x27'dir.
const int LCD_ADDR = 0x27;
// I2C Pinleri
const int SDA_PIN = 4;
const int SCL_PIN = 5;
void lcd_send_byte(uint8_t val, int mode) {
    uint8_t high = mode | (val & 0xF0) | 0x08;
    uint8_t low = mode | ((val << 4) & 0xF0) | 0x08;
    
    uint8_t buf[2];
    
    // High Nibble gönder
    buf[0] = high; 
    i2c_write_blocking(i2c0, LCD_ADDR, buf, 1, false);
    buf[0] = high | 0x04; // Enable Yak
    i2c_write_blocking(i2c0, LCD_ADDR, buf, 1, false);
    buf[0] = high & ~0x04; // Enable Söndür
    i2c_write_blocking(i2c0, LCD_ADDR, buf, 1, false);

    // Low Nibble gönder
    buf[0] = low;
    i2c_write_blocking(i2c0, LCD_ADDR, buf, 1, false);
    buf[0] = low | 0x04;
    i2c_write_blocking(i2c0, LCD_ADDR, buf, 1, false);
    buf[0] = low & ~0x04;
    i2c_write_blocking(i2c0, LCD_ADDR, buf, 1, false);
}
void lcd_init() {
    lcd_send_byte(0x03, 0);
    lcd_send_byte(0x03, 0);
    lcd_send_byte(0x03, 0);
    lcd_send_byte(0x02, 0);

    lcd_send_byte(0x28, 0); // 4-bit mode
    lcd_send_byte(0x0C, 0); // Ekranı Aç, İmleç Kapalı
    lcd_send_byte(0x01, 0); // Ekranı Temizle
    sleep_ms(2);
}
void lcd_clear() {
    lcd_send_byte(0x01, 0);
    sleep_ms(2);
}
void lcd_set_cursor(int line, int position) {
    int val = (line == 0) ? 0x80 + position : 0xC0 + position;
    lcd_send_byte(val, 0);
}
void lcd_print(const char *s) {
    while (*s) {
        lcd_send_byte(*s++, 1);
    }
}
// --- DRIVER KISMI BİTTİ ---

int main() {
    stdio_init_all(); // Haberleşmeyi aç

    //I2C başlatma i2c0 kanalını 100kHz başlat.
    i2c_init(i2c0,100*1000);
    //Pinleri I2C moduna al.
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    //Pull up dirençlerini açar 
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);
    lcd_init();
  // 2. ADC Başlat (Potansiyometre için)
    adc_init();
    adc_gpio_init(26); // GP26 pinini kullanacağız
    adc_select_input(0);

    //0.Satır 0. Sutun
    lcd_set_cursor(0,0);
    lcd_print("AKTIF");

    char mesajKutusu[16];



    while (true) {
      uint16_t ham_veri=adc_read();
      float voltaj=ham_veri*3.3f/4095;
      sprintf(mesajKutusu,"Volt: %.2f V", voltaj);
      lcd_set_cursor(1,0);
      lcd_print(mesajKutusu);
      sleep_ms(500); // Yarım saniye bekle
    }
}