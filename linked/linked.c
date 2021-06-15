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

    //Выделим память
    lst = (struct listN *)malloc(sizeof(struct listN));

    if (lst != NULL)
    {
        lst->data = a;
        lst->next = NULL; //Последний указатель списка

        return lst;
    }
    else
        return NULL;
}

struct listN *addelem(struct listN *lst, char number)
{

    struct listN *new, *temp;
    new = (struct listN *)malloc(sizeof(struct listN));
    temp = lst->next;   // сохранение указателя на следующий узел
    lst->next = new;    // предыдущий узел привязали к новому
    new->data = number; // сохранение поля данных добавляемого узла
    new->next = temp;   // созданный узел указывает на следующий элемент
    return (new);
}

struct listN *deletelem(struct listN *lst, struct listN *root)
{
    struct listN *temp;

    temp = root;

    while (temp->next != lst) // просматриваем список начиная с корня
    {                         // пока не найдем узел, предшествующий lst
        temp = temp->next;
    }
    temp->next = lst->next; // переставляем указатель
    free(lst);              // освобождаем память удаляемого узла
    return (temp);
}

void listprint(struct listN *lst)
{
    struct listN *p;
    p = lst;
    do
    {
        printf("%c ", p->data); // вывод значения элемента p
        p = p->next;            // переход к следующему узлу
    } while (p != NULL);
}

int main(int argc, char const *argv[])
{
    struct listN *ptrlst = NULL;

    StartPtr = init('a'); //Инит нашего списка
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
