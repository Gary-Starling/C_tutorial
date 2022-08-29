#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <stdbool.h>


#define MAX_SIZE    (10U)

typedef struct sData {
    int value;
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
void InitTree(Tree * ptrRoot);

/**/


#endif