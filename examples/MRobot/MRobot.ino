//Copyright 2017 Joaquim Flávio Almeida Quirino Gomes, Dêmis Carlos ----*
//Fonseca Gomes, Marcos Dias da Conceição e Diego de Castro Rodrigues---*
//----------------------------------------------------------------------*
//Este arquivo é parte da Biblioteca de Funções GuaráTeca---------------*
//A GuaráTeca é um software livre; você pode redistribuí-lo e/ou--------* 
//modificá-lo sob os termos da Licença Pública Geral GNU como publicada-*
//pela Fundação do Software Livre (FSF); na versão 3 da Licença,--------*
//ou (a seu critério) qualquer versão posterior.------------------------*
//
//Este programa é distribuído na esperança de que possa ser útil,-------* 
//mas SEM NENHUMA GARANTIA; sem uma garantia implícita de ADEQUAÇÃO-----*
//a qualquer MERCADO ou APLICAÇÃO EM PARTICULAR. Veja a-----------------*
//Licença Pública Geral GNU para mais detalhes.-------------------------*
//
//Você deve ter recebido uma cópia da Licença Pública Geral GNU junto---*
//com este programa. Se não, veja <http://www.gnu.org/licenses/>--------*

//Uso da MRobot GuaraTeca_OBR-------------------*
//versao: 1.0---------------------------------*

#define funcao OBR
#include <GuaraTeca.h>

MRobot robo(1, 2, 100);//Definimos motores nas conexoes 1 e 2 e setamos suas velocidades em 100%

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
