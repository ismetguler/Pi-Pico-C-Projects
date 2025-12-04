# Raspberry Pi Pico ile Gömülü Sistemler Yolculuğum 🚀

Bu depo (repository), **Raspberry Pi Pico** ve **C SDK** kullanarak sıfırdan ileri seviyeye kadar geliştirdiğim gömülü sistem projelerini içerir.

## 📂 Proje Listesi ve Kazanımlar

Bu yolculukta aşağıdaki teknik aşamalar tamamlanmıştır:

| No | Proje Klasörü | Konu & Kazanım |
| :--- | :--- | :--- |
| **01** | `01_Blink_LED` | **GPIO Output:** Dijital çıkış mantığı ve `sleep` fonksiyonları. |
| **02** | `02_Button_Control` | **GPIO Input:** Dijital giriş okuma, `Pull-Up` direnci ve `if-else` mantığı. |
| **03** | `03_PWM_Fade` | **PWM (Sinyal Modülasyonu):** Analog çıktı simülasyonu ile "Nefes Alan LED" efekti. |
| **04** | `04_Potentiometer_ADC` | **ADC (Analog Okuma):** Potansiyometre verisini okuyup 12-bit/Voltaj dönüşümü yapma. |
| **05** | `05_Serial_Telemetry` | **UART (Haberleşme):** `printf` ile bilgisayara (Serial Monitor) sensör verisi gönderme. |
| **06** | `06_I2C_LCD_Display` | **I2C Protokolü:** 16x2 LCD ekranı sürücü (driver) fonksiyonları ile kontrol etme. |
| **07** | `07_Digital_Voltmeter` | **Sensor Fusion:** ADC ve I2C'yi birleştirerek çalışan bir dijital voltmetre tasarımı. |
| **08** | `08_Reflex_Game_Interrupts` | **Interrupts (Kesmeler):** Donanım kesmeleri ile milisaniye hassasiyetinde refleks ölçümü. |

## 🛠️ Kullanılan Teknolojiler ve Donanımlar
* **Kart:** Raspberry Pi Pico (RP2040)
* **Dil:** C (Pico SDK)
* **Simülasyon:** Wokwi
* **Donanımlar:** LED, Push Button, Potansiyometre, LCD1602 (I2C Modüllü).
