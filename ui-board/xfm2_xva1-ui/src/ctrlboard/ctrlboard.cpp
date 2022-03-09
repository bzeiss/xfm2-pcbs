#include "ctrlboard.h"
#include "../common.h"
#include <Arduino.h>

// ---------------------------------------------------------------------------------------

CtrlBoard::CtrlBoard() {
  mcp_functionkeys.begin_I2C(MCP_FUNCTION_KEYS_ADDRESS);
  mcp_datapad.begin_I2C(MCP_DATAPAD_ADDRESS);
  mcp_modekeys.begin_I2C(MCP_MODE_KEYS_ADDRESS);
  mcp_numpad.begin_I2C(MCP_NUMPAD_ADDRESS);
  initializeFunctionButtons();
  initializeDatapadButtons();
  initializeNumpadButtons();
  initializeModeButtons();
  this->xfm2Hw = new Xfm2Hw(&Serial1);
  this->xfm2Unit1 = new Xfm2Program(this->xfm2Hw);
  this->xfm2Unit2 = new Xfm2Program(this->xfm2Hw);
  this->xfm2Hw->loadProgram(0);
}

// ---------------------------------------------------------------------------------------

CtrlBoard::~CtrlBoard() = default;

// ---------------------------------------------------------------------------------------

void CtrlBoard::initializeFunctionButtons() {
  mcp_functionkeys.pinMode(BUTTON_FK_SHIFT, INPUT_PULLUP);
  mcp_functionkeys.pinMode(BUTTON_FK_F1, INPUT_PULLUP);
  mcp_functionkeys.pinMode(BUTTON_FK_F2, INPUT_PULLUP);
  mcp_functionkeys.pinMode(BUTTON_FK_F3, INPUT_PULLUP);
  mcp_functionkeys.pinMode(BUTTON_FK_F4, INPUT_PULLUP);
  mcp_functionkeys.pinMode(BUTTON_FK_F5, INPUT_PULLUP);
  mcp_functionkeys.pinMode(BUTTON_FK_F6, INPUT_PULLUP);
  mcp_functionkeys.pinMode(BUTTON_FK_F7, INPUT_PULLUP);
  mcp_functionkeys.pinMode(BUTTON_FK_F8, INPUT_PULLUP);
  mcp_functionkeys.pinMode(BUTTON_FK_EXIT, INPUT_PULLUP);
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::initializeDatapadButtons() {
  mcp_datapad.pinMode(BUTTON_DPAD_UP, INPUT_PULLUP);
  mcp_datapad.pinMode(BUTTON_DPAD_DOWN, INPUT_PULLUP);
  mcp_datapad.pinMode(BUTTON_DPAD_LEFT, INPUT_PULLUP);
  mcp_datapad.pinMode(BUTTON_DPAD_RIGHT, INPUT_PULLUP);
  mcp_datapad.pinMode(BUTTON_DPAD_ELEMENT, INPUT_PULLUP);
  mcp_datapad.pinMode(BUTTON_DPAD_JUMP, INPUT_PULLUP);
  mcp_datapad.pinMode(BUTTON_DPAD_NO, INPUT_PULLUP);
  mcp_datapad.pinMode(BUTTON_DPAD_OPERATOR, INPUT_PULLUP);
  mcp_datapad.pinMode(BUTTON_DPAD_PAGE_NEXT, INPUT_PULLUP);
  mcp_datapad.pinMode(BUTTON_DPAD_PAGE_PREV, INPUT_PULLUP);
  mcp_datapad.pinMode(BUTTON_DPAD_SELECT, INPUT_PULLUP);
  mcp_datapad.pinMode(BUTTON_DPAD_YES, INPUT_PULLUP);
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::initializeNumpadButtons() {
  mcp_numpad.pinMode(BUTTON_NUMPAD_0, INPUT_PULLUP);
  mcp_numpad.pinMode(BUTTON_NUMPAD_1, INPUT_PULLUP);
  mcp_numpad.pinMode(BUTTON_NUMPAD_2, INPUT_PULLUP);
  mcp_numpad.pinMode(BUTTON_NUMPAD_3, INPUT_PULLUP);
  mcp_numpad.pinMode(BUTTON_NUMPAD_4, INPUT_PULLUP);
  mcp_numpad.pinMode(BUTTON_NUMPAD_5, INPUT_PULLUP);
  mcp_numpad.pinMode(BUTTON_NUMPAD_6, INPUT_PULLUP);
  mcp_numpad.pinMode(BUTTON_NUMPAD_7, INPUT_PULLUP);
  mcp_numpad.pinMode(BUTTON_NUMPAD_8, INPUT_PULLUP);
  mcp_numpad.pinMode(BUTTON_NUMPAD_9, INPUT_PULLUP);
  mcp_numpad.pinMode(BUTTON_NUMPAD_ENTER, INPUT_PULLUP);
  mcp_numpad.pinMode(BUTTON_NUMPAD_SIGN, INPUT_PULLUP);
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::initializeModeButtons() {
  mcp_modekeys.pinMode(BUTTON_MD_UTILITY, INPUT_PULLUP);
  mcp_modekeys.pinMode(BUTTON_MD_COPY, INPUT_PULLUP);
  mcp_modekeys.pinMode(BUTTON_MD_EDIT, INPUT_PULLUP);
  mcp_modekeys.pinMode(BUTTON_MD_EF_BYPASS, INPUT_PULLUP);
  mcp_modekeys.pinMode(BUTTON_MD_MEMORY, INPUT_PULLUP);
  mcp_modekeys.pinMode(BUTTON_MD_MULTI, INPUT_PULLUP);
  mcp_modekeys.pinMode(BUTTON_MD_VOICE, INPUT_PULLUP);
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::setVoiceMode(VoiceMode *voiceModeParam) {
  this->voiceMode = voiceModeParam;
  updateVoiceModel();
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::handleLoop() {
// processing ui
//  if (Serial.available()) {
//    char val = Serial.read(); // NOLINT(cppcoreguidelines-narrowing-conversions)
//
//    switch (val) {
//    case 'u': // up
//    case 'd': // down
//    case 'e': // enter
//      break;
//    case 'l': // left
//      voiceNumber--;
//      if (voiceNumber < 0)
//        voiceNumber = 4;
//      updateVoiceModel();
//      break;
//    case 'r': // right
//      voiceNumber++;
//      if (voiceNumber > 4)
//        voiceNumber = 0;
//      updateVoiceModel();
//      break;
//    default:break;
//    }
//  }
  handleFunctionButtons();
  handleDatapadButtons();
  handleNumpadButtons();
  handleModeButtons();
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::handleFunctionButtons() {
  if (!mcp_functionkeys.digitalRead(BUTTON_FK_SHIFT)) {
    buttonPressed_shift();
    delay(150);
  }
  if (!mcp_functionkeys.digitalRead(BUTTON_FK_F1)) {
    buttonPressed_f1();
    delay(150);
  }
  if (!mcp_functionkeys.digitalRead(BUTTON_FK_F2)) {
    buttonPressed_f2();
    delay(150);
  }
  if (!mcp_functionkeys.digitalRead(BUTTON_FK_F3)) {
    buttonPressed_f3();
    delay(150);
  }
  if (!mcp_functionkeys.digitalRead(BUTTON_FK_F4)) {
    buttonPressed_f4();
    delay(150);
  }
  if (!mcp_functionkeys.digitalRead(BUTTON_FK_F5)) {
    buttonPressed_f5();
    delay(150);
  }
  if (!mcp_functionkeys.digitalRead(BUTTON_FK_F6)) {
    buttonPressed_f6();
    delay(150);
  }
  if (!mcp_functionkeys.digitalRead(BUTTON_FK_F7)) {
    buttonPressed_f7();
    delay(150);
  }
  if (!mcp_functionkeys.digitalRead(BUTTON_FK_F8)) {
    buttonPressed_f8();
    delay(150);
  }
  if (!mcp_functionkeys.digitalRead(BUTTON_FK_EXIT)) {
    buttonPressed_exit();
    delay(150);
  }
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::handleDatapadButtons() {
  if (!mcp_datapad.digitalRead(BUTTON_DPAD_DOWN)) {
    Serial.println("Down");
    delay(150);
  }
  if (!mcp_datapad.digitalRead(BUTTON_DPAD_UP)) {
    Serial.println("Up");
    delay(150);
  }
  if (!mcp_datapad.digitalRead(BUTTON_DPAD_LEFT)) {
    Serial.println("Left");
    delay(150);
  }
  if (!mcp_datapad.digitalRead(BUTTON_DPAD_RIGHT)) {
    Serial.println("Right");
    delay(150);
  }
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::handleNumpadButtons() {
  if (!mcp_numpad.digitalRead(BUTTON_NUMPAD_ENTER)) {
    Serial.println("Enter");
    delay(150);
  }

}

// ---------------------------------------------------------------------------------------

void CtrlBoard::handleModeButtons() {
  if (!mcp_modekeys.digitalRead(BUTTON_MD_VOICE)) {
    Serial.println("Voice");
    delay(150);
  }
  if (!mcp_modekeys.digitalRead(BUTTON_MD_UTILITY)) {
    Serial.println("Utility");
    delay(150);
  }

}


// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_shift() {
  Serial.println("Button Shift pressed.");
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f1() {
  Serial.println("Button F1 pressed.");
//  Serial.println("Button F1 pressed: Pitch EG Delay");
//  int pitchEgDelay = xfm2Unit1->pitchEg->getDelay();
//  Serial.println(pitchEgDelay);
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f2() {
  Serial.println("Button F2 pressed.");
//  Serial.println("Button F2 pressed: Pitch EG L0");
//  int l0 = xfm2Unit1->pitchEg->getL0();
//  Serial.println(l0);
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f3() { // NOLINT(readability-convert-member-functions-to-static)
  Serial.println("Button F3 pressed.");
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f4() {
  Serial.println("Button F4 pressed.");
//  Serial.println("Button F4 pressed: activate first unit");
//  xfm2Hw->activateFirstUnit();
//  xfm2Hw->printLastCommandResult();
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f5() {
  Serial.println("Button F5 pressed.");
//  Serial.println("Button F5 pressed: loading program 4");
//  xfm2Hw->loadProgram(4);
//  xfm2Hw->printLastCommandResult();
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f6() {
  Serial.println("Button F6 pressed.");
//  Serial.println("Button F6 pressed. Reading all parameters");
//  xfm2Hw->updateXfm2SynthModel();
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f7() {
  Serial.println("Button F7 pressed.");

//  if (voiceNumber > 0)
//    voiceNumber--;
//  else
//    voiceNumber = 0;
//
//  Serial.print("Button F7 pressed. Voice Number: ");
//  Serial.println(voiceNumber);
//
//  xfm2Hw->loadProgram(voiceNumber);
//  updateVoiceModel();
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_f8() {
  Serial.println("Button F8 pressed.");

//  voiceNumber++;
//  if (voiceNumber > 127)
//    voiceNumber = 127;
//
//  Serial.print("Button F8 pressed. Voice Number: ");
//  Serial.println(voiceNumber);
//
//  xfm2Hw->loadProgram(voiceNumber);
//  updateVoiceModel();
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::buttonPressed_exit() {
  Serial.println("Button Exit pressed.");
}

// ---------------------------------------------------------------------------------------

void CtrlBoard::updateVoiceModel() {
  delete this->voiceMode->getVoiceModel();
//  auto *voiceModel = new VoiceModel(patchNames[voiceNumber], 1); // temp: ohne serial
  char *name = xfm2Hw->readXva1Name(); // --> mit hardware

//  Serial.print("name: ");
//  Serial.println(name);

//  xfm2Hw->dump();
//  auto *voiceModel = new VoiceModel(patchNames[voiceNumber % 4]);

  auto *voiceModel = new VoiceModel(name, voiceNumber); // --> mit hardware
  free(name); // --> mit hardware
  voiceMode->updateVoiceModel(voiceModel);
  voiceMode->draw();
}

// ---------------------------------------------------------------------------------------
