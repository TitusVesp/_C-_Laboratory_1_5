#pragma once
#include <iostream>
#include <string>

using namespace std;

class Areph
{
private:
	char* expressionToParse;
	char peek()
	{
		return *expressionToParse;
	}

	char get()
	{
		return *expressionToParse++;
	}

	int Number();
	int Factor();
	int Term();
public:
	Areph(char* str)
	{
		expressionToParse = str;
	}

	int Expression();
};


void RNP();
int Strlength(char* str);

int Func();