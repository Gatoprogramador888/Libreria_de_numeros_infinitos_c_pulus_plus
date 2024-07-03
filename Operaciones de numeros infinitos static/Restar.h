#pragma once
#include"Conversor.h"

class Resta {
private:
	char* resultado = {};
	void Conversion(vector<int> resultadoint, bool negativo);
public:
	Resta(vector<int> n1, vector<int> n2);
	Resta(){};
	void SetResta(vector<int> n1, vector<int> n2);
	char* Resultado();
};
