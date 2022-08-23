#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>
#include <stdint.h>

#define Q_MAX   (5U)

typedef struct item_info {
    char name[100];
}ItemInfo;

typedef struct node {
  ItemInfo item;
  struct node * next;  
}Node;

typedef struct Queue {
    Node * head;  /* ptr on front */
    Node * tail;  /* ptr on rear  */
    uint32_t cnt; /* cnt item */
}queue;

/* init queue */
void InitQ(queue * pq); //

/* check queue is full or not */
bool QisFull(const queue * pq);

/* check queue is empty or not */
bool QisEmpty(const queue * pq);

/* return amount objrcts in queue */
int QItemCnt(const queue * pq);

/* add item in queue */
bool EnQueue(ItemInfo item, queue * pq);

/* delete item from queue */
ItemInfo DeQueue(queue * pq);

/* clear all queue */
void ClearQueue(queue * pq);



#endif