#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include "ui-common.h"

class UiElement {
public:
    UiElement();
    ~UiElement();
    virtual void draw() = 0;
protected:
    void initDraw();
    void finishDraw();
};

#endif