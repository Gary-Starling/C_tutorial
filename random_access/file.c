#include <stdio.h>

struct clientData
{
    int accNum;
    char lastName[15];
    char firstName[15];
    float balance;
};

int main(int argc, char const *argv[])
{
    struct clientData Blank = {0, "", "", 0.0};
    FILE *cfPtr;

    if ((cfPtr = fopen("blank.dat", "w")) == NULL)
        printf("File not opened \n");
    else
    {

        for (size_t i = 0; i < 100; i++)
        {
            if (fwrite(&Blank, sizeof(struct clientData), 1, cfPtr) == 1)
                printf(" ok ");
        }

        fclose(cfPtr);
        printf("\n");
    }

    if ((cfPtr = fopen("blank.dat", "r+")) == NULL)
        printf("File not opened \n");
    else
    {
        printf("Enter account number"
               "1 to 100, 0 to end input\n?");
        scanf("%d", &Blank.accNum);

        while (Blank.accNum != 0)
        {
            printf("Enter lastname, firstname, balance\n? ");
            scanf("%s%s%f", Blank.lastName, Blank.firstName, &Blank.balance);
            fseek(cfPtr, (Blank.accNum - 1) * sizeof(struct clientData), SEEK_SET);
            printf("Enter account number\n");
            fwrite(&Blank, sizeof(struct clientData), 1, cfPtr);
            scanf("%d", &Blank.accNum);
        }
    }

    fseek(cfPtr, 0, SEEK_SET); //start

    for (size_t i = 0; i < 100; i++)
        fread(&Blank, sizeof(struct clientData), 1, cfPtr);

    fclose(cfPtr);

    return 0;
}
