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

Nodo_T* SearchMin(Nodo_T* root)
{
    Nodo_T* tmp = root;
    if(root)
    {
        Nodo_T* min = SearchMin(root->left);
        if(min)
        {
            tmp = min;
        }
    }
    return tmp;
}

Nodo_T* SearchMax(Nodo_T* root)
{
    Nodo_T* tmp = root;
    if(root)
    {
        Nodo_T* max = SearchMax(root->right);
        if(max)
        {
            tmp = max;
        }
    }
    return tmp;
}

Nodo_T* SearchSuccessore(Nodo_T* root, int data)
{
    if(root)
    {
        Nodo_T* tmp = root;
        if(root->key <= data)
            return SearchSuccessore(root->right,data);
        else
        {
            tmp = SearchSuccessore(root->left,data);
            if(!tmp)
                return root;
            else
                return tmp;
        }
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

// Cancellazione di un nodo
Nodo_T* Cancella(Nodo_T* root, int data)
{
    if(root)
    {
        if(root->key < data)
        {
            root->left = Cancella(root->left,data);
        }
        else if (root->ley > data)
        {
            root->right = Cancella(root->right,data);
        }
        else
        {
            root = CancellaRadice(root);
        }
    }
    return root;
}

Nodo_T* CancellaRadice(Nodo_T* root)
{
    Nodo_T* tmp;
    if(root)
    {
        if(root->right != NULL && root->right != NULL)
        {
            tmp = StaccaMinimo(root->right,root);
            root->key = tmp;
        }
        else
        {
            tmp = root;
            if (root->right != NULL)
            {
                root = root->right;
            }
            else{
                root = root->left;
            }
            free(tmp);
        }
    }
    return root;
}

unsigned int StaccaMinimo(Nodo_T* root, Nodo_T* padre)
{
    if(root)
    {
        if(root->left)
            return StaccaMinimo(root->left, root);
        else
        {
            int tmp = root->key;
            if(padre->left == root)
                padre->left = root->right;
            else
                padre->right = root->right;
        }
    }
    return tmp;
}

void BFS(const Nodo_T* root, void(*fun)(int))
{
    Queue *Q = CreaCoda(Q);
    Q = Enqueue(Q,root->key);
    while(!(CodaVuota(Q)))
    {
        Nodo_T* tmp = root;
        int key = Head(Q);
        fun(key);
        Q = Enqueue(Q,tmp->left);
        Q = Enqueue(Q,tmp->right);
        Q = Dequeue(Q);
    }
}