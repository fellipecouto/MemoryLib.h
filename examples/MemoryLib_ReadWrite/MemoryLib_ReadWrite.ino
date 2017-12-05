/*------------------------------------------------------------------------
 Programa : MEMORYLIB_READWRITE
 Descr    : Exemplo de como ler e escrever variaveis numericas dos
            tipos int e long na EEPROM utilizando a biblioteca MemoryLib.h
 Autor    : Fellipe Couto  [ http://www.efeitonerd.com.br ]
 Data     : 27/06/2014
 ------------------------------------------------------------------------*/

#include <EEPROM.h> //Inclui a biblioteca da memoria EEPROM
#include <MemoryLib.h> //Inclui a biblioteca para gerenciar a EEPROM com variaveis dos tipos int e long

//Inicia a biblioteca passando como parametros a capacidade da EEPROM em KB e o tipo de variavel
MemoryLib memory(1, 1); //memory(sizeMemory, typeVar) : sizeMemory = KB  /  typeVar = 1=int | 2=long 

void setup() {
  Serial.begin(9600);
  Serial.println("Escrevendo na EEPROM... (Enderecos: 0 a " + String(memory.lastAddress) + ")");

  //Escreve em todos os enderecos da EEPROM. Valores obtidos na leitura da A0: 0 a 1023
  for (int address = 0; address <= memory.lastAddress; address++) {
    int value = analogRead(0);
    memory.write(address, value); //Parametros: Endereco, Valor tipo int/long
  }

  Serial.println("Feito.\n");
  delay(1000);
  Serial.println("Lendo os valores armazenados na EEPROM...");

  //Le os valores armazenados na EEPROM
  for (int address = 0; address <= memory.lastAddress; address++) {
    Serial.print("Endereco: ");
    Serial.print(address);
    Serial.print("\t");
    Serial.print("Valor: ");
    Serial.println(memory.read(address));
    delay(100);
  }

}

void loop() {
}
