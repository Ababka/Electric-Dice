#include <Adafruit_GFX.h>    // graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>             // Arduino library

#define TFT_CS    10  // define chip select pin
#define TFT_DC     9  // define data/command pin
#define TFT_RST    8  // define reset pin, or set to -1 and connect to Arduino RESET pin

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
long randNumber;

void setup() {
  tft.init(240, 240, SPI_MODE2);

  // if the screen is flipped, remove this command
  tft.setRotation(2);

  tft.fillScreen(0);
  delay(100);
  tft.setTextSize(6); //each 1 = 10 pixels
  delay(2000);
  tft.fillScreen(0);
  delay(2000);
  RandoNumber();
  delay(5000);
  tft.fillScreen(0);
  RandoNumber2();
  delay(5000);
  tft.fillScreen(0);
  delay(5000);
  tft.fillScreen(0);
}

void loop() {
}

void RandoNumber() {
    randomSeed(analogRead(0));
    randNumber = random(1, 21);

  tft.setTextSize(6);
  tft.setCursor(0, 0);
  tft.setTextColor(ST77XX_WHITE);
  tft.print("Ready?");
    haptic();
  delay(1000);
  tft.fillScreen(0);
  tft.setTextSize(10);
  tft.setCursor(60, 60);
  tft.setTextColor(ST77XX_WHITE);
  ft.print(randNumber);
}

void RandoNumber2() {
    randomSeed(analogRead(0));
    randNumber = random(1, 20);

  tft.setTextSize(6);
  tft.setCursor(0, 0);
  tft.setTextColor(ST77XX_WHITE);
  tft.print("Again?");
    haptic();
  delay(1000);
  tft.fillScreen(0);
  tft.setTextSize(10);
  tft.setCursor(60, 60);
  tft.setTextColor(ST77XX_BLUE);
     tft.print(randNumber);
}

void haptic() {
  digitalWrite(7, HIGH);
  delay(3000);
  digitalWrite(7, LOW);
}