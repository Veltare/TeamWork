#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <vector>
#include <clocale>

using namespace std; 

void initilizeBoard(vector<vector <char>> &board, char c,int wordlength) {

	int i, j;

	for (i = 0; i <= wordlength-1; i++)
		for (j = 0; j <= wordlength-1; j++) {
			board[i][j] = c; //sets the entire matrix of letters to the character 'c'
		}

	return;
}