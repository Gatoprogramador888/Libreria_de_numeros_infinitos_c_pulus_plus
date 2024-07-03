#include "pch.h"
#include "Restar.h"

Resta::Resta(vector<int> n1, vector<int> n2)
{
    /*----------------------INICIO RESTA----------------------------------*/
   /*con estas variables podremos usar para saber ciertas cosas
   y auxiliarnos*/
    size_t min = (n1.size() < n2.size()) ? n1.size() : n2.size();

    /*en caso de que n2 sea mayor a n1 en el ultimo numero los cambiaremos
    y sabemos si es o no negativo*/
    bool es_negativo = n1[n1.size() - 1] < n2[n2.size() - 1];
    vector<int>resultadoint, aux;

    if (es_negativo)
    {
        aux = n2;
        n2 = n1;
        n1 = aux;
        aux.clear();
    }

    /*despues de acomodar y todo eso el for sera usado para la resta
    de los numeros del usuario y hacer la resta en un vector*/
    for (size_t i = 0; i < min; i++)
    {
        bool es_decimal = n1[i] != -1 || n2[i] != -1;
        int resta = es_decimal ? n1[i] - n2[i] : -1;

        if (resta < 0 && es_decimal)
        {
            resta = abs(resta);
            if (n1.size() < i) n1[i + 1]--;
        }
        resultadoint.push_back(resta);
    }

    Conversion(resultadoint, es_negativo);
    /*----------------------FIN RESTA----------------------------------*/
}

void Resta::SetResta(vector<int> n1, vector<int> n2)
{
    /*----------------------INICIO RESTA----------------------------------*/
   /*con estas variables podremos usar para saber ciertas cosas
   y auxiliarnos*/
    size_t min = (n1.size() < n2.size()) ? n1.size() : n2.size();

    /*en caso de que n2 sea mayor a n1 en el ultimo numero los cambiaremos
    y sabemos si es o no negativo*/
    bool es_negativo = n1[n1.size() - 1] < n2[n2.size() - 1];
    vector<int>resultadoint, aux;
    bool negativo = false;

    if (es_negativo)
    {
        negativo = true;
        aux = n2;
        n2 = n1;
        n1 = aux;
        aux.clear();
    }

    /*despues de acomodar y todo eso el for sera usado para la resta
    de los numeros del usuario y hacer la resta en un vector*/
    for (size_t i = 0; i < min; i++)
    {
        bool es_decimal = n1[i] != -1 || n2[i] != -1;
        int resta = es_decimal ? n1[i] - n2[i] : -1;

        if (resta < 0 && es_decimal)
        {
            resta = abs(resta);
            if (n1.size() < i) n1[i + 1]--;
        }
        resultadoint.push_back(resta);
    }

    Conversion(resultadoint, negativo);
    /*----------------------FIN RESTA----------------------------------*/
}

void Resta::Conversion(vector<int> resultadoint, bool negativo)
{
    /*----------------------INICIO RESTA----------------------------------*/
   /*Creamos las variables para iniciar la conversion de int a char*/
    size_t t = resultadoint.size();
    resultado = new char[t + 2];
    int inicio = 0;
    bool decimal = false;
    //si el usuario puso numeros grandes y el resultado es negativo
    //hacemos que el resultado se vea como negativo
    if (negativo) 
    {
        resultado[0] = '-';
        inicio++;
    }

    /*Iniciamos la conversion del resultado que usuario puso en la resta*/
    for (size_t i = resultadoint.size() - 1; i > 0; i--)
    {
        decimal = resultadoint[i] != -1;
        if (resultadoint[i] != -1)
            resultado[inicio] = static_cast<char>(resultadoint[i] + '0');
        else
            resultado[inicio] = '.';
        inicio++;
    }

    for (size_t i = 0; i < t; i++) {
        if (resultado[i] - '0' >= 0)continue;
        else resultado[i] = NULL;
    }

    resultado[t] = '\0';
    /*----------------------FIN RESTA----------------------------------*/
}

char* Resta::Resultado()
{
    return resultado;
}