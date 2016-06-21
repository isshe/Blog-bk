/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : linked_lists.c
* Version      : v1.0.0
* Author       : 初代
* Date         : 2016/06/16
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
#include <malloc.h>
#include "linked_lists.h"

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
* Date       (日期): 2016/06/16
* Others     (其他): 表头插入
\*=======================================================================*/
int insert_node(linked_lists **head, int value)
{
     linked_lists *new_node = NULL;

     new_node = (linked_lists *)malloc(sizeof(linked_lists));
     if (new_node == NULL)
     {
         printf("分配节点出错!\n");
         return (-1);
     }

     new_node->value = value;

     //无节点情况
     if (*head == NULL)
     {
         *head = new_node;
         new_node->next_node = NULL;
     }
     else
     {
          new_node->next_node = *head;
          *head = new_node;
     }

     return 0;
}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/16
* Others     (其他):
\*=======================================================================*/
int output_list(linked_lists *head)
{
     linked_lists   *current_node = head;

     if (head == NULL)
     {
         printf("没有元素!\n");
         return 0;
     }

     do
     {
          printf("%d ", current_node->value);
          current_node = current_node->next_node;
     }while(current_node != NULL);

     return 0;
}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/16
* Others     (其他): 获取链表长度
\*=======================================================================*/
int list_size(linked_lists *head)
{
    int             count = 0;
    linked_lists    *current_node = head;

     if (head == NULL)
     {
         count = 0;
     }
     else
     {
         do
         {
              count++;
              current_node = current_node->next_node;
         }while(current_node != NULL);
     }

     return count;
}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/16
* Others     (其他): 获取指定节点位置
\*=======================================================================*/
int get_node(linked_lists *head, int value)
{
    int             count = 0;
    linked_lists    *current_node = head;

    if (head == NULL)
    {
        //空表，无任何节点
         count = 0;
    }
    else
    {
        do
        {
            count++;
            if (current_node->value == value)
            {
                 break;
            }
            current_node = current_node->next_node;
        }while(current_node != NULL);
    }

    if (count != 0 && current_node == NULL)
    {
         count = -1;        //-1代表没找到
    }
    return count;
}



/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/16
* Others     (其他): 删除一个指定值的节点
\*=======================================================================*/
int delete_node(linked_lists **head, int value)
{
     linked_lists   *del_node = NULL;
     linked_lists   *current_node = *head;
     int            ret = 0;

     //先找找看有没有此节点
     if(get_node(*head, value) <= 0)
     {
         ret = -1;
     }
     else
     {
         ret = 0;       //有需要删除的那个节点！
         //首节点
         if (current_node->value == value)
         {
              del_node = current_node;
              *head = (*head)->next_node;
//              ret = 0;
         }
         else
         {
             //中间节点和尾节点
             del_node = current_node->next_node;
             while(del_node != NULL)
             {
                  if (value == del_node->value)
                  {
                      current_node->next_node = del_node->next_node;
//                      ret = 0;
                      break;
                  }
                  else
                  {
                       del_node = del_node->next_node;
                       current_node = current_node->next_node;
                  }
             }
         }
     }
     //free!remember!
     if (ret == 0)
     {
          free(del_node);
     }
     return ret;
}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/16
* Others     (其他): 删除整张表
\*=======================================================================*/
void delete_all_node(linked_lists **head)
{
     linked_lists   *del_node = NULL;

     while(*head != NULL)
     {
         del_node = *head;
         *head = (*head)->next_node;
         free(del_node);
         del_node = NULL;
     }
}
