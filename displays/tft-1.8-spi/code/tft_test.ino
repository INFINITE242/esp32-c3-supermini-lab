
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

// ===== TFT PINS =====
#define TFT_CS   10
#define TFT_RST   3
#define TFT_DC    2
#define TFT_MOSI  6
#define TFT_SCLK  4

Adafruit_ST7735 tft =
    Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

// ===== USER SETTINGS: EDIT HERE =====
const char* line1 = "WELCOME";
const char* line2 = "YOUR NAME";
const char* line3 = "ESP32-C3";
const char* line4 = "TFT DISPLAY";

const int textSize1 = 1;
const int textSize2 = 2;
const int textSize3 = 1;
const int textSize4 = 1;

const int posX1 = 10, posY1 = 15;
const int posX2 = 10, posY2 = 45;
const int posX3 = 10, posY3 = 85;
const int posX4 = 10, posY4 = 110;

const uint16_t color1 = ST77XX_CYAN;
const uint16_t color2 = ST77XX_YELLOW;
const uint16_t color3 = ST77XX_GREEN;
const uint16_t color4 = ST77XX_WHITE;

const uint16_t backgroundColor = ST77XX_BLACK;

// ===== DISPLAY LOGIC =====
void drawLine(const char* text, int size, int x, int y,
              uint16_t color) {
  tft.setTextSize(size);
  tft.setTextColor(color);
  tft.setCursor(x, y);
  tft.print(text);
}

void setup() {
  Serial.begin(115200);
  delay(300);

  tft.initR(INITR_GREENTAB);
  tft.setRotation(0);
  tft.fillScreen(backgroundColor);
  tft.setTextWrap(false);

  drawLine(line1, textSize1, posX1, posY1, color1);
  drawLine(line2, textSize2, posX2, posY2, color2);
  drawLine(line3, textSize3, posX3, posY3, color3);
  drawLine(line4, textSize4, posX4, posY4, color4);

  Serial.println("TFT text display ready!");
}

void loop() {
  // Static text display
}
