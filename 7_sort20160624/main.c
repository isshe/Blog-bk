/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : main.c
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

int main(void)
{
    int         option = 0;
    poperation  data = NULL;
    int         *dst_array;
    int         *temp_array;
    int         i = 0;

    data = create_array();

    while(1)
    {
        printf("\r1.选择排序\n"
                "\r2.插入排序\n"
                "\r3.归并排序\n"
                "\r4.快速排序\n"
                "\r5.冒泡排序\n"
                "\r8.打印数据\n"
                "\r9.退出程序\n");
        scanf("%d\n", &option);
        switch(option)
        {
            case 1:
                printf("选择排序结果: ");
                selection_sort(data);
                break;
            case 2:
                printf("插入排序结果: ");
                insertion_sort(data);
                break;
            case 3:
                dst_array = (int *)malloc(sizeof(int) * data->num);
                if (dst_array == NULL)
                {
                    printf("dst array malloc error!\n");
                    break;
                }
                 temp_array = (int *)malloc(sizeof(int) * data->num);
                if (temp_array == NULL)
                {
                    printf("merge temp array malloc error!\n");
                    break;
                }

                for (i = 0; i < data->num; i++)
                {
                     temp_array[i] = data->array[i];
                }

                printf("归并排序结果: ");
                merge_sort(temp_array, 0, data->num-1, dst_array);
                output_array(dst_array, data->num);
                free(dst_array);
                dst_array = NULL;
                free(temp_array);
                dst_array = NULL;
                break;
            case 4:
                temp_array = (int *)malloc(sizeof(int) * data->num);
                if (temp_array == NULL)
                {
                    printf("quick sort temp array malloc error!\n");
                    break;
                }
                for (i = 0; i < data->num; i++)
                {
                     temp_array[i] = data->array[i];
                }
                printf("快速排序结果: ");
                quick_sort(temp_array, 0, data->num - 1);
                output_array(temp_array, data->num);
                free(temp_array);
                temp_array = NULL;
                break;
            case 5:
                 temp_array = (int *)malloc(sizeof(int) * data->num);
                if (temp_array == NULL)
                {
                    printf("quick sort temp array malloc error!\n");
                    break;
                }
                for (i = 0; i < data->num; i++)
                {
                     temp_array[i] = data->array[i];
                }
                printf("冒泡排序结果: ");
                bubble_sort(temp_array, data->num);
                output_array(temp_array, data->num);
                free(temp_array);
               break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                output_array(data->array, data->num);
                break;
            case 9:
                exit(0);
            default:
                break;
        }
    }
}
