#include"list.h"

// Gestione liste
Nodo_SL *CreaNodoSL(int data)
{
    Nodo_SL *tmp = malloc(sizeof(Nodo_SL));
    if(tmp)
    {
        tmp->next = NULL;
        tmp->key = data;
    }
    return tmp;
}

Nodo_SL *InserisciInTesta(Nodo_SL *root, int data)
{
    Nodo_SL *tmp = NULL;
    tmp = CreaNodoSL(data);
    if(tmp)
    {
        tmp->next = root;
        root = tmp;
    }
    return root;
}

Nodo_SL *InserisciInCoda(Nodo_SL *root, int data)
{
    Nodo_SL *tmp = NULL;
    Nodo_SL *p = root;
    if(!root)
    {
        root = InserisciInTesta(root,data);
    }
    else
    {
        tmp = CreaNodoSL(data);
        while(p->next)
        {
            p = p->next;
        }
        p -> next = tmp;
    }
    return root;
}