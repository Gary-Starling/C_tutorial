#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define _PRINT_OUT_ NO
#define _NO_ 0
#define _YES_ 1
#define N (102400U)     

// result on my PC Sorting time 7.3140 sec

void arr_print(int *arr, unsigned int len);

// sort example
//                ^
//            {4, 1, 8, 2, 9}}
//                     ^
//     i=1    {[1 ,4,] 8, 2, 9}
//                        ^
//     i=2    {[1, 4, 8,] 2, 9}
//                           ^
//     i=3    {[1, 2, 4, 8,] 9}
//                              end;
//     i=4    {[1, 2, 4, 8, 9]}
int main(int argc, char const *argv[])
{
    int arr[N];
    unsigned int len = (sizeof(arr) / sizeof(int));
    int tmp;
    double st, end;

    srand(time(NULL));

    /* fill array */
    for (unsigned int i = 0; i < len; i++)
        arr[i] = rand() % len;

#if _PRINT_OUT_ == _YES_
    printf("\nUnsorted\n");
    arr_print(arr, len);
#endif

    st = clock();

    for (unsigned int i = 1; i < len; i++)
    {
        for (unsigned int j = i; j != 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
            }
            else
                break;
        }
    }

    end = clock();

#if _PRINT_OUT_ == _YES_
    printf("\nSorted\n");
    arr_print(arr, len);
#endif

    printf("Sorting time %.4lf sec.\n", (double)((end - st) / CLK_TCK));

    return 0;
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
