# Espressif 32: development platform for [PlatformIO](https://platformio.org)

[![Build Status](https://github.com/platformio/platform-espressif32/workflows/Examples/badge.svg)](https://github.com/platformio/platform-espressif32/actions)

ESP32 is a series of low-cost, low-power system on a chip microcontrollers with integrated Wi-Fi and Bluetooth. ESP32 integrates an antenna switch, RF balun, power amplifier, low-noise receive amplifier, filters, and power management modules.

* [Home](https://registry.platformio.org/platforms/platformio/espressif32) (home page in the PlatformIO Registry)
* [Documentation](https://docs.platformio.org/page/platforms/espressif32.html) (advanced usage, packages, boards, frameworks, etc.)

# Usage

1. [Install PlatformIO](https://platformio.org)
2. Create PlatformIO project and configure a platform option in [platformio.ini](https://docs.platformio.org/page/projectconf.html) file:

## Stable version

See `platform` [documentation](https://docs.platformio.org/en/latest/projectconf/sections/env/options/platform/platform.html#projectconf-env-platform) for details.

```ini
[env:stable]
; recommended to pin to a version, see https://github.com/platformio/platform-espressif32/releases
; platform = espressif32 @ ^6.0.1
platform = espressif32
board = yolo_uno
framework = arduino
monitor_speed = 115200

build_flags =
    -D ARDUINO_USB_MODE=1
    -D ARDUINO_USB_CDC_ON_BOOT=1
```

## Development version

```ini
[env:development]
platform = https://github.com/platformio/platform-espressif32.git
board = yolo_uno
framework = arduino
monitor_speed = 115200
build_flags =
    -D ARDUINO_USB_MODE=1
    -D ARDUINO_USB_CDC_ON_BOOT=1
```

# YoloUNO ESP32-S3 LED Blinky Project

## Project Overview

This project implements a simple LED blinking application using the Yolo_Uno_S3 board based on the ESP32-S3 microcontroller. It demonstrates the basic functionality of controlling GPIO pins for LED output.

## Hardware Requirements

- [Yolo_Uno_S3 board](https://www.espressif.com/en/products/socs/esp32s3)
- USB cable for programming and power

## Pin Configuration

The project uses the onboard LED or can be configured to use any GPIO pin for LED output.

## Software Setup

This project is developed using PlatformIO with the following configuration:

```ini
[env:yolo_uno]
platform = espressif32
board = yolo_uno
framework = arduino
monitor_speed = 115200

build_flags =
    -D ARDUINO_USB_MODE=1
    -D ARDUINO_USB_CDC_ON_BOOT=1
```

## Usage Instructions

1. [Install PlatformIO](https://platformio.org)
2. Clone this repository or download the source code
3. Open the project in PlatformIO
4. Build and upload to your Yolo_Uno_S3 board:
   ```
   pio run --target upload
   ```
5. Monitor the serial output (optional):
   ```
   pio device monitor
   ```

## Code Structure

The main application code is in `src/main.cpp` and demonstrates:
- GPIO pin configuration
- LED control using digital output
- Timing control using delay functions

## Modifying the Project

You can modify the blink rate by changing the delay values in the main loop. To use different GPIO pins, update the pin definition in the code.

## Troubleshooting

If you encounter issues:
- Ensure USB CDC is enabled (as set in build_flags)
- Check your board connection
- Verify your COM port selection
- Make sure you have the correct drivers installed

## Additional Resources

* [ESP32-S3 Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/index.html)
* [Arduino Framework for ESP32](https://docs.platformio.org/en/latest/frameworks/arduino.html#framework-arduino)
* [PlatformIO Documentation](https://docs.platformio.org/)

## License

This project is open-source software. Feel free to modify and distribute as needed.

# Configuration

Please navigate to [documentation](https://docs.platformio.org/page/platforms/espressif32.html).