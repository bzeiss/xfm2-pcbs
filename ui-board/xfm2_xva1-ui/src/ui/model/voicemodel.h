#ifndef VoiceModel_H
#define VoiceModel_H

class VoiceModel {
public:
  VoiceModel(const char *voiceName, const byte voiceNumber);
  ~VoiceModel();
  const char *getVoiceName();
  byte getVoiceNumber();
  void setVoiceNumber(const byte voiceNumber);
private:
  char *voiceName = nullptr;
  byte voiceNumber;
};

#endif