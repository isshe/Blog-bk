/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : binary.c
* Version      : v1.0.0
* Author       : 初代
* Date         : 2016/06/19
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
#include "binary.h"

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
* Date       (日期): 2016/06/19
* Others     (其他):
\*=======================================================================*/
int *my_malloc(int num)
{
    int *temp = NULL;

    temp = (int *)malloc(sizeof(int) * num);
    if (temp == NULL)
    {
        printf("内存分配错误!\n");
        exit(-1);
    }

    return temp;
}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/19
* Others     (其他):
\*=======================================================================*/
int input_data(int *array, int num)
{
     int i = 0;

     for (i = 0; i < num; i++)
     {
         scanf("%d", &array[i]);        //note!
     }
}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/19
* Others     (其他):
\*=======================================================================*/
int check_input_data(int *array1, int *array2, int num)
{
     int    i = 0;
     int    j = 0;
     int    ret = 0;
     int    flag = 0;

     for (i = 0; i < num; i++)
     {
         flag = 0;
         for (j = 0; j < num; j++)
         {
             if (array1[i] == array2[j])
             {
                 flag = 1;
                 break;
             }
         }

         if (flag != 1)
         {
              ret = -1;
              break;
         }
     }

     return ret;
}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/19
* Others     (其他):
\*=======================================================================*/
BTnode_s *construct(int *pre_start, int *pre_end, int *in_start, int *in_end)
{
    BTnode_s    *new_node = NULL;
    int         i = 0;

    new_node = (BTnode_s *)malloc(sizeof(BTnode_s));
    if (new_node == NULL)
    {
         printf("分配内存错误!\n");
         exit(-1);
    }

    //先序遍历中第一个就是当前根节点
    new_node->value         = pre_start[0];   //
//    printf("new_node->value = %d\n", new_node->value);
    new_node->leftchild     = NULL;
    new_node->rightchild    = NULL;

    if (pre_start == pre_end
        && in_start == in_end )
//        && *pre_start == *in_start)       //!!!
    {
         return new_node;
    }


    //在中序遍历中找根节点
    while(in_start + i <= in_end
            && in_start[i] != new_node->value)
    {
         i++;
    }

    //i是不是加多了一个？
    //如果找到最后都没有找到
    if (in_start + i - 1 == in_end
            && in_start[i-1] != new_node->value)
    {
         printf("%s:%d:输入有误!\n", __func__, __LINE__);
         exit(-1);
    }

    if (i > 0)      //i代表左节点的长度
    {
         new_node->leftchild = construct(pre_start + 1,
                 pre_start + i, in_start, in_start + i - 1);
    }

    if (pre_end - pre_start > i)        //右边也还有节点
    {
         new_node->rightchild = construct(pre_start + i + 1,
                 pre_end, in_start + i + 1, in_end);
    }

    return new_node;
}
/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/19
* Others     (其他): 构建二叉树。
\*=======================================================================*/
BTnode_s *create_binary_tree(int *preorder, int *inorder, int num)
{
     if (inorder == NULL || preorder == NULL || num <= 0)
     {
         return NULL;
     }
     else
     {
         return construct(preorder, preorder+num-1, inorder, inorder+num-1);
     }
}



/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/19
* Others     (其他):
\*=======================================================================*/
int order_traverse(BTnode_s *root, int flag)
{
     if (root == NULL)
     {
         return ;
     }

     if (flag == 1)             //先序
     {
          printf("%d ", root->value);
          order_traverse(root->leftchild, flag);
          order_traverse(root->rightchild, flag);
     }
     else if(flag == 2)         //中序
     {
          order_traverse(root->leftchild, flag);
          printf("%d ", root->value);
          order_traverse(root->rightchild, flag);
     }
     else if (flag == 3)        //后序
     {
          order_traverse(root->leftchild, flag);
          order_traverse(root->rightchild, flag);
          printf("%d ", root->value);
     }
     else if (flag == 4)        //层次，使用队列
     {
          queue_s   queue;
          BTnode_s  *p;

          queue.rear = -1;
          queue.front = -1;
          queue.size = 0;
          memset(queue.array, 0, sizeof(int) * MAXSIZE);

          //先把根节点放进队列
          queue.array[++queue.rear] = root;
          queue.size++;

          //这里注意!
          while (queue.size > 0) //可以改为rear和front
          {
               //出栈，打印
               queue.front = (queue.front + 1) % MAXSIZE;
               p = queue.array[queue.front];
//               printf("p = %p\n", p);
               printf("%d ", p->value);
               queue.size--;

               if (p->leftchild != NULL)
               {
                    queue.rear = (queue.rear + 1) % MAXSIZE;
                    queue.array[queue.rear] = p->leftchild;
                    queue.size++;
               }

               if (p->rightchild != NULL)
               {
                    queue.rear = (queue.rear + 1) % MAXSIZE;
                    queue.array[queue.rear] = p->rightchild;
                    queue.size++;
               }
          }
     }

     return 0;
}
