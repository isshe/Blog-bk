/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : pqarray.c
* Version      : v1.0.0
* Author       : 初代
* Date         : 2016/06/22
* Description  :
* Function list: 1.
*                2.
*                3.
* History      :
\*=========================================================================*/

/*-----------------------------------------------------------*
 * 头文件                                                    *
 *-----------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pqarray.h"

/*-----------------------------------------------------------*
 * 外部变量说明                                              *
 *-----------------------------------------------------------*/

/*-----------------------------------------------------------*
 * 外部函数原型说明                                          *
 *-----------------------------------------------------------*/

/*-----------------------------------------------------------*
 * 内部函数原型说明                                          *
 *-----------------------------------------------------------*/

/*-----------------------------------------------------------*
 * 全局变量                                                  *
 *-----------------------------------------------------------*/

/*-----------------------------------------------------------*
 * 模块级变量                                                *
 *-----------------------------------------------------------*/

/*-----------------------------------------------------------*
 * 常量定义                                                  *
 *-----------------------------------------------------------*/

/*-----------------------------------------------------------*
 * 宏定义                                                    *
 *-----------------------------------------------------------*/

/*-----------------------------------------------------------*
 * 函数实现                                                  *
 *-----------------------------------------------------------*/


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/22
* Others     (其他):
\*=======================================================================*/
ppqueue_s create_queue(int capacity)
{
     ppqueue_s  temp = NULL;

     temp = (ppqueue_s)malloc(sizeof(pqueue_s));
     if (temp == NULL)
     {
          printf("malloc error!\n");
          return NULL;
     }

     //多一个是因为从1开始,0的位置没有用!
     temp->array = (int *)malloc(sizeof(int) * (capacity+1));
     if (temp->array == NULL)
     {
          printf("malloc error!\n");
          return NULL;
     }

//     memset(temp->array, 0, sizeof(int) * capacity);
//     temp->capacity = capacity;
//     temp->size = 0;

     return temp;
}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/22
* Others     (其他): 这里构造的是最小堆
\*=======================================================================*/
int insert_data(ppqueue_s queue, int value)
{
     int    i = queue->size + 1;        //当前空闲位置

     if (i == queue->capacity + 1)      //从0开始,已经不能再插入了
     {
         printf("队列满!\n");
         return -1;
     }

     while(queue->array[i/2] > value)
     {
          queue->array[i] = queue->array[i/2];
          queue->array[i/2] = -1;
          i = (int)i / 2;
     }
     queue->array[i] = value;
     printf("array[%d] = %d\n", i, queue->array[i]);
     queue->size++;
     return 0;
}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/22
* Others     (其他):
\*=======================================================================*/
int delete_min(ppqueue_s queue)
{
    int delete_value = queue->array[1];     //注意是1!
    int i = 1;

    while(i * 2 < queue->size)
    {
        if (queue->array[2 * i] <= queue->array[2 * i + 1])
        {
            queue->array[i] = queue->array[2 * i];
            i = 2 * i;
        }
        else
        {
             queue->array[i] = queue->array[2 * i + 1];
             i = 2 * i + 1;
        }
    }

    queue->array[i] = queue->array[queue->size];
    queue->array[queue->size] = INITVALUE;      //
    queue->size--;

    return delete_value;

}

/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/22
* Others     (其他):
\*=======================================================================*/
void output_queue(ppqueue_s queue)
{
     int    i = 0;

     //note!!!
     for (i = 1; i <= queue->size; i++)
     {
         printf("%d ", queue->array[i]);
     }

     printf("\n");
}