/******************************************************************************
Simple hash table
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 50000000
//(701) //simple numbers

/* Hash data */
struct sHashItem
{
    size_t key;             // hash key    char * val;
    char *s;                // C-style string
    struct sHashItem *next; // Using a linked list to resolve collisions
};

typedef struct sHashItem Item;

typedef struct
{
    Item **cell; // array pointer
    size_t cnt;  //
    size_t size; // capacity
} sHashTable;

/* example

    HashTable.cnt;
    HashTable.size;
    HashTable.cell[0].key;
    HashTable.cell[0].val;
    HashTable.cell[0].next->key;

    HashTable.cell[1].val;


*/

void initHashTable(sHashTable *table);
void insertItem(sHashTable *table, char *data);
Item *createItem(sHashTable *table, char *data, size_t key);

void error_alloc_exit(void);
// sHashItem * createItem(unsigned long key, char * val);
// void freeItem(sHashTable * table);

/* all table */
sHashTable HashTable;

int main()
{
    printf("Hash table test\n");

    initHashTable(&HashTable);

    printf("OK\n");

    return 0;
}

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

int hashFunc(const char *s)
{
    unsigned long c = 0;

    if (s == NULL)
        return -1; // error

    while (*s)
        c += (int)(*s);

    return (c % HASH_SIZE);
}

void insertItem(sHashTable *table, char *data)
{
    int key = hashFunc(data);
    Item *item = createItem(table, data, key);

    if (item == NULL)
        error_alloc_exit();

    if (key < 0)
    {
        printf("Error insert item\n");
        exit(1);
    }

    /* no collision */
    if (table->cell[key] == NULL)
    {
        if (table->cnt == table->size)
        {
            printf("Warning, table is full\n");
            free(item);
            return;
        }

        table->cell[key] = item;
        table->cnt ++;
    }
    else
    {
        //while (table->cell[key] != NULL)
    }
}

Item *createItem(sHashTable *table, char *data, size_t key)
{
    Item *new_item = (Item *)malloc(sizeof(Item));

    if (data == NULL)
        return NULL;

    if (new_item == NULL)
        error_alloc_exit();

    new_item->s = (char *)malloc(strlen(data) + 1);

    if (new_item->s == NULL)
        error_alloc_exit();

    new_item->key = key;
    strcpy(new_item->s, data);

    return new_item;
}

void error_alloc_exit(void)
{
    printf("Error alloc memory\n");
    // free
    exit(1);
}