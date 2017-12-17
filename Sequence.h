/*Author: Nina Nguyen
Filename: Sequence.h
11/30/2017
Version 1
Project: P5x
CPSC 5011
Reference: SequenceEnum.cpp, mkyong.com for hashCode() override
*/

/*
~Description: This class is an abstract class that implement the Inverter
			  interface and provides abstract methods that needs to be
		      implemented by the child classes.The class itself can't be 
			  instantiated.The class will be the parent class for child
			  class that takes in a word from the driver with 3 or more
		      letters and manipulated in some way.The user can guess
			  what the modified word is.
~Functionality : invert() is implemented from Inverter interface(), mod() is
				 abstract equals() and hashCode() allows driver to compare
				 two objects.
~Legal States : active(true) or inactive(false) for Sequence, inverted(true)
				or not inverted(false).
~State transition : State is active when object is created.Will be inactive
					after mod() or reset() is called.
					State is "not inverted" when object is first created, becomes
					"active" once invert() is called.
~Overlapping of state : invert() can only be called when the word has not been
						modified.Meaning, the state has to be "not inverted"
						and "active".
						mod() can be called if the inverter state is "inverted"
						or "not inverted", but Sequence state has to be "active"
~Dependencies : Depends on the child classes to not violate state.And dependent
				on the interface Inverter.Total dependence on the driver class
				to give all valid inputs.Abstract methods should be overriden.
~Anticipated Use : To be the parent class for the child classes.Sequence will
				provide variables to hold the original and modified strings.
				Child classes will have all the implemented abstract methods
				from Sequence.
~Data processed : A class variable that holds the original word passed in by
				  driver class.The string will be manipulated and assigned to
			      another class variable that holds the modified word.
~Legal / Illegal input: The constructor takes in a string of 3 letters or more.
						It will accept strings with less than 3 letters, has spaces,
						numbers, or symbols.However, results are not guaranteed if
						inputs does not meet requirements.
~Error Response : There are no try / catch blocks or defensive programming to catch
				  user errors.So program will crash if it's misused. Users are 
				  expected to follow the contract set by Sequence class.
				  guess(string) should only take a single string as argument,
				  string should be 3 letters or more.Program might not act
				  accordingly if input is invalid.
~Design : Implements the invert() and isInvertState() from the Inverter interface.
		  The child classes will inherit these functions as well.Two protected
		  strings will be used, one to hold the original and one to hold the word
		  after mod() is called.They should remain protected.
		  toString(), hashCode() and operator== was created to imitate Java's
		  version of overriding.
~Utility Functions : rand for random integer and functional for hash_code
~Data structure used : Arrays to separate letters in strings into array of
					   characters invert().
~Class invariants : The length of the string will be 3 or more.classModWord and
					wordFromUser can't be empty strings.
					Index generated should always be a positive integer and
					index can't equal the length of the wordFromUser at 0
					indexing.EX, if the word is "hello", index can't be 4.

~Assumptions: The class will accept words less than three letters, spaces, 
		      integers, or symbols but results will not be guaranteed.This 
			  class cannot be instantiated on it's own.Sequence is meant to 
			  be a parent class, can be used to achieve polymorphism.
Output given: Class will print out original and modified string.
			  All abstract methods should be overriden by child classes.
			  setState() should remain private and can be accessed through 
			  reset()
*/


#ifndef SEQUENCE
#define SEQUENCE

#include "Inverter.h"
#include <iostream>
#include <string>
#include <sstream> //ostream
#include <functional> //hash
using namespace std;

class Sequence:public Inverter {
public:
	//Description: Constructor
	//Pre: None
	//Post: Sequence state becomes "active" (true) and inverter state becomes 
	//		"not inverted" (false).
	Sequence(string);
	
	//Description: Virtual method that should be implemented from the child
	//			   classes. Definition varies but should modify a word somehow.
	//Pre: None	
	//Post: None
	virtual string mod(void) = 0;

	//Description: Destructor
	//Pre: None
	//Post: NOne
	virtual ~Sequence();

	//Description: Random index is generate in Sequence.java because Sequence
	//			   has the original word's length. Invert the letter at that
	//			   index and index+1
	//Pre: Sequence has to be in an "active" and invert in "not inverted" state
	//Post: Will remain in an "active" state and becomes "inverted"
	string invert() override;

	//Description: Allow the user to guess what the modified word is
	//Pre: Sequence state has to be "not active" (false), inverter state may be
	//	   "inverted" or "not inverted"
	//Post: No state change
	bool guess(string);

	//Description: Resets the the state of the current object, allows user
	//			   to set a new word on the same object. 
	//Pre: State has to be not active (false), Inverter state can be
	// 	   "inverted" or true.
	//Post: State reset to active (true), Inverter state may or may not
	//	    change to "not inverted" (false)
	void reset(string);

	//Description: Gets the current state of the object
	//Pre: None
	//Post: None
	bool isActive();

	//Description: Return the state of the Invert class. 
	//Pre: None
	//Post: None
	bool isInvertState() override;

	//Description: Override object's hashCode method
	//Pre: Sequence state has to be "not active", invert state may or may not
	//	   "inverted"
	//Post: No change
	//Code reference from 
	//		mkyong.com/java/java-how-to-overrides-equals-and-hashcode/
	int hashCode();

	//Description: Override object's toString method to return original word
	//			   and modified word.
	//Pre: Sequence state has to be "not active", invert state may or may not
	//	   "inverted"
	//Post: None
	string toString() const;

	//Description: Operator overloading to compare two objects
	//Pre: has to be in an "active" state. Invert state does not matter
	//Post: None.
	friend ostream& operator<<(ostream&, const Sequence&);

	//Description: Compares two objects to see if they are equal using
	//			  wordFromUser (original word) and classModWord (modified word)
	//			  using operator overloading
	//Pre: Sequence state has to be "not active", invert state may or may not
	//	   "inverted"
	//Post: No change
	bool operator==(const Sequence&) const;

	//Description: Return the index used in invert();
	//Pre: Has to be in an "invert" state, sequence state does not matter
	//Post: None
	int getIndex();


	//Description: Return the original word
	//Pre: Has to be in "active" state, invert state is not relevant
	//Post: None
	string getWord() const;


protected:

	//Description: Holds the word from user in lowercase.
	string wordFromUser;

	//Description: Holds the word after mod() is called.
	string classModWord;

	//Description: Holds the state of the object. 
	//"True" is for active, "False" is for inactive.
	bool state;
	
	//Description: Holds the state of the invert object.
	//not invert ("False") and invert ("True")
	bool invertState;

	//Holds the random generate index used to swap in invert()
	int index;

private:

	//Description: setter - used to set the word for the object. Is protected so it can be used by the child classes. 
	//			   is called by the reset() and will only run if the current state is active (true)
	//Pre: State has to be active
	//Post: No change
	void setWord(string);

};

#endif