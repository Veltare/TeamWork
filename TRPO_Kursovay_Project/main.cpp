#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <vector>
#include "CrosswordGenerator.h"
#include "RenderingCrossword.h"
#include <clocale>
#include <windows.h>

using namespace std;
struct base
{
	string word;
	string questions;
	int orintation;
	int x, y;
	int number;

};

int main()
{
	//Количество слов в базе 

	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Считывание базы слов
	ifstream wordList;
	wordList.open("WordBase10word.txt");

	string *words;
	string *questions;

	//Заполнение массива строк базой слов 
	string line,buffer;
	int size_list(0);
	while (getline(wordList, buffer))
	{
		size_list++;
	}
	words = new string[size_list];
	questions = new string[size_list];
	wordList.close();
	wordList.open("WordBase10word.txt");
	int count = 0;
	while (getline(wordList, line))
	{
		words[count] = line;
		count++;
	}

	wordList.close();



	//Считывание базы вопросов
	ifstream QuestionsList;
	QuestionsList.open("Issues10quiz.txt");
	count = 0;
	while (getline(QuestionsList, line))
	{
		questions[count] = line;

		count++;
	}
	//Запись в список слов
	base *basic_lib;
	basic_lib = new base[size_list];
	for (int i = 0; i < size_list; i++)
	{
		basic_lib[i].word = words[i];
		basic_lib[i].questions = questions[i];
	}

	QuestionsList.close();
	//Перепись в массив структур

	//Сортировка слов по длинне
	for (int i = 0; i < size_list; i++)
	{
		for (int comparisonIndex = i + 1; comparisonIndex < size_list; comparisonIndex++)
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

	//Расширение динамического вектора
	char puzzle[100][100], solution[100][100], NewBoard[100][200];

	initilizeBoard(puzzle, '#');
	initilizeBoard(NewBoard, '#');
	initilizeBoard(solution, '.');



	printf("\n");

	int **location;
	location = new int*[size_list];
	for (int i = 0; i < size_list; i++)
		location[i] = new int[3];

	
	puzzleMaker(words, solution, size_list, location);
	CreateBoards(NewBoard, solution, location, size_list, words, basic_lib);

	MainManu(size_list, basic_lib, NewBoard);
	
	system("pause");
}