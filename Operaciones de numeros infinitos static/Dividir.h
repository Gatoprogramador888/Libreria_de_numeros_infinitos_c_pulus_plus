#pragma once
#include"Conversor.h"
#include<conio.h>


class Division {
private:
	char* resultado;

private:
	void Conversion(int resultadoint);
	bool Es_Mayor_o_Menor(const listnum& n1, const listnum& n2);
	listnum Restar(listnum& n1, listnum& n2);

public:
	Division(listnum& n1, listnum& n2);
	void SetDivision(listnum& n1, listnum& n2);
	//void SetDivision(listnum n1,listnum n2);
	char* Resultado();
};
