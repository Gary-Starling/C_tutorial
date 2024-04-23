#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int data;

#define _PRINT_OUT_ _NO_
#define _NO_ 0
#define _YES_ 1
#define N (102400U)

//result on my PC Sorting time 0.0456 sec
//TODO graph results

void arr_to_max_heap(data *arr, unsigned int size, unsigned int i);
void swap(data *a, data *b);
void heap_sort(data *arr, unsigned int size);
void arr_print(data *arr, unsigned int len);

int main(int argc, char const *argv[])
{
    data arrIn[N];
    double st, end;
    unsigned int len = (sizeof(arrIn) / sizeof(data));
    long unsigned int test = 0;

    srand(time(NULL));

    for (unsigned int i = 0; i < len; i++)
        arrIn[i] = rand() % len;

#if _PRINT_OUT_ == _YES_
    printf("\nUnsorted\n");
    arr_print(arrIn, len);
#endif

    st = clock();
    heap_sort(arrIn, len);
    end = clock();

#if _PRINT_OUT_ == _YES_
    printf("\nSorted\n");
    arr_print(arrIn, len);

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

    return 0;
}
/**
 * @brief function heap sorting
 *
 * @param arr - pointer to array
 * @param size - size of array
 */
void heap_sort(data *arr, unsigned int size)
{
    // Build heap
    for (int i = size / 2 - 1; i >= 0; i--)
        arr_to_max_heap(arr, size, i);

    // Sort
    for (int i = size - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);     // swap max and last elements
        arr_to_max_heap(arr, i, 0); // refresh heap
    }
}

/**
 * @brief Convert array to max-heap
 *
 * @param arr - pointer to array
 * @param size - size of array
 * @param i - root
 */
void arr_to_max_heap(data *arr, unsigned int size, unsigned int i)
{
    unsigned int left, right, par;

    while (i < size / 2)
    {
        par = i;
        left = (par * 2) + 1;
        right = (par * 2) + 2;

        if (left < size && arr[left] > arr[par])
            par = left;

        if (right < size && arr[right] > arr[par])
            par = right;

        if (par != i)
        {
            swap(&arr[i], &arr[par]);
            i = par;
        }
        else
            break;
    }
}

/**
 * @brief swap two elements
 *
 * @param a - pointer to left value
 * @param b - pointer to right value
 */
void swap(data *a, data *b)
{
    int temp = *a;

    if ((a == NULL) || (b == NULL))
    {
        printf("Error in swap func(using null ptr)\n");
        exit(EXIT_FAILURE);
    }

    *a = *b;
    *b = temp;
}

/**
 * @brief Print all elements of array
 *
 * @param arr - pointer to array
 * @param len - length of array
 */
void arr_print(data *arr, unsigned int len)
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