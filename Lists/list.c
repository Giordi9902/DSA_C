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

Nodo_SL *RicercaRicorsiva(Nodo_SL *root,int data)
{
    Nodo_SL* tmp = root;
    if(tmp)
    {
        if(tmp->key == data)
        {
            return tmp;
        }
        else
        {
            return tmp = RicercaRicorsiva(tmp->next,data);
        }
    }
}

Nodo_SL * RicercaIterativa(Nodo_SL * root, int data)
{
    Nodo_SL * tmp = root;
    while(tmp->next && tmp->key != data)
    {
        tmp = tmp->next;
    }
    return tmp;
}