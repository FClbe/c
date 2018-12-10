#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#define W 20 //��ͼ���
#define L 40 //��ͼ����
#define S 4//��ʼ���߳�+1
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define ENTER 13

void show();
void remap();
void snakelife();
void freesnake();
void Pos(int x, int y);//���
void food();
void poison();
void tip(int a);
int checkPoison(int npoisonxy[2][8], int npoisonCount);
void eatPoison(int npoisonxy[2][8], int nPoisonCount);

#endif // SNAKE_H_INCLUDED
