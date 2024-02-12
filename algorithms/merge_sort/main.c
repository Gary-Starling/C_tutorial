#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>

typedef int data;

#define _PRINT_OUT_ _NO_
#define _NO_ 0
#define _YES_ 1
#define N (102400U)

//result on my PC Sorting time 0.0160 sec

void mergeSort(data *arrIn, data *arrOut, unsigned int start, unsigned int end);
void merge(data *arrIn, data *arrOut, unsigned int start, unsigned int end);
void arrPrint(data *arr, unsigned int len);

int main(int argc, char const *argv[])
{
    data arrIn[N];
    data *arrOut = NULL;
    double st, end;
    unsigned int len = (sizeof(arrIn) / sizeof(data));

    srand(time(NULL));

    arrOut = (data *)malloc(sizeof(data) * N);

    for (unsigned int i = 0; i < len; i++)
        arrIn[i] = rand() % (len + 99);

#if _PRINT_OUT_ == _YES_
    printf("\nUnsorted\n");
    arrPrint(arrIn, len);
#endif

    if (arrOut == NULL)
    {
        printf("Memory allocation is failed\n");
        exit(EXIT_FAILURE);
    }

    st = clock();
    mergeSort(arrIn, arrOut, 0, N - 1);
    end = clock();

#if _PRINT_OUT_ == _YES_
    printf("\nSorted\n");
    arrPrint(arrOut, len);
#endif

    printf("Sorting time %.4lf sec.\n", (double)((end - st) / CLK_TCK));

    return 0;
}

/**
 * @brief
 *
 * @param arrIn
 * @param arrOut
 * @param start
 * @param end
 */
//                          {4, 2, 1, 3}
//                 ({4, 2}                  {1, 3} )
//              ({4}       {2})          {1}      {3})
//                      /
//                 ({2, 4})                 ({1,3})     //1,2,3,4
//                          {1, 2, 3, 4}
void mergeSort(data *arrIn, data *arrOut, unsigned int start, unsigned int end)
{
    unsigned int mid = (start + end) / 2;

    if ((end - start) < 1)
        return;

    mergeSort(arrIn, arrOut, start, mid);   // left
    mergeSort(arrIn, arrOut, mid + 1, end); // right
    merge(arrIn, arrOut, start, end);
}

/**
 * @brief
 *
 * @param arrIn
 * @param arrOut
 * @param start
 * @param end
 */
void merge(data *arrIn, data *arrOut, unsigned int start, unsigned int end)
{
    unsigned int l1, l2;                  // left index each part of array a1[0..2] mid a2[3..6]
    unsigned int mid = (start + end) / 2; // mid element(end of left array and start of right array)
    unsigned int i;                       // index of out array

    l1 = start;
    l2 = mid + 1;
    i = start;

    while ((l1 <= mid) && (l2 <= end))
    {
        if (arrIn[l1] <= arrIn[l2])
            arrOut[i++] = arrIn[l1++];
        else
            arrOut[i++] = arrIn[l2++];
    }

    while (l1 <= mid)
        arrOut[i++] = arrIn[l1++];

    while (l2 <= end)
        arrOut[i++] = arrIn[l2++];

    // copy res array to input arry
    i = start;
    while (i <= end)
    {
        arrIn[i] = arrOut[i];
        i++;
    }
}

/**
 * @brief Print all elements of array
 *
 * @param arr - pointer to array
 * @param len - length of array
 */
void arrPrint(int *arr, unsigned int len)
{
    for (unsigned int i = 0; i < len; i++)
        printf("%d ", arr[i]);

    printf("\n");
}
