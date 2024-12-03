#include <iostream>
using namespace std;

class Arr
{
private:
    int tamano = 0;
    string* matriz = new string [0];

public:
    Arr() {};

    void agregar(string _palabra)
    {
        matriz = ampliar(matriz, tamano);
        matriz[tamano] = _palabra;
        tamano++;
    };

    string* ampliar(string *matriz, int tamano) //amplía nuestra matriz
    {
        string *nueva = new string[tamano+1];

        for (int i = 0; i < tamano; i++)
        {
            nueva[i] = matriz[i];
        };
        delete[] matriz;
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

    void borrar(int index)
    {
        matriz = reducir(matriz, index);
        tamano--;
    };
    
    string* reducir(string* matriz, int index)
    {
        string* nueva = new string[tamano - 1];
        for (int i = 0; i < tamano - 1; i++)
        {
            if (i >= index)
            {
                nueva[i] = matriz[i + 1];
            }
            else
            {
                nueva[i] = matriz[i];
            };
        };
        return nueva;
    };

    ~Arr()
    {
        delete[] matriz;
    };
};

void dividir(string* base, Arr *matrizX, int inicio, int fin) //bucle para asignar
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

    dividir(Base, &matriz1, inicio1, fin1); //llama la funcion para asignar
    dividir(Base, &matriz2, inicio2, fin2);
    
    matriz1.imprimir(); //imprime
    cout << endl;
    cout << endl;
    matriz2.imprimir();

    int index;
    cout << endl << "inserta numero para borrar: ";
    cin >> index;

    matriz1.borrar(index);
    cout << endl;
    matriz1.imprimir();
};

/*
========================================================================================================================
  MMP""MM""YMM `7MM"""Mq.  `YMM'   `MM'    `7MMF'  `7MMF'      db      `7MM"""Mq.  `7MM"""Yb.   `7MM"""YMM  `7MM"""Mq.
  P'   MM   `7   MM   `MM.   VMA   ,V        MM      MM       ;MM:       MM   `MM.   MM    `Yb.   MM    `7    MM   `MM.
       MM        MM   ,M9     VMA ,V         MM      MM      ,V^MM.      MM   ,M9    MM     `Mb   MM   d      MM   ,M9
       MM        MMmmdM9       VMMP          MMmmmmmmMM     ,M  `MM      MMmmdM9     MM      MM   MMmmMM      MMmmdM9
       MM        MM  YM.        MM           MM      MM     AbmmmqMA     MM  YM.     MM     ,MP   MM   Y  ,   MM  YM.
       MM        MM   `Mb.      MM           MM      MM    A'     VML    MM   `Mb.   MM    ,dP'   MM     ,M   MM   `Mb.
     .JMML.    .JMML. .JMM.   .JMML.       .JMML.  .JMML..AMA.   .AMMA..JMML. .JMM..JMMmmmdP'   .JMMmmmmMMM .JMML. .JMM.
==========================================================================================================================
*/