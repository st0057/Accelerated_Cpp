#include "extract_fails.h"
#include "Student_info.h"
#include "grade.h"

using std::list;  using std::vector;

// separate passing and failing student records
int extract_fails(Students_infos& students){
  Students_infos::iterator iter = students.begin();
  int i = 0;
  while (iter != students.end()) {
    if (!fgrade(*iter)) {
      //students.insert(*iter, students.begin());
      students.begin() = iter;
      ++i;
    }
    ++iter;
  }
  students.resize(i);

  return 0;
}

bool fgrade(const Student_info& s){
  return grade(s) < 60;
}