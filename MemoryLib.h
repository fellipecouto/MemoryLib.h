/*----------------------------------------------------------
 Programa : MEMORYLIB
 Descr    : Biblioteca para gerenciar o armazenamento de
            variaveis dos tipos INT e LONG na memoria EEPROM
 Autor    : Fellipe Couto [ http://www.efeitonerd.com.br ]
 Data     : 27/06/2014
 ----------------------------------------------------------*/
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