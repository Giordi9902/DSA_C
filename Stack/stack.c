#include"stack.h"

Stack Push(Stack P, int key) {
    Nodo_SL *newNode = malloc(sizeof(Nodo_SL));
    if (newNode) 
    {  
        newNode->key = key;
        newNode->next = P;
    }
    return newNode;
}

int EmptyStack(Stack P) {
    return (P == NULL);
}

Stack Pop(Stack P) {
    if (!EmptyStack(P)) 
    {
        Nodo_SL *temp = P;
        P = P->next;
        free(temp);
    }
    return P;
}

int Top(Stack P) {
    if (EmptyStack(P)) {
        fprintf(stderr, "Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return P->key;
}