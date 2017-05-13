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
	//���������� ���� � ���� 
	const int size = 52;

	setlocale(LC_ALL,"Russian");

	//���������� ���� ����
	ifstream wordList;
	wordList.open("WordBase.txt");

	string words[size];

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
	int wordlength = words[0].length();

	//���������� ������������� �������
	int i, j;
	char puzzle[100][100], solution[100][100];

	initilizeBoard(puzzle, '#');
	initilizeBoard(solution, '.');


	printf("\n");

	int location[52][3];


	puzzleMaker(words, solution, size, location);

	displayBoards(puzzle, solution, location, size, words);
	//displayBoards(puzzle, solution, location, size, words, wordlength);
	//���������,������ � ����� ����� ����
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