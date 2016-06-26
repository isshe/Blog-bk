/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : main.c
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

int main(int argc, char *argv[])
{
     int            vertexnum = 0;
     int            edgenum = 0;
     pgraph_s       graph = NULL;
     int            option = 0;

//     scanf("%d", &vertexnum);
//     scanf("%d", &edgenum);

//     graph.vertex_num = vertexnum;
//     graph.edge_num = edgenum;
     graph = create_graph();

     printf("广度优先遍历: \n");
     breadth_first(graph);


     printf("深度优先遍历: \n");
     depth_first(graph);
     output_graph(graph);

     return 0;
}
