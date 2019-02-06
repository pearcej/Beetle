/**
FIXME: Place your name(s) and a description of the lab here
Beetle image by Dr. Jan Pearce, Berea College
*/

#include <iostream>
#include <string>
#include <random> //needed for Getrandom
#include <chrono> 
using namespace std;

class Getrandom {
	/** Uses <random> and <chrono> from C++11 to return a random integer in range [1..size] */
public:
	Getrandom(int size) {
		auto seed = chrono::system_clock::now().time_since_epoch().count(); //gets a new seed for the randomness
		default_random_engine generator(seed);			//seeds our randomness
		uniform_int_distribution<int> intdist(1, size); //a distibution to make each in-range integer equally likely
		self_rand_int_ = intdist(generator);			//generates the randme number
	}
	int roll() {
		return self_rand_int_;
	}
private:
	int self_rand_int_;
};

class Dice {
	/** class that can be used to make dice.
	Dependent upon the Getrandom class above. */
public:
	Dice() {// default constructor assumes a 6-sided die.
		self_roll_count_ = 0;
		self_sides_ = 6;
	}
	Dice(int sides) {        // constructor for any size dice
		self_roll_count_ = 0;
		self_sides_ = sides;
	}
	int roll() {             // return the random roll of the die
		// postcondition: number of rolls updated, random 'die' roll returned

		Getrandom newrandom(self_sides_);
		self_roll_count_ = self_roll_count_ + 1;         // update # of times die rolled
		return(newrandom.roll());
	}
	int get_sides() const {   // how many sides this die has
		// postcondition: return # of sides of die
		return self_sides_;
	}
	int get_roll_count() const {   // # times this die rolled
		// postcondition: return # of times die has been rolled
		return self_roll_count_;
	}
private:
	int self_roll_count_;       // # times die rolled
	int self_sides_;           // # sides on die
}; //a semi colon must end every C++ class declaration.

class Beetle 
{
public:  
	Beetle() {
		//FIXME: initialize all member variables
	}

	//FIXME: Add all of your methods

	void show() const { 
		//FIX ME -- this needs to done using << overloading
		// and it needs to show the partial Beetle.
		for (int i = 0; i < len_beetle; i++) {
			cout << complete_beetle[i] << endl;
		}
		return; 
	}
private:
	//FIXME: declare all member class and instance variables here
	const int len_beetle = 11;
	//Note: You do not need to use my Beetle image..., but you may.
	string complete_beetle[11]={
		"      Y   Y      ",
		"      \\\\_//      ",
		"     .@   @.     ",
		"  v__/  -  \\__v  ",
		"v___|---.---|___v",
		" v__|   |   |__v ",
		"    \\   |   /    ",
		"     `. : .'     ",
		"       |:|       ",
		"       |:|       ",
		"        v        "
	};
	

}; //don't forget semi-colon!!


int main( ){

	char readchar;

	//FIXME: Make your own again

	Beetle beetle1;
	beetle1.show();

	cin >> readchar; //This is to keep screen open in some situations.

	return 0;
}

