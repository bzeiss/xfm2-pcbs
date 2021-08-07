#include "xfm2.h"
#include <Arduino.h>
#include "XFM2_params.h"

// ---------------------------------------------------------------------------------------

Xfm2::Xfm2(HardwareSerial *serial) {
    this->serial = serial;
    this->serial->begin(500000);

    this->activateFirstUnit();
    this->printLastCommandResult();
    this->loadProgram(0);
    this->printLastCommandResult();
}

// ---------------------------------------------------------------------------------------

Xfm2::~Xfm2() {
    this->serial->end();
}

// ---------------------------------------------------------------------------------------

void Xfm2::updateXfm2SynthModel() {
// parameter 'd' does not seem to work properly with the arduino. The serial buffer has a size of 64 byte and with baud rate 500000, the arduino
// does not empty this buffer quick enough in order for the buffer to be cleared before more bytes arrive. Thus, we need to query each parameter
// through a loop. If you have a solution, let me know, I'd rather get all parameters via a single command...
  for (int i=1; i <= this->maxParameters; i++) {
    byte result = this->getParameter(i);
    Serial.print("Parameter ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(result, DEC);
  }
}

// ---------------------------------------------------------------------------------------

int Xfm2::loadProgram(byte programNumber) {
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

int Xfm2::writeProgram(byte programNumber) {
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

void Xfm2::setParameter(int parameterNumber, byte value) {
  if (parameterNumber < 0)
    return;

  this->serial->write('s');
  
  if (parameterNumber > 254) {
    this->serial->write(255);
    this->serial->write(parameterNumber-255);
  } else {
    this->serial->write(parameterNumber);
  }
  this->serial->write(value); 
  this->serial->flush();
  this->serialDrain();
}

// ---------------------------------------------------------------------------------------

byte Xfm2::getParameter(int parameterNumber) {
  this->lastResult = -1;

  if (parameterNumber < 0)
    return this->lastResult;

  this->serial->write('g');
  if (parameterNumber > 254) {
    this->serial->write(255);
    this->serial->write(parameterNumber-255);
  } else {
    this->serial->write(parameterNumber);
  }
  this->lastResult = readResultByte();

  return this->lastResult;
}

// ---------------------------------------------------------------------------------------

int Xfm2::activateFirstUnit() {
  this->lastResult = -1;
  this->serial->write('1');
  this->lastResult = readResultByte();
  return this->lastResult;
}

// ---------------------------------------------------------------------------------------

int Xfm2::activateSecondUnit() {
  this->lastResult = -1;
  this->serial->write('2');
  this->lastResult = readResultByte();

  return this->lastResult;
}

// ---------------------------------------------------------------------------------------

void Xfm2::initializeEeprom() {
  this->serial->write('$');
  this->serial->flush();
  this->serialDrain();
}

// ---------------------------------------------------------------------------------------

int Xfm2::setFirstUnitMidiChannel(byte channelNumber) {
  this->serial->write('*');
  this->serial->write(10);
  this->serial->write(channelNumber);
  this->lastResult = this->readResultByte();
  return this->lastResult;
}

// ---------------------------------------------------------------------------------------

int Xfm2::setSecondUnitMidiChannel(byte channelNumber) {
  this->serial->write('*');
  this->serial->write(11);
  this->serial->write(channelNumber);
  this->lastResult = this->readResultByte();
  return this->lastResult;
}

// ---------------------------------------------------------------------------------------

int Xfm2::setLayerMode(bool enabled) {
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

Xfm2Program *Xfm2::getSynthModelUnit1() {
  return this->unit1;
}

// ---------------------------------------------------------------------------------------

Xfm2Program *Xfm2::getSynthModelUnit2() {
  return this->unit2;
}

// ---------------------------------------------------------------------------------------

void Xfm2::printLastCommandResult() {
  Serial.print("Last result: ");
  Serial.println(this->lastResult);
}

// ---------------------------------------------------------------------------------------

void Xfm2::serialDrain() {
  while(this->serial->available() > 0) {
    this->serial->read();
  }
}

// ---------------------------------------------------------------------------------------

byte Xfm2::readResultByte() {
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
