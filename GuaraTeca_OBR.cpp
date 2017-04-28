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

//------------------------------------------------------------------------------------------------

MRobot::MRobot(uint8_t tempConexao1, uint8_t tempConexao2, int velocidade) : MotorShield(){
    MotorShield::iniciaMotorShield();

    if(velocidade > 100){
        velocidade = 100;
    }else if(velocidade < 0){
        velocidade = 0;
    }

    V1 = (velocidade*255)/100;
    V2 = (velocidade*255)/100;

    MotorShield::controleDeCorrente(tempConexao1, V1);
    MotorShield::controleDeCorrente(tempConexao2, V2);

    conexao1 = tempConexao1;
    conexao2 = tempConexao2;
}
void MRobot::frente(float tempo){
    MotorShield::sentido1(conexao1);
    MotorShield::sentido1(conexao2);
    execute_durante(tempo);
}
void MRobot::tras(float tempo){
    MotorShield::sentido2(conexao1);
    MotorShield::sentido2(conexao2);
    execute_durante(tempo);
}
void MRobot::esquerda(float tempo){
    MotorShield::sentido1(conexao1);
    MotorShield::sentido2(conexao2);
    execute_durante(tempo);
}
void MRobot::direita(float tempo){
    MotorShield::sentido2(conexao1);
    MotorShield::sentido1(conexao2);
    execute_durante(tempo);
}
void MRobot::para(float tempo){
    MotorShield::trava(conexao1);
    MotorShield::trava(conexao2);
    execute_durante(tempo);
}
void MRobot::DefineVelocidade(int tempV1, int tempV2){
    V1 = (tempV1*255)/100;
    V2 = (tempV2*255)/100;

    MotorShield::controleDeCorrente(conexao1, V1);
    MotorShield::controleDeCorrente(conexao2, V2);
}
float MRobot::AdquiriVelocidade(uint8_t OP){
    switch(OP){
        case 1:
            return (100*V1)/255;
        break;
        case 2:
            return (100*V2)/255;
        break;
        default:
            return 0;
    }
}

HRobot::HRobot(uint8_t T1A, uint8_t T1B, uint8_t T1V, uint8_t T2A, uint8_t T2B, uint8_t T2V, unsigned char velocidade) : PonteH(){
    motor[0] = T1A;//pino de controle porta 1
    motor[1] = T1B;//           ||
    motor[2] = T1V;//pino velocidade
    motor[3] = T2A;//pino de controle porta 2
    motor[4] = T2B;//           ||
    motor[5] = T2V;//pino velocidade

    PonteH::iniciaPonteH(motor[0], motor[1], motor[2], motor[3], motor[4], motor[5]);
    PonteH::controleDeCorrente(motor[2], ((velocidade*255)/100));
    PonteH::controleDeCorrente(motor[5], ((velocidade*255)/100));
}
void HRobot::frente(float tempo){
    PonteH::sentido1(motor[0], motor[1]);
    PonteH::sentido1(motor[3], motor[4]);
    execute_durante(tempo);
}
void HRobot::tras(float tempo){
    PonteH::sentido2(motor[0], motor[1]);
    PonteH::sentido2(motor[3], motor[4]);
    execute_durante(tempo);
}
void HRobot::esquerda(float tempo){
    PonteH::sentido2(motor[0], motor[1]);
    PonteH::sentido1(motor[3], motor[4]);
    execute_durante(tempo);
}
void HRobot::direita(float tempo){
    PonteH::sentido1(motor[0], motor[1]);
    PonteH::sentido2(motor[3], motor[4]);
    execute_durante(tempo);
}
void HRobot::para(float tempo){
    PonteH::trava(motor[0], motor[1]);
    PonteH::trava(motor[3], motor[4]);
    execute_durante(tempo);
}
void HRobot::DefineVelocidade(int tempV1, int tempV2){
    PonteH::controleDeCorrente(motor[2], ((tempV1*255)/100));
    PonteH::controleDeCorrente(motor[5], ((tempV1*255)/100));

    V1 = tempV1;
    V2 = tempV2;
}
float HRobot::AdquiriVelocidade(uint8_t OP){
    switch(OP){
        case 1:
            return V1;
        break;
        case 2:
            return V2;
        break;
        default:
            return 0;
    }
}


void execute_durante(float tempo){
    delay(tempo*1000);
}


//---------------------------------------------------------------------------------------------
/*
Garra::Garra(char tipoControlador[10], int pinoMotor0, int pinoMotor1, int pinoVelocidadeMotor1, int pinoMotor2, int pinoMotor3, int pinoVelocidadeMotor2, int pinSensorGarra0, int pinSensorGarra1) : PonteH(), MotorShield(){

    GarraMotorPorts[0] = pinoMotor0;//motor1
    GarraMotorPorts[1] = pinoMotor1;//   ||
    GarraMotorPorts[2] = pinoVelocidadeMotor1;//velocidade motor 1
    GarraMotorPorts[3] = pinoMotor2;//motor2
    GarraMotorPorts[4] = pinoMotor3;//   ||
    GarraMotorPorts[5] = pinoVelocidadeMotor2;//velocidade motor 2

    if(GuarraMotorPorts[3] =! 0){
    	defaltTipoControlodar[1] = '2';
    }else{
    	defaltTipoControlodar[1] = '1';
    }

    switch(tipoControlador[0]){
        case 'P':
            PonteH::abilitaPinos(GuarraMotorPorts[0],GuarraMotorPorts[1],GuarraMotorPorts[2],GuarraMotorPorts[3],GuarraMotorPorts[4],GuarraMotorPorts[5]);
            defaltTipoControlodar[0] = 'P';
        break;
        case 'M':
            defaltTipoControlodar[0] = 'M';
            MotorShield::MotorShield();
        break;
    }

    if(pinSensorGarra0 =! 0){
        Sensor::Sensor(pinSensorGarra0, pinSensorGarra1);
    }
}

void Garra::trava(int OPT){
    switch(defaltTipoControlodar[0]){
        case 'P':
            if(OPT == 1){
                PonteH::trava(GuarraMotorPorts[0], GuarraMotorPorts[1]);
            }else if(OPT == 2){
                PonteH::trava(GuarraMotorPorts[3], GuarraMotorPorts[4]);
            }else{
                PonteH::trava(GuarraMotorPorts[0], GuarraMotorPorts[1]);
                PonteH::trava(GuarraMotorPorts[3], GuarraMotorPorts[4]);
            }
        break;
        case 'M':
            if(OPT == 1){
                MotorShield::trava(GuarraMotorPorts[0]);
            }else if(OPT == 2){
                MotorShield::trava(GuarraMotorPorts[1]);
            }else{
                MotorShield::trava(GuarraMotorPorts[0]);
                MotorShield::trava(GuarraMotorPorts[1]);
            }
        break;
    }
}
void Garra::abre(float temp, int velocidade){
    switch(defaltTipoControlodar[0]){
        case 'P':
            if(OPT == 1){
                PonteH::trava(GuarraMotorPorts[0], GuarraMotorPorts[1]);
            }else if(OPT == 2){
                PonteH::trava(GuarraMotorPorts[3], GuarraMotorPorts[4]);
            }else{
                PonteH::trava(GuarraMotorPorts[0], GuarraMotorPorts[1]);
                PonteH::trava(GuarraMotorPorts[3], GuarraMotorPorts[4]);
            }
        break;
        case 'M':
            if(OPT == 1){
                MotorShield::trava(GuarraMotorPorts[0]);
            }else if(OPT == 2){
                MotorShield::trava(GuarraMotorPorts[1]);
            }else{
                MotorShield::trava(GuarraMotorPorts[0]);
                MotorShield::trava(GuarraMotorPorts[1]);
            }
        break;
    }
}
void Garra::fecha(float temp, int velocidade){
    if(defaltTipoControlodar[0] == 'M'){
        motorDefaltOfBiblioteca1.setSpeed((velocidade*255)/100);
        motorDefaltOfBiblioteca1.run(FORWARD);
        delay(temp);
        motorDefaltOfBiblioteca1.run(RELEASE);
    }else if(defaltTipoControlodar[0] =='M'){
        analogWrite(GarraMotorPorts[2], ((velocidade*255)/100));

        digitalWrite(GarraMotorPorts[0], HIGH);
        digitalWrite(GarraMotorPorts[1], LOW);
        delay(temp);
        digitalWrite(GarraMotorPorts[0], LOW);
        digitalWrite(GarraMotorPorts[1], LOW);
    }
}
void Garra::levanta(float temp, int velocidade){
    if(defaltTipoControlodar[0] == 'M'){
        motorDefaltOfBiblioteca2.setSpeed((velocidade*255)/100);
        motorDefaltOfBiblioteca2.run(BACKWARD);
        delay(temp);
        motorDefaltOfBiblioteca2.run(RELEASE);
    }else if(defaltTipoControlodar[0] =='M'){
        analogWrite(GarraMotorPorts[5], ((velocidade*255)/100));

        digitalWrite(GarraMotorPorts[3], LOW);
        digitalWrite(GarraMotorPorts[4], HIGH);
        delay(temp);
        digitalWrite(GarraMotorPorts[3], LOW);
        digitalWrite(GarraMotorPorts[4], LOW);
    }
}
void Garra::abaixa(float temp, int velocidade){
    if(defaltTipoControlodar[0] == 'M'){
        motorDefaltOfBiblioteca2.setSpeed((velocidade*255)/100);
        motorDefaltOfBiblioteca2.run(BACKWARD);
        delay(temp);
        motorDefaltOfBiblioteca2.run(RELEASE);
    }else if(defaltTipoControlodar[0] =='M'){
        analogWrite(GarraMotorPorts[5], ((velocidade*255)/100));

        digitalWrite(GarraMotorPorts[3], HIGH);
        digitalWrite(GarraMotorPorts[4], LOW);
        delay(temp);
        digitalWrite(GarraMotorPorts[3], LOW);
        digitalWrite(GarraMotorPorts[4], LOW);
    }
}
void Garra::AGARRA(float temp1, float temp2, int velocidade){
    fecha(temp1, velocidade);
    levanta(temp2, velocidade);
}
void Garra::SOLTA(float temp1, float temp2, int velocidade){
    abaixa(temp2, velocidade);
    abre(temp1, velocidade);
}
int Garra::detecta(){
    Sensor defaltSensorLuzOnCode(pino1);
    Sensor defaltSensorUltrassonicoOnCode(pino1, pino2);
    Sensor defaltSensorConducaoOnCode(pino1);

    if(criacaoObjectSensors){
        if(strcmp(str2,OPT3) == 0){
            strcpy(defaltTipoSensor, "Luz");
        }else if(strcmp(str2,OPT4) == 0){
            strcpy(defaltTipoSensor, "ultrasonico");
        }else if(strcmp(str2,OPT5) == 0){
            strcpy(defaltTipoSensor, "conducao");
        }
        criacaoObjectSensors = 0;
    }

    if(strcmp(defaltTipoSensor,"Luz") == 0){
        return defaltSensorLuzOnCode.luz();
    }else if(strcmp(defaltTipoSensor,"ultrasonico") == 0){
        return defaltSensorUltrassonicoOnCode.distancia();
    }else if(strcmp(defaltTipoSensor,"conducao") == 0){
        return defaltSensorConducaoOnCode.conducao();
    }else return 0;
}
*/
//---------------------------------------------------------------------------------------------

Sensor::Sensor() : SensorGiroscopioAcelerometro(){
    IniSensor_ag();
}
Sensor::Sensor(uint8_t PinSense1) : SensorRefletancia(){
    this->PinSense1 = PinSense1;
    SensorRefletancia::iniciaSensorRefletancia(PinSense1);
}
Sensor::Sensor(uint8_t PinSense1, uint8_t PinSense2) : SensorUltrassonico(){
    this->PinSense1 = PinSense1;
    this->PinSense2 = PinSense2;
    SensorUltrassonico::iniciaSensorUltrassonico(PinSense1, PinSense2);
}
Sensor::Sensor(uint8_t PinSense1, uint8_t PinSense2, uint8_t PinSense3, uint8_t PinSense4, uint8_t PinSense5) : SensorCor(){
    this->PinSense1 = PinSense1;
    this->PinSense2 = PinSense2;
    this->PinSense2 = PinSense3;
    this->PinSense2 = PinSense4;
    this->PinSense2 = PinSense5;
    SensorCor::iniciaSensorCor(PinSense1, PinSense2, PinSense3, PinSense4, PinSense5);
}

void Sensor::IniSensor_ag(){
    ini = false;
}

int Sensor::luz(){
    SensorRefletancia::leitura(PinSense1);
}
void Sensor::cor_frequencia(uint8_t OP){
    SensorCor::frequencia(OP);
}
void Sensor::cor_filtro(uint8_t RGB){
    switch(RGB){
        case 'R':
            SensorCor::filtroVermelho();
        break;
        case 'G':
            SensorCor::filtroVerde();
        break;
        case 'B':
            SensorCor::filtroAzul();
        break;
        default:
            SensorCor::filtroNulo();
    }
}
int Sensor::cor(){
    SensorCor::leitura();
}
float Sensor::distancia(){
    SensorUltrassonico::leitura(PinSense1, PinSense2);
}
float Sensor::posicao(uint8_t OP){
    if(ini){
        SensorGiroscopioAcelerometro::_ObtemDados();
        switch(OP){
            case 1:
                return SensorGiroscopioAcelerometro::AcelerometroX();
            break;
            case 2:
                return SensorGiroscopioAcelerometro::AcelerometroY();
            break;
            case 3:
                return SensorGiroscopioAcelerometro::AcelerometroZ();
            break;
            case 4:
                return SensorGiroscopioAcelerometro::GiroscopioX();
            break;
            case 5:
                return SensorGiroscopioAcelerometro::GiroscopioY();
            break;
            case 6:
                return SensorGiroscopioAcelerometro::GiroscopioZ();
            break;
            case 7:
                return SensorGiroscopioAcelerometro::temperatura();
            break;
            default:
                return 0;
          }
    }else{
        SensorGiroscopioAcelerometro::iniciaSensorGiroscopioAcelerometro();
        ini=true;
        posicao(OP);
    }
}
int Sensor::conducao(){
    return analogRead(PinSense1);
}
//------------------------------------------------------------------------------------------------------
Led::Led(uint8_t pin_adquiri){
    pino = pin_adquiri;
    pinMode(pino, OUTPUT);
}

void Led::liga(float temp){
    digitalWrite(pino , HIGH);
    delay(temp);
}
void Led::desliga(float temp){
    digitalWrite(pino , LOW);
    delay(temp);
}

