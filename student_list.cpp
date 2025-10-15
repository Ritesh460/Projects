#include <iostream>
#include <cstring>
#include <vector>
//ask options in this function(ADD,PRINT,DELETE,QUIT)
int main () {
  /*
  char option[20];
  cout << "Pick an option for your student list(ADD,PRINT,DELETE,QUIT): " << endl;
  cin >> option;
  if (option == "ADD") {
    ADD()
  }
  elif (option == "PRINT") {
    PRINT()
  }
  elif (option == "DELETE") {
    DELETE()
  }
  elif (option == "QUIT") {
    QUIT()
  }
  else {
    print("Not an option. Try again!")
    cout << "Pick an option for your student list(ADD,PRINT,DELETE,QUIT): " << endl;
    cin >> option;
  }
  */
  
}
//Create structs containing first name, last name, a number for student id, and deicmal for GPA
struct Student {
  char first_name[20];
  char last_name[20];
  int student_id;
  float GPA;
}
//Need to have vector of struct pointer passed by reference or a vector pointer(which will point to a vector of struct pointers)

//create ADD function for new entry of a student, add stuff in sturct and add to vector of students

//create PRINT function for printing all students currently stored, GPA is two decimal places, and use iterators(search up)

//create DELETE function to delet a student id and remove struct from vector

//create QUIT function for quitting program.
void QUIT() {
  char positive;
  cout << "Are you sure you want to quit?(y/n)" << endl;
  cin >> positive;
  if (positive == 'n') {
    cout << "Ok thanks for playing" << endl;
    return 0;
  }
}

