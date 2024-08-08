#ifndef LIST_H
#define LIST_H
#include<stdio.h>
#include<stdlib.h>

typedef struct Node_SL
{
    int key;
    struct Node_SL *next;
}Node_SL;

Node_SL *New_Node_SL(int );
Node_SL *Free_SL(Node_SL *);

Node_SL *Insert_AtFront_SL(Node_SL *, int );
Node_SL *Insert_AtBack_SL(Node_SL *, int );
Node_SL *Insert_InOrder_SL(Node_SL *, int );
Node_SL *Insert_AfterNode_SL(Node_SL *, int , int );

Node_SL *Remove_FromFront_SL(Node_SL *);
Node_SL *Remove_FromBack_SL(Node_SL *);

Node_SL *Remove_Node_Iterative_SL(Node_SL *, int );
Node_SL *Remove_Node_Recursive_SL(Node_SL*, int);

Node_SL *Find_Predecessor_SL(Node_SL *, int );
Node_SL *Find_Iterative_SL(Node_SL *, int );
Node_SL* Find_Recursive_SL(Node_SL*, int);

void Display_SL(Node_SL *);
void Recursive_Display_SL(Node_SL*);

int Exists_SL(Node_SL *, int );
int Empty_SL(Node_SL*);
int Is_Sorted_SL(Node_SL*);
#endif