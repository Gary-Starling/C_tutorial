#include "RingBuff.h"

static void ClearRingBuff(sRingBuff * buff);

/** ������� ������, ��������� ���������� � �������� ��������� 
sRingBuff * buff - ��������� �� ������������ ��������� ������
*/
void InitRingBuff(sRingBuff * buff)
{
  ClearRingBuff(buff);
  buff->head = buff->tail = buff->data; //�������� ��������� � ������ ������
}


/** ������� ������
sRingBuff * buff - ��������� �� ������������ ��������� ������
*/
static void ClearRingBuff(sRingBuff * buff)
{                                     
  for(uint32_t i = 0; i < (sizeof(buff->data)/sizeof(data_type)); i++)
    buff->data[i] = 0x00;
}

/** ������� ������ ���������� ������������� ������
sRingBuff * buff - ��������� �� ������������ ��������� ������
return uint32_t ���������� ������������� ������
*/
uint32_t UnreadDataBuff(sRingBuff * buff)
{
  return (uint32_t)((RING_BUFF_LEN + buff->tail - buff->head) %  RING_BUFF_LEN);
}


/* ���� ���������� ��������� ���� */
#ifdef _INTERRUPT_
/** ������� ������ � ��������� ����� (��� ������� ���������� ptr Tail)   
sRingBuff * buff - ��������� �� ������������ ��������� ������
*/
void PutRingData(sRingBuff * buff, data_type data)
{  
  /* ������ �� ������������, ��������� ������ �� ������ */
  if( UnreadDataBuff(buff) >= (RING_BUFF_LEN - 1) )
    return;
  
  *(buff->tail++) = data;                             //�������� data � ����� � ������� ���������
  
  if((buff->tail) > &(buff->data[RING_BUFF_LEN - 1])) //���� ��������� �� ����� �� �������� ������
    buff->tail = &(buff->data[0]);                    //������� � ������
/* dma + idle_it
  note: idle ����� ��������� � � �������� ��������� ������� ��� ����� �����-����
  ������ ��� ����� ��������� '\n' \0' � �.�. 
  */

}
#else
void PutRingData(sRingBuff * buff);
{
  sim_buff->tail = &sim_buff.data[(RING_BUFF_LEN - 1) - DMA1_Stream1->NDTR];
}
#endif


/** 
������ ������ �� ������ (��� ������ ������������ ptr Head)
sRingBuff * buff - ��������� �� ������������ ��������� ������
return data_type - ����������� �������
*/
data_type ReadRingData(sRingBuff * buff)
{
  data_type data = *(buff->head);                        //������ ������
  
  buff->head++;                                         //���������� ���������
  if((buff->head) > &(buff->data[RING_BUFF_LEN - 1]))   //������� � ������
    buff->head = &(buff->data[0]); 
  
  return data;
}

