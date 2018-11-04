#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define W 20 //地图宽度
#define L 40 //地图长度
#define S 4//初始化蛇长+1

void Pos(int x, int y);//光标
void food();
void du();
void tip();


char map[W][L];
int k;//
int sum = 5;//蛇的总长
int foodx,foody;//食物坐标
int foodCount = 0;//食物数量
int dux,duy;//毒草坐标
int duCount;//毒草数量
int a = 0;
signed int score = 0;//得分
int over = 1;//1继续，0结束
int nandu = 0;//难度
int sudu = 0;//速度

struct Snake{
   int x;
   int y;
   struct Snake*next;
}*current,*snaketail,*head,*snakehead;


void show();
void remap();
void snakelife();
void freesnake();

int main()
{

    while (1)
    {
     tip();
     if (a == 1)
     {
         printf("请选择难度：\n1、初级\n2、中级\n3、高级\n请选择：");
         scanf("%d",&nandu);
         while(nandu != 1 && nandu != 2 && nandu != 3)
         {
             fflush(stdin);
             printf("请输入正确数字");
             scanf("%d",&nandu);
         }
         if (nandu == 1)
            sudu = 800;
         else if(nandu == 2)
            sudu = 400;
         else
            sudu = 100;

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
     }
    }






    return 0;
}
void remap()
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
void snakelife()
{
    int i = 0;
    int dir = 2;//方向
    int a,b;//擦除的坐标
    score = 0;
    sum = 5;
    foodCount = 0;
    over = 1;
    duCount = 0;
    current = NULL;
    snaketail = NULL;
    head = NULL;
    snakehead = NULL;
    //初始化蛇
    snaketail = (struct Snake*)malloc(sizeof(struct Snake)) ;
    snaketail->x = 20;
    snaketail->y = 10;
    snaketail->next = NULL;
    head = snaketail;
    for (i = 0; i < S; i++)
    {
        current = (struct Snake*)malloc(sizeof(struct Snake));
        snaketail->next = current;
        current->x = snaketail->x -2;
        current->y = snaketail->y;
        current->next = NULL;
        snaketail = current;
    }
    snakehead = head;
    while (snakehead->next != NULL)
        snakehead = snakehead->next;
    current = NULL;
    snaketail = head;
    //移动************************************************************************************************************
    while(1)
    {
        snaketail = head;
        food();

        du();
        Sleep(sudu);
    char ch;
    if(_kbhit())
    ch = getch();
    switch(ch)
    {
        case 'w':
        if(dir != 3)
            dir = 1;
            break;
        case 'd':
        if(dir != 2)
            dir = 0 ;
            break;
        case 'a':
        if(dir != 0)
            dir = 2;
            break;
        case 's':
        if(dir != 1)
            dir = 3;
            break;
        default:
            fflush(stdin);
    }
    if(dir == 0)
    {
        current = head;
        a = head->x;
        b = head->y;
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
        snaketail = head;
        Pos (a,b);
        printf(" ");
    }
    else if(dir == 1)
    {
        current = head;
        a = head->x;
        b = head->y;
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
        snaketail = head;
        Pos (a,b);
        printf(" ");

    }
    else if(dir == 2)
    {
        current = snaketail;
        a = head->x;
        b = head->y;
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

        snaketail = head;
        Pos (a,b);
        printf(" ");

    }
    else
    {
        current = head;
        a = head->x;
        b = head->y;
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
        snaketail = head;
        Pos (a,b);
        printf(" ");

    }

    //显示蛇
     current = NULL;
     current = head;
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
         snaketail = head;
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
         current->next = head;
         head = current;
         current = NULL;

     }
     //吃毒草
     if (snakehead->x == dux && snakehead->y == duy)
     {
         duCount--;
         sum--;
         if (sum == 1)
         {
             Pos(0,21);
             printf("很遗憾，你的蛇被毒死了！\n再接再励！\n");
             printf("你的得分是%d。",score);
             system("pause");
             break;
         }
         Pos(head->x,head->y);
         printf(" ");
         /*Pos(0,22);
         printf("%p  ",head);
         printf("%p  ",snaketail);
         printf("%p  ",snaketail->next);
         system("pause");*/
         head = snaketail->next;
         free(snaketail);

     }

  if (over == 0)
    break;


    }
     freesnake();
}
void freesnake()
{
    struct Snake*pre;
     pre = head;
       while(head != NULL)
     {
         pre = head;
         head = pre->next;
         free (pre);
     }
     pre = NULL;
     Pos(0,25);
     printf("Bye!\n");
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

        if ((foodx == snaketail->x && foody == snaketail->y)||(dux == foodx&& duy == foody))
        {
             foodx = (rand()%(L/4))*2;
             foody = rand()%(W-2)+1;
        }

     else if(k==sum-1)
     {
         snaketail = head;
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
void du()
{

    k=0;
   while (duCount==0)//生成食物
   {
       srand((unsigned)time(NULL));
   dux = (rand()%(L/4))*2;
   duy = rand()%(W-2)+1;
   while (1)//避免食物生在蛇上
{

        if ((dux == snaketail->x && duy == snaketail->y)||(dux == foodx&& duy == foody))
        {
             dux = (rand()%(L/4))*2;
             duy = rand()%(W-2)+1;
        }

     else if(k == sum-1)
     {
         snaketail = head;
         break;
     }
     else
     {
         snaketail = snaketail->next;
         k++;
     }


           }
   if (dux!=0   &&duy!= 0  )
    duCount++;
    }
    //食物点
      Pos(dux,duy);
      printf("@");
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
