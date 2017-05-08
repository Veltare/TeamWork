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

#define _GNU_SOURCE
#define PLACE_SUCCESS 1;
#define PLACE_FAILURE 0;

const int size_o = 10;
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
void puzzleMaker(string words[], vector<vector <char>> &solution, int wordcount, vector<vector <char>> &location,int wordlength)
{

	int value, i;        //,j,k;
	value = wordPlace(words[0], solution, 5, ((wordlength - words[0].length()) / 2), 1, wordlength); //places the first word, calls placefinder for the rest of the words
	location[0][0] = ((wordlength - words[0].length()) / 2);
	location[0][1] = 5;
	location[0][2] = 1;
	// printf("%d\n",value );

	for (i = 1; i <= wordcount; i++) {
		if (!placeFinder(words, solution, i, location, wordlength)) location[i][0] = -1; //doesn't print out clues and locations for words that couldn't be placed
																			 //there's a check for this later

	}
}
int wordPlace(string word, vector<vector <char>> &solution, int y, int x, int orientation,int wordlength) { //1 for horizontal, 0 for vertical 
	int i = 0, j = 0, wordpos = 0, adjacentcount = 0; // a lot of complicated logic here to account for little errors

	if (orientation == 0) { //vertical (horizontal is essentially the same)

		if (solution[y - 1][x] != '.'&& y - 1>0) return PLACE_FAILURE; //accounts for an adjacent word in the same axis as the word
		if ((solution[y + word.length()][x] != '.')&& ((y + word.length())<wordlength)) return PLACE_FAILURE;

		for (j = y; j <= y + word.length() - 1; j++) {
			if (solution[j][x] != '.'&&solution[j][x] != word[wordpos]) return PLACE_FAILURE; //checks to see if there are any words in the way of the path

			if (solution[j][x] != word[wordpos]) {
				if (solution[j][x + 1] != '.')adjacentcount++; //checks adjacent spaces for words
				if (solution[j][x - 1] != '.')adjacentcount++;

			}

			wordpos++; //increments position in the word
		}


		if (adjacentcount>0) return PLACE_FAILURE;

		while (word[i] != '\0') { //if the location clears all of the hurdles, the word is saved in board
			solution[y][x] = word[i];
			i++;
			y++;
		}

	}
	else if (orientation == 1) { //similar to the other case

		if (solution[y][x - 1] != '.'&& x - 1>0) return PLACE_FAILURE;
		if (solution[y][x + word.length()] != '.'&& x + word.length() <wordlength) return PLACE_FAILURE;


		for (j = x; j <= x + word.length() - 1; j++) {
			if (solution[y][j] != '.'&&solution[y][j] != word[wordpos]) return PLACE_FAILURE;

			if (solution[y][j] != word[wordpos]) {
				if (solution[y + 1][j] != '.')adjacentcount++;
				if (solution[y - 1][j] != '.')adjacentcount++;
			}

			wordpos++;
		}

		if (adjacentcount>0) return PLACE_FAILURE;

		while (word[i] != '\0') {
			solution[y][x] = word[i];
			i++;
			x++;
		}




	}

	return PLACE_SUCCESS; //no exceptions -> success
}
int placeFinder(string words[], vector<vector <char>> &solution, int wordnumber, vector<vector <char>> &location,int wordlength) {
	int value, i, j, k;

	for (i = 0; i <= words[wordnumber].length(); i++) { //brute force checks for places in the board that the word can be placed
		for (j = 0; j <= wordlength-1; j++) {
			for (k = 0; k <= wordlength-1; k++) {
				if (words[wordnumber][i] == solution[j][k]) { //the link between the words



					if (j - i>-1 && j - i + words[wordnumber].length() - 1<wordlength) {   //makes sure its within bounds of the board             
						if (wordPlace(words[wordnumber], solution, j - i, k, 0, wordlength)) { //try to place the word, if a success then record its location
							location[wordnumber][0] = k;
							location[wordnumber][1] = j - i;
							location[wordnumber][2] = 0;
							return PLACE_SUCCESS;
						}
					}
					if (k - i>-1 && k - i + words[wordnumber].length() - 1<wordlength) {
						if (wordPlace(words[wordnumber], solution, j, k - i, 1, wordlength)) {
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