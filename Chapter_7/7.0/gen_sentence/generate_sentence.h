#ifndef GUARD_GENERATE_SENTENCE_H
#define GUARD_GENERATE_SENTENCE_H
#include <string>
#include <vector>

#include "gen_aux.h"
#include "read_grammar.h"

std::vector<std::string> gen_sentence(const Grammar&);
#endif