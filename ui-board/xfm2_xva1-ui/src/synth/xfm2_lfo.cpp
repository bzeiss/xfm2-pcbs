#include "xfm2_lfo.h"

// ---------------------------------------------------------------------------------------

Xfm2Lfo::Xfm2Lfo() = default;

// ---------------------------------------------------------------------------------------

Xfm2Lfo::Xfm2Lfo(Xfm2Hw *xfm2Hw) {
    this->xfm2Hw = xfm2Hw;
}

// ---------------------------------------------------------------------------------------

Xfm2Lfo::~Xfm2Lfo() = default;

// ---------------------------------------------------------------------------------------

void Xfm2Lfo::setXfm2Hw(Xfm2Hw *xfm2HwParam) {
    this->xfm2Hw = xfm2HwParam;
}

// ---------------------------------------------------------------------------------------

byte Xfm2Lfo::getWave() { // NOLINT(readability-convert-member-functions-to-static)
    return 0;
}

// ---------------------------------------------------------------------------------------

byte Xfm2Lfo::getSpeed() { // NOLINT(readability-convert-member-functions-to-static)
    return 0;
}

// ---------------------------------------------------------------------------------------

byte Xfm2Lfo::getSync() { // NOLINT(readability-convert-member-functions-to-static)
    return 0;
}

// ---------------------------------------------------------------------------------------

byte Xfm2Lfo::getFade() { // NOLINT(readability-convert-member-functions-to-static)
    return 0;
}

// ---------------------------------------------------------------------------------------

byte Xfm2Lfo::getDepthPitch() { // NOLINT(readability-convert-member-functions-to-static)
    return 0;
}

// ---------------------------------------------------------------------------------------

byte Xfm2Lfo::getDepthAmp() {  // NOLINT(readability-convert-member-functions-to-static)
    return 0;
}
