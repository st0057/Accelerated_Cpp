#ifndef GUARD_extract_fails_h
#define GUARD_extract_fails_h

#include <algorithm>
#include <vector>
#include "Student_info.h"

std::vector<Student_info> extract_fails_1(std::vector<Student_info>&);
std::vector<Student_info> extract_fails_2(std::vector<Student_info>&);
bool fgrade(const Student_info&); 
bool pgrade(const Student_info&);

#endif