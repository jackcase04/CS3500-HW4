#ifndef TOKENS_H 
#define TOKENS_H

#include <string>

bool decimal(std::string local_token);

bool integer(std::string local_token);

bool keyword(std::string local_token);

bool identifier(std::string local_token);

bool string_literal(std::string local_token);

bool is_operator(std::string local_token);

#endif