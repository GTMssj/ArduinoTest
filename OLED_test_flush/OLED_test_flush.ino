#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }//display initiallize
  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.cp437(true);
  Serial.begin(9600);
  Serial.println("Boot Success");
}
void loop() {
  if (Serial.available() != 0){
    readinput();
  }//if has input, read it
  delay(10);
}

void readinput(){
  refresh();
  while (Serial.available() > 0){
    char input = Serial.read();
    display.print(input);
    display.display();
  }
  display.display();
}
void refresh(){
  int cursorY = display.getCursorY();
  if (cursorY >= 64){
    display.clearDisplay();
    display.display();
    display.setCursor(0,0);
  }
}
