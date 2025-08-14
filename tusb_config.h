#ifndef _TUSB_CONFIG_H_
#define _TUSB_CONFIG_H_

#ifdef __cplusplus
 extern "C" {
#endif

//--------------------------------------------------------------------+
// Common Configuration
//--------------------------------------------------------------------+

// Tùy chọn này phải được định nghĩa để bật TinyUSB
#define CFG_TUSB_ENABLED 1

// Bật chế độ Host để Pico có thể kết nối với thiết bị USB khác
#define CFG_TUH_ENABLED 1

// Bật Audio Class cho chế độ Host
#define CFG_TUH_AUDIO 1

//--------------------------------------------------------------------+
// Host Configuration
//--------------------------------------------------------------------+

// Số cổng Host trên Pico RP2040
#define CFG_TUH_RHPORT_COUNT 1

// Số thiết bị tối đa mà Host có thể quản lý
#define CFG_TUH_DEVICE_MAX 1

// Kích thước buffer cho control transfer (điều khiển)
#define CFG_TUH_ENUMERATION_BUFSIZE 256

//--------------------------------------------------------------------+
// Audio Class Driver Configuration (Host)
//--------------------------------------------------------------------+

// Số thiết bị Audio Class tối đa
#define CFG_TUH_AUDIO_MAX_DEV 1

#ifdef __cplusplus
 }
#endif

#endif