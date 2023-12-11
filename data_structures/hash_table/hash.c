/******************************************************************************
Simple hash table

How to handle Collisions?
Separate Chaining

*******************************************************************************/
#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    time_t start, end;
    sHashTable HashTable; /* all table */
    Item *curr;
    char s[10];

    start = clock();
    srand(time(NULL));

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
    /* test case 1 add collision */
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

    printf("*************\n\n\r");
    insertItem(&HashTable, "Abc");
    curr = findItemVal(&HashTable, "Abc");
    printf("value : %s, key[%d]\n", curr->val, curr->key);
    rmItem(&HashTable, "Abc"); // rm head

    insertItem(&HashTable, "Acb");
    curr = findItemVal(&HashTable, "Acb");
    printf("value : %s, key[%d]\n", curr->val, curr->key);
    // rmItem(&HashTable, "Acb"); //rm item list []->[x]->[]->[]
    //                          //                |________^

    insertItem(&HashTable, "cAb");
    curr = findItemVal(&HashTable, "cAb");
    printf("value : %s, key[%d]\n", curr->val, curr->key);
    // rmItem(&HashTable, "cAb");// rm item list []->[]->[x]->[]
    //                           //                   |________^

    insertItem(&HashTable, "cbA");
    curr = findItemVal(&HashTable, "cbA");
    printf("value : %s, key[%d]\n", curr->val, curr->key);
    // rmItem(&HashTable, "Acbd"); rm in the end of list []->[]->[]->[x]
    printf("*************\n\n\r");

    /* random test */
    for (unsigned int i = 0; i < HASH_SIZE; i++)
    {
        randString10(s);
        insertItem(&HashTable, s);
    }

    for (unsigned int i = 0; i < HASH_SIZE; i++)
    {
        randString10(s);
        rmItem(&HashTable, s);
    }

    printTable(&HashTable);
    freeTable(&HashTable);
    printf("OK\n");
    end = clock();

    printf("Total time:%g\n", (double)(end - start) / CLOCKS_PER_SEC);

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
        errAllocExit();

    for (size_t i = 0; i < table->size; i++)
        table->cell[i] = NULL; /* NULL to all ceils */
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
        return ERR; /* error */

    for (; *s; s++)
        c += (unsigned long)(*s);

    return (c % HASH_SIZE);
}

/*
Multiplication method
h(key) = [ m * (key * A % 1) ]
m - TABLE_SIZE

int hashFunc(const char *s)
{
    double A = 0.61803398;
    double res;
    unsigned long c = 0;

    for (; *s; s++)
        c += (unsigned long)(*s);

    double res = HASH_SIZE * fmod(c * A, 1);
    return (int)res;
}
 */

/**
 * @brief Insert value to Hash table
 *
 * @param table - ptr to table
 * @param data - input data(C-string)
 */
void insertItem(sHashTable *table, const char *data)
{
    int key = hashFunc(data);
    Item *item = NULL;
    Item *curr_item = NULL;

    if (table->cnt == table->size) /* no space in table */
    {
#ifdef DEBUG
        printf("Warning, table is full\n");
#endif
        return;
    }

    if (key < 0)
    {
#ifdef DEBUG
        printf("Error insert item(key error)\n");
#endif
        exit(1);
    }

    item = createItem(table, data, key); /* new item alloc */

    if (item == NULL)
        errAllocExit();

    if (table->cell[key] == NULL) /* no collision */
    {
        table->cell[key] = item; /* new data */
        table->cnt++;
#ifdef DEBUG
        printf("[%s] added in table; key[%d]\n", data, key);
#endif
    }
    else /* collision occur  */
    {
        if (strcmp(table->cell[key]->val, data) == 0) /* nothing to do */
        {                                             //.. val = "Abc" data = "Abc" ; val = data
#ifdef DEBUG
            printf("[%s] = [%s] (skip)\n", table->cell[key]->val, data);
#endif
            return;
        }
        else /* collision */
        {
            curr_item = table->cell[key];

            while (curr_item->next != NULL)
            {
                curr_item = curr_item->next;
                if (strcmp(curr_item->val, data) == 0) /* nothing to do */
                {                                      //.. val = "Abc" data = "Abc" ; val = data
#ifdef DEBUG
                    printf("[%s] = [%s] (skip)\n", curr_item->val, data);
#endif
                    return;
                }
            }

            curr_item->next = item; /* new data */
            table->cnt++;
#ifdef DEBUG
            printf("[%s] added in table(Collision); key[%d]\n", data, key);
#endif
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
        errAllocExit();

    new_item->val = (char *)malloc(strlen(data) + 1); /* alloc mem for string */

    if (new_item->val == NULL)
        errAllocExit();

    new_item->key = key;
    strcpy(new_item->val, data);

    new_item->next = NULL;

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
#ifdef DEBUG
        printf("no input data\n");
#endif
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
 * TODO: 3 case -> 3 func
 */
int rmItem(sHashTable *table, const char *v)
{
    int key = hashFunc(v);
    Item *curr_item, *temp = NULL, *prev = NULL;
    curr_item = table->cell[key];

    if (table->cnt == 0)
    {
#ifdef DEBUG
        printf("Table is empty\n");
#endif
        return ERR;
    }

    if (key < 0) /* Error key */
    {
#ifdef DEBUG
        printf("No input vaulue\n");
#endif
        return ERR;
    }

    if (curr_item == NULL) /* case 1: empty cell (nothing to do) */
    {
#ifdef DEBUG
        printf("[value] : %s not in table\n", v);
#endif
        return ERR;
    }
    /* case 1: end */

    if (strcmp(v, curr_item->val) == 0) /* if data match (head value) */
    {
        table->cnt--;
        temp = curr_item;
        curr_item = curr_item->next; /* next data or NULL */
        table->cell[key] = curr_item;
        free(temp);
        printf("[value] : %s rm from table\n", v);
        return OK;
    }
    else /* collision */
    {
        prev = curr_item;
        curr_item = curr_item->next;

        while (curr_item != NULL)
        {
            if (strcmp(v, curr_item->val) == 0)
            {
                table->cnt--;
                temp = curr_item;
                prev->next = curr_item->next;
                free(temp);
                printf("[value] : %s rm from table\n", v);
                return OK;
            }

            prev = curr_item;
            curr_item = curr_item->next;
        }
    }

#ifdef DEBUG
    printf("[value] : %s not in table\n", v);
#endif
    return ERR;
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
void errAllocExit(void)
{
#ifdef DEBUG
    printf("Error alloc memory\n");
#endif
    exit(1);
}

/**
 * @brief
 *
 * @param table
 */
void printTable(const sHashTable *const table)
{
    Item *curr;

    /* printall */
    for (unsigned int i = 0; i < HASH_SIZE - 1; i++)
    {
        curr = table->cell[i];
        while (curr != NULL)
        {
#ifdef DEBUG
            printf("value : %s, key[%d]\n", curr->val, curr->key);
#endif
            curr = curr->next;
        }
    }
}

void randString10(char *s)
{
    int i;
    int len = 1 + rand() % 9;
    for (i = 0; i < len; ++i)
    {
        s[i] = rand() % 26 + 'A';
        len = 1 + rand() % 9;
    }
    s[len] = '\0';
}