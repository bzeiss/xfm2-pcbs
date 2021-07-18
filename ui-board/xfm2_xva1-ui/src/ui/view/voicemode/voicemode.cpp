#include "voicemode.h"
#include "../common/functionkeys-ui.h"

// ---------------------------------------------------------------------------------------

VoiceMode::VoiceMode() {
    this->voiceModel = new VoiceModel("-");
    FunctionKeys *functionKeys = new FunctionKeys();
    functionKeys->f1 = strdup("Send");
    functionKeys->f7 = strdup("Ctrl");
    functionKeys->f8 = strdup("Dir");

    this->functionKeyUi = new FunctionKeysUI(functionKeys);
    this->voiceDetails = new VoiceDetails(voiceModel);
}

// ---------------------------------------------------------------------------------------

void VoiceMode::draw() {
    this->initDraw();
    functionKeyUi->draw();
    voiceDetails->draw();
    this->finishDraw();
}

// ---------------------------------------------------------------------------------------

void VoiceMode::updateVoiceModel(VoiceModel *voiceModel) {
    VoiceModel *oldVoiceModel = this->voiceModel;
    this->voiceModel = voiceModel;
    this->voiceDetails->updateVoiceModel(voiceModel);
    delete oldVoiceModel;
}

// ---------------------------------------------------------------------------------------

VoiceModel *VoiceMode::getVoiceModel() {
    return this->voiceModel;
}