/******************************************************************************
Simple hash table
*******************************************************************************/
#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* all table */
    sHashTable HashTable;
    Item *curr;

    printf("Hash table\n");

    initHashTable(&HashTable);

    printf("Input data\n");
    printf("%d\n", hashFunc("Anna"));
    printf("%d\n", hashFunc("Igor"));
    printf("%d\n", hashFunc("rogI"));
    printf("%d\n", hashFunc("Saladin"));
    printf("%d\n", hashFunc("Richard"));
    printf("%d\n", hashFunc("Drahcir")); // inversion richard(collision)
    printf("%d\n", hashFunc("Darhcir")); // +(collision)
    printf("\n");

    printf("Insert\n");
    insertItem(&HashTable, "Anna");
    insertItem(&HashTable, "Igor");
    insertItem(&HashTable, "rogI");
    insertItem(&HashTable, "Saladin");
    insertItem(&HashTable, "Richard");
    insertItem(&HashTable, "Richard");
    insertItem(&HashTable, "Drahcir");
    insertItem(&HashTable, "Darhcir");
    printf("\n");

    printf("Search\n");
    curr = findItemVal(&HashTable, "Anna");
    printf("value : %s, key[%d]\n", curr->val, curr->key);
    curr = findItemVal(&HashTable, "Igor");
    printf("value : %s, key[%d]\n", curr->val, curr->key);
    curr = findItemVal(&HashTable, "Saladin");
    printf("value : %s, key[%d]\n", curr->val, curr->key);
    curr = findItemVal(&HashTable, "Richard");
    printf("value : %s, key[%d]\n", curr->val, curr->key);
    curr = findItemVal(&HashTable, "Drahcir");
    printf("value : %s, key[%d]\n", curr->val, curr->key);
    curr = findItemVal(&HashTable, "Darhcir");
    printf("value : %s, key[%d]\n", curr->val, curr->key);
    printf("\n");

    printf("Delete data\n");
    if (OK == rmItem(&HashTable, "Drahcir"))
        printf("delate Drahcir ok\n");

    curr = findItemVal(&HashTable, "Drahcir");
    if (curr != NULL)
        printf("value : %s, key[%d]\n", curr->val, curr->key);

    curr = findItemVal(&HashTable, "Richard");
    printf("value : %s, key[%d]\n", curr->val, curr->key);

    curr = findItemVal(&HashTable, "Darhcir");
    printf("value : %s, key[%d]\n", curr->val, curr->key);

    printf("Delete data\n");
    if (OK == rmItem(&HashTable, "Igor"))
        printf("delate Igor ok\n");

    curr = findItemVal(&HashTable, "rogI");
    printf("value : %s, key[%d]\n", curr->val, curr->key);

    /* printall */
    for (unsigned int i = 0; i < HASH_SIZE - 1; i++)
    {
        curr = HashTable.cell[i];
        while (curr != NULL)
        {
            printf("value : %s, key[%d]\n", curr->val, curr->key);
            curr = curr->next;
        }
    }

    freeTable(&HashTable);
    printf("OK\n");

    return 0;
}

/**
 * @brief Init and allocate hash table
 *
 * @param table - ptr to table
 */
void initHashTable(sHashTable *table)
{
    table->size = HASH_SIZE;
    table->cnt = 0;
    table->cell = (Item **)malloc(table->size * sizeof(Item *));

    if (table->cell == NULL)
        error_alloc_exit();

    for (size_t i = 0; i < table->size; i++)
        table->cell[i] = NULL; // cell is emppty
}

/**
 * @brief Simple hash function
 *
 * @param s - ptr to string(value)
 * @return int - key or -1(error)
 */
int hashFunc(const char *s)
{
    unsigned long c = 0;

    if (s == NULL)
        return -1; // error

    for (; *s; s++)
        c += (unsigned long)(*s);

    return (c % HASH_SIZE);
}

/**
 * @brief Insert value to Hash table
 *
 * @param table - ptr to table
 * @param data - input data(C-string)
 */
void insertItem(sHashTable *table, const char *data)
{
    int key = hashFunc(data);
    Item *item = createItem(table, data, key);
    Item *curr_item;

    if (item == NULL)
        error_alloc_exit();

    if (key < 0)
    {
        printf("Error insert item\n");
        exit(1);
    }

    if (table->cell[key] == NULL) /* no collision */
    {
        if (table->cnt == table->size) /* no space in table */
        {
            printf("Warning, table is full\n");
            free(item);
            return;
        }
        /* 0K*/
        table->cell[key] = item; /* new data */
        table->cnt++;
        printf("%s added in table\n", data);
    }
    else
    {
        if (table->cell[key]->key == key) /* value == data */
        {
            if (strcmp(table->cell[key]->val, data) == 0) /* nothing to do*/
            {
                printf("%s = %s\n", table->cell[key]->val, data);
                return;
            }

            else /* collision */
            {
                curr_item = table->cell[key];

                while (curr_item->next != NULL)
                    curr_item = curr_item->next;

                curr_item->next = item; /* new data */
                table->cnt++;
                printf("%s added in table(Collision)\n", data);
            }
        }
    }
}

/**
 * @brief Create a Item object
 *
 * @param table - ptr to table
 * @param data - input data(C-string)
 * @param key - key in array
 * @return Item* - NULL(error) or ptr(ok)
 */
Item *createItem(sHashTable *table, const char *data, const int key)
{
    Item *new_item = (Item *)malloc(sizeof(Item));

    if (data == NULL)
        return NULL;

    if (new_item == NULL)
        error_alloc_exit();

    new_item->val = (char *)malloc(strlen(data) + 1); /* alloc mem for string */

    if (new_item->val == NULL)
        error_alloc_exit();

    new_item->key = key;
    strcpy(new_item->val, data);

    return new_item;
}

/**
 * @brief Find item in hash table
 *
 * @param table - ptr to table
 * @param v - finding value(C-string)
 * @return Item* - NULL(error) or ptr(ok)
 */
Item *findItemVal(sHashTable *table, const char *v)
{
    int key = hashFunc(v);
    Item *curr_item = NULL;

    if (key < 0)
    {
        printf("no input data\n");
        return NULL;
    }

    curr_item = table->cell[key];

    while (curr_item != NULL) /* finding */
    {
        if (strcmp(v, curr_item->val) == 0)
            return curr_item;

        curr_item = curr_item->next;
    }

    return NULL;
}

/**
 * @brief delete item from table
 *
 * @param table - ptr to table
 * @param v - rm value(C-string)
 * @return int - result OK/ERR
 */
int rmItem(sHashTable *table, const char *v)
{
    int key = hashFunc(v);
    Item *curr_item = NULL, *temp = NULL, *prv;

    if (key < 0)
    {
        printf("No input vaulue\n");
        return ERR;
    }

    curr_item = table->cell[key];

    if (curr_item == NULL) /* empty */
    {
        printf("value : %s not in table\n", v);
        return ERR; /* no delete */
    }
    

    //** 3 case *//
    //TODO
    while (curr_item != NULL) /* finding */
    {
        if (strcmp(v, curr_item->val) == 0)
        {
            temp = curr_item;
            curr_item = curr_item->next;
            free(temp);
            table->cell[key] = curr_item;
            return OK;
        }

        curr_item = curr_item->next;
    }

    //prev_item->next = curr_item->next;
    
    return 0;
}

/**
 * @brief Free all data
 *
 * @param table - ptr to table
 */
void freeTable(sHashTable *table)
{
    Item *curr_item = NULL;
    Item *next_item = NULL;

    for (unsigned int i = 0; i < HASH_SIZE; i++)
    {
        curr_item = table->cell[i];
        while (curr_item != NULL)
        {
            next_item = curr_item->next;
            /* erase data*/
            memset(curr_item->val, 0x00, strlen(curr_item->val) + 1);
            curr_item->key = 0;
            free(curr_item->val);
            free(curr_item);
            curr_item = next_item;
        }
    }

    free(table->cell);
}

/**
 * @brief User function error
 *
 */
void error_alloc_exit(void)
{
    printf("Error alloc memory\n");
    exit(1);
}