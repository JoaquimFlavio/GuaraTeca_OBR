//Pisca-pisca GuaraTeca_OBR-------------------*

#define funcao OBR
#include <GuaraTeca.h>

Led led(7);//Led conectado ao pino 7 do Arduino

void setup() {}

void loop() {
  led.liga(100);//Liga o LED e espera 100 mls
  led.desliga(100);//Desliga o LED e espera 100 mls
}
