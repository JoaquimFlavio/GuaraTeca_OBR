//Uso da HMRobot GuaraTeca_OBR-------------------*

#define funcao OBR
#include <GuaraTeca.h>

//motor 1: portas 2,3 | velocidade: 9
//motor 1: portas 4,5 | velocidade: 10
HRobot robo(2,3,9,4,5,10,100);//define o robo nas portas e define a velocidade em 100%

void setup() {
  Serial.begin(9600);//Iniciamos o monitor serial em 9600

  robo.DefineVelocidade(100, 100);//define a velocidade dos motores 1 e 2
  
  Serial.print("Velocidade motor 1: ");
  Serial.print(robo.AdquiriVelocidade(1));//imprimimos no monitor serial a velocidade do motor 1
  Serial.print("%   |   Velocidade motor 2: ");
  Serial.print(robo.AdquiriVelocidade(2));//imprimimos no monitor serial a velocidade do motor 2
  Serial.println("%");
}

void loop() {
  robo.frente(0.5);//Robo ira para frente por 500ms
  robo.tras(0.5);//Robo ira para tras por 500ms
  robo.direita(0.5);//Robo ira para direita por 500ms
  robo.esquerda(0.5);//Robo ira para esquerda por 500ms
  robo.para(0.5);//Robo ira parar por 500ms
}
