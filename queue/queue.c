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
        new = (Node *)malloc(sizeof(Node)); // create

    if (new == NULL)
    {
        fprintf(stderr, "Error allocated data\n");
        exit(1);
    }
    else
    {
        strcpy(new->item.name, data.name); // copy data
        new->next = NULL;                  // end list

        if (QisEmpty(pq))
            pq->head = new;
        else
            pq->tail->next = new; // current node pointer to new

        pq->tail = new; // current pointer now is new(last pointer)

        pq->cnt++;
    }

    return true;
}

/**
 * @brief
 *
 * @param data
 * @param pq
 * @return true
 * @return false
 */
bool DelQueue(ItemInfo *data, queue *pq)
{
    Node *tmp;

    if (QisEmpty(pq))
        return false;

    strcpy(data->name, pq->head->item.name); // data which will delete

    tmp = pq->head;

    pq->head = pq->head->next;

    free(tmp);

    pq->cnt--;

    if (pq->cnt == 0)
    {
        pq->tail = NULL;
        pq->head = NULL;
    }

    return true;
}

void ClearQueue(queue *pq)
{
    ItemInfo some;

    while (pq->cnt != 0)
    {
        DelQueue(&some, pq);
    }
}

int main(int argc, char const *argv[])
{
    queue myQ;

    ItemInfo tmp;

    ItemInfo data1 = {
        .name = "somebody"};

    ItemInfo data2 = {
        .name = "once"};

    ItemInfo data3 = {
        .name = "told"};

    ItemInfo data4 = {
        .name = "me"};

    InitQ(&myQ);
    EnQueue(data1, &myQ);
    EnQueue(data2, &myQ);
    EnQueue(data3, &myQ);
    EnQueue(data4, &myQ);
    DelQueue(&tmp,&myQ);

    while (myQ.cnt != 0)
    {
        DelQueue(&tmp, &myQ);
        printf("%s ", tmp.name);
    }

    printf("\n");

    EnQueue(data1, &myQ);
    EnQueue(data2, &myQ);
    EnQueue(data3, &myQ);
    EnQueue(data4, &myQ);

    printf("item in queue = %d\n", QitemCnt(&myQ));
    ClearQueue(&myQ);
    printf("item in queue = %d\n", QitemCnt(&myQ));

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