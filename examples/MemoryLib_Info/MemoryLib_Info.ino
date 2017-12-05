/*----------------------------------------------------------
 Programa : MEMORYLIB_INFO
 Descr    : Informacoes adicionais da biblioteca MemoryLib.h
 Autor    : Fellipe Couto [ http://www.efeitonerd.com.br ]
 Data     : 27/06/2014
 ----------------------------------------------------------*/

#include <EEPROM.h> //Inclui a biblioteca da memoria EEPROM
#include <MemoryLib.h> //Inclui a biblioteca para gerenciar a EEPROM com variaveis dos tipos int e long

int sizeMemory = 1; //KB
int typeVar = 2; //1=int | 2=long

//Inicia a biblioteca passando como parametros a capacidade da EEPROM em KB e o tipo de variavel
MemoryLib memory(sizeMemory, typeVar); //sizeMemory = KB  /  typeVar = 1=int | 2=long

void setup() {
  Serial.begin(9600);
  Serial.println("- BIBLIOTECA -");
  Serial.println("MemoryLib.h\n");

  Serial.println("- TIPO INT -");
  Serial.println("Valor maximo: 32767\n");
  Serial.println("- TIPO LONG -");
  Serial.println("Valor maximo: 2147483647\n\n");

  Serial.println("- INFORMACOES -");
  Serial.println("Ultimo endereco da EEPROM 1 Kb e tipo INT: 510");
  Serial.println("Ultimo endereco da EEPROM 1 Kb e tipo LONG: 202\n");
  Serial.println("Ultimo endereco da EEPROM 4 Kb e tipo INT: 2046");
  Serial.println("Ultimo endereco da EEPROM 4 Kb e tipo LONG: 817\n\n");

  Serial.println("- CONFIGURACAO DESTA EEPROM -");
  Serial.print("Capacidade: ");
  Serial.print(sizeMemory);
  Serial.println(" Kb");
  Serial.print("Tipo: ");
  if (typeVar == 1) {
    Serial.println("INT");
  } else if (typeVar == 2) {
    Serial.println("LONG");
  }
  Serial.print("Ultimo endereco: ");
  Serial.println(memory.lastAddress);

}

void loop() {
}
