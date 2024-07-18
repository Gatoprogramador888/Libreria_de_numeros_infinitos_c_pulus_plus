#include "pch.h"
#include "Multiplicar.h"


Multiplicacion::Multiplicacion(vector<int> n1, vector<int> n2)
{
    /*------------------INICIO-DE-LA-MULTIPLICACION-------------------*/
    size_t n = n1.size();
    size_t m = n2.size();
    std::vector<int> result(n + m, 0); // Inicializar el resultado con ceros
    // Multiplicar cada dígito de num1 por cada dígito de num2
    for (size_t i = n - 1; i > 0; --i) {
        for (size_t j = m - 1; j > 0; --j) {
            int product = n1[i] * n2[j];
            int sum = product + result[i + j + 1];

            result[i + j + 1] = sum % 10; // Almacenar el dígito actual
            result[i + j] += sum / 10;    // Propagar el resto
        }
    }

    
    // Eliminar ceros iniciales del resultado
    while (result.size() > 1 && result[0] == 0) {
        result.erase(result.begin());
    }
    
    Conversion(result);
    /*--------------------FIN-DE-LA-MULTIPLICACION-------------------*/
}

void Multiplicacion::SetMultiplicacion(vector<int> n1, vector<int> n2)
{
    /*------------------INICIO-DE-LA-MULTIPLICACION-------------------*/
    size_t n = n1.size();
    size_t m = n2.size();
    std::vector<int> result(n + m, 0); // Inicializar el resultado con ceros

    // Multiplicar cada dígito de num1 por cada dígito de num2
    for (size_t i = n - 1; i > 0; --i) {
        for (size_t j = m - 1; j > 0; --j) {
            int product = n1[i] * n2[j];
            int sum = product + result[i + j + 1];

            result[i + j + 1] = sum % 10; // Almacenar el dígito actual
            result[i + j] += sum / 10;    // Propagar el resto
        }
    }

    // Eliminar ceros iniciales del resultado
    while (result.size() > 1 && result[0] == 0) {
        result.erase(result.begin());
    }
    Conversion(result);
    /*--------------------FIN-DE-LA-MULTIPLICACION-------------------*/
}

void Multiplicacion::Conversion(vector<int> resultadoint)
{
    /*-----------------INICIO-CONVERSION--------------------*/

    for (auto i : resultadoint)
    {
        cout << i;
    }
    cout << endl;

    size_t t = resultadoint.size();
    resultado = new char[t + 3];
    int inicio = 0;
    int punto = 0;

    for (size_t i = 0; i < resultadoint.size(); i++) 
    {

        if (punto != 2) resultado[inicio] = static_cast<char>(resultadoint[i] + '0');
        else 
        {
            resultado[inicio++] = '.';
            resultado[inicio] = static_cast<char>(resultadoint[i] + '0');
        }
        inicio++;
        punto++;
    }
    resultado[t] = '\0';

    /*--------------FIN-DE-LA-CONVERSION-----------------------*/
}

char* Multiplicacion::Resultado()
{
    return resultado;
}