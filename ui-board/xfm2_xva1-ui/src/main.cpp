#include <Arduino.h>
#include "ctrlboard/ctrlboard.h"
#include "ui/model/functionkeys.h"
#include "ui/view/voicemode/voicemode.h"
#include "ui/model/voicemodel.h"
#include "common.h"

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

CtrlBoard *ctrlboard;

// ---------------------------------------------------------------------------------------

void setup(void) {
  VoiceModel *voiceModel = nullptr;

  Serial.begin(500000);

  setupUi();
  VoiceMode *voiceMode = new VoiceMode(nullptr);
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