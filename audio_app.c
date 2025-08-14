#include <stdio.h>
#include "audio_app.h"

// Hàm callback này được gọi khi một thiết bị âm thanh USB được gắn vào
void tuh_audio_mount_cb(uint8_t dev_addr, uint8_t instance, uint8_t const* desc_report, uint16_t len) {
  (void)desc_report;
  (void)len;
  
  printf("A USB audio device is mounted, address = %d, instance = %d\n", dev_addr, instance);
}

// Hàm callback này được gọi khi một thiết bị âm thanh USB bị gỡ ra
void tuh_audio_umount_cb(uint8_t dev_addr, uint8_t instance) {
  (void)instance;
  
  printf("A USB audio device is unmounted, address = %d\n", dev_addr);
}

// Hàm callback này được gọi khi có dữ liệu âm thanh đến từ thiết bị
void tuh_audio_rx_cb(uint8_t dev_addr, uint8_t instance, uint8_t const* data, uint16_t len) {
  (void)dev_addr;
  (void)instance;
  
  // Ở đây bạn có thể xử lý dữ liệu âm thanh đến (data)
  // Ví dụ: lưu vào bộ nhớ, xử lý, hoặc gửi qua mạng.
  printf("Received audio data: len = %d\n", len);
}

void audio_app_task(void) {
    // Add your application logic here
}
