/*Author: Nina Nguyen
Filename: SeqExtract.cpp
11/30/2017
Version 1
Project: P5x
CPSC 5011*/

/*
~Data structure used: array to manipulate string
~Ultility Functions: ctime for random int
~Dependencies: Relies on client program to validate legal inputs. Also relies
			   on the parent class to remain unchanged and stable
~Design: Will inherit all public and protected variables and functionalities 
		 from SequenceEnum. subString() will be added to SeqExtract to help 
		 the class generate a subsequence string if any. State to remain
		 consistent with parent's class. Constructor will generate a 
		 subsequence, subString will take in the subsequence and find if that
		 string is in the original string.
~Error Response: guess() will allow for the user to guess what the modify() 
				 word is. They can only guess once. There will be no statistics
				 to hold guess data.
~Assumptions: setWord() is dependent on state so it won't violate encapsulation.
			  It should remain protected and can only be called through reset().

*/

#include "SeqExtract.h"
#include "Sequence.h"
#include <cstdlib> //for srand
#include <ctime> //for srand

SeqExtract::SeqExtract(string word) : Sequence(word) {
	reset(word);

	int end = rand() % wordFromUser.length();
	int begin = rand() % wordFromUser.length();
	int difference = end - begin;
	int sub = ((rand() % 100) + 1) % 2;
	if (sub == 0) { //False - no subsequence generated
		subsequence = "";
	}
	else {
		if (begin < end && difference >= 2) { //substring is 2 length or longer
			subsequence = wordFromUser.substr(begin, end);
		}
		else {
			subsequence = wordFromUser.substr(0, 2);
		}
	}
}

//override from parent's class
string SeqExtract::mod()
{
	if (state == true) {
		classModWord = subString(subsequence);
		state = false;
	}
	else {
		cout << "This violates the current state.";
	}
	return classModWord;
}

SeqExtract::~SeqExtract()
{
}

//helper class
string SeqExtract::subString(string sub)
{
	string getSub = sub;
	string temp = wordFromUser;
	if (!getSub.empty()) {
		if (temp.find(getSub) != std::string::npos) {
			string::size_type i = temp.find(getSub);
			while (i != string::npos) {
				temp.erase(i, getSub.length());
				i = temp.find(getSub, i);
			}
		}
	} else {
		temp = wordFromUser;
	}
	return temp;
}
