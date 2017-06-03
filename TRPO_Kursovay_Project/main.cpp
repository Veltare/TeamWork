#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <vector>
#include <clocale>
#include <windows.h>

#include "CrosswordGenerator.h"
#include "RenderingCrossword.h"

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
	string line,buffer;

	base *basicLib;

	int sizeList(0);

	char puzzle[100][100], solution[100][100], newBoard[100][200];

	while (getline(wordList, buffer))
	{
		sizeList++;
	}
	words = new string[sizeList];
	questions = new string[sizeList];
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
	ifstream questionsList;
	questionsList.open("Issues10quiz.txt");

	count = 0;

	while (getline(questionsList, line))
	{
		questions[count] = line;

		count++;
	}

	
	basicLib = new base[sizeList];
	for (int i = 0; i < sizeList; i++)
	{
		basicLib[i].word = words[i];
		basicLib[i].questions = questions[i];
	}

	questionsList.close();


	for (int i = 0; i < sizeList; i++)
	{
		for (int comparisonIndex = i + 1; comparisonIndex < sizeList; comparisonIndex++)
		{

			if (words[i].length() < words[comparisonIndex].length())
			{
				string biggerWord = words[comparisonIndex];

				words[comparisonIndex] = words[i];
				words[i] = biggerWord;
			}
		}

	}
	int wordLength = words[0].length();


	initilizeBoard(puzzle, '#');
	initilizeBoard(newBoard, '#');
	initilizeBoard(solution, '.');

	printf("\n");

	int **location;
	location = new int*[sizeList];

	for (int i = 0; i < sizeList; i++)
		location[i] = new int[3];

	
	puzzleMaker(words, solution, sizeList, location);
	createBoards(newBoard, solution, location, sizeList, words, basicLib);

	mainManu(sizeList, basicLib, newBoard);
	
	system("pause");
}