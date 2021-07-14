#include "voicemode.h"
#include "../common/functionkeys-ui.h"

// ---------------------------------------------------------------------------------------

VoiceMode::VoiceMode() {
    FunctionKeys *functionKeys = new FunctionKeys();
    functionKeys->f1 = strdup("Send");
    functionKeys->f7 = strdup("Ctrl");
    functionKeys->f8 = strdup("Dir");

    this->functionKeyUi = new FunctionKeysUI(functionKeys);

    this->voiceDetails = new VoiceDetails();
    voiceDetails->setPatchName(strdup("GrandPiano"));
}

// ---------------------------------------------------------------------------------------

void VoiceMode::draw() {
    this->initDraw();
    functionKeyUi->draw();
    voiceDetails->draw();
    this->finishDraw();
}