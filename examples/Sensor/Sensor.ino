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

Sensor Refletancia(A0);
Sensor Cor(10,9,8,7,6);
Sensor Ultrassonico(A1, A2);
Sensor Giroscopio;

void setup() {
  Serial.begin(9600);//Define o serial monitor em 9600
}

void loop() {
  Serial.print("Sensor de luz: ");Serial.println(Refletancia.luz());
  Serial.print("Sensor de cor: ");Serial.println(Cor.cor());
  Serial.print("Sensor de distancia: ");Serial.println(Ultrassonico.distancia());
  Serial.print("Sensor de posicao: ");Serial.println(Ultrassonico.posicao());
  Serial.println("_____________________________________________________________");
}
