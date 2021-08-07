#ifndef XFM2PROGRAM_H
#define XFM2PROGRAM_H

#include "xfm2_operator.h"
#include "xfm2_pitcheg.h"
#include "xfm2_hw.h"

class Xfm2Program {
public:
    Xfm2Program(); // don't use
    Xfm2Program(Xfm2Hw *xfm2Hw);
    ~Xfm2Program();

    Xfm2PitchEnvelopeGenerator *pitchEg;
private:
    Xfm2Hw *xfm2Hw;
    Xfm2Operator *operators;
};

#endif
