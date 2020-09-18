#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "GamePhrases.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class GameState{
private:
	int size;
	string player1;
	string player2;
	string fileNameP;
	string phrase;
	string key;
	vector<int> listP;

public:
	GameState();
	GameState(string p1, string p2, string fnp, int size);

	//various set methods for variables if needed
	void setPlayer1Name(string p1){player1 = p1;}
	void setPlayer2Name(string p2){player2 = p2;}
	void setFileNameP(string fnp){fileNameP = fnp;}

	//read file function for the prize amounts being played with
	void readFileP(){
		ifstream infile(fileNameP);
		if(!infile){
			cout << "error opening file" << endl;
			exit(-1);
		}

		listP.reserve(size); //sets the container amount before hand using the users input
		string p;
		int i = 0;
		while(getline(infile, p)){
			listP.push_back(stoi(p));
			i++;
		}
		cout << "file read successfully" << endl;
	}

	//grabs a random prize amount from the container made using the list provided
	int randomPrize() const{
		int prize;
		srand(time(0));
		int r = rand() % size;
		prize = listP[r];
		return prize;
	}

	/*
	 * function that finds the total amount of times a character is in a string that is provided
	 * then returns the amount of times it is in that string
	 */
	int findLetter(string s, char c){
		int tot=0, i=0;
		while (i<s.length()){
			if (s[i] == c)
				tot = tot + 1;
				i++;
		}

		return tot;
	}

	/*
	 * main game play function where the player turns and general game state is being stored and run
	 * using the functions above and from GamePhrases
	 */
	void play(){
		bool playing = true;
		bool turn = true;
		char guess;
		int amount;
		int p1prize;
		int p2prize;
		int spin;

		readFileP();  			//reading in the prize money file using what was already provided

		//gathering info from the user to create the game phrases container
		int inputNum;
		string inputStr;
		cout << "Game Phrases file name? " << endl;
		cin >> inputStr;
		cout << "Number of phrases in the file?  " << endl;
		cin >> inputNum;
		GamePhrases g(inputNum, inputStr);
		g.readFile();

		/*
		 * creates a key where the original phrase is stored and makes a general phrase that all
		 *  characters are replaced by underscores
		 */
		phrase = g.randPhrase();
		key = phrase;
		for(int i = 0;i < phrase.length(); i++){
			if(phrase[i] != ' '){
				phrase[i] = '_';
			}
		}

		while(playing){

			//player 1's turn is run
			while(turn and phrase != key){
				cout << "\nit is " << player1 << "'s turn" << endl;
				spin = randomPrize();
				cout << "\nyou have spun " << spin << endl;
				cout << "\n" << phrase << endl;
				cout << "what letter is your guess? " << endl;
				cin >> guess;
				amount = findLetter(key, guess);
				if(amount == 0){  			//if no specified characters are found it goes to the next player
					cout << "\nsorry there is no " << guess << endl;
					turn = false;			//sets to player 2's turn when wrong
				}else{
					cout << "\nthere were " << amount << " " << guess << "'s" << endl;
					p1prize = p1prize + (spin * amount);		//multiples the times the letter is shown by prize spun and added to total
					for(int i = 0;i < key.length(); i++){		//goes through a loop to find all iterations of a specified character in the phrase
						if (key[i] == guess){
							phrase[i] = guess;
						}
					}
				}
			}

			if(phrase == key){		//if the phrase is complete it changes the turn so it doesn't go through the second players turn since the turn is over
				cout << "\n" << phrase << endl;
				cout << "the phrase is complete!" << endl;
				turn = true;
			}

			//player 2's turn is run
			while(!turn and phrase != key){
				cout << "\nit is " << player2 << "'s turn" << endl;
				spin = randomPrize();
				cout << "\nyou have spun " << spin << endl;
				cout << "\n" << phrase << endl;
				cout << "what letter is your guess? " << endl;
				cin >> guess;
				amount = findLetter(key, guess);
				if(amount == 0){
					cout << "\nsorry there is no " << guess << endl;
					turn = true;
				}else{
					cout << "\nthere were " << amount << " " << guess << "'s" << endl;
					p2prize = p2prize + (spin * amount);
					for(int i = 0;i < key.length(); i++){
						if (key[i] == guess){
							phrase[i] = guess;
						}
					}
				}
			}

			//where the game asks if they wish to play again or stop ONLY if the phrase is complete
			if(phrase == key){
				string ans;
				cout << "\nwould you like to play / play again? y/n " << endl;
				cin >> ans;
				if(ans == "n"){		//if 'n' or no the game terminates and displays the final prize amounts of the players
					cout << "\nplayer 1 had: $" << p1prize << endl;
					cout << "player 2 had: $" << p2prize << endl;
					cout << "thanks for playing! " << endl;
					playing = false;
				}

				//if they wish to continue playing then the final block is run to get a new phrase for the next round
				phrase = g.randPhrase();
				key = phrase;
				for(int i = 0;i < phrase.length(); i++){
					if(phrase[i] != ' '){
						phrase[i] = '_';
					}
				}
			}
		}
	}
};

#endif /* GAMESTATE_H_ */
