#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "snake.h"

extern int speed;
extern int difficult;
extern struct Snake *snakehead;
extern struct Snake *snaketail;
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
void tip(int a)
{
    int flag = 0;
    remap();
    while(flag ==0)
    {
        remap();
        int nx = 10; int ny = 6;
        Pos(nx, ny);printf(">");
        a = 1;
        Pos(10, 5);printf ("��ӭ����̰������Ϸ\n");
        Pos(11, 6);printf(" 1����ʼ��Ϸ\n");
        Pos(11, 7);printf(" 2����Ϸ˵��\n");
        Pos(11, 8);printf(" 3���˳�\n");
        char ch;
        while((ch = getch()) != ENTER)
        {
            if(ch == -32)
            {
                ch = getch();
                if(ch == UP)
                {
                    a--;
                    if(a == 0)
                        a = 3;
                }
                else if(ch == DOWN)
                {
                    a++;
                    if(a == 4)
                        a = 1;
                }
            }
            Pos(nx, ny);printf("  ");
            Pos(10, 5 + a);printf(">");
            ny = 5 + a;
        }

        if (a == 1)
     {
         system("cls");
         remap();
         Pos(10, 5);printf ("��ѡ���Ѷȣ�\n");
         Pos(11, 6);printf("1.����\n");
         Pos(11, 7);printf("2.�м�\n");
         Pos(11, 8);printf("3.�߼�\n");
         int nx2 = 10; int ny2 = 6;
         Pos(nx2, ny2);printf(">");
         difficult = 1;
         while((ch = getch()) != ENTER)
        {
            if(ch == -32)
            {
                ch = getch();
                if(ch == UP)
                {
                    difficult--;
                    if(difficult == 0)
                        difficult = 3;
                }
                else if(ch == DOWN)
                {
                    difficult++;
                    if(difficult == 4)
                        difficult = 1;
                }
            }
            Pos(nx, ny);printf(" ");
            Pos(10, 5 + difficult);printf(">");
            ny = 5 + difficult;
        }
         if (difficult == 1)
            speed = 600;
         else if(difficult == 2)
            speed = 255;
         else
            speed = 100;
            flag = 1;

         /*remap();
         snakelife();
         system("cls");
         continue;*/
     }
     else if (a == 2)//��Ϸ˵��
     {
         system("cls");
         remap();
         Pos(5, 5);printf("1.* Ϊʳ��Ե����߳��ȼ�1��");
         Pos(5, 6);printf("2.@ Ϊ���ݳԵ����߳��ȼ�1��\n");
         Pos(5, 7);printf("3.���߳���Ϊ40ʱ���ʤ��");
         Pos(5, 8);printf("4.ײǽ��ҧ���Լ������ߵĳ���ֻ��");
         Pos(5, 9);printf("1���ʧ�ܡ�");
         Pos(5, 10);printf("w s a d Ϊ�����");
         Pos(5, 11);printf("w Ϊ�� sΪ�� aΪ�� dΪ�ҡ�");
         Pos(5, 12);printf("���ͣ�ȥ��ȡ��Ϸʤ����");
         Pos(5, 13);system ("pause");
         continue;
     }
     else
     {
         Pos(0, 21);
         exit(0);
     }
    }


}

 int checkPoison(int npoisonxy[2][8], int npoisonCount)
{
      if(npoisonCount == 1)
        return 0;
      else
      {
          int i;
        for(i = 0; i < npoisonCount - 1; i++)
        {
            if(npoisonxy[0][npoisonCount - 1] == npoisonxy[0][i])
            {
                if(npoisonxy[1][npoisonCount - 1] == npoisonxy[1][i])
                    return 1;
            }
        }
      }
      return 0;
}
