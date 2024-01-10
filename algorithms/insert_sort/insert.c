#include <stdio.h>

void arr_print(int *arr, unsigned int len);

int arr[] = {4, 1, 8, 2, 9, 7, 2, 12};
// sort
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
    int tmp;

    arr_print(arr,  sizeof(arr) / sizeof(arr[0]));

    for (unsigned int i = 1; i < sizeof(arr) / sizeof(arr[0]); i++)
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

     arr_print(arr,  sizeof(arr) / sizeof(arr[0]));

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
