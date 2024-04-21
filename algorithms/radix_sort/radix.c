#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// decimal
#define _SYST (10)
#define _PRINT_OUT_ _YES_
#define _NO_ 0
#define _YES_ 1
#define N (512)
//Sorting time 0.0080 sec.

int get_max(int *arr, unsigned int size);
void sort(int *arr, int *buff, unsigned int size, unsigned int place);
void radix_sort(int *arr, unsigned int size);
void arr_print(int *arr, unsigned int len);

int arr_in[N];

int main(int argc, char const *argv[])
{

    double st, end;
    unsigned int len = (sizeof(arr_in) / sizeof(int));

    srand(time(NULL));

    /* fill array */
    for (unsigned int i = 0; i < len; i++)
        arr_in[i] = rand() % len;

#if _PRINT_OUT_ == _YES_
    printf("\nUnsorted\n");
    arr_print(arr_in, len);
#endif

    st = clock();
    radix_sort(arr_in, len);
    end = clock();

#if _PRINT_OUT_ == _YES_
    printf("\nSorted\n");
    arr_print(arr_in, len);
#endif

    printf("Sorting time %.4lf sec.\n", (double)((end - st) / CLOCKS_PER_SEC));

    return 0;
}

int get_max(int *arr, unsigned int size)
{
    int max = arr[0];

    for (unsigned int indx = 0; indx < size; indx++)
    {
        if (max < arr[indx])
            max = arr[indx];
    }
    return max;
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

void radix_sort(int *arr, unsigned int size)
{
    if (arr == NULL)
    {
        printf("radix_sort -> Null pointer\n");
        exit(1);
    }

    int max = get_max(arr, size);                    // get maximum from array
    int *buff = malloc(size * sizeof(unsigned int)); // buffer for data recovery after one sorting pass

    if (buff == NULL)
    {
        printf("memory allocated error\n");
        exit(1);
    }

    // numbers of iterations
    // for example max = 123; place = 1 -> 12[3]; place = 10 -> 1[2]3 ....
    for (unsigned int place = 1; (max / place) > 0; place *= 10)
        sort(arr, buff, size, place);

    free(buff);
}

void sort(int *arr, int *buff, unsigned int size, unsigned int place)
{
    unsigned int count[_SYST] = {0}; // decimal(0-9)
    unsigned int n;
    int i;

    // count sort
    for (i = 0; i < size; i++)
        count[(arr[i] / place) % 10]++;

    // calculate real number in output array
    for (unsigned int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // out array
    for (i = size - 1; i >= 0; i--)
    {
        n = (arr[i] / place) % 10;
        buff[count[n] - 1] = arr[i];
        count[n]--;
    }

    // copy to arr
    for (i = 0; i < size; i++)
        arr[i] = buff[i];
}