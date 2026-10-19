# 1.8-inch SPI TFT Display

Hardware test for a 1.8-inch, 128x160 SPI TFT display using the ESP32-C3 SuperMini.

## Hardware

- Board: ESP32-C3 SuperMini
- Display: 1.8-inch TFT SPI, 128x160, V1.1
- Power: 3.3V, tested by the user
- Interface: SPI
- Arduino libraries:
  - Adafruit ST7735 and ST7789 Library
  - Adafruit GFX Library
  - Adafruit BusIO

## Wiring

| TFT pin | ESP32-C3 connection |
|---|---|
| VCC | 3V3 |
| GND | GND |
| CS | GPIO10 |
| RESET | GPIO3 |
| A0 / DC | GPIO2 |
| SDA / MOSI | GPIO6 |
| SCK | GPIO4 |
| LED | 3.3V, as tested |

## Test

- Sketch: `code/tft_test.ino`
- Resolution: 128x160 pixels
- Initialization: `INITR_GREENTAB`
- Test result: Passed — text display confirmed working
- Serial output: `TFT text display ready!`

## Customization

Edit the USER SETTINGS section in the sketch to change:

- Four text lines
- Text size
- Text position
- Text colors
- Background color

Text size 1 is small; size 2 is larger. Keep text within the 128x160 screen area.

## Photos

Add wiring and display test photos to the `photos/` directory.

## Notes

The exact controller chip has not been independently identified.
