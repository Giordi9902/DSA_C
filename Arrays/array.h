#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

/* ARRAY DEFINITION */

typedef struct 
{   
    void* elements;
    size_t element_size;
    size_t capacity;
    size_t lenght;
} Array;

// Print function pointer
typedef void (*PrintFunction)(const void*);

// Allocate memory for any array of prefixed size
Array* CreateArray(size_t,size_t);

// Deallocate memory
void FreeArray(Array*);

// Display all elements in the array
void Display(const Array*,PrintFunction);

// Resize
int Resize(Array*,size_t);

// Add element
int Add(Array*, const void*);

// Delete element
int Delete(Array*, size_t);

// Linear Search element
int LinearSearch(Array*, const void*);

// Get element at specific position
const void * GetAt(Array*,size_t);

// Set element at specific position

// Max finder

// Min finder

// Reverse array

// Shift

// Rotate

// Sort

// Binary research
#endif