#include "voicemode.h"
#include "../common/functionkeys-ui.h"

// ---------------------------------------------------------------------------------------

VoiceMode::VoiceMode(VoiceModel *voiceModel) {
    this->voiceModel = voiceModel;
    FunctionKeys *functionKeys = new FunctionKeys();
    functionKeys->f1 = strdup("Send");
    functionKeys->f7 = strdup("Ctrl");
    functionKeys->f8 = strdup("Dir");

    this->functionKeyUi = new FunctionKeysUI(functionKeys);
    this->voiceDetails = new VoiceDetails(voiceModel);
}

VoiceMode::~VoiceMode() {
    delete this->functionKeyUi;
    delete this->voiceDetails;
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
    this->voiceModel = voiceModel;
    this->voiceDetails->updateVoiceModel(voiceModel);
}

// ---------------------------------------------------------------------------------------

VoiceModel *VoiceMode::getVoiceModel() {
    return this->voiceModel;
}