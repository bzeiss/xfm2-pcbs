#include <Arduino.h>
#include <string.h>
#include "voicemodel.h"

// ---------------------------------------------------------------------------------------

VoiceModel::VoiceModel(const char *voiceName, const byte voiceNumber) {
  this->voiceName = strdup(voiceName);
  this->voiceNumber = voiceNumber;
}

// ---------------------------------------------------------------------------------------

VoiceModel::~VoiceModel() {
  free(this->voiceName);
}

// ---------------------------------------------------------------------------------------

const char *VoiceModel::getVoiceName() {
  return this->voiceName;
}

// ---------------------------------------------------------------------------------------

byte VoiceModel::getVoiceNumber() {
  return this->voiceNumber;
}

// ---------------------------------------------------------------------------------------

void VoiceModel::setVoiceNumber(const byte voiceNumber) {
  this->voiceNumber = voiceNumber;
}
