/******************************************************************************
fibonacci
*******************************************************************************/
#include <stdio.h>
#include <time.h>

#define DUMP //NORMAL


#ifdef DUMP
int dump[100] = {0};
#endif

int fibonacci(int n);

int main()
{

  /* Recursion */
    for(int i = 1; i < 45; i += 1)  //overflow if i > 45
    {
     clock_t t1 = clock();
     printf("fibonacci(%d) = %d\n", i, fibonacci(i));
     clock_t t2 = clock();
     int d_sec = (t2 - t1)/CLOCKS_PER_SEC;
     printf("time = %d sec\n", d_sec);
    }
  /* Recursion */
    
  /* NO ! Recursion */
  /*
    int fib1 = 1, fib2 = 1, nextfib, input;
    
    printf("Enter number of fibonacci\n");
    
    scanf("%d", &input);
    
    while(input != 2)
    {
        nextfib = fib1 + fib2;
        fib1 = fib2;
        fib2 = nextfib;
        input--;
    }
    
    printf("fibonacci  = %d", fib2);
    */
  /* NO ! Recursion */
    
    
     
    

    return 0;
}

int fibonacci(int n)
{
#ifdef NORMAL

  if(n <= 1)
   return n;
   
  return fibonacci(n - 1) + fibonacci(n - 2);

#else

  if(n <= 1)
   return n;
  
 if(dump[n] == 0)
  dump[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return dump[n];

#endif

}
