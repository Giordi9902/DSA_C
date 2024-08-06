#include "array.h"
#include <stdio.h>
#include <stdlib.h>
int *create_array(int n, int initial_value)
{
    int *array = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        array[i] = initial_value;
    }
    return array;
}

int partition(int *array, int p, int r)
{
    int pivot = array[p];
    int j = r + 1;
    int i = p - 1;
    do
    {
        do
        {
            j--;
        } while ((array[j] > pivot));
        do
        {
            i++;
        } while ((array[i] < pivot));
        if (i < j)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    } while (i < j);
    return j;
}

int *quicksort(int *array, int p, int r)
{
    if (p < r)
    {
        int q = partition(array, p, r);
        quicksort(array, p, q);
        quicksort(array, q + 1, r);
    }
    return array;
}

void print_array(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}

int check_sorted(int *array, int n)
{
    int sorted = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            sorted = 0;
            break;
        }
    }
    return sorted;
}