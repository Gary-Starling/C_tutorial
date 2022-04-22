//бинарные операции
#include <stdio.h>

#define MASK 0x03 //маска 1го и 2го разрядов

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
    printf("dig ^ (1 < 0) = 0x%x\n", dig);
        dig = dig ^ (1 << 1); 
    printf("dig ^ (1 < 1) = 0x%x\n", dig);
        dig = dig ^ (1 << 2); 
    printf("dig ^ (1 < 2) = 0x%x\n", dig);
    
    return 0;
}
