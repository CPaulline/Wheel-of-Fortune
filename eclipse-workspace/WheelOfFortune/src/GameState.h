#include <string>
using namespace std;

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector>

class GameState{
private:
	int size;
	string player1;
	string player2;
	string fileNameP;
	vector<int> listP;

public:
	GameState();
	GameState(string p1, string p2, string fnp, int size);

	void readFile(){
		ifstream infile(fileNameP);
		if(!infile){
			cout << "error opening file" << endl;
			exit(-1);
		}

		listP.reserve(size);
		string s;
		int i = 0;
		while(getline(infile, s)){
			listP.push_back(stoi(s));
			i++;
		}
		cout << "file read successfully" << endl;

		for(i=0;i<listP.size();i++){
			cout<<listP.at(i)<< endl;
		}
	}

};
