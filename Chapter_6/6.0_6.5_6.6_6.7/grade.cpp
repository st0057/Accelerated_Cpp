#include <algorithm>
#include <stdexcept>
#include <vector>
#include "average.h"
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error;    using std::vector;

bool did_all_hw(const Student_info& s)
{
  return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

double grade(double midterm, double final, double homework)
{
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw)
{
  if (hw.size() == 0)
    throw domain_error("student has done no homework");
  return grade(midterm, final, median(hw));
}

double grade(const Student_info& s)
{
  return grade(s.midterm, s.final, s.homework);
}

double average_grade(const Student_info& s)
{
  return grade(s.midterm, s.final, average(s.homework));
}

// Problem 6.7 extract students that didn't do all hw
vector<Student_info> extract_didnt(vector<Student_info>& students) 
{
  vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), did_all_hw);
  vector<Student_info> didnt(iter, students.end());
  students.erase(iter,students.end());

  return didnt;
}