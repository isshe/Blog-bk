/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : binary_search.h
* Version      : v1.0.0
* Author       : i.sshe
* Github       : github.com/isshe
* Date         : 2016/06/20
* Description  :
* Function list: 1.
*                2.
*                3.
* History      :
\*=========================================================================*/

#ifndef _BINARY_SEARCH_H_
#define _BINARY_SEARCH_H_

#ifdef __cplusplus
extern "C"{
#endif

/*=========================================================================*\
 * #include#                                                               *
\*=========================================================================*/

/*=========================================================================*\
 * #define#                                                                *
\*=========================================================================*/
#define MAXSIZE         32      //最大队列取值
#define MINNODEFLAG     1
#define MAXNODEFLAG     2
/*=========================================================================*\
 * #enum#                                                                  *
\*=========================================================================*/

/*=========================================================================*\
 * #struct#                                                                *
\*=========================================================================*/
typedef struct _NODE_S_
{
     int                value;
     struct _NODE_S_    *leftchild;
     struct _NODE_S_    *rightchild;
}BTnode_s;


typedef struct _QUEUE_S_
{
     BTnode_s   *array[MAXSIZE];
     int        rear;
     int        front;
     int        size;
}queue_s;

/*=========================================================================*\
 * #function#                                                              *
\*=========================================================================*/


/*=====================================================================\
* Function   (名称): create_root()
* Description(功能): 新建根节点。
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
int insert_node(BTnode_s **root, int value);



/*=====================================================================\
* Function   (名称): traverse()
* Description(功能): 遍历
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
int traverse(BTnode_s *root, int flag);


/*=====================================================================\
* Function   (名称): find_node()
* Description(功能): 查找节点
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
BTnode_s *find_node(BTnode_s *root, int value);


/*=====================================================================\
* Function   (名称): find_min_max_node()
* Description(功能): 查找最小或最大节点
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
BTnode_s *find_min_max_node(BTnode_s *root, int flag);


/*=====================================================================\
* Function   (名称): delete_node()
* Description(功能): 删除节点
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
int delete_node(BTnode_s **root, int value);
#ifdef __cplusplus
}
#endif

#endif

