#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
void printsudoku(int sudoku[9][9])
{
	int i,j;
	system("cls");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n%c\t%c\t%c\t%c\n",218,196,196,196,196,196,196,196,194,196,196,196,196,196,196,196,194,196,196,196,196,196,196,196,191,179,179,179,179);
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(j==0||j==3||j==6)
				printf("%c ",179);
			if(sudoku[i][j]!=0)
				printf("%d ",sudoku[i][j]);
			else
				printf("  ");
		}
		if(i!=8)
			printf("%c %d\n%c\t%c\t%c\t%c\n",179,i+1,179,179,179,179);
		if(i==2||i==5)
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n%c\t%c\t%c\t%c\n",195,196,196,196,196,196,196,196,197,196,196,196,196,196,196,196,197,196,196,196,196,196,196,196,180,179,179,179,179);
	}
	printf("%c 9\n%c\t%c\t%c\t%c\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n  A B C   D E F   G H I\n\n",179,179,179,179,179,192,196,196,196,196,196,196,196,193,196,196,196,196,196,196,196,193,196,196,196,196,196,196,196,217);
}
int checkline(int temp[9][9],int a,int b,int c)
{
	int i;
	for(i=0;i<9;i++)
		if(temp[i][c]==a)
			return 0;
	for(i=0;i<9;i++)
		if(temp[b][i]==a)
			return 0;
	return 1;
}
int checksquare(int temp[9][9],int a,int b,int c)
{
	int i,j;
	for(i=(b/3)*3;i<(b/3)*3+3;i++)
		for(j=(c/3)*3;j<(c/3)*3+3;j++)
			if(temp[i][j]==a)
				return 0;
	return 1;
}
int fillrandom(int sudoku[9][9])
{
	int a,b,i,j;
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			sudoku[i][j]=0;
		for(i=0;i<9;i++)
			for(j=0;j<9;j++)
			{
				a=rand()%9+1;
				if(checkline(sudoku,a,i,j)&&checksquare(sudoku,a,i,j))
				{
					sudoku[i][j]=a;
					b=0;
				}
				else
				{
					j--;
					b++;
					if(b>100)
						return 1;
				}
			}
	return 0;
}
int checksolutions(int temp[9][9],int sudoku[9][9],int i,int j,int e,int f)
{
	int a=0,b,c,d=0;
	for(c=1;c<10;c++)
	{
		if(a==-1)
		{
			a=i;
			b=j;
			while(a<9)
			{
				while(b<9)
				{
					b++;
					temp[a][b]=sudoku[a][b];
				}
				if(b==9)
				{
					b=0;
					a++;
				}
			}
			temp[e][f]=0;
		}
		if(checkline(temp,c,i,j)&&checksquare(temp,c,i,j))
		{
			temp[i][j]=c;
			a=i;
			b=j;
			while(a<9)
			{
				while(b<9)
				{
					b++;
					if(temp[a][b]==0)
						break;
				}
				if(b==9)
				{
					b=0;
					a++;
				}
				if(temp[a][b]==0)
					break;
			}
			if(a!=9)
				d+=checksolutions(temp,sudoku,a,b,e,f);
			else
				d++;
			if(d>1)
				break;
			if(c<10)
				a=-1;
		}
	}
	return d;
}
void tempcreator(int sudoku[9][9])
{
	int a,b,i=0,k,j=0,temp[9][9];
	for(k=0;k<100;k++)
	{
		for(i=0;i<9;i++)
			for(j=0;j<9;j++)
				temp[i][j]=sudoku[i][j];
		do
		{
			a=rand()%9;
			b=rand()%9;
		}while(temp[a][b]==0);
		temp[a][b]=0;
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
				if(temp[i][j]==0)
						break;
			if(temp[i][j]==0)
				break;
		}
		if(j==9)
		{
			j=0;
			i++;
		}
		if(checksolutions(temp,sudoku,i,j,a,b)==1)
			sudoku[a][b]=0;
	}
}
void play(int sudoku[9][9])
{
	char a;
	int b,c,i,j,temp[9][9];
start:
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			temp[i][j]=sudoku[i][j];
	printsudoku(temp);
	while(1)
	{
		do
		{
			scanf("%c",&a);
			if(a=='r'||a=='R')
			{
				printf("Are you sure you want to restart?");
				a=getche();
				if(a=='y'||a=='Y')
					goto start;
			}
			else if(a=='n'||a=='N')
			{
				printf("Are you sure you want to start a new game?");
				a=getche();
				if(a=='y'||a=='Y')
					goto end;
			}
			scanf("%d%d",&b,&c);
			if(a>90)
				a-=32;
			a-=65;
			b-=1;
		}while(a<0||a>8||b<0||b>8||c<0||c>9||sudoku[b][a]!=0);
		temp[b][a]=c;
		printsudoku(temp);
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				if(temp[i][j]==0)
					break;
				if(checkline(temp,temp[i][j],i,j)||checkline(temp,temp[i][j],i,j))
					break;
			}
			if(temp[i][j]==0)
				break;
			if(checkline(temp,temp[i][j],i,j)||checkline(temp,temp[i][j],i,j))
				break;
		}
		if(i==9&&j==9)
		{
			printf("%c%c%c%c%c%c%c%c%c%c%c%c!\n%c%c%c%c%c%c%c%c %c%c%c %c%c%c %c%c%c%c%c%c %c%c%c%c%c%c%c%c%c %c%c%c sudoku!\n%c%c%c %c%c%c%c%c%c%c%c%c%c %c%c' %c%c%c%c;",145,172,164,174,152,168,158,171,227,168,160,152,137,226,168,155,160,169,156,170,169,171,166,167,160,166,158,162,229,159,160,166,167,168,230,154,168,152,163,163,152,154,160,152,143,233,170,152,160,169,159,225,164,156,169,152,160,154,160,152,172,171,230);
			getch();
			break;
		}
	}
end:;
}
main()
{
	int sudoku[9][9];
	srand(time(0));
	while(1)
	{
		while(fillrandom(sudoku));
		tempcreator(sudoku);
		play(sudoku);
	}
}