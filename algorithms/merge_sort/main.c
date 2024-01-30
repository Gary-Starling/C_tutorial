#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

#define _SIZE_IN (100)
#define _SIZE_OUT (100)
typedef int data;

#define _PRINT_OUT_ _YES_
#define _NO_ 0
#define _YES_ 1
// #define N (102400U)

data ArrIn[_SIZE_IN] = {3, 2, 8, 1};
data ArrOut[_SIZE_IN];

void mergeSort(data *arrIn, data *arrOut, uint64_t start, uint64_t end);
void merge(data *arrIn, data *arrOut, uint64_t start, uint64_t end);
void arrPrint(data *arr, unsigned int len);

int main(int argc, char const *argv[])
{
    uint64_t len = (sizeof(ArrIn) / sizeof(data));

    srand(time(NULL));

    // arrOut = (data *)malloc(sizeof(data) * _SIZE_OUT);

    for (uint64_t i = 0; i < len; i++)
        ArrIn[i] = rand() % (len + 99);

#if _PRINT_OUT_ == _YES_
    printf("\nUnsorted\n");
    arrPrint(ArrIn, len);
#endif

    // if (arrOut == NULL)
    // {
    //     printf("Memory allocation is failed\n");
    //     exit(EXIT_FAILURE);
    // }

    assert(_SIZE_IN == _SIZE_OUT);
    mergeSort(ArrIn, ArrOut, 0, _SIZE_IN - 1);

#if _PRINT_OUT_ == _YES_
    printf("\nSorted\n");
    arrPrint(ArrOut, len);
#endif

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
void mergeSort(data *arrIn, data *arrOut, uint64_t start, uint64_t end)
{
    uint64_t mid = (start + end) / 2;

    if ((end - start) < 1) return;

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
void merge(data *arrIn, data *arrOut, uint64_t start, uint64_t end)
{
    uint64_t l1, l2;                  // left index each part of array a1[0..2] mid a2[3..6]
    uint64_t mid = (start + end) / 2; // mid element(end of left array and start of right array)
    uint64_t i;                       // index of out array

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
