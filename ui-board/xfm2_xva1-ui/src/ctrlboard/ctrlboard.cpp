#include "ctrlboard.h"
#include "../common.h"
#include <Arduino.h>

// ---------------------------------------------------------------------------------------

CtrlBoard::CtrlBoard() {
  mcp.begin();
  initializeFunctionButtons();
  this->xfm2Hw = new Xfm2Hw(&Serial1);
  this->xfm2Unit1 = new Xfm2Program(this->xfm2Hw);
  this->xfm2Unit2 = new Xfm2Program(this->xfm2Hw);
  this->xfm2Hw->loadProgram(0);
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::initializeFunctionButtons() {
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

CtrlBoard::~CtrlBoard() = default;

// ---------------------------------------------------------------------------------------

void CtrlBoard::setVoiceMode(VoiceMode *voiceModeParam) {
  this->voiceMode = voiceModeParam;
  updateVoiceModel();
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::handleLoop() {
  if (Serial.available()) {
    char val = Serial.read(); // NOLINT(cppcoreguidelines-narrowing-conversions)

    switch (val) {
    case 'u': // up
    case 'd': // down
    case 'e': // enter
      break;
    case 'l': // left
      voiceNumber--;
      if (voiceNumber < 0)
        voiceNumber = 4;
      updateVoiceModel();
      break;
    case 'r': // right
      voiceNumber++;
      if (voiceNumber > 4)
        voiceNumber = 0;
      updateVoiceModel();
      break;
    default:break;
    }
  }
  handleFunctioButtons();
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::handleFunctioButtons() {
  if (!mcp.digitalRead(BUTTON1_PIN)) {
    buttonPressed_f1();
    delay(150);
  }
  if (!mcp.digitalRead(BUTTON2_PIN)) {
    buttonPressed_f2();
    delay(150);
  }
  if (!mcp.digitalRead(BUTTON3_PIN)) {
    buttonPressed_f3();
    delay(150);
  }
  if (!mcp.digitalRead(BUTTON4_PIN)) {
    buttonPressed_f4();
    delay(150);
  }
  if (!mcp.digitalRead(BUTTON5_PIN)) {
    buttonPressed_f5();
    delay(150);
  }
  if (!mcp.digitalRead(BUTTON6_PIN)) {
    buttonPressed_f6();
    delay(150);
  }
  if (!mcp.digitalRead(BUTTON7_PIN)) {
    buttonPressed_f7();
    delay(150);
  }
  if (!mcp.digitalRead(BUTTON8_PIN)) {
    buttonPressed_f8();
    delay(150);
  }
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f1() {
  Serial.println("Button F1 pressed: Pitch EG Delay");
  int pitchEgDelay = xfm2Unit1->pitchEg->getDelay();
  Serial.println(pitchEgDelay);
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f2() {
  Serial.println("Button F2 pressed: Pitch EG L0");
  int l0 = xfm2Unit1->pitchEg->getL0();
  Serial.println(l0);
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f3() { // NOLINT(readability-convert-member-functions-to-static)
  Serial.println("Button F3 pressed");
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f4() {
  Serial.println("Button F4 pressed: activate first unit");
  xfm2Hw->activateFirstUnit();
  xfm2Hw->printLastCommandResult();
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f5() {
  Serial.println("Button F5 pressed: loading program 4");
  xfm2Hw->loadProgram(4);
  xfm2Hw->printLastCommandResult();
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f6() {
  Serial.println("Button F6 pressed. Reading all parameters");
  xfm2Hw->updateXfm2SynthModel();
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f7() {
  if (voiceNumber > 0)
    voiceNumber--;
  else
    voiceNumber = 0;

  Serial.print("Button F7 pressed. Voice Number: ");
  Serial.println(voiceNumber);

  xfm2Hw->loadProgram(voiceNumber);
  updateVoiceModel();
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f8() {
  voiceNumber++;
  if (voiceNumber > 127)
    voiceNumber = 127;

  Serial.print("Button F8 pressed. Voice Number: ");
  Serial.println(voiceNumber);

  xfm2Hw->loadProgram(voiceNumber);
  updateVoiceModel();
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::updateVoiceModel() {
  delete this->voiceMode->getVoiceModel();
//  auto *voiceModel = new VoiceModel(patchNames[voiceNumber]);
  char *name = xfm2Hw->readXva1Name();

//  Serial.print("name: ");
//  Serial.println(name);

//  xfm2Hw->dump();
//  auto *voiceModel = new VoiceModel(patchNames[voiceNumber % 4]);

  auto *voiceModel = new VoiceModel(name, voiceNumber);
  free(name);
  voiceMode->updateVoiceModel(voiceModel);
  voiceMode->draw();
}

// ---------------------------------------------------------------------------------------
