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

    #define Control_MotorShield                  Ativada
    #define Control_PonteH                       Ativada
    #define Control_SensorCor                    Ativada
    #define Control_SensorGiroscopioAcelerometro Ativada
    #define Control_SensorRefletancia            Ativada
    #define Control_SensorUltrassonico           Ativada
    #define Control_Servo                        Ativada

#include <GuaraTeca_includes.h>

//-------------------------------------------------------------------------------------
class MRobot : public MotorShield{
    public:
        MRobot(uint8_t conexao1, uint8_t conexao2, int velocidade);
        
        void frente     (float tempo = 0);
        void tras       (float tempo = 0);
        void esquerda   (float tempo = 0); 
        void direita    (float tempo = 0);
        void para       (float tempo = 0);

        void DefineVelocidade   (int tempV1, int tempV2); //set
        float AdquiriVelocidade (uint8_t OP);// get
    protected:
        float V1, V2;
        uint8_t conexao1, conexao2, conexao3, conexao4;
};

class HRobot : public PonteH{
    public:
        HRobot(uint8_t T1A, uint8_t T1B, uint8_t T1V, uint8_t T2A, uint8_t T2B, uint8_t T2V, unsigned char velocidade = 100);
        
        void frente     (float tempo = 0);
        void tras       (float tempo = 0);
        void esquerda   (float tempo = 0);
        void direita    (float tempo = 0);
        void para       (float tempo = 0);

        void DefineVelocidade   (int tempV1, int tempV2);
        float AdquiriVelocidade (uint8_t OP);
    protected:
        uint8_t motor[6];
        unsigned char V1, V2;
};

void execute_durante(float tempo);
//-------------------------------------------------------------------------------------
/*class Garra : public PonteH, public MotorShield{
    public:
        Garra(int pinoMotor0, int pinoMotor1, int pinoVelocidadeMotor1, int pinoMotor2, int pinoMotor3, int pinoVelocidadeMotor2);
        void trava();
        void abre(float temp, int velocidade);
        void fecha(float temp, int velocidade);
        void levanta(float temp, int velocidade);
        void abaixa(float tmep, int velocidade);
        void AGARRA(float temp1, float temp2, int velocidade);
        void SOLTA(float temp1, float temp2, int velocidade);
        int detecta();
    private:
        int i;
        int criacaoObjectSensors = 1;;
        int pino1, pino2;
        char defaltTipoControlodar[6];
        char defaltTipoSensor[10];
        int GarraMotorPorts[5];
        char str1[10], str2[10];
        char OPT1[10], OPT2[10], OPT3[10], OPT4[10], OPT5[10];
};
*/
//-------------------------------------------------------------------------------------

#define Ax 1
#define Ay 2
#define Az 3

#define Gx 4
#define Gy 5
#define Gz 6

#define Temperatura 7

class Sensor : public SensorRefletancia, public SensorCor, public SensorUltrassonico, public SensorGiroscopioAcelerometro{
    public:
        Sensor();
        Sensor(uint8_t PinSense1);
        Sensor(uint8_t PinSense1, uint8_t PinSense2);//Tp e Ep
        Sensor(uint8_t PinSense1, uint8_t PinSense2, uint8_t PinSense3, uint8_t PinSense4, uint8_t PinSense5);//Out, S0, S1, S2, S3

        int luz();
        int cor();
            void cor_frequencia(uint8_t OP);
            void cor_filtro(uint8_t RGB);
        float distancia();
        float posicao(uint8_t OP);
        int conducao();
    protected:
        void IniSensor_ag();//Acelerometro e giroscopio
    private:
        uint8_t PinSense1, PinSense2, PinSense3, PinSense4, PinSense5;
        bool ini;
};

//-------------------------------------------------------------------------------------

class Led{ // isso e uma classe
    public:
        Led(uint8_t pin_adquiri);// isso e um construtor de objetos
        void liga(float temp = 0);// isso e um metodo
        void desliga(float temp = 0);
    private:
        uint8_t pino;
};
#endif