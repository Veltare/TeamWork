
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
		cout << "Неправильный ввод данных,Попробуйте другое значение! " << endl;
		cin.ignore(10, '\n');
	}
	return p;
}
// Поиск полей вывода
void SearchFieldsConclusion(char board[][200],int &x_min, int &x_max,int &y_min, int &y_max)
{
	int x1(0), x2(0), x_main(0),y1(1), y2(1);
	bool switcher(1);
	//Поиск координаты(Цикл идет слева и вниз)
	//Поиск наим y
	for (int i = 0; i <= 100; i++)
	{

		

		for (int z = 0; z < 200; z++)
			{
				if (board[i][z] == ' ' || isalpha((unsigned char)board[i][z]) == 1)
				{
					x1 = z;
					y1 = i;
					switcher = false;
					break;
				
				}
		}
		if(switcher==0)
		{
			break;
		}
	}
		
	//Поиск наиб y
	y2 = y1;
	for (int i = 0; i <= 100; i++)
		for (int z = 0; z < 200; z++)
		{
			if (board[i][z] == ' ' || isalpha((unsigned char)board[i][z]) == 1)
			{
				if (y2 < i)
				{
					y2 = i;
				
				}
			}
		}
	//Поиск наим х
	for (int i = 0; i <= 100; i++)
		for (int z = 0; z < 200; z++)
		{
			if (board[i][z] == ' ' || isalpha((unsigned char)board[i][z]) == 1)
			{
				if (x1 > z)
				{
					x1 = z;
				
				}
				
			}
		}
	//Поиск наиб х
	x2 = x1;
	for (int i = 0; i <= 100; i++)
		for (int z = 0; z < 200; z++)
		{
			if (board[i][z] == ' ' || isalpha((unsigned char)board[i][z]) == 1)
			{
				if (x2 < z)
				{
					x2 = z;
				}
			}
		}
	x_min = x1;
	x_max = x2;
	y_min = y1;
	y_max = y2;
}
