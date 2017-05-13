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

using namespace std; 

void initilizeBoard(char board[][100], char c) {

	int i, j;

	for (i = 0; i <= 99; i++)
		for (j = 0; j <= 99; j++) {
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
/*char toChar(int number)
{
	char digit;
	int summator(6);

	if (number < 9) digit = '0' + number;
	else
	{
		if (number % 10 == 9 || number== 9)
		{
			digit = number + summator;
			summator+=6;
		}
			
		else
			digit = number + summator;
	}
	return digit;
}*/
void displayBoards(char board[][100], char solution[][100], int location[][3], int wordcount, string words[])
{
	int i, j;
	//printf("Работа Алгоритма: \n");
	for (i = 0; i <= 99; i++) {
		for (j = 0; j <= 99; j++) {
			//printf("%c", solution[i][j]);
			if (isalpha((unsigned char)solution[i][j])) board[i][j] = ' ';
		}
		//printf("\n");
	}
	/*int count_number(0);
	for (i = 0; i < wordcount; i++) {
		if (location[i][0] == -1) continue; 

		if (location[i][2] == 1) {
	
			board[location[i][1]][location[i][0]] = toChar(count_number);
			count_number++;
		}
		if (location[i][2] == 0) {
			board[location[i][1]][location[i][0]] = toChar(count_number++);
		}
	}*/
	printf("\nКроссворд Пазл:\n\n");
	cout << endl;
	for (i = 0; i <= 50; i++) {
		for (j = 0; j <= 99; j++) {
			printf("%c", board[i][j]);

		}
		printf("\n");
	}
	
		cout<<" "<<"Положение:"<<endl;
		cout << "По вертикале" << endl;
		cout << endl;
	for (i = 0; i<wordcount; i++) {
		if (location[i][0] == -1) continue; 

		if (location[i][2] == 1) {
			cout << location[i][0] << " " << location[i][1] << " " << words[i] << endl;
			
		}
		}
	cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
		cout << "По горизонтале" << endl;
		cout << endl;
		for (i = 0; i<wordcount; i++) {
			if (location[i][0] == -1) continue;

			if (location[i][2] == 0) {
				cout << location[i][0] << " " << location[i][1] << " " << words[i] << endl;
		
			}
		//strfry(words[i]);
		//printf("(%2d, %2d)", location[i][0], location[i][1]);
		
	}
		
}


