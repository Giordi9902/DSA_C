#!/bin/bash
# Compile tree.c and create object file
gcc -c source/stack.c -o bin/stack.o

# Compile main.c and create object file
gcc -c source/main.c -o bin/main.o

# Link the object files to create the executable
gcc bin/main.o bin/stack.o -o bin/main

echo "Compilation successful. Executable 'main' is in the 'bin' folder."

