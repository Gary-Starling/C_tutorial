#include <stdio.h>
#include <stdlib.h>
#include "current.h"

// #define LEN_NAME 30 //Размер имени фильма

// typedef struct film_info
// {
//   char name[LEN_NAME];
//   unsigned int rating;
//   struct film_info *next;
// } link_data;



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

  // link_data *head = NULL, *tmp = NULL, *current = NULL;
  // char input_name[LEN_NAME] = {0};

  // puts("Enter name film:");

  // while (gets(input_name) != NULL && input_name[0] != '\0')
  // {
  //   /*create new node*/
  //   tmp = (link_data *)malloc(sizeof(link_data)); // alloc memory
  //   tmp->next = NULL;
  //   /*create new node*/

  //   /*input data*/
  //   strcpy(tmp->name, input_name);
  //   puts("Enter rating this film from 0 to 5");
  //   scanf("%d", &tmp->rating);
  //   while (getchar() != '\n')
  //     ;
  //   /*input data*/

  //   if (head == NULL)
  //     head = tmp; // first alloc
  //   else
  //     current->next = tmp; // current node link to next(created)

  //   current = tmp; // change current ptr on next node

  //   puts("Enter next film or EOF | empty string to end");
  // }

  // printf("Pirnt library\n");

  // current = head;
  // while (current != NULL)
  // {
  //   printf("Name film : %s\n", current->name);
  //   printf("Rating film : %d\n", current->rating);
  //   current = current->next;
  // }

  // current = head;
  // while (current != NULL)
  // {
  //   tmp = current;
  //   current = current->next;
  //   free(tmp);
  // }

  // puts("End.");
  // exit(0);

  // return 0;
}
