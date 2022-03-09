#include <Arduino.h>
#include "common.h"
#include "ui/ui-common.h"

const char *patchNames[5] = {"GrandPiano", "Arianne", "Dyno E.Pno", "BrasChoral", "Nasty Saw"};

// ---------------------------------------------------------------------------------------

#ifdef __arm__
// should use uinstd.h to define sbrk but Due causes a conflict
extern "C" char* sbrk(int incr);
#else  // __ARM__
extern char *__brkval; // NOLINT(bugprone-reserved-identifier)
#endif  // __arm__

int freeMemory() {
  char top;
#ifdef __arm__
  return &top - reinterpret_cast<char*>(sbrk(0));
#elif defined(CORE_TEENSY) || (ARDUINO > 103 && ARDUINO != 151)
  return &top - __brkval; // NOLINT(cppcoreguidelines-narrowing-conversions)
#else  // __arm__
  return __brkval ? &top - __brkval : &top - __malloc_heap_start;
#endif  // __arm__
}

// ---------------------------------------------------------------------------------------

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
void printFreeMemory() {
  Serial.print("Free memory: ");
  Serial.println(freeMemory());
}
#pragma clang diagnostic pop

// ---------------------------------------------------------------------------------------

void testScreen() {
  u8g2->clearBuffer();                    // clear the internal memory
  u8g2->setFont(u8g2_font_ncenB08_tr);    // choose a suitable font
  u8g2->drawStr(0, 10, "Hello World!");    // write something to the internal memory
  u8g2->sendBuffer();                    // transfer internal memory to the display
}

// ---------------------------------------------------------------------------------------

