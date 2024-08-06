#include<stdio.h>
#include<stdlib.h>
#include"./Arrays/array.h"

void print_int(const void*);
void print_float(const void*);
void print_string(const void*);


int main()
{
    Array* int_array = CreateArray(5,sizeof(int));
    Display(int_array, print_int);
    int value_1 = 5;
    int value_2 = 19;
    int value_3 = 233;
    Add(int_array,&value_1);
    Add(int_array,&value_2);
    Add(int_array,&value_3);
    Display(int_array,print_int);

    Array * reversed = Reverse(int_array);
    Display(reversed,print_int);
    FreeArray(int_array);
    return 0;
}

void print_int(const void* elem)
{
    printf("%d", *(int*)elem);
}

void print_float(const void* elem)
{
    printf("%.2f", *(float*)elem);
}

void print_string(const void* elem)
{
    printf("%s", *(char**)elem);
}



