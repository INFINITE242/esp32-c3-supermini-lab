# ESP32-C3 SuperMini Board Guide

## 1. Board Overview

The ESP32-C3 SuperMini is a compact development board based on the Espressif ESP32-C3 RISC-V microcontroller. It supports 2.4 GHz Wi-Fi, Bluetooth Low Energy (BLE), GPIO, I²C, SPI, UART, PWM, and ADC.

## 2. Arduino IDE Setup
## 2. ESP32-C3 SuperMini Pin Configuration

The following pinout image identifies the GPIO pins, power connections, and common peripheral functions shown for this board.

![ESP32-C3 SuperMini pin configuration](images/esp32-c3-supermini-pinout.jpg)

### Pin Mapping

| Board Pin / Function | GPIO | Common Function |
|---|---:|---|
| MISO | GPIO5 | SPI MISO |
| MOSI | GPIO6 | SPI MOSI |
| SS | GPIO7 | SPI chip select |
| SDA | GPIO8 | I²C data |
| SCL | GPIO9 | I²C clock |
| GPIO10 | GPIO10 | General-purpose I/O |
| RX | GPIO20 | UART receive |
| TX | GPIO21 | UART transmit |
| SCK | GPIO4 | SPI clock |
| GPIO3 | GPIO3 | General-purpose I/O / ADC-capable |
| GPIO2 | GPIO2 | General-purpose I/O / ADC-capable |
| GPIO1 | GPIO1 | General-purpose I/O / ADC-capable |
| GPIO0 | GPIO0 | General-purpose I/O / ADC-capable |

### Power Pins

- **5V:** 5 V input/output according to board power circuitry.
- **GND:** Ground.
- **3V3:** 3.3 V supply.

**Important:** Pin labels and power behavior can vary between board revisions. Check the physical board markings and its documentation before wiring. GPIO pins use 3.3 V logic; do not apply 5 V directly to a GPIO.

### Board Package

1. Open Arduino IDE.
2. Go to **File → Preferences**.
3. Add Espressif's board manager URL if it is not already configured:

   `https://espressif.github.io/arduino-esp32/package_esp32_index.json`

4. Open **Tools → Board → Boards Manager**.
5. Search for `esp32`.
6. Install or update **esp32 by Espressif Systems**.

### Select the Board

Go to **Tools → Board → esp32** and select:

`ESP32C3 Dev Module`

This is the usual Arduino IDE board profile for the ESP32-C3 SuperMini when a dedicated SuperMini profile is unavailable.

## 3. USB Port Selection

1. Connect the board to the Raspberry Pi using a USB data cable.
2. Open **Tools → Port**.
3. Select the serial port that appears when the board is connected, often `/dev/ttyACM0` or `/dev/ttyUSB0`.

The actual port name can vary. If no port appears, check the USB cable and connection.

## 4. Recommended Arduino IDE Settings

Under **Tools**, use these starting settings where available:

| Setting | Value |
|---|---|
| Board | ESP32C3 Dev Module |
| Upload Speed | 115200 |
| USB CDC On Boot | Enabled, if available and appropriate for the board connection |
| CPU Frequency | Default |
| Flash Frequency | Default |
| Flash Mode | Default |
| Partition Scheme | Default |
| Port | Detected board serial port |

Menu options can vary by ESP32 board package version. Start with the defaults for settings not listed here.

## 5. Compile and Upload a Sketch

1. Connect the board over USB.
2. Select the board and port.
3. Open or create an Arduino sketch (`.ino`).
4. Click **Verify** to compile.
5. Click **Upload** to flash the board.
6. Open **Tools → Serial Monitor** if the sketch outputs serial messages, and select the baud rate configured in the sketch.

If upload fails, try holding the board's **BOOT** button while upload begins, then release it when writing starts. Button behavior may vary by board revision.

## 6. GPIO and Pinout

The ESP32-C3 has GPIO pins with functions that can include digital input/output, ADC, PWM, I²C, SPI, and UART. Available functions depend on the board wiring and pin assignments.

For this lab's OLED project, the current wiring is:

- SDA: GPIO 8
- SCL: GPIO 9
- Power: 3.3 V
- Ground: GND

These are the pins used by the OLED setup, not a complete pinout for every SuperMini board revision. Check the labels printed on your board before connecting other hardware.

## 7. Troubleshooting

- **No port appears:** Try a known data-capable USB cable and another USB port.
- **Upload fails:** Confirm the board and port; try 115200 upload speed and BOOT mode if needed.
- **Compilation fails:** Check the selected ESP32 board package and required libraries.
- **Serial output is unreadable:** Match the Serial Monitor baud rate to the sketch's `Serial.begin(...)` setting.
- **Board profile differs:** Select `ESP32C3 Dev Module` if a dedicated SuperMini entry is unavailable.

## Related Project

The OLED wiring, display sketches, test results, and photos are documented separately in [`displays/oled-0.96/`](../../displays/oled-0.96/).
