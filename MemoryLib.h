/*------------------------------------------------------------------------------
  Program  : MemoryLib.h
  Descr    : Library to manage the storage of INT and LONG variables in EEPROM 
  Author   : Fellipe Couto [ http://www.efeitonerd.com.br ]
  GitHub   : https://github.com/fellipecouto/MemoryLib.h
  Date     : 2014-06-27
  ------------------------------------------------------------------------------*/
#ifndef MemoryLib_h
#define MemoryLib_h
#include "Arduino.h"
class MemoryLib {
  public:
    MemoryLib(int sizeMemory, int typeVar);
    void write(int address, long value);
    long read(int address);
    int lastAddress;
  private:
    long stringToLong(String str);
    int _sizeMemory;
    int _typeVar;
};
#endif