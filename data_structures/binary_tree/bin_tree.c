#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bin_tree.h"

int main(int argc, char const *argv[])
{
    Tree tree;

    
    InitTree(&tree);
    
    printf("elements in tree = %d \n", ItemСntTree(&tree));

    AddItemTree(&tree, 50);
    AddItemTree(&tree, 40);
    AddItemTree(&tree, 60);
    AddItemTree(&tree, 30);
    AddItemTree(&tree, 20);
    AddItemTree(&tree, 10);
    AddItemTree(&tree, 32);

    printf("elements in tree = %d \n", ItemСntTree(&tree));

    if(IsBinary(tree.root))
        printf("Is binary tree\n");

    printTree(tree.root);

    if(SearchItemTree(tree.root, 30))
        printf("30 in tree\n");
    
    if(SearchItemTree(tree.root, 20))
        printf("20 in tree\n");
    
    if(SearchItemTree(tree.root, 10))
        printf("10 in tree\n");
    
    if(SearchItemTree(tree.root, 22))
        printf("22 in tree\n");

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


int ItemСntTree(const Tree * ptT)
{
    return ptT->size;
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

void printTree(Sleaf * root)
{
    if(root)
    {
        printf("%d \n", root->value);
        printTree(root->left);
        printTree(root->right);
    }
}


bool SearchItemTree(Sleaf * root, const int val)
{   

    if(root)
    {
        if(root->value == val)
            return true;
        else if(val < root->value)
            SearchItemTree(root->left, val);
        else if(val > root->value)
            SearchItemTree(root->right, val);
    }
    else
        return false;

}



bool AddItemTree(Tree *ptT, const int val)
{
    Sleaf *new = NULL;

    if (TreeIsFull(ptT))
    {
        fprintf(stderr, "Max size Tree\n");
        return false;
    }

    //if (SearchItemTree(ptT, val))
    //{
    //    fprintf(stderr, "Tree have this item <%s> \n", val);
    //    return false;
    //}

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