#ifndef VOICEDETAILS_H
#define VOICEDETAILS_H

#include "../../ui-element.h"

class VoiceDetails : UiElement {
public:
    VoiceDetails();
    void draw() override;
    void setPatchName(char *patchName);
private:
    char *patchName;
    void drawVoiceHead();
    void drawPatchName();
};

#endif