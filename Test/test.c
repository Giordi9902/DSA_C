#include "test.h"

void print_int(const void* elem)
{
    printf("%d", *(int*)elem);
}

void print_float(const void* elem)
{
    printf("%.2f", *(float*)elem);
}

void print_string(const void* elem)
{
    printf("%s", *(char**)elem);
}

void array_test()
{

}

void lists_test()
{
    int loctest = 0 ;
    int loctesterr = 0;
    Node_SL*  head =  NULL;
    IsEmptyList_SL(&loctest,&loctesterr,head,1);
    head = Insert_AtFront_SL(head,5);
    IsEmptyList_SL(&loctest,&loctesterr,head,0);
    IsPresent_SL(&loctest,&loctesterr,head,5,1);
    printf("\nTest completed...[%d errors / %d tests]\n\n",loctesterr,loctest);
}