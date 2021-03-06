#ifndef VOICEMODE_H
#define VOICEMODE_H

#include "../../ui-element.h"
#include "../common/functionkeys-ui.h"
#include "voicedetails.h"
#include "../../model/voicemodel.h"

class VoiceMode : public UiElement {
public:
  explicit VoiceMode(VoiceModel *voiceModel);
  virtual ~VoiceMode();
  void draw() override;
  void updateVoiceModel(VoiceModel *voiceModelParam);
  VoiceModel *getVoiceModel();
private:
  FunctionKeysUI *functionKeyUi;
  VoiceDetails *voiceDetails;
  VoiceModel *voiceModel = nullptr;
};

#endif