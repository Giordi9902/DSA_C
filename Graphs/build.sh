#!/bin/bash
# Compile list.c and create object file
gcc -c source/graph.c -o bin/graph.o

# Compile main.c and create object file
gcc -c source/main.c -o bin/main.o

# Link the object files to create the executable
gcc bin/main.o bin/graph.o -o bin/main

echo "Compilation successful. Executable 'main' is in the 'bin' folder."