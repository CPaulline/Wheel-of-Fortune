//============================================================================
// Name        : WheelOfFortune.cpp
// Author      : Cole Paulline
// Version     :
// Copyright   : Your copyright notice
// Description : Wheel of Fortune in C++
//============================================================================

#include <iostream>
using namespace std;

#include "GamePhrases.h"

int main() {
	cout << "Hello World" << endl; // prints Hello World

	int inputNum;
	string inputStr;
	cout << "Please input the amount of phrases in the file " << endl;
	cin >> inputNum;
	cout << "Please input the file name being used" << endl;
	cin >> inputStr;
	GamePhrases g(inputNum, inputStr);
	g.readFile();


}
