# ESP32-S3 Touch LCD 4.3" — EV Charger UI

Firmware for the Waveshare ESP32-S3-Touch-LCD-4.3 board running a multi-screen EV charger interface designed in SquareLine Studio and built with PlatformIO.

The UI includes a loading screen, a main dashboard, and a settings screen, all with animated transitions and GT911 capacitive touch input.

## Hardware

- **Board**: Waveshare ESP32-S3-Touch-LCD-4.3
- **Display**: 800×480 RGB parallel (ST7262)
- **Touch**: GT911 (I2C, SDA=GPIO8, SCL=GPIO9)
- **IO Expander**: CH422G (backlight, LCD reset, touch reset, SD card)

## Getting Started

1. Open the project in PlatformIO.
2. Connect the board via USB.
3. To enter flash mode: hold **Boot**, press **Reset**, release **Boot**.
4. Run **Upload** from PlatformIO.
5. After flashing, press **Reset** to start the firmware.

## Project Structure

```
src/main.cpp          — LVGL init, panel setup, touch polling, RTOS task
lib/lv_conf.h         — LVGL configuration (tick, buffers, fonts)
lib/ESP_Panel_Conf.h  — Hardware pin/timing config for display and touch
lib/ui/               — UI source exported from SquareLine Studio
squareline/           — SquareLine Studio project files
```

## Libraries

Managed locally under `lib/` to allow customization:

- **ESP32_Display_Panel** — Display and touch driver abstraction for Espressif boards.
- **ESP32_IO_Expander** — CH422G IO expander support (not yet in the official upstream).
- **lvgl 8.3.8** — Added as a PlatformIO library dependency in `platformio.ini`.

## PlatformIO Configuration

```ini
[env:esp32s3box]
platform = espressif32
board = esp32s3box
framework = arduino
monitor_speed = 115200
board_upload.flash_size = 16MB
build_flags =
    -D BOARD_HAS_PSRAM
    -D LV_CONF_INCLUDE_SIMPLE
    -I lib
board_build.arduino.memory_type = qio_opi
board_build.f_flash = 80000000L
board_build.flash_mode = qio
lib_deps =
    lvgl/lvgl@8.3.8
```

## SquareLine Studio

The UI was designed using SquareLine Studio with the **Arduino / TFT_eSPI** export target at 800×480. Only the `lib/ui` folder from the exported template project is used here.

## Rendering Notes

- LVGL is configured with a **dual 60-line internal SRAM buffer** for smoother transitions.
- The RGB parallel bus uses an **immediate flush** path (no frame-sync wait per chunk) to avoid visible scanline artifacts.
- Refresh period is set to **16 ms** (~60 fps target).
- The GT911 touch controller is reset via the CH422G expander before panel initialization to ensure reliable detection.
