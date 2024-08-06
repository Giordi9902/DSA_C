#ifndef LIST_H
#define LIST_H
#include<stdio.h>
#include<stdlib.h>

typedef struct Node_SL
{
    int key;
    struct Node_SL *next;
}Node_SL;

typedef struct Node_DL
{
    int key;
    struct Node_DL *prev;
    struct Node_DL *next;
}Node_DL;


Node_SL *Create_Node_SL(int );

Node_SL *Insert_AtFront_SL(Node_SL *, int );
Node_SL *Insert_AtBack_SL(Node_SL *, int );
Node_SL *Insert_InOrder_SL(Node_SL *, int );
Node_SL *Insert_AfterNode_SL(Node_SL *, int , int );

Node_SL *Remove_FromFront_SL(Node_SL *);
Node_SL *Remove_FromBack_SL(Node_SL *);
Node_SL *Remove_Node_SL(Node_SL *, int );

Node_SL *Revert_SL(Node_SL *);
Node_SL *Sort_SL(Node_SL *);
Node_SL *Merge_SL(Node_SL *, Node_SL *);
Node_SL *Duplicate_SL(Node_SL *, Node_SL *);
Node_SL *Unione_SL(Node_SL *, Node_SL *);
Node_SL *Libera_ListaSL(Node_SL *);

Node_SL *Cerca_PredecessoreSL(Node_SL *, int );
Node_SL *Cerca_ElementoSL(Node_SL *, int );



Node_SL *Complemento_SL(Node_SL *, Node_SL *);

void Display_SL(Node_SL *);
void Cerca_UltimoSL(Node_SL *);
float Media_listaSL(Node_SL *);

unsigned int Length_SL(Node_SL *);
unsigned int Norma_listaSL(Node_SL *);
unsigned int TrovaMinSL(Node_SL *);
unsigned int TrovaMaxSL(Node_SL *);
unsigned int Conta_OccorrenzeSL(Node_SL *, int );
unsigned int Somma_listaSL(Node_SL *);
unsigned int Prodotto_listaSL(Node_SL *);

int Exists_SL(Node_SL *, int );
int Is_Sorted_SL(Node_SL *);


Node_DL *Create_Node_DL(int);

Node_DL *InsertAtFront_DL(Node_DL *, int );
Node_DL *InsertAtBack_DL(Node_DL *, int );
Node_DL *Insert_InOrder_DL(Node_DL *, int );
Node_DL *Insert_AfterNode_DL(Node_DL *, int , int );

Node_DL *Remove_FromFront_DL(Node_DL *);
Node_DL *Remove_FromBack_DL(Node_DL *);
Node_DL *Remove_Node_DL(Node_DL *, int );

Node_DL *Linear_Search_DL(Node_DL *, int );

unsigned int Conta_OccorrenzeDL(Node_DL *, int );
unsigned int Somma_listaDL(Node_DL *);
unsigned int Lenght_DL(Node_DL *);

float Media_listaDL(Node_DL *);

int Trova_MaxDL(Node_DL *);

int Trova_MinDL(Node_DL *);

int Is_ListaDLOrdinata(Node_DL *);

int Is_EmptyDL(Node_DL *);

int Is_PresenteDL(Node_DL *, int );

void Stampa_InversaDL(Node_DL *);

void Stampa_ListaDL(Node_DL *);

#endif