#!/bin/bash
# Compile tree.c and create object file
gcc -c source/stack.c -o object/stack.o

# Compile main.c and create object file
gcc -c source/main.c -o object/main.o

# Link the object files to create the executable
gcc object/main.o object/stack.o -o object/main

echo "Compilation successful. Executable 'main' is in the 'object' folder."

