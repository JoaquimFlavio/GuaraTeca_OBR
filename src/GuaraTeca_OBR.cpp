//Copyright 2017 Joaquim Fl�vio Almeida Quirino Gomes, D�mis Carlos ----*
//Fonseca Gomes, Marcos Dias da Concei��o e Diego de Castro Rodrigues---*
//----------------------------------------------------------------------*
//Este arquivo � parte da Biblioteca de Fun��es Guar�Teca---------------*
//A Guar�Teca � um software livre; voc� pode redistribu�-lo e/ou--------*
//modific�-lo sob os termos da Licen�a P�blica Geral GNU como publicada-*
//pela Funda��o do Software Livre (FSF); na vers�o 3 da Licen�a,--------*
//ou (a seu crit�rio) qualquer vers�o posterior.------------------------*
//
//Este programa � distribu�do na esperan�a de que possa ser �til,-------*
//mas SEM NENHUMA GARANTIA; sem uma garantia impl�cita de ADEQUA��O-----*
//a qualquer MERCADO ou APLICA��O EM PARTICULAR. Veja a-----------------*
//Licen�a P�blica Geral GNU para mais detalhes.-------------------------*
//
//Voc� deve ter recebido uma c�pia da Licen�a P�blica Geral GNU junto---*
//com este programa. Se n�o, veja <http://www.gnu.org/licenses/>--------*

#include "GuaraTeca_OBR.h"

//MotorShield________________________________________________________________________________________________________________________________________

MRobot::MRobot(uint8_t conexao1, uint8_t conexao2, int velocidade) : MotorShield(){
    this->conexao1 = conexao1;//Motor esquerdo.
    this->conexao2 = conexao2;//Motor direito.

    //Correcão de possíveis erros de usuario.
    if(velocidade > 100){
        velocidade = 100;
    }else if(velocidade < 0){
        velocidade = 0;
    }

    V1 = V2 = (velocidade*255)/100;//Converção de"% de velocidade" para "nivel de tensao".
    
    MotorShield::iniciaMotorShield();//Preparamos o hardware para controle.
    MotorShield::controleDeCorrente(conexao1, V1);//Definimos a velocidade do motor esquerdo.
    MotorShield::controleDeCorrente(conexao2, V2);//Definimos a velocidade do motor direito.

    adicaoMotors = false;//Desativamos o modo de 4 motores.
}

MRobot::MRobot(uint8_t conexao1, uint8_t conexao2, uint8_t conexao3, uint8_t conexao4, int velocidade) : MotorShield(){
    this->conexao1 = conexao1;//Motor esquerdo 1.
    this->conexao2 = conexao2;//Motor esquerdo 2.
    this->conexao3 = conexao3;//Motor direito 1.
    this->conexao4 = conexao4;//Motor direito 2.
    
    //Correcão de possíveis erros de usuario.
    if(velocidade > 100){
        velocidade = 100;
    }else if(velocidade < 0){
        velocidade = 0;
    }

    V1 = V2 = (velocidade*255)/100;//Converção de "% de velocidade" para "nivel de tensao".

    MotorShield::iniciaMotorShield();//Preparamos o hardware para controle.
    MotorShield::controleDeCorrente(conexao1, V1);//Definimos a velocidade do motor esquerdo 1.
    MotorShield::controleDeCorrente(conexao2, V1);//Definimos a velocidade do motor esquerdo 2.
    MotorShield::controleDeCorrente(conexao3, V2);//Definimos a velocidade do motor direito 1.
    MotorShield::controleDeCorrente(conexao4, V2);//Definimos a velocidade do motor direito 2.

    adicaoMotors = true;//Ativamos o modo de 4 motores.
}
void MRobot::defineVelocidade(int tempV1, int tempV2){
    //Correcão de possíveis erros de usuario.
    if(tempV1 > 100)
        tempV1 = 100;
    else if(tempV1 < 0)
        tempV1 = 0;
    if(tempV2 > 100)
        tempV2 = 100;
    else if(tempV2 < 0)
        tempV2 = 0;

    //Atualizamos as variaveis com a nova velocidade.
    V1 = (tempV1*255)/100;//Converção de "% de velocidade" para "nivel de tensao".
    V2 = (tempV2*255)/100;//Converção de "% de velocidade" para "nivel de tensao".

    MotorShield::controleDeCorrente(conexao1, V1);//Definimos a velocidade do motor esquerdo 1.
    MotorShield::controleDeCorrente(conexao2, V1);//Definimos a velocidade do motor esquerdo 2.
    MotorShield::controleDeCorrente(conexao3, V2);//Definimos a velocidade do motor direito 1.
    MotorShield::controleDeCorrente(conexao4, V2);//Definimos a velocidade do motor direito 2.
}
int MRobot::adquireVelocidade(uint8_t OP){
    return ((OP == 1 ? V1 : V2)*100)/255;//Converção de "nivel de tensao" para "% de velocidade".
}

/*
    Os metodos: frente, tras, esquerda, direita, seguem um padrao:
        ->Verifica se há 2 ou 4 motores no sistema.
        *Em ambos os modos.
        ->Verifica se o usuario definiu um tempo de duracao para a movimentacao.
        *Se estiver definido:
            ->Congela o codigo durante o tempo definido.
            ->Desliga a alimentacao dos motores.
        *Senao:
            ->Não Faz nada, apenas deixa o estado de movimentacao ativo, de modo
              que a menos que o usuario o altere ele se mantera em movimento
*/

void MRobot::frente(float tempo){
    if(adicaoMotors){
        MotorShield::sentido1(conexao1);
        MotorShield::sentido1(conexao2);
        MotorShield::sentido1(conexao3);
        MotorShield::sentido1(conexao4);
        if(tempo > 0){
            execute_durante(tempo);
            MotorShield::desliga(conexao1);
            MotorShield::desliga(conexao2);
            MotorShield::desliga(conexao3);
            MotorShield::desliga(conexao4);
        }
    }else{
        MotorShield::sentido1(conexao1);
        MotorShield::sentido1(conexao2);
        if(tempo > 0){
            execute_durante(tempo);
            MotorShield::desliga(conexao1);
            MotorShield::desliga(conexao2);
        }
    }
}
void MRobot::tras(float tempo){
    if(adicaoMotors){
        MotorShield::sentido2(conexao1);
        MotorShield::sentido2(conexao2);
        MotorShield::sentido2(conexao3);
        MotorShield::sentido2(conexao4);
        if(tempo > 0){
            execute_durante(tempo);
            MotorShield::desliga(conexao1);
            MotorShield::desliga(conexao2);
            MotorShield::desliga(conexao3);
            MotorShield::desliga(conexao4);
        }
    }else{
        MotorShield::sentido2(conexao1);
        MotorShield::sentido2(conexao2);
        if(tempo > 0){
            execute_durante(tempo);
            MotorShield::desliga(conexao1);
            MotorShield::desliga(conexao2);
        }
    }
}
void MRobot::esquerda(float tempo){
    if(adicaoMotors){
        MotorShield::sentido1(conexao1);
        MotorShield::sentido1(conexao2);
        MotorShield::sentido2(conexao3);
        MotorShield::sentido2(conexao4);
        if(tempo > 0){
            execute_durante(tempo);
            MotorShield::desliga(conexao1);
            MotorShield::desliga(conexao2);
            MotorShield::desliga(conexao3);
            MotorShield::desliga(conexao4);
        }
    }else{
        MotorShield::sentido1(conexao1);
        MotorShield::sentido2(conexao2);
        if(tempo > 0){
            execute_durante(tempo);
            MotorShield::desliga(conexao1);
            MotorShield::desliga(conexao2);
        }
    }
}
void MRobot::direita(float tempo){
    if(adicaoMotors){
        MotorShield::sentido2(conexao1);
        MotorShield::sentido2(conexao2);
        MotorShield::sentido1(conexao3);
        MotorShield::sentido1(conexao4);
        if(tempo > 0){
            execute_durante(tempo);
            MotorShield::desliga(conexao1);
            MotorShield::desliga(conexao2);
            MotorShield::desliga(conexao3);
            MotorShield::desliga(conexao4);
        }
    }else{
        MotorShield::sentido2(conexao1);
        MotorShield::sentido1(conexao2);
        if(tempo > 0){
            execute_durante(tempo);
            MotorShield::desliga(conexao1);
            MotorShield::desliga(conexao2);
        }
    }
}
void MRobot::para(float tempo){
    MotorShield::trava(conexao1);
    MotorShield::trava(conexao2);
    if(adicaoMotors){
        MotorShield::trava(conexao3);
        MotorShield::trava(conexao4);  
    }
    execute_durante(tempo);
}

//Ponte-H dupla______________________________________________________________________________________________________________________________________

HRobot::HRobot(uint8_t P1A, uint8_t P2A, uint8_t VA, uint8_t P1B, uint8_t P2B, uint8_t VB, int velocidade) : PonteH(){
    motor[0] = P1A;//pino de controle porta 1, lado A da PonteH | Motor esquerdo.
    motor[1] = P2A;//pino de controle porta 2, lado A da PonteH |       ||      .
    motor[2] = VA;//pino velocidade lado A da PonteH            |       ||      .
    motor[3] = P1B;//pino de controle porta 1, lado B da PonteH | Motor direito .
    motor[4] = P2B;//pino de controle porta 2, lado B da PonteH |       ||      .
    motor[5] = VB;//pino velocidade lado B da Ponte H           |       ||      .

    //Correcão de possíveis erros de usuario.
    if(velocidade > 100)
        velocidade = 100;
    else if(velocidade < 100)
        velocidade = 0;

    V1 = V2 = (velocidade*255)/100;//Converção de "% de velocidade" para "nivel de tensao".
    
    PonteH::iniciaPonteH(motor[0], motor[1], motor[2], motor[3], motor[4], motor[5]);//Preparamos o hardware para controle.
    PonteH::controleDeCorrente(motor[2], V1);//Definimos a velocidade do lado A da ponteH.
    PonteH::controleDeCorrente(motor[5], V2);//Definimos a velocidade do lado B da ponteH.
}
void HRobot::defineVelocidade(int tempV1, int tempV2){
    //Correcão de possíveis erros de usuario.
    if(tempV1 > 100)
        tempV1 = 100;
    else if(tempV1 < 0)
        tempV1 = 0;
    if(tempV1 > 100)
        tempV1 = 100;
    else if(tempV1 < 0)
        tempV1 = 0;
    
    //Atualizamos as variaveis com a nova velocidade.
    V1 = (tempV1*255)/100;//Converção de "% de velocidade" para "nivel de tensao".
    V2 = (tempV2*255)/100;//Converção de "% de velocidade" para "nivel de tensao".

    PonteH::controleDeCorrente(motor[2], V1);//Atualizamos a velocidade do lado A da Ponte H.
    PonteH::controleDeCorrente(motor[5], V2);//Atualizamos a velocidade do lado B da Ponte H.
}
int HRobot::adquireVelocidade(uint8_t OP){
    return ((OP == 1 ? V1 : V2)*100)/255;//Converção de "nivel de tensao" para "% de velocidade". 
}

/*
    Os metodos: frente, tras, esquerda, direita, para, seguem um padrao:
        ->Verifica se o usuario definiu um tempo de duracao para a movimentacao.
        *Se estiver definido:
            ->Congela o codigo durante o tempo definido.
            ->Desliga a alimentacao dos motores.
        *Senao:
            ->Não Faz nada, apenas deixa o estado de movimentacao ativo, de modo
              que a menos que o usuario o altere ele se mantera em movimento
*/

void HRobot::frente(float tempo){
    PonteH::sentido1(motor[0], motor[1]);
    PonteH::sentido1(motor[3], motor[4]);
    if(tempo > 0){
        execute_durante(tempo);
        PonteH::desliga(motor[0], motor[1]);
        PonteH::desliga(motor[3], motor[4]);
    }
}
void HRobot::tras(float tempo){
    PonteH::sentido2(motor[0], motor[1]);
    PonteH::sentido2(motor[3], motor[4]);
    if(tempo > 0){
        execute_durante(tempo);
        PonteH::desliga(motor[0], motor[1]);
        PonteH::desliga(motor[3], motor[4]);
    }
}
void HRobot::esquerda(float tempo){
    PonteH::sentido2(motor[0], motor[1]);
    PonteH::sentido1(motor[3], motor[4]);
    if(tempo > 0){
        execute_durante(tempo);
        PonteH::desliga(motor[0], motor[1]);
        PonteH::desliga(motor[3], motor[4]);
    }
}
void HRobot::direita(float tempo){
    PonteH::sentido1(motor[0], motor[1]);
    PonteH::sentido2(motor[3], motor[4]);
    if(tempo > 0){
        execute_durante(tempo);
        PonteH::desliga(motor[0], motor[1]);
        PonteH::desliga(motor[3], motor[4]);
    }
}
void HRobot::para(float tempo){
    PonteH::trava(motor[0], motor[1]);
    PonteH::trava(motor[3], motor[4]);
    if(tempo > 0){
        execute_durante(tempo);
        PonteH::desliga(motor[0], motor[1]);
        PonteH::desliga(motor[3], motor[4]);
    }
}

void execute_durante(float tempo){
    delay(tempo*1000);
}

//Sensores___________________________________________________________________________________________________________________________________________

Sensor::Sensor() : GY521_MPU6050(){}

Sensor::Sensor(uint8_t PinSense1) : SensorRefletancia(){
    this->PinSense1 = PinSense1;

    SensorRefletancia::iniciaSensorRefletancia(PinSense1);//Preparamos o hardware para controle.
}
Sensor::Sensor(uint8_t trigPin, uint8_t echoPin) : HCSR04(){
    PinSense1 = trigPin;
    PinSense2 = echoPin;

    HCSR04::iniciaHCSR04(PinSense1, PinSense2);//Preparamos o hardware para controle.
}
Sensor::Sensor(uint8_t outPin, uint8_t S0, uint8_t S1, uint8_t S2, uint8_t S3) : TCS230(){
    PinSense1 = outPin;
    PinSense2 = S0;
    PinSense2 = S1;
    PinSense2 = S2;
    PinSense2 = S3;

    TCS230::iniciaTCS230(PinSense1, PinSense2, PinSense3, PinSense4, PinSense5);//Preparamos o hardware para controle.

    //Definimos o melhor modo de operacao do sensor, baseado em pesquisas realizadas pela equipe.
    cor_frequencia(frequenciaRecomendada_GUARABOTS);
    cor_filtro(filtroCorRecomendada_GUARABOTS);
}
//Ir sensor____________________________________________________________________
int Sensor::luz(){
    return SensorRefletancia::leitura(PinSense1);
}

//Color sensor_________________________________________________________________
/*
    Frequencia de operacao do sensor:
        -> 0 = 0%
        -> 1 = 2%;
        -> 2 = 20%
        -> 3 = 100%
*/
void Sensor::cor_frequencia(uint8_t OP){
    TCS230::frequencia(OP);
}
/*
    Filtro de cores do sensor:
        -> 'R' = Vermelho.
        -> 'G' = Verde.
        -> 'B' = Azul.
        -> 'N' = Sem filtro.
*/
void Sensor::cor_filtro(char RGB){
    switch(RGB){
        case 'R':
            TCS230::filtroVermelho();
        break;
        case 'G':
            TCS230::filtroVerde();
        break;
        case 'B':
            TCS230::filtroAzul();
        break;
        default:
            TCS230::filtroNulo();
    }
}
int Sensor::cor(){
    return TCS230::leitura();
}

//ultrasonico__________________________________________________________________
float Sensor::distancia(){
    return HCSR04::leitura(PinSense1, PinSense2);
}

//Giroscopio e Acelerometro____________________________________________________
void Sensor::inicia(bool add){
    DLC_sensor = add;
    GY521_MPU6050::iniciaGY521_MPU6050(add ? Endereco_1 : Endereco_2);
}

int Sensor::acelerometroX(){
    GY521_MPU6050::ObtemDados(dados, DLC_sensor ? Endereco_1 : Endereco_2);
    return dados[Ax];
}
int Sensor::acelerometroY(){
    GY521_MPU6050::ObtemDados(dados, DLC_sensor ? Endereco_1 : Endereco_2);     
    return dados[Ay];
}
int Sensor::acelerometroZ(){
    GY521_MPU6050::ObtemDados(dados, DLC_sensor ? Endereco_1 : Endereco_2);     
    return dados[Az];
}
int Sensor::giroscopioX(){
      GY521_MPU6050::ObtemDados(dados, DLC_sensor ? Endereco_1 : Endereco_2);     
    return dados[Gx];
}
int Sensor::giroscopioY(){
      GY521_MPU6050::ObtemDados(dados, DLC_sensor ? Endereco_1 : Endereco_2);     
    return dados[Gy];
}
int Sensor::giroscopioZ(){
      GY521_MPU6050::ObtemDados(dados, DLC_sensor ? Endereco_1 : Endereco_2);     
    return dados[Gz];
}
int Sensor::temperatura(){
      GY521_MPU6050::ObtemDados(dados, DLC_sensor ? Endereco_1 : Endereco_2);     
    return dados[Tmp]/340.00+36.53;
}

//Led________________________________________________________________________________________________________________________________________________

Led::Led(uint8_t pin_adquiri){
    pino = pin_adquiri;
    pinMode(pino, OUTPUT);
}

void Led::liga(){
    digitalWrite(pino , HIGH);
}
void Led::desliga(){
    digitalWrite(pino , LOW);
}
