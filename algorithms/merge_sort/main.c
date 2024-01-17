#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

#define _SIZE_IN (4)
#define _SIZE_OUT (4)
typedef int data;

#define _PRINT_OUT_ _YES_
#define _NO_ 0
#define _YES_ 1
// #define N (102400U)

data arrIn[_SIZE_IN];
data arrOut[_SIZE_IN];

void mergeSort(data *arrIn, data *arrOut, uint64_t start, uint64_t end);
void merge(data *arrIn, data *arrOut, uint64_t start, uint64_t end);
void arrPrint(data *arr, unsigned int len);

int main(int argc, char const *argv[])
{
    uint64_t len = (sizeof(arrIn) / sizeof(data));

    srand(time(NULL));

    // arrOut = (data *)malloc(sizeof(data) * _SIZE_OUT);

    for (uint64_t i = 0; i < len; i++)
        arrIn[i] = rand() % len;

#if _PRINT_OUT_ == _YES_
    printf("\nUnsorted\n");
    arrPrint(arrIn, len);
#endif

    if (arrOut == NULL)
    {
        printf("Memory allocation is failed\n");
        exit(EXIT_FAILURE);
    }

    assert(_SIZE_IN == _SIZE_OUT);
    mergeSort(arrIn, arrOut, 0, _SIZE_IN - 1);

#if _PRINT_OUT_ == _YES_
    printf("\nSorted\n");
    arrPrint(arrOut, len);
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
//                 ({4, 2}                  {1, 3} )    s = 0; e = 4; mid = 2
//          ({0 , 2})
//      (0)        (2)
void mergeSort(data *arrIn, data *arrOut, uint64_t start, uint64_t end)
{
    uint64_t mid = (start + end) / 2;

    printf("start = %d, end = %d\n", start, end);

    if ((end - start) < 1)
        return;

    mergeSort(&arrIn[start], &arrOut[start], start, mid); // left
    mergeSort(&arrIn[mid], &arrOut[mid], mid + 1, end);   // right // arrPrint(arrOut, _SIZE_IN)
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
    //TODO: error, swap array
    while ((l1 <= mid) && (l2 <= end)) // 1 3 0 3
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
