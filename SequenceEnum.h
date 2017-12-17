/*Author: Nina Nguyen
Filename: SequenceEnum.h
11/30/2017
Version 1
Project: P5x
CPSC 5011*/

/*
~Description: This class extends the abstract Sequence class. It override the
			  abstract method mod() from Sequence to duplicate a letter at a
			  random index. All other methods and variables are inherited from
			  Sequence.
~Anticipated Use: To modify a word by duplicating a letter at a certain index.
				  To be a part of the Sequence hierarchy.
~Data structure used: Array to manipulate string
~Utility Functions: util.Random used to generate random integer for index
~Dependencies: Relies on client program and parent class to validate legal
			   inputs. Also relies the parent class to remain stable
~Design: only mod() override was implemented.
		 state to remain consistent with parent's class.
~Error response: No error checking will be used. Class expects driver to
				 not input any invalid values and for parent's class to
				 handle any exceptions if any.
~Functionality: see ~Design.
~Legal States: "active" (true) or "not active" (false)
~State Transition: state is "active" before mod() and "not active" after mod().
				   invert() state is inherited from Sequence.
~Data processed: a string of length 3 or more passed in by the driver class.
				 Will modify the word accordingly and return it.
~Legal/Illegal input: A single string with 3 letters or more in all lower case.
					  Numbers, symbols, and spaces will crash the program.
~Assumptions: The class will accept words less than three letters, spaces, 
		      integers, or symbols but results will not be guaranteed.
			  Output will return a modify word. User can guess the modified word.
*/

#ifndef SEQUENCE_ENUM
#define SEQUENCE_ENUM

#include "Sequence.h"
#include "SequenceEnum.h"
#include <iostream>
#include <string>
using namespace std;

class SequenceEnum: public Sequence {
public:

	//Description: Constructor, calls Sequence class constructor
	//Pre: None
	//Post: State becomes "active" and "not inverted"
	SequenceEnum(string);

	//Description: Modify the word by duplicating a letter at a random index
	//			   override from parent's class
	//Pre: In an "active" state and may or may not be "inverted"
	//Post: State becomes "not active", invert state does not change
	string mod();

	//Description: Destructor
	//Pre: In an inactive state
	//Post: none
	virtual ~SequenceEnum();

};

#endif