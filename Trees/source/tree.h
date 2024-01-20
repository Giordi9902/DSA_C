#ifndef _TREE_H
#define _TREE_H
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"./../Queues/source/queue.h"

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
void BFS(const Nodo_T* root, void (*fun)(int));
/*_____________________________________________________*/

//  Creazione nodo
Nodo_T *CreaNodo(int);
/*______________________________________________________*/

// Inserimento di un nodo
void Insert(Nodo_T** root, int data);
/*______________________________________________________*/

//Ricerca di un nodo
Nodo_T* Search(Nodo_T* root, int data);
Nodo_T* SearchMin(Nodo_T* root);
Nodo_T* SearchMax(Nodo_T* root);
Nodo_T* SearchSuccessore(Nodo_T* root, int data);
/*_____________________________________________________*/
// Cancellazione di un nodo
Nodo_T* Cancella(Nodo_T* root, int data);
Nodo_T* CancellaRadice(Nodo_T* root);
unsigned int StaccaMinimo(Nodo_T* root, Nodo_T* padre);
#endif