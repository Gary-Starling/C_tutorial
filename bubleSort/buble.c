#include <stdio.h>
#include <stdlib.h>


#define SIZE    49
#define VALUE   20 /* заполняемое значение для rand */

void mean(int mass[],int numElem);
void mode(int freq[], int rezult[]);

int main(void)
{
    int array[SIZE] = {0};
    int freq[SIZE] = {0};

    srand(time(0));

    printf("Not sort\n");

    for (size_t i = 0; i < (sizeof(array) / sizeof(int)); i++)
    {
        /* Заполним массив случайными числами */
        array[i] = rand() % VALUE;
        printf("a[%d] = %4d   ", i, array[i]);

        if ((i % 5 == 0) && (i != 0))
            printf("\n");
    }

    printf("\nSort mass..\n");

    int temp; //переменная захвата
    /* Проходы по массиву*/
    for (size_t d = 0; d <= ((sizeof(array) / sizeof(int)) - 1); d++)
    {

        for (size_t j = 0; j <= ((sizeof(array) / sizeof(int)) - 2); j++) //Это один проход
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j + 1];     //сохраним переменную
                array[j + 1] = array[j]; //сделали перестановку
                array[j] = temp;         //спустили меньшее вниз
                                         /* Тааким образом 1 3 2 .. 1 2 3 */
            }
        }
    }

    for (size_t f = 0; f < (sizeof(array) / sizeof(int)); f++)
    {
        /*сортированнный массив */
        printf("a[%d] = %4d   ", f, array[f]);

        if ((f % 5 == 0) && (f != 0))
            printf("\n");
    }

    mean(array,sizeof(array) / sizeof(int));
    mode(freq,array);
    

}


void mean(int mass[], int numElem)
{
    float total;

    printf("\n");

      for (size_t f = 0; f < numElem; f++)
    {
        total += mass[f];
    }

    total = total/numElem;

    printf("the mean of mass = %f \n", total);


}


void mode(int freq[], int rezult[])
{
   printf("\n%s\n%s\n%s\n","*********","  MODE","*********");


   for (size_t i = 0; i < SIZE - 1; i++)
   {
       /* Посчитали статистику */
       ++freq[rezult[i]];
   }

   printf("%s%11s%19s\n\n",
   "Mass", "freq", "Histog");

   for (size_t rating = 0; rating < VALUE; rating++)
   {
       printf("%8d%11d          ", rating, freq[rating]);
       /* code */
   }
   
   

}