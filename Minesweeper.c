#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include<math.h>
#define ZERO 177
int x,y,empty,numbers,marks,X=30,Y=16,B=5;
void print(unsigned char table[X][Y])
{
	int i,j;
	system("cls");
	printf("%c",201);
	for(i=0;i<X-1;i++)
	printf("%c%c",205,209);
	printf("%c%c\n",205,187);
	for(i=0;i<Y-1;i++)
	{
		printf("%c",186);
		for(j=0;j<X-1;j++)
		printf("%c%c",table[j][i],179);
		printf("%c%c\n%c",table[j][i],186,199);
		for(j=0;j<X-1;j++)
		printf("%c%c",196,197);
		printf("%c%c\n",196,182);
	}
	printf("%c",186);
	for(j=0;j<X-1;j++)
	printf("%c%c",table[j][i],179);
	printf("%c%c\n%c",table[j][i],186,200);
	for(i=0;i<X-1;i++)
	printf("%c%c",205,207);
	printf("%c%c\n",205,188);
}
void spaceFill(unsigned char pin[X][Y])
{
	int i,j;
	for(i=0;i<X;i++)
	for(j=0;j<Y;j++)
	pin[i][j]=32;
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
char input()
{
	unsigned char a;
	while(1)
	{
		a=getch();
		if(a==224)
		a=getch();
		if(a=='w' || a=='W' || a==72)
		y--;
		else if(a=='a' || a=='A' || a==75)
		x--;
		else if(a=='s' || a=='S' || a==80)
		y++;
		else if(a=='d' || a=='D' || a==77)
		x++;
		else if(a==32 || a==13 || a==10 || a=='q' || a=='Q')
		return a;
		renewCursorGrid(x,y);
	}
}
unsigned char count(unsigned char table[X][Y],int i,int j)
{
	if(table[i][j]==15)
	return 15;
	int count=0,k,l;
	for(k=i-1;k<i+2;k++)
	for(l=j-1;l<j+2;l++)
	if(k>=0 && k<X && l>=0 && l<Y)
	if(table[k][l]==15)
	count++;
	if(count==0)
	return ZERO;
	return count+'0';
}
void randomize(unsigned char table[X][Y])
{
	int a,b;
	for(empty=0;empty<B;empty++)
	{
		do
		{
			a=rand()%X;
			b=rand()%Y;
		}while(table[a][b]==15 || a<=x+1 && a>=x-1 && b<=y+1 && b>=y-1);
		table[a][b]=15;
	}
	for(a=0;a<X;a++)
	for(b=0;b<Y;b++)
	table[a][b]=count(table,a,b);
}
int crash(unsigned char table[X][Y],unsigned char table2[X][Y])
{
	for(x=0;x<X;x++)
	for(y=0;y<Y;y++)
	if(table[x][y]==15)
	if(table2[x][y]==' ')
	table2[x][y]=table[x][y];
	else if(table2[x][y]=='!')
	table2[x][y]=1;
	else if(table2[x][y]=='?')
	table2[x][y]=2;
	print(table2);
	printf("\nLegend:\n%c=%c+!\n%c=%c+?",1,15,2,15);
	getch();
	return 1;
}
void revealArea2(unsigned char table[X][Y],unsigned char table2[X][Y],int x1,int y1)
{
	if(x1==-1 || x1==X || y1==-1 || y1==Y)
	return;
	int check=0,tempx=x1,tempy=y1;
	if(table2[x1][y1]!=table[x1][y1])
	{
		check=1;
		table2[x1][y1]=table[x1][y1];
		renewCursorGrid(x1,y1);
		printf("%c",table2[x][y]);
		numbers--;
	}
	if(table[x][y]==ZERO && check)
	for(x1=tempx-1;x1<=tempx+1;x1++)
	for(y1=tempy-1;y1<=tempy+1;y1++)
	revealArea2(table,table2,x1,y1);
}
void revealArea(unsigned char table[X][Y],unsigned char table2[X][Y])
{
	int tempx=x,tempy=y;
	revealArea2(table,table2,tempx,tempy);
	renewCursorGrid(tempx,tempy);
}
int victory()
{
	renewCursor(0,Y*2+4);
	printf("Victorius!");
	getch();
	return 1;
}
startingValues(int a,int b,int c)
{
	X=a;
	Y=b;
	B=c;
	x=(X+1)/2-1;
	y=(Y+1)/2-1;
	empty=-1;
	numbers=X*Y-B;
	marks=B;
}
int welcome()
{
	unsigned char a;
	system("cls");
	printf("%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c:\n1. %c%c%c%c%c%c%c%c (9x9-10)\n2. %c%c%c%c%c%c%c (16x16-40)\n3. %c%c%c%c%c%c%c%c%c%c%c%c (30x16-99)\n4. Custom\n0. Quit\n",132,167,229,167,156,155,166,155,172,169,161,166,162,229,152,170,128,168,174,225,168,160,166,170,139,226,171,168,160,166,170,143,168,166,174,224,168,158,163,226,164,166,170);
	do
	{
		a=getch();
	}while(a<'0' || a>'4');
	if(a=='0')
	return 1;
	else if(a=='1')
	startingValues(9,9,10);
	else if(a=='2')
	startingValues(16,16,40);
	else if(a=='3')
	startingValues(30,16,99);
	else if(a=='4')
	{
		int pin[3]={X,Y,B},pin2[3]={log10(X)+1,log10(Y)+1,log10(B)+1},temp=0;
		system("cls");
		printf("1. %c%c%c%c%c%c (X) : %d\n2. %c%c%c%c   (Y) : %d\n3. %c%c%c%c%c%c     : %d\n\nq. Return",143,162,225,171,166,170,pin[0],239,175,166,170,pin[1],129,230,163,153,156,170,pin[2]);
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
		}while(a!=10 && a!=13 || pin[0]<5 || pin[1]<5 || pin[2]<5 || pin[0]>256 || pin[1]>256 || pin[2]>pin[0]*pin[1]-16);
		startingValues(pin[0],pin[1],pin[2]);
	}
	return 0;
}
void mark(unsigned char table[X][Y],unsigned char table2[X][Y],char a,int b)
{
	table2[x][y]=a;
	if(table[x][y]==15)
	empty+=b;
	else
	empty-=b;
	marks+=b;
	int tempx=x,tempy=y;
	renewCursor(0,Y*2+2);
	printf("Bombs remaining : %d   ",marks);
	renewCursorGrid(tempx,tempy);
}
int move()
{
	unsigned char a;
	while(a=welcome())
	if(a==1)
	return 0;
	unsigned char table[X][Y],table2[X][Y];
	spaceFill(table);
	spaceFill(table2);
	print(table);
	mark(table,table2,' ',0);
	while(1)
	{
		a=input();
		if(a==13 || a==10)
		{
			if(empty>=0 && table2[x][y]==' ')
			mark(table,table2,'!',-1);
			else if(table2[x][y]=='!')
			mark(table,table2,'?',1);
			else if(table2[x][y]=='?')
			table2[x][y]=' ';
			printf("%c\b",table2[x][y]);
			if(empty==0)
			return victory();
		}
		else if(a==32)
		{
			if(empty==-1)
			randomize(table);
			if(table[x][y]==15 && table2[x][y]!='!')
			{
				table2[x][y]='*';
				return crash(table,table2);
			}
			if(table[x][y]==ZERO)
			revealArea(table,table2);
			if(table[x][y]!=table2[x][y] && table2[x][y]!='!')
			{
				table2[x][y]=table[x][y];
				printf("%c\b",table[x][y]);
				numbers--;
			}
			if(numbers==0)
			return victory();
		}
		else if(a=='q' || a=='Q')
		{
			printf("Are you sure you want to quit? (y/n) ");
			do
			{
				a=getch();
				if(a=='y' || a=='Y')
				return crash(table,table2);
			}while(a!='n' && a!='N');
			print(table2);
			mark(table,table2,table2[x][y],0);
		}
	}
}
int main()
{
	srand(time(0));
	while(move());
	system("pause");
}
