#pragma once
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

class Losowanie
{
public:
	fstream plik;
	int * tabWynikow;

	Losowanie();
	~Losowanie();
	int Start(int iloscLini);
	string DajSlowo(int numerLini);
	static void StartMaszynyLosujacej();
	static int WylosojLiczbe(int iloscLiczb);
};

