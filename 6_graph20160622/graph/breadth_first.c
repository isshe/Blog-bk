/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : breadth_first.c
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


/*=====================================================================\
* Function   (名称): breadth_first()
* Description(功能): 广度优先遍历
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
void breadth_first(pgraph_s graph)
{
    int         i = 0;
    int         j = 0;
    pqueue_s    queue = NULL;
    int         outvalue = 0;       //出队的值
    int         invalue = 0;        //入队的值
    pnode_s    tempnode = NULL;

    if (graph == NULL)
    {
        printf("图不存在!\n");
        exit(-1);
    }

    queue = (pqueue_s)malloc(sizeof(queue_s));
    if (queue == NULL)
    {
        printf("malloc queue error!\n");
        exit(-1);
    }
    queue->array = (int *)malloc(sizeof(int) * graph->vertex_num);
    if (queue->array == NULL)
    {
         printf("malloc queue array error!\n");
         exit(-1);
    }
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;

    //遍历前初始化标志
    for(i = 1; i < graph->vertex_num; i++)
    {
         graph->flag[i] = 0;
    }


    //因为队长(chang)就是vertex_num
    //这里固定了"1"不好,但是如果要改则要改邻接表,改动较大
    //这个程序中,邻接表中数组的下标就是顶点号,没有用多一个
    //节点来记录此顶点号,所以这里有点尴尬.
    queue->rear = (queue->rear+1) % graph->vertex_num;
    queue->array[queue->rear] = 1; //第一个顶点入队!
    graph->flag[1] = 1;             //标志
    queue->size++;
    printf("1 ");
    while(queue->size > 0)     //队不空时,从队里出来一个
    {
         queue->front = (queue->front + 1) % graph->vertex_num;
         outvalue = queue->array[queue->front];
         queue->size--;
         //遍历出队顶点的相邻顶点
         tempnode = graph->list[outvalue];         //i用处
         while(tempnode != NULL)
         {
             //flag = 0说明没有遍历过.
             if (graph->flag[tempnode->vertex] == 0)
             {
                  //入队,打印
                  graph->flag[tempnode->vertex] = 1;
                  queue->rear = (queue->rear + 1) % graph->vertex_num;
                  queue->array[queue->rear] = tempnode->vertex;
                  queue->size++;
                  printf("%d ", tempnode->vertex);
             }
             tempnode = tempnode->next;
         }
    }

    printf("\n");

//    return 0;
}
