/*
Puente h para los motores,
Sensores de color TCS3200,
MicroSevo *Pendiente*,
Sensor Utrasonido,
Pantalla LCD
*/

#include <Wire.h>
#include <LiquidCrystal.h>
#include <LCD.h>

class SensorColor
{
public:
    int pines[4];
    int out;
    int output[4];

    //              R  G  B  SC
    int color[4] = {0, 0, 0, 0};
    // 4 pines un pin de output y 4 pines de entrada
    SensorColor(int s0, int s1, int s2, int s3, int o, int OUTPUT1, int OUTPUT2, int OUTPUT3, int OUTPUT4)
    {
        this->pines[0] = s0;
        this->pines[1] = s1;
        this->pines[2] = s2;
        this->pines[3] = s3;
        this->out = o;
        this->output[0] = OUTPUT1;
        this->output[1] = OUTPUT2;
        this->output[2] = OUTPUT3;
        this->output[3] = OUTPUT4;
    };
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
    int trigger;
    int echo;
    float distancia;
    SensorUtrasonido(int trig, int ec)
    {
        this->trigger = trig;
        this->echo = ec;
    }
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
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7);
class PantallaLCD
{
public:
    void setup()
    {
        lcd.setbacklight(3, POSITIVE);
        lcd.Backlight(HIGH);
        lcd.begin(16, 2);
        lcd.clear();
    }
    void imprimirArriba(String texto)
    {
        lcd.setCursor(0, 0);
        lcd.print(texto);
    }
    void imprimirAbajo(String texto)
    {
        lcd.setCursor(0, 1);
        lcd.print(texto);
    }
};

SensorColor sensorColor1(1, 2, 3, 4, 5, 6, 7, 8, 9);
PuenteH puenteH;
SensorUtrasonido sensorUtrasonido1(13, 12);
PantallaLCD pantallaLCD;

void setup()
{
    Serial.begin(9600);
    //sensorColor.setup();
    //sensorUtrasonido1.setup();
    pantallaLCD.setup();
}

void loop()
{
    pantallaLCD.imprimirArriba("Hola");
    delay(100);
    pantallaLCD.imprimirAbajo("Mundo");
}
