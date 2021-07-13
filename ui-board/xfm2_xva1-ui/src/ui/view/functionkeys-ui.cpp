#include <U8g2lib.h>
#include "functionkeys-ui.h"

void FunctionKeysUI::draw() {
    u8g2->setFont(u8g2_font_5x8_mf);
    int16_t spacing=240/8;
    u8g2->setFontMode(0);
    u8g2->setDrawColor(1);
    u8g2->setCursor(0, 64);
    u8g2->print(functionKeys->f1);
    u8g2->setCursor(spacing, 64);
    u8g2->print(functionKeys->f2);
    u8g2->setCursor(spacing*2, 64);
    u8g2->print(functionKeys->f3);
    u8g2->setCursor(spacing*3, 64);
    u8g2->print(functionKeys->f4);
    u8g2->setCursor(spacing*4, 64);
    u8g2->print(functionKeys->f5);
    u8g2->setCursor(spacing*5, 64);
    u8g2->print(functionKeys->f6);
    u8g2->setCursor(spacing*6, 64);
    u8g2->print(functionKeys->f7);
    u8g2->setCursor(spacing*7, 64);
    u8g2->setFontMode(0);
    u8g2->setDrawColor(0);
    u8g2->print(functionKeys->f8);
    u8g2->setFontMode(0);
    u8g2->setDrawColor(1);
    u8g2->drawHLine(0,57,240);
}

FunctionKeysUI::FunctionKeysUI(FunctionKeys *functionKeys, U8G2 u8g2) {
    this->functionKeys = functionKeys;
    this->u8g2 = &u8g2;
}