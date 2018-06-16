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

MRobot::MRobot(uint8_t conexao1, uint8_t conexao2, float velocidade) : MotorShield(){
    this->conexao1 = conexao1;//Motor esquerdo.
    this->conexao2 = conexao2;//Motor direito.
    //this->conexao3 = NULL;
    //this->conexao4 = NULL;

    //Correcão de possíveis erros de usuario.
    if(velocidade > 100){
        velocidade = 100;
    }else if(velocidade < 0){
        velocidade = 0;
    }

    VME = VMD = (velocidade*255)/100;//Converção de"% de velocidade" para "nivel de tensao".
    
    MotorShield::iniciaMotorShield();//Preparamos o hardware para controle.
    MotorShield::controleDeCorrente(conexao1, VME);//Definimos a velocidade do motor esquerdo.
    MotorShield::controleDeCorrente(conexao2, VMD);//Definimos a velocidade do motor direito.

    adicaoMotors = false;//Desativamos o modo de 4 motores.
}

MRobot::MRobot(uint8_t conexao1, uint8_t conexao2, uint8_t conexao3, uint8_t conexao4, float velocidade) : MotorShield(){
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

    VME = VMD = (velocidade*255)/100;//Converção de "% de velocidade" para "nivel de tensao".

    MotorShield::iniciaMotorShield();//Preparamos o hardware para controle.
    MotorShield::controleDeCorrente(this->conexao1, VME);//Definimos a velocidade do motor esquerdo 1.
    MotorShield::controleDeCorrente(this->conexao2, VME);//Definimos a velocidade do motor esquerdo 2.
    MotorShield::controleDeCorrente(this->conexao3, VMD);//Definimos a velocidade do motor direito 1.
    MotorShield::controleDeCorrente(this->conexao4, VMD);//Definimos a velocidade do motor direito 2.

    adicaoMotors = true;//Ativamos o modo de 4 motores.
}
void MRobot::defineVelocidade(float VME, float VMD){
    //Correcão de possíveis erros de usuario.
    if(VME > 100)
        VME = 100;
    else if(VME < 0)
        VME = 0;
    if(VMD > 100)
        VMD = 100;
    else if(VMD < 0)
        VMD = 0;

    //Atualizamos as variaveis com a nova velocidade.
    this->VME = (VME*255)/100;//Converção de "% de velocidade" para "nivel de tensao".
    this->VMD = (VMD*255)/100;//Converção de "% de velocidade" para "nivel de tensao".

    //Atribuimos a velocidade aos motores.
    if(adicaoMotors){//Verifica se o usuario esta utilizando 2 ou 4 motores.
        MotorShield::controleDeCorrente(conexao1, this->VME);//Definimos a velocidade do motor esquerdo 1.
        MotorShield::controleDeCorrente(conexao2, this->VME);//Definimos a velocidade do motor esquerdo 2.
        MotorShield::controleDeCorrente(conexao3, this->VMD);//Definimos a velocidade do motor direito 1.
        MotorShield::controleDeCorrente(conexao4, this->VMD);//Definimos a velocidade do motor direito 2.
    }else{
        MotorShield::controleDeCorrente(conexao1, this->VME);//Definimos a velocidade do motor esquerdo.
        MotorShield::controleDeCorrente(conexao2, this->VMD);//Definimos a velocidade do motor direito.
    }
}
float MRobot::adquireVME(void){
    return (VME*100)/255;//Converção de "nivel de tensao" para "% de velocidade".
}
float MRobot::adquireVMD(void){
    return (VMD*100)/255;//Converção de "nivel de tensao" para "% de velocidade".
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
void MRobot::move(float VME, float VMD, float tempo){
    VME > 0 ? MotorShield::sentido1(conexao1) : MotorShield::sentido2(conexao1);
    VMD > 0 ? MotorShield::sentido1(conexao1) : MotorShield::sentido2(conexao2);
    if(tempo!=0)
        execute_durante(tempo);
}

//Ponte-H dupla______________________________________________________________________________________________________________________________________

HRobot::HRobot(uint8_t P1A, uint8_t P2A, uint8_t VA, uint8_t P1B, uint8_t P2B, uint8_t VB, int velocidade){
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

    VME = VMD = (velocidade*255)/100;//Converção de "% de velocidade" para "nivel de tensao".
    
    inicia_PonteH(motor[0], motor[1], motor[2], motor[3], motor[4], motor[5]);//Preparamos o hardware para controle.
    controleDeCorrente_PonteH(motor[2], VME);//Definimos a velocidade do lado A da ponteH.
    controleDeCorrente_PonteH(motor[5], VMD);//Definimos a velocidade do lado B da ponteH.
}
void HRobot::defineVelocidade(float VME, float VMD){
    //Correcão de possíveis erros de usuario.
    if(VME > 100)
        VME = 100;
    else if(VME < 0)
        VME = 0;
    if(VMD > 100)
        VMD = 100;
    else if(VMD < 0)
        VMD = 0;
    
    //Atualizamos as variaveis com a nova velocidade.
    this->VME = (VME*255)/100;//Converção de "% de velocidade" para "nivel de tensao".
    this->VMD = (VMD*255)/100;//Converção de "% de velocidade" para "nivel de tensao".

    controleDeCorrente_PonteH(motor[2], this->VME);//Atualizamos a velocidade do lado A da Ponte H.
    controleDeCorrente_PonteH(motor[5], this->VMD);//Atualizamos a velocidade do lado B da Ponte H.
}
float HRobot::adquireVME(void){
    return (VME*100)/255;//Converção de "nivel de tensao" para "% de velocidade". 
}
float HRobot::adquireVMD(void){
    return (VMD*100)/255;//Converção de "nivel de tensao" para "% de velocidade". 
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
    sentido1_PonteH(motor[0], motor[1]);
    sentido1_PonteH(motor[3], motor[4]);
    if(tempo > 0){
        execute_durante(tempo);
        desliga_PonteH(motor[0], motor[1]);
        desliga_PonteH(motor[3], motor[4]);
    }
}
void HRobot::tras(float tempo){
    sentido2_PonteH(motor[0], motor[1]);
    sentido2_PonteH(motor[3], motor[4]);
    if(tempo > 0){
        execute_durante(tempo);
        desliga_PonteH(motor[0], motor[1]);
        desliga_PonteH(motor[3], motor[4]);
    }
}
void HRobot::esquerda(float tempo){
    sentido2_PonteH(motor[0], motor[1]);
    sentido1_PonteH(motor[3], motor[4]);
    if(tempo > 0){
        execute_durante(tempo);
        desliga_PonteH(motor[0], motor[1]);
        desliga_PonteH(motor[3], motor[4]);
    }
}
void HRobot::direita(float tempo){
    sentido1_PonteH(motor[0], motor[1]);
    sentido2_PonteH(motor[3], motor[4]);
    if(tempo > 0){
        execute_durante(tempo);
        desliga_PonteH(motor[0], motor[1]);
        desliga_PonteH(motor[3], motor[4]);
    }
}
void HRobot::para(float tempo){
    trava_PonteH(motor[0], motor[1]);
    trava_PonteH(motor[3], motor[4]);
    if(tempo > 0){
        execute_durante(tempo);
        desliga_PonteH(motor[0], motor[1]);
        desliga_PonteH(motor[3], motor[4]);
    }
}
void HRobot::move(float VME, float VMD, float tempo){
    VME > 0 ? sentido1_PonteH(motor[0], motor[1]) : sentido2_PonteH(motor[3], motor[4]);
    VMD > 0 ? sentido1_PonteH(motor[0], motor[1]) : sentido2_PonteH(motor[3], motor[4]);
    if(tempo!=0)
        execute_durante(tempo);
    desliga_PonteH(motor[0], motor[1]);
    desliga_PonteH(motor[3], motor[4]);
}

void execute_durante(float tempo){
    delay(tempo*1000);
}

//Sensores___________________________________________________________________________________________________________________________________________

Sensor::Sensor(){}

Sensor::Sensor(uint8_t PinSense1){
    this->PinSense1 = PinSense1;

    inicia_SensorRefletancia(PinSense1);//Preparamos o hardware para controle.
}
Sensor::Sensor(uint8_t trigPin, uint8_t echoPin){
    PinSense1 = trigPin;
    PinSense2 = echoPin;

    inicia_Ultrassonico(PinSense1, PinSense2);//Preparamos o hardware para controle.
}
Sensor::Sensor(uint8_t outPin, uint8_t S0, uint8_t S1, uint8_t S2, uint8_t S3){
    PinSense1 = outPin;
    PinSense2 = S0;
    PinSense3 = S1;
    PinSense4 = S2;
    PinSense5 = S3;

    inicia_TCS230(PinSense1, PinSense2, PinSense3, PinSense4, PinSense5);//Preparamos o hardware para controle.

    //Definimos o melhor modo de operacao do sensor, baseado em pesquisas realizadas pela equipe.
    cor_frequencia(frequenciaRecomendada_GUARABOTS);
    cor_filtro(filtroCorRecomendada_GUARABOTS);
}
//Ir sensor____________________________________________________________________
int Sensor::luz(){
    return leitura_SensorRefletancia(PinSense1);
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
    frequencia_TCS230(PinSense2, PinSense3, OP);
}
/*
    Filtro de cores do sensor:
        -> 'R' = Vermelho.
        -> 'G' = Verde.
        -> 'B' = Azul.
        -> 'N' = Sem filtro.
*/
void Sensor::cor_filtro(char RGB){
    filtroCor_TCS230(PinSense4, PinSense5, RGB);
}
int Sensor::cor(){
    return leitura_TCS230(PinSense1);
}

//ultrasonico__________________________________________________________________
int Sensor::distancia(){
    return leitura_Ultrassonico(PinSense1, PinSense2);
}

//Giroscopio e Acelerometro____________________________________________________
void Sensor::inicia(bool add){
    DLC_sensor = add;
    inicia_GY521_MPU6050(add ? Endereco_1 : Endereco_2);
}

int Sensor::acelerometroX(){
    obtemDados_GY521_MPU6050(dados, DLC_sensor ? Endereco_1 : Endereco_2);
    return dados[Ax];
}
int Sensor::acelerometroY(){
    obtemDados_GY521_MPU6050(dados, DLC_sensor ? Endereco_1 : Endereco_2);     
    return dados[Ay];
}
int Sensor::acelerometroZ(){
    obtemDados_GY521_MPU6050(dados, DLC_sensor ? Endereco_1 : Endereco_2);     
    return dados[Az];
}
int Sensor::giroscopioX(){
    obtemDados_GY521_MPU6050(dados, DLC_sensor ? Endereco_1 : Endereco_2);     
    return dados[Gx];
}
int Sensor::giroscopioY(){
    obtemDados_GY521_MPU6050(dados, DLC_sensor ? Endereco_1 : Endereco_2);     
    return dados[Gy];
}
int Sensor::giroscopioZ(){
    obtemDados_GY521_MPU6050(dados, DLC_sensor ? Endereco_1 : Endereco_2);     
    return dados[Gz];
}
int Sensor::temperatura(){
    obtemDados_GY521_MPU6050(dados, DLC_sensor ? Endereco_1 : Endereco_2);     
    return dados[Tmp]/340.00+36.53;
}

//Led________________________________________________________________________________________________________________________________________________

Led::Led(uint8_t pino){
    this->pino = pino;
    pinMode(pino, OUTPUT);
}

void Led::liga(){
    digitalWrite(pino, HIGH);
}
void Led::desliga(){
    digitalWrite(pino, LOW);
}
