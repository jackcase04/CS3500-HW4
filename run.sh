#!/bin/bash
gcc src/puckparser.c src/tokens.c -I include -o puckparser.ex
./a.out
