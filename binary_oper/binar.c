//бинарные операции
#include <stdio.h>

#define MASK 0x03 //маска 1го и 2го разрядов

#define BYTE_MASK 0xFF

unsigned int color = 0x002a162f;
unsigned char blue, green, red;

unsigned int dig = 2;

int main(int argc, char const *argv[])
{
    printf("source dig = 0x%x\n", dig);
    dig = ~dig;
    printf("inversion dig = 0x%x\n", dig);
    dig = dig & 0b010101;
    printf("dig & 0b010101 = 0x%x\n", dig);
    dig = dig | 0b101010;
    printf("dig | 0b101010 = 0x%x\n", dig);
    dig = dig ^ 0b101010;
    printf("dig ^ 0b101010 = 0x%x\n", dig);

    dig |= MASK; //установить 0 и 1 биты
    printf("dig & MASK = 0x%x\n", dig);

    dig &= MASK; //усечь всё, кроме 0 и 1 бита
    printf("dig & MASK = 0x%x\n", dig);

    dig = dig ^ (1 << 0); 
    printf("dig ^ (1 << 0) = 0x%x\n", dig);
        dig = dig ^ (1 << 1); 
    printf("dig ^ (1 << 1) = 0x%x\n", dig);
        dig = dig ^ (1 << 2); 
    printf("dig ^ (1 << 2) = 0x%x\n", dig);

    dig = 0x03;
    if ((dig & MASK) == MASK)
    {
        printf("dig == 0x02\n");
    }

    dig <<= 3;
    printf("%d\n", dig);

    red = color & BYTE_MASK;
    printf("color = %x\n", color);
    printf("red = %x\n", red);
    
    green = (color >> 8) & BYTE_MASK;
    printf("color >> 8 = %x\n", color >> 8);
    printf("green = %x\n", green);

    blue = (color >> 16) & BYTE_MASK;
    printf("color >> 16 = %x\n", color >> 16);
    printf("color = %x\n", blue);
    
    return 0;
}
