#include <iostream>
#include <string>
#include <vector>

bool not_url_char(char);
std::string::const_iterator url_end(std::string::const_iterator, std::string::const_iterator);
std::string::const_iterator url_beg(std::string::const_iterator, std::string::const_iterator);
std::vector<std::string> find_urls(const std::string&);
std::istream& read(std::istream&, std::vector<std::string>&);