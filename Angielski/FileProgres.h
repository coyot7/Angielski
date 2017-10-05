#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

class FileProgres
{
public:
	enum Odpowiedzi
	{
		BAD,
		OK,
	} odpowiedzUzytkownika;

	fstream plik;
	fstream plikTemp;
	static string postep;
	static string angielskiWyraz;

	FileProgres();
	~FileProgres();

	void SprawdzWiedze(string linia, int numerLini, int iloscLini);
	string DajSlowo(int numerLini);
	void Open(int numerLini);
	void Save(int linia, int iloscLini);
	void Close();
	void ZapisZtempa();
	void CzyszczenieBufora();
};