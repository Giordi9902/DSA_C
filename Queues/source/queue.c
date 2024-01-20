#include"queue.h"

int CodaVuota(Queue* Q)
{
    return (Q->head == NULL);
}

Queue* CreaCoda(Queue *Q)
{
    if(Q)
    {
        Q->head = NULL;
        Q->tail = NULL;
    }
    else
    {
        Q = malloc(sizeof(Queue));
        if (Q)
        {
            Q->head = NULL;
            Q->tail = NULL;
        }
    }
    return Q;
}


Queue* Enqueue(Queue *Q, int data)
{
    Nodo_SL *tmp;
    if (Q)
    {
        if (CodaVuota(Q))
        {
            Q->head = Q->tail = CreaNodoSL(data);
        }
        else
        {
            tmp = CreaNodoSL(data);
            if (tmp)
            {
                Q->tail->next = tmp;
                Q->tail = tmp;
            }
        }
    }
    return Q;
}


Queue* Dequeue(Queue* Q, int *key)
{
    Nodo_SL *tmp;
    if (CodaVuota(Q) || key == NULL) 
        return Q;
    if (Q->head == Q->tail)
    {
        *key = Q->head->key;
        free(Q->head);
        Q->head = Q->tail = NULL;
    }
    else
    {
        tmp = Q->head;
        *key = Q->head->key;
        Q->head = Q->head->next;
        free(tmp);
    }
    return Q;
}

int Head(Queue* Q)
{
    if(Q)
    {
        return Q->head->key;
    }
}