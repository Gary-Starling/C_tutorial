#ifndef _MAIN_H_
#define _MAIN_H_

typedef struct stack
{
    char *name;
    struct stack *next;
} sStack;



void push(sStack **head, char *name);
void pop(sStack **head);
void print_stack(sStack **head);
int stack_size(sStack **head);

#endif
