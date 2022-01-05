#ifndef GUARD_grade_h
#define GUARD_grade_h

//grade.h
#include <vector>
#include "Student_info.h"

bool did_all_hw(const Student_info&);
double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
double average_grade(const Student_info&);
// Problem 6.7 extract students that didn't do all hw
std::vector<Student_info> extract_didnt(std::vector<Student_info>&); 

#endif