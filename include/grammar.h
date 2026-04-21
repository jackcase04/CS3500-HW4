#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <string>

extern std::string token;

void error(std::string expected); 

void get_token();

void parse_factor();

void parse_term();

void parse_simple_expression();

void parse_expression();

void parse_designator();

void parse_selector();

void parse_assignment();

void parse_write_statement();

void parse_statement();

void parse_statement_sequence();

#endif