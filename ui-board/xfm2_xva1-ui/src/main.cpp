#include <Arduino.h>
#include "ctrlboard/ctrlboard.h"
#include "ui/model/functionkeys.h"
#include "ui/view/voicemode/voicemode.h"
#include "ui/model/voicemodel.h"

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

CtrlBoard *ctrlboard;
VoiceMode *voiceMode;

// =======================================================================================

void setup(void) {
  Serial.begin(9600);
  ctrlboard = new CtrlBoard();
  setupUi();
  voiceMode = new VoiceMode();
}

// =======================================================================================

void loop(void) {
  voiceMode->updateVoiceModel(new VoiceModel(strdup("GrandPiano")));
  voiceMode->draw();
  delay(1000);
  voiceMode->updateVoiceModel(new VoiceModel(strdup("Arianne")));
  voiceMode->draw();
  delay(1000);
  voiceMode->updateVoiceModel(new VoiceModel(strdup("Dyno E.Pno")));
  voiceMode->draw();
  delay(1000);
  voiceMode->updateVoiceModel(new VoiceModel(strdup("BrasChoral")));
  voiceMode->draw();
  delay(1000);
  voiceMode->updateVoiceModel(new VoiceModel(strdup("Nasty Saw")));
  voiceMode->draw();
  delay(1000);

  //ctrlboard->handleLoop();
}