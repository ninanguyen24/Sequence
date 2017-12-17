/*Author: Nina Nguyen
Filename: Inverter.h
11/30/2017
Version 1
Project: P5x
CPSC 5011*/

/*
~Description: This is an interface.Any class that implements this class
			needs to implement the two method.Inverter has an index that
			should be declared by the implement class.
			The Inverter class will swap a letter at index with the letter
			at index + 1.
~Functionality : invert() and isInvertState() are both method signatures.
~Legal State : None, implement class will define state.
~Dependencies : Relies on implemented class.
~Anticipated use : To be implemented by another class.Cannot be instantiated.
~State : Defined by implemented class.
*/

#ifndef INVERTER
#define INVERTER

#include <iostream>
#include <string>
using namespace std;

class Inverter {
public:

	//Description: This method will be implemented in the class that uses 
	//				this interface. Method should swap the letter at index
	//   		 	and index + 1.
	virtual string invert() = 0;

	//Description: This method return the current state of the inverter
	//			   in classes that uses the interface.
	virtual bool isInvertState() = 0;

	//Description: Destructor
	virtual ~Inverter();

};

#endif