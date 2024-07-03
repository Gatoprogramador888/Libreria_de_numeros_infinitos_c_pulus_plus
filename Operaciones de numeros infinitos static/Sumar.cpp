#include "pch.h"
#include "Sumar.h"

Suma::Suma(vector<int> n1, vector<int> n2)
{
    /*----------------------ININICIO SUMA----------------------------------*/
    vector<int>resultadoint;
    int resto = 0;
    int suma = 0;
    bool es_decimal = false;
    size_t min = (n1.size() < n2.size()) ? n1.size() : n2.size();
    size_t max = (n1.size() > n2.size()) ? n1.size() : n2.size();

    /*Iniciamos el for de los numeros del usuario  eh iniciamos con su suma*/
    for (int i = 0; i < min; i++)
    {
        es_decimal = n1[i] != -1 || n2[i] != -1;
        suma = es_decimal ? (n1[i] + n2[i] + resto) % 10 : -1;
        resto = es_decimal ? (n1[i] + n2[i] + resto) / 10 : resto;

        resultadoint.push_back(suma);
    }

    vector<int>aux = (max == n1.size()) ? n1 : n2;
    for (size_t i = min; i < max; i++)
    {
        suma = aux[i] + resto;
        resultadoint.push_back(suma % 10);
        resto = suma / 10;
    }

    bool restante = resto > 0;
    if (restante)resultadoint.push_back(resto);

    Conversion(resultadoint);
    /*----------------------FIN SUMA----------------------------------*/
}

void Suma::SetSuma(vector<int> n1, vector<int> n2)
{
    /*----------------------INICIO SUMA----------------------------------*/
    vector<int>resultadoint;
    int resto = 0;
    int suma = 0;
    bool es_decimal = false;
    size_t min = (n1.size() < n2.size()) ? n1.size() : n2.size();
    size_t max = (n1.size() > n2.size()) ? n1.size() : n2.size();

    /*Iniciamos el for de los numeros del usuario  eh iniciamos con su suma*/
    for (int i = 0; i < min; i++)
    {
        es_decimal = n1[i] != -1 || n2[i] != -1;
        suma = es_decimal ? (n1[i] + n2[i] + resto) % 10 : -1;
        resto = es_decimal ? (n1[i] + n2[i] + resto) / 10 : resto;

        resultadoint.push_back(suma);
    }

    vector<int>aux = (max == n1.size()) ? n1 : n2;
    for (size_t i = min; i < max; i++)
    {
        suma = aux[i] + resto;
        resultadoint.push_back(suma % 10);
        resto = suma / 10;
    }

    bool restante = resto > 0;
    if (restante)resultadoint.push_back(resto);
    resultadoint.push_back(0);

    Conversion(resultadoint);
    /*----------------------FIN SUMA----------------------------------*/
}

void Suma::Conversion(vector<int> resultadoint)
{
    /*----------------------INICIO CONVERSION----------------------------------*/
    size_t t = resultadoint.size();
    numeros = new char[t + 1];
    int inicio = 0;
    bool decimal;
    auto itl = resultadoint.rbegin();

    for (size_t i = 0; i < t; ++i)
    {
        decimal = *itl != -1;
        numeros[i] = decimal ? static_cast<char>(*itl + '0') : '.';
        ++itl;
    }

    numeros[t] = '\0';
    /*----------------------FIN CONVERSION----------------------------------*/
}

char* Suma::Resultado()
{
    return numeros;
}
