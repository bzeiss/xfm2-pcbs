#ifndef VOICEDETAILS_H
#define VOICEDETAILS_H

#include "../../ui-element.h"
#include "../../model/voicemodel.h"

class VoiceDetails : UiElement {
public:
    VoiceDetails(VoiceModel *voiceModel);
    void draw() override;
    void updateVoiceModel(VoiceModel *voiceModel);
private:
    VoiceModel *voiceModel;
    void drawVoiceHead();
    void drawPatchName();    
};

#endif