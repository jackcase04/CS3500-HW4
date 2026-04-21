#include "grammar.h"
#include "tokens.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void get_token() {
    cin >> token;
    cout << "Got token: " << token <<  endl;
}

void error(string expected, string got) {
    cout << "Expected " << expected << ", got" << got << endl;

    exit(EXIT_FAILURE);
}

void is_statement_sequence() {
    parse_statement();

    while (token == ";") {
        parse_statement();
    }
}

void parse_statement() {
    if (identifier(token)) {
        cout << "Need to parse assignment" << endl;
    } else if (token == "WRITE") {
        cout << "Need to parse write statement" << endl;

    } else {
        error("Statement", token);
    }
}