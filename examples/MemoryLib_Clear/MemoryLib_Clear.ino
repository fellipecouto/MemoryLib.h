/*----------------------------------------------------
 Programa : MEMORYLIB_CLEAR
 Descr    : Exemplo de como limpar a EEPROM utilizando
            a biblioteca MemoryLib.h
 Autor    : Fellipe Couto [ http://www.efeitonerd.com.br ]
 Data     : 27/06/2014
 ----------------------------------------------------*/

#include <EEPROM.h> //Inclui a biblioteca da memoria EEPROM
#include <MemoryLib.h> //Inclui a biblioteca para gerenciar a EEPROM com variaveis dos tipos int e long

//Inicia a biblioteca passando como parametros a capacidade da EEPROM em KB e o tipo de variavel
MemoryLib memory(1, 1); //memory(sizeMemory, typeVar) : sizeMemory = KB  /  typeVar = 1=int | 2=long 

void setup() {

  //Escreve zero em todos os enderecos da EEPROM
  for (int address = 0; address <= memory.lastAddress; address++) {
    memory.write(address, 0);
  }

  //Acende o LED do Arduino quando finalizar
  digitalWrite(13, HIGH);
}

void loop(){
}
