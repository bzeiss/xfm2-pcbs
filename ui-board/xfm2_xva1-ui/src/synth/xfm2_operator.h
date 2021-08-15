#ifndef XFM2OPERATOR_H
#define XFM2OPERATOR_H

#include <Arduino.h>

class Xfm2Operator {
public:
  Xfm2Operator();
  ~Xfm2Operator();
  void setSynthParameter(byte parameter);
  void setOperatorId(byte operatorIdParam);
private:
  bool carrier = false;
  byte feedbackLevel = 0;
  Xfm2Operator *outputOperators{};
  byte operatorId = 0;
};

#endif
