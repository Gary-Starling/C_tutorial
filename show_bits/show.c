#include <stdio.h>

void bit_show(int n);

int main(int argc, char const *argv[])
{
    int num = 0;

    printf("Enter int\n");
    scanf("%d", &num);
    bit_show(num);
    return 0;
}

void bit_show(int n)
{
    for (int i = (sizeof(int) * 8) - 1; i >= 0; i--)
    {
        printf("%d", (n >> i) & 0x1);
        if ((i % 8) == 0)
            printf(" ");
    }
    printf("\n");
}
