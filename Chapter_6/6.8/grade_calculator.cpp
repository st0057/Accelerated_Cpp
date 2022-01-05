#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <list>
#include <stdexcept>
#include "average.h"
#include "extract_fails.h"
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::cin;           using std::setprecision;
using std::cout;          using std::sort;
using std::domain_error;   using std::streamsize;
using std::endl;          using std::string;
using std::max;           using std::vector;
using std::list;          using std::ostream;

double grade_aux(const Student_info& s)
{
  try {
    return grade(s);
  } catch (domain_error) {
    return grade(s.midterm, s.final, 0);
  }
}

// Problem 6.6 - Merge the 3 above functions into one.
double analysis_merge(const vector<Student_info>& students, double grade_scheme(const Student_info&))
{
  vector<double> grades;

  transform(students.begin(),students.end(), back_inserter(grades), grade_scheme);

  return median(grades);
}

void write_analysis(ostream& out, const string& name, double grade_scheme(const Student_info&), const vector<Student_info>& did, const vector<Student_info>& didnt)
{
  out << name << ": median(did) = " << analysis_merge(did, grade_scheme) << ", median(didnt) = " << analysis_merge(didnt, grade_scheme) << endl;
}

int main() {
  vector<Student_info> did, didnt, fails;
  Student_info student;

  // Problem 6.7
  while (read(cin, student))
      did.push_back(student);
  // Extract the students that didn't do all hw
  didnt = extract_on_criteria(did, did_all_hw); // function added to grade.cpp

  // check that both groups contain data
  if (did.empty()) {
    cout << "No student did all the homework!" << endl;
    return 1;
  }
  if (didnt.empty()) {
    cout << "Every student did all the homework!" << endl;
    return 1;
  }

  // do the anaylysis
  write_analysis(cout, "median", grade_aux, did, didnt);
  write_analysis(cout, "average", average_grade, did, didnt);
  write_analysis(cout, "median of homework turned in", optimistic_median, did, didnt);

  // Extract the failing grades
  fails = extract_on_criteria(did, fgrade);
  if (fails.size() != 0)
    cout << (*fails.begin()).name << " " << grade(*(fails.begin())) << endl;
  else 
    cout << "Nobody that did all the hw failed!" << endl;

  return 0;
}