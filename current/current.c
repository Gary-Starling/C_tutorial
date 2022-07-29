#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_NAME 30

struct film_info
{
        char name[LEN_NAME];
        unsigned int year;
        struct film_info *next;
};

typedef struct film_info link_data;

int main(int argc, char const *argv[])
{
        link_data *head = NULL;
        link_data *curr, *tmp;
        char input_name[LEN_NAME] = {0};


        puts("Enter name film:");

        while (gets(input_name) != NULL && input_name[0] != '\0')
        {
                tmp = (link_data *)malloc(sizeof(link_data)); // new elem
                tmp->next = NULL;
                
                curr = tmp;


                if (head == NULL)
                 head = tmp;

                strcpy(curr->name, input_name);
                puts("Enter year film:");
                scanf("%d", &curr->year);
                while (getchar() != '\n')
                        continue;
                puts("Next or if you need exit press only enter");
        }

        printf("Pirnt library\n");

        while (head != NULL)
        {
                printf("Name film : %s\n", head->name);
                printf("Data of film: %d\n", head->year);
                head = head->next;
        }

        return 0;
}
