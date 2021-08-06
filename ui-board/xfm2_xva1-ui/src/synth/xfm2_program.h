#ifndef XFM2PROGRAM_H
#define XFM2PROGRAM_H

#include "xfm2_operator.h"

class Xfm2Program {
public:
    Xfm2Program();
    ~Xfm2Program();
private:
    Xfm2Operator *operators;
};

#endif
