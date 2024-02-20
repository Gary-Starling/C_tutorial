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
#include <string.h>
#include "list.h"
#include <assert.h>

/* test arrays */
#define TEST_SIZE (13U)
const char *test_in_str[TEST_SIZE] = {
    "hello world",
    "world hello",
    "hello xxx world",
    "world yyy hello",
    "ttttt hello world",
    "ttttt world hello",
    "hello world ppppp",
    "world hello tttttt",
    "xxx hello yyy world",
    "xxx world yyy hello",
    "hello abc defg hijkl world",
    "aaa hello bbb world ccc",
    "aaa world bbb hello ccc",
    };

const char *test_out_str[TEST_SIZE] = {
    "world hello ",
    "hello world ",
    "world xxx hello ",
    "hello yyy world ",
    "ttttt world hello ",
    "ttttt hello world ",
    "world hello ppppp ",
    "hello world tttttt ",
    "xxx world yyy hello ",
    "xxx hello yyy world ",
    "world abc defg hijkl hello ",
    "aaa world bbb hello ccc ",
    "aaa hello bbb world ccc ",
    };
/* test arrays end */

/**
 * @brief create new list
 *
 * @return sList* - pointer to list
 */
sList *list_manual_new(void)
{
    sList *list = malloc(sizeof(sList));

    printf("\nEnter the words on one line separated by spaces. There is no need to enter the last space\n");

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

// for test
/**
 * @brief New list and copy string into it
 *
 * @param str - pointer to string
 * @return sList* - pointer to list
 */
sList *list_auto_new(const char *str)
{
    sList *list = malloc(sizeof(sList));

    if (list == NULL)
        return NULL;

    list->head = NULL;
    list->tail = NULL;

    while (*str)
        item_insert_back(&list, *str++);

    item_insert_back(&list, 32); // end of string in list
    return list;
}

/**
 * @brief add node to end of list
 *
 * @param list - Pointer to list address
 * @param data - string character
 * @return sItem* - pointer to new node
 */
sItem *item_insert_back(sList **list, const char data)
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
 * @brief add node to start of list
 *
 * @param list - Pointer to list address
 * @param data - string character
 */
void item_insert_top(sList **list, const char data)
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
 * @brief create node
 *
 * @param data - character
 * @return sItem* - pointer to new node
 */
sItem *item_create(int data)
{
    sItem *tmp = malloc(sizeof(sItem));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

/**
 * @brief Delete list
 *
 * @param list - Pointer to list address
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
 * @brief Print list
 *
 * @param list - Pointer to list address
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

/**
 * @brief compare string and list
 *
 * @param list - Pointer to list address
 * @return int - 1 if error, 0 - ok
 */
int list_comp(sList **list, const char *str)
{
    sItem *tmp = (*list)->head;

    while (tmp)
    {
        if (tmp->data != *str++)
            return -1;
        tmp = tmp->next;
    }

    return 0;
}

/**
 * @brief Length of list
 *
 * @param list - Pointer to list address
 * @return unsigned int len of list
 */
unsigned int list_len(sList **list)
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

/**
 * @brief Swap two words in list
 *
 * @param list - Pointer to list address
 * @param l1 - pointer to start word1
 * @param l2 - pointer to start word2
 */
void swap_word(sList **list, sItem *l1, sItem *l2)
{                                         //
    sItem *prl1, *nextl1, *prl2, *nextl2; // [prl1] [l1] [l1e] ;;;; [prl2] [l2] [l2e]
    sItem *l1e, *l2e;                     // end word  [pr] [l1 data = H]... [l1e data=o] [l1e]] -> word "Hello_"

    if ((l1 == NULL) || (l2 == NULL))
    {
        printf("adr1 -> %p; adr2 -> %p;\n", l1, l2);
        return;
    }

    if ((*list) == NULL)
    {
        printf("list is empty\n");
        return;
    }

    prl1 = find_pr_item(list, l1);
    prl2 = find_pr_item(list, l2);
    l1e = find_end_item(l1);
    l2e = find_end_item(l2);
    nextl1 = l1e->next;
    nextl2 = l2e->next;

    if (nextl1 == l2) /* swap near (word1) -> (word2) */
    {
        if ((*list)->head == l1) (*list)->head = l2;
        else prl1->next = l2;

        l2e->next = l1;
        l1e->next = nextl2;
    }
    else if (nextl2 == l1) /* swap near (word2) -> (word1) */
    {
        if ((*list)->head == l2) (*list)->head = l1;
        else prl2->next = l1;

        l1e->next = l2;
        l2e->next = nextl1;
    }
    else /* swap word1->word2->[word3]->word4->[word5] ...*/
    {
        if ((*list)->head != l1 && (*list)->head == l2)
        {
            l2e->next = nextl1;
            l1e->next = nextl2;
            prl1->next = l2;
            (*list)->head = l1;
        }
        else if ((*list)->head != l2 && (*list)->head == l1)
        {
            l2e->next = nextl1;
            l1e->next = nextl2;
            prl2->next = l1;
            (*list)->head = l2;
        }
        else
        {
            l2e->next = nextl1;
            l1e->next = nextl2;
            prl1->next = l2;
            prl2->next = l1;
        }
    }
}

/**
 * @brief User error function
 *
 * @param msg -
 */
void error_exit(const char *msg)
{
    printf("%s\n", msg);
    exit(1);
}

/**
 * @brief Find the address of the beginning of a word
 *
 * @param list - Pointer to list address
 * @param word - what you're looking for
 * @param len - word length
 * @return sItem* - pointer to start word
 */
sItem *find_start_word(sList **list, const char *word, const size_t len)
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

/**
 * @brief Find previous element of the word
 *
 * @param list - Pointer to list address
 * @param f - pointer to start word
 * @return sItem* - pointer to previous element
 */
sItem *find_pr_item(sList **list, sItem *f)
{
    sItem *tmp = (*list)->head;

    if (f != tmp)
    {
        while (tmp->next != f)
            tmp = tmp->next;
    }

    return tmp;
}

/**
 * @brief Find end of the word
 * all words end with a symbol ' '
 * @param f - pointer to start word
 * @return sItem* - pointer to end word
 */
sItem *find_end_item(sItem *f)
{
    sItem *tmp = f;
    while (tmp->data != ' ')
        tmp = tmp->next;

    return tmp;
}

int main()
{
    sList *list = NULL;
    sItem *f1 = NULL, *f2 = NULL;

    for (size_t i = 0; i < TEST_SIZE; i++)
    {
        printf("Test N%lld\n", i);
        list = list_auto_new(test_in_str[i]);
        list_print(&list);

        f1 = find_start_word(&list, "hello", strlen("hello"));
        f2 = find_start_word(&list, "world", strlen("world"));

        swap_word(&list, f1, f2);

        list_print(&list);
        assert(!list_comp(&list, test_out_str[i]));
        printf("list len ->%d\n\n", list_len(&list));

        list_delete(&list);
    }

    return 0;
}