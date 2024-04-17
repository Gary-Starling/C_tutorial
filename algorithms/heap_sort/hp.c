#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define _PRINT_OUT_ _NO_
#define _NO_ 0
#define _YES_ 1
#define N (102400U)

int glob_arr[] = {9,11,16,10,6,5,2,1,8,4};

void arr_max_heap(int *arr, unsigned int size, unsigned int i);
void swap(int *a, int *b);
void heap_sort(int *arr, unsigned int size);
void arr_print(int *arr, unsigned int len);

// for()
//     //step1 int arr[] = {4,10,3,5,1}; i=0
//     if(4 < 10)//*
//         swap(4, 10)
//     if(4 < 3)
//         swap(4, 3)
//     else next
//         //step2 int arr[5] = {10,4,3,5,1}; i=1
//         if(4 < 3)
//             swap(4, 3)
//         if(4 < 5)//*
//             swap(4,5)
//         else next
//             //step3 int arr[5] = {10,5,3,4,1}; i=3

//         swap(arr[0], arr[n-1])

int main(int argc, char const *argv[])
{
    double st, end;
    unsigned int len = (sizeof(glob_arr) / sizeof(int));
    unsigned int j = 0;

    arr_print(glob_arr, len);

    // Построение кучи (перегруппируем массив)
    for (int i = len/2 - 1; i >= 0 ; i--)
        arr_max_heap(glob_arr, len, i);

    arr_print(glob_arr, len);

    // // Один за другим извлекаем элементы из кучи
    // for (int i = len - 1; i >= 0; i--)
    // {
    //     // Перемещаем текущий корень в конец
    //     swap(&arr[0], &arr[i]);

    //     // вызываем процедуру heapify на уменьшенной куче
    //     arr_max_heap(arr, i, 0);
    // }

    // arr_print(arr, len);

    return 0;
}

/**
 * @brief
 *
 * @param arr
 * @param size
 */
void heap_sort(int *arr, unsigned int size)
{
    for (unsigned int i = (size / 2) - 1; i >= 0; i--)
    {
        arr_max_heap(arr, i, 0);
        swap(&arr[0], &arr[size - i]);
    }
}

/**
 * @brief
 *
 * @param arr
 * @param size
 * @param i
 */
void arr_max_heap(int *arr, unsigned int size, unsigned int i)
{
    unsigned int left, right, parent;

    parent = i;
    left = (i * 2) + 1;
    right = (i * 2) + 2;

    if (left < size && arr[left] > arr[parent])
        parent = left;

    if (right < size && arr[right] > arr[parent])
        parent = right;

    if (parent != i)
    {
        swap(&arr[i], &arr[parent]);
        arr_max_heap(arr, size, parent);
    }
}

/**
 * @brief
 *
 * @param a
 * @param b
 */
void swap(int *a, int *b)
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
void arr_print(int *arr, unsigned int len)
{
    for (unsigned int i = 0; i < len; i++)
        printf("%d ", arr[i]);

    printf("\n");
}