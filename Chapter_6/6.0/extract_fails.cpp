#include "extract_fails.h"
#include "grade.h"

using std::vector;

vector<Student_info> extract_fails_1(vector<Student_info>& students) 
{
  vector<Student_info> fail;
  remove_copy_if(students.begin(), students.end(), back_inserter(fail), pgrade);
  students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());

  return fail;
}

bool fgrade(const Student_info& s)
{
  return grade(s) < 60;
}

bool pgrade(const Student_info& s)
{
  return !fgrade(s);
}