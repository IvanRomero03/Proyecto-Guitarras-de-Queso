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
int OUTPUT4 = 12;
int OUTPUT3 = 11;
int OUTPUT2 = 10;
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

class Componente
{
public:
    int pines[n];
    int out;
    int output[k];
    int Salida;
    void setup()
    {
        //Setup puede cambiar y es muy posible que lo haga para cada componente
        for (int i = 0; i < n; i++)
        {
            pinMode(pines[i], OUTPUT);
            digitalWrite(pines[i], LOW);
        }
        pinMode(out, INPUT);
        for (int i = 0; i < k; i++)
        {
            pinMode(output[i], OUTPUT);
            digitalWrite(output[i], LOW);
        }
        digitalWrite(pines[0], HIGH);
        digitalWrite(pines[1], HIGH);
    }
    void Metodo()
    {
        //Los metodos son las funciones propias del componente
    }
};

void setup()
{
    Serial.begin(9600);
    SensorColor sensorColor;
    sensorColor.setup();
}

void loop()
{
}
