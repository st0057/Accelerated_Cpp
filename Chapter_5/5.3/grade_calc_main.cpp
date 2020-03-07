#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"
#include "extract_fails.h"

using std::cin;           using std::setprecision;
using std::cout;          using std::sort;
using std::domain_error;   using std::streamsize;
using std::endl;          using std::string;
using std::max;           using std::vector;
using std::list;         

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
  //sort(students.begin(), students.end(), compare);
  // else
  //   return 1;

  // Extract the failing grades
  fails = extract_fails(students);

  cout << (*fails.begin()).name << "  " << grade((*fails.begin())) << endl;

  return 0;
}