
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLEAdvertising.h>

BLEServer *pServer = nullptr;

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("ESP32-C3 Bluetooth LE Test");

  BLEDevice::init("ESP32-C3-SuperMini-Test");
  pServer = BLEDevice::createServer();

  BLEAdvertising *pAdvertising =
      BLEDevice::getAdvertising();

  pAdvertising->addServiceUUID("180A");
  pAdvertising->start();

  Serial.println("BLE advertising started!");
  Serial.println("Device name: ESP32-C3-SuperMini-Test");
  Serial.println("Scan for this device using a BLE scanner app.");
}

void loop() {
  delay(2000);
  Serial.println("BLE advertising is active.");
}
