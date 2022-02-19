/*------------------------------------------------------------------------------
  Program  : MemoryLib.h
  Descr    : Library to manage the storage of INT and LONG variables in EEPROM 
  Author   : Fellipe Couto [ http://www.efeitonerd.com.br ]
  GitHub   : https://github.com/fellipecouto/MemoryLib.h
  Date     : 2014-06-27
  ------------------------------------------------------------------------------*/
#include "Arduino.h"
#include "MemoryLib.h"
#include <EEPROM.h>

MemoryLib::MemoryLib(int sizeMemory, int typeVar) {
  sizeMemory *= 1024;
  _sizeMemory = sizeMemory;
  _typeVar = typeVar;
  if (typeVar == 1) {
    _typeVar = 16;
    lastAddress = (sizeMemory / 2) - 2; //Last address (int) - two positions for one
  } else if (typeVar == 2) {
    _typeVar = 32;
    lastAddress = (sizeMemory / 5) - 2; //Last address (long) - five positions for one
  }
  if (EEPROM.read(sizeMemory - 1) != _typeVar) { //Clear EEPROM - Last address with 16-int ou 32-long
    for (int i = 0; i < sizeMemory; i++) {
      EEPROM.write(i, 0);
    }
    EEPROM.write(sizeMemory - 1, _typeVar);
  }
}

void MemoryLib::write(int address, long value) {
  if (address > lastAddress) return;
  if (_typeVar == 16 && value > 32767) return; //Maximum value for int
  if (_typeVar == 16) { //Multiplies the address value to write to the correct address
    address *= 2;
  } else if (_typeVar == 32) {
    address *= 5;
  }
  if (_typeVar == 16) {
    byte hiByte = highByte(value);
    byte loByte = lowByte(value);
    EEPROM.write(address, hiByte);
    EEPROM.write(address + 1, loByte);
  } else if (_typeVar == 32) {
    String val = "0000000000" + String(value);
    val = val.substring(String(value).length(), 10 + String(value).length());
    EEPROM.write(address, val.substring(0, 2).toInt());
    EEPROM.write(address + 1, val.substring(2, 4).toInt());
    EEPROM.write(address + 2, val.substring(4, 6).toInt());
    EEPROM.write(address + 3, val.substring(6, 8).toInt());
    EEPROM.write(address + 4, val.substring(8, 10).toInt());
  }
}

long MemoryLib::read(int address) {
  if (address > lastAddress) return 0;
  if (_typeVar == 16) { //Multiplies the address value to write to the correct address
    address *= 2;
  } else if (_typeVar == 32) {
    address *= 5;
  }
  if (_typeVar == 16) {
    byte hiByte = EEPROM.read(address);
    byte loByte = EEPROM.read(address + 1);
    return word(hiByte, loByte);
  } else if (_typeVar == 32) {
	//p1 p2 p3 p4 p5 : Ex 101
    //00 00 00 01 01
    String p1 = String(EEPROM.read(address));
    String p2 = String(EEPROM.read(address + 1));
    String p3 = String(EEPROM.read(address + 2));
    String p4 = String(EEPROM.read(address + 3));
    String p5 = String(EEPROM.read(address + 4));
    if (p1.toInt() < 10) p1 = "0" + p1;
    if (p2.toInt() < 10) p2 = "0" + p2;
    if (p3.toInt() < 10) p3 = "0" + p3;
    if (p4.toInt() < 10) p4 = "0" + p4;
    if (p5.toInt() < 10) p5 = "0" + p5;
    long ret = stringToLong(p1 + p2 + p3 + p4 + p5);
    return ret;
  }
}

long MemoryLib::stringToLong(String str) {
  char charArray[str.length() + 1];
  str.toCharArray(charArray, sizeof(charArray));
  return atol(charArray);
}