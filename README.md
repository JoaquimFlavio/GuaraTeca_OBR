## Sobre a GuaraTeca_OBR

A GuaraTeca é uma sub-biblioteca da biblioteca [Guarateca](https://github.com/JoaquimFlavio/GuaraTeca), focada na programação de robôs, baseadas em Arduino, para a participação na [Olimpiada Brasileira de Robotica - OBR](http://www.obr.org.br/). Reduzindo o tempo de produção e facilitando a compreenção do codigo e totalmente em português.

## Instalação

1. **Instalação**
    - Primeiro baixe a biblioteca clicando [aqui](https://codeload.github.com/JoaquimFlavio/GuaraTeca_OBR/zip/1.2.0)
    - Abra a sua IDE do Arduino, clique em ```Sketch > Incluir Biblioteca > Adicionar biblioteca .ZIP```
    - Procure a biblioteca Brasilino baixada em arquivo .ZIP em sua pasta de downloads
    - Pronto, agora a sua biblioteca está instalada e pronta para ser utilizada!
    
## Exemplo de uso

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

## Aprendendo

Na [documentação oficial da GuaraTeca](http://guarabots.wordpress.com/guarateca) você encontrará tudo o que precisa para dominar a biblioteca.

## Suporte

Caso encontre falhas ou tenha sugestões, não exite em nos contatar em [guarabots@gmail.com](mailto:guarabots@gmail.com?Subject=GuaraTeca) ou [joaquimflavio.quirino@yahoo.com.br](mailto:joaquimflavio.quirino@yahoo.com.br?Subject=GuaraTeca).

## Licença

A GuaraTeca é licenciada sob a [Licença Pública Geral GNU GPL](https://www.gnu.org/licenses/gpl-3.0.html)
