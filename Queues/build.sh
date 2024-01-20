# Compile tree.c and create object file
gcc -c source/queue.c -o object/queue.o

# Compile main.c and create object file
gcc -c source/main.c -o object/main.o

# Link the object files to create the executable
gcc object/main.o object/queue.o -o object/main

echo "Compilation successful. Executable 'main' is in the 'object' folder."

