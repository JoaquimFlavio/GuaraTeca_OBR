/* 
 * Guarateca_OBR *** by *** Guarabots________________
 * 
 * Uso dos sensores de: 
 *                      -> Refletancia.
 *                      -> Cor.
 *                      -> Ultrassonico.
 *                      -> Giroscopio.
 * 
 * Autor: Joaquim Flávio A Q Gomes___________________
 * Data: 06/2018_____________________________________
 */

#define funcao OBR
#include <GuaraTeca.h>

/*
 * sensor de refletancia na porta: A0
 * Sensor Giroscopio na interface I2C: SCL = A5
 *                                     SDA = A4
 * Sensor Ultrassonico nas portas: TrigPin = A1                                   
 *                                 EchoPin = A2
 * Sensor de cor nas portas: out = 10 
 *                           S0  = 9
 *                           S1  = 8
 *                           S2  = 7
 *                           S3  = 6
 *                           
 * !!!Atenção!!!
 * Giroscopio por padrao estará no endereco 0x68
 * caso ocorrao erros, substitua por 1 o parametro 
 * da funçao "Giroscopio.inicia()".
 */
 
Sensor Refletancia(A0);
Sensor Cor(10,9,8,7,6);
Sensor Ultrassonico(A1, A2); 
Sensor Giroscopio;

void setup() {
  Serial.begin(9600);//Define o serial monitor em 9600.
  Giroscopio.inicia();//Inicia o sensor giroscopio/acelerometro, o unico que necessita ser iniciado!
}

void loop() {
  Serial.print("Sensor de luz: ");       Serial.println(Refletancia.luz());
  Serial.print("Sensor de cor: ");       Serial.println(Cor.cor());
  Serial.print("Sensor de distancia: "); Serial.println(Ultrassonico.distancia());
  Serial.print("Sensor de posicao: ");   Serial.println(Ultrassonico.distancia());
  Serial.println("_____________________________________________________________");
}
