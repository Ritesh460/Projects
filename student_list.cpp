#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
//Create structs containing first name, last name, a number for student id, and deicmal for GPA
struct Student {
  char first_name[20];
  char last_name[20];
  int student_id;
  float GPA;
};


//function prototypes
void ADD(vector<Student*> &students);
void PRINT(const vector<Student*> &students);
void DELETE(vector<Student*> &students);
bool QUIT(vector<Student*> &students);


//ask options in this function(ADD,PRINT,DELETE,QUIT)
int main () {
  char option[20];
  vector<Student*> students; //vector for students
  bool running = true;
  //while loop choosing option
  while (running) {
    cout << "Pick an option for your student list(ADD,PRINT,DELETE,QUIT): " << endl;
    cin >> option;
    if (strcmp(option, "ADD") == 0) {
      ADD(students);
    }
    else if (strcmp(option, "PRINT") == 0) {
      PRINT(students);
    }
    else if (strcmp(option, "DELETE") == 0) {
      DELETE(students);
    }
    else if (strcmp(option, "QUIT") == 0) {
      if (QUIT(students)) {
        running = false;
      }
    }
    else {
      cout << "Not an option. Try again!" << endl;
    }
  }
}


//create ADD function for new entry of a student, add stuff in sturct and add to vector of students
void ADD(vector<Student*> &students) {
   //creates new students and lists all attributes
   Student* newStudent = new Student();
   cout << "Enter first name: " << endl;
   cin >> (*newStudent).first_name;
   cout << "Enter last name: " << endl;
   cin >> (*newStudent).last_name;
   cout << "Enter Student ID: " << endl;
   cin >> (*newStudent).student_id;
   cout << "Enter GPA: " << endl;
   cin >> (*newStudent).GPA;
   students.push_back(newStudent);
}

//create PRINT function for printing all students currently stored, GPA is two decimal places, and use iterators(search up)
void PRINT(const vector<Student*> &students) {
  //no students call this
  if (students.empty()) {
    cout << "No students." << endl;
  }
  //iterators for printing all students in vector
  for (const Student* s : students) {
    cout << (*s).first_name << ", " << (*s).last_name << ", " << (*s).student_id << ", " << fixed << setprecision(2) << (*s).GPA << endl; //using import for GPA here
  }
}
//create DELETE function to delete a student id and remove struct from vector
void DELETE(vector<Student*> &students) {
  //no students call this
  if (students.empty()) {
    cout << "No students." << endl;
    return;
  }
  // initializes id for deletion and auto
  int id = 0;
  cout << "ID to delete: " << endl;
  cin >> id; 
  bool none = false;
  auto i = students.begin();//searched for variable detection
  // while loop for deletion
  while (i != students.end()) {
    if ((*i)->student_id == id) {
      delete (*i);
      i = students.erase(i);
      cout << "Student with ID " << id << " deleted." << endl;
      none = true;
    }
    else {
     ++i;
    }
    
  }
  // no ID in there state this
  if (none == false) {
    cout << "No student with that ID" << endl;
  }
}
//create QUIT function for quitting program.
bool QUIT(vector<Student*> &students ) {
  //char for quitting
  char positive;
  cout << "Are you sure you want to quit?(y/n)" << endl;
  cin >> positive;
  //quitting results in end of program
  if (positive == 'y') {
    for (Student* s : students) {
     delete s;
    }	  
    cout << "Ok thanks for playing" << endl;
    students.clear();
    return true;
  }
  //otherwise return back to meny
  else {
    cout << "Go back to menu" << endl;
    return false;
  }
}

