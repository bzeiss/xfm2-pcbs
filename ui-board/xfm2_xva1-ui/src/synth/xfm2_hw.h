#ifndef XFM2HW_H
#define XFM2HW_H

#include <Arduino.h>

class Xfm2Hw {
public:
    explicit Xfm2Hw(HardwareSerial *serial);
    ~Xfm2Hw();
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
    void printLastCommandResult() const;
private:
    HardwareSerial *serial;
    byte lastResult;
    byte readResultByte();
    void serialDrain();
    int const maxParameters=394;
};

#endif