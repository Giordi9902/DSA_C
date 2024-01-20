#ifndef _TREE_H
#define _TREE_H
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Definizione nodo albero
typedef struct Nodo_T
{
    int key;
    struct Nodo_T *left;
    struct Nodo_T *right;
}Nodo_T;

// Funzioni unarie
void print(int);
void isEven(int);
void isLeaf(const Nodo_T*);
/*_____________________________________________________*/

// Funzioni di visita che applicano funzioni unarie
void InOrderVisit(const Nodo_T* root, void(*fun)(int));
void PostOrderVisit(const Nodo_T* root, void (*fun)(int));
void PreOrderVisit(const Nodo_T* root, void (*fun)(int));
/*_____________________________________________________*/

//  Creazione nodo
Nodo_T *CreaNodo(int);
/*______________________________________________________*/

// Inserimento di un nodo
void Insert(Nodo_T** root, int data);
/*______________________________________________________*/

//Ricerca di un nodo
Nodo_T* Search(Nodo_T* root, int data);
/*_____________________________________________________*/
#endif