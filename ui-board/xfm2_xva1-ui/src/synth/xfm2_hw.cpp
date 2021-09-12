#include <Arduino.h>
#include "xfm2_hw.h"

// ---------------------------------------------------------------------------------------

Xfm2Hw::Xfm2Hw(HardwareSerial *serial) {
  Serial.println("[Xfm2Hw] init...");
  this->serial = serial;
  this->serial->begin(500000);
  this->serial->setTimeout(500);

  // this->activateFirstUnit();
  // this->printLastCommandResult();
  // this->loadProgram(0);
  // this->printLastCommandResult();
}

// ---------------------------------------------------------------------------------------

Xfm2Hw::~Xfm2Hw() {
  this->serial->end();
}

// ---------------------------------------------------------------------------------------

void Xfm2Hw::updateXfm2SynthModel() {
// parameter 'd' does not seem to work properly with the arduino. The serial buffer has a size of 64 byte and with baud rate 500000, the arduino
// does not empty this buffer quick enough in order for the buffer to be cleared before more bytes arrive. Thus, we need to query each parameter
// through a loop. If you have a solution, let me know, I'd rather get all parameters via a single command...
  for (int i = 1; i <= this->maxParameters; i++) {
    byte result = this->getParameter(i);
    Serial.print("Parameter ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(result, DEC);
  }
}

// ---------------------------------------------------------------------------------------

void Xfm2Hw::dump() {
  char buffer[512];
  memset(buffer, 0, sizeof(buffer));
  this->serial->write('d');

  for (int i = 0; i < 512; i++) {
    buffer[i] = this->readResultByte();
  }

//  if (this->serial->available() > 0) {
//    this->serial->readBytes(buffer, 512);
//  }

//  for (int i = 0; i < 512; i++) {
//    if (this->serial->available() > 0) {
//      buffer[i] = (char) this->serial->read();
//      Serial.print(buffer[i]);
//    }
//  }
  Serial.println(buffer);
  Serial.println();
}

// ---------------------------------------------------------------------------------------

int Xfm2Hw::loadProgram(byte programNumber) {
  Serial.println("[Xfm2Hw] load program...");

  this->lastResult = -1;

  if (programNumber < 0)
    return this->lastResult;
  if (programNumber > 127)
    return this->lastResult;

  this->serial->write('r');
  this->serial->write(programNumber);
  this->lastResult = readResultByte();

  return this->lastResult;
}

// ---------------------------------------------------------------------------------------

int Xfm2Hw::writeProgram(byte programNumber) {
  this->lastResult = -1;

  if (programNumber < 0)
    return this->lastResult;
  if (programNumber > 127)
    return this->lastResult;

  this->serial->write('w');
  this->serial->write(programNumber);
  this->lastResult = readResultByte();

  return this->lastResult;
}

// ---------------------------------------------------------------------------------------

void Xfm2Hw::setParameter(int parameterNumber, byte value) {
  if (parameterNumber < 0)
    return;

  this->serial->write('s');

  if (parameterNumber > 254) {
    this->serial->write(255);
    this->serial->write(parameterNumber - 255);
  } else {
    this->serial->write(parameterNumber);
  }
  this->serial->write(value);
  this->serial->flush();
  this->serialDrain();
}

// ---------------------------------------------------------------------------------------

byte Xfm2Hw::getParameter(int parameterNumber) {
  this->lastResult = -1;

  if (parameterNumber < 0)
    return this->lastResult;

  this->serial->write('g');
  if (parameterNumber > 254) {
    this->serial->write(255);
    this->serial->write(parameterNumber - 255);
  } else {
    this->serial->write(parameterNumber);
  }
  this->lastResult = readResultByte();

  return this->lastResult;
}

// ---------------------------------------------------------------------------------------

int Xfm2Hw::activateFirstUnit() {
  this->lastResult = -1;
  this->serial->write('1');
  this->lastResult = readResultByte();
  return this->lastResult;
}

// ---------------------------------------------------------------------------------------

int Xfm2Hw::activateSecondUnit() {
  this->lastResult = -1;
  this->serial->write('2');
  this->lastResult = readResultByte();

  return this->lastResult;
}

// ---------------------------------------------------------------------------------------

void Xfm2Hw::initializeEeprom() {
  this->serial->write('$');
  this->serial->flush();
  this->serialDrain();
}

// ---------------------------------------------------------------------------------------

int Xfm2Hw::setFirstUnitMidiChannel(byte channelNumber) {
  this->serial->write('*');
  this->serial->write(10);
  this->serial->write(channelNumber);
  this->lastResult = this->readResultByte();
  return this->lastResult;
}

// ---------------------------------------------------------------------------------------

int Xfm2Hw::setSecondUnitMidiChannel(byte channelNumber) {
  this->serial->write('*');
  this->serial->write(11);
  this->serial->write(channelNumber);
  this->lastResult = this->readResultByte();
  return this->lastResult;
}

// ---------------------------------------------------------------------------------------

int Xfm2Hw::setLayerMode(bool enabled) {
  this->lastResult = -1;

  this->serial->write('*');
  this->serial->write(12);
  if (enabled) {
    this->serial->write(1);
  } else {
    this->serial->write(0);
  }
  this->lastResult = readResultByte();

  return this->lastResult;
}

// ---------------------------------------------------------------------------------------

void Xfm2Hw::printLastCommandResult() const {
  Serial.print("Last result: ");
  Serial.println(this->lastResult);
}

// ---------------------------------------------------------------------------------------

void Xfm2Hw::serialDrain() {
  while (this->serial->available() > 0) {
    this->serial->read();
  }
}

// ---------------------------------------------------------------------------------------

byte Xfm2Hw::readResultByte() {
  // this is blocking code. need to do this differently.
  while (this->serial->available() <= 0) {
    // wait for buffer to fill
  }
  if (this->serial->available() > 0) {
    byte result = this->serial->read();
    return result;
  }
  return -1;
}

// ---------------------------------------------------------------------------------------

char *Xfm2Hw::readXva1Name() {
  char buffer[24];
  memset(buffer, 0, sizeof(buffer));
  for (int i = 0; i < 24; i++) {
    buffer[i] = (char) this->getParameter(479 + i);
  }

  int numChars;
  for (int i = 23; i >= 0; i--) {
    if (buffer[i] != ' ') {
      numChars = i + 1;
      break;
    }
  }

  //Serial.println(buffer);

  char *name = (char *) malloc(numChars + 1);
  memset(name, 0, numChars + 1);
  memcpy(name, buffer, numChars);
  name[numChars + 1] = '\0';

  //Serial.println(name);

  return name;

  //  this->serial->write('g');
//  this->serial->write(480);
//  for (int i = 0; i < 24; i++) {
//    if (this->serial->available() > 0) {
//      char ch = (char) this->serial->read();
//      Serial.print(ch);
//      name[i] = ch;
//    }
//  }
//  Serial.println();
//  this->serial->write('d');
//  if (this->serial->available() > 0) {
//    this->serial->readBytes(buffer, 512);
//    memcpy(name, &buffer[480], 24);
//  }
}