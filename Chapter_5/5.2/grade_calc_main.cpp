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
#include "extract_fails_ver4.h"

using std::cin;           using std::setprecision;
using std::cout;          using std::sort;
using std::domain_error;   using std::streamsize;
using std::endl;          using std::string;
using std::max;           using std::vector;
using std::list;

int main() {
  // vector<Student_info> students;
  // vector<Student_info> fails;
  list<Student_info> students;
  list<Student_info> fails;
  Student_info record;

  // read and store all student data
  while (read(cin, record)) {
    // find length of longest name
    students.push_back(record);
  }

  // alphabetize the student records
  students.sort(compare);
  //sort(students.begin(), students.end(), compare);

  // Extract the failing grades
  fails = extract_fails(students);

  cout << (*fails.begin()).name << "  " << grade((*fails.begin())) << endl;

  return 0;
}