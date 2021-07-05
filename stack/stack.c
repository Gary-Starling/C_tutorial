#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int data;
    struct Stack *nextptr;
};

typedef struct Stack STACKNODE;

int push(STACKNODE **topPtr, int info);
int pop(STACKNODE **topPtr);
void print_stack(STACKNODE *topPtr);

int main(int argc, char const *argv[])
{
    STACKNODE *StacktPtr = NULL;

    printf("add item : %d to stack\n", push(&StacktPtr, 10));
    printf("add item : %d to stack\n", push(&StacktPtr, 22));
    printf("add item : %d to stack\n", push(&StacktPtr, 31));
    printf("add item : %d to stack\n", push(&StacktPtr, 6));
    printf("add item : %d to stack\n", push(&StacktPtr, 18));
    printf("add item : %d to stack\n", push(&StacktPtr, 98));
    printf("delete item %d: in stack\n", pop(&StacktPtr));
    printf("delete item %d: in stack\n", pop(&StacktPtr));
    print_stack(StacktPtr);
    //Доделать pop
    return 0;
}

void print_stack(STACKNODE *topPtr)
{
    while (topPtr != NULL)
    {
        printf("data -> %d\n", topPtr->data);
        topPtr = topPtr->nextptr;
    }
}

/* Если сделать просто *, а не ** то стек изменится только локально
внутри функции, а не глобально, сели допустим нам надо
передать в функию y f(&y) f(int *y). Мы изменим значение глобально
но если в функцию нужно передать структуру struct op{ int a, op * next }
нам нужно использовать двойной указатель, т.к нужно изменить значения указателя,
а значит нужен двойной указатель, указатель на указатель*/

/*  Тут отличный пример подъехал
    int c = 1;
    int d = 2;
    int e = 3;
    int * a = &c;
    int * b = &d;
    int * f = &e;
    int ** pp = &a; 

     a = b;
    //Тут значение указателя изменится, но только внутри функции
     cant_change(a, f);
     //А тут мы предадим адрес, где лежит адрес, и изменим его
     change(pp, f);

void cant_change(int * x, int * z){
    x = z;
}

void change(int ** x, int * z){
    *x = z;
}
*/
int push(STACKNODE **topPtr, int info)
{
    STACKNODE *newPtr;

    newPtr = malloc(sizeof(STACKNODE)); //Выделим память

    if (newPtr != NULL)
    {
        newPtr->data = info;       //Втолкнём значения в нашу структуру
        newPtr->nextptr = *topPtr; //Теперь элемент который получили свяжем с верхом стопки
        *topPtr = newPtr;          // Верхний элемент это наш новый элемент
    }
    else
    {
        printf("memory is empty\n");
    }
    return (*topPtr)->data;
}

int pop(STACKNODE **topPtr)
{
    STACKNODE *tempPtr;

    int temp_data = (*topPtr)->data;
    tempPtr = *topPtr;
    *topPtr = (*topPtr)->nextptr;
    free(tempPtr);
    return temp_data;
}