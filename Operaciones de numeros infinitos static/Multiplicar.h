#pragma once
#include"Conversor.h"

class Multiplicacion
{
private:
	char* resultado;
	void Conversion(vector<int> resultadoint);

public:

	Multiplicacion(vector<int> n1, vector<int> n2);
	void SetMultiplicacion(vector<int> n1, vector<int> n2);
	char* Resultado();
};
