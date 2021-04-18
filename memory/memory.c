#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

char dest[10] = {};
char src[] = "Hello";

char str[] = "Sweet home Alabama";
char str2[] = "ABCDEFG";

int main(void)
{
    void *res;
    /* copy from src to dst */
    res = memcpy(dest, src, sizeof(src));

    /* res is ptr fo reult operation memcpy */
    if (res != NULL)
        printf("%s", res);



    printf("\r\nthe string \'str\' before memmove is : %s", str);
    memmove(str, &str[6], 5);
    printf("\r\nthe string \'str\' after memmove is : %s", str);

    printf("\r\nthe string \'str2\' before memset is : %s", str2);
    memset(str2, 'a', 3);
    printf("\r\nthe string \'str2\' before memset is : %s", str2);

    /*exercises*/
    


    return 0;
}
