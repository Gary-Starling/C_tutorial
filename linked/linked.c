#include <stdio.h>
#include <stdlib.h>

struct listN *ptrlst = NULL;
struct listN *StartPtr = NULL;

struct listN
{
    char data;
    struct listN *next;
};

struct listN *init(char a)
{
    struct listN *lst;

    lst = (struct listN *)malloc(sizeof(struct listN));

    if (lst != NULL)
    {
        lst->data = a;
        lst->next = NULL;
        return lst;
    }
    else
        return NULL;
}

struct listN *addelem(struct listN *lst, char number)
{
    struct listN *new, *temp;

    new = (struct listN *)malloc(sizeof(struct listN));
    temp = lst->next; // save ptr
    lst->next = new;
    new->data = number;
    new->next = temp;
    return new;
}

struct listN *deletelem(struct listN *lst, struct listN *root)
{
    struct listN *temp = root;

    while (temp->next != lst) /* look all litst*/
        temp = temp->next;    /* until we find the node preceding lst */

    temp->next = lst->next; /* let's rearrange */
    free(lst);              /* free memory node*/
    return (temp);
}

void listprint(struct listN *lst)
{
    struct listN *p = lst;
    do
    {
        printf("%c ", p->data); 
        p = p->next;            
    } while (p != NULL);
}

int main(int argc, char const *argv[])
{
    struct listN *ptrlst = NULL;

    StartPtr = init('a');
    ptrlst = StartPtr;
    ptrlst = addelem(ptrlst, 'b');
    ptrlst = addelem(ptrlst, 'c');
    ptrlst = addelem(ptrlst, 'd');
    ptrlst = addelem(ptrlst, 'e');
    ptrlst = addelem(ptrlst, 'f');
    ptrlst = addelem(ptrlst, 'g');
    deletelem(ptrlst, StartPtr);

    listprint(StartPtr);

    return 0;
}
