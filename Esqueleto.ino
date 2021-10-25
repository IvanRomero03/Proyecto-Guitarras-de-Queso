
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

Componente componente;

void setup()
{
    Serial.begin(9600);
    componente.setup();
}

void loop()
{
    componente.Metodo();
}
