#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <string>

extern std::string token;

void error(std::string expected, std::string got); 

void get_token();

void is_statement_sequence();

void parse_statement();

#endif