#ifndef VOICEDETAILS_H
#define VOICEDETAILS_H

#include "../../ui-element.h"
#include "../../model/voicemodel.h"

class VoiceDetails : UiElement {
public:
  explicit VoiceDetails(VoiceModel *voiceModel);
  virtual ~VoiceDetails();
  void draw() override;
  void updateVoiceModel(VoiceModel *voiceModel);
private:
  VoiceModel *voiceModel;
  static void drawVoiceHead();
  void drawPatchName();
};

#endif