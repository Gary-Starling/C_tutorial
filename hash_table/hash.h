#ifndef _HASH_H
#define _HASH_H

#define DEBUG

#include <stdint.h>
#include <string.h>

#define OK  (0)
#define ERR (-1)

// use prime number
#define PRIME (176021)
// #define TEST_MALLOC  (100000000)
#define HASH_SIZE (PRIME)

/* Hash data */
struct sHashItem
{
    int key;                // hash key    char * val;
    char *val;              // C-style string
    struct sHashItem *next; // Using a linked list to resolve collisions
};

typedef struct sHashItem Item;

/* Hash table */
typedef struct
{
    Item **cell; // array pointer
    size_t cnt;  // сell counter. Just cells, not nodes.
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

int hashFunc(const char *val);
void initHashTable(sHashTable *table);
void freeTable(sHashTable *table);
void insertItem(sHashTable *table, const char *data);
Item *createItem(sHashTable *table, const char *data, const int key);
Item *findItemVal(sHashTable *table, const char *v);
int rmItem(sHashTable *table, const char *v);
void errAllocExit(void);

#endif