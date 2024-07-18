#include "pch.h"
#include "Dividir.h"


bool Division::Es_Mayor_o_Menor(const listnum& n1, const listnum& n2) {
    /*SABER SI N1 ES MAYOR A N2*/
    string N1, N2;

    for (auto i : n1)
    {
        N1 += to_string(i);
    }

    for (auto i : n2)
    {
        N2 += to_string(i);
    }

    size_t CN1 = atoi(N1.c_str());
    size_t CN2 = atoi(N2.c_str());

    if (CN1 < CN2)return false;


    for (size_t i = 0; i < n1.size(); ++i) {
        if (n1[i] != n2[i]) {
            return n1[i] > n2[i];
        }
    }

    if (n1.size() != n2.size()) {
        return n1.size() > n2.size();
    }
    
    return true;
}

listnum Division::Restar(listnum& n1, listnum& n2) {
    /*RESTAR N1 CON N2 PARA IR CONTANDO CUANTO VALE CADA DIVISION*/
    listnum result = n1;
    for (size_t i = n2.size() - 1, j = result.size() - 1; i > 0; --i, --j) {
        result[j] -= n2[i];
        if (result[j] < 0) {
            result[j] += 10;
            result[j - 1] -= 1;
        }
    }
    while (result.size() > 1 && result[0] == 0) {
        result.erase(result.begin());
    }
    return result;
}

Division::Division(listnum& n1, listnum& n2) {
    /*------------------------INICIO-DE-LA-DIVISION----------------------------*/
    listnum resto = n1;
    int cant = 0;
    listnum Resultado;
    /*----------------------RESTAR HASTA CONSEGUIR 0---------------------------*/
        while (Es_Mayor_o_Menor(resto, n2)) {
            Resultado = Restar(resto, n2);
            resto = Resultado;
            cant++;
        }
    Conversion(cant);
    /*---------------------------FIN-DE-LA-DIVISION----------------------------*/
}

void Division::SetDivision(listnum& n1, listnum& n2) {
    /*------------------------INICIO-DE-LA-DIVISION----------------------------*/
    listnum resto = n1;
    int cant = 0;
    listnum Resultado;

    /*----------------------RESTAR HASTA CONSEGUIR 0---------------------------*/
    while (Es_Mayor_o_Menor(resto, n2)) {
        Resultado = Restar(resto, n2);
        resto = Resultado;
        cant++;
    }

    Conversion(cant);
    /*---------------------------FIN-DE-LA-DIVISION----------------------------*/
}

void Division::Conversion(int resultadoint) {
    /*-----------------------INICIO DE CONVERSION----------------*/
    size_t t = sizeof(resultadoint);
    resultado = new char[t + 2];
    char* cadena_a_convertir = new char[t + 2];
    char* resultadostring = new char[t + 2];
    int inicio = 0;
    int punto = 0;

    sprintf(cadena_a_convertir, "%i", resultadoint);

    for (int i = 0; i < t + 2; i++)
    {
        if (punto == 4) {
            resultadostring[inicio] = '.';
            inicio++;
        }
        resultadostring[inicio] = cadena_a_convertir[inicio];
        inicio++;
        punto++;
    }

    resultadostring[t] = '\0';
    strcpy(resultado, resultadostring);
    /*----------FIN-CONVERSION--------------*/
}

char* Division::Resultado() {
    return resultado;
}