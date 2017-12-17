/*Author: Nina Nguyen
Filename: p5x.cpp
11/30/2017
Version 1
Project: P5x
CPSC 5011*/

/*
~Description: This program will use 7 words and 7 guessed words to test seven
			  Sequence type objects. 3 SequenceEnum, 2 SpasEnum, 2 SeqExtract.
~Data Structure used : Arrays to hold the list of test words, guessed words,
					   and Sequence type objects.
~Functionality used : mod(), toString(), invert(), hashCode(), equals(),
					  guessWord(), isActive(), isInvertState(), and getIndex()
~Anticipated use : To create Sequence type objects and modify a word, guessing
				   will be allowed.But for the purpose of this assignment, all
				   words and test words will be provided.
~Value ranges : see Legal / Illegal inputs
~Source of input / output : No input at this time, output will be printed out to
							the console.
~Legal / Illegal inputs : All words should be in lower case and has 3 or more
						  letters.Spaces, numbers, and symbols will crash the
						  program.
~Errors handling : All classes use Programming by Contract; therefore, if an
				   invalid input is entered, that will violate the contract.
				   No defensive programming is in place.
~Design and intent: A loop is used to test most functionality within the
				    hierarchy to keep it streamline.Only invert() and equals()
					will be tested outside of the loop.generateArray()
					is used as helper method.invert() and mod() from SpasEnum
					was done outside the loop to demonstrate how the it
					affected the state.
					testInvert() was created to test the invert() function.
~Assumptions: Test words used are - hello, seattle, hello, blank, space,
			  wildest, and dreams
Guessed words are - helloo, seaattle, helllo, blank, sce,
				    wildestwi, dreamsams
*/

#include "Sequence.h"
#include "SequenceEnum.h"
#include "SeqExtract.h"
#include "SpasEnum.h"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

//Size of array ob objects
const int SIZE = 7;

//Create sequence types objects
Sequence *objects[SIZE];

//Description: Short intro that prints out into the console explaining 
//			   what the program does.
void intro() {
	cout << "Welcome to the Sequence Project!\n\n" <<
		"This program will demonstrate the uses of abstract classes, "
		<< "interface, and inheritance.\n" <<
		"The following three words will be used to create 3 SequenceEnum "
		<< "objects 1 - 3: \"hello\", \"seattle\", and \"hello\"\n" <<
		"The following two words will be used to create 2 SeqExtract "
	<< "objects 4 - 5: \"blank\", and \"space\" \n" <<
		"The following two words will be used to create 2 SpasEnum objects "
		<< "6 - 7: \"wildest\", and \"dreams\"" << endl;
		cout << endl;
	cout << "Different functions will be called for those "
		<< "7 objects.\nIn addition to that, functions wills be called to "
		<< "invert a word and compare two objects.\nLet's get started!";
		cout << endl;
}

void generateCollection() {
	objects[0] = new SequenceEnum("hello");
	objects[1] = new SequenceEnum("seattle");
	objects[2] = new SequenceEnum("hello");
	objects[3] = new SeqExtract("blank");
	objects[4] = new SeqExtract("space");
	objects[5] = new SpasEnum("wildest");
	objects[6] = new SpasEnum("dreams");
}

//Description: This method test the invert() function that was implemented
//			   in Sequence class and inherited from Inverter class.
void testInvert(string star) {
	Sequence* obj = objects[4];
	cout << endl;
	cout << star << endl;
	cout << "The word \"" << obj->getWord() << "\"" << " is going to be inverted." << endl;
	cout << "State before inverting: " << boolalpha << obj->isInvertState() << endl;
	cout << "Inverted word: " << obj->invert() << endl;
	cout << "Index used to invert (0 indexing): " << obj->getIndex() << endl;
	cout << "State after inverting: " << boolalpha << obj->isInvertState() << endl;
	cout << star << endl;
	cout << endl;
}

//Description: Use the array generated from generateArray() method to test
//  		   the functionality of the Sequence type objects. A for loop
//			   is used to iterate all the objects and run the methods. 
//			   invert(), spasEnum mod(), and equals() will be tested 
//			   outside of the loop.
int main() {
	srand((unsigned int)time(NULL));
	intro();
	string guessWord[] = { "helloo", "seaattle", "helllo", "blank", "sce",
		"wildestwi", "dreamsams" };
	string star =
		"****************************************************************";

	//Create array of Sequence type objects
	generateCollection();

	//Test invert() function
	testInvert(star);

	//Loop through objects to test Sequence functionality
	for (int i = 0; i < 7; i++) {
		cout << "Testing for Oject #" << (i + 1) << ": " << endl;
		cout << "State of Sequence object before modifying: " << objects[i]->isActive() << endl;
		objects[i]->mod();
		cout << "State of Sequence object after modifying: " << objects[i]->isActive() << endl;
		cout << "Guess word used is: " << guessWord[i] << endl;
		cout << "Was the guess word correct? " << boolalpha << objects[i]->guess(guessWord[i]) << endl;
		cout << objects[i]->toString() << endl;
		cout << "Hash code: " << objects[i]->hashCode() << endl;
		cout << star << endl;
		cout << endl;
	}

	//Test truncate on SpasEnum object #7
	cout << "This test SpasEnum mod() function when the state is \"not active\"." << endl;
	cout << "Modified called again on object #7" << endl;
	objects[6]->mod();
	cout << objects[6]->toString() << endl;
	cout << star << endl;
	cout << endl;


	//Test to see if objects are equal
	cout << "Is object 1 and object 2 equal? (True for yes and False for no): " << objects[0]->operator==(*objects[1]) << endl;
	cout << "Is object 1 and object 3 equal? (True for yes and False for no): " << objects[0]->operator==(*objects[2]) << endl;


}