#include <stdio.h>
#include <string.h>
#include "bin_tree.h"

int main(int argc, char const *argv[])
{
    return 0;
}

void InitTree(Tree *ptT)
{
    ptT->root->leaf = ptT->root->leaf = NULL;
    ptT->size = 0;
}

bool TreeIsEmpty(const Tree *ptT)
{
    return ptT->size == 0U;
}

bool TreeIsFull(const Tree *ptT)
{
    return ptT->size == MAX_SIZE;
}

bool AddItemTree(Tree *ptT, sData data)
{
    sLeaf *new = NULL;

    if (TreeIsFull(ptT))
    {
        fprintf(stderr, "Max size Tree\n");
        return false;
    }

    if (SearchItemTree(ptT, data))
    {

        fprintf(stderr, "Tree have this item <%s> \n", data.name);
        return false;
    }

    new = (sLeaf *)malloc(sizeof(sLeaf));

    if (new != NULL)
    {
        new->data.age = data.age;
        strcpy(new->data.name, data.name); //warning size
        new->leaf = NULL;
        new->right = NULL;
    }
    else
    {
         fprintf(stderr, "failed data allocate\n");
        return false;
    }

    //allocate is ok
    ptT->size++;

    if(TreeIsEmpty(ptT))
        ptT->root = new; // first leaf
    else

}