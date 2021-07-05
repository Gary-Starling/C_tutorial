/* write file */

#include <stdio.h>
#include <errno.h>


int main()
{
    int account;
    char name[30];
    float balance;
    FILE *cfPtr;

    if( (cfPtr = fopen("file.txt","w")) == NULL)
    {
         printf("Error %d \n", errno);
         printf("file not open\n");
    }
        
    else
    {
        printf("Enter acc, name, balance.\n");
        printf("Enter OF to end input.\n");
        printf("=>  ");
        scanf("%d%s%f", &account, name, &balance);

        while(!feof(stdin)) 
        {
            fprintf(cfPtr, "%d %s %.2f\n", account, name, balance);
            printf("=> ");

         scanf("%d%s%f", &account, name, &balance);
        }
        
        fclose(cfPtr);

    }

    return 0;
}