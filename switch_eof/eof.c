#include <stdio.h>


int main()
{
	char symb;
	
	printf("Enter the symb A/B/C/D/E/F \n\r");
	printf("Enter EOF to the end program\n\r");
	
	while( ( symb = getchar() ) != EOF )
	{
		switch(symb)
		{
			case 'A': case 'a':
			printf("A\r\n\r\n");
			break;
			
			case 'B': case 'b':
			printf("B\r\n\r\n");
			break;
			
			case 'C': case 'c':
			printf("C\r\n\r\n");
			break;
			
			case 'D': case 'd':
			printf("D\r\n");
			break;
			
			case 'E': case 'e':
			printf("E\r\n\r\n");
			break;
			
			case 'F': case 'f':
			printf("F\r\n\r\n");
			break;
			
			case '\n': case ' ':
			break;
			
			default:
			printf("Incorrect input\r\n\r\n");
			break;
			
		}
	}
	
	printf("End program\r\n");
	return 0;
}