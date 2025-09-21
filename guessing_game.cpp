/*
Ritesh Grandhe 
9/3/25
<<<<<<< HEAD
1. No global variables. (Global constants are all right.)

2. No strings. Not ever. (You can use cstrings/character arrays, and the cstring and cctype libraries are okay. In fact, I recommend using strcmp and strlen in your projects.)

3. You should include <iostream>, not stdio. (This applies more to C programmers.) Also, use "new" and "delete" instead of "malloc" and "free".
*/
#include <iostream>
//I searched up these two imports to know which ones I needed for srand(time(NULL))
#include <stdlib.h>
#include <time.h>
using namespace std;
//main function
int main() 
{
	//variables for while loops
	bool guessing = true;
	char decide = 'Y';
	//first while loop
	while (decide == 'Y'){
		//variables for guesses count and random number
		guessing = true;
		int guesses = 0;
		int random = rand() % 101;
		//second while loop	
		while (guessing == true)
		{
			srand(time(NULL));
			// choosing guesses and conditions if high/low
			int guess = 0; 
   			cout << "Guess a number:" << endl;
   			cin >> guess;
   			if (guess > random) {
   				cout << "Too high!" << endl;
				guesses += 1;		
   			}
   			else if (guess < random) {
   				cout << "Too low!" << endl;
				guesses += 1;
   			}
   			else {
				// getting correct answer break out of second loop
   				cout << "You got the correct answer!" << endl;
				guesses += 1;
				guessing = false;
   			}	  
		}
		//ask user if they want to play again, if not break out of first loop
		cout << "The number of guesses you did was " << guesses << "!" << endl;
		cout << "Do you want to play again?(Y/N): ";
		cin >> decide;
	}
	//if user said no, end program	
	cout << "Thank you for playing!" << endl;	
	return 0;
}
