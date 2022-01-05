#ifndef GUARD_extract_fails_h
#define GUARD_extract_fails_h

#include <algorithm>
#include <vector>
#include "Student_info.h"

std::vector<Student_info> extract_on_criteria(std::vector<Student_info>& students, bool criteria(const Student_info&));
bool fgrade(const Student_info&); 
bool pgrade(const Student_info&);

#endif