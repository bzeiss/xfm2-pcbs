#ifndef XFM2PITCHEG_H
#define XFM2PITCHEG_H

#include <Arduino.h>
#include "xfm2_hw.h"

class Xfm2PitchEnvelopeGenerator {
public:
  Xfm2PitchEnvelopeGenerator(); // don't use
  explicit Xfm2PitchEnvelopeGenerator(Xfm2Hw *xfm2Hw);

  ~Xfm2PitchEnvelopeGenerator();

  void setXfm2Hw(Xfm2Hw *xfm2HwParam);

  // xfm2 pitch eg parameters getter
  byte getDelay(); // delay time before the EG starts
  byte
  getL0(); // Segment final levels for Attack, Decay-1, Decay-2, Sustain, Release-1 and Release-2 stages, respectively. Center value is 128.
  byte getL1();
  byte getL2();
  byte getL3();
  byte getL4();
  byte getL5();
  byte getR1(); // Segment times for Attack, Decay-1, Decay-2, Sustain, Release-1 and Release-2 stages, respectively.
  byte getR2();
  byte getR3();
  byte getR4();
  byte getR5();
  byte getRateKey(); // Sets how the EG times change with the generating MIDI notes.
  byte getRange(); // Defines the Pitch EG range, in octaves.
  byte getVelocity(); // Sets how much the Pitch EG range changes with incoming MIDI velocity, in octaves.

  // xfm2 pitch eg parameters setter
  // ...
private:
  Xfm2Hw *xfm2Hw = nullptr;
};

#endif
