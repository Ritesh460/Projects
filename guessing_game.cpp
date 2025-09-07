/*
Ritesh Grandhe 
9/3/25
- Treat your teachers and classmates with respect.
- Be safe.
- Use your class time well.
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
