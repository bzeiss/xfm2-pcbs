#ifndef FunctionKeysUI_H
#define FunctionKeysUI_H

#include <U8g2lib.h>
#include "../model/functionkeys.h"

class FunctionKeysUI {
public:
    FunctionKeysUI(FunctionKeys *functionKeys, U8G2 u8g2);
    void draw();
private:
    FunctionKeys *functionKeys;
    U8G2 *u8g2;
};

#endif