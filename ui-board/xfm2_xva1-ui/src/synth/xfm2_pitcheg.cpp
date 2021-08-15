#include "xfm2_pitcheg.h"
#include "xfm2_params.h"


// ---------------------------------------------------------------------------------------

Xfm2PitchEnvelopeGenerator::Xfm2PitchEnvelopeGenerator() = default;

// ---------------------------------------------------------------------------------------

Xfm2PitchEnvelopeGenerator::Xfm2PitchEnvelopeGenerator(Xfm2Hw *xfm2Hw) {
    this->xfm2Hw = xfm2Hw;
}

// ---------------------------------------------------------------------------------------

Xfm2PitchEnvelopeGenerator::~Xfm2PitchEnvelopeGenerator() = default;

// ---------------------------------------------------------------------------------------

void Xfm2PitchEnvelopeGenerator::setXfm2Hw(Xfm2Hw *xfm2HwParam) {
    this->xfm2Hw = xfm2HwParam;
}

// ---------------------------------------------------------------------------------------

byte Xfm2PitchEnvelopeGenerator::getDelay() {
    return xfm2Hw->getParameter(PRM_PITCH_EG_DLY);
}

// ---------------------------------------------------------------------------------------

byte Xfm2PitchEnvelopeGenerator::getL0() {
    return xfm2Hw->getParameter(PRM_PITCH_EG_L0);
}

// ---------------------------------------------------------------------------------------

byte Xfm2PitchEnvelopeGenerator::getL1() {
    return xfm2Hw->getParameter(PRM_PITCH_EG_L1);
}

// ---------------------------------------------------------------------------------------

byte Xfm2PitchEnvelopeGenerator::getL2() {
    return xfm2Hw->getParameter(PRM_PITCH_EG_L2);
}

// ---------------------------------------------------------------------------------------

byte Xfm2PitchEnvelopeGenerator::getL3() {
    return xfm2Hw->getParameter(PRM_PITCH_EG_L3);
}

// ---------------------------------------------------------------------------------------

byte Xfm2PitchEnvelopeGenerator::getL4() {
    return xfm2Hw->getParameter(PRM_PITCH_EG_L4);
}

// ---------------------------------------------------------------------------------------

byte Xfm2PitchEnvelopeGenerator::getL5() {
    return xfm2Hw->getParameter(PRM_PITCH_EG_L5);
}

// ---------------------------------------------------------------------------------------

byte Xfm2PitchEnvelopeGenerator::getR1() {
    return xfm2Hw->getParameter(PRM_PITCH_EG_R1);
}

// ---------------------------------------------------------------------------------------

byte Xfm2PitchEnvelopeGenerator::getR2() {
    return xfm2Hw->getParameter(PRM_PITCH_EG_R2);
}

// ---------------------------------------------------------------------------------------

byte Xfm2PitchEnvelopeGenerator::getR3() {
    return xfm2Hw->getParameter(PRM_PITCH_EG_R3);
}

// ---------------------------------------------------------------------------------------

byte Xfm2PitchEnvelopeGenerator::getR4() {
    return xfm2Hw->getParameter(PRM_PITCH_EG_R4);
}

// ---------------------------------------------------------------------------------------

byte Xfm2PitchEnvelopeGenerator::getR5() {
    return xfm2Hw->getParameter(PRM_PITCH_EG_R5);
}

// ---------------------------------------------------------------------------------------

byte Xfm2PitchEnvelopeGenerator::getRateKey() {
    return xfm2Hw->getParameter(PRM_PITCH_EG_RATEKEY);
}

// ---------------------------------------------------------------------------------------

byte Xfm2PitchEnvelopeGenerator::getRange() {
    return xfm2Hw->getParameter(PRM_PITCH_EG_RANGE);
}

// ---------------------------------------------------------------------------------------

byte Xfm2PitchEnvelopeGenerator::getVelocity() {
    return xfm2Hw->getParameter(PRM_PITCH_EG_VELO);
}

// ---------------------------------------------------------------------------------------
