#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define M 20    //地图大小
#define L 50    //蛇的长度
//j对横坐标，i对纵坐标
void show();//显示
void food();
void remap();
void du();
void snakelife();
void tip();

wchar_t map[M][M];
int a;//用户输入判断游戏开始
int foodx,foody;//食物坐标
int foodCount = 0;//食物数量
int dux,duy;//毒草坐标
int duCount;//毒草数量
int snake[L][2];//蛇
int score;
int over = 1;
int k;//节点
int sum = 4;//蛇的初始长度

int main()
{
    while (1)
    {
     tip();
     if (a == 1)
     {
         remap();
         du();
         food();
         snakelife();

     }
     else if (a == 2)//游戏说明
     {
         printf("1、 * 为食物吃到后蛇长度加1。\n    @ 为毒草吃到后蛇长度减1。\n");
         printf("2、当蛇长度为40时玩家胜利，\n撞墙或咬到自己玩家失败。\n");
         printf("w s a d 为方向键，w 为上 s为下 a为左 d为右。\n");
         printf("加油！去获取游戏胜利吧\n");
         system ("pause");
         break;
     }
     else
     {
         exit(0);
     }
    }


    return 0;
}

void tip()
{
    printf ("欢迎来到贪吃蛇游戏\n");
    printf("    1、开始游戏\n");
    printf("    2、游戏说明\n");
    printf("    3、退出\n");
    printf("请输入你的选择");
    scanf("%d",&a);
    while (a != 1 && a != 2 && a != 3)
    {
        fflush(stdin);
        printf("请输入正确数字");
        scanf("%d",&a);


    }

}

//显示
void show()
{
    int i,j;
    for (i = 0; i < M; i++)
    {
        for(j = 0; j < M; j++)
        {
           printf("%c",map[i][j]);
        }
        printf ("\n");
    }
}
//蛇
void snakelife()
{
    int i, j;
    int dir = 0;//0  d向右，1  w向上，2  a向左，3 s向下
    char ch = 'd';
    //刚开始蛇在10行排开四节
    //snake[i][0]为纵坐标，snake[i][1]为横坐标
    snake[0][0] = 10;
    snake[0][1] = 10;
    snake[1][0] = 9;
    snake[1][1] = 10;
    snake[2][0] = 8;
    snake[2][1] = 10;
    snake[3][0] = 7;
    snake[3][1] = 10;
   while (1)
   {
//显示蛇
    for(k = 0; k < sum; k++)
    {
         for (i = 0; i < M; i++)
    {
        for(j = 0; j < M; j++)
        {
            if(i==snake[k][1]&&j==snake[k][0])//1对应i    0对应j
            {
              map[i][j] = '*';//显示符号

            }

            else
             continue;
        }
    }
    }
        show();
      Sleep(200);
    system("cls");
   //转弯
    int fdir = dir;
   if(_kbhit())
    ch = getch();
    switch(ch)
    {  case 'd':
        if (dir!=2)
            dir = 0;
            break;
       case 'w':
        if (dir!=3)
            dir = 1;
            break;
       case 'a':
        if (dir!=0)
            dir = 2;
            break;
       case 's':
        if (dir!=1)
            dir = 3;
            break;
       default :
       dir = fdir;

        }
//运动
       if (dir == 0)//向右
       {
           for(k = 1;k < sum;k++)
           {
               if (snake[0][0]+1 == snake[k][0]&&snake[0][1] == snake[k][1])
                      {
                      printf("你输了！按任意键结束游戏。\n");
                      printf("你的得分是%d \n",score);
                      system("pause");
                      return;
                      }
               else if(snake[0][0]+1 == 0||snake[0][0]+1 ==M-1)
                        {
                      printf("你输了！按任意键结束游戏。\n");
                      printf("你的得分是%d \n",score);
                      system("pause");
                      return ;
                      }
               else
                    continue;

           }
           map[snake[sum-1][1]][snake[sum-1][0]] = ' ';

       for(k = sum-1; k > 0; k--)
       {
         snake[k][0] = snake[k-1][0];
         snake[k][1] = snake[k-1][1];
       }
          snake[0][0] = snake[0][0]+1;

       }
       else if(dir == 1)//向上
       {
              for(k = 1;k < sum;k++)
           {
               if (snake[0][1]-1 == snake[k][1]&&snake[0][0] == snake[k][0])
                      {
                      printf("你输了！按任意键结束游戏。\n");
                      printf("你的得分是%d \n",score);
                      system("pause");
                      return;
                      }
               else if(snake[0][1]-1 == 0||snake[0][1]-1 ==M-1)
                        {
                      printf("你输了！按任意键结束游戏。\n");
                      printf("你的得分是%d \n",score);
                      system("pause");
                      return ;
                      }
               else
                    continue;

           }
          map[snake[sum-1][1]][snake[sum-1][0]] = ' ';

       for(k = sum-1; k > 0; k--)
       {
         snake[k][0] = snake[k-1][0];
         snake[k][1] = snake[k-1][1];
       }
          snake[0][1] = snake[0][1]-1;

       }
       else if(dir == 2)//向左
       {
                      for(k = 1;k < sum;k++)
           {
               if (snake[0][0]-1 == snake[k][0]&&snake[0][1] == snake[k][1])
                      {
                      printf("你输了！按任意键结束游戏。\n");
                      printf("你的得分是%d \n",score);
                      system("pause");
                      return;
                      }
               else if(snake[0][0]-1 == 0||snake[0][0]-1 ==M-1)
                        {
                      printf("你输了！按任意键结束游戏。\n");
                      printf("你的得分是%d \n",score);
                      system("pause");
                      return ;
                      }
               else
                    continue;

           }
            map[snake[sum-1][1]][snake[sum-1][0]] = ' ';

       for(k = sum-1; k > 0; k--)
       {
         snake[k][0] = snake[k-1][0];
         snake[k][1] = snake[k-1][1];
       }
          snake[0][0] = snake[0][0]-1;

       }
       else
       {
              for(k = 1;k < sum;k++)
           {
               if (snake[0][1]+1 == snake[k][1]&&snake[0][0] == snake[k][0])
                      {
                      printf("你输了！按任意键结束游戏。\n");
                      printf("你的得分是%d \n",score);
                      system("pause");
                      return;
                      }
               else if(snake[0][1]+1 == 0||snake[0][1]+1 ==M-1)
                        {
                      printf("你输了！按任意键结束游戏。\n");
                      printf("你的得分是%d \n",score);
                      system("pause");
                      return ;
                      }
               else
                    continue;

           }
            map[snake[sum-1][1]][snake[sum-1][0]] = ' ';

       for(k = sum-1; k > 0; k--)
       {
         snake[k][0] = snake[k-1][0];
         snake[k][1] = snake[k-1][1];
       }
          snake[0][1] = snake[0][1]+1;

       }
      //吃到食物
       if (snake[0][0] == foody&&snake[0][1] == foodx )
            {
                score++;
                sum++;
                if (sum == 40)
                {
                    printf ("你赢了，太厉害了，你真是个高手。\n");
                    printf("你的得分是%d \n",score);
                    system ("pause");
                    return;

                }
                snake[sum-1][0] = snake[sum-2][0];
                snake[sum-1][1] = snake[sum-2][1];
                foodCount--;
                food();
            }
     //吃到毒草
       else if (snake[0][0] == duy&&snake[0][1] == dux )///问题
            {
                score--;
                map[snake[sum-1][1]][snake[sum-1][0]] = ' ';
                sum--;
                if (sum == 0)
                {
                    printf("你的蛇蛇饿死了。\n你的得分是%d \n",score);
                    printf("按任意键返回。");
                    system ("pause");
                    return;
                }
                snake[sum][0] = 0;
                snake[sum][1] = 0;
                duCount--;
                du();

   }

}
}
//生成食物
void food()
{
    int i,j;
    k=0;
   while (foodCount==0)//生成食物
   {
       srand((unsigned)time(NULL));
   foodx = rand()%(M-2)+1;
   foody = rand()%(M-2)+1;
   while (over == 1)//避免食物生在蛇上
{
     if ( (foody == snake[k][0]&&foodx == snake[k][1])||(dux == foodx&& duy == foody))
     {
          foodx = rand()%(M-2)+1;
          foody = rand()%(M-2)+1;
      }
     else if(k==sum-1)
     {
         break;
     }
      else
        k++;
      ;

           }
   if (foodx!=0   &&foody!= 0  )
    foodCount++;
    }
    //食物点
         for (i = 0; i < M; i++)
    {
        for(j = 0; j < M; j++)
        {
            if(i==foodx&&j==foody)
            {
              map[i][j] = '*';

            }

            else
                 continue;
        }

    }
}
//地图*******************************************************************************************************************
void remap()
{
    int i;//显示的坐标
    int j;
     for (i = 0; i < M; i++)
    {
        for(j = 0; j < M; j++)
        {
            if(i==0||i==M-1||j==0||j==M-1)
            {
              map[i][j] = '*';

            }

            else
             map[i][j] = ' ';
        }

    }
}
void du()
{

    int i,j;
    k=0;
   while (duCount==0)//生成毒草
   {
       srand((unsigned)time(NULL));
       dux = rand()%(M-2)+1;
       duy = rand()%(M-2)+1;
   while (over == 1)//避免毒草生在蛇上
{
     if ( (duy == snake[k][0]&&dux == snake[k][1])||(dux == foodx&& duy == foody))
     {
          dux = rand()%(M-2)+1;
          duy = rand()%(M-2)+1;
      }
     else if(k==sum-1)
     {
         break;
     }
      else
        k++;
      ;

           }
   if (dux!=0   &&duy!= 0  )
    duCount++;
    }
    //食物点
         for (i = 0; i < M; i++)
    {
        for(j = 0; j < M; j++)
        {
            if(i==dux&&j==duy)
            {
              map[i][j] = '@';

            }

            else
                 continue;
        }

    }
}

