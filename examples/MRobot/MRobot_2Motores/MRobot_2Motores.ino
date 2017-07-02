//Uso da MRobot GuaraTeca_OBR-------------------*

#define funcao OBR
#include <GuaraTeca.h>

MRobot robo(3, 4, 100);//Definimos motores nas conexoes 1 e 2 e setamos suas velocidades em 100%

void setup() {
  Serial.begin(9600);//Iniciamos o monitor serial em 9600

  robo.defineVelocidade(90, 90);//define a velocidade dos motores 1 e 2
  
  Serial.print("Velocidade motor 1: ");
  Serial.print(robo.adquireVelocidade(1));//imprimimos no monitor serial a velocidade do motor 1
  Serial.print("%   |   Velocidade motor 2: ");
  Serial.print(robo.adquireVelocidade(2));//imprimimos no monitor serial a velocidade do motor 2
  Serial.println("%");
}

void loop() {
  robo.frente(1.5);//Robo ira para frente por 500ms
  robo.tras(1.5);//Robo ira para tras por 500ms
  robo.direita(1.5);//Robo ira para direita por 500ms
  robo.esquerda(1.5);//Robo ira para esquerda por 500ms
  robo.para(1.5);//Robo ira parar por 500ms
}
