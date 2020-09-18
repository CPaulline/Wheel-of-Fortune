#include "GameState.h"

/*
 * sets the file name and size for the prize money container as well as the player names for the game
 */

GameState::GameState(string p1, string p2, string fnp, int s){
	player1 = p1;
	player2 = p2;
	fileNameP = fnp;
	size = s;
}
