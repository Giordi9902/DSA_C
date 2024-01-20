#!/bin/bash
gcc -c tree.c
gcc -c main.c
gcc -o main main.o tree.o