/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : merge_sort.c
* Version      : v1.0.0
* Author       : 初代
* Date         : 2016/06/25
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
#include <stdlib.h>
#include <string.h>
#include "operation.h"

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
* Date       (日期): 2016/06/25
* Others     (其他): 合并
\*=======================================================================*/
void merge(int *array, int front, int rear, int *dst_array)
{
    int a = front;
    int b = (front + rear) / 2;
    int x = b + 1;
    int y = rear;
    int i = front;

    while(a <= b || x <= y)
    {
         if (x > y || (a <= b && array[a] < array[x]))      //这一句是最关键的!是精华!
         {
             dst_array[i++] = array[a++];
         }
         else
         {
              dst_array[i++] = array[x++];
         }
    }

    //
    for (i = front; i <= rear; i++)
    {
         array[i] = dst_array[i];
    }
}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/25
* Others     (其他): 归并排序主体
\*=======================================================================*/
void merge_sort(int *array, int front, int rear, int *dst_array)
{
     int    mid = 0;

     if (front >= rear)
     {
          return;
     }

     mid = (front + rear) / 2;

     merge_sort(array, front, mid, dst_array);
     merge_sort(array, mid + 1, rear, dst_array);
     merge(array, front, rear, dst_array);
}