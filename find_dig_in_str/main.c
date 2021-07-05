#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    
    int size = 1;
    char ch = 0;
    char *str = NULL; 
    int x = 0;
    int i = 0;
    int fl = 0;
    int temp = 0;
    int pos = 0;

    str = (char*) malloc(size * sizeof(char));
   
    while((ch = getchar())!= '\n')
    {
        str[size - 1] = ch;
        size++;
        str = (char *) realloc (str, size * sizeof(char));
    }
    
    scanf("%d", &x);
    
    for (i = 0 ; i < size; ++i) {
        
         if(isdigit(str[i]) || str[i]=='-')
         {
            
          sscanf(&str[i], "%d", &temp);
          
          while(isdigit(str[i]) || str[i]=='-')
           str++;
           
          if(x == temp)
          {
            fl = 1;
            printf("%d ", pos);
          }
           
         pos++;

         }
    }
    
    if (!fl)
     printf("Отсутствует\n");
     
    return 0;
}


