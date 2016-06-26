/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : graph.h
* Version      : v1.0.0
* Author       : i.sshe
* Github       : github.com/isshe
* Date         : 2016/06/22
* Description  :
* Function list: 1.
*                2.
*                3.
* History      :
\*=========================================================================*/

#ifndef GRAPH_H_
#define GRAPH_H_

#ifdef __cplusplus
extern "C"{
#endif

/*=========================================================================*\
 * #include#                                                               *
\*=========================================================================*/

/*=========================================================================*\
 * #define#                                                                *
\*=========================================================================*/
#define MAXVERTEX       20
#define GRAPHTYPE       0       //0:无向图; 1:有向图

/*=========================================================================*\
 * #enum#                                                                  *
\*=========================================================================*/

/*=========================================================================*\
 * #struct#                                                                *
\*=========================================================================*/
typedef struct NODE_S_
{
    int     vertex;             //相邻的顶点,和它有边
    int     weight;             //权重
    struct NODE_S_   *next;      //下一节点
}node_s, *pnode_s;

typedef struct LIST_GRAPH_S
{
    pnode_s  *list;
    int     *flag;              //用于遍历,标志是否遍历过了.
    int     vertex_num;
    int     edge_num;
    int     graph_type;         //0:无向图;1:有向图
}graph_s, *pgraph_s;

//用于广度优先遍历
typedef struct QUEUE_S_
{
     int    *array;
     int    front;
     int    rear;
     int    size;
}queue_s, *pqueue_s;

//深度优先遍历中用到
typedef struct STACK_S_
{
     int    *array;
     int    top;
     int    size;       //
}stack_s, *pstack_s;

/*=========================================================================*\
 * #function#                                                              *
\*=========================================================================*/

/*=====================================================================\
* Function   (名称): create_graph()
* Description(功能): 新建一个图
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
pgraph_s create_graph();


/*=====================================================================\
* Function   (名称): output_graph()
* Description(功能): 输出图的顶点信息
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
void output_graph(pgraph_s graph);

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
void breadth_first(pgraph_s graph);


/*=====================================================================\
* Function   (名称): depth_first()
* Description(功能): 深度优先遍历
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
void depth_first(pgraph_s graph);

#ifdef __cplusplus
}
#endif

#endif

