## Sobre a GuaraTeca_OBR

A GuaraTeca é uma sub-biblioteca da biblioteca [Guarateca](https://github.com/JoaquimFlavio/GuaraTeca), focada na programação de robôs, baseadas em Arduino, para a participação na [Olimpiada Brasileira de Robotica - OBR](http://www.obr.org.br/). Reduzindo o tempo de produção e facilitando a compreenção do codigo e totalmente em português.

Esta biblioteca presume o robô do usuário com a seguinte estrutura:

- De 1 a 4 motores DC, através da PonteH ou MotorShield.
- Sensores de refletância.
- Sensores de cor.
- Sensores ultrassônicos.
- Sensores acelerômetros e giroscópios.
- LEDs e demais atuadores simples.

## Instalação

1. Primeiro baixe a biblioteca clicando [aqui](https://codeload.github.com/JoaquimFlavio/GuaraTeca_OBR/zip/1.2.0)
2. Abra a sua IDE do Arduino, clique em ```Sketch > Incluir Biblioteca > Adicionar biblioteca .ZIP```
3. Procure a biblioteca GuaraTeca_OBR baixada em arquivo .ZIP em sua pasta de downloads
4. Pronto, agora a sua biblioteca está instalada e pronta para ser utilizada!

## Utilização

```c++
#define funcao OBR
#include <GuaraTeca.h>

// Inicializa um objeto da classe Led na porta 7
Led led(7);

void setup() {}

void loop() {
  led.liga(100);
  led.desliga(100);
}
```

Para utilizar a biblioteca, em plataforma Windows basta que definamos a função da Guarateca como “OBR”, através de uma constante “funcao”, no sketch presente no IDE do Arduino.

```cpp
#define funcao OBR
#include <GuaraTeca.h>
```

Ao fazermos isso já aplicamos todas as propriedades de compilação ao nosso arquivo principal.
Caso utilize a plataforma Linux, o cabeçalho deverá seguir o seguinte modelo:

```cpp
#include <Wire.h>
#include <LiquidCrystal.h>
#include <GuaraTeca_MotorShield.h>
#include <GuaraTeca_SensorCor.h>
#include <GuaraTeca_SensorUltrassonico.h>
#include <GuaraTeca_Bluethoth.h>
#include <GuaraTeca_TelaCristalLiquido.h>
#include <GuaraTeca_SensorRefletancia.h>
#include <GuaraTeca_SensorDHT.h>
#include <GuaraTeca_SensorGiroscopioAcelerometro.h>
#include <GuaraTeca_Buzzer.h>
#include <GuaraTeca_SensorChuva.h>
#include <GuaraTeca_Servo.h>
#include <GuaraTeca_PonteH.h>
#include <GuaraTeca_OBR.h>

#define funcao OBR
#include <GuaraTeca.h>
```

### Motores

#### Declaração  

```cpp
MRobot "nomeObjeto"( "conexao1", "conexao2", "velocidade");
```

Este é o construtor de objetos da classe MRobot que tem como função o controle de motores DC com a utilização da MotorShield da Adafruit. Essa classe permite o uso de até 2 motores DC por objeto, ou seja para o uso de mais motores é necessário declarar outro objeto da classe. O controle de velocidade se dá a partir do último parâmetro sendo medido de 0 à 100.

```cpp
HRobot "nomeObjeto"("1A", "1B", "1V", "2A", "2B", "2V", velocidade);
```

Este é o construtor de objetos da classe “HRobot” que tem como função o controle de motores DC com a utilização de PonteH dupla de qualquer fabricante. Essa classe permite o controle de 2 motores DC.  Os parâmetros a serem passados para a biblioteca são as 6 portas da PonteH dupla, sendo 4 de controle da direção dos motores e 2 de controle de velocidade, de tal modo que os 3 primeiros parâmetros correspondem a 1 dos lados da ponte H na respectiva ordem: pino de controle 1 e 2 do motor seguido do seu pino de velocidade, o mesmo vale para o outro lado, seu último parâmetro corresponde ao controle de velocidade medido de 0 à 100.

#### Movimentação

```cpp
"nomeObjeto"."direção"("tempo");
```

Por padrão para as classes “MRobot” e “HRobot” a movimentação de motores segue o modelo acima. Sendo então o nome do objeto seguido de sua direção no ambiente: “frente”, “tras”, “esquerda”, “direita” ou “para”. Seu tempo de duração é definido em segundos, caso o tempo não seja informado ou seja igual a 0 ele iniciara a ação e a manterá em execução até que algo o interrompa.

#### Auxiliares

```cpp
"nomeObjeto".DefineVelocidade("V1", "V2");
```

Esse método tem como função o controle de velocidade dos motores DC das Classes: “MRobot” e “HRobot”. Os dois parâmetros são obrigatório.

### Sensores

#### Declaração

Sensor “nomeObjeto”.(“pino1”, “pino2”);
Este é o construtor da classe Sensor, que tem a função de realizar o controle de múltiplos sensores (de cor, refletância, ultrassônico, giroscópio e sistemas por eletro condução). O reconhecimento do tipo de sensor se dá pela quantidade de pinos que são passados ao construtor, desta forma temos: Parâmetros vazios: sensor giroscópio. 1 pino: sensor de luz / refletância ou sensor de condução. 2 pinos: sensor ultrassônico. 5 pinos: sensor de cor.

#### Leitura

```cpp
"nomeObjeto"."tipoSensor"();
```

Este método da função Sensor tem como função a leitura dos sensores, basta colocar o nome do objeto e seguido de seu “tipo”, podendo ser do tipo:

luz => para sensores de refletância.
cor => para sensores de cor.
conducao => para sistemas por condução elétrico.
distancia => para sensor ultrassônico.
posição => para sensor giroscópio.

Todos, com exceção do sensor de “posicao”, dispensam o uso de parâmetros. Para utilizar este sensor é necessário informar o eixo do sensor a ser lido sendo representado pela letra inicial do sensor, A ou G, seguido de seu eixo x, y ou z, sendo assim:

Ax = acelerômetro eixo x.
Ay = acelerômetro eixo y.
Az = acelerômetro eixo z.
temp = sensor de temperatura.
Gx = giroscópio eixo x.
Gy = giroscópio eixo y.
Gz = giroscópio eixo z.

## LED

Para inicializar um LED (Light Emitting Diode | Diodo Emissor de Luz), utilize o construtor `Led "objeto"("int pino")`, onde `"pino"` representa o número do pino digital ao qual o LED está ligado. Ex.:

```cpp
Led meuLed(3);
```

> Este mesmo construtor pode ser utilizado por outros componentes que utilizem apenas um pino digital, como um buzzer, por exemplo.

### `void liga([float ms])`

O exemplo abaixo liga `meuLed` e aguarda 500 milissegundos.

```cpp
meuLed.liga(500);
```

É possível utilizar este mesmo método sem um tempo de espera. Ex.:

```cpp
meuLed.liga();
```

### `void desliga([float ms])`

O exemplo abaixo desliga `meuLed` e aguarda 500 milissegundos.

```cpp
meuLed.desliga(500);
```

É possível utilizar este mesmo método sem um tempo de espera. Ex.:

```cpp
meuLed.desliga();
```

## Aprendendo

Na [documentação oficial da GuaraTeca](http://guarabots.wordpress.com/guarateca) você encontrará tudo o que precisa para dominar a biblioteca.

## Suporte

Caso encontre falhas ou tenha sugestões, não exite em nos contatar em [guarabots@gmail.com](mailto:guarabots@gmail.com?Subject=GuaraTeca) ou [joaquimflavio.quirino@yahoo.com.br](mailto:joaquimflavio.quirino@yahoo.com.br?Subject=GuaraTeca).

## Licença

A GuaraTeca é licenciada sob a [Licença Pública Geral GNU GPL](https://www.gnu.org/licenses/gpl-3.0.html)
