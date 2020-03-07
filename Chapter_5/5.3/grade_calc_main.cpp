#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <vector>
#include "grade.h"
#include "Student_info.h"
#include "extract_fails_ver4.h"

using std::cin;           using std::setprecision;
using std::cout;          using std::sort;
using std::domain_error;   using std::streamsize;
using std::endl;          using std::string;
using std::max;           using std::vector;
using std::list;         

typedef vector<Student_info> Students_infos;
//typedef list<STudent_info> Students_infos;

int main() {
  Students_infos students;
  Students_infos fails;
  Student_info record;

  // read and store all student data
  while (read(cin, record)) {
    // find length of longest name
    students.push_back(record);
  }

  // alphabetize the student records
  // if (typeid(students).name() == "list<Student_info>")
  //   students.sort(compare);
  // else if (typeid(students).name() == "vector<Student_info>")
  sort(students.begin(), students.end(), compare);
  // else
  //   return 1;

  // Extract the failing grades
  fails = extract_fails(students);

  cout << (*fails.begin()).name << "  " << grade((*fails.begin())) << endl;

  return 0;
}