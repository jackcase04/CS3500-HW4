#include "tokens.h"
#include "grammar.h"

#include <iostream>

using namespace std;

string token;

int main() {
    get_token();

    parse_statement_sequence();

    return 0;
}

