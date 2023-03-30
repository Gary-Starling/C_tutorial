#include "RingBuff.h"

static void ClearRingBuff(sRingBuff * buff);

/** Очистка буфера, установка указателей в исходное положение 
sRingBuff * buff - указатель на используемую структуру данных
*/
void InitRingBuff(sRingBuff * buff)
{
  ClearRingBuff(buff);
  buff->head = buff->tail = buff->data; //Поставим указатели в начало буфера
}


/** Очистка буфера
sRingBuff * buff - указатель на используемую структуру данных
*/
static void ClearRingBuff(sRingBuff * buff)
{                                     
  for(uint32_t i = 0; i < (sizeof(buff->data)/sizeof(data_type)); i++)
    buff->data[i] = 0x00;
}

/** Функция чтения количества непрочитанных данных
sRingBuff * buff - указатель на используемую структуру данных
return uint32_t количество непрочитанных данных
*/
uint32_t UnreadDataBuff(sRingBuff * buff)
{
  return (uint32_t)((RING_BUFF_LEN + buff->tail - buff->head) %  RING_BUFF_LEN);
}


/* Если используем побайтный приём */
#ifdef _INTERRUPT_
/** Вставка данных в кольцевой буфер (При вставке перемещает ptr Tail)   
sRingBuff * buff - указатель на используемую структуру данных
*/
void PutRingData(sRingBuff * buff, data_type data)
{  
  /* Защита от переполнения, забегание хвоста за голову */
  if( UnreadDataBuff(buff) >= (RING_BUFF_LEN - 1) )
    return;
  
  *(buff->tail++) = data;                             //Присвоим data в буфер и сдвинем указатель
  
  if((buff->tail) > &(buff->data[RING_BUFF_LEN - 1])) //Если указываем на адрес за пределом буфера
    buff->tail = &(buff->data[0]);                    //Перейдём к началу
/* dma + idle_it
  note: idle может сработать и в середине сообщения поэтому нам нужен какой-либо
  символ для конца сообщения '\n' \0' и т.п. 
  */

}
#else
void PutRingData(sRingBuff * buff)
{
  buff->tail = &buff->data[(RING_BUFF_LEN - 1) - DMA1_Stream1->NDTR];
}
#endif


/** 
Чтение данных из буфера (При чтении перемещается ptr Head)
sRingBuff * buff - указатель на используемую структуру данных
return data_type - прочитанный элемент
*/
data_type ReadRingData(sRingBuff * buff)
{
  data_type data = *(buff->head);                        //Прочтём данные
  
  buff->head++;                                         //Передвинем указатель
  if((buff->head) > &(buff->data[RING_BUFF_LEN - 1]))   //Перейдём к началу
    buff->head = &(buff->data[0]); 
  
  return data;
}

