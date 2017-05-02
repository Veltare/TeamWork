#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <vector>
#include "CrosswordGenerator.h"
#include <clocale>

using namespace std;

int main()
{
	//���������� ���� � ���� 
	const int size = 53;

	setlocale(LC_ALL,"Russian");

	//���������� ���� ����
	ifstream wordList;
	wordList.open("WordBase.txt");

	string words[size];

	//�������� ������������� ������� ��� ������ ����� ����
	vector<vector<string>> crossword;

	crossword.resize(size);
	//���������� ������������� �������
	for (int z = 0; z < size; z++)
	{
		crossword[z].resize(size);
	}

	//���������� ������� ����� ����� ���� 
	string line;
	int count = 0;
	while (getline(wordList, line))
	{
		words[count] = line;
		count++;
	}

	wordList.close();

	//���������� ���� �� ������
	for (int i = 0; i < size; i++)
	{
		for (int comparisonIndex = i + 1; comparisonIndex < size; comparisonIndex++)
		{

			if (words[i].length() < words[comparisonIndex].length())
			{
				string biggerWord = words[comparisonIndex];

				words[comparisonIndex] = words[i];
				words[i] = biggerWord;
			}
		}

	}
	//���������,������ � ����� ����� ����
	for (int i = 0; i < size; i++)
	{
		for (int comparisonIndex = i + 1; comparisonIndex < size; comparisonIndex++)

		{
			string result = sharedLetters(words[i],words[comparisonIndex]);
			crossword[i][comparisonIndex] = result;

			cout << result << endl;
		}
	}

	system("pause");
}