/*
Puente h para los motores,
Sensores de color TCS3200,
MicroSevo *Pendiente*,
Sensor Utrasonido,
Pantalla LCD
*/

//global variables
const int s0 = 1;
const int s1 = 2;
const int s2 = 3;
const int s3 = 4;
const int out = 5;
int OUTPUT4 = 6;
int OUTPUT3 = 7;
int OUTPUT2 = 8;
int OUTPUT1 = 9;
int rojo = 0;
int verde = 0;
int azul = 0;
int SC = 0;

class SensorColor
{
public:
    int pines[5] = {s0, s1, s2, s3};
    int out = 5;
    int output[4] = {OUTPUT1, OUTPUT2, OUTPUT3, OUTPUT4};
    int color[4] = {rojo, verde, azul, SC};
    void setup()
    {
        for (int i = 0; i < 4; i++)
        {
            pinMode(pines[i], OUTPUT);
            digitalWrite(pines[i], LOW);
        }
        pinMode(out, INPUT);
        for (int i = 0; i < 4; i++)
        {
            pinMode(output[i], OUTPUT);
            digitalWrite(output[i], LOW);
        }
        digitalWrite(pines[0], HIGH);
        digitalWrite(pines[1], HIGH);
    }
    void LecturaColor()
    {
        for (int i = 0; i < 4; i++)
        {
            color[i] = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
        }
    }
};

class PuenteH
{
public:
    int motorD[2] = {3, 4};
    int motorI[2] = {5, 6};
    int VelocidadesD = 7;
    int VelocidadesI = 8;
    void setup()
    {
        for (int i = 0; i < 2; i++)
        {
            pinMode(motorD[i], OUTPUT);
            pinMode(motorI[i], OUTPUT);
        }
        pinMode(VelocidadesD, OUTPUT);
        pinMode(VelocidadesI, OUTPUT);
    }
    void Avanzar(int velocidad)
    {
        digitalWrite(motorD[0], HIGH);
        digitalWrite(motorD[1], LOW);
        digitalWrite(motorI[0], LOW);
        digitalWrite(motorI[1], HIGH);
        analogWrite(VelocidadesD, velocidad);
        analogWrite(VelocidadesI, velocidad);
    }
    void Retroceder(int velocidad)
    {
        digitalWrite(motorD[0], LOW);
        digitalWrite(motorD[1], HIGH);
        digitalWrite(motorI[0], HIGH);
        digitalWrite(motorI[1], LOW);
        analogWrite(VelocidadesD, velocidad);
        analogWrite(VelocidadesI, velocidad);
    }
    void Detener()
    {
        digitalWrite(motorD[0], LOW);
        digitalWrite(motorD[1], LOW);
        digitalWrite(motorI[0], LOW);
        digitalWrite(motorI[1], LOW);
        analogWrite(VelocidadesD, 0);
        analogWrite(VelocidadesI, 0);
    }
    void Derecha()
    {
        digitalWrite(motorD[0], HIGH);
        digitalWrite(motorD[1], LOW);
        digitalWrite(motorI[0], LOW);
        digitalWrite(motorI[1], HIGH);
        analogWrite(VelocidadesD, 255);
        analogWrite(VelocidadesI, 255);
    }
    void Izquierda()
    {
        digitalWrite(motorD[0], LOW);
        digitalWrite(motorD[1], HIGH);
        digitalWrite(motorI[0], HIGH);
        digitalWrite(motorI[1], LOW);
        analogWrite(VelocidadesD, 255);
        analogWrite(VelocidadesI, 255);
    }
};

class SensorUtrasonido
{
public:
    int trigger = 13;
    int echo = 12;
    float distancia = 0;
    void setup()
    {
        pinMode(trigger, OUTPUT);
        pinMode(echo, INPUT);
    }
    void Lectura()
    {
        digitalWrite(trigger, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigger, LOW);
        distancia = pulseIn(echo, HIGH) / 58.0;
        Serial.println(distancia);
    }
};

SensorColor sensorColor;
PuenteH puenteH;
SensorUtrasonido sensorUtrasonido;
void setup()
{
    Serial.begin(9600);
    //sensorColor.setup();
    sensorUtrasonido.setup();
}

void loop()
{
    sensorUtrasonido.Lectura();
    delay(200);
}
