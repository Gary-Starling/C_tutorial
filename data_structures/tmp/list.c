/* Type your code here, or load an example. */
/* exrecise for string aka linked list
[h]->[e]->[y]->[_]->[a]->[l]->[l]
need swap words in string///*/
#include <stdio.h>
#include <stdlib.h>

//
typedef struct
{
    int data;
    struct Item *next;
} sItem;

//
typedef struct
{
    sItem *head;
    sItem *tail;
} sList;

/* */
sItem *item_create(int data);
sList *list_new(void);
void list_delete(sList **list);
void item_insert_back(sList **list, char data);
void item_insert_top(sList **list, char data);
/* */
int list_len(sList *list);
void list_print(sList *list);
/**/
void error_exit(void);

//
sList *list_new(void)
{
    sList *list = malloc(sizeof(sList));

    if(list == NULL) return  NULL;

    list->head = NULL;
    list->head = NULL;

    char check = getchar();

    while (check != '\n')
    {
        item_insert_back(&list, check);
        check = getchar();
    }

    return list;
}

//
void item_insert_back(sList **list, char data)
{
    sItem *new = item_create(data);
    sItem *tmp = (*list)->head;

    if (new == NULL) exit(1);

    if (tmp == NULL)
    {
        list->head = new;
        list->tail = new;
    }
    else
    {
        while (tmp->next != NULL)
            tmp = tmp->next;

        tmp->next = new;
    }
}

//
void item_insert_top(List *list, char data)
{
    Item *new = item_create(data);

    if (new == NULL)
        exit(1);

    if (list->head == NULL)
    {
        list->head = new;
        list->tail = new;
    }
    else
    {
        new->next = list->head;
        list->head = new;
    }
}

Item *item_create(int data)
{
    Item *tmp = (Item *)malloc(sizeof(Item));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

//
void list_delete(List **list)
{
    Item *ptr = (*list)->head;
    Item *tmp;

    while (ptr != NULL)
    {
        tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }

    free(*list);
    *list = NULL;
}

//
void list_print(List *list)
{
    Item *tmp = list->head;

    while (tmp)
    {
        printf("%c", tmp->data);
        tmp = tmp->next;
    }

    printf("\n");
}

//
int list_len(List *list)
{
    Item *ptr;
    unsigned int len = 0;

    if (list == NULL)
        return 0;

    ptr = list->head;

    while (ptr != NULL)
    {
        len++;
        ptr = ptr->next;
    }

    return len;
}

//
void swap_word(List *list, Item *l, Item *r)
{
    Item *prL, *nextl, *prR, *nextR;

    prL = list->head;
    prR = list->head;

    if (prL == l)
        prL = NULL; // no item prev left
    while (prL->next != l)
        prL = prL->next; // prev
    nextl = l->next;     // next

    if (prR = r)
        prR = NULL;
    while (prR->next != r)
        prR = prR->next;
    nextR = r->next;

    if (nextl == r) //
    {
    }
    else if (nextR == l)
    {
    }
    else
    {
    }
}

int main()
{
    sList *list = list_new();

    if(list == NULL)
    {
        printf("Error memory alloc\n");
        exit(1);
    }

    while (list)
    {
        // item_insert_top(list, 'c');
        // item_insert_top(list, 'b');
        // item_insert_top(list, 'a');
        //  list_print(list);
        //  list_sort(list);
        list_print(list);
        printf("list len ->%d\n", list_len(list));
        list_delete(&list);
        printf("list len ->%d\n", list_len(list));
        list = list_new();
    }

    return 0;
}