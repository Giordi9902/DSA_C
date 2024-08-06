#ifndef _STACK_H
#define _STACK_H
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"./../Lists/source/list.h"

typedef Nodo_SL *Stack;

Stack Push(Stack P, int key);
int EmptyStack(Stack P);
Stack Pop(Stack P);
int Top(Stack P);