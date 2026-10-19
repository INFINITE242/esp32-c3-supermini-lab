
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

// ===== COLORS =====
#define BG       0x0841
#define BLUE     0x3D7F
#define LIGHT    0x7DFF
#define DARK     0x11B5
#define PINK     0xF9B6
#define WHITE    0xFFFF
#define BLACK    0x0000
#define RED      0xF800
#define YELLOW   0xFFE0

// ===== SETTINGS =====
const int FACE_X = 64;
const int FACE_Y = 83;
const int FACE_R = 37;

const int DISPLAY_TIME = 3000; // milliseconds

// ===== DRAW A BUBBLY BLUE FACE =====
void drawFace() {
  // Soft blue outline and face
  tft.fillCircle(FACE_X, FACE_Y, FACE_R + 3, DARK);
  tft.fillCircle(FACE_X, FACE_Y, FACE_R, BLUE);

  // Highlight bubbles
  tft.fillCircle(43, 60, 5, LIGHT);
  tft.fillCircle(48, 54, 2, WHITE);
  tft.fillCircle(87, 105, 3, LIGHT);

  // Cheeks
  tft.fillCircle(39, 91, 6, PINK);
  tft.fillCircle(89, 91, 6, PINK);
}

// ===== SMILE EMOJI =====
void drawSmile() {
  drawFace();

  // Happy eyes
  tft.fillCircle(50, 73, 4, BLACK);
  tft.fillCircle(78, 73, 4, BLACK);

  // Little eye highlights
  tft.fillCircle(51, 72, 1, WHITE);
  tft.fillCircle(79, 72, 1, WHITE);

  // Curved-looking smile
  tft.drawLine(49, 91, 54, 97, BLACK);
  tft.drawLine(54, 97, 64, 101, BLACK);
  tft.drawLine(64, 101, 74, 97, BLACK);
  tft.drawLine(74, 97, 79, 91, BLACK);

  tft.fillCircle(64, 96, 12, BLACK);
  tft.fillCircle(64, 91, 13, BLUE);
  tft.fillRect(49, 85, 30, 7, BLUE);
  tft.drawLine(51, 91, 56, 96, BLACK);
  tft.drawLine(56, 96, 64, 99, BLACK);
  tft.drawLine(64, 99, 72, 96, BLACK);
  tft.drawLine(72, 96, 77, 91, BLACK);
}

// ===== KISS EMOJI =====
void drawKiss() {
  drawFace();

  // One winking eye
  tft.drawLine(45, 73, 55, 73, BLACK);
  tft.drawLine(46, 72, 50, 68, BLACK);
  tft.drawLine(50, 68, 54, 72, BLACK);

  // Open eye
  tft.fillCircle(78, 72, 4, BLACK);
  tft.fillCircle(79, 71, 1, WHITE);

  // Puckered lips
  tft.fillCircle(62, 91, 5, RED);
  tft.fillCircle(69, 91, 5, RED);
  tft.fillTriangle(58, 92, 73, 92, 66, 101, RED);

  // Floating heart
  tft.fillCircle(91, 48, 5, RED);
  tft.fillCircle(99, 48, 5, RED);
  tft.fillTriangle(86, 50, 104, 50, 95, 62, RED);
}

// ===== HUG EMOJI =====
void drawHug() {
  // Arms behind the face
  tft.fillRoundRect(12, 83, 34, 19, 9, LIGHT);
  tft.fillRoundRect(82, 83, 34, 19, 9, LIGHT);

  drawFace();

  // Happy eyes
  tft.drawLine(45, 73, 50, 68, BLACK);
  tft.drawLine(50, 68, 55, 73, BLACK);
  tft.drawLine(73, 73, 78, 68, BLACK);
  tft.drawLine(78, 68, 83, 73, BLACK);

  // Big happy mouth
  tft.fillRoundRect(54, 88, 20, 12, 5, BLACK);
  tft.fillRect(58, 89, 12, 3, WHITE);

  // Arms hugging the cheeks
  tft.fillCircle(31, 91, 8, LIGHT);
  tft.fillCircle(97, 91, 8, LIGHT);

  // Little heart
  tft.fillCircle(60, 119, 5, PINK);
  tft.fillCircle(68, 119, 5, PINK);
  tft.fillTriangle(55, 121, 73, 121, 64, 132, PINK);
}

// ===== SCREEN TITLE =====
void drawTitle(const char* title) {
  tft.fillRect(0, 0, 128, 24, BG);
  tft.setTextSize(1);
  tft.setTextColor(WHITE, BG);

  int16_t x1, y1;
  uint16_t w, h;
  tft.getTextBounds(title, 0, 0, &x1, &y1, &w, &h);
  tft.setCursor((128 - w) / 2, 8);
  tft.print(title);
}

// ===== SETUP =====
void setup() {
  Serial.begin(115200);

  tft.initR(INITR_GREENTAB);
  tft.setRotation(0);
  tft.fillScreen(BG);

  Serial.println("Blue Emoji TFT started!");
}

// ===== LOOP: CYCLE THROUGH EXPRESSIONS =====
void loop() {
  tft.fillScreen(BG);
  drawTitle("1. KISS");
  drawKiss();
  Serial.println("Kiss emoji");
  delay(DISPLAY_TIME);

  tft.fillScreen(BG);
  drawTitle("2. SMILE");
  drawSmile();
  Serial.println("Smile emoji");
  delay(DISPLAY_TIME);

  tft.fillScreen(BG);
  drawTitle("3. HUG");
  drawHug();
  Serial.println("Hug emoji");
  delay(DISPLAY_TIME);
}
