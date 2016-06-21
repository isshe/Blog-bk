/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : avl.h
* Version      : v1.0.0
* Author       : i.sshe
* Github       : github.com/isshe
* Date         : 2016/06/21
* Description  : 双旋转从下往上进行!!!!
* Function list: 1.
*                2.
*                3.
* History      :
\*=========================================================================*/

#ifndef AVL_H_
#define AVL_H_

#ifdef __cplusplus
extern "C"{
#endif

/*=========================================================================*\
 * #include#                                                               *
\*=========================================================================*/

/*=========================================================================*\
 * #define#                                                                *
\*=========================================================================*/
#define MAXSIZE         32
#define MAX(a,b)             ((a)>(b)?(a):(b))

/*=========================================================================*\
 * #enum#                                                                  *
\*=========================================================================*/

/*=========================================================================*\
 * #struct#                                                                *
\*=========================================================================*/
typedef struct _NODE_S_
{
    int             value ;
    int             height;
    struct _NODE_S_ *leftchild;
    struct _NODE_S_ *rightchild;
}BTnode_s, *pBTnode_s;

typedef struct _QUEUE_S_
{
     BTnode_s       *array[MAXSIZE];
     int            rear;
     int            front;
     int            size;
}queue_s, *pqueue_s;

/*=========================================================================*\
 * #function#                                                              *
\*=========================================================================*/


/*=====================================================================\
* Function   (名称): insert_node()
* Description(功能): 插入节点，并进行平衡调节
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
int insert_node(pBTnode_s *root, int value);


/*=====================================================================\
* Function   (名称): single_left_rotate()
* Description(功能): 左单旋转,
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
int single_left_rotate(pBTnode_s *root);


/*=====================================================================\
* Function   (名称): single_right_rotate()
* Description(功能): 右单旋转.
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
int single_right_rotate(pBTnode_s *root);



/*=====================================================================\
* Function   (名称): double_left_rotate()
* Description(功能): 先右旋后左旋
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
int double_left_rotate(pBTnode_s *root);


/*=====================================================================\
* Function   (名称): double_right_rotate()
* Description(功能): 先左旋后右旋
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
int double_right_rotate(pBTnode_s *root);



/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/21
* Others     (其他):
\*=======================================================================*/
int traverse(pBTnode_s root, int flag);
#ifdef __cplusplus
}
#endif

#endif

