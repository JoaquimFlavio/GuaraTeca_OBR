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

#ifndef GuaraTeca_OBR_H
#define GuaraTeca_OBR_H

//Inclusao da biblioteca com todas as funcoes de controle de baixo nivel_______________________
#include <GuaraTeca_Hardware.h>

//-------------------------------------------------------------------------------------
class MRobot : public MotorShield{
    public:
        MRobot(uint8_t conexao1, uint8_t conexao2, float velocidade = 100);//Construtor da classe MRobot, para 2 motores.
        MRobot(uint8_t conexao1, uint8_t conexao2, uint8_t conexao3, uint8_t conexao4, float velocidade = 100);//Construtor da classe MRobot, para 4 motores, os dois primeiro trabalharam em paralelo.
        
        //Corespondencia de pinos: motor esquerdo, motor direito, velocidade(0~100).                                          
        void frente     (float tempo = 0);//Metodo para mover o robo para frente   , durante "x" segundos.
        void tras       (float tempo = 0);//Metodo para mover o robo para tras     , durante "x" segundos.
        void esquerda   (float tempo = 0);//Metodo para mover o robo para esquerda , durante "x" segundos.
        void direita    (float tempo = 0);//Metodo para mover o robo para direita  , durante "x" segundos.
        void para       (float tempo = 0);//Metodo para travar movimentacao do robo, durante "x" segundos.
            
        //VME => velocidade do motor esquerdo.
        //VMD => velocidade do motor direto.
        void move (float VME, float VMD, float tempo = 0);//Metodo para movimentar o robo de acordo com as forças informadas (mais para a direita ou esquerda...), durante "x" segundos.

        void defineVelocidade (float VME, float VMD);//Metodo "set" de velocidade da classe.
        float adquireVME (void);//Metodo "get" de velocidade da classe.
        float adquireVMD (void);//Metodo "get" de velocidade da classe.
    private:
        float VME, VMD;//Atributos de velocidade da classe.
        uint8_t conexao1, conexao2, conexao3, conexao4;//Atributos de conexoes da classe.
        bool adicaoMotors;//atributo que controla a quantidade de motores: "2" ou "4".
};

class HRobot{
    public:
        HRobot(uint8_t P1A, uint8_t P2A, uint8_t VA, uint8_t P1B, uint8_t P2B, uint8_t VB, int velocidade = 100);//Construtor da classe HRobot.
        //Corespondencia de pinos:
            //P1A -> pino de controle 1 do lado A da PonteH.
            //P2A -> pino de controle 2 do lado A da PonteH.
            //VA  -> pino de controle de velocidade do lado A da PonteH.
            //P1B -> pino de controle 1 do lado B da PonteH.
            //P2B -> pino de controle 2 do lado B da PonteH.
            //VB  -> pino de controle de velocidade do lado B da PonteH.
            //velocidade -> 0~100.
        void frente     (float tempo = 0);//Metodo para mover o robo para frente   , durante "x" segundos.
        void tras       (float tempo = 0);//Metodo para mover o robo para tras     , durante "x" segundos.
        void esquerda   (float tempo = 0);//Metodo para mover o robo para esquerda , durante "x" segundos.
        void direita    (float tempo = 0);//Metodo para mover o robo para direita  , durante "x" segundos.
        void para       (float tempo = 0);//Metodo para travar movimentacao do robo, durante "x" segundos.

        //VME => velocidade do motor esquerdo.
        //VMD => velocidade do motor direto.
        void move (float VME, float VMD, float tempo = 0);//Metodo para movimentar o robo de acordo com as forças informadas (mais para a direita ou esquerda...), durante "x" segundos.

        void defineVelocidade (float VME, float VMD);//Metodo "set" de velocidade da classe.
        float adquireVME (void);//Metodo "get" de velocidade da classe.
        float adquireVMD (void);//Metodo "get" de velocidade da classe.
    private:
        uint8_t motor[6];//Atributos de conexoes da classe.
        int VME, VMD;//Atributos de velocidade da classe.
};

void execute_durante(float tempo);//Funcao para converter o delay de milisegundos para segundos.

#define Ax 0//Acelerometro eixo X.
#define Ay 1//Acelerometro eixo Y.
#define Az 2//Acelerometro eixo Z.

#define Gx 4//Giroscopio eixo X.
#define Gy 5//Giroscopio eixo Y.
#define Gz 6//Giroscopio eixo Z.

#define Tmp 3//Sensor de temperatura.

#define Endereco_1 0x68//Endereco i2C do 1° sensor Giroscopio.
#define Endereco_2 0x69//Endereco i2C do 2° sensor Giroscopio.

#define frequenciaRecomendada_GUARABOTS 2
#define filtroCorRecomendada_GUARABOTS 'G'

class Sensor{
    public:
        Sensor();//Construtor da classe Sensor, para sensor Giroscopio (GY521_MPU6050).
        Sensor(uint8_t PinSense1);//Construtor da classe Sensor, para sensor de refletancia.
        Sensor(uint8_t trigPin, uint8_t echoPin);//Construtor da classe Sensor, para sensor ultrassonico(HCSR04).
        Sensor(uint8_t outPin, uint8_t S0, uint8_t S1, uint8_t S2, uint8_t S3);//Construtor da classe Sensor, para sensor de cor (TCS230).

        int luz(void);//Metodo de leitura do sensor de refletancia.
        
        int cor(void);//Metodo de leitura do sensor de cor.
            void cor_frequencia(uint8_t OP);//Metodo para alterar a frequencia de operacao do sensor de cor.
            void cor_filtro(char RGB);//Metodo para selecao de filtro de luz do sensor de cor.
        
        int distancia(void);//Metodo de leitura do sensor ultrassonico.

        void inicia(bool add = 0x00);//Metodo para iniciar o sensor Giroscopio.

        int acelerometroX   ();//Metodo de leitura do sensor Acelerometro, eixo X.
        int acelerometroY   ();//Metodo de leitura do sensor Acelerometro, eixo Y.
        int acelerometroZ   ();//Metodo de leitura do sensor Acelerometro, eixo Z.
        int giroscopioX     ();//Metodo de leitura do sensor Giroscopio, eixo X.
        int giroscopioY     ();//Metodo de leitura do sensor Giroscopio, eixo Y.
        int giroscopioZ     ();//Metodo de leitura do sensor Giroscopio, eixo Z.
        int temperatura     ();//Metodo de leitura do sensor de temperatura.

    private:
        uint8_t PinSense1, PinSense2, PinSense3, PinSense4, PinSense5;//Atributos de conexao dos sensores.
        int dados[7];//Atributo de dados da leitura Giroscopio/Acelerometro.
        bool DLC_sensor;
};

//-------------------------------------------------------------------------------------

class Led{
    public:
        Led(uint8_t pino);//Construtor da classe Lec.
        void liga   ();//Metodo para ligar o led.
        void desliga();//Metodo para desligar o led.
    private:
        uint8_t pino;//Atributo de conexao do led.
};

#endif
