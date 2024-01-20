#ifndef _QUEUE_H
#define _QUEUE_H
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"./../Lists/source/list.h"

typedef struct Queue{
    Nodo_SL *tail;
    Nodo_SL *head;
}Queue;

// Gestione code
Queue * Enqueue(Queue *Q, int key);
Queue * dequeue(Queue *Q, int *key);
int Head(Queue* Q);
int CodaVuota(Queue *Q);
Queue *CreaCoda(Coda *Q);