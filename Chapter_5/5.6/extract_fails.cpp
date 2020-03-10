#include "extract_fails.h"
#include "Student_info.h"
#include "grade.h"

using std::list;  using std::vector;

// separate passing and failing student records
Students_infos extract_fails(Students_infos& students){
  Students_infos fail;
  Students_infos::iterator iter = students.begin();
  while (iter != students.end()) {
    if (fgrade(*iter)) {
      fail.push_back(*iter);
      iter = students.erase(iter);
    }
    else
      ++iter;
  }
  return fail;
}

bool fgrade(const Student_info& s){
  return grade(s) < 60;
}