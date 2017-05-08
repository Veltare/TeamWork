#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <vector>
#include "CrosswordGenerator.h"
#include "RenderingCrossword.h"
#include <clocale>

using namespace std;

int main()
{
	//Количетсво слов в базе 
	const int size = 10;

	setlocale(LC_ALL,"Russian");

	//Считывание базы слов
	ifstream wordList;
	wordList.open("WordBase.txt");

	string words[size];

	//Создание динамического вектора для записи общих букв
	vector<vector<char>> location;
	//..............................
	vector<vector<char>> puzzle;
	vector<vector<char>> solution;

	

	

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
	int wordlength = words[0].length();

	location.resize(size);
	solution.resize(wordlength);
	puzzle.resize(wordlength);
	//Расширение динамического вектора
	for (int z = 0; z < 3; z++)
	{
		location[z].resize(size);
	}
	for (int z = 0; z < wordlength; z++)
	{
		solution[z].resize(wordlength);
	}
	for (int z = 0; z < wordlength; z++)
	{
		puzzle[z].resize(wordlength);
	}

	initilizeBoard(puzzle, '#', wordlength);
	initilizeBoard(solution, '.', wordlength);

	puzzleMaker(words,solution,size,location, wordlength); //Постройка пазла,вызов других функций

	//Получение,запись и вывод общих букв
	/*
	for (int i = 0; i < size; i++)
	{
		for (int comparisonIndex = i + 1; comparisonIndex < size; comparisonIndex++)

		{
			string result = sharedLetters(words[i],words[comparisonIndex]);
			crossword[i][comparisonIndex] = result;

			cout << result << endl;
		}
	*/


	system("pause");
}