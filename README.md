# Sequence

Author: Nina Nguyen
Filename: p5x.cpp
11/30/2017
Version 1
Project: P5x
CPSC 5011

This program demonstrates the use of abstract class. This program will use 7 words and 7 guessed words to test seven
			  Sequence type objects. 3 SequenceEnum, 2 SpasEnum, 2 SeqExtract.
        
Sequence:
This class is an abstract class that implement the Inverter
			  interface and provides abstract methods that needs to be
		      implemented by the child classes.The class itself can't be 
			  instantiated.The class will be the parent class for child
			  class that takes in a word from the driver with 3 or more
		      letters and manipulated in some way.The user can guess
			  what the modified word is.
        
SeqExtract:
This class extends the abstract Sequence class. It override the
abstract method mod() from Sequence to create a subsequence at
random indexed. A helper method is called from mod() to take in
the the subsequence as a parameter and will extract the word
without the subsequence string in it.
Inverter state does not affect mod().


SpasEnum:
This class extends the abstract Sequence class. It override the
abstract method mod() from Sequence to create a subsequence at
random indexed. Then the subsequence string will either be
concatenate or trunction dependent on state of the object.
Inverter state does not affect mod().
        
SequenceEnum:
This class extends the abstract Sequence class. It override the
			  abstract method mod() from Sequence to duplicate a letter at a
			  random index. All other methods and variables are inherited from
			  Sequence.
        
 Built with:
 Visual Studios
 Vim
 
 Acknowledgement:
 P5x Seattle U
