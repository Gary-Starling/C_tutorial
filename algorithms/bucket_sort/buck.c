#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef int data;

#define _PRINT_OUT_ _NO_
#define _NO_ 0
#define _YES_ 1
#define N (102400U)
#define MAX N
// RAND_MAX

void arrPrint(data *arr, unsigned int len);
data *initMemToBuckets(unsigned int max);
void bucketSort(data *arrIn, unsigned int dataLen);

int main(int argc, char const *argv[])
{
    data arrIn[N];
    long unsigned int test = 0;
    double st, end;
    long unsigned int len = (sizeof(arrIn) / sizeof(data));
    int msb;

    srand(time(NULL));

    for (unsigned int i = 0; i < len; i++)
    {
        msb = (rand()) << 15;
        arrIn[i] = msb | rand();
    }

#if _PRINT_OUT_ == _YES_
    printf("\nUnsorted\n");
    arrPrint(arrIn, len);
#endif

    st = clock();
    bucketSort(arrIn, len);
    end = clock();

#if _PRINT_OUT_ == _YES_
    printf("\nSorted\n");
    arrPrint(arrIn, len);
#endif

    for (unsigned int i = 1; i < len - 1; i++)
    {
        if (arrIn[i - 1] <= arrIn[i])
            test++;
    }

    if (test == len - 2)
        printf("Test ok\n");
    else
        printf("Test error\n");

    printf("Sorting time %.4lf sec.\n", (double)((end - st) / CLOCKS_PER_SEC));

    printf("For me .....%d %d %d %d %d %d\n", arrIn[N - 6], arrIn[N - 5], arrIn[N - 4], arrIn[N - 3], arrIn[N - 2], arrIn[N - 1]);

    return 0;
}

/**
 * @brief
 *
 * @param size
 * @param max
 * @return data**
 */
data *initMemToBuckets(unsigned int max)
{
    data *pBuckets = malloc(max * sizeof(data));

    if (pBuckets == NULL)
    {
        printf("Error memory alloc \n");
        exit(EXIT_FAILURE);
    }

    memset(pBuckets, 0, max * sizeof(data));

    return pBuckets;
}

/**
 * @brief Print all elements of array
 *
 * @param arr - pointer to array
 * @param len - length of array
 */
void arrPrint(data *arr, unsigned int len)
{
    if (arr == NULL)
    {
        printf("Error in print func(using null ptr)\n");
        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < len; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

/**
 * @brief
 *
 * @param arrIn
 * @param buckets
 */
void bucketSort(data *arrIn, unsigned int dataLen)
{
    data *buckets;
    data max = arrIn[0];

    /* get max value from input artray */
    for (size_t i = 1; i < dataLen - 1; i++)
    {
        if (arrIn[i] > max)
            max = arrIn[i];
    }

    buckets = initMemToBuckets(max + 1);

    for (size_t i = 0; i < dataLen; i++)
        buckets[arrIn[i]]++;

    for (size_t i = 0, j = 0; i <= max; i++)
    {
        while (buckets[i] > 0)
        {
            arrIn[j++] = i;
            buckets[i]--;
        }
    }

    free(buckets);
}
