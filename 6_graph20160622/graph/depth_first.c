/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : depth_first.c
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
#include <stdlib.h>
#include "graph.h"

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
* Date       (日期): 2016/06/24
* Others     (其他): 深度优先搜索递归实现.
\*=======================================================================*/
static void dfs(pgraph_s graph, int i)
{
//    int     vertex = 0;//graph->list[i]->vertex; //5
    pnode_s node = NULL;

    graph->flag[i] = 1;                //标志
//    printf("flag = %d, i = %d\n", graph->flag[i], i);                  //5
    printf("%d ", i);
    for(node = graph->list[i]; node != NULL; node = node->next)
    {
//        printf("node->vertex = %d\n", node->vertex);
        if (graph->flag[node->vertex] == 0)
        {
            dfs(graph, node->vertex);
        }
    }
}

void depth_first(pgraph_s graph)
{
    int     i = 0;
    pnode_s node = NULL;

    //因为有效数据从i=1开始,所以要+1!!!!
    for (i = 0; i < graph->vertex_num+1; i++)
    {
         graph->flag[i] = 0;
    }

//    node = graph->list[1];      //第一个
    dfs(graph, 1);

    printf("\n");

}





/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/22
* Others     (其他): 深度优先搜索栈实现.
\*=======================================================================*/
//栈实现,一个失败的例子,还未完成.
/*
void depth_first(pgraph_s graph)
{
     pstack_s   stack = NULL;
     pnode_s    tempnode = NULL;
     int        i = 0;
     int        j = 0;

     //新建一个栈
     stack = (pstack_s)malloc(sizeof(stack_s));
     if (stack == NULL)
     {
          printf("malloc stack error!\n");
          exit(-1);
     }

     stack->array = (int *)malloc(sizeof(int) * graph->vertex_num);
     if (stack->array == NULL)
     {
          printf("malloc stack array error!\n");
          exit(-1);
     }
     stack->top = 0;

     //把标志清零, 也可以从1开始.
     for (i = 0; i < graph->vertex_num; i++)
     {
          graph->flag[i] = 0;
     }

     //出栈时打印

     j = 1;
     stack->array[stack->top] = j;
     stack->top++;
     graph->flag[j] = 1;
     j = graph->list[j]->vertex;
     tempnode = graph->list[j];
     for (i = 0; i < graph->vertex_num; i++)
     {
          while(tempnode != NULL)
          {
              if (graph->flag[j] == 0)  //进栈
              {
                   graph->flag[j] = 1;
                   stack->array[stack->top] = graph->list[j]->vertex;
                   j = stack->array[stack->top];
                   stack->top++;
//                   graph->flag[j] = 1;
                   tempnode = graph->list[j];
                   printf("\'%d ", j);
                   continue;
              }
              else
              {
                   tempnode = tempnode->next;
                   continue;
              }
          }

          stack->top--;
//          graph->flag[stack->top] = 1;
          printf("%d ", stack->array[stack->top]);
     }
     printf("\n");
}
*/
