#pragma once

#ifndef RenderingCrossword_H
#define RenderingCrossword_H

using namespace std;

void initilizeBoard(char board[][100], char c);
void initilizeBoard(char board[][200], char c);
void display(char sayings[][102], int size);
void CreateBoards(char board[][200], char solution[][100], int location[][3], int wordcount, string words[],struct base arg[]);
void displayQuestions(string arg[], int size);
int MainManu(int size, struct base basic_base[], char board[][200]);
int InputInCrossword(char board[][200], int x, int y, string word, int orintation);
void DisplayBoards(char board[][200]);
int VictoryCondition(struct base basic_base[], int size);
#endif // !RENDERING_CROSSWORD_H


