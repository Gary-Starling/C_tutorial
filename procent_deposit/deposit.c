#include <stdio.h>
#include <math.h>


int main()
{
	float sum_end_yr = 0.0, start_cap = 1000.0, percent = 0.05;
	
	unsigned int cnt_year = 10; //Кроичество лет
	
	
	printf("%4s%21s\r\n", "Year", "On deposit");//Нарисуем заголовок
	
	
	for (unsigned int year = 1; year <= cnt_year; year++)
	{
		sum_end_yr = start_cap * pow(( 1.0 + percent ),year); 
		printf("%4d%21.2f\r\n", year, sum_end_yr);
	}
	
	return 0; //sucsess
}