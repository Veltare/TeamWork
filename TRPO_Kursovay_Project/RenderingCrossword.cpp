#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <vector>
#include <clocale>

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

void displayBoards(char board[][100], char solution[][100], int location[][3], int wordcount, string words[]) {
	int i, j;
	printf("Работа Алгоритма: \n");
	for (i = 0; i <= 99; i++) {
		for (j = 0; j <= 99; j++) {
			printf("%c", solution[i][j]);
			//if (isalpha(solution[i][j])) board[i][j] = ' ';
		}
		printf("\n");
	}
	/*printf("\nКроссворд Пазл:\n\n");
	for (i = 0; i <= 99; i++) {
		for (j = 0; j <= 99; j++) {
			printf("%c", board[i][j]);

		}
		printf("\n");
	}*/
	
}

