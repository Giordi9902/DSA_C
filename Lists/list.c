#include "list.h"

/*  $$$$$$\  $$\                     $$\                  */
/* $$  __$$\ \__|                    $$ |                 */
/* $$ /  \__|$$\ $$$$$$$\   $$$$$$\  $$ | $$$$$$\         */
/* \$$$$$$\  $$ |$$  __$$\ $$  __$$\ $$ |$$  __$$\        */
/*  \____$$\ $$ |$$ |  $$ |$$ /  $$ |$$ |$$$$$$$$ |       */
/* $$\   $$ |$$ |$$ |  $$ |$$ |  $$ |$$ |$$   ____|       */
/* \$$$$$$  |$$ |$$ |  $$ |\$$$$$$$ |$$ |\$$$$$$$\        */
/*  \______/ \__|\__|  \__| \____$$ |\__| \_______|       */
/*                         $$\   $$ |                     */
/*                         \$$$$$$  |                     */
/*                          \______/                      */
/* $$\       $$\           $$\                       $$\  */
/* $$ |      \__|          $$ |                      $$ | */
/* $$ |      $$\ $$$$$$$\  $$ |  $$\  $$$$$$\   $$$$$$$ | */
/* $$ |      $$ |$$  __$$\ $$ | $$  |$$  __$$\ $$  __$$ | */
/* $$ |      $$ |$$ |  $$ |$$$$$$  / $$$$$$$$ |$$ /  $$ | */
/* $$ |      $$ |$$ |  $$ |$$  _$$<  $$   ____|$$ |  $$ | */
/* $$$$$$$$\ $$ |$$ |  $$ |$$ | \$$\ \$$$$$$$\ \$$$$$$$ | */
/* \________|\__|\__|  \__|\__|  \__| \_______| \_______| */
/*                                                        */
/*                                                        */
/*                                                        */
/* $$\       $$\             $$\                          */
/* $$ |      \__|            $$ |                         */
/* $$ |      $$\  $$$$$$$\ $$$$$$\    $$$$$$$\            */
/* $$ |      $$ |$$  _____|\_$$  _|  $$  _____|           */
/* $$ |      $$ |\$$$$$$\    $$ |    \$$$$$$\             */
/* $$ |      $$ | \____$$\   $$ |$$\  \____$$\            */
/* $$$$$$$$\ $$ |$$$$$$$  |  \$$$$  |$$$$$$$  |           */
/* \________|\__|\_______/    \____/ \_______/            */

Node_SL *New_Node_SL(int data)
{
    Node_SL *tmp;
    tmp = malloc(sizeof(Node_SL));
    if (tmp)
    {
        tmp->next = NULL;
        tmp->key = data;
    }
    return tmp;
}

void Display_SL(Node_SL *head)
{
    Node_SL *temp = head;
    while (temp)
    {
        printf("%d\t", temp->key);
        temp = temp->next;
    }
    printf("\n");
}

int Empty_SL(Node_SL* head)
{
    return (head == NULL);
}

// Node_SL *Revert_SL(Node_SL *Lista1)
// {
//     Node_SL *tmp = Lista1;
//     Node_SL *Lista2 = NULL;
//     while (tmp)
//     {
//         Lista2 = Insert_AtFront_SL(Lista2, tmp->key);
//         tmp = tmp->next;
//     }
//     return Lista2;
// }

// unsigned int Conta_OccorrenzeSL(Node_SL *head, int dato)
// {
//     Node_SL *tmp = head;
//     unsigned int cont = 1;
//     while (tmp->next)
//     {
//         if ((tmp->key) == dato)
//         {
//             cont++;
//         }
//         tmp = tmp->next;
//     }
//     return cont;
// }

// void Cerca_UltimoSL(Node_SL *head)
// {
//     Node_SL *p = head;
//     while (p->next)
//     {
//         p = p->next;
//     }
//     printf("L'ultimo elemento della lista è: %d\n", p->key);
// }

Node_SL *Insert_AtFront_SL(Node_SL *head, int data)
{
    Node_SL *tmp = NULL;
    tmp = New_Node_SL(data);
    if (tmp != NULL)
    {
        tmp->next = head;
        head = tmp;
    }
    return head;
}

Node_SL *Insert_AtBack_SL(Node_SL *head, int data)
{
    Node_SL *temp = NULL;
    Node_SL *prec = head;
    if (head == NULL)
    {
        head = Insert_AtFront_SL(head, data);
    }
    else
    {
        temp = New_Node_SL(data);
        while (prec->next)
        {
            prec = prec->next;
        }
        prec->next = temp;
    }
    return head;
}

Node_SL *Find_Predecessor_SL(Node_SL *head, int data)
{
    Node_SL *q = head;
    Node_SL *p = head;

    while (q != NULL && (q->key < data))
    {
        p = q;
        q = q->next;
    }
    return p;
}

Node_SL *Insert_InOrder_SL(Node_SL *head, int data)
{
    Node_SL *temp = NULL;
    Node_SL *prec = head;
    Node_SL *succ = head;
    if (succ == NULL || succ->key > data)
        head = Insert_AtFront_SL(head, data);
    else
    {
        prec = Find_Predecessor_SL(head, data);
        temp = New_Node_SL(data);
        succ = prec->next;
        temp->next = succ;
        prec->next = temp;
    }
    return head;
}

// int Is_Sorted_SL(Node_SL *head)
// {
//     int ordinata = 1;
//     Node_SL *tmp = head;
//     if (!head)
//         ordinata = 1;
//     else
//     {
//         while (tmp->next && ordinata == 1)
//         {
//             if (tmp->key > tmp->next->key)
//             {
//                 ordinata = 0;
//             }
//             tmp = tmp->next;
//         }
//     }
//     return ordinata;
// }

Node_SL *Find_Iterative_SL(Node_SL *head, int data)
{
    Node_SL *tmp =  NULL;
    if(head)
    {
        tmp = head;
        while (tmp->next && !(tmp->key == data))
        {
            tmp = tmp->next;
        }
    }
    return tmp;
}

Node_SL* Find_Recursive_SL(Node_SL * head, int data)
{
    Node_SL* tmp = NULL;
    if(head)
    {
        tmp  = head;
        if(!(tmp->key == data))
        {
            tmp = Find_Recursive_SL(tmp->next,data);
        }
    }
    return tmp;
}

int Exists_SL(Node_SL *head, int data)
{
    return (Find_Iterative_SL(head, data) != NULL);
}

Node_SL *Insert_AfterNode_SL(Node_SL *head, int predecessore, int data)
{
    Node_SL *temp = NULL;
    Node_SL *nuovo = NULL;
    temp = Find_Iterative_SL(head, predecessore);
    if (temp)
    {
        nuovo = New_Node_SL(data);
        nuovo->next = temp->next;
        temp->next = nuovo;
    }
    return head;
}

Node_SL *Free_SL(Node_SL *head)
{
    Node_SL *temp = head;
    while (head)
    {
        temp = head;
        head = temp->next;
        free(temp);
    }
    return head;
}

Node_SL *Remove_Node_SL(Node_SL *head, int data)
{
    Node_SL *prec = NULL;
    Node_SL *currPtr = head;
    Node_SL *tmp = NULL;
    while (currPtr != NULL && currPtr->key < data)
    {
        prec = currPtr;
        currPtr = currPtr->next;
    }
    if (currPtr)
    {
        tmp = currPtr;
        if (currPtr == head)
        {
            head = currPtr->next;
        }
        else
            prec->next = currPtr->next;
    }
    return head;
}

// unsigned int Somma_listaSL(Node_SL *head)
// {
//     Node_SL *temp = head;
//     unsigned int somma = 0;
//     while (temp != NULL)
//     {
//         somma = somma + temp->key;
//         temp = temp->next;
//     }
//     return somma;
// }

// unsigned int Prodotto_listaSL(Node_SL *head)
// {
//     Node_SL *temp = head;
//     unsigned int prodotto = 1;
//     while (temp != NULL)
//     {
//         prodotto = prodotto * temp->key;
//         temp = temp->next;
//     }
//     return prodotto;
// }

// float Media_listaSL(Node_SL *head)
// {
//     Node_SL *temp = head;
//     unsigned int cont = 0;
//     float media = 0;
//     float somma = 0;
//     while (temp != NULL)
//     {
//         cont++;
//         somma = somma + temp->key;
//         temp = temp->next;
//     }
//     if (cont > 0)
//     {
//         media = somma / cont;
//     }
//     return media;
// }

// unsigned int Length_SL(Node_SL *head)
// {
//     Node_SL *temp = head;
//     unsigned int cont = 0;
//     while (temp != NULL)
//     {
//         cont++;
//         temp = temp->next;
//     }
//     return cont;
// }

// unsigned int Norma_listaSL(Node_SL *head)
// {
//     Node_SL *temp = head;
//     unsigned int norma = 0;
//     unsigned int somma = 0;
//     while (temp != NULL)
//     {
//         somma = somma + (temp->key) * (temp->key);
//         temp = temp->next;
//     }
//     norma = sqrt(somma);
//     return norma;
// }

// unsigned int TrovaMinSL(Node_SL *head)
// {
//     Node_SL *temp = head;
//     unsigned int min = temp->key;
//     while (temp != NULL)
//     {
//         if (temp->key <= min)
//         {
//             min = temp->key;
//         }
//         temp = temp->next;
//     }
//     return min;
// }

// unsigned int TrovaMaxSL(Node_SL *head)
// {
//     Node_SL *temp = head;
//     unsigned int max = temp->key;
//     while (temp != NULL)
//     {
//         if (temp->key >= max)
//         {
//             max = temp->key;
//         }
//         temp = temp->next;
//     }
//     return max;
// }

// Node_SL *Unione_SL(Node_SL *Lista1, Node_SL *Lista2)
// {
//     Node_SL *tmp = Lista2;
//     Node_SL *search = NULL;
//     while (tmp)
//     {
//         search = Find_Iterative_SL(Lista1, tmp->key);
//         if (!search)
//         {
//             Lista1 = Insert_AtBack_SL(Lista1, tmp->key);
//         }
//         tmp = tmp->next;
//     }
//     return Lista1;
// }

// Node_SL *Complemento_SL(Node_SL *Lista1, Node_SL *Lista2)
// {
//     Node_SL *tmp = Lista1;
//     Node_SL *search = NULL;
//     while (tmp)
//     {
//         search = Find_Iterative_SL(Lista2, tmp->key);
//         if (search)
//         {
//             Lista1 = Remove_Node_SL(Lista1, tmp->key);
//         }
//         tmp = tmp->next;
//     }
//     return Lista1;
// }

// Node_SL *Duplicate_SL(Node_SL *Lista1, Node_SL *Lista2)
// {
//     Node_SL *tmp = Lista1;
//     while (tmp)
//     {
//         Lista2 = Insert_AtBack_SL(Lista2, tmp->key);
//         tmp = tmp->next;
//     }
//     return Lista2;
// }

// Node_SL *Merge_SL(Node_SL *Lista1, Node_SL *Lista2)
// {
//     Node_SL *tmp = Lista2;
//     while (tmp)
//     {
//         Lista1 = Insert_AtBack_SL(Lista1, tmp->key);
//         tmp = tmp->next;
//     }
//     return Lista1;
// }

// Node_SL *Sort_SL(Node_SL *head)
// {
//     Node_SL *tmp = head;
//     Node_SL *list_tmp = NULL;
//     if (head)
//     {
//         while (tmp)
//         {
//             list_tmp = Insert_InOrder_SL(list_tmp, tmp->key);
//             tmp = tmp->next;
//         }
//     }
//     return list_tmp;
// }

/* $$$$$$$\                      $$\       $$\            */
/* $$  __$$\                     $$ |      $$ |           */
/* $$ |  $$ | $$$$$$\  $$\   $$\ $$$$$$$\  $$ | $$$$$$\   */
/* $$ |  $$ |$$  __$$\ $$ |  $$ |$$  __$$\ $$ |$$  __$$\  */
/* $$ |  $$ |$$ /  $$ |$$ |  $$ |$$ |  $$ |$$ |$$$$$$$$ | */
/* $$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |$$   ____| */
/* $$$$$$$  |\$$$$$$  |\$$$$$$  |$$$$$$$  |$$ |\$$$$$$$\  */
/* \_______/  \______/  \______/ \_______/ \__| \_______| */
/*                                                        */
/*                                                        */
/*                                                        */
/* $$\       $$\           $$\                       $$\  */
/* $$ |      \__|          $$ |                      $$ | */
/* $$ |      $$\ $$$$$$$\  $$ |  $$\  $$$$$$\   $$$$$$$ | */
/* $$ |      $$ |$$  __$$\ $$ | $$  |$$  __$$\ $$  __$$ | */
/* $$ |      $$ |$$ |  $$ |$$$$$$  / $$$$$$$$ |$$ /  $$ | */
/* $$ |      $$ |$$ |  $$ |$$  _$$<  $$   ____|$$ |  $$ | */
/* $$$$$$$$\ $$ |$$ |  $$ |$$ | \$$\ \$$$$$$$\ \$$$$$$$ | */
/* \________|\__|\__|  \__|\__|  \__| \_______| \_______| */
/*                                                        */
/*                                                        */
/*                                                        */
/* $$\       $$\             $$\                          */
/* $$ |      \__|            $$ |                         */
/* $$ |      $$\  $$$$$$$\ $$$$$$\    $$$$$$$\            */
/* $$ |      $$ |$$  _____|\_$$  _|  $$  _____|           */
/* $$ |      $$ |\$$$$$$\    $$ |    \$$$$$$\             */
/* $$ |      $$ | \____$$\   $$ |$$\  \____$$\            */
/* $$$$$$$$\ $$ |$$$$$$$  |  \$$$$  |$$$$$$$  |           */
/* \________|\__|\_______/    \____/ \_______/            */

// unsigned int Conta_OccorrenzeDL(Node_DL *head, int dato)
// {
//     Node_DL *tmp = head;
//     unsigned int cont = 1;
//     while (tmp->next)
//     {
//         if ((tmp->key) == dato)
//         {
//             cont++;
//         }
//         tmp = tmp->next;
//     }
//     return cont;
// }

// void Stampa_InversaDL(Node_DL *head)
// {
//     Node_DL *tmp = head;
//     // Scorro la lista per arrivare all'ultimo nodo
//     while (tmp->next)
//     {
//         tmp = tmp->next;
//     }
//     // A partire dall'ultimo inizio a stampare i valori della lista e vado indietro
//     while (tmp)
//     {
//         printf("%d\t", tmp->key);
//         tmp = tmp->prev;
//     }
//     printf("\n");
// }

int Exists_DL(Node_DL *head, int dato)
{
    Node_DL *tmp = head;
    int trovato = 0;
    while (tmp && trovato == 0)
    {
        if (tmp->key == dato)
        {
            trovato = 1;
        }
        tmp = tmp->next;
    }
    return trovato;
}

Node_DL *Free_DL(Node_DL * head)
{
    Node_DL *temp = head;
    while (head)
    {
        temp = head;
        head = temp->next;
        free(temp);
    }
    return head;
}

// int Trova_MaxDL(Node_DL *head)
// {
//     Node_DL *tmp = head;
//     int max = tmp->key;
//     while (tmp)
//     {
//         if (tmp->key >= max)
//         {
//             max = tmp->key;
//         }
//         tmp = tmp->next;
//     }
//     return max;
// }

// int Trova_MinDL(Node_DL *head)
// {
//     Node_DL *tmp = head;
//     int min = tmp->key;
//     while (tmp)
//     {
//         if (tmp->key <= min)
//         {
//             min = tmp->key;
//         }
//         tmp = tmp->next;
//     }
//     return min;
// }

// float Media_listaDL(Node_DL *head)
// {
//     return (Somma_listaDL(head) / Lenght_DL(head));
// }

// unsigned int Somma_listaDL(Node_DL *head)
// {
//     Node_DL *tmp = head;
//     unsigned int Somma = 0;
//     while (tmp)
//     {
//         Somma = Somma + tmp->key;
//         tmp = tmp->next;
//     }
//     return Somma;
// }

// unsigned int Lenght_DL(Node_DL *head)
// {
//     Node_DL *tmp = head;
//     unsigned int cont = 0;
//     while (tmp)
//     {
//         cont++;
//         tmp = tmp->next;
//     }
//     return cont;
// }

int Empty_DL(Node_DL *head)
{
    return (head == NULL);
}

Node_DL *New_Node_DL(int data)
{
    Node_DL *tmp = malloc(sizeof(Node_DL));
    if (tmp)
    {
        tmp->key = data;
        tmp->next = NULL;
        tmp->prev = NULL;
    }
    return tmp;
}

Node_DL *Insert_AtFront_DL(Node_DL *head, int data)
{
    Node_DL *tmp = NULL;
    if (head == NULL)
    {
        tmp = New_Node_DL(data);
        if (tmp)
        {
            head = tmp;
        }
    }
    else
    {
        tmp = New_Node_DL(data);
        if (tmp)
        {
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
        }
    }
    return head;
}

Node_DL *Insert_AtBack_DL(Node_DL *head, int data)
{
    Node_DL *tmp = NULL;
    Node_DL *q = head;
    Node_DL *p;
    if (!head)
    {
        head = Insert_AtFront_DL(head, data);
    }
    else
    {
        tmp = New_Node_DL(data);
        while (q->next)
        {
            q = q->next;
        }
        q->next = tmp;
        tmp->prev = q;
    }
    return head;
}
void Display_DL(Node_DL *head)
{
    Node_DL *tmp = head;
    int i = 0;
    while (tmp)
    {
        printf("%d\t", tmp->key);
        tmp = tmp->next;
    }
    printf("\n");
}

Node_DL *Linear_Search_DL(Node_DL *head, int data)
{
    Node_DL *tmp = head;
    while (tmp && tmp->key != data)
    {
        tmp = tmp->next;
    }
    return tmp;
}

Node_DL *Insert_AfterNode_DL(Node_DL *head, int predecessore, int data)
{
    if (head)
    {
        Node_DL *tmp = NULL;
        Node_DL *new = NULL;
        tmp = Linear_Search_DL(head, predecessore);
        if (tmp)
        {
            new = New_Node_DL(data);
            new->next = tmp->next;
            new->prev = tmp;
            tmp->next = new;
            if (new->next != NULL)
            {
                new->next->prev = new;
            }
        }
    }
    return head;
}

// int Is_ListaDLOrdinata(Node_DL *head)
// {
//     int ordinata = 1;
//     Node_DL *tmp = head;
//     if (!head)
//     {
//         ordinata = 1;
//     }
//     else
//     {
//         while (tmp->next && ordinata == 1)
//         {
//             if (tmp->key > tmp->next->key)
//             {
//                 ordinata = 0;
//             }
//             tmp = tmp->next;
//         }
//     }
//     return ordinata;
// }

Node_DL *Insert_InOrder_DL(Node_DL *head, int data)
{
    Node_DL *new = NULL;
    if (!head)
    {
        head = Insert_AtFront_DL(head, data);
    }
    else
    {
        Node_DL *tmp = head;
        while (tmp && (tmp->key < data))
        {
            tmp = tmp->next;
        }
        new = New_Node_DL(data);
        new->next = tmp->next;
        new->prev = tmp;
        tmp->next = new;
        if (new->next)
        {
            new->next->prev = new;
        }
    }
    return head;
}

Node_DL *Remove_FromFront_DL(Node_DL *head)
{
    Node_DL *tmp = head;
    if (tmp)
    {
        if (tmp->next)
        {
            tmp->next->prev = head;
            head = tmp->next;
            free(tmp);
        }
        else
        {
            head = NULL;
        }
    }
    return head;
}

Node_DL *Remove_FromBack_DL(Node_DL *head)
{
    Node_DL *tmp = head;
    if (tmp)
    {
        while (tmp->next)
        {
            tmp = tmp->next;
        }
        if (tmp->prev)
        {
            tmp->prev->next = NULL;
        }
        free(tmp);
    }
    return head;
}

Node_DL *Remove_Node_DL(Node_DL *head, int data)
{
    Node_DL *tmp = NULL;
    if (head)
    {
        tmp = Linear_Search_DL(head, data);
        if (tmp)
        {
            if (tmp->next == NULL)
            {
                head = Remove_FromBack_DL(head);
            }
            else if (tmp->prev == NULL)
            {
                head = Remove_FromFront_DL(head);
            }

            else
            {
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                free(tmp);
            }
        }
    }
    return head;
}
