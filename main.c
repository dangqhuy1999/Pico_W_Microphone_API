#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "tusb.h"

// Bao gồm file header audio của bạn
#include "audio_app.h"

// Thay đổi với thông tin Wi-Fi của bạn
#define WIFI_SSID "WIFI_SSID"
#define WIFI_PASSWORD "WIFI_PASSWORD"

int main() {
    stdio_init_all();
    printf("TinyUSB Host Audio over Wi-Fi Example\r\n");

    // Khởi tạo Wi-Fi
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed\n");
        return 1;
    }
    printf("Wi-Fi initialized successfully.\n");
    cyw43_arch_enable_sta_mode();

    // Kết nối Wi-Fi
    if (cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASSWORD, CYW43_AUTH_WPA2_AES_PSK, 30000)) {
        printf("Wi-Fi failed to connect!\n");
        return 1;
    } else {
        printf("Wi-Fi connected successfully\n");
    }

    // Khởi tạo TinyUSB Host
    // Thay thế BOARD_TUH_RHPORT bằng 0 vì RP2040 chỉ có 1 host port
    tuh_init(0);
    printf("TinyUSB Host initialized successfully.\n");

    while (1) {
        // Chạy tác vụ chính của TinyUSB
        tuh_task();

        // Chạy tác vụ của ứng dụng audio (nếu có)
        audio_app_task();
    }

    return 0;
}
