/******************************************************************************
sort by counting
*******************************************************************************/
#include <stdio.h>

#define MAX_SIZE    20          //define max input

void print_arr(int *arr);
void print_sort_cnt(int *arr);

int main()
{
    int cnts[MAX_SIZE] = {0};   //init 0!
    int in;                     //for scanf
    
    
    /* input */
    for(int i = 0; i < MAX_SIZE; i++)
    {
     scanf("%d", &in);
     if(in > MAX_SIZE-1 || in < 0)
     {
      printf("pls enter digit > 0 and <%d\n", MAX_SIZE);
      if(i!=0)
       i--;
     }
     else
     {
      cnts[in]++;
     }
    }
    
    
    print_sort_cnt(cnts);

    return 0;
}

void print_arr(int *arr)
{
    for(int i = 0; i < MAX_SIZE; i++)
     printf("%d ", arr[i]);
     
    printf("\n"); 
}

void print_sort_cnt(int *arr)
{
    for(int i = 0; i < MAX_SIZE; i++)
    {
     for(int j = 0; j < arr[i]; j++)
      printf("%d ", i);
    }
     
    printf("\n"); 
}

