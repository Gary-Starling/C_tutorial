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
sItem *item_insert_back(sList **list, char data);
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
// Test
sItem *arr[100] = {NULL}; // for test
unsigned int step = 0;    // for fast test swap
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
        arr[step++] = item_insert_back(&list, check);
        check = getchar();
    }

    arr[step++] = item_insert_back(&list, 10);
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
{
    sItem *prl1, *nextl1, *prl2, *nextl2; //  [pr] [l1] [next]
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
    if (prl1 == l1)
        prl1 = NULL; // no item prev<-l1
    else
    {
        while (prl1->next != l1) // find prv
            prl1 = prl1->next;   // next ptr
    }
    nextl1 = l1->next; // next for l1
    /* for l1 find end */
    l1e = nextl1;
    while (l1e->data != ' ')
        l1e = l1e->next;

    /* for l2 */
    // TODO:**
    if (prl2 == l2)
        prl2 = NULL; // same opertions for l2
    else
    {
        while (prl2->next != l2)
            prl2 = prl2->next;
    }
    nextl2 = l2->next;
    /* for l1 find end */
    l2e = nextl2;
    while (l2e->data != ' ')
        l2e = l2e->next;

    /* swap */
    prl1->next = l2;
    l2e->next = nextl1;
    prl2->next = l1;
    l1e->next = nextl2;
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
    sItem *tmp, *res = (*list)->head;
    char *p = word;
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

    /*
    char *
strstr (const char *s1, const char *s2)
{
  const char *p = s1;
  const size_t len = strlen (s2);

  if (!len)
    return s1;

  for (; (p = strchr (p, *s2)) != 0; p++)
    {
      if (strncmp (p, s2, len) == 0)
    return (char *)p;
    }
  return (0);
}*/

    /* Find the start word(letter) */
    // while(p && tmp)
    // {
    //     if(*p++ == tmp->data)
    //     {
    //         while (*p !=)
    //         {
    //             /* code */
    //         }

    //     }
    // }

    // if(len_check == len) return ok;
}

int main()
{
    //Hey_all_ TEST 
    sList *list = list_new();

    if (list == NULL)
        error_exit("Error alloc");

    while (list)
    {
        // item_insert_top(list, 'c');
        // item_insert_top(list, 'b');
        // item_insert_top(list, 'a');

        list_print(&list);
        swap_word(&list, arr[0], arr[4]);
        list_print(&list);
        printf("list len ->%d\n", list_len(&list));
        list_delete(&list);
        printf("list len ->%d\n", list_len(&list));
        list = list_new();
    }

    return 0;
}