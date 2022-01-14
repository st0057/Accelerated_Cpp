#include "generate_sentence.h"

using std::vector;   using std::string;

vector<string> gen_sentence(const Grammar& g)
{
  vector<string> ret;
  gen_aux(g, "<sentence>", ret);
  return ret;
}