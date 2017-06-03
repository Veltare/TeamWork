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
#include "Logic.h"
#include <windows.h>

using namespace std;

HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

struct base
{
	string word;
	string questions;
	int orintation;
	int x, y;
	int number;

};
using namespace std; 



void initilizeBoard(char board[][100], char c) 
{

	int i, j;

	for (i = 0; i <= 99; i++)
		for (j = 0; j <= 99; j++) 
		{
			board[i][j] = c; 
		}

	return;
}
void initilizeBoard(char board[][200], char c) 
{

	int i, j;

	for (i = 0; i <= 99; i++)
		for (j = 0; j <= 199; j++) 
		{
			board[i][j] = c;
		}

	return;
}


void createBoards(char board[][200], char solution[][100], int **location, int wordcount, string words[], struct base *basic_base)
{
	int i, j,k(0);
	for (i = 0; i <= 99; i++) 
	{
		for (j = 0; j <= 99; j++) 
		{
			
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


	int countNumber(1), cif1(1), cif2(0);

	for (i = 0; i < wordcount; i++) 
	{

		if (location[i][2] == -1) continue;

		if (location[i][2] == 0) {
			if (board[location[i][1]][location[i][0] * 2 + 1] == ' ')
			{


				if (i < 10)
				{
					board[location[i][1]][location[i][0] * 2 + 1] = countNumber + 48;

				
					countNumber++;
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
						board[location[i][1]][location[i][0] * 2] = cif1 + 48;
						board[location[i][1]][location[i][0] * 2 + 1] = (cif2++) + 48;

					}
				}
			}
		}
	}
	for (i = 0; i < wordcount; i++)
	{
		if (location[i][2] == -1) continue;
		if (location[i][2] == 1) {
			if (board[location[i][1]][location[i][0] * 2 + 1] == ' ')
			{
				if (i < 10)
				{
					board[location[i][1]][location[i][0] * 2 + 1] = countNumber + 48;

					
					countNumber++;
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
						board[location[i][1]][location[i][0] * 2] = cif1 + 48;
						board[location[i][1]][location[i][0] * 2 + 1] = (cif2++) + 48;
					}
				}
			}
			else 
			{
				continue;
			}

		}
			
	}



	for (i = 0; i < wordcount; i++)
	{

		if (location[i][2] == -1) continue;

		if (location[i][2] == 0)
		{
			for (int z = 0; z < wordcount; z++)
			{
				if (words[i] == basic_base[z].word)
				{
					

					basic_base[z].orintation = location[i][2];
					basic_base[z].x = location[i][0]*2;
					basic_base[z].y = location[i][1];
	
					
					if ((board[location[i][1]][location[i][0] * 2] == ' '))
					{
						if (board[location[i][1]][location[i][0] * 2 + 1] != ' ')
						{
							basic_base[z].number = board[location[i][1]][location[i][0] * 2 + 1] - 48;
							
						}
						if (board[location[i][1]][location[i][0] * 2 + 1] == ' ')
						{
							basic_base[z].number = board[location[i][1]][location[i][0] * 2 + 1] - 48;
							
						}
							
					}
						
					
					else
					{
						basic_base[z].number = (board[location[i][1]][location[i][0] * 2] - 48)*10 + (board[location[i][1]][location[i][0] * 2+1] - 48);

					}
					

				}

			}
			
		} 
		

		if (location[i][2] == 1)
		{
			for (int z = 0; z < wordcount; z++)
			{
				if (words[i] == basic_base[z].word)
				{
					
					basic_base[z].orintation = location[i][2];
					basic_base[z].x = location[i][0] * 2;
					basic_base[z].y = location[i][1];
					if ((board[location[i][1]][location[i][0] * 2] == ' '))
					{
						basic_base[z].number = board[location[i][1]][location[i][0] * 2 + 1] - 48;


					}


					else
					{
						basic_base[z].number = (board[location[i][1]][location[i][0] * 2] - 48) * 10 + (board[location[i][1]][location[i][0] * 2 + 1] - 48);

					}


				}

			}

		}
	}
		
}
		
void displayQuestions(struct base *basicBase,int size)
{
	system("cls");
	cout << endl;
	for (int i = 0; i < 20; i++)
		cout << "  ";
	cout << "ВОПРОСЫ" << endl <<endl;
	int count(0);

	cout << "По вертикале" << endl;

	for(int i=0;i<size;i++)
	{
		
		if (basicBase[i].orintation == 0)
		{
		SetConsoleTextAttribute(hConsole, 2);
		cout << basicBase[i].number << endl;
		cout << basicBase[i].questions << endl;
		SetConsoleTextAttribute(hConsole, 7);
		cout <<"--------------------------------------------------------------------------------------------"<<endl;
		}
		
	}

	cout << "По горизонтале" << endl;

	for (int i = 0; i<size; i++)
	{

		if (basicBase[i].orintation == 1)
		{
			SetConsoleTextAttribute(hConsole, 5);
			cout << basicBase[i].number << endl;
			cout << basicBase[i].questions << endl;
			SetConsoleTextAttribute(hConsole, 7);
			cout << "--------------------------------------------------------------------------------------------" << endl;
		}

	}
}


int mainManu(int size, struct base *basicBase, char board[][200])
{


	string argument;

	int number(0),m(-1);
	int x_min(0), x_max(0), y_min(0), y_max(0);
	searchFieldsConclusion(board, x_min, x_max, y_min, y_max);
	system("cls");
	displayBoards(board, x_min, x_max, y_min, y_max);
	SetConsoleTextAttribute(hConsole, 10);
	cout << "----------------------------------------------------" << endl;
	cout <<"                   "<<"Главное меню" << endl;
	cout << "----------------------------------------------------" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout << "Для вывода списка команд используйте команду 'Помощь' " << endl;
	cout << "****************************************************" << endl;
	while (true)
	{
		cout << endl;

		cout << "Введите плоскость 1 - Горизонталь / 0 - Вертикаль" << endl;
		cin >> argument;
		system("cls");
		displayBoards(board, x_min, x_max, y_min, y_max);
		if (argument == "1")
		{

			cout << "Введите номер поля для ответа" << endl;

			number = Input();
			
			
			

			for (int z = 0; z < size; z++)
			{
				if (number == basicBase[z].number && basicBase[z].orintation == 1)
				{
					cout << " . " << number << "." << basicBase[z].questions << endl;
					cout << "Введите ответ:";
					cin >> argument;
					if (argument == "Подсказка")
					{
						cout << endl;


						SetConsoleTextAttribute(hConsole, 13);
						cout << basicBase[z].word << endl;;
						SetConsoleTextAttribute(hConsole, 7);

						cout << "Введите ответ:";
						cin >> argument;

					}
					if (argument == basicBase[z].word)
					{
						m = z;
						basicBase[z].orintation = inputInCrossword(board, basicBase[z].x, basicBase[z].y, argument, basicBase[z].orintation);
						if (victoryCondition(basicBase, size) == -1)
						{
							cout << endl;
							system("cls");
							displayBoards(board, x_min, x_max, y_min, y_max);
							cout << "Игра окончена" << endl;
							return 0;
						}
						system("cls");
						displayBoards(board, x_min, x_max, y_min, y_max);
						
					}
					
				}

			}
		}

		if (argument == "0")
		{

			cout << "Введите номер поля для ответа" << endl;

			number = Input();
			
			for (int z = 0; z < size; z++)
			{
				if (number == basicBase[z].number && basicBase[z].orintation == 0)
				{
					cout << " . " << number << "." << basicBase[z].questions << endl;
					cout << "Введите ответ:";
					cin >> argument;
					if (argument == "Подсказка")
					{
						cout << endl;

						
							SetConsoleTextAttribute(hConsole, 13);
							cout << basicBase[z].word << endl;;
							SetConsoleTextAttribute(hConsole, 7);
						
							cout << "Введите ответ:";
							cin >> argument;

					}
					if (argument == basicBase[z].word)
					{
						m = z;
						basicBase[z].orintation = inputInCrossword(board, basicBase[z].x, basicBase[z].y, argument, basicBase[z].orintation);
						if (victoryCondition(basicBase, size) == -1)
						{
							cout << endl;
							system("cls");
							displayBoards(board, x_min, x_max, y_min, y_max);

							SetConsoleTextAttribute(hConsole, 4);
							
							cout << "Игра окончена" << endl;
							SetConsoleTextAttribute(hConsole, 7);
							return 0;
						}
						system("cls");
						displayBoards(board, x_min, x_max, y_min, y_max);
						continue;

					}
				}
			}
		}

		if (argument == "Вопросы")
		{
			displayQuestions(basicBase, size);
			system("pause");
			system("cls");
			displayBoards(board, x_min, x_max, y_min, y_max);
		}
		
		if (argument == "Выход")
		{
			system("cls");
			return 0;
		}
		if (argument == "Ответы")
		{
			system("cls");
			cout << endl;
			for (int i = 0; i < 20; i++)
				cout << "  ";
			cout << "ОТВЕТЫ" << endl << endl;
			int count(0);

			cout << "По вертикале" << endl;

			for (int i = 0; i < size; i++)
			{

				if (basicBase[i].orintation == 1)
				{
					SetConsoleTextAttribute(hConsole, 2);
					cout << basicBase[i].number << endl;
					cout << basicBase[i].word << endl;
					SetConsoleTextAttribute(hConsole, 7);
					cout << "--------------------------------------------------------------------------------------------" << endl;
				}

			}

			cout << "По горизонтале" << endl;

			for (int i = 0; i < size; i++)
			{

				if (basicBase[i].orintation == 0)
				{
					SetConsoleTextAttribute(hConsole, 5);
					cout << basicBase[i].number << endl;
					cout << basicBase[i].word << endl;
					SetConsoleTextAttribute(hConsole, 7);
					cout << "--------------------------------------------------------------------------------------------" << endl;
				}

			}
			system("pause");
			system("cls");
			displayBoards(board, x_min, x_max, y_min, y_max);
		}


		if (argument == "Помощь")
		{
			cout << "----------------------------------------------------" << endl;
			cout << "Список доступных команд" << endl;
			cout << "----------------------------------------------------" << endl;
			cout << "'Выход' - для выхода из программы" << endl;
			cout << "----------------------------------------------------" << endl;
			cout << "'Вопросы' - вывод списка вопросов" << endl;
			cout << "----------------------------------------------------" << endl;
			cout << "'Ответы' - вывод списка ответов на вопросы" << endl;
			cout << "----------------------------------------------------" << endl;
			cout << "'Подсказка' - получит ответ на вопрос" << endl;
			cout << "----------------------------------------------------" << endl;

		}
	}	
}


		


int inputInCrossword(char board[][200], int x, int y,string word,int orintation)
{
	int count_x = x+1;
	int count_y = y;
	board[y][x] = ' ';
	board[y][x+1] = ' ';

	if (orintation == 1)
	{
		for (int count = 0; count < word.size(); count++)
		{
			board[y][count_x] = word[count];	
			count_x+=2;
		}
		

		return -1;
	}
	if (orintation == 0)
	{
		for (int count = 0; count < word.size(); count++)
		{
			board[count_y][x+1] = word[count];
			count_y += 1;
		}

		return -1;
	}
	return 1;
}



void displayBoards(char board[][200], int x_min, int x_max, int y_min, int y_max)
{

	
	
	printf("\nКроссворд Пазл:\n\n");
	cout << endl;
	cout << "    ";
	for (int i = 0; i <= y_max; i++)
	{
		SetConsoleTextAttribute(hConsole, 9);
		cout << " " << i;
		SetConsoleTextAttribute(hConsole, 7);
		
	}
		
	cout << endl;
	for (int i = 0; i <= y_max+1; i++) 
	{
		if (i < 10)
		{
			SetConsoleTextAttribute(hConsole, 9);
			cout << "  " << i << " ";
			SetConsoleTextAttribute(hConsole, 7);
		}
			
		else
		{
			SetConsoleTextAttribute(hConsole, 9);
			cout << " " << i << " ";
			SetConsoleTextAttribute(hConsole, 7);
		}
			
		for (int j = x_min-1; j <= x_max+1; j++) 
		{
			if (isalpha((unsigned char)board[i][j]) == 1)
			{
				SetConsoleTextAttribute(hConsole, 9);
				cout << board[i][j];
				
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 7);
				printf("%c", board[i][j]);
			}
			

		}
		printf("\n");
	}
}

int victoryCondition(struct base *basic_base, int size)
{
	int counterPositive(0);
	for (int count = 0; count < size; count++)
	{
		if (basic_base[count].orintation == -1)
		{
			counterPositive++;
			
		}
			
	}
	if (counterPositive == size)
		return -1;

	return 0;
}

