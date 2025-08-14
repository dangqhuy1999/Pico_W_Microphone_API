cmake_minimum_required(VERSION 3.13)

# Đặt loại bo mạch là Pico W
set(PICO_BOARD pico_w)

# Bao gồm các file cấu hình từ Pico SDK.
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(pico_api_microphone_project C CXX ASM)

# Tiêu chuẩn ngôn ngữ C và C++
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Khởi tạo Pico SDK
pico_sdk_init()

# Thêm file mã nguồn của bạn
add_executable(${PROJECT_NAME}
    main.c
    audio_app.c
)

# Thêm đường dẫn tới các file header (.h) cần thiết
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PICO_SDK_PATH}/lib/tinyusb/src
)

# Dòng này thêm thư mục lwipopts để trình biên dịch tìm thấy lwipopts.h
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts
)
set(PICO_LWIP_IRAM_NO_COPY 1)

# Thêm các thư viện mà code của bạn sử dụng
target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    pico_cyw43_arch_lwip_threadsafe_background
    tinyusb_host
)

# Tùy chọn, để tạo ra file uf2
pico_add_extra_outputs(${PROJECT_NAME})
