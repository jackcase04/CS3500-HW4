#!/bin/bash
g++ src/puckparser.cpp src/tokens.cpp src/grammar.cpp -I include -o puckparser.ex
./puckparser.ex
