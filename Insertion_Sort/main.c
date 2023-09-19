/******************************************************************************
Insertion sort
*******************************************************************************/
#include <stdio.h>
#include <string.h> //for memset
#include <time.h>   //for time()
#include <stdlib.h> //rand

#define SIZE (11)

void count_sort(int *unsr_arr, int *sortd_arr);
void print_arr(int *arr);



int main()
{
    int in_cnts[SIZE];
    int sorted[SIZE];

    srand(time(NULL));
    memset(in_cnts, 0x00, sizeof(in_cnts));
    memset(sorted, 0x00, sizeof(sorted));

    printf("Enter %d diigts, >=[0] and <=[%d]\n", SIZE, SIZE - 1);

    for (unsigned int i = 0; i < SIZE; i++)
        in_cnts[i] = rand() % SIZE; // range

    printf("Unsorted\n");
    print_arr(in_cnts);

    count_sort(in_cnts, sorted);
    printf("Sorted\n");
    print_arr(sorted);

    return 0;
}

void count_sort(int *unsr_arr, int *sortd_arr)
{
    int insert_arr[SIZE] = {0};
    unsigned int pos = 0;

    /* Insertion sort */
    for (unsigned int indx = 0; indx < SIZE; indx++)
        insert_arr[unsr_arr[indx]]++;

    for (unsigned int i = 0; i < SIZE; i++)
    {
            for (unsigned int j = 0; j < insert_arr[i]; j++)
            {
                sortd_arr[pos] = i;
                pos++;
            }
    }
}

void print_arr(int *arr)
{
    for (unsigned int indx = 0; indx < SIZE; indx++)
        printf("%d ", arr[indx]);
    printf("\n");
}
