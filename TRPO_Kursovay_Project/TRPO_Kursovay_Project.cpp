// TRPO_Kursovay_Project.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream issues("Issues.txt");
	ifstream answers("Answers.txt");
    string word[10];
    string issues_mass;

	if (!issues.is_open()) // ���� ���� �� ��� ������
	{
		cout << "���� �� ����� ���� ������ ��� ������\n"; // ���������� ��������������� ���������
		
	}
	if (!answers.is_open()) // ���� ���� �� ��� ������
	{
		cout << "���� �� ����� ���� ������ ��� ������\n"; // ���������� ��������������� ���������

	}
	int i(0);
	while (!answers.eof())
	{
	
		if (i < 10)
		{

			answers >> word[i];
			cout << word[i] << endl;
			i++;

		}
		else break;
		
	
	
	}
	
	int z(0);
	while (getline(issues, issues_mass))
	{
	
		
			cout << issues_mass<<endl;
			z++;
		
	}
	
	system("pause");
    return 0;
}

