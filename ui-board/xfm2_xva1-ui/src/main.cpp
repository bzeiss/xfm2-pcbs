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
  ctrlboard->setup();
  setupUi();
  voiceMode = new VoiceMode(nullptr);
  voiceModel = new VoiceModel(patchNames[i]);  
  voiceMode->updateVoiceModel(voiceModel);
  voiceMode->draw();
}

// =======================================================================================

void updateVoiceModel() {
  delete voiceModel;
  voiceModel = new VoiceModel(patchNames[i]);  
  voiceMode->updateVoiceModel(voiceModel);
  voiceMode->draw();
}

void loop(void) {
  if (Serial.available()) {
    char val = Serial.read();
    
    if (val == 'u') { // up
    } else if (val == 'd') { // down
    } else if (val == 'l') { // left
      i--;
      if (i<0) 
        i = 4;
      updateVoiceModel();
    } else if (val == 'r') { // right
      i++;
      if (i>4) 
        i = 0;
      updateVoiceModel();
    } else if (val == 'e') {      
    }
  }
  ctrlboard->handleLoop();

  //printFreeMemory();
}