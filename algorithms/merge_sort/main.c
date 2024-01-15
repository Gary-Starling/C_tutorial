#include <stdio.h>

// SIZE
typedef int data;
// data[SIZE]

void mergeSort(data *arr, unsigned int start, unsigned int end);

int arr[64];
int arr1[6] = {0, 1, 2, 3, 4, 5};
//                          arr, 0, 5
//            arr, 0, 2     --            arr, 2, 5
//   arr, 0, 1  -- arr, 1, 2    arr, 2, 2 --  arr 2, 5
//

int main(int argc, char const *argv[])
{
    return 0;
}

/**
 * @brief function of merge sorting
 *
 * @param arr - pointer to array
 * @param start - indx start of array
 * @param end - indx end of array
 */
void mergeSort(data *arr, unsigned int start, unsigned int end)
{
    int arrNew = NULL; // for merge two part
    unsigned int mid = (start + end) / 2;

    if( ) return;

    mergeSort(&arr[start], start, mid); // left
    mergeSort(&arr[mid], mid + 1, end); // right 
}

void merge(data *l, data *r, data *_new)
{
    // assert
}