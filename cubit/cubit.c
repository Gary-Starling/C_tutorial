#include <stdio.h>


int main()
{
    int i = 0;
    int cnt = 0;
    char str[15] = {0};


    fgets(str, 15, stdin);

    for (i = 0; i < 14; i++ )
    {
        if (str[i] == ' ')
        {
            printf("%d ", i);
            cnt++;
        }
    }
    

    if (cnt == 0)
    {
     printf("-");
    }


    return 0;
}
