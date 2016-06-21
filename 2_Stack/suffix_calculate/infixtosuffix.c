/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : infix2suffix.c
* Version      : v1.0.0
* Author       : 初代
* Date         : 2016/06/17
* Description  : 这个程序的栈直接用int类型可能更好，到需要打印字符串的时候再用int转
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
#include "infixtosuffix.h"


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
* Date       (日期): 2016/06/17
* Others     (其他): 中缀转后缀
\*=======================================================================*/
int infixtosuffix(char *expression)
{
     stack_s    stack;
     char       output[128] = {0};
     int        ret = 0;
     int        flag = 0;
     int        i = 0;
     int        j = 0;
     int        value = 0;
     int        expre_num = 0;
     int        stack_num = 0;

     if (expression == NULL)
     {
         ret = -1;
     }
     else
     {
          stack.array = (char *)malloc(sizeof(char) * 64);
          if (stack.array == NULL)
          {
              printf("error!\n");
              exit(-1);
          }
          stack.top = -1;


          i = 0;
          j = 0;
          while(expression[i] != '\0')
          {
//              printf("test!\n");
//            //如果是数字，则取数字出来
              while(expression[i] >= '0' && expression[i] <= '9')
              {
                  i++;
                  flag = 1;
              }
              if (flag == 1)        //因为指向下一个了，所以减一。
                  i--;

              //如果是运算符
              if (expression[i] < '0' || expression[i] > '9')
              {
                   flag = 2;
              }

              //如果是数字，则直接放到输出数组即可.
              if (flag == 1)
              {
                   flag = 0;
                   sscanf(expression + j, "%d", &value);
                   sprintf(output+strlen(output), "%d ", value); //
 //                 printf("%s", output);
              }
              else if(flag == 2)
              {
                   flag = 0;

                   //获取优先级
                   expre_num = get_num(expression[i]);
                   if(stack.top == -1)
                   {
                       stack_num = -1;
                   }
                   else
                   {
                       stack_num = get_num(stack.array[stack.top]);
                   }

                   //比较哪个优先级高。栈内和表达式中的比较。
                   if (expre_num > stack_num)
                   {
 /*                       if (expression[i] == '(')
                        {
                            //如果是左括号(直接入栈
                            stack.array[++stack.top] = expression[i];
                        }
                        else
*/
                        if (expression[i] == ')')          //如果是右括号，则出栈，直到遇到左括号。
                        {
                            //把(上面的都出栈
                            while(stack.array[stack.top] != '(')
                            {
                                sprintf(output+strlen(output), "%c ", stack.array[stack.top]);
                                stack.top--;
                            }
                            stack.top--;        //把(也出栈
                        }
                        else        //直接进栈
                        {
                             stack.array[++stack.top] = expression[i];
                        }

                   }
                   else if (expre_num == stack_num)
                   {
                        //如果是左括号则进栈，否则直接输出
                        if (expression[i] == '(')
                        {
                            stack.array[++stack.top] = expression[i];
                        }
                        else
                        {
                             sprintf(output+strlen(output), "%c ", expression[i]);
                        }
                   }
                   else     //这里不会再出现()!.
                   {
                       //如果栈内是(, 则expression[i]入栈,
                       if (stack.array[stack.top] == '(')
                       {
                            stack.array[++stack.top] = expression[i];
                       }
                       else         //否则栈内元素出栈放到输出，再和栈内下一个比较。
                       {
                            sprintf(output+strlen(output), "%c ", stack.array[stack.top]);
                            stack.top--;
                            i--;        //再用这个和栈内比较
                       }
                   }
              }
              i++;
              j = i;
         }
    }

     while(stack.top != -1)
     {
         sprintf(output+strlen(output), "%c ", stack.array[stack.top]);
         stack.top--;
     }

     output[strlen(output)] = '\0';
     printf("output= %s", output);
     free(stack.array);
     return ret;
}





/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/06/17
* Others     (其他):
\*=======================================================================*/
int get_num(char c)
{
     int ret = 0;

     switch(c)
     {
         case '+':
         case '-':
             ret = 1;
             break;
         case '*':
         case '/':
             ret = 2;
             break;
         case '(':
         case ')':
             ret = 3;
             break;
         default:
             ret = -1;
             break;
     }
     return ret;
}
