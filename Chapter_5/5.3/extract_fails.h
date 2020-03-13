#ifndef GUARD_extract_fails
#define GUARD_extract_fails

#include <list>
#include <vector>
#include "Student_info.h"


//typedef std::vector<Student_info> Students_infos;
typedef std::list<Student_info> Students_infos;

Students_infos extract_fails(Students_infos&);
bool fgrade(const Student_info&);

#endif