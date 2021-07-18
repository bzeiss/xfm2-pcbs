#include <Arduino.h>
#include <string.h>
#include "voicemodel.h"

VoiceModel::VoiceModel(const char *voiceName) {
    this->voiceName = strdup(voiceName);
}

// ---------------------------------------------------------------------------------------

VoiceModel::~VoiceModel() {
}

// ---------------------------------------------------------------------------------------

const char *VoiceModel::getVoiceName() {
    return this->voiceName;
}

// ---------------------------------------------------------------------------------------
/*
VoiceModel::VoiceModel(const VoiceModel &voiceModel) {
    this->voiceName = voiceModel.voiceName;
}
*/