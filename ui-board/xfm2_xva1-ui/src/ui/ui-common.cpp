#include "ui-common.h"

U8G2 *u8g2;

void setupUi() {
  /* U8g2 Project: T6963 Test Board */
  pinMode(18, OUTPUT);
  digitalWrite(18, 1);

  /*
      Mapping for Arduino Pins:
      Pin 08: DB0
      Pin 09: DB1
      Pin 10: DB2
      Pin 11: DB3
      Pin 04: DB4
      Pin 05: DB5
      Pin 06: DB6
      Pin 07: DB7
      Pin 17: ~WR
      Pin 14: CS / ~CE
      Pin 15: CD / C/D
      Pin 16: ~RST

      Mapping for remaining ERM24064 Pins:
      Pin 01: GND
      Pin 02: GND
      Pin 03: VCC +5V
      Pin 04: Pin 20 through 20k Trimpot
      Pin 06: VCC +5V
      Pin 19: GND
      Pin 09: leave open
      Pin 20: --> Pin 04


  */
  u8g2 = new U8G2_T6963_240X64_F_8080(U8G2_R0,
                                      8,
                                      9,
                                      10,
                                      11,
                                      4,
                                      5,
                                      6,
                                      7, /*enable/wr=*/
                                      17, /*cs/ce=*/
                                      14, /*dc=*/
                                      15, /*reset=*/
                                      16); // Connect RD with +5V, FS0 and FS1 with GND

//    u8g2->setDisplayRotation(U8G2_R2);
  u8g2->begin();
  u8g2->enableUTF8Print();
}
