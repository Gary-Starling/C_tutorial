/* write file */
<<<<<<< HEAD

#include <stdio.h>
#include <errno.h>


int main()
{
=======
#include <stdio.h>
int main()
{
    char *filename = "clients.dat";
>>>>>>> df35165bcf714dc4c2b32537fbbc89349fedbe07
    int account;
    char name[30];
    float balance;
    FILE *cfPtr;

<<<<<<< HEAD
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

=======
    /* Создадим или допишем в файл */
    if ((cfPtr = fopen(filename, "a+")) == NULL)
        printf("%s not open\n", filename);
    else
    {
        printf("Enter id, name, balance.\n");
        printf("Enter EOF(ctrl+z) to end input\n");
        printf("=>id___name___balance\n=>");
        scanf("%d%s%f", &account, name, &balance);
        while (!feof(stdin))
        {
            fprintf(cfPtr, "%d %s %.2f\n", account, name, balance);
            printf("=> ");
            scanf("%d%s%f", &account, name, &balance);
        }

        fclose(cfPtr);
        printf("write client.dat file ok\n");
    }

    /* Откроем файл*/
    if ((cfPtr = fopen("clients.dat", "r")) == NULL)
        printf("%s not open\n", filename);
    else
    {
        printf("%-10s %-15s %s\n", "ID", "NAME", "BALANCE");
        fscanf(cfPtr, "%d%s%f", &account, name, &balance);

        while (!feof(cfPtr))
        {
            printf("%-10d %-15s %7.2f$\n", account, name, balance);
            fscanf(cfPtr, "%d%s%f", &account, name, &balance);
        }
        fclose(cfPtr);
    }

    /* Снова откроем файл*/
    if ((cfPtr = fopen("clients.dat", "r")) == NULL)
        printf("%s not open\n", filename);
    else
    {
        printf("Enter request\n"
               "1 - list zero balance\n"
               "2 - list credit balance\n"
               "3 - list debit balance\n"
               "4 - Exit\n");

        int request;

        scanf("%d", &request);

        while (request != 4)
        {
            fscanf(cfPtr, "%d%s%f", &account, name, &balance);

            switch (request)
            {
            case 1:
                printf("ZERO BALANCE:\n");
                while (!feof(cfPtr))
                {
                    if (balance == 0)
                        printf("%-10d %-15s %7.2f$\n", account, name, balance);
                    fscanf(cfPtr, "%d%s%f", &account, name, &balance);
                }
                break;

            case 2:
                printf("CREDIT BALANCE:\n");
                while (!feof(cfPtr))
                {
                    if (balance < 0)
                        printf("%-10d %-15s %7.2f$\n", account, name, balance);
                    fscanf(cfPtr, "%d%s%f", &account, name, &balance);
                }
                break;

            case 3:
                printf("DEBIT BALANE:\n");
                while (!feof(cfPtr))
                {
                    if (balance > 0)
                        printf("%-10d %-15s %7.2f$\n", account, name, balance);
                    fscanf(cfPtr, "%d%s%f", &account, name, &balance);
                }
                break;
            }

            rewind(cfPtr);
            printf("new search ?\n");
            scanf("%d", &request);
        }

        printf("End\n");
        fclose(cfPtr);
>>>>>>> df35165bcf714dc4c2b32537fbbc89349fedbe07
    }

    return 0;
}