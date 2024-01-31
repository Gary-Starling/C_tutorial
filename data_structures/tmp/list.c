/* exrecise for string aka linked list
[h]->[e]->[y]->[_]->[a]->[l]->[l]-[_]
1)need swap words in string
2)all words end ' '
3)make program */
#include <stdio.h>
#include <stdlib.h>

//
typedef struct Item
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
int list_len(sList **list);
void list_print(sList **list);

/**/
void error_exit(const char *s);

/**/
void swap_word(sList **list, sItem *l1, sItem *l2);

/**
 * @brief
 *
 * @return sList*
 */
sList *list_new(void)
{
    sList *list = malloc(sizeof(sList));

    if (list == NULL)
        return NULL;

    list->head = NULL;
    list->tail = NULL;

    char check = getchar();

    while (check != '\n')
    {
        item_insert_back(&list, check);
        check = getchar();
    }

    item_insert_back(&list, 10);
    return list;
}

/**
 * @brief
 *
 * @param list
 * @param data
 */
void item_insert_back(sList **list, char data)
{
    sItem *new = item_create(data);
    sItem *tmp = (*list)->head;

    if (new == NULL)
        error_exit("Error alloc");

    if (tmp == NULL)
    {
        (*list)->head = new;
        (*list)->tail = new;
    }
    else
    {
        while (tmp->next != NULL)
            tmp = tmp->next;

        tmp->next = new;
    }
}

/**
 * @brief
 *
 * @param list
 * @param data
 */
void item_insert_top(sList **list, char data)
{
    sItem *new = item_create(data);

    if (new == NULL)
        error_exit("Error alloc");

    if ((*list)->head == NULL)
    {
        (*list)->head = new;
        (*list)->tail = new;
    }
    else
    {
        new->next = (*list)->head;
        (*list)->head = new;
    }
}

/**
 * @brief
 *
 * @param data
 * @return sItem*
 */
sItem *item_create(int data)
{
    sItem *tmp = malloc(sizeof(sItem));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

/**
 * @brief
 *
 * @param list
 */
void list_delete(sList **list)
{
    sItem *ptr = (*list)->head;
    sItem *tmp;

    while (ptr != NULL)
    {
        tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }

    free(*list);
    *list = NULL;
}

/**
 * @brief
 *
 * @param list
 */
void list_print(sList **list)
{
    sItem *tmp = (*list)->head;

    while (tmp)
    {
        printf("%c", tmp->data);
        tmp = tmp->next;
    }

    printf("\n");
}

//
int list_len(sList **list)
{
    sItem *ptr = NULL;
    unsigned int len = 0;

    if (*list == NULL)
        return 0;

    ptr = (*list)->head;
    while (ptr != NULL)
    {
        len++;
        ptr = ptr->next;
    }

    return len;
}

//
void swap_word(sList **list, sItem *l1, sItem *l2)
{
    sItem *prL, *nextl, *prR, *nextR;

    prL = (*list)->head;
    prR = (*list)->head;

    if (prL == l1)
        prL = NULL; // no item prev left
    while (prL->next != l1)
        prL = prL->next; // prev
    nextl = l1->next;     // next

    if (prR = l2)
        prR = NULL;
    while (prR->next != l2)
        prR = prR->next;
    nextR = l2->next;

    if (nextl == l2) //
    {
    }
    else if (nextR == l2)
    {
    }
    else
    {
    }
}

void error_exit(const char *msg)
{
    printf("%s\n");
    exit(1);
}

int main()
{
    sList *list = list_new();

    if (list == NULL)
        error_exit("Error alloc");

    while (list)
    {
        // item_insert_top(list, 'c');
        // item_insert_top(list, 'b');
        // item_insert_top(list, 'a');
        //  list_print(list);
        //  list_sort(list);
        list_print(&list);
        printf("list len ->%d\n", list_len(&list));
        list_delete(&list);
        printf("list len ->%d\n", list_len(&list));
        list = list_new();
    }

    return 0;
}