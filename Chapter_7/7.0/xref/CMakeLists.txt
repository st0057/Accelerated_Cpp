
# $ cmake --version

cmake_minimum_required(VERSION 3.5)

# Set the project name

project (cross_ref)

# Add an executable

add_executable(cross_ref main.cpp split.cpp split.h xref.cpp xref.h)