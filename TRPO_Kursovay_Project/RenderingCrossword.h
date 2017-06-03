
#pragma once

#ifndef RenderingCrossword_H
#define RenderingCrossword_H

using namespace std;

void initilizeBoard(char board[][100], char c);
void initilizeBoard(char board[][200], char c);
void createBoards(char board[][200], char solution[][100], int **location, int wordcount, string words[], struct base *basic_base);
void displayQuestions(struct base *basic_base, int size);
void displayBoards(char board[][200], int x_min, int x_max, int y_min, int y_max);

int mainManu(int size, struct base *basic_base, char board[][200]);
int inputInCrossword(char board[][200], int x, int y, string word, int orintation);
int victoryCondition(struct base *basic_base, int size);

#endif // !RENDERING_CROSSWORD_H

