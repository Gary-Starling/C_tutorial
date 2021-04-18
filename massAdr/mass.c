#include <stdio.h>

int main(void)
{
	char mass[10] = {0}; //Массив из 10 ячеек
	char * p_mass;
	
	for(int i = 0; i < (sizeof(mass)/sizeof(char)); i++)
	 mass[i] = i + 1;
	 
	 printf("sizeof mass = %d\n",sizeof(mass)/sizeof(char));
	
	for(int i = 0; i < (sizeof(mass)/sizeof(char)); i++)
	 printf("mass[%d] = %d \n",i,mass[i]);

	printf("adress 1-st element mass %p like mass \n",mass);
	printf("adress 1-st element mass %p like &mass[0] \n",&mass[0]);

	p_mass = mass;

	printf("pointer to mass p_mass = mass  %p \n",p_mass);

	p_mass = &mass[0];

	printf("pointer to mass p_mass = &mass[0]  %p \n",p_mass);

	printf("address of p_mass =  %p \n", &p_mass );

	printf("value on p_mass =  %d \n", *p_mass );

	printf("value on p_mass + 1 =  %d \n", *p_mass + 1);

	printf("value on p_mass + 2 =  %d \n", *p_mass + 2);




}