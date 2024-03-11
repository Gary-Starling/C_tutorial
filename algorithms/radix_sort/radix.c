#include <stdio.h>
#include <stdlib.h>

int arr_in[7] = {10, 202, 3, 235, 7, 9, 12};
int arr_out[7] = {0};

// decimal
#define _SYST (10)

void print_arr(int *arr, unsigned int size);
int get_max(int *arr, unsigned int size);
void count_sort(int *arr, int *buff, unsigned int size, unsigned int place);
void radix_sort(int *arr, unsigned int size);

int main(int argc, char const *argv[])
{
    print_arr(arr_in, 7);
    printf("%d\n", get_max(arr_in, 7));
    radix_sort(arr_in, 7);
    return 0;
}

int get_max(int *arr, unsigned int size)
{
    int max = arr[0];

    for (unsigned int indx = 0; indx < size; indx++)
        if (max < arr[indx])
            max = arr[indx];

    return max;
}

void print_arr(int *arr, unsigned int size)
{
    for (unsigned int indx = 0; indx < size; indx++)
        printf("%d ", arr[indx]);
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
    //int *buff = malloc(size * sizeof(unsigned int)); // buffer for data recovery after one sorting pass

    // if (buff == NULL)
    // {
    //     printf("memory allocated error\n");
    //     exit(1);
    // }

    // numbers of iterations
    // for example max = 123; place = 1 -> 12[3]; place = 10 -> 1[2]3 ....
    for (unsigned int place = 1; (max / place) > 0; place *= 10)
        count_sort(arr, arr_out, size, place);
}

void count_sort(int *arr, int *buff, unsigned int size, unsigned int place)
{
    // place here sorting

    unsigned int count[_SYST] = {0}; // decimal(0-9)
    // int max = (arr[0]/place) % 10;

    for (unsigned int i = 0; i < size; i++)
        count[(arr[i] / place) % 10]++;

    for (unsigned int i = 0; i < _SYST; i++)
    {
        for (unsigned int j = 0; j < count[i]; j++)
            printf("%d ", i);

        printf("\n");
    }
    
    // for (unsigned int i = 0; i < size; i++)
    // {
    //     buff[ count[(arr[i] / place) % 10] ] = arr[i];
    //     count[(arr[i] / place) % 10]--;
    // }
}