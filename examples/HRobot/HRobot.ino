/* 
 * Guarateca_OBR *** by *** Guarabots________________
 * 
 * Uso da HMRobot, com 2 motores_____________________
 * 
 * Autor: Joaquim Flávio A Q Gomes___________________
 * Data: 06/2018_____________________________________
 */

#define funcao OBR
#include <GuaraTeca.h>

/*
 * motor Esquerdo -> portas de controle  : 2,3
 *                   porta de velocidade : 9 
 * motor Direito  -> portas de controle  : 4,5
 *                   porta de velocidade : 10   
 */

HRobot robo(2,3,9,4,5,10,100);//define o robo nas portas e define a velocidade em 100%.

void setup() {
  Serial.begin(9600);//Iniciamos o monitor serial em 9600.

  robo.defineVelocidade(100, 100);//Define novamente a velocidade dos motores Dir. e Esq.
  
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
