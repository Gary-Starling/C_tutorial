#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char const *argv[])
{

    sStack *ptrHead = NULL;

    push(&ptrHead, "Igor");
    push(&ptrHead, "Anna");
    push(&ptrHead, "Egor");
    push(&ptrHead, "Feta");
    push(&ptrHead, "Rada");
    push(&ptrHead, "TM");

    print_stack(&ptrHead);

    printf("(%d) elemnts in stack\n", stack_size(&ptrHead));

    pop(&ptrHead);
    pop(&ptrHead);
    
    print_stack(&ptrHead);

    printf("(%d) elemnts in stack\n", stack_size(&ptrHead));

    return 0;
}

void push(sStack **head, char *name)
{
    sStack *new_el = (sStack *)malloc(sizeof(sStack));

    if (new_el == NULL)
    {
        printf("Error allocate memory\n");
        exit(1);
    }
    else
    {
        new_el->name = name;
        new_el->next = *head;
        *head = new_el;
    }
}

void print_stack(sStack **head)
{
    sStack *tmp_head = *head;

    while (tmp_head != NULL)
    {
        printf("data -> %s\n", tmp_head->name);
        tmp_head = tmp_head->next;
    }
}

void pop(sStack **head)
{
    struct stack *tmp = *head;
    printf("delete item (%s)\n", (*head)->name);
    *head = (*head)->next;
    free(tmp);
}

int stack_size(sStack **head)
{
    int size = 0;
    sStack *tmp_head = *head;

    while (tmp_head != NULL)
    {
        size++;
        tmp_head = tmp_head->next;
    }

    return size;
}
