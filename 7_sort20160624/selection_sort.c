/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : selection_sort.c
* Version      : v1.0.0
* Author       : 初代
* Date         : 2016/06/24
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

void selection_sort(poperation data)
{
    int     i = 0;
    int     j = 0;
    int     *temp_array = NULL; //为了不改变原数据,新开一个数组
    int     num = data->num;
    int     tempvalue = 0;
    int     smallest = 0;

    if (data->array == NULL || data->num <= 0)
    {
         printf("数据数组不存在!\n");
         return;
    }

    temp_array = (int*)malloc(sizeof(int) * num);
    if (temp_array == NULL)
    {
         printf("malloc temp array error!\n");
         return;
    }

    for (i = 0; i < num; i++)
    {
         temp_array[i] = data->array[i];
    }

    for (i = 0; i < num; i++)
    {
         smallest = i;
         for (j = i; j < num; j++)
         {
             if (temp_array[j] < temp_array[smallest])
             {
                 //找最小
                 smallest = j;
             }
         }
         //交换
         tempvalue = temp_array[smallest];
         temp_array[smallest] = temp_array[i];
         temp_array[i] = tempvalue;
//         printf("samllest = %d\n", temp_array[i]);
    }

    output_array(temp_array, num);

    free(temp_array);
}



