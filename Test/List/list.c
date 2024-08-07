#include "./list.h"

void IsEmptyList_SL(int* loctest, int* testerr, Node_SL* head, int check)
{
    ++(*loctest);
    int tst = Empty_SL(head);
    printf("Test %d: Checking if the list is empty. The list is %s : %s\n",*loctest,Empty_SL(head)?"empty":"not empty",(tst = (tst==check))?"Correct!":"Error!");
    *testerr += (1-(unsigned int)tst);
}

void IsEmptyList_DL(int* loctest, int* testerr, Node_DL* head, int check)
{
    ++(*loctest);
    int tst = Empty_DL(head);
    printf("Test %d: Checking if the list is empty. The list is %s : %s\n",*loctest,Empty_DL(head)?"empty":"not empty",(tst = (tst==check))?"Correct!":"Error!");
    *testerr += (1-tst);
}

void IsPresent_SL(int* loctest,  int* testerr, Node_SL* head, int* element, int check)
{
    ++(*loctest);
    int tst = Exists_SL(head,element);
    printf("Test %d: Checking if the element is in the list. The element is %s : %s\n",*loctest,Exists_SL(head,element)?"present":"not present",(tst = (tst == check))?"Correct!":"Error!");
    *testerr += (1-tst);

}

void IsPresent_DL( int* loctest,  int* testerr, Node_DL* head, int* element, int check)
{
    ++(*loctest);
    int tst = Exists_DL(head,element);
    printf("Test %d: Checking if the element is in the list. The element is %s : %s\n",*loctest,Exists_SL(head,element)?"present":"not present",(tst = (tst == check))?"Correct!":"Error!");
    *testerr += (1-tst);
}