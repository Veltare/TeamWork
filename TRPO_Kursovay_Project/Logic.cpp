#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int vvod()
{
	int p;
	while (true)
	{

		cin >> p;
		if (cin.good())
		{
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		cout << "Неправильный ввод данных " << endl;
		cin.ignore(10, '\n');
	}
	return p;
}
