#include <Arduino.h>
#include "functionkeys.h"

// ---------------------------------------------------------------------------------------

FunctionKeys::FunctionKeys() {
    
}

// ---------------------------------------------------------------------------------------

FunctionKeys::~FunctionKeys() {
    if (f1)
        free(f1);
    if (f2)
        free(f2);
    if (f3)
        free(f3);
    if (f4)
        free(f4);
    if (f5)
        free(f5);
    if (f6)
        free(f6);
    if (f7)
        free(f7);
    if (f8)
        free(f8);
}