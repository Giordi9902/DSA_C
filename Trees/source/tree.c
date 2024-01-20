#include "tree.h"

// Funzioni che visitano un albero applicando una funzione unaria
void InOrderVisit(const Nodo_T* root, void(*fun)(int))
{
    if(root)
    {
        InOrderVisit(root->left,fun);
        fun(root->key);
        InOrderVisit(root->right,fun);
    }
}

void PostOrderVisit(const Nodo_T* root, void (*fun)(int))
{
    if(root)
    {
        PostOrderVisit(root->left,fun);
        PostOrderVisit(root->right,fun);
        fun(root->key); 
    }
}

void PreOrderVisit(const Nodo_T* root, void (*fun)(int)){
    if(root)
    {
        fun(root->key);
        PreOrderVisit(root->left,fun);
        PreOrderVisit(root->right,fun);
    }
}
/*______________________________________________________________*/

// Funzioni unarie
void print(int key)
{  
  printf("%d \t",key); 
}

void isEven(int key)
{
    if(key%2 == 0)
        printf("%d è pari\n",key);
    else
        printf("%d è dispari\n");
}
void isLeaf(const Nodo_T* root)
{
    if(root->left == NULL && root->right==NULL)
    {
        printf("Il nodo con chiave %d è una foglia\n",root->key);
    }
}
/*______________________________________________________________*/

// Creazione nodo
Nodo_T* CreaNodo(int key)
{
    Nodo_T* newNode = malloc(sizeof(Nodo_T));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
/*______________________________________________________________*/

// Ricerca di un nodo
Nodo_T* Search (Nodo_T* root, int data)
{
    if(root)
    {
        if(root->key < data)
            return Search(root->right,data);
        else if(root->key > data)
            return Search(root->left,data);
        else
            return root;
    }
}

// Inserimento di un nodo
void Insert(Nodo_T** root, int data)
{
    if(*root == NULL)
    {
        Nodo_T* new = CreaNodo(data);
        *root = new;
    } 
    else if ((*root)->key < data)
        Insert(&(*root)->right, data);
    else
        Insert(&(*root)->left, data);
}