#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define SIZE 70

void rabbit(int *pos);
void turtle(int *pos);

/* mass for print of trace */
char trace[4][SIZE];

int main(void)
{
    char finish = 0;     //flag of end
    int posittion_r = 0; //pos rabbit
    int posittion_t = 0; //pos turtl

    /* draw the sides */
    memset(&trace[0], 0x3D, sizeof(trace[0]));
    memset(&trace[3], 0x3D, sizeof(trace[3]));

    srand(time(NULL));

    printf(" TURTLE VS RABBIT!!! \n\n\
press ENTER-> to start...\n\n");

    while (getchar() == 0)
    {
    }

    printf("START!\n\n");

    Sleep(1000);

    while (!finish)
    {

        rabbit(&posittion_r);
        turtle(&posittion_t);

        if (posittion_r <= 0)
            posittion_r = 0;

        if (posittion_r >= (SIZE - 1))
        {
            posittion_r = (SIZE - 1);
            finish = 1;
        }

        if (posittion_t <= 0)
            posittion_t = 0;

        if (posittion_t >= (SIZE - 1))
        {
            posittion_t = (SIZE - 1);
            finish = 1;
        }

        if(posittion_t == posittion_r)
        {
            printf("\n *AAAUUUCH!* \n");
        }

        memset(&trace[1], ' ', sizeof(trace[3])); //fill road space
        memset(&trace[2], ' ', sizeof(trace[2]));
        trace[1][posittion_r] = 0x52;             //fill point rab
        trace[2][posittion_t] = 0x54;             // -.- turt

        for (size_t j = 0; j < 4; j++)
        {
            for (size_t i = 0; i < SIZE; i++)
            {
                printf("%c", trace[j][i]);
            }
            printf("\n");
        }

        Sleep(500);
    }

    if (posittion_t > posittion_r)
    {
        printf("\nTURTLE WIN!!!\n");
    }
    else if (posittion_t < posittion_r)
    {
        printf("\nRABBIT WIN!!!\n");
    }
    else
    {
        printf("\nDEAD HEAT!!!\n");
    }

    printf("\n\n\
press ENTER-> to end...\n\n");

    while (getchar() == 0)
        ;
}

void turtle(int *pos)
{

    switch ((1 + rand() % 10))
    {
    case 6:
    case 7:
        *pos -= 6;
        break;

    case 8:
    case 9:
    case 10:
        *pos += 1;
        break;

    default:
        *pos += 3;
    }
}

void rabbit(int *pos)
{
    switch ((1 + rand() % 10))
    {

    case 1:
    case 2:
        break;

    case 3:
    case 4:
        *pos += 9;
        break;

    case 5:
        *pos -= 12;
        break;

    case 6:
    case 7:
    case 8:
        *pos += 1;
        break;

    default:
        *pos -= 2;
    }
}