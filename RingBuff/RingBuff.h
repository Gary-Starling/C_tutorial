#ifndef _RING_BUFF_
#define _RING_BUFF_

/* Интерефейс кольцевого буфера для UART */

#include "stdint.h"

/* Настройки */
#define RING_BUFF_LEN	(128U) 	          //Размер буфера
#define _DMA_                             //_DMA_ or _INTERRUPT_ 
typedef uint8_t data_type;                //тип данных в буфере
/* Настройки */

typedef struct {
        data_type * head;                 //Указатель на "головной" элемент
	data_type * tail;                 //Хвост
	data_type   data[RING_BUFF_LEN];  //Кольцевой буфер
}sRingBuff;

/* Функция заполняет нулями весь буфер и устанавливает указаетели в исходное положение */
void InitRingBuff(sRingBuff * buff);

/* Наличие данных в буфере */
uint32_t UnreadDataBuff(sRingBuff * buff);

/* Запись данных в буфер */
#ifdef _INTERRUPT_
void PutRingData(sRingBuff * buff, data_type data);
#else
void PutRingData(sRingBuff * buff);
#endif

/* Чтение данных из буфера */
uint8_t ReadRingData(sRingBuff * buff);

#endif