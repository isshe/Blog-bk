/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : linked_list.h
* Version      : v1.0.0
* Author       : i.sshe
* Github       : github.com/isshe
* Date         : 2016/06/16
* Description  :
* Function list: 1.
*                2.
*                3.
* History      :
\*=========================================================================*/

#ifndef LINKED_LISTS_H_
#define LINKED_LISTS_H_

#ifdef __cplusplus
extern "C"{
#endif

/*=========================================================================*\
 * #include#                                                               *
\*=========================================================================*/

/*=========================================================================*\
 * #define#                                                                *
\*=========================================================================*/

/*=========================================================================*\
 * #enum#                                                                  *
\*=========================================================================*/

/*=========================================================================*\
 * #struct#                                                                *
\*=========================================================================*/
typedef struct _LINKED_LISTS_
{
    int                     value;
    struct _LINKED_LISTS_   *next_node;
}linked_lists;

/*=========================================================================*\
 * #function#                                                              *
\*=========================================================================*/

/*=====================================================================\
* Function   (名称): create_linked_lists()
* Description(功能): 根据初始数据新建链表
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
int create_linked_lists(int *array);


/*=====================================================================\
* Function   (名称): list_size()
* Description(功能): 获取链表的长度
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
int list_size(linked_lists *head);


/*=====================================================================\
* Function   (名称): get_node()
* Description(功能): 根据值来获取节点（地址）,第几个位置。
* Called By  (被调): 1.
* Call_B file(被文): 1.
* Calls list (调用): 1.
* Calls file (调文): 1.
* Input      (输入): 1.
* Output     (输出): 1.
* Return     (返回):
*         success  : 节点位置
*         failure  : 0:空表，无任何节点；-1:没找到；
* Change log (修改): 1.
* Others     (其他): 1.
\*=====================================================================*/
int get_node(linked_lists *head, int value);


/*=====================================================================\
* Function   (名称): delete_node();
* Description(功能): 删除节点
* Called By  (被调): 1.
* Call_B file(被文): 1.
* Calls list (调用): 1.
* Calls file (调文): 1.
* Input      (输入): 1.
* Output     (输出): 1.
* Return     (返回):
*         success  : 0: 成功删除。
*         failure  : -1:表中没有此元素或者表是空表。
* Change log (修改): 1.
* Others     (其他): 1.
\*=====================================================================*/
int delete_node(linked_lists **head, int value);


/*=====================================================================\
* Function   (名称): delete_all_node(link)
* Description(功能): 删除整个表。
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
void delete_all_node(linked_lists **head);

/*=====================================================================\
* Function   (名称): insert_node()
* Description(功能): 插入节点(头插／尾插)
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
* Others     (其他): 1.注意是指针的指针！
\*=====================================================================*/
int insert_node(linked_lists **head, int value);


/*=====================================================================\
* Function   (名称): output_list()
* Description(功能): 输出链表
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
int output_list(linked_lists *head);

#ifdef __cplusplus
}
#endif

#endif

