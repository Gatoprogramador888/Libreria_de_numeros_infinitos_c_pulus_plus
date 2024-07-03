#pragma once
#include"Conversor.h"

class Division {
private:
	char* resultado;

private:
	void Conversion(int resultadoint);
	bool Es_Mayor_o_Menor(const listnum& n1, const listnum& n2);
	listnum Restar(const listnum& n1, const listnum& n2);

public:
	Division(const listnum& n1, const listnum& n2);
	void SetDivision(const listnum& n1, const listnum& n2);
	//void SetDivision(listnum n1,listnum n2);
	char* Resultado();
};
