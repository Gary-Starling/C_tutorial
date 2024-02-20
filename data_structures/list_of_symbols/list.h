#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>

typedef struct Item
{
    char data;
    struct Item *next;
} sItem;

typedef struct
{
    sItem *head;
    sItem *tail;
} sList;

sItem *item_create(const int data);

sList *list_manual_new(void);
sList *list_auto_new(const char * str);

void list_delete(sList **list);

sItem *item_insert_back(sList **list, const char data);

void item_insert_top(sList **list, const char data);

sItem *find_start_word(sList **list, const char *word, const size_t len);

unsigned int list_len(sList **list);

void list_print(sList **list);

void error_exit(const char *s);

void swap_word(sList **list, sItem *l1, sItem *l2);

sItem *find_pr_item(sList **list, sItem * f);

sItem *find_end_item(sItem * f);

int list_comp(sList **list, const char * str);

#endif