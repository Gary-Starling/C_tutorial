#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>

#define _PRINT_OUT_ _NO_
#define _NO_ 0
#define _YES_ 1
#define N (102400U)

int minf(int *a, unsigned int offset, unsigned int len);
void arr_print(int *arr, unsigned int len);

int main(void)
{
    int arr[N];
    unsigned int len = (sizeof(arr) / sizeof(int));
    unsigned int tmp;
    int indx;
    double st, end;

    srand(time(NULL));

    /* fill array */
    for (unsigned int i = 0; i < len; i++)
        arr[i] = rand() % len;

    printf("\nUnsorted\n");
#if _PRINT_OUT_ == _YES_
    arr_print(arr, len);
#endif
    st = clock();

    for (unsigned int i = 0; i < len; i++)
    {
        indx = minf(arr, i, len);

        if (indx > 0)
        {
            tmp = arr[i];
            arr[i] = arr[indx];
            arr[indx] = tmp;
        }
    }

    end = clock();
    printf("\nSorted\n");
#if _PRINT_OUT_ == _YES_
    arr_print(arr, len);
#endif

    printf("Sorting time %.4lf sec.\n", (double)((end - st) / CLK_TCK));

    return 0;
}

/**
 * @brief The function is finding minimal element in linear array and return index of element in case success
 *
 * @param a - pointer to array
 * @param offset - offset in array
 * @param len - length of array
 * @return int - return index in array or -1 if didn't find minimal element
 */
int minf(int *a, unsigned int offset, unsigned int len)
{
    int min;
    int indx = -1;

    if (len == 0)
        return -1;

    min = a[offset];

    for (unsigned int i = offset; i < len; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            indx = i; // mark index
        }
    }

    return indx; // if indx == -1, no minimum
}

/**
 * @brief Print all elements of array
 *
 * @param arr - pointer to array
 * @param len - length of array
 */
void arr_print(int *arr, unsigned int len)
{
    for (unsigned int i = 0; i < len; i++)
        printf("%d ", arr[i]);

    printf("\n");
}