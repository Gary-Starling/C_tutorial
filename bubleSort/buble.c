

/******************************************************************************
Требуется в произвольной строке удалить последнее слово, т.е. 
все символы после последнего пробела в строке. Если в строке одно слово,
но после него стоит пробел, то результатом должна являться пустая строка.
Если в строке одно слово и после него пробела нет, то результатом должна являться строка равная исходной.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Работаем над выводом пробел пустая строка 
пример
test<space>bb неправильно
а test<space>правильно*/
char test1[]="aa";
char test2[]="aa ";
char test3[]="aa bb";
char test4[]="aa bb cc";
//char str[100] = "test aa";

char *remove_last_word(char *input);

int main()
{
  printf("-------\n");
  printf("input : %s\n", test1);
  printf("%s\n", remove_last_word(test1));
  printf("-------\n");
  printf("-------\n");
  printf("input : %s\n", test2);
  printf("%s\n", remove_last_word(test2));
  printf("-------\n");
  printf("-------\n");
  printf("input : %s\n", test3);
  printf("%s\n", remove_last_word(test3));
  printf("-------\n");
  printf("-------\n");
  printf("input : %s\n", test4);
  printf("%s\n", remove_last_word(test4));
  printf("-------\n");

  return 0;
}

char *remove_last_word(char *input)
{
    char *adr_space = NULL;  //для strrchr
    char *out = NULL;   //для вывода
    int space_cnt = 0;
    int word_len = 0;
    
    word_len = strlen(input); //Сколько символов в строке
    
    adr_space = strrchr(input, ' ');    //ищем с хвоста ' '
    
    /* Пробелов нет, выводим исходную строку */
    if(adr_space == NULL)
    { 
     out = (char *)malloc(sizeof(char) * (word_len+1));
     for (int i = 0; i < word_len; i++) //+1 т.к. нуль символ
       out[i] = input[i];
     out[word_len] = '\0'; 
     return out;
    }
    else
    {
     /* Если в строке одно слово и после него пробел */
     if(input[word_len-1] == *adr_space)//word_len-1 т.к. массив с 0
     {
      out = (char *)malloc(sizeof(char));
      *out = '\0';
      return out;
     }/* Обычный случай, когда нужно только удлить последнее слово */
     else
     {
      word_len = adr_space - input; //Посчитаем количество копируемых символов
      out = (char *)malloc(sizeof(char) * (word_len+2));
      for (int i = 0; i < word_len; i++) //+1 т.к. пробел
       out[i] = input[i];
      out[word_len] = '\0'; 
      return out;
     }
    }
    
 return input; //Мы не должны сюда дойти
}




