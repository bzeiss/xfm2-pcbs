#ifndef CtrlBoard_H
#define CtrlBoard_H

#include <Adafruit_MCP23017.h>

#define BUTTON1_PIN 8
#define BUTTON2_PIN 9
#define BUTTON3_PIN 10
#define BUTTON4_PIN 11
#define BUTTON5_PIN 12
#define BUTTON6_PIN 13
#define BUTTON7_PIN 14
#define BUTTON8_PIN 15

class CtrlBoard {
public:
    void setup();
    void handleLoop();
private:
    void buttonPressed_f1();
    void buttonPressed_f2();
    void buttonPressed_f3();
    void buttonPressed_f4();
    void buttonPressed_f5();
    void buttonPressed_f6();
    void buttonPressed_f7();
    void buttonPressed_f8();
    void buttonPressed_f9();

    Adafruit_MCP23017 mcp;
};

#endif