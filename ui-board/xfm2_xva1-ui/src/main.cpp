#include <Arduino.h>
//#include <U8g2lib.h>
#include "ctrlboard/ctrlboard.h"
#include "ui/model/functionkeys.h"
#include "ui/view/voicemode/voicemode.h"

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

//U8G2_T6963_240X64_F_8080 u8g2(U8G2_R0, 8, 9, 10, 11, 4, 5, 6, 7, /*enable/wr=*/ 17, /*cs/ce=*/ 14, /*dc=*/ 15, /*reset=*/ 16); // Connect RD with +5V, FS0 and FS1 with GND

CtrlBoard *ctrlboard;
VoiceMode *voiceMode;

// ---------------------------------------------------------------------------------------
/*
void drawPatchName(const char *s) {
//  int16_t displayWidth = -(int16_t)u8g2.getDisplayWidth();
//  int16_t len = strlen(s);

//  u8g2.setFont(u8g2_font_logisoso32_tf);
  u8g2.setFont(u8g2_font_luRS19_tf);

  int16_t textWidth = u8g2.getUTF8Width(s);
  // Serial.print("text width: ");
  // Serial.print(textWidth);
  // Serial.println();
  int16_t offset=((240-textWidth)/2)-1;
    
  u8g2.setCursor(offset, ((64-6-6-1)/2)+(32/2));
//  u8g2.setCursor(offset, 32);
  u8g2.print(s);
}
*/
// ---------------------------------------------------------------------------------------
/*
void drawVoiceHead(const char *bank, int number) {
  u8g2.setFont(u8g2_font_5x8_mf);
  u8g2.setCursor(0, 6);
  u8g2.print("VOICE");
  u8g2.print(" ");
  u8g2.print("I -C09(41)");

  u8g2.setFont(u8g2_font_5x8_mf);
}
*/
// ---------------------------------------------------------------------------------------

void drawVoiceForm(const char *s) {
  //u8g2.clearBuffer();
  //drawPatchName(s);

  voiceMode->draw();
 
  //drawVoiceHead("A", 49);
  
  //u8g2.sendBuffer();

}

// =======================================================================================

void setup(void) {
  ctrlboard = new CtrlBoard();
  setupUi();
  voiceMode = new VoiceMode();
}

// =======================================================================================

void loop(void) {
  drawVoiceForm("GrandPiano3");
  delay(3000);
  drawVoiceForm("Arianne");
  delay(3000);
  drawVoiceForm("Dyno E.Pno");
  delay(3000);
  drawVoiceForm("BrasChoral");
  delay(3000);
  drawVoiceForm("Nasty Saw");
  delay(3000);
  //ctrlboard->handleLoop();
}