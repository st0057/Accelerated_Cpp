#include "extract_fails.h"
#include <iostream>
#include "Student_info.h"
#include "grade.h"

using std::list;  using std::vector;
using std::cout;  using std::endl;

// separate passing and failing student records
int extract_fails(Students_infos& students){
  
  int i = 0;
  for (Students_infos::iterator iter = students.begin(); iter != students.end(); ++iter) {
    //cout << iter->name << endl;
    if (!fgrade(*iter)) {
      //students.insert(*iter, students.begin());
      *(students.begin() + i) = *iter;
      ++i;
    }
  }
  students.resize(i);

  return 0;
}

bool fgrade(const Student_info& s){
  return grade(s) < 60;
}