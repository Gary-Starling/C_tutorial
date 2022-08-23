#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <string.h>

/* default init q */
void InitQ(queue *pq)
{
    pq->head = pq->tail = NULL;
    pq->cnt = 0;
}

/**
 * @brief
 * Check if the queue is full
 * @param pq - pointer to queue
 * @return true
 * @return false
 */
bool QisFull(const queue *pq)
{
    return pq->cnt == Q_MAX;
}

/**
 * @brief
 * Check if the queue is empty
 * @param pq
 * @return true
 * @return false
 */
bool QisEmpty(const queue *pq)
{
    return pq->cnt == 0U;
}

/**
 * @brief
 * return the amount of data in the queue
 * @param pq
 * @return true
 * @return false
 */
uint32_t QitemCnt(const queue *pq)
{
    return pq->cnt;
}

bool EnQueue(ItemInfo data, queue *pq)
{
    Node *new = NULL;

    if (QisFull(pq))
        return false;
    else
        new = (Node *)malloc(sizeof(Node));

    if (new == NULL)
    {
        fprintf(stderr, "Error allocated data\n");
        exit(1);
    }
    else
    {
        strcpy(new->item.name, data.name);
        new->next = NULL;

        if (QisEmpty(pq))
            pq->head = new;
        else
            pq->tail->next = new;

        pq->tail = new;

        pq->cnt++;
    }

    return true;
}

int main(int argc, char const *argv[])
{
    queue myQ;

    ItemInfo test1 = {
        .name = "test1\0"};

    ItemInfo test2 = {
        .name = "test2\0"};

    ItemInfo test3 = {
        .name = "test3\0"};    

    InitQ(&myQ);
    EnQueue(test1, &myQ);
    EnQueue(test2, &myQ);
    EnQueue(test3, &myQ);

    return 0;
}

//Прикол с указателем, на указатель QnextPtr = QueueNew *
//т.е  QueueNew **head  QueueNew **tail
//в основной программе объявлен указатель типа QnextPtr Head (QueueNew *Head)
//чтобы в нём произошли изменения мы передаём адрес указателя на указатель
//и уже в теле цикал происходит присваивание
// void addQueue(QnextPtr *head, QnextPtr *tail, char in_data)
// {
//     QnextPtr newPtr;

//     newPtr = malloc(sizeof(QueueNew));

//     if (newPtr != NULL)
//     {
//         newPtr->data = in_data;
//         newPtr->next = NULL;

//         if ((*head) == NULL)
//             (*head) = newPtr;
//         else
//             (*tail)->next = newPtr;

//         (*tail) = newPtr;
//     }
//     else
//         printf("no memory \n");
// }

// char delQueue(QnextPtr *head, QnextPtr *tail)
// {
//     QnextPtr temPtr = NULL;
//     char data = 0;

//     data = (*head)->data;
//     temPtr = (*head);
//     *head = (*head)->next;

//     if(*head == NULL)
//      *tail = NULL;

//      free(temPtr);
//      return data;
// }

// void printQueue(QnextPtr headptr)
// {
//     if(headptr == NULL)
//      printf("Queue is empty\n");
//      else
//      {
//         printf("data :");
//          while (headptr != NULL)
//          {
//              printf(" [%c] ->", headptr->data);
//              headptr = headptr->next;
//          }
//           printf("\n");
//      }
// }