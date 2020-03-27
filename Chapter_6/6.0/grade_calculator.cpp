#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <list>
#include <stdexcept>
#include "average.h"
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

double median_analysis(const vector<Student_info>& students)
{
  vector<double> grades;

  transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
  return median(grades);
}

double average_analysis(const vector<Student_info>& students)
{
  vector<double> grades;

  transform(students.begin(), students.end(), back_inserter(grades), average_grade);

  return median(grades);
}

double optimistic_median_analysis(const vector<Student_info>& students)
{
  vector<double> grades;

  transform(students.begin(),students.end(), back_inserter(grades), optimistic_median);

  return median(grades);
}

void write_analysis(ostream& out, const string& name, double analysis(const vector<Student_info>&), const vector<Student_info>& did, const vector<Student_info>& didnt)
{
  out << name << ": median(did) = " << analysis(did) << ", median(didnt) = " << analysis(didnt) << endl;
}

int main() {
  vector<Student_info> did, didnt;
  Student_info student;

  // read all the records, separating them based on whether all hw was done
  while (read(cin, student)) {
    if (did_all_hw(student))
      did.push_back(student);
    else
      didnt.push_back(student);
  }

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
  write_analysis(cout, "median", median_analysis, did, didnt);
  write_analysis(cout, "average", average_analysis, did, didnt);
  write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);
  
  return 0;
}