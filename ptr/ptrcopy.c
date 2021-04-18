#include <stdio.h>

#define SIZE 4

void copy1(char *s1, const char *s2);
void copy2(char *s1, const char *s2);

int main(void)
{
    char string1[20];
    char *string2 = "first str";

    char string3[20];
    char string4[] = "second str";

    copy1(string1, string2);

    printf("string1 = %s\n", string1);

    copy2(string3, string4);

    printf("string3 = %s\n", string3);
}

/* Копирование по индексу */
void copy1(char *s1, const char *s2)
{
    int t=0;

    for (size_t i = 0; s1[i] = s2[i]; i++)
        t++;
}

/* Копирование по арифметике указатлей */

void copy2(char *s1, const char *s2)
{
     int t=0;

    for (; *s1 = *s2; s1++, s2++)
        t++;
}
