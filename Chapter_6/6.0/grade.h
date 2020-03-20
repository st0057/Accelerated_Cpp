#ifndef GUARD_grade_h
#define GUARD_grade_h

//grade.h
#include <vector>
#include "Student_info.h"

bool did_all_hw(const Student_info&)
double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);

#endif