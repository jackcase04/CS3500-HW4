#include "tokens.h"

#include <ctype.h>
#include <iostream>

using namespace std;

bool decimal(string local_token) {
    int len = local_token.size();
    int state = 0;
    char val;

    for (int i = 0; i < len; ++i) {
        val = local_token[i];

        switch (state) {
            case 0:
                if (isdigit(val)) state = 2;
                else if (val == '-' || val == '+') state = 1;
                else return false;

                break;
            case 1:
                if (isdigit(val)) state = 2;
                else return false;

                break;
            case 2:
                if (isdigit(val)) state = 2;
                else if (val == '.') state = 3;
                else return false;

                break;
            case 3:
                if (isdigit(val)) state = 4;
                else return false;

                break;
            case 4:
                if (isdigit(val)) state = 4;
                else return false;

                break;
        }
    }

    if (state == 4) {
        return true;
    }

    return false;
}

bool integer(string local_token) {
    int len = local_token.size();
    int state = 0;
    char val;

    for (int i = 0; i < len; ++i) {
        val = local_token[i];

        switch (state) {
            case 0:
                if (isdigit(val)) state = 2;
                else if (val == '-' || val == '+') state = 1;
                else return false;

                break;
            case 1:
                if (isdigit(val)) state = 2;
                else return false;

                break;
            case 2:
                if (isdigit(val)) state = 2;
                else return false;
        }
    }

    if (state == 2) {
        return true;
    }

    return false;
}

bool identifier(string local_token) {
    if (local_token == "WRITE"
        || local_token == "OR"
        || local_token == "AND"
    ) {
        return false;
    }

    int len = local_token.size();
    int state = 0;
    char val;

    for (int i = 0; i < len; ++i) {
        val = local_token[i];

        switch (state) {
            case 0:
                if (isalpha(val)) state = 1;
                else return false;

                break;
            case 1:
                if (isalnum(val) || val == '_') state = 1;
                else return false;

                break;
        }
    }

    if (state == 1) {
        return true;
    }

    return false;
}

bool string_literal(string local_token) {
    int len = local_token.size();
    int state = 0;
    char val;

    for (int i = 0; i < len; ++i) {
        val = local_token[i];

        switch (state) {
            case 0:
                if (val == '"') state = 1;
                
                else return false;

                break;
            case 1:
                if (val != ' ' && val != '"' && val != 9 && val != 10) state = 2;
                else return false;

                break;
            case 2:
                if (val != ' ' && val != '"' && val != 9 && val != 10) state = 2;
                else if (val == '"') state = 3;
                else return false;

                break;
            case 3:
                return false;

                break;
        }
    }

    if (state == 3) {
        return true;
    }

    return false;
}

bool is_mul_operator(string local_token) {
    if (local_token == "*" || local_token == "/" || local_token == "AND") return true;
    return false;
}

bool is_add_operator(string local_token) {
    if (local_token == "+" || local_token == "-" || local_token == "OR" || local_token == "&") return true;
    return false;
}

bool is_relation(string local_token) {
    if (local_token == "<" || local_token == ">" || local_token == "=" || local_token == "#") return true;
    return false;
}