#include "helper.h"

#include <string.h>
#include <ctype.h>
#include <stdio.h>

int decimal(char string[]) {
    int len = strlen(string);
    int state = 0;
    char val;

    for (int i = 0; i < len; ++i) {
        val = string[i];

        switch (state) {
            case 0:
                if (isdigit(val)) state = 2;
                else if (val == '-' || val == '+') state = 1;
                else return -1;

                break;
            case 1:
                if (isdigit(val)) state = 2;
                else return -1;

                break;
            case 2:
                if (isdigit(val)) state = 2;
                else if (val == '.') state = 3;
                else return -1;

                break;
            case 3:
                if (isdigit(val)) state = 4;
                else return -1;

                break;
            case 4:
                if (isdigit(val)) state = 4;
                else return -1;

                break;
        }
    }

    if (state == 4) {
        return 1;
    }
}

int integer(char string[]) {
    int len = strlen(string);
    int state = 0;
    char val;

    for (int i = 0; i < len; ++i) {
        val = string[i];

        switch (state) {
            case 0:
                if (isdigit(val)) state = 2;
                else if (val == '-' || val == '+') state = 1;
                else return -1;

                break;
            case 1:
                if (isdigit(val)) state = 2;
                else return -1;

                break;
            case 2:
                if (isdigit(val)) state = 2;
                else return -1;
        }
    }

    if (state == 2) {
        return 1;
    }
}

int keyword(char string[]) {
    int len = strlen(string);
    int state = 0;
    char val;

    for (int i = 0; i < len; ++i) {
        val = string[i];

        switch (state) {
			case 0:
				if (val == 'W') state = 1;
				else if (val == '.') state = 6;
				else if (val == '[') state = 7;
				else if (val == ']') state = 8;
				else if (val == '(') state = 9;
				else if (val == ')') state = 10;
				else if (val == ';') state = 11;
				else return -1;

				break;
			case 1:
				if (val == 'R') state = 2;
				else return -1;

				break;
			case 2:
				if (val == 'I') state = 3;
				else return -1;

				break;
			case 3:
				if (val == 'T') state = 4;
				else return -1;

				break;
			case 4:
				if (val == 'E') state = 5;
				else return -1;

				break;

			case 5:
				return -1;

				break;
        }
    }

    if (state == 5 || state == 6 || state == 7 || state == 8 || state == 9 || state == 10 || state == 11) {
        return 1;
    }
}

int identifier(char string[]) {
    int len = strlen(string);
    int state = 0;
    char val;

    for (int i = 0; i < len; ++i) {
        val = string[i];

        switch (state) {
            case 0:
                if (isalpha(val)) state = 1;
                else return -1;

                break;
            case 1:
                if (isalnum(val) || val == '_') state = 1;
                else return -1;

                break;
        }
    }

    if (state == 1) {
        return 1;
    }
}

int string_literal(char string[]) {
    int len = strlen(string);
    int state = 0;
    char val;

    for (int i = 0; i < len; ++i) {
        val = string[i];

        switch (state) {
            case 0:
                if (val == '"') state = 1;
                
                else return -1;

                break;
            case 1:
                if (val != ' ' && val != '"' && val != 9 && val != 10) state = 2;
                else return -1;

                break;
            case 2:
                if (val != ' ' && val != '"' && val != 9 && val != 10) state = 2;
                else if (val == '"') state = 3;
                else return -1;

                break;
            case 3:
                return -1;

                break;
        }
    }

    if (state == 3) {
        return 1;
    }
}

int operator(char string[]) {
    int len = strlen(string);
    int state = 0;
    char val;

    for (int i = 0; i < len; ++i) {
        val = string[i];

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
				else return -1;

                break;
            case 1:
				if (val == '=') state = 2;
				else return -1;

                break;
            case 2:
				return -1;

                break;
            case 3:
                return -1;

                break;
            case 4:
                return -1;

                break;
            case 5:
                return -1;

                break;
            case 6:
                return -1;

                break;
            case 7:
                return -1;

                break;
            case 8:
                return -1;

                break;
            case 9:
                return -1;

                break;
            case 10:
                return -1;

                break;
            case 11:
                if (val == 'R') state = 12;
                else return -1;

                break;
            case 12:
                return -1;
                
                break;

            case 13:
                if (val == 'N') state = 14;
                else return -1;

                break;

            case 14:
                if (val == 'D') state = 15;
                else return -1;

                break;

            case 15:
                return -1;

                break;

            case 16:
                return -1;

                break;

            case 17:
                return -1;

                break;
        }
    }
                
    if ((state >= 2 && state <= 10) || (state <= 15 && state >= 17)) {
        return 1;
    }
}


void lexx(char string[]) {
   	if (decimal(string) == 1) {
        printf("Decimal\n");
    } else if (integer(string) == 1) {
        printf("Integer\n");
    } else if (keyword(string) == 1) {
        printf("Keyword\n");
    } else if (identifier(string) == 1) {
        printf("Identifier\n");
    } else if (string_literal(string) == 1) {
        printf("String\n");
    } else if (operator(string) == 1) {
        printf("Operator\n");
    } else {
        printf("INVALID!\n");
    }
}
