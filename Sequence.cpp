/*Author: Nina Nguyen
Filename: Sequence.cpp
11/30/2017
Version 1
Project: P5x
CPSC 5011*/

/*
~Data structure used: Array to manipulate string
~Ultility Functions: ctime for random int, cctypes and algorithm for transform()
					 to turn string into lower case, functional for hashCode
~Dependencies: Relies on client program to validate legal inputs
~Design: Two protected strings will be used, one to hold the original and one to
		 hold the word after mod() is called. They should remain protected.
~Error response: guess() will allow for the user to guess what the modify() word
			     is. They can only guess once. There will be no statistics to hold
				 guess data.
~Assumption: setWord() is dependent on state so it won't violate encapsulation. 
			 It should remain protected and can only be called through reset().
			 original word will have a valid string size throughout the lifetime
			 of the class.
*/

#include "Sequence.h"
#include <iostream>
#include <cstdlib> //for srand
#include <ctime> //for srand
#include <cctype> //transform
#include <algorithm> //transfrom
#include <sstream> //ostream
#include <functional> //hash
using namespace std;


Sequence::Sequence(string)
{
}

void Sequence::reset(string resetWord)
{
	state = true;
	invertState = false;
	setWord(resetWord);
}

string Sequence::invert()
{
	string temp;
	if (state == true && invertState == false) {
		index = (rand() % wordFromUser.length()) - 1;
		swap(wordFromUser[index], wordFromUser[index + 1]);
		invertState = true;
	}
	else {
		cout << "The state is invalid, you can't invert the word at this time." << endl;
	}
	return wordFromUser;
}

bool Sequence::guess(string userGuess)
{
	if (userGuess == classModWord) {
		return true;
	}
	else {
		return false;
	}
}

bool Sequence::isActive() {
	return state;
}

bool Sequence::isInvertState() {
	return invertState;
}

string Sequence::toString() const {
	ostringstream temp;
	temp << "Original word: " << wordFromUser
		<< "\nModified word: " << classModWord;
	return (temp.str());

}


int Sequence::hashCode() {
	std::hash<std::string> str_hash;
	std::size_t word1 = str_hash(wordFromUser);
	std::size_t word2 = str_hash(classModWord);
	std::size_t h = word1 + word2;
	return h;
}

ostream & operator<<(ostream & out, const Sequence & in)
{
	out << in.toString();
	return out;
}

bool Sequence::operator==(const Sequence& rhs) const {
	return
		wordFromUser == rhs.wordFromUser
		&& classModWord == rhs.classModWord;
}

string Sequence::getWord() const {
	return wordFromUser;
}

int Sequence::getIndex()
{
	return index;
}


void Sequence::setWord(string word)
{
	if (word.length() >= 3 && state == true) {
		std::transform(word.begin(), word.end(), word.begin(), ::tolower); //reuse from EncryptWord
		wordFromUser = word;
	}
}

//Description: Destructor
Sequence::~Sequence()
{
}



