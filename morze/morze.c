#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(void)
{
    printf( "Enter your text to convert Morze code\n");

    char *str = NULL, c;
    int len = 1;
    str = (char*) malloc(sizeof(char));
    while((c = getchar()) != '\n') {
        str[len - 1] = c;
        len++;
        str = (char*) realloc(str, len);
    }
    str[len - 1] = '\0';
    printf("%s (%d symbols)\n", str, len - 1);
    free(str);


    return 0;
}
