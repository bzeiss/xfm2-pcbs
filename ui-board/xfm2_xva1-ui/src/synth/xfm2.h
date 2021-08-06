#ifndef XFM2_H
#define XFM2_H

#include <Arduino.h>
#include "xfm2_program.h"

class Xfm2 {
public:
    Xfm2(HardwareSerial *serial);
    ~Xfm2();
    void updateXfm2SynthModel();
    int loadProgram(byte programNumber);
    int writeProgram(byte programNumber);
    void setParameter(int parameterNumber, byte value);
    byte getParameter(int parameterNumber);
    int activateFirstUnit();
    int activateSecondUnit();
    void initializeEeprom();
    int setFirstUnitMidiChannel(byte channelNumber);
    int setSecondUnitMidiChannel(byte channelNumber);
    int setLayerMode(bool enabled);
    Xfm2Program *getSynthModelUnit1();
    Xfm2Program *getSynthModelUnit2();
    void printLastCommandResult();
private:
    HardwareSerial *serial;
    Xfm2Program *unit1;
    Xfm2Program *unit2;
    byte lastResult;
    byte readResultByte();
    void serialDrain();
    int const maxParameters=394;
};

#endif