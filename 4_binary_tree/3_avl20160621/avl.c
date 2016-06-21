/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : avl.c
* Version      : v1.0.0
* Author       : 初代
* Date         : 2016/06/21
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
#include "avl.h"

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
* Date       (日期): 2016/06/21
* Others     (其他):
\*=======================================================================*/
int max_func(int a, int b)
{
    if (a > b)
    {
         return a;
    }
    else
    {
        return b;
    }
}

/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/21
* Others     (其他):
\*=======================================================================*/
static int  get_height(pBTnode_s node)
{
     if (node == NULL)
     {
         return -1;
     }
     else
     {
          return node->height;
     }
}

/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/21
* Others     (其他): 插入节点并进行平衡调节
\*=======================================================================*/
int insert_node(pBTnode_s *root, int value)
{
     //如果当前节点为空,新建节点,把节点添加到此.
     if (*root == NULL)
     {
         *root = (pBTnode_s)malloc(sizeof(BTnode_s));
         if (*root == NULL)
         {
             printf("内存分配错误(out of space)!\n");
             return -1;             //
         }
         else
         {
              (*root)->value = value;
              (*root)->height = 0;      //
              (*root)->leftchild = NULL;
              (*root)->rightchild = NULL;
         }
     }
     else
     {
          if ((*root)->value > value)       //左边
          {
              insert_node(&(*root)->leftchild, value);

              //因为是在左边插入,所以是左子树高度-右子树高度
              //用绝对值也行
              if (get_height((*root)->leftchild)
                      - get_height((*root)->rightchild) == 2)
              {
                  //LL型
                  if ((*root)->leftchild->value > value)
                  {
                      single_left_rotate(root);
                  }
                  else      //LR型
                  {
                      double_left_rotate(root);
                  }
              }

          }
          else if ((*root)->value < value)  //右边
          {
              insert_node(&(*root)->rightchild, value);
              if (get_height((*root)->rightchild)
                      -get_height((*root)->leftchild) == 2)
              {
                  //RR型
                  if ((*root)->rightchild->value < value)
                  {
                       single_right_rotate(root);
                  }
                  else      //RL型
                  {
                      double_right_rotate(root);
                  }
              }

          }
          else      //相等,说明节点已存在,不需要做什么.
          {
              ;
          }
     }

     (*root)->height = MAX(get_height((*root)->leftchild),
                            get_height((*root)->rightchild)) + 1;

     return 0;
}



/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/21
* Others     (其他): LL型
\*=======================================================================*/
int single_left_rotate(pBTnode_s *root)
{
    //如果前面已经确定root != NULL,则可以不写.
    if (*root == NULL)
    {
        return -1;
    }
    //当前节点和当前节点的左子节点.
    pBTnode_s temproot = *root;
    pBTnode_s templeft = (*root)->leftchild;

    //当前节点的左节点=左节点的左节点
    //左节点的左节点=当前节点,实现旋转
    //最后要把根改变成templeft.
    temproot->leftchild = templeft->rightchild;
    templeft->rightchild = temproot;

    //更新树高
    temproot->height = MAX(get_height(temproot->leftchild),
                            get_height(temproot->rightchild)) + 1;
    templeft->height = MAX(get_height(templeft->leftchild),
                            get_height(templeft->rightchild)) + 1;

    //更新根节点
    *root = templeft;

    return 0;
}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/21
* Others     (其他):
\*=======================================================================*/
int single_right_rotate(pBTnode_s *root)
{
    //如果前面已经确定root != NULL,则可以不写.
    if (*root == NULL)
    {
         return -1;
    }

     pBTnode_s  temproot = *root;
     pBTnode_s  tempright = (*root)->rightchild;

     //
     temproot->rightchild = tempright->leftchild;
     tempright->leftchild = temproot;

     //更新树高
    temproot->height = MAX(get_height(temproot->leftchild),
                            get_height(temproot->rightchild)) + 1;
    tempright->height = MAX(get_height(tempright->leftchild),
                            get_height(tempright->rightchild)) + 1;

     *root = tempright;

     return 0;
}



/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/21
* Others     (其他):
\*=======================================================================*/
int double_left_rotate(pBTnode_s *root)
{
     if (*root == NULL)
     {
         return -1;
     }

     single_right_rotate(&(*root)->leftchild);
     single_left_rotate(root);
}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/21
* Others     (其他):
\*=======================================================================*/
int double_right_rotate(pBTnode_s *root)
{
     if (*root == NULL)
     {
         return -1;
     }

     single_left_rotate(&(*root)->rightchild);
     single_right_rotate(root);
}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/19
* Others     (其他):
\*=======================================================================*/
int traverse(pBTnode_s root, int flag)
{
     if (root == NULL)
     {
         return ;
     }

     if (flag == 1)             //先序
     {
          printf("%d ", root->value);
          traverse(root->leftchild, flag);
          traverse(root->rightchild, flag);
     }
     else if(flag == 2)         //中序
     {
          traverse(root->leftchild, flag);
          printf("%d ", root->value);
          traverse(root->rightchild, flag);
     }
     else if (flag == 3)        //后序
     {
          traverse(root->leftchild, flag);
          traverse(root->rightchild, flag);
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
