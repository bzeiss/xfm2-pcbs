#ifndef XFM2_H
#define XFM2_H

#include <Arduino.h>

class Xfm2 {
public:
    Xfm2(HardwareSerial *serial);
    ~Xfm2();
    void loadProgram(int programNumber);
    void writeProgram();
    void setParameter(int parameterNumber, int value);
    void getParameter(int parameterNumber);
    void activateFirstUnit();
    void activateSecondUnit();
    void initializeEeprom();
    void setFirstUnitMidiChannel(int channelNumber);
    void setSecondUnitMidiChannel(int channelNumber);
    void setLayerMode(bool enabled);

private:
    HardwareSerial *serial;
};


#endif