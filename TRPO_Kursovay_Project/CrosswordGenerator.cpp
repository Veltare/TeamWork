// TRPO_Kursovay_Project.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>

#include "CrosswordGenerator.h"


#define PLACE_SUCCESS 1;
#define PLACE_FAILURE 0;


using namespace std;

//Алгоритм получения общих букв
string sharedLetters(string s1,string s2)

{
	string sharedletters = "";

	string commonletter = "";

	for(int i=0;i<s1.length();i++)
	{
		for (int j = 0; j < s2.length(); j++)
		{

			if (tolower(s1.at(i)) == tolower(s2.at(j)))
			{
				commonletter = s1.at(i);


				sharedletters.append(commonletter);
			}
		}

	}


	return sharedletters;
}


void puzzleMaker(string words[], char solution[][100], int wordcount, int location[][3])
{

	int value, i;        
	value = wordPlace(words[0], solution, 5, (100 - words[0].length()) / 2, 1); 
	location[0][0] = (100 - words[0].length()) / 2;
	location[0][1] = 5;
	location[0][2] = 1;
	

	for (i = 1; i < wordcount; i++) {
		if (!placeFinder(words, solution, i, location)) location[i][0] = -1; 
																			 

	}
}

int placeFinder(string words[], char solution[][100], int wordnumber, int location[][3]) {
	int value, i, j, k;

	for (i = 0; i <= words[wordnumber].length(); i++) { 
		for (j = 0; j <= 99; j++) {
			for (k = 0; k <= 99; k++) {
				if (words[wordnumber][i] == solution[j][k]) { 



					if ((j - i>-1 && j - i + words[wordnumber].length()) - 1<100) {          
						if (wordPlace(words[wordnumber], solution, j - i, k, 0)) {
							location[wordnumber][0] = k;
							location[wordnumber][1] = j - i;
							location[wordnumber][2] = 0;
							return PLACE_SUCCESS;
						}
					}
					if ((k - i>-1 && k - i + words[wordnumber].length()) - 1<100) {
						if (wordPlace(words[wordnumber], solution, j, k - i, 1)) {
							location[wordnumber][0] = k - i;
							location[wordnumber][1] = j;
							location[wordnumber][2] = 1;
							return PLACE_SUCCESS;
						}
					}
				}

			}
		}
	}
	return PLACE_FAILURE;
}

int wordPlace(string words, char solution[][100], int y, int x, int orientation)
{
	int i = 0, j = 0, wordpos = 0, adjacentcount = 0;

	if (orientation == 0) {

		if (solution[y - 1][x] != '.'&& y - 1 > 0) return PLACE_FAILURE;
		if (solution[y + words.length()][x] != '.'&& y + words.length() < 100) return PLACE_FAILURE;

		for (j = y; j <= y + words.length() - 1; j++) {
			if (solution[j][x] != '.'&&solution[j][x] != words[wordpos]) return PLACE_FAILURE;

			if (solution[j][x] != words[wordpos]) {
				if (solution[j][x + 1] != '.')adjacentcount++;
				if (solution[j][x - 1] != '.')adjacentcount++;

			}

			wordpos++;
		}


		if (adjacentcount > 0) return PLACE_FAILURE;

		while (words[i] != '\0') {
			solution[y][x] = words[i];
			i++;
			y++;
		}

	}
	else if (orientation == 1) {

		if (solution[y][x - 1] != '.'&& x - 1 > 0) return PLACE_FAILURE;
		if (solution[y][x + words.length()] != '.'&& x + words.length() < 100) return PLACE_FAILURE;


		for (j = x; j <= x + words.length() - 1; j++) {
			if (solution[y][j] != '.'&&solution[y][j] != words[wordpos]) return PLACE_FAILURE;

			if (solution[y][j] != words[wordpos]) {
				if (solution[y + 1][j] != '.')adjacentcount++;
				if (solution[y - 1][j] != '.')adjacentcount++;
			}

			wordpos++;
		}

		if (adjacentcount > 0) return PLACE_FAILURE;

		while (words[i] != '\0') {
			solution[y][x] = words[i];
			i++;
			x++;
		}




	}

	return PLACE_SUCCESS;
}

