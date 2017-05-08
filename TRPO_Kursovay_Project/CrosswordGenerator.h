#pragma once

#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
//�������� ������� � ������� �� ����� ������������ CrosswordGenerator.h

string sharedLetters(string s1, string s2);
void puzzleMaker(string words[], vector<vector <char>> &solution, int wordcount, vector<vector <char>> &location, int wordlength);
int wordPlace(string word, vector<vector <char>> &solution, int y, int x, int orientation, int wordlength); //����� ��� ����� �� �����
int placeFinder(string words[], vector<vector <char>> &solution, int wordnumber, vector<vector <char>> &location, int wordlength);
