#include <string>
using namespace std;

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

class GamePhrases {
private:
	string fileName;
	int size;
	int list[size];

public:
	GamePhrases();
	GamePhrases(int s, string fn);

	void setSize(int s){size = s;}
	void setFileName(string fn){fileName = fn;};

	void readFile(){
		ifstream infile(fileName);
		if(!infile){
			cout << "error opening file" << endl;
			exit(-1);
		}
		string s;
		int i = 0;
		while(getline(infile, s)){
			list[i];
			i++;
		}
		cout << "file read successfully" << endl;
		for(i=0;i<size;i++){
			cout << list[i] << endl;
		}
	}

	string randPhrase() const{
		string ph;
		srand(time(0));
		int f = rand() % size;
		ph = list[f];
		return ph;
	}
};
