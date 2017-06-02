
#pragma once

#ifndef RenderingCrossword_H
#define RenderingCrossword_H

using namespace std;

void initilizeBoard(char board[][100], char c);
void initilizeBoard(char board[][200], char c);
void CreateBoards(char board[][200], char solution[][100], int **location, int wordcount, string words[], struct base *basic_base);
void displayQuestions(struct base *basic_base, int size);
int MainManu(int size, struct base *basic_base, char board[][200]);
int InputInCrossword(char board[][200], int x, int y, string word, int orintation);
void DisplayBoards(char board[][200], int x_min, int x_max, int y_min, int y_max);
int VictoryCondition(struct base *basic_base, int size);
#endif // !RENDERING_CROSSWORD_H

