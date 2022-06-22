/* pointer math */

#include <stdio.h>

#define SIZE 4

int main(void)
{
    int b[SIZE] = {10, 20, 30, 40};
    int *bPtr = b; 

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

    int mass[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char string[20] = "how are you?\n";
    int * p1_mass = &mass[1];
    int * p2_mass = &mass[7];
    
    char * p1_str = &string[3];
    char * p2_str = &string[12];
    
    printf("addr p2_int = %p\n", p2_mass);
    printf("addr p1_int = %p\n", p1_mass);
    printf("int = 4 => \n");
    printf("p2_int - p1_int = %ld\n", p2_mass - p1_mass);
    printf("addr p2_char = %p\n", p2_str);
    printf("addr p1_char = %p\n", p1_str);
    printf("char = 1 => \n");
    printf("p2_char - p1_char = %ld\n", p2_str - p1_str);
    return 0;
}