/* Программа сложения двух чисел */

#include <stdio.h>

main() //Главное тело функции
{
	int slag1,slag2;
	
	printf("Vvedite 1 slagaemoe\n"); /*Подсказка*/
	scanf("%d",&slag1);			 	 /*Читаем первый операнд*/
	printf("Vvedite 2 slagaemoe\n"); /*Подсказка*/
	scanf("%d",&slag2);			     /*Читаем второй операнд*/
	printf("Summa slagaemih  = %d \n",slag1+slag2); /*Вывод результата*/
	
	return 0; /*Успешное завершение программы*/
	
	
}