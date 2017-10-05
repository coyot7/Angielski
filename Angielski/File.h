#pragma once
#include <fstream>
#include <string>

using namespace std;

class File
{
public:

	fstream plik;
	static int liczbaSlowek;
	File();
	~File();

	void Open();
	void Close();
	int LiczbaSlowek();
	string DajSlowo(int numerLini);
};