#include "voicedetails.h"

// ---------------------------------------------------------------------------------------

VoiceDetails::VoiceDetails(VoiceModel *voiceModel) {
    this->voiceModel = voiceModel;
}

// ---------------------------------------------------------------------------------------

VoiceDetails::~VoiceDetails() {
}

// ---------------------------------------------------------------------------------------

void VoiceDetails::draw() {
    drawVoiceHead();
    drawPatchName();
}

// ---------------------------------------------------------------------------------------

void VoiceDetails::drawVoiceHead() {
  u8g2->setFont(u8g2_font_5x8_mf);
  u8g2->setCursor(0, 6);
  u8g2->print("VOICE");
  u8g2->print(" ");
  u8g2->print("I -C09(41)");

  u8g2->setFont(u8g2_font_5x8_mf);
}

// ---------------------------------------------------------------------------------------

void VoiceDetails::drawPatchName() {
    //  int16_t displayWidth = -(int16_t)u8g2.getDisplayWidth();
    //  int16_t len = strlen(s);

    //  u8g2.setFont(u8g2_font_logisoso32_tf);
    u8g2->setFont(u8g2_font_luRS19_tf);

//    int16_t textWidth = u8g2->getUTF8Width(this->patchName);
    int16_t textWidth = u8g2->getUTF8Width(voiceModel->getVoiceName());
    // Serial.print("text width: ");
    // Serial.print(textWidth);
    //Serial.print(this->voiceModel->voiceName);

    int16_t offset=((240-textWidth)/2)-1;

    u8g2->setCursor(offset, ((64-6-6-1)/2)+(32/2));
    //  u8g2.setCursor(offset, 32);
    u8g2->print(voiceModel->getVoiceName());
}

// ---------------------------------------------------------------------------------------

void VoiceDetails::updateVoiceModel(VoiceModel *voiceModel) {
    this->voiceModel = voiceModel;
}