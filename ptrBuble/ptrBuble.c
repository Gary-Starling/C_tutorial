#include <stdio.h>
#include <stdlib.h>

/* Сортировка с указателем на функцию*/

#define SIZE 20
#define VALUE 100 /* заполняемое значение для rand */

int sort_up(int a, int b);
int sort_down(int a, int b);
void buble(int *array, int (*compare)(int a, int b), int size);
void swap(int *elmnt1, int *elmnt2);
void print_sort(int size, int *array);

void func1(void);
void func2(void);
void func3(void);



int main(void)
{

    void (*fprint[3]) (void)= {func1, func2, func3};

    int array[SIZE] = {0};
    char symb;
    int regim = -1;

    srand(time(NULL));

    printf("Not sort\n");

    for (size_t i = 0; i < (sizeof(array) / sizeof(int)); i++)
    {
        /* Заполним массив случайными числами */
        array[i] = rand() % VALUE;
        printf("a[%d] = %4d   ", i, array[i]);

        if ((i % 5 == 0) && (i != 0))
            printf("\n");
    }
    printf("\n");

    printf("enter \"U\" if you need sort UP\n\
or enter \"D\", if need sort DOWN\n\
enter key....\n\n");

    symb = getchar();

    printf("\n");

    if (symb == 'U' || symb == 'u')
    {
        regim = 0;
        (*fprint[regim])();
    }
    else if (symb == 'D' || symb == 'd')
    {
        regim = 1;
        (*fprint[regim])();
    }
    else
    {
        regim = 2;
        (*fprint[regim])();
    }

    switch (regim)
    {

    case 0:
        buble(array, sort_up, SIZE);
        print_sort(SIZE, array);
        break;

    case 1:
        buble(array, sort_down, SIZE);
        print_sort(SIZE, array);
        break;

    default:
        printf("nithing to do.");
        break;
    }

    return 0;
}

void buble(int *array, int (*compare)(int a, int b), int size)
{
    for (size_t d = 0; d <= (size - 1); d++)
    {

        for (size_t j = 0; j <= (size - 2); j++) //Это один проход
        {
            if ((*compare)(array[j], array[j + 1]))
                swap(&array[j], &array[j + 1]);
        }
    }
}

int sort_up(int a, int b)
{
    if (b < a)
        return 1;
    else
        return 0;
}

int sort_down(int a, int b)
{
    if (a < b)
        return 1;
    else
        return 0;
}

void swap(int *elmnt1, int *elmnt2)
{
    int temp; //Промежуточная переменная для хранения

    temp = *elmnt1;
    *elmnt1 = *elmnt2;
    *elmnt2 = temp;
}

void print_sort(int size, int *array)
{
    for (size_t f = 0; f < size; f++)
    {
        /*сортированнный массив */
        printf("a[%d] = %4d   ", f, array[f]);

        if ((f % 5 == 0) && (f != 0))
            printf("\n");
    }
}

void func1(void)
{
    printf("sorted UP\n");
}

void func2(void)
{
    printf("sorted DOWN\n");
}

void func3(void)
{
    printf("nothing to do\n");
}
