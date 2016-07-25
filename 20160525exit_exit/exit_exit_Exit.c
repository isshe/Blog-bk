/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : exit_exit_Exit.c
* Version      : v1.0.0
* Author       : 初代
* Date         : 2016/05/25
* Description  :
* Function list: 1.
*                2.
*                3.
* History      :
\*=========================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
     pid_t  p1 ;
     pid_t  p2 ;

     p1 = fork();
     if (p1 == 0)
     {
          printf("_exit()1!\n");
          printf("_exit()2!");
          _exit(1);
     }
     else if (p1 > 0)
     {
          p2 = fork();
          if(p2 == 0)
          {
              printf("_Exit()1!\n");
              printf("_Exit()2!");
              _Exit(2);
          }
          else if (p2 > 0)
          {
               printf("exit()1\n");
               printf("exit()2");
               exit(3);
          }
          else
          {
               ;
          }
     }
     else
     {
          ;
     }
}
