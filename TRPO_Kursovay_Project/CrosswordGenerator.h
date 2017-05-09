#pragma once

#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
//Описание функции в которой мы будем использовать CrosswordGenerator.h

string sharedLetters(string s1, string s2);
void puzzleMaker(string words[], char solution[][100], int wordcount, int location[][3]);
int wordPlace(string words, char solution[][100], int y, int x, int orientation);
int placeFinder(string words[], char solution[][100], int wordnumber, int location[][3]);

