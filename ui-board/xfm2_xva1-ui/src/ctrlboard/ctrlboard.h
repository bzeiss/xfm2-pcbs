#ifndef CtrlBoard_H
#define CtrlBoard_H

#include <Adafruit_MCP23X17.h>
#include "../ui/view/voicemode/voicemode.h"
#include "../ui/model/voicemodel.h"
#include "../synth/xfm2_hw.h"
#include "../synth/xfm2_program.h"

#define BUTTON_FK_SHIFT 8
#define BUTTON_FK_F1 9
#define BUTTON_FK_F2 10
#define BUTTON_FK_F3 11
#define BUTTON_FK_F4 12
#define BUTTON_FK_F5 13
#define BUTTON_FK_F6 14
#define BUTTON_FK_F7 15
#define BUTTON_FK_F8 0
#define BUTTON_FK_EXIT 1

#define BUTTON_NUMPAD_0 8
#define BUTTON_NUMPAD_1 9
#define BUTTON_NUMPAD_4 10
#define BUTTON_NUMPAD_7 11
#define BUTTON_NUMPAD_SIGN 12
#define BUTTON_NUMPAD_2 13
#define BUTTON_NUMPAD_5 14
#define BUTTON_NUMPAD_8 15
#define BUTTON_NUMPAD_9 4
#define BUTTON_NUMPAD_6 5
#define BUTTON_NUMPAD_3 6
#define BUTTON_NUMPAD_ENTER 7

#define BUTTON_DPAD_LEFT 8
#define BUTTON_DPAD_NO 9
#define BUTTON_DPAD_PAGE_PREV 10
#define BUTTON_DPAD_SELECT 11
#define BUTTON_DPAD_DOWN 12
#define BUTTON_DPAD_UP 13
#define BUTTON_DPAD_PAGE_NEXT 14
#define BUTTON_DPAD_ELEMENT 15
#define BUTTON_DPAD_OPERATOR 4
#define BUTTON_DPAD_JUMP 5
#define BUTTON_DPAD_YES 6
#define BUTTON_DPAD_RIGHT 7

#define BUTTON_MD_EF_BYPASS 8
#define BUTTON_MD_EDIT 9
#define BUTTON_MD_VOICE 10
#define BUTTON_MD_UTILITY 4
#define BUTTON_MD_MEMORY 5
#define BUTTON_MD_MULTI 6
#define BUTTON_MD_COPY 7

#define MCP_NUMPAD_ADDRESS 0x20
#define MCP_DATAPAD_ADDRESS 0x21
#define MCP_FUNCTION_KEYS_ADDRESS 0x24
#define MCP_MODE_KEYS_ADDRESS 0x22
#define BR24T1MF_EEPROM_ADDRESS 0x50

//19:56:12.354 -> I2C device found at address 0x51  !


class CtrlBoard {
public:
  CtrlBoard();
  ~CtrlBoard();
  void setVoiceMode(VoiceMode *voiceModeParam);
  void handleLoop();
private:
  void initializeFunctionButtons();
  void initializeDatapadButtons();
  void initializeNumpadButtons();
  void initializeModeButtons();
  void handleFunctionButtons();
  void handleDatapadButtons();
  void handleNumpadButtons();
  void handleModeButtons();

  void buttonPressed_shift();
  void buttonPressed_f1();
  void buttonPressed_f2();
  void buttonPressed_f3();
  void buttonPressed_f4();
  void buttonPressed_f5();
  void buttonPressed_f6();
  void buttonPressed_f7();
  void buttonPressed_f8();
  void buttonPressed_exit();

  void updateVoiceModel();

  Adafruit_MCP23X17 mcp_numpad;
  Adafruit_MCP23X17 mcp_datapad;
  Adafruit_MCP23X17 mcp_functionkeys;
  Adafruit_MCP23X17 mcp_modekeys;
  int voiceNumber = 0;
  VoiceMode *voiceMode = nullptr;
  Xfm2Hw *xfm2Hw = nullptr;
  Xfm2Program *xfm2Unit1 = nullptr;
  Xfm2Program *xfm2Unit2 = nullptr;
};

#endif