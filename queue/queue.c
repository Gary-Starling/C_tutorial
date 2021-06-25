#include <stdio.h>
#include <stdlib.h>

struct myQueue
{
    char data;
    struct myQueue *next;
};

typedef struct myQueue QueueNew;
typedef QueueNew *QnextPtr;

void addQueue(QnextPtr *head, QnextPtr *tail, char in_data);
char delQueue(QnextPtr *head, QnextPtr *tail);
void printQueue(QnextPtr);

int main(int argc, char const *argv[])
{

    QnextPtr Head = NULL, Tail = NULL;
    printf("Add to Queue symbols\n");
    addQueue(&Head, &Tail, 'a');
    addQueue(&Head, &Tail, 'b');
    addQueue(&Head, &Tail, 'c');
    addQueue(&Head, &Tail, 'd');
    addQueue(&Head, &Tail, 'e');
    addQueue(&Head, &Tail, '1');
    addQueue(&Head, &Tail, '$');
    printQueue(Head);
    printf("del data [%c] \n", delQueue(&Head, &Tail));
    printf("del data [%c] \n", delQueue(&Head, &Tail));
    printf("del data [%c] \n", delQueue(&Head, &Tail));
    printf("Delete to Queue symbols\n");


    printQueue(Head);

    return 0;
}

//Прикол с указателем, на указатель QnextPtr = QueueNew *
//т.е  QueueNew **head  QueueNew **tail
//в основной программе объявлен указатель типа QnextPtr Head (QueueNew *Head)
//чтобы в нём произошли изменения мы передаём адрес указателя на указатель
//и уже в теле цикал происходит присваивание
void addQueue(QnextPtr *head, QnextPtr *tail, char in_data)
{
    QnextPtr newPtr;

    newPtr = malloc(sizeof(QueueNew));

    if (newPtr != NULL)
    {
        newPtr->data = in_data;
        newPtr->next = NULL;

        if ((*head) == NULL)
            (*head) = newPtr;
        else
            (*tail)->next = newPtr;

        (*tail) = newPtr;
    }
    else
        printf("no memory \n");
}

char delQueue(QnextPtr *head, QnextPtr *tail)
{
    QnextPtr temPtr = NULL;
    char data = 0;

    data = (*head)->data;
    temPtr = (*head);
    *head = (*head)->next;

    if(*head == NULL)
     *tail = NULL;

     free(temPtr);
     return data;
}

void printQueue(QnextPtr headptr)
{
    if(headptr == NULL)
     printf("Queue is empty\n");
     else
     {
        printf("data :");
         while (headptr != NULL)
         {
             printf(" [%c] ->", headptr->data);
             headptr = headptr->next; 
         }
          printf("\n");
     }
}