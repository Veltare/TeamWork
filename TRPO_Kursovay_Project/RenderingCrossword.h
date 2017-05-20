#pragma once

#ifndef RenderingCrossword_H
#define RenderingCrossword_H

using namespace std;

void initilizeBoard(char board[][100], char c);
void initilizeBoard(char board[][200], char c);
void display(char sayings[][102], int size);
void displayBoards(char board[][200], char solution[][100], int location[][3], int wordcount, string words[],struct base arg[]);
void displayQuestions(string arg[], int size);
void ExpansionMass(char board[][100], char NewBoard[][200]);



#endif // !RENDERING_CROSSWORD_H


