#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	int dig = 0;
	srand(time(NULL));
	//i = rand();
	
	printf(" prees Enter \r\n");
	//printf ( "The time %u", time(NULL));
	
	while( getchar() != EOF )
	{
		
   
    for( int i = 0; i<100; i++)
	{
		dig = rand()%100;
	
		printf(" %5d" ,dig);
		
		if(i%5 == 0)
			printf("\n");
	}
	
	printf(" prees Enter \r\n");
	
	}
	
	return 0;
}