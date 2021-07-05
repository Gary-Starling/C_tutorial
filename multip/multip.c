#include <stdio.h>

int multiple(int num);
int mystery(unsigned bits);

int main(int argc, char const *argv[])
{
    int y;
    unsigned x;

    printf("Enter value between 1 and 32000\n");
    scanf("%d", &y);

    if (multiple(y))
        printf("%d is mult of 1024\n", y);
    else
        printf("%d is not mult of 1024\n", y);

    printf("Enter unsigned var\n");
    scanf("%u", &x);

    if (mystery(x))
        printf("multiples bits on %d \n", x);
    else
        printf("NOTmultiples bits on %d \n", x);

    return 0;
}

int multiple(int num)
{
    int i, mask = 1, mult = 1;

    for (i = 0; i < 10; i++, mask <<= 1)
    {
        if ((num & mask) != 0)
        {
            mult = 0;
            break;
        }
    }

    return mult;
}

int mystery(unsigned bits)
{
    unsigned i, mask = 1 << 15, total = 0;

    for (i = 0; i <= 16; i++, bits <<= 1)
    {
        if ((bits & mask) == mask)
            ++total;
    }

    return total % 2 == 0 ? 1 : 0;
}