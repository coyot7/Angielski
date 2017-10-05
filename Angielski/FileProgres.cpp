#include "stdafx.h"
#include "FileProgres.h"
#include <Windows.h>


string FileProgres::postep;
string FileProgres::angielskiWyraz;

FileProgres::FileProgres()
{
	//sprawdzenie czy istnieje plik postepu
	plik.open("postepWiedzy.txt", ios::in);
	if (plik.good() == true)
	{
		plik.close();
	}
	//tworzenie nowego czystego pliku
	else
	{
		plik.open("postepWiedzy.txt", ios::out);
		plik.close();
	}
}


FileProgres::~FileProgres()
{
}

void FileProgres::SprawdzWiedze(string linia, int numerLini, int iloscLini)
{
	char znak = ';';
	size_t	pozycja = linia.find(znak);
	//cout << "Srednik jest na pozcyji: " << pozycja << endl;
	string polskiWyraz = "";
	string wyrazUzytkownika = "";
	angielskiWyraz = "";

	polskiWyraz.insert(0, linia, 0, pozycja);
	angielskiWyraz.insert(0, linia, pozycja + 1, linia.length());

	system("cls");
	cin.clear();
	cin.sync();
	cout << polskiWyraz << ":" << endl;
	getline(cin, wyrazUzytkownika);
	HANDLE kolorTekstu;
	kolorTekstu = GetStdHandle(STD_OUTPUT_HANDLE);
	if (angielskiWyraz.compare(wyrazUzytkownika) == 0)
	{
		//zielony
		SetConsoleTextAttribute(kolorTekstu, 10);
		cout << "        /" << endl;
		cout << "OK     /" << endl;
		cout << "     \\/" << endl;
		//domyslny bialy kolor
		SetConsoleTextAttribute(kolorTekstu, 7);
		odpowiedzUzytkownika = Odpowiedzi::OK;
	}
	else
	{
		SetConsoleTextAttribute(kolorTekstu, 12);
		cout << "        \\ /" << endl;
		cout << "WRONG    X   " << endl;
		cout << "        / \\  " << endl;
		cout << "\nPoprawny wyraz:  " << angielskiWyraz << endl;
		SetConsoleTextAttribute(kolorTekstu, 7);
		odpowiedzUzytkownika = Odpowiedzi::BAD;
	}
	CzyszczenieBufora();
	Open(numerLini);
	//Close();
	CzyszczenieBufora();
	Save(numerLini, iloscLini);
	//Close();
	ZapisZtempa();
}

void FileProgres::Open(int numerLini)
{
	plik.open("postepWiedzy.txt", ios::in);	

	if (plik.good() == true)
	{
		string linia;
		linia = DajSlowo(numerLini + 1);

		char znak = ';';
		size_t	pozycja = linia.find(znak);

		postep = "";
		postep.insert(0, linia, 0, pozycja);
	}
	else
	{
		cout << "-> Problem z otwarciem pliku postepu ;((" << endl;
	}
	plik.close();
}

void FileProgres::Save(int linia, int iloscLini)
{
	plik.open("postepWiedzy.txt", ios::in |ios::out);
	plikTemp.open("temp.txt", ios::out);
	string liniaTemp = "";
	for (int i = 0; i < linia; i++)
	{
		liniaTemp = "";
		getline(plik, liniaTemp);
		plikTemp << liniaTemp << endl;
	}
	int punkty = atoi(postep.c_str());
	if ((punkty > 0) && (odpowiedzUzytkownika == OK))
	{
		plikTemp << punkty + 1 << ";" << angielskiWyraz << endl;
		getline(plik, liniaTemp);
	}
	else
	{
		plikTemp << "1;" << angielskiWyraz << endl;
		getline(plik, liniaTemp);
	}
	for (int i = linia; i < iloscLini; i++)
	{
		liniaTemp = "";
		getline(plik, liniaTemp);
		plikTemp << liniaTemp << endl;
	}

	plikTemp.close();
	plik.close();
}

void FileProgres::Close()
{
	plik.close();
}

string FileProgres::DajSlowo(int numerLini)
{
	string line;
	CzyszczenieBufora();
	plik.seekg(0);

	for (int i = 0; i < numerLini; i++)
	{
		line = "";
		getline(plik, line);
	}
	return line;
}

void FileProgres::ZapisZtempa()
{
	remove("postepWiedzy.txt");
	rename("temp.txt", "postepWiedzy.txt");
}

void FileProgres::CzyszczenieBufora()
{
	cin.clear();
	cin.sync();
}