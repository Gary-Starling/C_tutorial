#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* */
enum move_dir
{
    MD_UP,
    MD_RIGHT,
    MD_DOWN,
    MD_LEFT,
    MD_NONE
};

// Определите тип обработчика событий move_callback с помощью typedef
typedef void (*move_callback)(enum move_dir move);

// структура связного списка для callbakОВ
struct node
{
    void (*move_callback)(enum move_dir move);
    struct node *next;
};

// Робот и его callback'и
// callback'ов может быть неограниченное количество
struct robot
{
    const char *name;
    struct node *list_callbacks;
};

struct node *node_create(void (*fptr)(enum move_dir move))
{
    struct node *tmp = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));

    if (tmp)
    {
        tmp->move_callback = fptr;
        tmp->next = NULL;
    }

    return tmp;
}

void list_destroy(struct node *list)
{
    struct node *tmp = list;

    while (tmp)
    {
        list = list->next;
        free(tmp);
        tmp = list;
    }
}

void list_add_front(struct node **old, void (*fptr)(enum move_dir move))
{
    struct node *tmp = node_create(fptr);
    if (tmp)
    {
        if (*old != NULL)
        {
            tmp->next = *old;
            *old = tmp;
        }
        else
        {
            *old = tmp;
        }
    }
}

// Добавить callback к роботу, чтобы он вызывался при движении
// В callback будет передаваться направление движения
void register_callback(struct robot *robot, move_callback new_cb)
{
    list_add_front(&robot->list_callbacks, new_cb);
}

// Отменить все подписки на события.
// Это нужно чтобы освободить зарезервированные ресурсы
// например, выделенную в куче память
void unregister_all_callbacks(struct robot *robot)
{
    list_destroy(robot->list_callbacks);
    robot->list_callbacks = NULL;
}

// Вызывается когда робот движется
// Эта функция должна вызвать все обработчики событий
void move(struct robot *robot, enum move_dir dir)
{
    struct node *tmp = (struct node *)robot->list_callbacks;
    if (robot->list_callbacks != NULL)
    {
        while (tmp)
        {
            tmp->move_callback(dir);
            tmp = tmp->next;
        }
    }
}

struct robot my_robot = {
    .name = "robot",
    .list_callbacks = NULL};

void left(enum move_dir move)
{
    printf("move left enum = %d\n", move);
}

void right(enum move_dir move)
{
    printf("move right enum = %d\n", move);
}

int main(int argc, char const *argv[])
{
    register_callback(&my_robot, left);
    register_callback(&my_robot, right);
    move(&my_robot, MD_UP);
    move(&my_robot, MD_DOWN);
    move(&my_robot, MD_LEFT);
    move(&my_robot, MD_RIGHT);
    move(&my_robot, MD_NONE);
    unregister_all_callbacks(&my_robot);
    return 0;
}
