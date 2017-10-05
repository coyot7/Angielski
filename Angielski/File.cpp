#include "stdafx.h"
#include "File.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

int File::liczbaSlowek = 0;

File::File()
{
}


File::~File()
{
}

void File::Open()
{
	plik.open("Dane.txt", ios::in);
	if (plik.good() == true)
	{
		cout << "-> Uzyskano dostep do pliku" << endl;
	}
	else
	{
		cout << "-> Problem z otwarciem pliku ;((" << endl;
	}
}

void File::Close()
{
	plik.close();
}

int File::LiczbaSlowek()
{
	string line;
	while (!plik.eof())
	{
		getline(plik, line);
		liczbaSlowek++;
	}
	cout << "-> Liczba slowek w bazie: " << liczbaSlowek << endl;
	cout << "##############################" << endl;
	//ustawienie czytanie pliku od 1 bajtu
	plik.seekg(0);

	return liczbaSlowek;
}

string File::DajSlowo(int numerLini)
{
	string line;

	for (int i = 0; i < numerLini; i++)
	{
		getline(plik, line);
	}
	return line;
}