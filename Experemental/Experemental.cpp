/*Ben Becker
Charlie Newell
lab10 crossword.c
This version skips the unplacable words and moves onto the rest
*/


#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define _GNU_SOURCE
#define PLACE_SUCCESS 1;
#define PLACE_FAILURE 0;

void initilizeBoard(char board[][15], char c); //initializes the board to all periods or poundsigns
int input(char words[][17]); //takes in the words
void display(char sayings[][17], int size); //displays the list of words, debugging purposes
void wordSorter(char words[][17], int wordcount); //sorts the words by length
int wordPlace(char word[], char space[][15], int y, int x, int orientation); //places the word on the board
void puzzleMaker(char words[][17], char solution[][15], int wordcount, int location[][3]); //builds the puzzle, calls other functions
int placeFinder(char words[][17], char solution[][15], int wordnumber, int location[][3]); //finds a place for a word on the puzzle
void displayBoards(char board[][15], char solution[][15], int location[][3], int wordcount, char words[][17]); //displays the boards


int main(void) {
	printf("Please enter up to 20 words that are 15 characters or less in length\nPress \".\" to finish entering words\n");

	int wordcount, i, j;
	char puzzle[15][15], solution[15][15], words[20][17];

	initilizeBoard(puzzle, '#');
	initilizeBoard(solution, '.');

	wordcount = input(words);

	printf("\n");

	int location[8][3];

	wordSorter(words, wordcount);

	puzzleMaker(words, solution, wordcount, location);

	displayBoards(puzzle, solution, location, wordcount, words);

	return 0;

}



void initilizeBoard(char board[][15], char c) {

	int i, j;

	for (i = 0; i <= 14; i++)
		for (j = 0; j <= 14; j++) {
			board[i][j] = c; //sets the entire matrix of letters to the character 'c'
		}

	return;
}

int input(char words[][17]) {

	int i = 0, j, badstring;

	while (1) {
		j = 0;
		badstring = 0;

		fgets(words[i], 16, stdin); //inputs the string
		strtok(words[i], "\n"); //takes out the '/n'

		if ((words[i][0] == '.') || i == 19) break;

		while (words[i][j] != '\0') {
			words[i][j] = toupper(words[i][j]);
			if ((isalpha(words[i][j]) == 0) && words[i][j] != '\0'&&words[i][j] != '\n') {
				printf("%s\n", "Please only use letters, input a different word");
				badstring = 1;
				break;
			}
			j++;
		}

		if (badstring) continue; //the badstring doesn't increment i because it needs to be rewritten with a good string
		i++;

	}

	return i;
}

void display(char sayings[][17], int size) { //displays the matrix of letters, necessary because there are no null characters
	int i = 0;
	for (i = 0; i<(size); i++) {
		printf("%s\n", sayings[i]);
	}
}

void wordSorter(char words[][17], int wordcount) { //simple bubble sort using strlen 
	char buffer[15];
	int didChange = 1, i;

	while (didChange) {
		didChange = 0;

		for (i = 1; i <= wordcount - 1; i++) {

			if (strlen(words[i - 1])<strlen(words[i])) {
				strcpy(buffer, words[i]);
				strcpy(words[i], words[i - 1]);
				strcpy(words[i - 1], buffer);
				didChange = 1;

			}
		}

	}

	return;
}

int wordPlace(char word[], char solution[][15], int y, int x, int orientation) { //1 for horizontal, 0 for vertical 
	int i = 0, j = 0, wordpos = 0, adjacentcount = 0; // a lot of complicated logic here to account for little errors

	if (orientation == 0) { //vertical (horizontal is essentially the same)

		if (solution[y - 1][x] != '.'&& y - 1>0) return PLACE_FAILURE; //accounts for an adjacent word in the same axis as the word
		if (solution[y + strlen(word)][x] != '.'&& y + strlen(word)<15) return PLACE_FAILURE;

		for (j = y; j <= y + strlen(word) - 1; j++) {
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
		if (solution[y][x + strlen(word)] != '.'&& x + strlen(word)<15) return PLACE_FAILURE;


		for (j = x; j <= x + strlen(word) - 1; j++) {
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

void puzzleMaker(char words[][17], char solution[][15], int wordcount, int location[][3]) {

	int value, i;        //,j,k;
	value = wordPlace(words[0], solution, 5, (15 - strlen(words[0])) / 2, 1); //places the first word, calls placefinder for the rest of the words
	location[0][0] = (15 - strlen(words[0])) / 2;
	location[0][1] = 5;
	location[0][2] = 1;
	// printf("%d\n",value );

	for (i = 1; i <= wordcount; i++) {
		if (!placeFinder(words, solution, i, location)) location[i][0] = -1; //doesn't print out clues and locations for words that couldn't be placed
																			 //there's a check for this later

	}
}

int placeFinder(char words[][17], char solution[][15], int wordnumber, int location[][3]) {
	int value, i, j, k;

	for (i = 0; i <= strlen(words[wordnumber]); i++) { //brute force checks for places in the board that the word can be placed
		for (j = 0; j <= 14; j++) {
			for (k = 0; k <= 14; k++) {
				if (words[wordnumber][i] == solution[j][k]) { //the link between the words



					if (j - i>-1 && j - i + strlen(words[wordnumber]) - 1<15) {   //makes sure its within bounds of the board             
						if (wordPlace(words[wordnumber], solution, j - i, k, 0)) { //try to place the word, if a success then record its location
							location[wordnumber][0] = k;
							location[wordnumber][1] = j - i;
							location[wordnumber][2] = 0;
							return PLACE_SUCCESS;
						}
					}
					if (k - i>-1 && k - i + strlen(words[wordnumber]) - 1<15) {
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

void displayBoards(char board[][15], char solution[][15], int location[][3], int wordcount, char words[][17]) {
	int i, j;
	printf("Solution: \n");
	for (i = 0; i <= 14; i++) {
		for (j = 0; j <= 14; j++) {
			printf("%c", solution[i][j]);
			if (isalpha(solution[i][j])) board[i][j] = ' ';
		}
		printf("\n");
	}
	printf("\nCrossword puzzle:\n\n");
	for (i = 0; i <= 14; i++) {
		for (j = 0; j <= 14; j++) {
			printf("%c", board[i][j]);

		}
		printf("\n");
	}
	printf("\nClues: \n");
	for (i = 0; i<wordcount; i++) {
		if (location[i][0] == -1) continue; //skips the unplacable words

		if (location[i][2] == 1) {
			printf("Across ");
		}
		if (location[i][2] == 0) {
			printf("Down   ");
		}
		//strfry(words[i]);
		printf("(%2d, %2d), %s", location[i][0], location[i][1], words[i]);
		printf("\n");
	}
}

