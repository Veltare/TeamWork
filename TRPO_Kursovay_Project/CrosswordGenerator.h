#pragma once

#ifndef CrosswordGenerator_H
#define CrosswordGenerator_H


#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


string sharedLetters(string s1, string s2);

void puzzleMaker(string words[], char solution[][100], int wordcount, int **location);

int wordPlace(string words, char solution[][100], int y, int x, int orientation);
int placeFinder(string words[], char solution[][100], int wordnumber, int **location);


#endif