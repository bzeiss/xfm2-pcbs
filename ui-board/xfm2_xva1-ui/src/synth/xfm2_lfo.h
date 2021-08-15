#ifndef XFM2LFO_H
#define XFM2LFO_H

#include <Arduino.h>
#include "xfm2_hw.h"

class Xfm2Lfo {
public:
    Xfm2Lfo(); // don't use
    explicit Xfm2Lfo(Xfm2Hw *xfm2Hw);
    ~Xfm2Lfo();
    void setXfm2Hw(Xfm2Hw *xfm2HwParam);

    byte getWave(); // 0 = Triangle, 1 = Square, 2 = Saw up, 3 = Saw down, 4 = Sine, 5 = Random
    byte getSpeed(); // Sets the LFO speed.
    byte getSync(); // 0 = Single, Free running, 1 = Single, Key sync, 2 = Multi, Free running, 3 = Multi, Key sync
    byte getFade(); // Sets the time for the LFO effect to ramp up to the maximum.
    byte getDepthPitch(); // Sets the fixed LFO effect depth applied to pitch (individual operators can receive different values, see PMS).
    byte getDepthAmp(); // Sets the fixed LFO effect depth applied to amplitude (individual operators can receive different values, see AMS).

private:
    Xfm2Hw *xfm2Hw = nullptr;
};

#endif
