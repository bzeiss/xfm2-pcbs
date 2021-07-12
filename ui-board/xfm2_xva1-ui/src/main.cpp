#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

struct functionKeys {
  char *f1="";
  char *f2="";
  char *f3="";
  char *f4="";
  char *f5="";
  char *f6="";
  char *f7="";
  char *f8="";
};

U8G2_T6963_240X64_F_8080 u8g2(U8G2_R0, 8, 9, 10, 11, 4, 5, 6, 7, /*enable/wr=*/ 17, /*cs/ce=*/ 14, /*dc=*/ 15, /*reset=*/ 16); // Connect RD with +5V, FS0 and FS1 with GND

void drawPatchName(const char *s) {
  int16_t displayWidth = -(int16_t)u8g2.getDisplayWidth();
  int16_t len = strlen(s);

//  u8g2.setFont(u8g2_font_logisoso32_tf);
  u8g2.setFont(u8g2_font_luRS19_tf);

  int16_t textWidth = u8g2.getUTF8Width(s);
  Serial.print("text width: ");
  Serial.print(textWidth);
  Serial.println();
  int16_t offset=((240-textWidth)/2)-1;
    
  u8g2.setCursor(offset, ((64-6-6-1)/2)+(32/2));
//  u8g2.setCursor(offset, 32);
  u8g2.print(s);
}

void drawFunctionKeys(functionKeys functionKeysInstance) {
  u8g2.setFont(u8g2_font_5x8_mf);
  int16_t spacing=240/8;
  u8g2.setFontMode(0);
  u8g2.setDrawColor(1);
  u8g2.setCursor(0, 64);
  u8g2.print(functionKeysInstance.f1);
  u8g2.setCursor(spacing, 64);
  u8g2.print(functionKeysInstance.f2);
  u8g2.setCursor(spacing*2, 64);
  u8g2.print(functionKeysInstance.f3);
  u8g2.setCursor(spacing*3, 64);
  u8g2.print(functionKeysInstance.f4);
  u8g2.setCursor(spacing*4, 64);
  u8g2.print(functionKeysInstance.f5);
  u8g2.setCursor(spacing*5, 64);
  u8g2.print(functionKeysInstance.f6);
  u8g2.setCursor(spacing*6, 64);
  u8g2.print(functionKeysInstance.f7);
  u8g2.setCursor(spacing*7, 64);
  u8g2.setFontMode(0);
  u8g2.setDrawColor(0);
  u8g2.print(functionKeysInstance.f8);
  u8g2.setFontMode(0);
  u8g2.setDrawColor(1);
  u8g2.drawHLine(0,57,240);
}

void drawVoiceHead(char *bank, int number) {
  u8g2.setFont(u8g2_font_5x8_mf);
  u8g2.setCursor(0, 6);
  u8g2.print("VOICE");
  u8g2.print(" ");
  u8g2.print("I -C09(41)");

  u8g2.setFont(u8g2_font_5x8_mf);
}


void drawVoiceForm(const char *s) {
  u8g2.clearBuffer();
  drawPatchName(s);
  struct functionKeys functionKeysInstance;
  functionKeysInstance.f1 = "Send";
  functionKeysInstance.f7 = "Ctrl";
  functionKeysInstance.f8 = "Dir";
  drawFunctionKeys(functionKeysInstance);
  drawVoiceHead("A", 49);
  u8g2.sendBuffer();
}

// ---------------------------------------------------------------------------------------

void setup(void) {
  /* U8g2 Project: T6963 Test Board */
  pinMode(18, OUTPUT);
  digitalWrite(18, 1);	

  u8g2.begin();  
  u8g2.enableUTF8Print();
}

void loop(void) {
  drawVoiceForm("GrandPiano2");
  delay(3000);
  drawVoiceForm("Arianne");
  delay(3000);
  drawVoiceForm("Dyno E.Pno");
  delay(3000);
  drawVoiceForm("BrasChoral");
  delay(3000);
  drawVoiceForm("Nasty Saw");
  delay(3000);
}