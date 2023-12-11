/******************************************************************************
Sieve of Eratosthenes
*******************************************************************************/
#include <stdio.h>

#define SIZE 100

void print_array_full(int *arr);
void print_array_simple(int *arr);

int main(void)
{
  int digits[SIZE] = {0};

  for (int i = 0; i < SIZE; i++)
    digits[i] = i;

  print_array_full(digits);

  for (int i = 2; i * i < SIZE; i++)
  {
    if (digits[i] != 0)
    {
      for (int j = i * i; j < SIZE; j += i)
        digits[j] = 0;
    }
  }

  print_array_simple(digits);

  return 0;
}

void print_array_full(int *arr)
{

  for (int i = 1; i < SIZE; i++)
  {
    printf("%5d", arr[i]);
    if (i % 10 == 0)
      printf("\n");
  }
  printf("\n");
  printf("\n");
  printf("\n");
}

void print_array_simple(int *arr)
{
  for (int i = 1; i < SIZE; i++)
  {
    if (arr[i] != 0)
      printf("%5d", arr[i]);
    if (i % 10 == 0)
      printf("\n");
  }
  printf("\n");
  printf("\n");
  printf("\n");
}
