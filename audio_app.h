#ifndef _AUDIO_APP_H_
#define _AUDIO_APP_H_

#include "tusb.h"

// Khai báo hàm task chính của ứng dụng
void audio_app_task(void);

// Hàm callback này được gọi khi một thiết bị âm thanh USB được gắn vào
void tuh_audio_mount_cb(uint8_t dev_addr, uint8_t instance, uint8_t const* desc_report, uint16_t len);

// Hàm callback này được gọi khi một thiết bị âm thanh USB bị gỡ ra
void tuh_audio_umount_cb(uint8_t dev_addr, uint8_t instance);

// Hàm callback này được gọi khi có dữ liệu âm thanh đến từ thiết bị
void tuh_audio_rx_cb(uint8_t dev_addr, uint8_t instance, uint8_t const* data, uint16_t len);

#endif
