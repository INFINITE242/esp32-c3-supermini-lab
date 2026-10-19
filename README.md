# ESP32-C3 SuperMini Lab

Documentation, wiring guides, Arduino sketches, and hardware tests for the ESP32-C3 SuperMini.

## Documentation

### 1. Board

- [ESP32-C3 SuperMini Board Guide](board/esp32-c3-supermini/README.md) — board specifications, pin configuration, Arduino IDE setup, port selection, upload settings, and troubleshooting.

### 2. Wireless

- [Wireless Tests](wireless/README.md) — Wi-Fi scanning and Bluetooth Low Energy (BLE) testing.
- [Wi-Fi Test](wireless/wifi-test/README.md) — scan for nearby 2.4 GHz networks.
- [Bluetooth LE Test](wireless/bluetooth-test/README.md) — BLE advertising and phone detection.

### 3. Displays

- [0.96-inch OLED](displays/oled-0.96/README.md) — wiring, test sketches, results, and photos.
- **TFT Display** — planned; documentation will be added when the project is ready.

## Working Setup

- **Board:** ESP32-C3 SuperMini
- **Development environment:** Arduino IDE
- **OLED interface:** I²C
- **OLED SDA:** GPIO 8
- **OLED SCL:** GPIO 9
- **OLED power:** 3.3 V

## Project Status

- Board documentation: Added
- Wi-Fi scan test: Hardware test reported passed
- Bluetooth LE test: Hardware test reported passed
- OLED tests: Tested
- TFT display: Planned

Only mark a hardware test as passed after confirming it works on the physical board.
