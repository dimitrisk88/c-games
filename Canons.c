#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<math.h>
int X=20,Y=20,P=0;
void renewCursor(int x,int y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}
void print(unsigned char table[X])
{
	int i,j;
	system("cls");
	printf("%c",201);
	for(i=0;i<X;i++)
	printf("%c",205);
	printf("%c",187);
	for(i=1;i<=Y;i++)
	{
		renewCursor(0,i);
		printf("%c",186);
		for(j=0;j<X;j++)
		if(table[j]>Y-i)
		printf("%c",177);
		else
		printf(" ");
		printf("%c",186);
	}
	renewCursor(0,i);
	printf("%c",200);
	for(i=0;i<X;i++)
	printf("%c",205);
	printf("%c",188);
}
int analogue(int x,int y)
{
	int i,j,sum=0;
	renewCursor(x,y);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,187);
	renewCursor(x,y+1);
	printf("%c          %c",186,186);
	renewCursor(x,y+2);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,188);
	renewCursor(x+1,y+1);
	for(i=0;i<2000 && GetKeyState(VK_SPACE)>>1;i++)
	{
		sleep(1);
		sum+=1;
		if(i%200==99)
		printf("%c",176);
		else if(i%200==199)
		printf("\b%c",219);
	}
	while(GetKeyState(VK_SPACE)>>1)
	sleep(50);
	while(kbhit())
	getch();
	renewCursor(x,y+4);
	printf("%d ",sum);
	return sum;
}
startingValues(int a,int b,int c)
{
	X=a;
	Y=b;
	P=Y*c/20;
}
int welcome()
{
	unsigned char a;
	system("cls");
	printf("%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c:\n1. %c%c%c%c%c%c%c%c\n2. %c%c%c%c%c%c%c\n3. %c%c%c%c%c%c%c%c%c%c%c%c\n4. Custom\n0. Quit\n",132,167,229,167,156,155,166,155,172,169,161,166,162,229,152,170,128,168,174,225,168,160,166,170,139,226,171,168,160,166,170,143,168,166,174,224,168,158,163,226,164,166,170);
	do
	{
		a=getch();
	}while(a<'0' || a>'4');
	if(a=='0')
	return 1;
	else if(a=='1')
	startingValues(rand()%335+20,rand()%135+20,15);
	else if(a=='2')
	startingValues(rand()%335+20,rand()%135+20,17);
	else if(a=='3')
	startingValues(rand()%335+20,rand()%135+20,19);
	else if(a=='4')
	{
		int pin[3]={X,Y,P},pin2[3]={log10(X)+1,log10(Y)+1,log10(P)+1},temp=0;
		system("cls");
		printf("1. %c%c%c%c%c%c (X) : %d\n2. %c%c%c%c   (Y) : %d\n3. %c%c%c%c%c%c%c    : %d\n\nq. Return",143,162,225,171,166,170,pin[0],239,175,166,170,pin[1],132,167,229,167,156,155,166,pin[2]);
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
			else if(a=='\b' && pin[temp])
			{
				pin[temp]/=10;
				pin2[temp]--;
				printf("\b \b");
			}
			if((a==10 || a==13 || a=='d' || a=='D' || a==77 || a=='s' || a=='S' || a==80) && temp<2)
			temp++;
			else if((a=='w' || a=='W' || a==72 || a=='a' || a=='A' || a==75) && temp>0)
			temp--;
		}while(a!=10 && a!=13 || pin[0]<20 || pin[1]<20 || pin[2]<0 || pin[0]>350 || pin[1]>150 || pin[2]>19);
		startingValues(pin[0],pin[1],pin[2]);
	}
	return 0;
}
void randomize(unsigned char table[X])
{
	int i,j,temp=Y/(X/7)+1;
	do
	{
		for(i=0;i<X;i++)
		table[i]=0;
		i=X/2;
		table[i]=P;
		if(X%2==0)
		i--;
		table[i]=P;
		for(i--;i && table[i+1]<=P;i--)
		table[i]=table[i+1]-rand()%temp;
		table[i+1]=0;
		for(i=X/2+1;table[i-1]<=P;i++)
		table[i]=table[i-1]-rand()%temp;
		table[i-1]=0;
	}while(table[5] || table[X-6]);
}
void printTurretLine(char a,char pl,int y)
{
	int i;
	if(pl)
	renewCursor(X-2,y);
	else
	renewCursor(1,y);
	if(pl)
	i=2;
	else
	i=0;
	while(i>=0 && i<=2)
	{
		if(a&(1<<(2-i)))
		printf("%c",254);
		else
		printf(" ");
		if(pl)
		i--;
		else
		i++;
	}
}
void printTurret(float a,char pl)
{
	if(a<2.5)
	printTurretLine(0,pl,Y-2);
	else if(a<3.5)
	printTurretLine(1,pl,Y-2);
	else if(a<5.5)
	printTurretLine(2,pl,Y-2);
	else
	printTurretLine(4,pl,Y-2);
	if(a<0.5)
	printTurretLine(0,pl,Y-1);
	else if(a<1.5)
	printTurretLine(1,pl,Y-1);
	else if(a<2.5)
	printTurretLine(3,pl,Y-1);
	else if(a<4.5)
	printTurretLine(2,pl,Y-1);
	else
	printTurretLine(4,pl,Y-1);
	if(a<0.5)
	printTurretLine(7,pl,Y);
	else if(a<1.5)
	printTurretLine(6,pl,Y);
	else
	printTurretLine(4,pl,Y);
}
void move(char a,char pl,float*c)
{
	c+=pl;
	int temp=*c+0.5;
	float add=0.01;
	if(a=='d')
	add=-add;
	while((a=='u' && *c<6 && (GetKeyState('W')>>1 || GetKeyState(VK_UP)>>1) || a=='d' && *c>0 && (GetKeyState('S')>>1 || GetKeyState(VK_DOWN)>>1)))
	{
		sleep(5);
		(*c)+=add;
		if(temp!=(int)(*c+0.5))
		{
			printTurret(*c,pl);
			temp=*c+0.5;
		}
	}
	if(*c<0)
	*c=0;
	else if(*c>6)
	*c=6;
}
void victory(char pl)
{
	renewCursor(0,Y+9);
	printf("Player %d wins!\nPress any key to restart ",pl+1);
	getch();
}
int projection(char pl,float d,unsigned char table[X])
{
	int x,y,power,flag=1;
	double px,py,tx,ty,tempx,tempy;
	if(d<3.5)
	tx=4+pl*(X-6.5);
	else
	tx=(7.5-d)*(!pl)+(X+d-5.5)*pl;
	if(d>2.5)
	ty=Y-2.5;
	else
	ty=Y-d+0.5;
	power=analogue(pl*(X-10),Y+3);
	renewCursor(tx,ty);
	printf("%c",254);
	px=power/1000.0*cos(d*M_PI/12);
	if(pl)
	px=-px;
	py=-power/1000.0*sin(d*M_PI/12);
	while(flag)
	{
		py+=0.01;
		tempx=tx+px;
		tempy=ty+py;
		while(tempx<1 || tempx>=X+1 || tempy<1 || tempy>=Y+1 || table[(int)tempx-1]>Y-(int)tempy || (tempx<3 || tempx>=X-1) && tempy>=Y-1)
		{
			px/=2;
			py/=2;
			flag=0;
			tempx=tx+px;
			tempy=ty+py;
		}
		sleep(15);
		tx+=px;
		ty+=py;
		if((int)tx!=(int)(tx-px) || (int)ty!=(int)(ty-py))
		{
			if(px>0)
			tempx=tx+20;
			else if(px<0)
			tempx=tx-20;
			if(py>0)
			tempy=ty+20;
			else if(py<0)
			tempy=ty-20;
			if(tempx>X+1)
			tempx=X+1;
			else if(tempx<0)
			tempx=0;
			if(tempy>Y+1)
			tempy=Y+1;
			else if(tempy<0)
			tempy=0;
			printf("\b ");
			renewCursor(tempx,tempy);
			renewCursor(tx,ty);
			printf("%c",254);
			if((tx<4 || tx>=X-2) && ty>=Y-2)
			printf("\b*");
			if((tx<4 && pl || tx>=X-2 && !pl) && ty>=Y-2)
			{
				victory(pl);
				return 1;
			}
			else if((tx<4 || tx>=X-2) && ty>=Y-2)
			{
				getch();
				printTurret(d,pl);
				return 0;
			}
		}
	}
	getch();
	printf("\b ");
	return 0;
}
int play()
{
	char a;
	while(a=welcome())
	if(a==1)
	return 0;
	unsigned char table[X];
	float d[2]={3,3};
	int moves=0;
	randomize(table);
	print(table);
	printTurret(3,0);
	printTurret(3,1);
	while(1)
	{
		if(moves%2)
		renewCursor(X+1,Y+7);
		else
		renewCursor(0,Y+7);
		a=getch();
		if(a=='w' || a=='W' || a==72)
		move('u',moves%2,d);
		else if(a=='s' || a=='S' || a==80)
		move('d',moves%2,d);
		else if(a==' ' && projection(moves++%2,d[moves%2],table))
		return 1;
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
		}
	}
	return 1;
}
int main()
{
	srand(time(0));
	while(play());
	system("pause");
}
