# ESP32-C3 SuperMini Lab

Experiments, wiring guides, and Arduino sketches for the ESP32-C3 SuperMini.

## Displays

| Display | Project | Status |
|---|---|---|
| 0.96-inch OLED | OLED test and name display | Tested |
| TFT Display | TFT initialization and display test | Planned |

## Repository Structure

- `displays/oled-0.96/` — OLED wiring, documentation, and working sketches.
- `displays/tft/` — TFT wiring and test sketch, when ready.

## Working Setup

- Board: ESP32-C3 SuperMini
- IDE: Arduino IDE
- OLED interface: I2C
- OLED wiring: SDA → GPIO8, SCL/SCK → GPIO9
- OLED power: 3.3V

## Notes

Only mark a project as tested after confirming it works on the hardware.

