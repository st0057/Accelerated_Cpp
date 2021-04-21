
# $ cmake --version

cmake_minimum_required(VERSION 3.5)

# Set the project name

project (test_find_urls)

# Add an executable

add_executable(test_find_urls test_find_urls.cpp find_urls.cpp find_urls.h)