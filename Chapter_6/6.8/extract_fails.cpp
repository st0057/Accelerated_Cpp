#include "extract_fails.h"
#include "grade.h"
#include <algorithm>

using std::vector;

vector<Student_info> extract_on_criteria(vector<Student_info>& students, bool criteria(const Student_info&)) 
{
  vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), criteria);
  vector<Student_info> fail(iter, students.end());
  students.erase(iter,students.end());

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