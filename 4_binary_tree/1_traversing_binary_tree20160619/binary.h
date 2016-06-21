/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : binary.h
* Version      : v1.0.0
* Author       : i.sshe
* Github       : github.com/isshe
* Date         : 2016/06/19
* Description  :
* Function list: 1.
*                2.
*                3.
* History      :
\*=========================================================================*/

#ifndef BINARY_H_
#define BINARY_H_

#ifdef __cplusplus
extern "C"{
#endif

/*=========================================================================*\
 * #include#                                                               *
\*=========================================================================*/

/*=========================================================================*\
 * #define#                                                                *
\*=========================================================================*/
//#define UDTYPE      int        //user defined type
#define MAXSIZE         32      //最大队列取值
/*=========================================================================*\
 * #enum#                                                                  *
\*=========================================================================*/

/*=========================================================================*\
 * #struct#                                                                *
\*=========================================================================*/
typedef struct _BTNODE_S_
{
     int                    value;
     struct _BTNODE_S_      *leftchild;
     struct _BTNODE_S_      *rightchild;
//     struct _BTNODE_S_      *parent;
}BTnode_s;              //binary tree node;

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
* Function   (名称): my_malloc()
* Description(功能): malloc的包裹函数
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
int *my_malloc(int num);


/*=====================================================================\
* Function   (名称): construct()
* Description(功能): 构建二叉树
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
BTnode_s *construct(int *pre_start, int *pre_end, int *in_start, int *in_end);

/*=====================================================================\
* Function   (名称): create_root()
* Description(功能): 创建根节点
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
BTnode_s *create_binary_tree(int *inorder, int *preorder, int num);


/*=====================================================================\
* Function   (名称): input_data()
* Description(功能): 输入数据
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
int input_data(int *array, int num);



/*=====================================================================\
* Function   (名称): check_input_data()
* Description(功能): 检查输入数据是否有错
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
int check_input_data(int *array1, int *array2, int num);

/*=====================================================================\
* Function   (名称): destroy_btree()
* Description(功能): 销毁二叉树
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
int destroy_btree(BTnode_s *root);

/*=====================================================================\
* Function   (名称): post_order_traverse()
* Description(功能): 遍历, 先序，中序，后序，层次，用flag标识
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
int order_traverse(BTnode_s *root, int flag);



#ifdef __cplusplus
}
#endif

#endif

