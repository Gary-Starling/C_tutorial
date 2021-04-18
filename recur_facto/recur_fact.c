#include <stdio.h>
#include <math.h>


long factorial(long num);



int main(void)
{

   for( int i = 0; i <= 20; i++)
		printf(" factorial %2d!= %ld \n", i, factorial(i));
		//printf("test");
		
	return 0;
}



/* Функция вычисления факториала */
long factorial(long num)
{
	
	if ( num <= 1 )
	 return 1;
	else 
	 return (num * factorial(num - 1));
	 
}
