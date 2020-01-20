
# $ cmake --version

cmake_minimum_required(VERSION 3.5)

# Set the project name

project (grade_calculator)

# Add an executable

add_executable(grade_calculator grade_calc_main.cpp grade.cpp grade.h median.cpp median.h Student_info.cpp Student_info.h extract_fails_ver1.cpp extract_fails_ver2.h)