#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <vector>
#include <clocale>
#include <cctype>
#include <stdlib.h>
#include <sstream>

#include "RenderingCrossword.h"

struct base
{
	string word;
	string questions;
	int orintation;
	int x, y;
	int number;

};
using namespace std; 



void initilizeBoard(char board[][100], char c) {

	int i, j;

	for (i = 0; i <= 99; i++)
		for (j = 0; j <= 99; j++) {
			board[i][j] = c; 
		}

	return;
}
void initilizeBoard(char board[][200], char c) {

	int i, j;

	for (i = 0; i <= 99; i++)
		for (j = 0; j <= 199; j++) {
			board[i][j] = c;
		}

	return;
}
void display(char sayings[][102], int size) { 
	int i = 0;
	for (i = 0; i<(size); i++) {
		printf("%s\n", sayings[i]);
	}
}

void displayBoards(char board[][200], char solution[][100], int location[][3], int wordcount, string words[], struct base basic_base[])
 {
	int i, j,k(0);
	for (i = 0; i <= 99; i++) {
		for (j = 0; j <= 99; j++) {
			cout << solution[i][j];
			if (isalpha((unsigned char)solution[i][j]))
			{

				board[i][k] = ' ';
				board[i][k+1] = ' ';

				
			}
			k += 2;
		}
		k = 0;
		cout << endl;
	}
	//Заполнение пазла цифрами(Вертикаль)
	int count_number(1), cif1(1), cif2(0);
	for (i = 0; i < wordcount; i++) {

		if (location[i][2] == -1) continue;

		if (location[i][2] == 0) {
			if (board[location[i][1]][location[i][0] * 2 + 1] == ' ')
			{


				if (i < 10)
				{
					board[location[i][1]][location[i][0] * 2 + 1] = count_number + 48;

					cout << count_number;
					count_number++;
				}
				else
				{
					if (cif2 < 10)
					{

						board[location[i][1]][location[i][0] * 2] = cif1 + 48;
						board[location[i][1]][location[i][0] * 2 + 1] = (cif2++) + 48;
					}
					else
					{
						cif1++;
						cif2 = 0;

					}
				}


			}
		}
	}
	for (i = 0; i < wordcount; i++){
		if (location[i][2] == -1) continue;
		if (location[i][2] == 1) {
			if (board[location[i][1]][location[i][0] * 2 + 1] == ' ')
			{
				if (i < 10)
				{
					board[location[i][1]][location[i][0] * 2 + 1] = count_number + 48;

					cout << count_number;
					count_number++;
				}
				else
				{
					if (cif2 < 10)
						{
						board[location[i][1]][location[i][0] * 2] = cif1 + 48;
						board[location[i][1]][location[i][0] * 2 + 1] = (cif2++) + 48;
					}
					else
					{
						cif1++;
						cif2 = 0;

					}
				}


			}
			else 
			{
				cout << "x :" << location[i][1] << "  y :" << location[i][0] << endl;
				cout << "Промах!" << endl;
				continue;
			}
			}
			
	}
	//Заполнение базы координатами
	for (i = 0; i < wordcount; i++)
	{

		if (location[i][2] == -1) continue;
		//По вертикале
		if (location[i][2] == 0)
		{
			for (int z = 0; z < wordcount; z++)
			{
				if (words[i] == basic_base[z].word)
				{
					cout << endl;
					cout << words[i] << endl;

					basic_base[z].orintation = location[i][2];
					cout << basic_base[z].orintation << endl;
					basic_base[z].x = location[i][0]*2;
					basic_base[z].y = location[i][1];
					cout <<"x :"<< basic_base[z].x << "  y :"<< basic_base[z].y<< endl;
					
					if ((board[location[i][1]][location[i][0] * 2] == ' '))
						{
						if (board[location[i][1]][location[i][0] * 2 + 1] != ' ')
						{
							basic_base[z].number = board[location[i][1]][location[i][0] * 2 + 1] - 48;
							cout << board[location[i][1]][location[i][0] * 2 + 1] - 48 << endl;
						}
						if (board[location[i][1]][location[i][0] * 2 + 1] == ' ')
						{
							basic_base[z].number = board[location[i][1]][location[i][0] * 2 + 1] - 48;
							cout << board[location[i][1]][location[i][0] * 2 + 1] - 48 << endl;
						}
							

						}
						
					
					else
					{
						basic_base[z].number = (board[location[i][1]][location[i][0] * 2] - 48)*10 + (board[location[i][1]][location[i][0] * 2+1] - 48);
						cout << basic_base[z].number << endl;

					}
					

				}

			}
			
		} 
		
		//По горизонтале
		if (location[i][2] == 1)
		{
			for (int z = 0; z < wordcount; z++)
			{
				if (words[i] == basic_base[z].word)
				{
					cout << endl;
					cout << words[i] << endl;

					basic_base[z].orintation = location[i][2];
					cout << basic_base[z].orintation << endl;
					basic_base[z].x = location[i][0] * 2;
					basic_base[z].y = location[i][1];
					cout << "x :" << basic_base[z].x << "  y :" << basic_base[z].y << endl;
					if ((board[location[i][1]][location[i][0] * 2] == ' '))
					{
						basic_base[z].number = board[location[i][1]][location[i][0] * 2 + 1] - 48;
						cout << board[location[i][1]][location[i][0] * 2 + 1] - 48 << endl;


					}


					else
					{
						basic_base[z].number = (board[location[i][1]][location[i][0] * 2] - 48) * 10 + (board[location[i][1]][location[i][0] * 2 + 1] - 48);
						cout << basic_base[z].number << endl;

					}


				}

			}

		}
	}

	printf("\nКроссворд Пазл:\n\n");
	cout << endl;
	cout << "    ";
	for (i = 0; i <= 40; i++)
		cout << " " << i;
	cout << endl;
	for (i = 0; i <= 40; i++) {
		if(i<10)
		cout << "  " << i << " ";
		else
			cout << " " << i << " ";
		for (j = 60; j <= 169; j++) {
			printf("%c", board[i][j]);

		}
		printf("\n");
	}
	
		cout<<" "<<"Положение:"<<endl;
		cout << "По вертикале" << endl;
		cout << endl;
	for (i = 0; i<wordcount; i++) {
		if (location[i][0] == -1) continue; 

		if (location[i][2] == 0) {
			cout << location[i][0] << " " << location[i][1] << " " << words[i] << endl;
			
		}
		}
	cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
		cout << "По горизонтале" << endl;
		cout << endl;
		for (i = 0; i<wordcount; i++) {
			if (location[i][0] == -1) continue;

			if (location[i][2] == 1) {
				cout << location[i][0] << " " << location[i][1] << " " << words[i] << endl;
		
			}
		
		
	}
		
}

void InputAnswer()
{
	int number_q(0);
	string answer;
	cout << "Введите номер вопроса и ответ" << endl;
	cout << "Введите номер вопроса" << endl;
	cin >> number_q;
	cout << "Введите ответ" << endl;
	cin >> answer;
	
}

void displayQuestions(string arg[],int size)
{
	for (int i = 0; i < 20; i++)
		cout << "  ";
	cout << "ВОПРОСЫ" << endl <<endl;
	int count(0);
	while (count != size)
	{
		cout << count+1 <<"   ";
		cout << arg[count++] << endl;
		cout <<"--------------------------------------------------------------------------------------------"<<endl;
	}
}

void ExpansionMass(char board[][100], char NewBoard[][200])
{
	int k(0);
	for(int i=0; i<100; i++)
		for (int j = 0; j < 100,k < 200; j++)
		{
			NewBoard[i][k] = board[i][j];
			NewBoard[i][k+1] = board[i][j];
			k += 2;

		}

}