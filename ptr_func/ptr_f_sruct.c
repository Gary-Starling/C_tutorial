#include <stdio.h>
#include <ctype.h>

char big_text1[] = "HELLO, THIS IS BIG DATA, PLS MAKE ME SMALLER";
char big_text2[] = "PAM PAPAM PAPAPAPAPAM";

typedef struct coord
{
    float x;
    float y;
} COORDINAT;

COORDINAT object1 = {60.3, 50.1};
COORDINAT object2;
COORDINAT *ptr_obj = NULL;

/*function set coordinats*/
void set_coord(COORDINAT *obj, float setX, float setY);
/* pointer for fucntion type set_coord */
void (*pf)(COORDINAT *obj, float x, float y);

/*function make smaller string and put them on stdout */
void show_string(void (*ptr_f)(char *data), char *string);
/*ptr fo this*/
//typedef тип_возвращаемого_значения (*имя_указ)(список_параметров_функции);
typedef void (*PTR_F)(char *data);
PTR_F ptr_f;

void ToLower(char *str);
void ToBigger(char *str);

int main(int argc, char const *argv[])
{
    object2 = object1;
    printf("PART1\n");
    printf("Coordinats object1 x = %f, y = %f\n", object1.x, object1.y);
    printf("Coordinats object2 equal 1 x = %f, y = %f\n", object2.x, object1.y);
    ptr_obj = &object2;
    printf("ptr_obj x = %f like (*ptr_obj).x)\n", (*ptr_obj).x);
    printf("ptr_obj x = %f like ptr_obj->x\n", ptr_obj->x);
    set_coord(&object2, 10.0, 20.5);
    printf("Coordinats object2 x = %f, y = %f\n", object2.x, object2.y);
    pf = set_coord;
    pf(&object1, 11.3, 12.4);
    printf("New valude Coordinats object1 x = %f, y = %f\n", object1.x, object1.y);
    printf("=========================\n");
    printf("\n");
    printf("PART2\n");
    printf("source data = %s\n", big_text1);
    ptr_f = ToBigger;
    show_string(ToLower, big_text1);
    show_string(ptr_f, big_text1);

    ptr_f = ToLower;
    printf("%s\n", big_text2);
    (*ptr_f)(big_text2);
    printf("%s\n", big_text2);
    return 0;
}

void set_coord(COORDINAT *obj, float setX, float setY)
{
    obj->x = setX;
    (*obj).y = setY;
}

void show_string(void (*ptr_f)(char *data), char *string)
{
    (*ptr_f)(string);
    puts(string);
}

void ToLower(char *str)
{
    while (*str != '\0')
    {
        *str = (char)tolower(*str);
        str++;
    }
}

void ToBigger(char *str)
{
    while (*str != '\0')
    {
        *str = (char)toupper(*str);
        str++;
    }
}