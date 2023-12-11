#include <stdio.h>
#include <math.h>

unsigned long long  factorial(unsigned long long  num);


int main(void)
{

   for( unsigned long long  i = 0; i <= 20; i++)
		printf(" factorial %2d!= %llu \n", i, factorial(i));
		
	return 0;
}


unsigned long long factorial(unsigned long long  num)
{
	
	if ( num <= 1 )
	 return 1;
	else 
	 return (num * factorial(num - 1));
	 
}
