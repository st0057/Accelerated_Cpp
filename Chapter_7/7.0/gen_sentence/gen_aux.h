#ifndef GUARD_GEN_AUX_H
#define GUARD_GEN_AUX_H
#include <stdexcept>
#include <string>
#include <vector>

#include "bracketed.h"
#include "nrand.h"
#include "read_grammar.h"

void gen_aux(const Grammar&, const std::string&, std::vector<std::string>&);
#endif