#ifndef _CURRENT_H_
#define _CURRENT_H_

#include <stdbool.h>

#define NAME_SIZE   50  

typedef struct 
{
    char name[NAME_SIZE];
    int rating;
}propert;

typedef struct node
{
    propert film;
    struct node * next;
}Node;

typedef Node * List;

/* Init list */
void InitList(List * ptrList);

/* check empty list */
bool ListIsEmpty(const List *ptrList);

/* item count */
unsigned int ListItemCnt(const List *ptrList);

/* 
Add item 
return result true = ok, false = error
*/
bool AddItem(propert item, List * ptrList);

/* 
free alloc memory
*/
void CleanList(List * ptrList);

/* show items of list */
void ItemShow(const List * ptrList);



#endif