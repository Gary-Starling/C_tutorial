#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSYMB 37

char symbText[MAXSYMB]  =     {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','0',' '};
/*                       a      b         c       d      e     f        g        h       i       j        k       l       m       n      o       p         q        r        s */
char* symbMorz[MAXSYMB] =  {".- ", "-... ", "-.-. ", "-.. ", ". ", "..-. ", "--. ", ".... ", ".. ", ".--- ", "-.- ", ".-.. ", "-- ", "-. ", "--- ", ".--. " , "--.- ", ".-. ", "... "
/*  t     u       v        w       x        y        z        1         2          3        4          5        6         7         8         9           0      space*/ 
, "- ", "..- ", "...- ", ".-- ", "-..- ", "-.-- ", "--.. ", ".----- ", "..--- ", "...--", "....- ", "..... ", "-.... ", "--... ", "---.. ", "----. ", "----- " , "-...- "};

int main(void)
{
    printf("Enter your text to convert Morze code\n");

    char *str = NULL, c;
    int len = 1;
    str = (char *)malloc(sizeof(char));
    while ((c = getchar()) != '\n')
    {
        c = tolower(c);
        str[len - 1] = c;
        len++;
        str = (char *)realloc(str, len);
    }
    str[len-1] = '\0'; 
    printf("%s (%d symbols)\n", str, len - 1);

    int i = 0;
    char *st_str;

    st_str = str;

    while (*str != '\0')
    {
        for (size_t j = 0; j < MAXSYMB; j++)
        {
            if (*str == symbText[j])
            {
                i++;
                printf("%s", symbMorz[j]);
                break; //symbol is found
            }
        }

        str++; //fix
    }

    free(st_str);

    return 0;
}
