#ifndef VoiceModel_H
#define VoiceModel_H

class VoiceModel {
public:
    VoiceModel(const char *voiceName);
    ~VoiceModel();
    const char *getVoiceName();
private:
    char *voiceName = nullptr;
};

#endif