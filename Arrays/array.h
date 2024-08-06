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
    size_t length;
} Array;

// Print function pointer
typedef void (*PrintFunction)(const void*);
typedef int (*CompareFunc)(const void *, const void *);

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
int LinearSearch(const Array*, const void*);

// Get element at specific position
void * GetAt(const Array*, size_t);
const void * ConstGetAt( const Array*,size_t);

// Set element at specific position
int SetAt(Array *, size_t, const void *);

// Max finder
const void * Max(const Array*, CompareFunc);

// Min finder
const void * Min(const Array*, CompareFunc);

// Reverse array
Array * Reverse(const Array *);

// Sort
void Sort(Array*,CompareFunc);

// Binary research
int BinaryResearch(const Array*,const void*);

#endif