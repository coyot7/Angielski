#include "stdafx.h"
#include "Losowanie.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Losowanie::Losowanie()
{
}


Losowanie::~Losowanie()
{
	delete tabWynikow;
}

int Losowanie::Start(int iloscLini)
{
	//zapis pukt do tablicy
	cin.clear();
	cin.sync();
	plik.open("postepWiedzy.txt", ios::in);
	if (plik.good() == true)
	{
		string linia = "";
		char znak = ';';
		string temp;
		tabWynikow = new int[iloscLini];
		for (int i = 0; i < iloscLini; i++)
		{
			linia = "";
			temp = "";
			linia = DajSlowo(i + 1);
			size_t	pozycja = linia.find(znak);
			temp.insert(0, linia, 0, pozycja);
			int punkty = atoi(temp.c_str());
			tabWynikow[i] = punkty;
		}
	}
	plik.close();
	//

	//sprawdzenie zapisanych pkt w tablicy dynamicznej
	/*for (int i = 0; i < iloscLini; i++)
	{
		cout << tabWynikow[i] << endl;
	}
	system("pause");*/
	

	return 0;
}

string Losowanie::DajSlowo(int numerLini)
{
	string line;
	plik.seekg(0);
	
	for (int i = 0; i < numerLini; i++)
	{
		line = "";
		getline(plik, line);
	}
	return line;
}

void Losowanie::StartMaszynyLosujacej()
{
	srand(time(NULL));
}

int Losowanie::WylosojLiczbe(int zakresLiczb)
{
	int wylosowanaLiczba = rand() % zakresLiczb + 1; //%zakres liczb + liczba startowa

	return wylosowanaLiczba;
}