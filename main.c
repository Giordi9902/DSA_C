#include<stdio.h>
#include<stdlib.h>
#include"./Arrays/array.h"
#include"./Lists/list.h"
#include"./Test/test.h"


void print_menu();

int main()
{
    print_menu();
    return 0; 
}

void print_menu()
{
    int choice = 0;
    do
    {
        printf("Welcome to Main Menu!\n\n");
        printf("Please, choose a test to run:\n");
        printf("1 : Array\n");
        printf("2 : Lists\n");
        printf("0 : Quit\n\n");
        printf("Choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Welcome to Array Test Suite!\n\n");
            array_test();
            break;
        case 2: 
            printf("Welcome to Lists Test Suite!\n\n");
            lists_test();
            break;
        default:
            printf("Exiting, goodbye!\n");
            break;
        }
    } while (choice != 0);
    
}


