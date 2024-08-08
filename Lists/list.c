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
    Node_SL *tmp = head;
    while (tmp)
    {
        printf("%d\t", tmp->key);
        tmp = tmp->next;
    }
    printf("\n");
}

void Recursive_Display_SL(Node_SL* head)
{
    Node_SL* tmp = NULL;
    if(head)
    {
        tmp = head;
        printf("%d\t",tmp->key);
        Recursive_Display_SL(tmp->next);
    }
}
int Empty_SL(Node_SL* head)
{
    return (head == NULL);
}

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
    Node_SL* tmp = head;
    Node_SL* predecessor =  NULL;
    while(tmp && (tmp->key < data))
    {
        predecessor = tmp;
        tmp =  tmp->next;
    }
    return predecessor;
}

Node_SL *Insert_InOrder_SL(Node_SL *head, int data)
{
    Node_SL *temp = NULL;
    Node_SL *prec = head;
    Node_SL *succ = head;
    if (head == NULL || head->key > data)
    {
        head = Insert_AtFront_SL(head, data);
    }
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

int Is_Sorted_SL(Node_SL *head)
{
    int ordinata = 1;
    Node_SL *tmp = head;
    if (!head)
        ordinata = 1;
    else
    {
        while (tmp->next && ordinata == 1)
        {
            if (tmp->key > tmp->next->key)
            {
                ordinata = 0;
            }
            tmp = tmp->next;
        }
    }
    return ordinata;
}

Node_SL *Find_Iterative_SL(Node_SL *head, int data)
{
    Node_SL *tmp = head;
    int found = 0;
    while (tmp && !found)
    {
        if(tmp->key == data)
        {
            found++;
        }
        else
        {
            tmp =  tmp->next;
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

Node_SL* Remove_FromFront_SL (Node_SL* head)
{
    if(head)
    {
        Node_SL* tmp = head;
        head = tmp->next;
        free(tmp);
    }
    return head;
}

Node_SL *Remove_Node_Recursive_SL(Node_SL *head, int data)
{
    if(head != NULL)
    {
        if(head->key == data)
        {
            //clearprintf("Key's at front, calling Remove from Front. Key to remove =  %d\n",head->key);
            head  = Remove_FromFront_SL(head);
        }
        else
        {

            head->next = Remove_Node_Recursive_SL(head->next,data);
        }
    }
    return head;
}

Node_SL * Remove_Node_Iterative_SL(Node_SL* head, int data)
{
    Node_SL* predecessor = head;
    Node_SL* current = head;
    if(head)
    {
        predecessor = Find_Predecessor_SL(head,data);
        //printf("Predecessor key : %d \n",predecessor->key);
        current = predecessor->next;
        predecessor->next = current->next;
        free(current);
    }
    return head;
}