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

// Operazioni binarie
unsigned int Conta_OccorrenzeSL(Nodo_SL *root, int data);
int Is_PresenteSL(Nodo_SL *root, int data);

// Operazioni unarie
int Is_ListaOrdinataSL(Nodo_SL *root);