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
VoiceMode *voiceMode;
VoiceModel *voiceModel = nullptr;
const char *patchNames[5] = {"GrandPiano","Arianne","Dyno E.Pno","BrasChoral","Nasty Saw"};
int i = 0;

// =======================================================================================

void setup(void) {
  Serial.begin(9600);
  ctrlboard = new CtrlBoard();
  setupUi();
  voiceMode = new VoiceMode(nullptr);
}

// =======================================================================================


void loop(void) {
  delete voiceModel;
  voiceModel = new VoiceModel(patchNames[i]);  
  voiceMode->updateVoiceModel(voiceModel);
  voiceMode->draw();
  delay(100);
  i++;
  if (i>5) 
    i = 0;

  //printFreeMemory();

  //ctrlboard->handleLoop();
}