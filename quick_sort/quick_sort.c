#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 10
int a[SIZE]; //n - количество элементов

void quick_sort(int *s_arr, int start, int end);

int main(void)
{

    srand(time(NULL));

    printf("\n\r Not sort mass : \r\n");

    for (size_t i = 0; i < SIZE; i++)
    {
        a[i] = rand() % 100;
        printf(" %d ", a[i]);

        if ((i != 0) && (i % 20 == 0))
            printf("\n");
    }

    quick_sort(a, 0, SIZE - 1);

    printf("\n\r Sort mass : \r\n");

    for (size_t i = 0; i < SIZE; i++)
        printf(" %d ", a[i]);

    return 0;
}

void quick_sort(int *s_arr, int start, int end)
{

    if (start >= end)
     return;

    int left = start;
    int right = end;

    int mid = s_arr[(left + end) / 2];

    while (left <= right)
    {
        while (s_arr[left] < mid)
            left++;

        while (s_arr[right] > mid)
            right--;

        if (left <= right)
        {
            int tmp = s_arr[left];
            s_arr[left] = s_arr[right];
            s_arr[right] = tmp;
            left++;
            right--;
        }
    }
    /* left >= right; s_arr now like a s_arr1 = {0 ... right} and s_arr2 = { left...end} */

    quick_sort(s_arr, start, right ); //rec s_arr1 like s_arr1.1 and s_arr1.2
    quick_sort(s_arr, left, end ); //rec s_arr2 like s_arr2.1 and s_arr2.2
}