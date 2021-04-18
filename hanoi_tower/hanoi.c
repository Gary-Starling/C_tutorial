#include <stdio.h>

void print_n(int n, int dl);
void hanoi(int n, int i ,int k);

int main(void){

//Число ступеней башни	
int st; 	
	
printf("vvedite visotu bashni \r\n");

//
scanf("%d", &st);

for(int i=1; i<=st; i++)
 {
	print_n(i, st);
 }
 
 hanoi(st, 1, 2);

return 0;	
}


/*Печатает n - раз  dl длина строки*/
void print_n(int n, int dl)
{
	
			
	for(int j = 0; j < dl - n; j++) 
	 printf(" ");
	
	for(int i = 0; i < n; i++)
	{		
	 printf("[]");
	}
	 
	 printf("\r\n");
}


void hanoi(int n, int i ,int k)
{
	if(n == 1)
	 printf("Dvigaem disk 1 iz palku %d na %d. \n",i, k);
	else
	{
		int tmp = 6 - i -k;
		
		hanoi(n-1, i, tmp);
		
		printf("Dvigaem disk %d iz palku %d na %d. \n",n, i, k);
		
		hanoi(n-1, tmp, k);
	}
}
