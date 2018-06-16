/* 
 * Guarateca_OBR *** by *** Guarabots________________
 * 
 * Uso da MRobot, com 2 motores______________________
 * 
 * Autor: Joaquim Flávio A Q Gomes___________________
 * Data: 06/2018_____________________________________
 */

#define funcao OBR
#include <GuaraTeca.h>

/*
 * Motor direito  : porta M3
 * Motor esquerdo : porta M4
 */

MRobot robo(3, 4, 100);//Definimos motores nas conexoes 1 e 2 e setamos suas velocidades em 100%.

void setup() {
  Serial.begin(9600);//Iniciamos o monitor serial em 9600.

  robo.defineVelocidade(90, 90);//Define novamente a velocidade dos motores Dir. e Esq.
  
  Serial.print("Velocidade motor 1: ");
  Serial.print(robo.adquireVMD());//Imprimimos no monitor serial a velocidade do motor Dir.
  Serial.print("%   |   Velocidade motor 2: ");
  Serial.print(robo.adquireVME());//Imprimimos no monitor serial a velocidade do motor Esq.
  Serial.println("%");
}

void loop() {
  robo.frente(0.5);   //Robo ira para frente por 500ms.
  robo.tras(0.5);     //Robo ira para tras por 500ms.
  robo.direita(0.5);  //Robo ira para direita por 500ms.
  robo.esquerda(0.5); //Robo ira para esquerda por 500ms.
  robo.para(0.5);     //Robo ira parar por 500ms.
}
