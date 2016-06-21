/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : binary_search.c
* Version      : v1.0.0
* Author       : 初代
* Date         : 2016/06/20
* Description  :
* Function list: 1.
*                2.
*                3.
* History      :
\*=========================================================================*/

/*-----------------------------------------------------------*
 * 头文件                                                    *
 *-----------------------------------------------------------*/

/*-----------------------------------------------------------*
 * 外部变量说明                                              *
 *-----------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_search.h"

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



/*=====================================================================\
* Function   (名称): insert_node()
* Description(功能): 插入节点
* Called By  (被调): 1.
* Call_B file(被文): 1.
* Calls list (调用): 1.
* Calls file (调文): 1.
* Input      (输入): 1.
* Output     (输出): 1.
* Return     (返回):
*         success  :
*         failure  :
* Change log (修改): 1.
* Others     (其他): 1.
\*=====================================================================*/
int insert_node(BTnode_s **root, int value)
{

     if (*root == NULL)      //没有根节点？！
     {
          *root = (BTnode_s *)malloc(sizeof(BTnode_s));
          if (*root == NULL)
          {
               printf("节点内存分配错误!\n");
               exit(-1);
          }

          (*root)->value = value;
          (*root)->leftchild = NULL;
          (*root)->rightchild = NULL;

     }
     else if (value > (*root)->value)
     {
         insert_node(&((*root)->rightchild), value);
     }
     else if(value < (*root)->value)
     {
          insert_node(&((*root)->leftchild), value);
     }
     else
     {
         printf("节点已存在!\n");
     }

     return 0;

}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/19
* Others     (其他):
\*=======================================================================*/
int traverse(BTnode_s *root, int flag)
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



/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/20
* Others     (其他):
\*=======================================================================*/
BTnode_s *find_node(BTnode_s *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->value > value)
    {
         find_node(root->leftchild, value);
    }
    else if (root->value < value)
    {
        find_node(root->rightchild, value);
    }
    else
    {
         return root;
    }
}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/20
* Others     (其他):
\*=======================================================================*/
BTnode_s *find_min_max_node(BTnode_s *root, int flag)
{

     if (root == NULL)
     {
         return NULL;
     }

     switch(flag)
     {
         case 1:
             if (root->leftchild == NULL)
             {
//                 root->value = 100;
                 return root;
             }
             else
             {
                 find_min_max_node(root->leftchild, flag);
             }
             break;
         case 2:
             while(root->rightchild != NULL)
             {
                  root = root->rightchild;
             }
             return root;

             break;
         default:
             break;
     }

}



/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/20
* Others     (其他):
\*=======================================================================*/
int delete_node(BTnode_s **root, int value)
{
     BTnode_s   *tempnode = NULL;
     //加temproot只是为了省去各种双重指针的括号之类的。
     BTnode_s   *temproot = *root;

     if (temproot == NULL)
     {
         return -1;
     }

     if (temproot->value > value)       //在左边
     {
          delete_node(&temproot->leftchild, value);
     }
     else if(temproot->value < value)   //右边
     {
         delete_node(&temproot->rightchild, value);
     }
     else       //等于
     {
          //左右孩子都有。
          if (temproot->leftchild != NULL && temproot->rightchild != NULL)
          {
               //找到右孩子最小的节点;（此节点没有左孩子）
               //然后把要删除节点的值替换成右孩子最小值
               //把右孩子最小节点删除。
               tempnode = find_min_max_node(temproot->rightchild, MINNODEFLAG);
               temproot->value = tempnode->value;
//               temproot->rightchild =
               delete_node(&temproot->rightchild, tempnode->value);
          }
          else      //０或１个孩子节点
          {

              tempnode = temproot;
              if (temproot->leftchild == NULL)      //没有左孩子
              {
                   *root = temproot->rightchild;
              }
              else if (temproot->rightchild == NULL)
              {
                  *root = temproot->leftchild;
              }

              free(tempnode);
          }
     }

     return 0;
}
