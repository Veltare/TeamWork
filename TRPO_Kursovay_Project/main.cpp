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
	//Количетсво слов в базе 
	const int size = 53;

	setlocale(LC_ALL,"Russian");

	//Считывание базы слов
	ifstream wordList;
	wordList.open("WordBase.txt");

	string words[size];

	//Создание динамического вектора для записи общих букв
	vector<vector<string>> crossword;

	crossword.resize(size);
	//Расширение динамического вектора
	for (int z = 0; z < size; z++)
	{
		crossword[z].resize(size);
	}

	//Заполнение массива строк базой слов 
	string line;
	int count = 0;
	while (getline(wordList, line))
	{
		words[count] = line;
		count++;
	}

	wordList.close();

	//Сортировка слов по длинне
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
	//Получение,запись и вывод общих букв
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