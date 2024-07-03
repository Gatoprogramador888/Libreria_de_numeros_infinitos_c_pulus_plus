#include "pch.h"
#include "Conversor.h"

vector<int> ConversionI::STOII(const char* texto)
{
    /*-----------------------INICIO-STOII--------------------*/

    /*-------------------------------------------------------*/
    /*                                                       */
    /*  Usa en caso de que sea suma o resta esto hara que    */
    /*  el numero se haga al reves y se convierta en lista   */
    /*                                                       */    
    /*-------------------------------------------------------*/

    vector<int> lista;
    STOICHECK(texto);

    for (size_t i = static_cast<size_t>(strlen(texto)-1); i > 0; i--)
    {
        if (texto[i] != '.')
            lista.push_back(texto[i] - '0');
        else lista.push_back(-1);
    }

    return lista;
    /*------------------FIN-STOII----------------------*/
}

vector<int> ConversionI::STOI(const char* texto)
{
    /*------------------INICIO-DE-STOI-----------------*/

    /*-------------------------------------------------*/
    /*      usarse en caso de que quiera saber el      */
    /*  resultado al reves de digitos ya que la suma   */
    /*       y la resta hacen el proceso al reves      */
    /*-------------------------------------------------*/
    vector<int> lista;
    STOICHECK(texto);

    for (int i = 0; i < strlen(texto); i++)
    {
        if (texto[i] != '.')lista.push_back(texto[i] - '0');
        else lista.push_back(-1);
    }

    return lista;
    /*--------------------FIN-STOI-------------------*/
}

vector<int> ConversionI::STOIM(const char* texto)
{
    /*--------------------INICIO-STOIM---------------*/

    /*-----------------------------------------------*/
    /*      Usar en caso de multiplicar o dividir    */
    /*-----------------------------------------------*/
    vector<int> lista;
    STOICHECK(texto);

    for (int i = 0; i < strlen(texto); i++)
    {
        if (texto[i] != '.')lista.push_back(texto[i] - '0');
        else continue;
    }

    return lista;
    /*---------------------FIN-STOIM-----------------*/
}

void ConversionI::STOICHECK(const char* texto)
{
    /*------------------INICIO-STOICHECK---------------*/

    /*-------------------------------------------------*/
    /*  Esta funcion se usa en todas las anteriores    */
    /*  Esto para verificar que no esten inconvenientes*/
    /*  De colocar otro caracter que no sea numeros o  */
    /*  El punto para inicio de un numero decimal      */
    /*-------------------------------------------------*/
    size_t puntos = 0, pospunto = 0;;
    for (size_t i = static_cast<size_t>(strlen(texto)) - 1; i > 0; i--)
    {
        if (!isdigit(texto[i]) && texto[i] != '.' || puntos > 1) {
            throw STOIERR(texto[i]);
        }
        if (texto[i] == '.')
        {
            puntos++;
            pospunto = i;
        }
    }

    /*-----------------FIN-STOICHECK-------------------*/
}

const char* ConversionI::STOIERR(char error)
{
    /*------------------INICIO-STOIERR----------------*/

    /*------------------------------------------------*/
    /*  En caso de error en STOICHECK se envia este   */
    /*  Error para avisarle al programador del error  */
    /*  Dira la letra que ocasiono el throw           */
    /*------------------------------------------------*/
    char* errorstring = new char[50];
    strcpy(errorstring, "Error conversion string to int: ");
    errorstring[strlen(errorstring) + 1] = error;
    errorstring[strlen(errorstring) + 2] = '\0';
    return errorstring;
    /*------------------FIN-STOIERR-------------------*/
}

void ConversionI::ajustarPrecision(char* numero) {
    /*---------------INICIO-AJUSTARPRECISION----------*/

    /*------------------------------------------------*/
    /*  Para ajustar de varias manera un numero.      */
    /*  Decimal o entera a continuacion lo que hace:  */
    /*  Agregar 2 ceros y un punto a numero entero.   */
    /*  Agregar 1 o 2 ceros a numero con punto sin    */
    /*                      Decimales.                */
    /*  Eliminar decimales si sobre pasan de dos      */
    /*                  Decimales.                    */
    /*  En caso de tener todo correcto no se hara nada*/
    /*------------------------------------------------*/
    if (numero == NULL) {
        throw "Valor Nulo vuelvalo un array";
    }
    char* punto = strchr(numero, '.'); // Buscar el punto decimal
    int64_t pospunto = punto - numero;
    // Si no se encuentra el punto decimal o no hay al menos dos caracteres después de él, agregamos dos decimales
    if (punto == nullptr) {
        strcat(numero, ".00");
        return;
    }
    else if (abs(static_cast<int>(strlen(punto)) - pospunto) == 1) {
        strcat(punto, "0");
    }
    else if (abs(static_cast<int>(strlen(punto)) - pospunto) == 0) {
        strcat(punto, "00");
    }
    else {
        punto[3] = '\0';
    }
    /*-----------------FIN-AJUSTARPRECISION-------------*/
}