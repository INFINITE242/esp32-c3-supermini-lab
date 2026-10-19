
#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("ESP32-C3 Wi-Fi Scan Test");

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);

  Serial.println("Scanning for nearby Wi-Fi networks...");
  int networks = WiFi.scanNetworks();

  if (networks == 0) {
    Serial.println("No networks found.");
  } else {
    Serial.printf("Found %d network(s):\n", networks);

    for (int i = 0; i < networks; i++) {
      Serial.printf("%d: %s | RSSI: %d dBm | Security: %s\n",
                    i + 1,
                    WiFi.SSID(i).c_str(),
                    WiFi.RSSI(i),
                    WiFi.encryptionType(i) == WIFI_AUTH_OPEN
                      ? "Open" : "Secured");
    }
  }

  WiFi.scanDelete();
  WiFi.mode(WIFI_OFF);
  Serial.println("Scan complete.");
}

void loop() {
  // One scan per reset.
}
