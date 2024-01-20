#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
int main()
{
    int n = 0;
    Nodo_T* root = NULL;
    printf("Inserisci il numero di nodi da inserire: ");
    scanf("%d",&n);
    for(int i = 0; i<n ; i++)
    {
        int key;
        printf("Inserisci la chiave del nodo %d: ",i);
        scanf("%d",&key);
        Insert(&root,key);
    }
    int scelta = 0;
    do{
        do{
            printf("In che modo vuoi stampare l'albero?\n");
            printf("1. Attraversamento in order\n");
            printf("2. Attraversamento pre order\n");
            printf("3. Attraversamento post order\n");
            printf("4. Esci dal menù\n");
            printf("Scelta = ");
            scanf("%d",&scelta);
            switch(scelta)
            {
                case 1:
                {
                    InOrderVisit(root,print);
                    printf("\n");
                    scelta = 0;
                    break;
                }
                case 2:
                {
                    PreOrderVisit(root,print);
                    printf("\n");
                    scelta = 0;
                    break;
                }
                case 3:
                {
                    PostOrderVisit(root,print);
                    printf("\n");
                    scelta = 0;
                    break;                    
                }
                default:
                {
                    printf("Arrivederci!\n");
                    break;
                }
            }
        }while(scelta< 1 || scelta > 4);
    }while(scelta != 4);
    return 0;
}