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
	const int size = 52;

	setlocale(LC_ALL, "Russian");

	//Считывание базы слов
	ifstream wordList;
	wordList.open("WordBase.txt");

	string words[size];
	string questions[size];

	//Заполнение массива строк базой слов 
	string line;
	int count = 0;
	while (getline(wordList, line))
	{
		words[count] = line;
		count++;
	}

	wordList.close();



	//Считывание базы вопросов
	ifstream QuestionsList;
	QuestionsList.open("Issues.txt");
	count = 0;
	while (getline(QuestionsList, line))
	{
		questions[count] = line;

		count++;
	}
	//Запись в список слов
	base basic_lib[size];
	for (int i = 0; i < size; i++)
	{
		basic_lib[i].word = words[i];
		basic_lib[i].questions = questions[i];
	}

	QuestionsList.close();
	//Перепись в массив структур

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

	//Расширение динамического вектора
	int i, j;
	char puzzle[100][100], solution[100][100], NewBoard[100][200];

	initilizeBoard(puzzle, '#');
	initilizeBoard(NewBoard, '#');
	initilizeBoard(solution, '.');



	printf("\n");

	int location[52][3];

	
	puzzleMaker(words, solution, size, location);
	displayBoards(NewBoard, solution, location, size, words, basic_lib);
	displayQuestions(questions, size);

	int b(0);
	cout << "По какой плоскости решать?" << endl;

	while (true)
	{
		cin >> b;
		switch (b)
		{
		case 1:
		{
			if (location[0][2] == 0)
			{
				cout << "ВОПРОСЫ" << endl << endl;
				int count(0);
				while (count != size)
				{
					cout << "  " << count << " " << basic_lib[count].questions << endl;
					cout << "  " << "Координаты:";
					//cout << arg[count++] << endl;
					cout << "--------------------------------------------------------------------------------------------" << endl;
				}
				break;
			}

		}
		case 0:
		{
			break;
		}
		default:
		{
			cout << "Некорректный ввод" << endl;
		}
		}



		
	}
	system("pause");
}