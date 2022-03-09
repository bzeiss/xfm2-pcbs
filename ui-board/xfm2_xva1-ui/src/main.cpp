#include <Arduino.h>
#include "ctrlboard/ctrlboard.h"
#include "common.h"

CtrlBoard *ctrlboard;

// ---------------------------------------------------------------------------------------

void setup() {
  VoiceModel *voiceModel;

  Serial.begin(500000); // for monitoring

  setupUi();
  auto *voiceMode = new VoiceMode(nullptr);
  //voiceModel = new VoiceModel(patchNames[0]);  // adapt the index zero later
  voiceModel = new VoiceModel(patchNames[0], 0);  // adapt the index zero later
  voiceMode->updateVoiceModel(voiceModel);
  ctrlboard = new CtrlBoard();
  ctrlboard->setVoiceMode(voiceMode);

}

// =======================================================================================
// Loop
// =======================================================================================

void loop(void) {
  ctrlboard->handleLoop();
//  printFreeMemory();
//  testScreen();
//  delay(10000);
}