#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bin_tree.h"

int main(int argc, char const *argv[])
{
    Tree tree;
    printf("%p\n",&tree);
    printf("%p\n",tree.root);

    InitTree(&tree);
    AddItemTree(&tree, 10);
    AddItemTree(&tree, 20);
    AddItemTree(&tree, 30);
    AddItemTree(&tree, 27);

    if(IsBinary(tree.root))
        printf("Is binary tree\n");

    printf("%p\n",&tree);
    printf("%p\n",tree.root);

    return 0;
}

void InitTree(Tree *ptT)
{
    ptT->root = NULL;
    ptT->size = 0;
}

bool TreeIsEmpty(const Tree *ptT)
{
    return ptT->root == NULL;
}

bool TreeIsFull(const Tree *ptT)
{
    return ptT->size == MAX_SIZE;
}

bool Toleft(int val1, int val2)
{
    if (val1 < val2)
        return true;
    else
        return false;
}

bool ToRight(int val1, int val2)
{
    if (val1 > val2)
        return true;
    else
        return false;
}

void AddNode(Sleaf *new, Sleaf *root)
{
    if (Toleft(new->value, root->value))
    {
        if (root->left == NULL)
            root->left = new;
        else
            AddNode(new, root->left);
    }
    else if (ToRight(new->value, root->value))
    {
        if (root->right == NULL)
            root->right = new;
        else
            AddNode(new, root->right);
    }
    else
    {
        fprintf(stderr, "Error duplicate value in tree");
        exit(1);
    }
}

bool IsBinary(Sleaf * root)
{
    if(!root || (!root->right && !root->right)) 
        return true;
    if(root->left && (root->left->value >= root->value))
        return false;
    if(root->right && (root->right->value <= root->value))
        return false;
    return (IsBinary(root->left) && IsBinary(root->right));
}


bool AddItemTree(Tree *ptT, const int val)
{
    Sleaf *new = NULL;

    if (TreeIsFull(ptT))
    {
        fprintf(stderr, "Max size Tree\n");
        return false;
    }
    /*
    if (SearchItemTree(ptT, data))
    {

        fprintf(stderr, "Tree have this item <%s> \n", data.name);
        return false;
    }
    */

    new = (Sleaf *)malloc(sizeof(Sleaf));

    if (new != NULL)
    {
        new->left = NULL; // left and right ptr to NULL
        new->right = NULL;
        new->value = val; // write val into tree
        ptT->size++;      // inc tree counter

        if (ptT->root == NULL) // tree was empty
            ptT->root = new;
        else
        {
            AddNode(new, ptT->root); // add leaf to tree
        }
    }
    else
    {
        fprintf(stderr, "failed data allocate\n");
        return false;
    }

    return true;
    /*
    if(TreeIsEmpty(ptT))
        ptT->root = new; // first leaf
    */
}