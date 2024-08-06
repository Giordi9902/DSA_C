#ifndef _LIST_H
#define _LIST_H
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Definizione nodo lista
typedef struct Nodo_SL
{
    int key;
    struct Nodo_SL *next;
}Nodo_SL;

typedef struct Nodo_DL
{
    int key;
    struct Nodo_DL *prev;
    struct Nodo_DL *next;
}Nodo_DL;

// Gestione liste
Nodo_SL *CreaNodoSL(int data);
Nodo_SL *InserisciInTesta(Nodo_SL *root, int data);
Nodo_SL *InserisciInCoda(Nodo_SL *root, int data);
Nodo_SL *RicercaRicorsiva(Nodo_SL * root,int data);

#endif