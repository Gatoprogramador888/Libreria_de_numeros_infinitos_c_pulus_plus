#pragma once
#include"Conversor.h"

class Suma
{
private:
	//Private variables
	char* numeros = {};

private:
	//private metodos
	vector<int> suma;
	void Conversion(vector<int> resultadoint);

public:
	//public metodos
	Suma(vector<int> n1, vector<int> n2);
	Suma() {};
	void SetSuma(vector<int> n1, vector<int> n2);
	char* Resultado();

};
