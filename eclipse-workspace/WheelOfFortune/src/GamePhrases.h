#ifndef GAMEPHRASES_H_
#define GAMEPHRASES_H_

#include <string>
using namespace std;

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector>

class GamePhrases {
private:
	int size;
	string fileName;
	vector<string> list;

public:
	GamePhrases();
	GamePhrases(int s, string fn);

	//various set methods for the variables if needed
	void setSize(int s){size = s;}
	void setFileName(string fn){fileName = fn;};

	//reads the file for the phrases to populate the container
	void readFile(){
		ifstream infile(fileName);
		if(!infile){
			cout << "error opening file" << endl;
			exit(-1);
		}

		list.reserve(size);
		string s;
		int i = 0;
		while(getline(infile, s)){
			list.push_back(s);
			i++;
		}
		cout << "file read successfully" << endl;
	}

	//picks a random phrase from the file passed in and comes from the container created in readFile()
	string randPhrase() const{
		string ph;
		srand(time(0));
		int f = rand() % size;
		ph = list[f];
		return ph;
	}
};

#endif /* GAMEPHRASES_H_ */
