#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define M 20    //��ͼ��С
#define L 50    //�ߵĳ���
//j�Ժ����꣬i��������
void show();//��ʾ
void food();
void remap();
void du();
void snakelife();
void tip();

wchar_t map[M][M];
int a;//�û������ж���Ϸ��ʼ
int foodx,foody;//ʳ������
int foodCount = 0;//ʳ������
int dux,duy;//��������
int duCount;//��������
int snake[L][2];//��
int score;
int over = 1;
int k;//�ڵ�
int sum = 4;//�ߵĳ�ʼ����

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
     else if (a == 2)//��Ϸ˵��
     {
         printf("1�� * Ϊʳ��Ե����߳��ȼ�1��\n    @ Ϊ���ݳԵ����߳��ȼ�1��\n");
         printf("2�����߳���Ϊ40ʱ���ʤ����\nײǽ��ҧ���Լ����ʧ�ܡ�\n");
         printf("w s a d Ϊ�������w Ϊ�� sΪ�� aΪ�� dΪ�ҡ�\n");
         printf("���ͣ�ȥ��ȡ��Ϸʤ����\n");
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
    printf ("��ӭ����̰������Ϸ\n");
    printf("    1����ʼ��Ϸ\n");
    printf("    2����Ϸ˵��\n");
    printf("    3���˳�\n");
    printf("���������ѡ��");
    scanf("%d",&a);
    while (a != 1 && a != 2 && a != 3)
    {
        fflush(stdin);
        printf("��������ȷ����");
        scanf("%d",&a);


    }

}

//��ʾ
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
//��
void snakelife()
{
    int i, j;
    int dir = 0;//0  d���ң�1  w���ϣ�2  a����3 s����
    char ch = 'd';
    //�տ�ʼ����10���ſ��Ľ�
    //snake[i][0]Ϊ�����꣬snake[i][1]Ϊ������
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
//��ʾ��
    for(k = 0; k < sum; k++)
    {
         for (i = 0; i < M; i++)
    {
        for(j = 0; j < M; j++)
        {
            if(i==snake[k][1]&&j==snake[k][0])//1��Ӧi    0��Ӧj
            {
              map[i][j] = '*';//��ʾ����

            }

            else
             continue;
        }
    }
    }
        show();
      Sleep(200);
    system("cls");
   //ת��
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
//�˶�
       if (dir == 0)//����
       {
           for(k = 1;k < sum;k++)
           {
               if (snake[0][0]+1 == snake[k][0]&&snake[0][1] == snake[k][1])
                      {
                      printf("�����ˣ��������������Ϸ��\n");
                      printf("��ĵ÷���%d \n",score);
                      system("pause");
                      return;
                      }
               else if(snake[0][0]+1 == 0||snake[0][0]+1 ==M-1)
                        {
                      printf("�����ˣ��������������Ϸ��\n");
                      printf("��ĵ÷���%d \n",score);
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
       else if(dir == 1)//����
       {
              for(k = 1;k < sum;k++)
           {
               if (snake[0][1]-1 == snake[k][1]&&snake[0][0] == snake[k][0])
                      {
                      printf("�����ˣ��������������Ϸ��\n");
                      printf("��ĵ÷���%d \n",score);
                      system("pause");
                      return;
                      }
               else if(snake[0][1]-1 == 0||snake[0][1]-1 ==M-1)
                        {
                      printf("�����ˣ��������������Ϸ��\n");
                      printf("��ĵ÷���%d \n",score);
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
       else if(dir == 2)//����
       {
                      for(k = 1;k < sum;k++)
           {
               if (snake[0][0]-1 == snake[k][0]&&snake[0][1] == snake[k][1])
                      {
                      printf("�����ˣ��������������Ϸ��\n");
                      printf("��ĵ÷���%d \n",score);
                      system("pause");
                      return;
                      }
               else if(snake[0][0]-1 == 0||snake[0][0]-1 ==M-1)
                        {
                      printf("�����ˣ��������������Ϸ��\n");
                      printf("��ĵ÷���%d \n",score);
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
                      printf("�����ˣ��������������Ϸ��\n");
                      printf("��ĵ÷���%d \n",score);
                      system("pause");
                      return;
                      }
               else if(snake[0][1]+1 == 0||snake[0][1]+1 ==M-1)
                        {
                      printf("�����ˣ��������������Ϸ��\n");
                      printf("��ĵ÷���%d \n",score);
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
      //�Ե�ʳ��
       if (snake[0][0] == foody&&snake[0][1] == foodx )
            {
                score++;
                sum++;
                if (sum == 40)
                {
                    printf ("��Ӯ�ˣ�̫�����ˣ������Ǹ����֡�\n");
                    printf("��ĵ÷���%d \n",score);
                    system ("pause");
                    return;

                }
                snake[sum-1][0] = snake[sum-2][0];
                snake[sum-1][1] = snake[sum-2][1];
                foodCount--;
                food();
            }
     //�Ե�����
       else if (snake[0][0] == duy&&snake[0][1] == dux )///����
            {
                score--;
                map[snake[sum-1][1]][snake[sum-1][0]] = ' ';
                sum--;
                if (sum == 0)
                {
                    printf("������߶����ˡ�\n��ĵ÷���%d \n",score);
                    printf("����������ء�");
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
//����ʳ��
void food()
{
    int i,j;
    k=0;
   while (foodCount==0)//����ʳ��
   {
       srand((unsigned)time(NULL));
   foodx = rand()%(M-2)+1;
   foody = rand()%(M-2)+1;
   while (over == 1)//����ʳ����������
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
    //ʳ���
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
//��ͼ*******************************************************************************************************************
void remap()
{
    int i;//��ʾ������
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
   while (duCount==0)//���ɶ���
   {
       srand((unsigned)time(NULL));
       dux = rand()%(M-2)+1;
       duy = rand()%(M-2)+1;
   while (over == 1)//���ⶾ����������
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
    //ʳ���
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

