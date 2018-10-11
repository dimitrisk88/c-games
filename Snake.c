#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#define X 16
#define Y 12
typedef struct snake
{
	int x;
	int y;
	int print;
}Snake;
Snake dot,snake[X*Y];
char b,c;
int j,difficulty;
void printTable()
{
	int a,i,k;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){0,0});
	printf("%c",218);
	for(i=0;i<X;i++)
	printf("%c",196);
	printf("%c\n",191);
	for(i=0;i<Y;i++)
	{
		printf("%c",179);	
		for(k=0;k<X;k++)
		{
			for(a=0;a<=j;a++)
			{
				if(snake[a].x==k && snake[a].y==i)
				{
					printf("%c",snake[a].print);
					a=0;
					break;
				}
			}
			if(dot.x==k && dot.y==i)
			printf("%c",254);
			else if(a!=0)
			printf(" ");
		}
		printf("%c\n",179);
	}
	printf("%c",192);
	for(i=0;i<X;i++)
	printf("%c",196);
	printf("%c\n\n%d",217,(j-3)*difficulty);
}
void crash()
{
	int i;
	sleep(200);
	while(kbhit())
	getch();
	while(1)
	{
		printTable();
		printf("\n\nPress any key to restart ");
		sleep(500);
		if(kbhit())
		break;
		system("cls");
		for(i=0;i<Y;i++)
		printf("\n");
		printf("\n\n\n%d\n\nPress any key to restart ",(j-3)*difficulty);
		sleep(500);
		if(kbhit())
		break;
	}
}
int checkCrash(Snake head,int a,int b)
{
	int i;
	if(snake[j].x+a==-1 || snake[j].x+a==X || snake[j].y+b==-1 || snake[j].y+b==Y)
	return 1;
	for(i=1;i<j-2;i++)
	if(head.x+a==snake[i].x && head.y+b==snake[i].y)
	return 1;
	return 0;
}
int dotOk()
{
	int i;
	for(i=0;i<=j;i++)
	if(dot.x==snake[i].x && dot.y==snake[i].y)
	return 1;
	return 0;
}
void eatdot(int a,int b,int c)
{
	int i;
	snake[j+1].x=snake[j].x;
	snake[j+1].y=snake[j].y;
	snake[++j].print=a;
	do
	{
		dot.x=rand()%X;
		dot.y=rand()%Y;
	}while(dot.x==snake[j].x+b && dot.y==snake[j].y+c || dotOk());
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){dot.x+1,dot.y+1});
	printf("%c",254);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){0,Y+3});
	printf("%d",(j-3)*difficulty);
}
void moveSnake3()
{
	int i=0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){snake[0].x+1,snake[0].y+1});
	printf(" ");
	while(i<j)
	snake[i]=snake[++i];
}
int moveSnake2(int a,int b,int pr1,int pr2,int pr3,int pr4)
{
	if(checkCrash(snake[j],a,b))
	{
		crash();
		return 0;
	}
	if(snake[j].print==pr1)
	if(snake[j].y>snake[j-1].y && a || snake[j].x>snake[j-1].x && b)
	snake[j].print=pr2;
	else
	snake[j].print=pr3;
	if(snake[j].x+a==dot.x && snake[j].y+b==dot.y)
	eatdot(pr4,a,b);
	else
	moveSnake3();
	snake[j].x+=a;
	snake[j].y+=b;
	if(snake[j].print==pr2 || snake[j].print==pr3)
	snake[j].print=pr4;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){snake[j-1].x+1,snake[j-1].y+1});
	printf("%c",snake[j-1].print);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){snake[j].x+1,snake[j].y+1});
	printf("%c\b",snake[j].print);
	return 1;
}
char input()
{
	char a=32;
	while(kbhit())
	{
		a=getch();
		if(a=='w' || a=='W' || a==72)
		return 'u';
		if(a=='a' || a=='A' || a==75)
		return 'l';
		if(a=='s' || a=='S' || a==80)
		return 'd';
		if(a=='d' || a=='D' || a==77)
		return 'r';
	}
	if(a==32)
	return 0;
	return 1;
}
int moveSnake()
{
	int i,a;
	sleep(500-(int)(difficulty*46.5));
	if(kbhit() || c)
	do
	{
		do
		{
			a=input();
		}while(kbhit() && ((a=='u' || a=='d') && (b=='u' || b=='d') || (a=='l' || a=='r') && (b=='l' || b=='r')));
		if(a=='u' && b!='d' || a=='l' && b!='r' || a=='d' && b!='u' || a=='r' && b!='l')
		b=a;
		if(a==0)
		sleep(50);
	}while(a==0);
	c=0;
	if(b=='u')
	return moveSnake2(0,-1,205,188,200,186);
	if(b=='l')
	return moveSnake2(-1,0,186,188,187,205);
	if(b=='d')
	return moveSnake2(0,1,205,187,201,186);
	if(b=='r')
	return moveSnake2(1,0,186,200,201,205);
	return 1;
}
int main()
{
	int i;
	srand(time(0));
start:
	j=2;
	c=1;
	b='r';
	for(i=0;i<3;i++)
	{
		snake[i].x=X/2-2+i;
		snake[i].y=Y/2;
		snake[i].print=205;
	}
	eatdot(205,1,0);
	system("cls");
	snake[j].x+=1;
	printf("%c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c (1-9)",131,160,225,162,156,165,156,156,167,229,167,156,155,166,155,172,169,161,166,162,229,152,170);
	do
	{
		difficulty=getch();
	}while(difficulty<49 || difficulty>58);
	difficulty-=48;
	system("cls");
	printTable();
	while(moveSnake());
	getch();
	goto start;
}
