#include <iostream>
#include <cstring>
#include <cctype> //added this from internet as one of the functions allow me to take out punctuation and spaces
using namespace std;

int main () {
  // created three arrays(one for regular input, one for input without punct or spaces, and one for the reversed word)
  char word[81];
  char fresh_word[81];
  char new_word[81];
  // input and getting the input
  cout << "Give me a word: ";
  cin.getline(word,81);
  // boolean statement for if it goes over 80 letters
  bool picking = true;
  // while loop for long words
  while (picking) {
    if (strlen(word) > 80) {
      cout << "Too long of a word!" << endl;
      cout << "Give me another word: " << endl;
      cin.getline(word,81);
    }
    else {
      picking = false;
    }
  }
  // loop for converting word to freshword(aka the one with only alphanumerics)
  int num = 0;
  for (int i = 0; word[i] != '\0'; i++) {
    if (isalnum(word[i])) //used for taking off punctutation and spaces
    {	  
    fresh_word[num] = tolower(word[i]);
    num++;
    }
  }
  // loop for getting the reversed word	
  int index = 0;	  
  for (int i = strlen(fresh_word) - 1; i >= 0; i--) {
      new_word[index] = fresh_word[i];
      index++;
  }
  new_word[strlen(fresh_word)] = '\0';
  // compare words to see if palindrome
  int result = strcmp(fresh_word,new_word);
  // check to see if palindrome or not palindrome
  if (result == 0) {
    cout << "Palindrome" << endl;
  } 
  else {
    cout << "Not a palindrome" << endl;
  }
  
  return 0;	
}
