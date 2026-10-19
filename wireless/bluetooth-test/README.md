# ESP32-C3 SuperMini — Bluetooth LE Test

## Objective

Verify that the ESP32-C3 SuperMini can advertise as a Bluetooth Low Energy (BLE) device.

**Note:** The ESP32-C3 supports BLE, not Bluetooth Classic.

## Requirements

- ESP32-C3 SuperMini
- USB data cable
- Raspberry Pi with Arduino IDE
- ESP32 board package by Espressif Systems
- Phone with a BLE scanner app

## Sketch

The test sketch is located at [`code/ble_test.ino`](code/ble_test.ino).

It starts BLE advertising with the device name `ESP32-C3-SuperMini-Test`.

## Arduino IDE Settings

- Board: `ESP32C3 Dev Module`
- Upload speed: `115200`
- Port: Select the ESP32-C3 serial port
- Serial Monitor baud rate: `115200`

## Test Procedure

1. Connect the board to the Raspberry Pi.
2. Open `code/ble_test.ino` in Arduino IDE.
3. Select the board and port, then verify and upload.
4. Open Serial Monitor at `115200` baud.
5. Use a BLE scanner app on your phone to scan for nearby devices.
6. Look for `ESP32-C3-SuperMini-Test`.

## Expected Result

The Serial Monitor reports that BLE advertising has started. A BLE scanner should detect the advertised device.

## Result

- Status: Passed — hardware tested
- Device detected: ESP32-C3-SuperMini-Test
- Notes: BLE advertising and phone detection successful

Mark the test as passed only after confirming detection on the physical board.
