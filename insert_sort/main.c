/******************************************************************************
sort by inserts
*******************************************************************************/
#include <stdio.h>

#define MAX_SIZE    10

void print_arr(int *arr);
void insert_sort(int *arr);


int main()
{
    int array[MAX_SIZE];
    
    printf("Sort by inserts, pls enter %d digits\n", MAX_SIZE);
    
    for(int i = 0; i < MAX_SIZE; i++)
     scanf("%d", &array[i]);
     
    print_arr(array);
    insert_sort(array);
    print_arr(array);
    
    
    return 0;
}


/* print all array */
void print_arr(int *arr)
{
    for(int i = 0; i < MAX_SIZE; i++)
     printf("%d ", arr[i]);
     
    printf("\n"); 
}

void insert_sort(int *arr)
{
  for(int i = 1; i < MAX_SIZE; i++)
   {
    int j = i;   
    while(j > 0 && arr[j-1] > arr[j])
    {
     int tmp;
     tmp = arr[j-1];
     arr[j-1] = arr[j];
     arr[j] = tmp;
     j--;
    }
   } 
}


