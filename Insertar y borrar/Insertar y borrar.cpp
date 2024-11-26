#include <iostream>
using namespace std;

class Arr
{
private:
    int tamano = 0;
    int capacidad;
    string* matriz = new string [tamano];

public:
    Arr() {};

    void agregar(string _palabra)
    {
        matriz = ampliar(matriz, tamano);
        matriz[tamano] = _palabra;
        tamano++;
    };

    string* ampliar(string *matriz, int tamano)
    {
        string *nueva = new string[tamano+1];

        for (int i = 0; i < tamano; i++)
        {
            nueva[i] = matriz[i];
        };
        return nueva;
    };

    void imprimir()
    {
        cout << " ===leyendo array===" << " tam vector: " <<tamano << endl;
        for (int i = 0; i < tamano; i++)
        {
            cout << matriz[i] << " | ";
        };
    };

};

void dividir(string* base, Arr *matrizX, int inicio, int fin)
{
    
    for (int i = inicio; i < fin; i++)
    {
        matrizX->agregar(base[i]);
    };

};

int main()
{
    string Base[10] = { "Cero","Uno", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho", "Nueve" };
    Arr matriz1;
    Arr matriz2;
    
    int corte;
    cout << "Ingresa un numero: ";
    cin >> corte;

    int fin1 = corte;
    int inicio1 = 0;

    int fin2 = 10;
    int inicio2 = fin1;

    cout << fin1 << endl;
    cout << fin2 << endl;


    dividir(Base, &matriz1, inicio1, fin1);
    dividir(Base, &matriz2, inicio2, fin2);
    
    matriz1.imprimir();
    cout << endl;
    cout << endl;
    matriz2.imprimir();

};
