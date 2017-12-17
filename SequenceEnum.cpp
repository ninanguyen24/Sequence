/*Author: Nina Nguyen
Filename: SequenceEnum.cpp
11/30/2017
Version 1
Project: P5x
CPSC 5011*/


/*
~Data structure used: Array to manipulate string
~Ultility Functions: ctime for random int, cctypes and algorithm for transform()
					 to turn string into lower case
~Dependencies: Relies on client program to validate legal inputs
~Design: Two protected strings will be used, one to hold the original and one to
		 hold the word after mod() is called.
They should remain protected.
~Error response: guess() will allow for the user to guess what the modify() word
			     is. They can only guess once. There
will be no statistics to hold guess data.
~Assumption: setWord() is dependent on state so it won't violate encapsulation. 
			  It should remain protected and can only be called through reset().
*/

#include "SequenceEnum.h"
#include <iostream>
#include <cstdlib> //for srand
#include <ctime> //for srand
#include <cctype> //transform
#include <algorithm> //transfrom
using namespace std;

SequenceEnum::SequenceEnum(string word): Sequence(word) {
	reset(word);
}

string SequenceEnum::mod()//virtual override
{
	
	if (state == true) { //can only call method when state is "true" or "active"
		string modWord = wordFromUser;
		int indexToDuplicate = 0;
		indexToDuplicate = rand() % wordFromUser.length(); // should generate a number between 0 and wordFromUser length
		char temp = wordFromUser.at(indexToDuplicate);
		string letterDup(1, temp); //char to string
		modWord.insert(indexToDuplicate, letterDup);
		state = false;
		classModWord = modWord;

	}
	return classModWord;
}


SequenceEnum::~SequenceEnum() //destructor
{
}

