#include <Arduino.h>
#include "ctrlboard/ctrlboard.h"
#include "common.h"

CtrlBoard *ctrlboard;

// ---------------------------------------------------------------------------------------

void setup(void) {
  VoiceModel *voiceModel;

  Serial.begin(500000);

  setupUi();
  auto *voiceMode = new VoiceMode(nullptr);
  voiceModel = new VoiceModel(patchNames[0]);  // adapt the index zero later
  voiceMode->updateVoiceModel(voiceModel);
  ctrlboard = new CtrlBoard();
  ctrlboard->setVoiceMode(voiceMode);
  voiceMode->draw(); 
}

// =======================================================================================
// Loop
// =======================================================================================

void loop(void) {
  ctrlboard->handleLoop();
  //printFreeMemory();
}