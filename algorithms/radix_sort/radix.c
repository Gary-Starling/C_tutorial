#include <stdio.h>

int arr_in[7] = {10, 202, 3, 235, 7, 9, 12};
int arr_out[7] = {0};

void print_arr(int *arr, unsigned int size);
int get_max(int * arr, unsigned int size);

int main(int argc, char const *argv[])
{
    print_arr(arr_in, 7);
    print_arr(arr_out, 7);
    printf("%d\n", get_max(arr_in, 7));
    return 0;
}

int get_max(int * arr, unsigned int size)
{
    int max = arr[0];

    for (unsigned int indx = 0; indx < size; indx++)
        if(max < arr[indx]) max = arr[indx];
    
    return max;
}

void print_arr(int *arr, unsigned int size)
{
    for (unsigned int indx = 0; indx < size; indx++)
        printf("%d ", arr[indx]);
    printf("\n");
}

void radix_sort(int* arr, unsigned int size)
{
    int max = get_max(arr, size);
    unsigned int place;             //how many dig in max

    while(max) {
        place++;
        max /= 10;
    }

    for (unsigned int i = 1; i < place; i++)
    {
       //for(unsigned int j = 0; j < )
    }
    
}