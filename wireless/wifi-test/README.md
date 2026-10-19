# ESP32-C3 SuperMini — Wi-Fi Scan Test

## Objective

Verify that the ESP32-C3 SuperMini can scan for nearby 2.4 GHz Wi-Fi networks.

## Requirements

- ESP32-C3 SuperMini
- USB data cable
- Raspberry Pi with Arduino IDE
- ESP32 board package by Espressif Systems

## Sketch

The test sketch is located at [`code/wifi_scan.ino`](code/wifi_scan.ino).

It scans for nearby Wi-Fi networks and prints each network's SSID, signal strength (RSSI), and whether it is open or secured.

## Arduino IDE Settings

- Board: `ESP32C3 Dev Module`
- Upload speed: `115200`
- Port: Select the port assigned to your ESP32-C3
- Serial Monitor baud rate: `115200`

## Test Procedure

1. Connect the ESP32-C3 to the Raspberry Pi using USB.
2. Open `code/wifi_scan.ino` in Arduino IDE.
3. Select the board and port.
4. Verify and upload the sketch.
5. Open Serial Monitor at `115200` baud.
6. Press the board's reset button if needed.

## Expected Result

The Serial Monitor should show the scan starting, the number of networks found, and the SSID and RSSI for each detected network.

The ESP32-C3 supports 2.4 GHz Wi-Fi; 5 GHz-only networks will not appear.

## Result

- Status: Passed — hardware tested
- Networks detected: Confirmed
- Notes: Wi-Fi scan completed successfully

Do not mark the test as passed until it has been run on the physical board.
