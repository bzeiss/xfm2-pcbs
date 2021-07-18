#ifndef FunctionKeysUI_H
#define FunctionKeysUI_H

#include <U8g2lib.h>
#include "../../ui-element.h"
#include "../../model/functionkeys.h"

class FunctionKeysUI : public UiElement {
public:
    FunctionKeysUI(FunctionKeys *functionKeys);
    virtual ~FunctionKeysUI();
    void draw();
private:
    FunctionKeys *functionKeys;
};

#endif