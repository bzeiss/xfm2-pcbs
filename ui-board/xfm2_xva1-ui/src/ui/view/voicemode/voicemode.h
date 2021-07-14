#ifndef VOICEMODE_H
#define VOICEMODE_H

#include "../../ui-element.h"
#include "../common/functionkeys-ui.h"
#include "voicedetails.h"

class VoiceMode : public UiElement {
public:
    VoiceMode();
    void draw() override;
private:
    FunctionKeysUI *functionKeyUi;
    VoiceDetails *voiceDetails;
};

#endif