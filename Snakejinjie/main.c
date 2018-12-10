#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "snake.h"

#define W 20 //地图宽度
#define L 40 //地图长度
#define S 4//初始化蛇长+1



void Pos(int x, int y);//光标
void food();
void poison();


char map[W][L];
int k;//
int sum = 5;//蛇的总长
int foodx,foody;//食物坐标
int foodCount = 0;//食物数量
int foodContinue = 0;//食物连吃数量
int poisonx,poisony;//毒草坐标
int poisonxy[2][8];
int poisonCount;//毒草数量
int poisonRepalce = 0;//刷新
int a = 0;
signed int score = 0;//得分
int over = 1;//1继续，0结束
int difficult = 0;//难度
int speed = 0;//速度

struct Snake{
   int x;
   int y;
   struct Snake*next;
   struct Snake*previous;
}*current,*snaketail,*head,*snakehead,*tail;


void show();
//void remap();
void snakelife();
void freesnake();

int main()
{
    while (1)
    {
     tip(a);
     remap();
     snakelife();
     /*if (a == 1)
     {
         printf("请选择难度：\n1、初级\n2、中级\n3、高级\n请选择：");
         scanf("%d",&difficult);
         while(difficult != 1 && difficult != 2 && difficult != 3)
         {
             fflush(stdin);
             printf("请输入正确数字");
             scanf("%d",&difficult);
         }
         if (difficult == 1)
            speed = 800;
         else if(difficult == 2)
            speed = 400;
         else
            speed = 100;

         remap();
         snakelife();
         system("cls");
         continue;
     }
     else if (a == 2)//游戏说明
     {
         printf("1、 * 为食物吃到后蛇长度加1。\n    @ 为毒草吃到后蛇长度减1。\n");
         printf("2、当蛇长度为40时玩家胜利，\n撞墙或咬到自己或者蛇的长度只有1玩家失败。\n");
         printf("w s a d 为方向键，w 为上 s为下 a为左 d为右。\n");
         printf("加油！去获取游戏胜利吧\n");
         system ("pause");
         continue;
     }
     else
     {
         exit(0);
     }*/
    }

    return 0;
}
/*void remap()
{
    int i , j;
    for (i = 0; i < W ;i++)
    {
        for(j = 0; j < L; j++)
        {
            if (j%2 == 0&&i == 0)
            {
            Pos(j,i);
            printf("*");
            }
            else if (j%2 == 0&&j == 0)
            {
            Pos(j,i);
            printf("*");
            }
            else if (j%2 == 0&&i == W-1)
            {
            Pos(j,i);
            printf("*");
            }
            else if (j%2 == 0&&j == L-2)
           {
            Pos(j,i);
            printf("*");
            }
            else
            {
            Pos(j,i);
            printf(" ");
            }
        }

    }
}*/

void snakelife()
{
    int i = 0;
    int dir = 2;//方向
    int a,b;//擦除的坐标
    score = 0;
    sum = 5;
    foodCount = 0;
    over = 1;
    poisonCount = 0;
    current = NULL;
    snaketail = NULL;
    head = NULL;
    snakehead = NULL;
    tail = NULL;
    //初始化蛇***************************************************************************************************
    snaketail = (struct Snake*)malloc(sizeof(struct Snake)) ;
    snaketail->x = 20;
    snaketail->y = 10;
    snaketail->next = NULL;
    snaketail->previous = NULL;
    tail = snaketail;
    for (i = 0; i < S; i++)
    {
        if(i == 0)
        {
            current = (struct Snake*)malloc(sizeof(struct Snake));
            snaketail->next = current;
            current->x = snaketail->x -2;
            current->y = snaketail->y;
            current->previous = NULL;
            current->next = NULL;
            snaketail = current;
        }
        else
        {
            current = (struct Snake*)malloc(sizeof(struct Snake));
            snaketail->next = current;
            current->x = snaketail->x -2;
            current->y = snaketail->y;
            current->next = NULL;
            current->previous = snaketail;
            snaketail = current;
        }

    }
    snakehead = tail;
    while (snakehead->next != NULL)
        snakehead = snakehead->next;

    current = NULL;
    snaketail = tail;
    //移动************************************************************************************************************
    while(1)
    {
        snaketail = tail;
        food();

        poison();
        Sleep(speed);
    char ch;
    if(_kbhit())
    ch = getch();
    if(ch == -32)
    {
        ch = getch();
        if(dir != 3 && ch == UP)
            dir = 1;
        else if(dir != 2 && ch == RIGHT)
            dir = 0;
        else if(dir != 0 && ch == LEFT)
            dir = 2;
        else if(dir != 1 && ch == DOWN)
            dir = 3;

    }
    else
    switch(ch)
    {
        case 'w':
        case 'W':
        if(dir != 3)
            dir = 1;
            break;
        case 'd':
        case 'D':
        if(dir != 2)
            dir = 0 ;
            break;
        case 'a':
        case 'A':
        if(dir != 0)
            dir = 2;
            break;
        case 's':
        case 'S':
        if(dir != 1)
            dir = 3;
            break;
        default:
            fflush(stdin);
    }
    if(dir == 0)
    {
        current = tail;
        a = tail->x;
        b = tail->y;
        while (current != NULL)
        {
            current = snaketail->next;
            if (current != NULL)
            {
            snaketail->x = current->x;
            snaketail->y = current->y;
            snaketail = current;
            }
        }
        snaketail->x = snaketail->x + 2;
        snaketail = tail;
        Pos (a,b);
        printf(" ");
    }
    else if(dir == 1)
    {
        current = tail;
        a = tail->x;
        b = tail->y;
        while (current != NULL)
        {
            current = snaketail->next;
            if (current != NULL)
            {
            snaketail->x = current->x;
            snaketail->y = current->y;
            snaketail = current;
            }
        }
        snaketail->y = snaketail->y - 1;
        snaketail = tail;
        Pos (a,b);
        printf(" ");

    }
    else if(dir == 2)
    {
        current = snaketail;
        a = tail->x;
        b = tail->y;
        while (current != NULL)
        {
            current = snaketail->next;
            if (current != NULL)
            {
            snaketail->x = current->x;
            snaketail->y = current->y;
            snaketail = current;
            }
        }
        snaketail->x = snaketail->x - 2;

        snaketail = tail;
        Pos (a,b);
        printf(" ");

    }
    else
    {
        current = tail;
        a = tail->x;
        b = tail->y;
        while (current != NULL)
        {
            current = snaketail->next;
            if (current != NULL)
            {
            snaketail->x = current->x;
            snaketail->y = current->y;
            snaketail = current;
            }
        }
        snaketail->y = snaketail->y + 1;
        snaketail = tail;
        Pos (a,b);
        printf(" ");

    }
    //显示蛇
     current = NULL;
     current = tail;
     while (current != NULL)
     {
         Pos(current->x,current->y);
         printf("*");
         if (current != NULL)
         current = current->next;
     }
     //撞墙
     k = 0;
     while (1)
{
        if (snakehead->x == snaketail->x && snakehead->y == snaketail->y)
        {
            over = 0;
             Pos(0,21);
             printf("很遗憾，你输了！\n再接再励！\n");
             printf("你的得分是%d。",score);
             system("pause");
             break;
        }
        else if(snakehead->x == 0||snakehead->x == 38||snakehead->y == 0||snakehead->y == 19)
        {
            over = 0;
             Pos(0,21);
             printf("很遗憾，你输了！\n再接再励！\n");
             printf("你的得分是%d。",score);
             system("pause");
             break;
        }
     else if(k==sum-2)
     {
         snaketail = tail;
         break;
     }
     else
     {
         snaketail = snaketail->next;
         k++;
     }
 }
     //吃食物
     if (snakehead->x == foodx && snakehead->y == foody)
     {
         score++;
         foodCount--;
         sum++;
         if (sum == 40)
         {
             Pos(0,21);
             printf("你赢了！");
             printf("你的得分是%d。",score);
             system("pause");
             break;
         }
         current = (struct Snake*)malloc(sizeof(struct Snake));
         current->x = a;
         current->y = b;
         current->next = tail;
         tail->previous = current;
         tail = current;
         current = NULL;
     }
     //吃毒草
     eatPoison(poisonxy, poisonCount);

  if (over == 0)
    break;
    }
     freesnake();
}

void Pos(int x, int y)
{
    COORD pos;
    HANDLE hOutput;
    pos.X = x;
    pos.Y = y;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput,pos);

}
void food()
{

    k=0;
   while (foodCount==0)//生成食物
   {
       srand((unsigned)time(NULL));
   foodx = (rand()%(L/4))*2;
   foody = rand()%(W-2)+1;
   while (1)//避免食物生在蛇上
{
        if ((foodx == snaketail->x && foody == snaketail->y)||(poisonx == foodx&& poisony == foody))
        {
             foodx = (rand()%(L/4))*2;
             foody = rand()%(W-2)+1;
        }
     else if(k==sum-1)
     {
         snaketail = tail;
         break;
     }
     else
     {
         snaketail = snaketail->next;
         k++;
     }
           }
   if (foodx!=0   &&foody!= 0  )
    foodCount++;
    }
    //食物点
      Pos(foodx,foody);
      printf("*");
}
void poison()
{
    if(poisonCount == 0)
    {
   while (poisonCount < 3)//生成毒草
   {
       srand((unsigned)time(NULL));
       poisonx = (rand()%(L/4))*2;
       poisony = rand()%(W-2)+1;
       int i = 0;
   while (i <= sum - 1)//避免食物生在蛇上
    {
        if ((poisonx == snaketail->x && poisony == snaketail->y)||(poisonx == foodx && poisony == foody))
        {
             poisonx = (rand()%(L/4))*2;
             poisony = rand()%(W-2)+1;
             snaketail = tail;
             i = 0;
        }
        else
        {
           snaketail = snaketail->next;
         i++;
        }

    }
    snaketail = tail;
   if (poisonx != 0   && poisony != 0  )
   {
       poisonCount++;
   poisonxy[0][poisonCount - 1] = poisonx;
   poisonxy[1][poisonCount - 1] = poisony;
   if(checkPoison(poisonxy, poisonCount) == 1)
    poisonCount--;
   }

    }
    //食物点
    int i;
    for(i = 0; i < poisonCount; i++)
    {
       Pos(poisonxy[0][i],poisonxy[1][i]);
          printf("@");
    }
    }
}

void eatPoison(int npoisonxy[2][8], int nPoisonCount)
{
    int i;
    for(i = 0; i < nPoisonCount; i++)
    {
        if(snakehead->x == npoisonxy[0][i] && snakehead->y == npoisonxy[1][i])
        {
            if(i < nPoisonCount - 1)
            {
                int j;
                for(j = i; j < nPoisonCount - 1; j++)
                {
                    npoisonxy[0][j] = npoisonxy[0][j + 1];
                    npoisonxy[1][j] = npoisonxy[1][j + 1];
                }
            }
           poisonCount--;
           sum--;
           if (sum == 1)
           {
             Pos(0,21);
             printf("很遗憾，你的蛇被毒死了！\n再接再励！\n");
             printf("你的得分是%d。",score);
             system("pause");
             break;
           }
           Pos(tail->x,tail->y);
           printf(" ");
           tail = snaketail->next;
           free(snaketail);
           break;
        }
    }
}
void freesnake()
{
    struct Snake*pre;
     pre = tail;
       while(tail != NULL)
     {
         pre = tail;
         tail = pre->next;
         free (pre);
     }
     pre = NULL;
     Pos(0,25);
     printf("Bye!\n");
}

void show()
{
    int i , j;
    for (i = 0; i < W ;i++)
    {
        for(j = 0; j < L; j++)
        {
            printf("%c",map[i][j]);
        }
         printf("\n");
     }
}
