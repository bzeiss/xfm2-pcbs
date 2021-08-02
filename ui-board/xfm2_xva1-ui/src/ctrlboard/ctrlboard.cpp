#include "ctrlboard.h"
#include "../common.h"
#include <Arduino.h>

// ---------------------------------------------------------------------------------------

void CtrlBoard::setup(VoiceMode *voiceMode) {
  this->voiceMode = voiceMode;
  mcp.begin();

  mcp.pinMode(BUTTON1_PIN, INPUT);
  mcp.pullUp(BUTTON1_PIN, HIGH);
  mcp.pinMode(BUTTON2_PIN, INPUT);
  mcp.pullUp(BUTTON2_PIN, HIGH);
  mcp.pinMode(BUTTON3_PIN, INPUT);
  mcp.pullUp(BUTTON3_PIN, HIGH);
  mcp.pinMode(BUTTON4_PIN, INPUT);
  mcp.pullUp(BUTTON4_PIN, HIGH);
  mcp.pinMode(BUTTON5_PIN, INPUT);
  mcp.pullUp(BUTTON5_PIN, HIGH);
  mcp.pinMode(BUTTON6_PIN, INPUT);
  mcp.pullUp(BUTTON6_PIN, HIGH);
  mcp.pinMode(BUTTON7_PIN, INPUT);
  mcp.pullUp(BUTTON7_PIN, HIGH);
  mcp.pinMode(BUTTON8_PIN, INPUT);
  mcp.pullUp(BUTTON8_PIN, HIGH);
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::handleLoop() {

  if (Serial.available()) {
    char val = Serial.read();
    
    if (val == 'u') { // up
    } else if (val == 'd') { // down
    } else if (val == 'l') { // left
      voiceNumber--;
      if (voiceNumber<0) 
        voiceNumber = 4;
      updateVoiceModel();
    } else if (val == 'r') { // right
      voiceNumber++;
      if (voiceNumber>4) 
        voiceNumber = 0;
      updateVoiceModel();
    } else if (val == 'e') {      
    }
  }

  if (!mcp.digitalRead(BUTTON1_PIN)) {
    buttonPressed_f1();
    delay(250);
  }
  if (!mcp.digitalRead(BUTTON2_PIN)) {
    buttonPressed_f2();
    delay(250);
  }
  if (!mcp.digitalRead(BUTTON3_PIN)) {
    buttonPressed_f3();
    delay(250);
  }
  if (!mcp.digitalRead(BUTTON4_PIN)) {
    buttonPressed_f4();
    delay(250);
  }
  if (!mcp.digitalRead(BUTTON5_PIN)) {
    buttonPressed_f5();
    delay(250);
  }
  if (!mcp.digitalRead(BUTTON6_PIN)) {
    buttonPressed_f6();
    delay(250);
  }
  if (!mcp.digitalRead(BUTTON7_PIN)) {
    buttonPressed_f7();
    delay(250);
  }
  if (!mcp.digitalRead(BUTTON8_PIN)) {
    buttonPressed_f8();
    delay(250);
  }
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f1() {
    Serial.println("Button F1 pressed");
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f2() {
    Serial.println("Button F2 pressed");    
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f3() {
    Serial.println("Button F3 pressed");        
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f4() {
    Serial.println("Button F4 pressed");
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f5() {
    Serial.println("Button F5 pressed");
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f6() {
    Serial.println("Button F6 pressed");    
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f7() {
    if (voiceNumber > 0)
      voiceNumber--;
    else
      voiceNumber=0;

  Serial.print("Button F7 pressed. Voice Number: ");
  Serial.println(voiceNumber);

  updateVoiceModel();

  Serial1.begin(500000);
  Serial1.write('r');
  Serial1.write(voiceNumber);
  Serial1.end();
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f8() {
  voiceNumber++;
  if (voiceNumber > 4)
    voiceNumber=4;

  Serial.print("Button F8 pressed. Voice Number: ");
  Serial.println(voiceNumber);

  updateVoiceModel();
  Serial1.begin(500000);

  Serial1.write('r');
  Serial1.write(voiceNumber);
  Serial1.end();
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::updateVoiceModel() {
  delete this->voiceMode->getVoiceModel();
  VoiceModel *voiceModel = new VoiceModel(patchNames[voiceNumber]);  
  voiceMode->updateVoiceModel(voiceModel);
  voiceMode->draw();
}

// ---------------------------------------------------------------------------------------
