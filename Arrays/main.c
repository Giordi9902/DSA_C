#include<stdio.h>
#include<stdlib.h>
#include"array.h"
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *array = create_array(n, 0);
    printf("\n");
    printf("Enter %d numbers: \n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    printf("The numbers are: [");
    print_array(array, n);
    printf("]\n");
    array = quicksort(array, 0, n - 1);
    printf("The sorted numbers are: [");
    print_array(array, n);
    printf("]\n");
    if (check_sorted(array, n))
    {
        printf("The array is sorted.\n");
    }
    else
    {
        printf("The array is not sorted.\n");
    }
    free(array);
    return 0;
}