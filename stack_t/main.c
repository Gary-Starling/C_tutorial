#include <stdio.h>
#include <stdlib.h>

struct list
{
    char * name;
    struct list * next;
};

struct stack
{
    struct list * head;
};


void push(struct stack * s, char * name);
//void pop(struct stack * s);
void print_stack(struct stack * head);



int main(int argc, char const *argv[])
{
    
    struct stack Stack;
    Stack.head = NULL;

    push(&Stack, "Igor");
    push(&Stack, "Anna");
    push(&Stack, "Egor");
    push(&Stack, "Feta");
    push(&Stack, "Rada");
    push(&Stack, "TM");
    print_stack(&Stack);
   // pop(&Head);
   // pop(&Head);
   // print_stack(Head);
    
    return 0;
}

void push(struct stack * s, char * name)
{
    struct list * new_el = (struct list *)malloc(sizeof(struct list));

    if(new_el == NULL)
    {
        printf("Error allocate memory\n");
        exit(1);
    }
    
    new_el->name = name;
    new_el->next = s->head;
    s->head = new_el;
}


void print_stack(struct stack * s)
{
    while (s->head != NULL)
    {
        printf("data -> %s\n", s->head->name);
        s->head = s->head->next;
    }
}

/*
void pop(struct stack ** head)
{
    struct stack * tmp = *head;

    printf("delete item (%s)\n", (*head)->name);
    *head = (*head)->next;
    free(tmp);
}

*/