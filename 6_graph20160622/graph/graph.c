/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : graph.c
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
#include <string.h>
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
* Date       (日期): 2016/06/22
* Others     (其他):
\*=======================================================================*/
pgraph_s create_graph()
{
     pgraph_s       graph = NULL;
     pnode_s        pnode = NULL;
     int            vertexnum = 0;
     int            edgenum = 0;
     int            vertex = 0;
     int            edge = 0;
     int            weight = 0;

     graph = (pgraph_s)malloc(sizeof(graph_s));
     if (graph == NULL)
     {
          printf("malloc graph error!\n");
          exit(-1);
     }

//     printf("输入顶点数目:\n");
     fscanf(stdin, "%d\n", &vertexnum);
//     printf("输入边数目:\n");
     fscanf(stdin, "%d\n", &edgenum);
//     printf("venum = %d, ednum = %d", vertexnum, edgenum);

     //给指针数组分配空间
     graph->graph_type = GRAPHTYPE;         //0为无向图
     graph->vertex_num = vertexnum;
     graph->edge_num = edgenum;
     graph->list = (pnode_s *)malloc(sizeof(pnode_s) * (vertexnum +1));
     if (graph->list == NULL)
     {
          printf("malloc grpah->list error!\n");
          exit(-1);
     }

     //给标志数组分配空间
     graph->flag = (int *)malloc(sizeof(int) * (vertexnum + 1));
     if (graph->flag == NULL)
     {
          printf("malloc graph flag error!\n");
     }

     //为了不使每次循环都多一次if判断,先scanf一次.
//     while(fscanf(stdin, "%d %d %d\n", &vertex, &edge, &weight) != EOF)
     while(fscanf(stdin, "<%d,%d,%d>\n", &vertex, &edge, &weight) != EOF)
     {
          pnode = (pnode_s)malloc(sizeof(node_s));
          if (pnode == NULL)
          {
               printf("malloc new node error!\n");
               return NULL;           //
          }

          pnode->vertex = edge; //确定两个顶点的时候相当与确定一条边
          pnode->weight = weight;
          //采用前插
          pnode->next = graph->list[vertex];
          graph->list[vertex] = pnode;

          if (graph->graph_type == 0)       //无向图
          {
               pnode = (pnode_s)malloc(sizeof(node_s));
               if (pnode == NULL)
               {
                    printf("tyep = 0 and malloc new node error!\n");
                    return NULL;
               }
               pnode->vertex = vertex;
               pnode->weight = weight;
               pnode->next = graph->list[edge];
               graph->list[edge] = pnode;
          }
//          printf("vertex = %d, edge = %d, weight=%d\n", vertex, edge, weight);
     }

     return graph;
}



/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/22
* Others     (其他):
\*=======================================================================*/
void output_graph(pgraph_s graph)
{
     int        i = 0;
     int        j = 0;
     pnode_s    pnode;

     for (i = 1; i <= graph->vertex_num; i++)
     {
          pnode = graph->list[i];
          printf("第%d个顶点: ", i);
          while(pnode != NULL)
          {
              printf("%d ", pnode->vertex);
              pnode = pnode->next;
          }
          printf("\n");
     }
}
