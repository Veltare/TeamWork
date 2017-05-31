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


void CreateBoards(char board[][200], char solution[][100], int **location, int wordcount, string words[], struct base *basic_base)
{
	int i, j,k(0);
	for (i = 0; i <= 99; i++) {
		for (j = 0; j <= 99; j++) {
			
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
	//���������� ����� �������
	int count_number(1), cif1(1), cif2(0);
	for (i = 0; i < wordcount; i++) {

		if (location[i][2] == -1) continue;

		if (location[i][2] == 0) {
			if (board[location[i][1]][location[i][0] * 2 + 1] == ' ')
			{


				if (i < 10)
				{
					board[location[i][1]][location[i][0] * 2 + 1] = count_number + 48;

				
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
						board[location[i][1]][location[i][0] * 2] = cif1 + 48;
						board[location[i][1]][location[i][0] * 2 + 1] = (cif2++) + 48;

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


	//���������� ���� ������������
	for (i = 0; i < wordcount; i++)
	{

		if (location[i][2] == -1) continue;
		//�� ���������
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
		
		//�� �����������
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
		

void InputAnswer()
{
	int number_q(0);
	string answer;
	cout << "������� ����� ������� � �����" << endl;
	cout << "������� ����� �������" << endl;
	cin >> number_q;
	cout << "������� �����" << endl;
	cin >> answer;
	
}

void displayQuestions(string arg[],int size)
{
	for (int i = 0; i < 20; i++)
		cout << "  ";
	cout << "�������" << endl <<endl;
	int count(0);
	while (count != size)
	{
		cout << count+1 <<"   ";
		cout << arg[count++] << endl;
		cout <<"--------------------------------------------------------------------------------------------"<<endl;
	}
}


int MainManu(int size, struct base *basic_base, char board[][200])
{


	string argument;

	int number(0);
	int x_min(0), x_max(0), y_min(0), y_max(0);
	SearchFieldsConclusion(board, x_min, x_max, y_min, y_max);
	while (true)
	{
		cout << endl;
		system("cls");
		DisplayBoards(board, x_min, x_max, y_min, y_max);
		cout << "������� ��������� 1 - ����������� / 0 - ���������" << endl;
		cin >> argument;
		
		if (argument == "1")
		{

			cout << "������� ����� ���� ��� ������" << endl;
			
			number = vvod();
			if (argument == "�����")
			{
				system("cls");
				continue;
			}
			

				for (int z = 0; z < size; z++)
				{
					if (number == basic_base[z].number && basic_base[z].orintation == 1)
					{
						cout << " . " << z << "." << basic_base[z].questions << endl;
						cout << "������� �����" << endl;
						cin >> argument;
						if (argument == basic_base[z].word)
						{

							basic_base[z].orintation = InputInCrossword(board, basic_base[z].x, basic_base[z].y, argument, basic_base[z].orintation);
							if (VictoryCondition(basic_base, size) == -1)
							{
								cout << endl;
								system("cls");
								DisplayBoards(board, x_min, x_max, y_min, y_max);
								cout << "���� ��������" << endl;
								return 0;
							}

						}
					}

				}
				cout << "������������ �������� ���� " << endl;
				

				
				
			}
		
		if (argument == "0")
		{

			cout << "������� ����� ���� ��� ������" << endl;

			number = vvod();
			if (argument == "�����")
			{
				system("cls");
				continue;
			}
			for (int z = 0; z < size; z++)
			{
				if (number == basic_base[z].number && basic_base[z].orintation == 0)
				{
					cout << " . " << z << "." << basic_base[z].questions << endl;
					cout << " . " << z << "." << basic_base[z].word << endl;
					cout << "������� �����" << endl;
					cin >> argument;

					if (argument == basic_base[z].word)
					{

						basic_base[z].orintation = InputInCrossword(board, basic_base[z].x, basic_base[z].y, argument, basic_base[z].orintation);
						if (VictoryCondition(basic_base, size) == -1)
						{
							cout << endl;
							system("cls");
							DisplayBoards(board, x_min, x_max, y_min, y_max);
							cout << "���� ��������" << endl;
							return 0;
						}

					}
				}

			}
			cout << "������������ �������� ���� " << endl;




		}


			if (argument == "�����")
			{
				system("cls");
				return 0;
			}
			if (argument == "�������")
			{
			}
		
		

		}

}


int InputInCrossword(char board[][200], int x, int y,string word,int orintation)
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



void DisplayBoards(char board[][200], int x_min, int x_max, int y_min, int y_max)
{

	
	
	printf("\n��������� ����:\n\n");
	cout << endl;
	cout << "    ";
	for (int i = 0; i <= y_max; i++)
		cout << " " << i;
	cout << endl;
	for (int i = y_min-1; i <= y_max+1; i++) 
	{
		if (i<10)
			cout << "  " << i << " ";
		else
			cout << " " << i << " ";
		for (int j = x_min-1; j <= x_max+1; j++) {
			printf("%c", board[i][j]);

		}
		printf("\n");
	}
}

int VictoryCondition(struct base *basic_base, int size)

{
	int counter_positive(0);
	for (int count = 0; count < size; count++)
	{
		if (basic_base[count].orintation == -1)
		{
			counter_positive++;
			cout << counter_positive << endl;
		}
		

		
	}
	if (counter_positive == size)
		return -1;

	return 0;
}

