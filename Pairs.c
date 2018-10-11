#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include<math.h>
int X=1,Y=2,x,y,L=121,count,moves;
void print(char table[X][Y])
{
	int i,j,x,y;
	system("cls");
	printf("%c",201);
	x=X-1;
	for(i=0;i<x;i++)
	printf("%c%c",205,209);
	printf("%c%c\n",205,187);
	y=Y-1;
	for(i=0;i<y;i++)
	{
		printf("%c",186);
		for(j=0;j<x;j++)
		printf("%c%c",table[j][i],179);
		printf("%c%c\n%c",table[j][i],186,199);
		for(j=0;j<x;j++)
		printf("%c%c",196,197);
		printf("%c%c\n",196,182);
	}
	printf("%c",186);
	for(j=0;j<x;j++)
	printf("%c%c",table[j][i],179);
	printf("%c%c\n%c",table[j][i],186,200);
	for(i=0;i<x;i++)
	printf("%c%c",205,207);
	printf("%c%c\n",205,188);
}
char asciiOf(int a)
{
	a%=L;
	if(a>25)
	a+=7;
	else if(a>7)
	a+=6;
	else if(a>5)
	a+=5;
	else
	a++;
	return a;
}
void charFill(char pin[X][Y],char a)
{
	int i,j;
	for(i=0;i<X;i++)
	for(j=0;j<Y;j++)
	pin[i][j]=a;
}
startingValues(int a,int b,int c)
{
	X=a;
	Y=b;
	L=c;
	x=0;
	y=0;
	moves=0;
}
void renewCursor(int tempx,int tempy)
{
	x=tempx;
	y=tempy;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}
void renewCursorGrid(int tempx,int tempy)
{
	x=tempx;
	y=tempy;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x*2+1,y*2+1});
}
int welcome()
{
	unsigned char a;
	system("cls");
	printf("%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c:\n1. %c%c%c%c%c%c%c%c (13x4-26)\n2. %c%c%c%c%c%c%c (14x6-41)\n3. %c%c%c%c%c%c%c%c%c%c%c%c (15x8-58)\n4. Hyper-Pro (18x10-90)\n5. Bitch, I'm a computer! (22x11-121)\n6. Custom\n0. Quit\n",132,167,229,167,156,155,166,155,172,169,161,166,162,229,152,170,128,168,174,225,168,160,166,170,139,226,171,168,160,166,170,143,168,166,174,224,168,158,163,226,164,166,170);
	do
	{
		a=getch();
	}while(a<'0' || a>'6');
	if(a=='0')
	return 1;
	else if(a=='1')
	startingValues(13,4,26);
	else if(a=='2')
	startingValues(14,6,41);
	else if(a=='3')
	startingValues(15,8,58);
	else if(a=='4')
	startingValues(18,10,90);
	else if(a=='5')
	startingValues(22,11,121);
	else if(a=='6')
	{
		int pin[3]={X,Y,L},pin2[3]={log10(X)+1,log10(Y)+1,log10(L)+1},temp=0;
		system("cls");
		printf("1. %c%c%c%c%c%c (X) : %d\n2. %c%c%c%c   (Y) : %d\n3. %c%c%c%c%c%c%c    : %d\n\nq. Return",143,162,225,171,166,170,pin[0],239,175,166,170,pin[1],145,231,163,153,166,162,152,pin[2]);
		do
		{
			renewCursor(16+pin2[temp],temp);
			a=getch();
			if(a=='q' || a=='Q')
			return 2;
			if(a>='0' && a<='9' && pin2[temp]<8)
			{
				pin[temp]=pin[temp]*10+a-'0';
				pin2[temp]++;
				putchar(a);
			}
			else if(a=='\b')
			{
				pin[temp]/=10;
				pin2[temp]--;
				printf("\b \b");
			}
			if((a==10 || a==13 || a=='d' || a=='D' || a==77 || a=='s' || a=='S' || a==80) && temp<2)
			temp++;
			else if((a=='w' || a=='W' || a==72 || a=='a' || a=='A' || a==75) && temp>0)
			temp--;
		}while(a!=10 && a!=13 || pin[0]<1 || pin[1]<1 || pin[2]<1 || pin[0]>256 || pin[1]>256 || pin[2]>121 || pin[0]*pin[1]%2);
		startingValues(pin[0],pin[1],pin[2]);
	}
	return 0;
}
char input()
{
	unsigned char a;
	while(1)
	{
		a=getch();
		if(a==224)
		a=getch();
		if((a=='w' || a=='W' || a==72) && y>0)
		y--;
		else if((a=='a' || a=='A' || a==75) && x>0)
		x--;
		else if((a=='s' || a=='S' || a==80) && y<Y-1)
		y++;
		else if((a=='d' || a=='D' || a==77) && x<X-1)
		x++;
		else if(a==32 || a=='q' || a=='Q')
		return a;
		renewCursorGrid(x,y);
	}
}
int randomize(char table[X][Y],char table2[X][Y])
{
	char a;
	int i,temp,tempi,tempj;
	charFill(table,' ');
	charFill(table2,0);
	for(i=0;i<count;i++)
	{
		temp=2;
		a=asciiOf((char)i);
		do
		{
			tempi=rand()%X;
			tempj=rand()%Y;
			if(table2[tempi][tempj]==0)
			{
				table2[tempi][tempj]=a;
				temp--;
			}
		}while(temp);
	}
}
void victory()
{
	renewCursor(0,Y*2+3);
	printf("Victorius!\n%d moves for %d pairs!\n\nPress any key to restart\n",moves,X*Y/2);
	getch();
}
int pairs()
{
	unsigned char a;
	while(a=welcome())
	if(a==1)
	return 0;
	char table[X][Y],table2[X][Y];
	int i,ex,ey;
	count=X*Y/2;
	randomize(table,table2);
	print(table);
	renewCursorGrid(0,0);
	while(count)
	{
		i=0;
		while(i<2)
		{
			a=input();
			if(a==' ' && table[x][y]==' ')
			{
				if(i==0)
				{
					ex=x;
					ey=y;
				}
				table[x][y]=table2[x][y];
				putchar(table[x][y]);
				putchar('\b');
				i++;
			}
			else if(a=='q' || a=='Q')
			{
				printf("Are you sure you want to quit? (y/n) ");
				do
				{
					a=getch();
					if(a=='y' || a=='Y')
					return 1;
				}while(a!='n' && a!='N');
				print(table);
				renewCursorGrid(x,y);
			}
		}
		if(table2[x][y]==table2[ex][ey])
		count--;
		else
		{
			getch();
			int x1=x,y1=y;
			renewCursorGrid(ex,ey);
			printf(" ");
			table[x][y]=' ';
			renewCursorGrid(x1,y1);
			printf(" \b");
			table[x][y]=' ';
		}
		moves++;
	}
	victory();
	return 1;
}
int main()
{
	srand(time(0));
	while(pairs());
	system("pause");
}
