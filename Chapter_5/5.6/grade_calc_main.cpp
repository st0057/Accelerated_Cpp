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

  // Remove the failing grades
  //cout << students.size() << endl;
  extract_fails(students);

  //cout << (*students.begin()).name << "  " << grade((*students.begin())) << endl;
  //cout << students.size() << endl;
  for (Students_infos::iterator i = students.begin(); i != students.end(); ++i)
    cout << i->name << " " << grade(*i) << endl;
  //cout << (*fails.begin()).name << "  " << grade((*fails.begin())) << endl;
  return 0;
}