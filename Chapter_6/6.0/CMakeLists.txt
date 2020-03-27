
# $ cmake --version

cmake_minimum_required(VERSION 3.5)

# Set the project name

project (grade_calculator)

# Add an executable

add_executable(grade_calculator grade_calculator.cpp grade.cpp grade.h median.cpp median.h Student_info.cpp Student_info.h average.cpp average.h)