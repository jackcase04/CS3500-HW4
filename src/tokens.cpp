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

bool keyword(string local_token) {
    int len = local_token.size();
    int state = 0;
    char val;

    for (int i = 0; i < len; ++i) {
        val = local_token[i];

        switch (state) {
			case 0:
				if (val == 'W') state = 1;
				else if (val == '.') state = 6;
				else if (val == '[') state = 7;
				else if (val == ']') state = 8;
				else if (val == '(') state = 9;
				else if (val == ')') state = 10;
				else if (val == ';') state = 11;
				else return false;

				break;
			case 1:
				if (val == 'R') state = 2;
				else return false;

				break;
			case 2:
				if (val == 'I') state = 3;
				else return false;

				break;
			case 3:
				if (val == 'T') state = 4;
				else return false;

				break;
			case 4:
				if (val == 'E') state = 5;
				else return false;

				break;

			case 5:
				return false;

				break;
        }
    }

    if (state == 5 || state == 6 || state == 7 || state == 8 || state == 9 || state == 10 || state == 11) {
        return true;
    }

    return false;
}

bool identifier(string local_token) {
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

bool is_operator(string local_token) {
    int len = local_token.size();
    int state = 0;
    char val;

    for (int i = 0; i < len; ++i) {
        val = local_token[i];

        switch (state) {
            case 0:
				if (val == ':') state = 1;
				else if (val == '~') state = 3;
				else if (val == '<') state = 4;
				else if (val == '>') state = 5;
				else if (val == '=') state = 6;
				else if (val == '#') state = 7;
				else if (val == '+') state = 8;
				else if (val == '-') state = 9;
				else if (val == '&') state = 10;
				else if (val == 'O') state = 11;
				else if (val == 'A') state = 13;
				else if (val == '*') state = 16;
				else if (val == '/') state = 17;
				else return false;

                break;
            case 1:
				if (val == '=') state = 2;
				else return false;

                break;
            case 2:
				return false;

                break;
            case 3:
                return false;

                break;
            case 4:
                return false;

                break;
            case 5:
                return false;

                break;
            case 6:
                return false;

                break;
            case 7:
                return false;

                break;
            case 8:
                return false;

                break;
            case 9:
                return false;

                break;
            case 10:
                return false;

                break;
            case 11:
                if (val == 'R') state = 12;
                else return false;

                break;
            case 12:
                return false;
                
                break;

            case 13:
                if (val == 'N') state = 14;
                else return false;

                break;

            case 14:
                if (val == 'D') state = 15;
                else return false;

                break;

            case 15:
                return false;

                break;

            case 16:
                return false;

                break;

            case 17:
                return false;

                break;
        }
    }
                
    if ((state >= 2 && state <= 10) || (state <= 15 && state >= 17)) {
        return true;
    }

    return false;
}