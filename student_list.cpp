#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
//Create structs containing first name, last name, a number for student id, and deicmal for GPA
struct Student {
  char first_name[20];
  char last_name[20];
  int student_id;
  float GPA;
};



//function prototypes
void ADD(vector<Student*> students);
void PRINT(const vector<Student*> students);
bool QUIT();


//ask options in this function(ADD,PRINT,DELETE,QUIT)
int main () {
  char option[20];
  vector<Student*> students;
  cout << "Pick an option for your student list(ADD,PRINT,DELETE,QUIT): " << endl;
  cin >> option;
  if (option == "ADD") {
    ADD(vector<Student*> students);
  }
  else if (option == "PRINT") {
    PRINT(vector<Student*> students);
  }
  else if (option == "DELETE") {
    //DELETE(vector<Student*> students)
    cout << "deleted" << endl;
  }
  else if (option == "QUIT") {
    QUIT(vector<Student*> students);
  }
  else {
    cout << "Not an option. Try again!" << endl;
    cout << "Pick an option for your student list(ADD,PRINT,DELETE,QUIT): " << endl;
    cin >> option;
  }
}

//Need to have vector of struct pointer passed by reference or a vector pointer(which will point to a vector of struct pointers)
//create ADD function for new entry of a student, add stuff in sturct and add to vector of students
void ADD(vector<Student*> &students) {
   Student* newStudent = new Student();
   cout << "Enter first name: " << endl;
   cin >> (*newStudent).first_name;
   cout << "Enter last name: " << endl;
   cin >> (*newStudent).last_name;
   cout << "Enter Student ID: " << endl;
   cin >> (*newStudent).student_id;
   cout << "Enter GPA: " << endl;
   cin >> (*newStudent).student_id;
   students.push_back(newStudent);
}
//
//create PRINT function for printing all students currently stored, GPA is two decimal places, and use iterators(search up)
void PRINT(const vector<Student*> &students) {
  for (const Student* s : students) {
    cout << (*s).first_name << (*s).last_name << (*s).student_id << (*s).GPA << endl;
  }
}
//create DELETE function to delete a student id and remove struct from vector
//void DELETE(vector<Student*> &students);
//cars.pop_back();
//create QUIT function for quitting program.
bool QUIT() {
  char positive;
  cout << "Are you sure you want to quit?(y/n)" << endl;
  cin >> positive;
  if (positive == 'n') {
    cout << "Ok thanks for playing" << endl;
    return 0;
  }
}

