#include "ui-common.h"

U8G2 *u8g2;

void setupUi() {
    /* U8g2 Project: T6963 Test Board */
    pinMode(18, OUTPUT);
    digitalWrite(18, 1);	

    u8g2 = new U8G2_T6963_240X64_F_8080(U8G2_R0, 8, 9, 10, 11, 4, 5, 6, 7, /*enable/wr=*/ 17, /*cs/ce=*/ 14, /*dc=*/ 15, /*reset=*/ 16); // Connect RD with +5V, FS0 and FS1 with GND

    u8g2->begin();  
    u8g2->enableUTF8Print();  
}