#!/bin/bash

clang++ -Wall -std=c++14 main.cpp -o out && ./out < input && rm ./out