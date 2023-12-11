/******************************************************************************
Round Robin scheduler and queue
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    FALSE,
    TRUE
} bool;

struct list
{
    int data;
    struct list *next;
};

struct queue
{
    struct list *tail, *head;
};

typedef struct queue myQ;

void PushQ(int _data, myQ *q);
int PopQ(myQ *q);
bool QisEmpty(myQ *q);
void IntiQ(myQ *q);
void SwhoQ(myQ *q);

myQ taskQueue;
int curr_thread_id; //Текущий поток выполнения, при установке (-1)
int cvant;
int ticks;

void switch_thread();
void scheduler_setup(int timeslice);
void new_thread(int thread_id);
void exit_thread();
void block_thread();
void wake_thread(int thread_id);
void timer_tick();
int current_thread();

int main()
{
    scheduler_setup(1);
    new_thread(1);
    new_thread(2);
    new_thread(3);
    printf("current thread = %d\n", curr_thread_id);

    for (size_t i = 0; i < 5; i++)
    {
        timer_tick();
        printf("current thread = %d\n", curr_thread_id);
    }

    for (size_t i = 0; i < 5; i++)
    {
        timer_tick();
        block_thread();
        printf("current thread = %d\n", curr_thread_id);
    }

    wake_thread(1);
    wake_thread(2);
    wake_thread(3);

    for (size_t i = 0; i < 5; i++)
    {
        timer_tick();
        printf("current thread = %d\n", curr_thread_id);
    }

    exit_thread();

    for (size_t i = 0; i < 5; i++)
    {
        timer_tick();
        printf("current thread = %d\n", curr_thread_id);
    }

    return 0;
}

void switch_thread()
{
    ticks = 0;

    if (QisEmpty(&taskQueue))
        curr_thread_id = -1; //Потоков на выполнение нет
    else
        curr_thread_id = PopQ(&taskQueue);
}

/**
 * Функция будет вызвана перед каждым тестом, если вы
 * используете глобальные и/или статические переменные
 * не полагайтесь на то, что они заполнены 0 - в них
 * могут храниться значения оставшиеся от предыдущих
 * тестов.
 *
 * timeslice - квант времени, который нужно использовать.
 * Поток смещается с CPU, если пока он занимал CPU функция
 * timer_tick была вызвана timeslice раз.
 **/
void scheduler_setup(int timeslice)
{
    IntiQ(&taskQueue);
    cvant = timeslice;   //Используемый квант времени
    ticks = 0;           //Сбросим счётчик тиков
    curr_thread_id = -1; //пока не создано ни одного потока
}

/**
 * Функция вызывается, когда создается новый поток управления.
 * thread_id - идентификатор этого потока и гарантируется, что
 * никакие два потока не могут иметь одинаковый идентификатор.
 **/
void new_thread(int thread_id)
{
    if (curr_thread_id == -1)
    {
        curr_thread_id = thread_id;
    }
    else
    {
        PushQ(thread_id, &taskQueue);
    }
}

/**
 * Функция вызывается, когда поток, исполняющийся на CPU,
 * завершается. Завершится может только поток, который сейчас
 * исполняется, поэтому thread_id не передается. CPU должен
 * быть отдан другому потоку, если есть активный
 * (незаблокированный и незавершившийся) поток.
 **/
void exit_thread()
{
    switch_thread();
}

/**
 * Функция вызывается, когда поток, исполняющийся на CPU,
 * блокируется. Заблокироваться может только поток, который
 * сейчас исполняется, поэтому thread_id не передается. CPU
 * должен быть отдан другому активному потоку, если таковой
 * имеется.
 **/
void block_thread()
{
    switch_thread();
}

/**
 * Функция вызывается, когда один из заблокированных потоков
 * разблокируется. Гарантируется, что thread_id - идентификатор
 * ранее заблокированного потока.
 **/
void wake_thread(int thread_id)
{
    if (curr_thread_id == -1)
    {
        curr_thread_id = thread_id;
    }
    else
    {
        PushQ(thread_id, &taskQueue);
    }
}

/**
 * Ваш таймер. Вызывается каждый раз, когда проходит единица
 * времени.
 **/
void timer_tick()
{

    if (curr_thread_id == -1)
        return;

    ticks++;

    if (ticks >= cvant)
    {
        ticks = 0;
        PushQ(curr_thread_id, &taskQueue);
        switch_thread();
    }
}

/**
 * Функция должна возвращать идентификатор потока, который в
 * данный момент занимает CPU, или -1 если такого потока нет.
 * Единственная ситуация, когда функция может вернуть -1, это
 * когда нет ни одного активного потока (все созданные потоки
 * либо уже завершены, либо заблокированы).
 **/
int current_thread()
{
    return curr_thread_id;
}

/**
 * @brief Функция добавляет данные в конец(Хвост очереди)
 *
 * @param data - данные в очередь
 * @param q - указатель на очерь
 */
void PushQ(int _data, myQ *q)
{
    struct list *temp = NULL;

    if (QisEmpty(q)) //Очедь пуста
    {
        IntiQ(q);
        /* При добавлении первого элемена голова и хвост указывают на одно и тоже */
        q->tail = q->head = (struct list *)malloc(sizeof(struct list));
        // TODO:Тут должна быть проверка на NULL
        q->tail->data = _data; //Вставим данные
        q->tail->next = NULL;  //Следующи указатель должен быть NULL
    }
    else
    {
        struct list *tmp = NULL;

        tmp = (struct list *)malloc(sizeof(struct list));
        // TODO:проверка на выделение
        q->tail->next = tmp; // Следующий пустой элемент "в хвосте" получает адрес выделенной памяти
        tmp->next = NULL;    // Следующий элемент за созданным указывает на null
        tmp->data = _data;   // Загрузим данные в наш элемент
        q->tail = tmp;       // И хвост теперь указывает на последний элемент

        /* Если работали бы как со стеком, то передвали бы верхушку и "на ней" определяли новые данные*/

        /* Такая конструкция больше подходит для head?
        while(q->tail->next != NULL)
        {
            q->tail = q->tail->next;
        }
        q->tail->next = (struct list *)malloc(sizeof(struct list));
        //TODO:проверка на выделение
        q->tail->next->data = _data;
        q->tail->next->next = NULL;
        */
    }
}

/**
 * @brief Функция возращеет true, если очередь пуста
 *
 * @param q - указатель на очерь
 * @return true
 * @return false
 */
bool QisEmpty(myQ *q)
{
    if (q->head == NULL)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief Функция инициализирует "указатели хвоста и голвы" значением NULL
 *
 * @param q
 */
void IntiQ(myQ *q)
{
    q->tail = q->head = NULL;
}

/**
 * @brief Функция выводит все значения в очереди
 *   Это эфермный пример, адреса с потолка
        HEAD(q.head = 0x9A0)
        n0{
            d = 10
            next_ptr = 0x9B0
        }
            step1 q.head = q.head->next_ptr
                HEAD(q.head = 0x9B0)
                    n0{
                    d = 20
                    next_ptr = 0x9C0
                }
                    step2 q.head = q.head->next_ptr
                    HEAD(q.head = 0x9C0)
                     n0{
                     d = 30
                     next_ptr = 0x9D0
                    }
 * @param q - указатель на структуру типа myQ
 */
void SwhoQ(myQ *q)
{
    unsigned int number = 0;      //Счётчик индекс показывающий номер эл-та с головы
    struct list *showq = q->head; //Временная переменная чтобы не трогать Head указатель

    if (QisEmpty(q))
        printf("Queue is empty\n");
    else
    {
        while (showq != NULL)
        {
            printf("[%d] element in queue : %d. next address: %p\n", number++, showq->data, showq->next);
            showq = showq->next; //Переставим указатель на следующий элемнт
        }
    }
}

/**
 * @brief Удаляет из очереди элемент находящийся
 *
 *
 * @param q - указатель на структуру типа myQ
 */
int PopQ(myQ *q)
{
    struct list *temp = NULL;
    int _data = 0;

    if (QisEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = q->head; // Временное хранение головного элемента
        _data = temp->data;
        q->head = q->head->next; // Переставим указатель "Головы" на следующий элемент
        free(temp);              // Освободим память
    }

    return _data;
}
