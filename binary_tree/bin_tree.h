#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <stdbool.h>


#define MAX_SIZE    (10U)

typedef struct sleaf
{
    int value;
    struct sleaf * left;
    struct sleaf * right;
}Sleaf;

typedef struct sTree
{
    Sleaf * root;
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



bool Toleft(int val1, int val2);
bool ToRight(int val1, int val2);
void AddNode(Sleaf * new, Sleaf * root);
bool IsBinary(Sleaf * root);
/**/
bool AddItemTree(Tree * ptT, const int val);




/**/
bool SearchItemTree(const Tree * ptT, const int val);

/**/
bool RemoveItemTree(const Tree * ptT, const int val);


#endif