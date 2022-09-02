#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <stdbool.h>


#define MAX_SIZE    (10U)

typedef struct sData {
    int age;
    char name[20];
} sData;

struct sleaf
{
    sData data;
    struct sleaf * leaf;
    struct sleaf * right;
};

typedef struct sleaf sLeaf;

typedef struct sTree
{
    sLeaf * root;
    int size;
}Tree;

/**/
void InitTree(Tree * ptT);

/**/
bool TreeIsEmpty(const Tree * ptT);

/**/
bool TreeIsFull(const Tree * ptT);

/**/
unsigned int ItemTree(const Tree * ptT);

/**/
bool AddItemTree(Tree * ptT, sData data);

/**/
bool SearchItemTree(const Tree * ptT, sData data);

/**/
bool RemoveItemTree(const Tree * ptT, sData data);


#endif