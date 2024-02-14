/*
exrecise for string aka linked list
[h]->[e]->[y]->[_]->[a]->[l]->[l]-[_]
* Words in a line are not repeated
*all words end ' ' !!!

Need swap words in string
  Input:  [H][e][l][l][o][_][W][o][r][l][d][_]
  Output: [W][o][r][l][d][_][H][e][l][l][o][_]
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
typedef struct Item
{
    char data;
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
sItem *item_insert_back(sList **list, char data);
void item_insert_top(sList **list, char data);
sItem *find_start_word(sList **list, const char *word, size_t len);

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
// Test
sList *list_new(void)
{
    sList *list = malloc(sizeof(sList));

    printf("Enter the words on one line separated by spaces. There is no need to enter the last space\n");

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

    item_insert_back(&list, 32);
    return list;
}

/**
 * @brief
 *
 * @param list
 * @param data
 * @return sItem*
 */
sItem *item_insert_back(sList **list, char data)
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

    return new;
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
{                                         //
    sItem *prl1, *nextl1, *prl2, *nextl2; // [prl1] [l1] [l1e] ;;;; [prl2] [l2] [l2e]
    sItem *l1e, *l2e;                     // end word  [pr] [l1 data = H]... [l1e data=o] [l1e]] -> word "Hello_"

    if ((l1 == NULL) || (l2 == NULL))
    {
        printf("adr1 -> %x; adr2 -> %x;\n", l1, l2);
        return;
    }

    if ((*list) == NULL)
    {
        printf("list is empty\n");
        return;
    }

    prl1 = (*list)->head;
    prl2 = (*list)->head;

    // TODO:** next two steps must be pack in function
    /* for l1 find start*/
    if (prl1 != l1)
    {
        while (prl1->next != l1) // find prv
            prl1 = prl1->next;   // next ptr
    }
    /* for l1 find end */
    l1e = l1;
    while (l1e->data != ' ')
        l1e = l1e->next;
    nextl1 = l1e->next;

    /* for l2 */
    // TODO:**
    if (prl2 != l2)
    {
        while (prl2->next != l2)
            prl2 = prl2->next;
    }
    // nextl2 = l2->next;
    /* for l1 find end */
    l2e = l2;
    while (l2e->data != ' ')
        l2e = l2e->next;
    nextl2 = l2e->next;

    if (nextl1 == l2) /* swap near (word1) -> (word2) */
    {
        if ((*list)->head == l1)
            (*list)->head = l2;
        else
            prl1->next = l2;

        l2e->next = l1;
        l1e->next = nextl2;
    }
    else if (nextl2 == l1) /* swap near (word2) -> (word1) */
    {
        if ((*list)->head == l2)
            (*list)->head = l1;
        else
            prl2->next = l1;

        l1e->next = l2;
        l2e->next = nextl1;
    }
    else /* swap word1->word2->[word3]->word4->[word5] ...*/
    {
        //TODO: 2 case  aaa l1 bbb l2 ccc | aaa l2 bbb l1 ccc
        if ((*list)->head != l1)
            prl1->next = l2;
        else
           (*list)->head = l2;

        l2e->next = nextl1;

        if ((*list)->head != l2)
            prl2->next = l1;
        else
         (*list)->head = l1;

        l1e->next = nextl2;
    }
}

/**
 * @brief
 *
 * @param msg
 */
void error_exit(const char *msg)
{
    printf("%s\n");
    exit(1);
}

/**
 * @brief
 *
 * @param list
 * @param word
 */
sItem *find_start_word(sList **list, const char *word, size_t len)
{
    sItem *tmp = (*list)->head;
    sItem *res = NULL;
    const char *p = word;
    size_t len_check = 0;

    if (tmp == NULL)
    {
        printf("list is empty\n");
        return NULL;
    }

    if (p == NULL)
    {
        printf("word is empty\n");
        return NULL;
    }

    /* Find the start word(letter) */
    while (p && tmp)
    {
        if (*p++ == tmp->data)
        {
            if (!res)
                res = tmp;
            len_check++;
        }
        else
        {
            p = word;
            len_check = 0;
            res = NULL;
        }
        tmp = tmp->next;

        if (len == len_check)
            return res;
    }

    return NULL;
}

int main()
{
    // Hey_all_ TEST string
    sList *list = list_new();
    sItem *f1 = NULL, *f2 = NULL;

    if (list == NULL)
        error_exit("Error alloc");

    while (list)
    {
        // item_insert_top(list, 'c');
        // item_insert_top(list, 'b');
        // item_insert_top(list, 'a');

        list_print(&list);
        //f1 = find_start_word(&list, "hey", strlen("hey"));
        //f2 = find_start_word(&list, "all", strlen("all"));
         f2 = find_start_word(&list, "hey", strlen("hey"));
         f1 = find_start_word(&list, "all", strlen("all"));
        swap_word(&list, f1, f2);
        list_print(&list);
        printf("list len ->%d\n", list_len(&list));
        list_delete(&list);
        printf("list len ->%d\n", list_len(&list));
        list = list_new();
    }

    return 0;
}