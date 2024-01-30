#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/* Init list */
void InitList(List *ptrList) //(Node ** ptrList)
{
  *ptrList = NULL;
}

/* check empty list */
bool ListIsEmpty(const List *ptrList)
{
  if (*ptrList == NULL)
    return true;

  return false;
}

/* item count */
unsigned int ListItemCnt(const List *ptrList)
{
  unsigned int cnt = 0;
  Node *ptrNode = *ptrList; // set in start

  while (ptrNode != NULL)
  {
    cnt++;
    ptrNode = ptrNode->next;
  }

  return cnt;
}

/*
Add item
return result true = ok, false = error
*/
bool AddItem(propert item, List *ptrList)
{
  Node *new;
  Node *search = *ptrList;

  new = (Node *)malloc(sizeof(Node));

  if (new == NULL)
    return false;
  else
  {
    new->next = NULL;
    new->film = item;
    if (search == NULL)
      *ptrList = new;
    else
    {
      while (search->next != NULL)
        search = search->next;

      search->next = new;
    }
  }

  return true;
}

/*
free alloc memory
*/
void CleanList(List *ptrList) //Node **ptrList
{
  Node *temp;

  while (*ptrList != NULL)
  {
    temp = *ptrList;
    *ptrList = (*ptrList)->next;
    free(temp);
  }
}

/* show items of list */
void ItemShow(const List *ptrList)
{
  Node *tmp = *ptrList;

  while (tmp != NULL)
  {
    printf("Movie: %s\n", tmp->film.name);
    tmp = tmp->next;
  }
}






int main(int argc, char const *argv[])
{
  List LibMovies; //like a (Node *LibMovies)
  propert tmp;

  // Init
  InitList(&LibMovies);

  puts("Enter name film:");

  while (gets(tmp.name) != NULL && tmp.name[0] != '\0')
  {
    puts("enter rating of film from <0 to 5>:");
    scanf("%d", &tmp.rating);
    while(getchar() != '\n');
    if(AddItem(tmp, &LibMovies) != true)
    {
      puts("Error memory allocate");
      exit(1);
    }
    else
      puts("Enter name next film or emty string to exit");
  }

  if(ListIsEmpty(&LibMovies))
  {
    puts("No data");
    exit(0);
  }
  else
    ItemShow(&LibMovies);

  CleanList(&LibMovies);  

}
