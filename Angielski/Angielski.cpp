// Angielski.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "File.h"
#include <string>
#include "FileProgres.h"
#include "Losowanie.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	string linia;
	File file;
	FileProgres fileProgres;
	Losowanie los;
	int losowanieWyrazu = 0;
	int iloscLini = 0;
	Losowanie::StartMaszynyLosujacej();

	file.Open(); //dane.txt
	iloscLini = file.LiczbaSlowek();
	file.Close();

	for (int i = 0; i < 10; i++)
	{
		cin.clear();
		cin.sync();
		file.Open(); //dane.txt
		los.Start(iloscLini);
		losowanieWyrazu = Losowanie::WylosojLiczbe(iloscLini);

		linia = file.DajSlowo(losowanieWyrazu);

		//cout << linia <<endl;
		fileProgres.SprawdzWiedze(linia, losowanieWyrazu - 1, iloscLini - 1);
		file.Close();

		cin.get();
	}

	return 0;
}

