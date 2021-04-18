#include <stdio.h>

#define SIZE 4

int main(void)
{
    int b[SIZE] = {10, 20, 30, 40};
    int *bPtr = b; /*Присваиваем начальный адрес массива b*/

    printf("array b printed for index: \n");

    for (size_t i = 0; i < SIZE; i++)
        printf("b[%d] = %d\n", i, b[i]);

    printf("array b printed for offset: \n");

    for (size_t i = 0; i < SIZE; i++)
        printf("b*(b+%d) = %d\n", i, *(b + i));

    printf("array b printed for pointer index: \n");

    for (size_t i = 0; i < SIZE; i++)
        printf("bPtr[%d] = %d\n", i, bPtr[i]);

    printf("array b printed for pointer + offset: \n");

    for (size_t i = 0; i < SIZE; i++)
        printf("bPtr+%d = %d\n", i, *(bPtr+i));
}