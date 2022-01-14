
# $ cmake --version

cmake_minimum_required(VERSION 3.5)

# Set the project name

project (gen_sentence)

# Add an executable

add_executable(gen_sentence main.cpp read_grammar.cpp read_grammar.h split.cpp split.h bracketed.cpp bracketed.h gen_aux.cpp gen_aux.h generate_sentence.cpp generate_sentence.h
nrand.cpp nrand.h)