#include "extract_fails_ver1.h"
#include "Student_info.h"

using std::vector;

// separate passing and failing student records
vector<Student_info> extract_fails(vector<Student_info>& students){
  for(vector<Student_info>::size_type i = 0; i != students.size(); ++i){
    if (fgrade(students[i]))
      fail.push_back(students[i]);
    else
      pass.push_back(students[i]);
  }
  students = pass;
  return fail;
}

bool fgrade(const Student_info& s){
  return grade(s) < 60;
}