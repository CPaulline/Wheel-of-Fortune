//============================================================================
// Name        : WheelOfFortune.cpp
// Author      : Cole Paulline
// Version     :
// Copyright   : Your copyright notice
// Description : Wheel of Fortune in C++
//============================================================================

#include <iostream>
using namespace std;

#include "GameState.h"

int main() {

	//sets the variables to be passed into the game state class
	string p1;
	string p2;
	string pfile;
	int size;

	//asks the user to input various names for the game
	cout << "welcome to Wheel of Fortune" << endl;
	cout << "what is player one's name? " << endl;
	cin >> p1;
	cout << "what is player two's name? " << endl;
	cin >> p2;
	cout << "Name of the prize money file? " << endl;
	cin >> pfile;
	cout << "Number of prizes in the file? " << endl;
	cin >> size;

	//creation and declaration of game for play
	GameState gs(p1, p2, pfile, size);
	gs.play();

}
