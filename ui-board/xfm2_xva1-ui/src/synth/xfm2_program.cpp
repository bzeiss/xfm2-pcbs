#include "xfm2_program.h"

// ---------------------------------------------------------------------------------------

Xfm2Program::Xfm2Program() = default;

// ---------------------------------------------------------------------------------------

Xfm2Program::Xfm2Program(Xfm2Hw *xfm2Hw) {
  this->xfm2Hw = xfm2Hw;
  this->pitchEg = new Xfm2PitchEnvelopeGenerator(this->xfm2Hw);

  this->operators = new Xfm2Operator[6];
  operators[0].setOperatorId(1);
  operators[1].setOperatorId(2);
  operators[2].setOperatorId(3);
  operators[3].setOperatorId(4);
  operators[4].setOperatorId(5);
  operators[5].setOperatorId(6);
}

// ---------------------------------------------------------------------------------------

Xfm2Program::~Xfm2Program() {
  delete this->operators;
  delete this->pitchEg;
}

// ---------------------------------------------------------------------------------------
