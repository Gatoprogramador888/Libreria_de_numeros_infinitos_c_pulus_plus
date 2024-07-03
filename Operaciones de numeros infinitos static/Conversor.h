#pragma once

#include<string.h>
#include<string>
#include<vector>
#include<iostream>
#pragma warning(disable : 4996)
using namespace std;

typedef vector<int> listnum;


class ConversionI
{
private:
	void STOICHECK(const char* texto);
public:
	//string a int invertido
	vector<int> STOII(const char* texto);
	//string a int
	vector<int> STOI(const char* texto);
	//string a int multiplicado
	vector<int> STOIM(const char* texto);
	//string a int erroneo
	const char* STOIERR(char error);
	void ajustarPrecision(char* numero);
};
