#include <Arduino.h>
#include <string.h>
#include "voicemodel.h"

// ---------------------------------------------------------------------------------------

VoiceModel::VoiceModel(const char *voiceName) {
    this->voiceName = strdup(voiceName);
}

// ---------------------------------------------------------------------------------------

VoiceModel::~VoiceModel() {
    free(this->voiceName);
}

// ---------------------------------------------------------------------------------------

const char *VoiceModel::getVoiceName() {
    return this->voiceName;
}

