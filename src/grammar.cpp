#include "grammar.h"
#include "tokens.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void get_token() {
    cin >> token;
}

void error(string expected) { 
    cout << "INVALID!\nError: \"" << expected << "\" expected, got \"" << token << "\"" << endl;

    exit(EXIT_FAILURE);
}

void parse_factor() {
    if (integer(token) ||
        decimal(token) ||
        string_literal(token) ||
        identifier(token)
    )
    {
        get_token();
    }
    else if (token == "(") 
    {
        get_token();
        parse_expression();

        if (token == ")") {
            get_token();
        } else {
            error(")");
        }
    }
    else if (token == "~") {
        get_token();
        parse_factor();
    }
    else
    {
        error("One of integer | decimal | string | identifier | ( Expression ) | ~ Factor");
    }
}

void parse_term() {
    parse_factor();

    while (is_mul_operator(token)) {
        get_token();
        parse_factor();
    }
}

void parse_simple_expression() {
    parse_term();

    while (is_add_operator(token)) {
        get_token();
        parse_term();
    }
}

void parse_expression() {
    parse_simple_expression();

    if (is_relation(token)) {
        get_token();
        parse_simple_expression();
    }
}

void parse_designator() {
    if (identifier(token)) {
        get_token();
    } else {
        error("Identifier");
    }

    // Technically, the . and [ is supposed to be part of the Selector symbol
    // But it makes the most implementation sense to check for it here.
    // We just check for the starting terminals of the selector to identify if a selector occurs
    while (token == "." || token == "[") {
        parse_selector();
    }
}

void parse_selector() {
    if (token == ".") {
        get_token();
        
        if (identifier(token)) {
            get_token();
        } else {
            error("Identifier");
        }
    } else if (token == "[") {
        get_token();
        parse_expression();

        if (token == "]") {
            get_token();
        } else {
            error("]");
        }
    } else {
        error("One of . identifier | [ Expression ]");
    }
}

void parse_assignment() {
    parse_designator();

    if (token == ":=") {
        get_token();

        parse_expression();
    } else {
        error(":=");
    }
}

void parse_write_statement() {
    if (token == "WRITE") {
        get_token();

        if (token == "(") {
            get_token();

            parse_expression();

            if (token == ")") {
                get_token();
            } else {
                error(")");
            }
        } else {
            error("(");
        }
    } else {
        error("WRITE");
    }
}

void parse_statement() {
    if (token == "WRITE") {
        parse_write_statement();
    } else {
        parse_assignment();
    }
}

void parse_statement_sequence() {
    parse_statement();

    while (token == ";") {
        get_token();

        parse_statement();
    }

    cout << "VALID\n";
}