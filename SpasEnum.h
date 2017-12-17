/*Author: Nina Nguyen
Filename: SpasEnum.h
11/30/2017
Version 1
Project: P5x
CPSC 5011*/

/*
~Description: This class extends the abstract Sequence class. It override the
abstract method mod() from Sequence to create a subsequence at
random indexed. Then the subsequence string will either be
concatenate or trunction dependent on state of the object.
Inverter state does not affect mod().
~Anticipated Use: To create a subsequence string and either concatenate or
or truncate depending on state of the object.
~Data structure used: array to manipulate string
~Ultility Functions: util.Random to generate random indexes
~Dependencies: Relies on client program and parent class to validate legal
inputs. Relies on the parent's class to remain unchanged.
~Design: Will inherit all public and protected variables and functionalities
from Sequence. mod() will be overriden by SpasEnum
subString() will be used to get a subsequence string from original
word.
mod() pre-condition is different from parent's.
mod() can be called when state is inactive, will reuse original word
setWord and reset() remain unchanged
State to remain consistent with parent's class.
~Legal/Illegal input: A single string with 3 letters or more in all lower case.
Numbers, symbols, and spaces will crash the program.
~Error Response: Programming by contract, driver is expected to input data
in the correct format.
~Functionality: See description and design.
~Legal States: "active" (true) or "not active" (false)
~State transition: mod() changes the state from "active" to "not active"
~Dependencies: Relies on client program and parent class to validate legal
inputs.
~Data processed: String passed into constructor
~Assumptions: The class will accept words less than three letters, spaces,
integers, or symbols but results will not be guaranteed.
Output given: return modified word.
*/

#ifndef SPAS_ENUM
#define SPAS_ENUM

#include "Sequence.h"
#include <iostream>
#include <string>
using namespace std;

class SpasEnum : public Sequence {
public:
	//Description: Constructor, calls the parent's constructor
	//Pre: None
	//Post: State becomes "active" and "not inverted"
	SpasEnum(string);

	//Description: Modify the word looking for a subsequence in the word and
	//	           and concatenate it to the original word if the state is 
	//			   "active", inverter state does not matter. It will truncate
	// 			   the subsequence string if the state is "not active".
	//			   override from parent's class
	//Pre: In an "active" or "not active" state and may or may not be "inverted"
	//Post: State becomes "not active", invert state does not change
	string mod() override;

	//Destructor
	//Pre: Object in an inactive state
	//Post: None
	~SpasEnum();

private:

	//Description: Helper method, create a subsequence from the original word
	//			   by generating random indexes.
	//Pre: is called by the mod() method.
	//Post: None
	string subString();

	//Description: Holds the subsequence string
	string subsequence;

};

#endif