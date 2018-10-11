#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int A=1;
typedef struct pieces
{
	char h,v,p;
}Pieces;
typedef struct taken
{
	Pieces*ptr;
	char h,v,p;
}Taken;
void piecesCoords(Pieces*a,int h,int v,int p)
{
	a->h=h;
	a->v=v;
	a->p=p;
}
void piecesSetup(Pieces*black,Pieces*white)
{
	int i;
	for(i=0;i<8;i++)
	{
		piecesCoords(black+i,i,A*5+1,'P');
		piecesCoords(white+i,i,!A*5+1,'P');
	}
	piecesCoords(black+8,0,A*7,'R');
	piecesCoords(black+9,7,A*7,'R');
	piecesCoords(black+10,1,A*7,'N');
	piecesCoords(black+11,6,A*7,'N');
	piecesCoords(black+12,2,A*7,'B');
	piecesCoords(black+13,5,A*7,'B');
	piecesCoords(black+14,4-A,A*7,'Q');
	piecesCoords(black+15,3+A,A*7,'K');
	piecesCoords(white+8,0,!A*7,'R');
	piecesCoords(white+9,7,!A*7,'R');
	piecesCoords(white+10,1,!A*7,'N');
	piecesCoords(white+11,6,!A*7,'N');
	piecesCoords(white+12,2,!A*7,'B');
	piecesCoords(white+13,5,!A*7,'B');
	piecesCoords(white+14,4-A,!A*7,'Q');
	piecesCoords(white+15,3+A,!A*7,'K');
}
char piecesFinder(Pieces*a,int h,int v)
{
	int i;
	for(i=0;i<16;i++)
		if(a[i].h==h&&a[i].v==v)
			return a[i].p;
	return 0;
}
void piecesPrint(Pieces*white,Pieces*black,int h,int v)
{
	if(piecesFinder(white,h,v))
		printf("%cw",piecesFinder(white,h,v));
	else if(piecesFinder(black,h,v))
		printf("%cb",piecesFinder(black,h,v));
	else if((v+h)%2)
		printf("%c%c",177,177);
	else
		printf("  ");
}
void boardPrint(Pieces*b,Pieces*w)
{
	int i,j;
	system("cls");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,209,205,205,205,205,209,205,205,205,205,209,205,205,205,205,209,205,205,205,205,209,205,205,205,205,209,205,205,205,205,209,205,205,205,205,187);
	for(i=0;i<8;i++)
	{
		if(i%2==0)
		{
			printf("%c    %c%c%c%c%c%c    %c%c%c%c%c%c    %c%c%c%c%c%c    %c%c%c%c%c%c\n",186,179,177,177,177,177,179,179,177,177,177,177,179,179,177,177,177,177,179,179,177,177,177,177,186);
			for(j=0;j<4;j++)
			{
				if(j==0)
					printf("%c%c",186,32);
				piecesPrint(w,b,j*2,i);
				printf(" %c%c",179,177);
				piecesPrint(w,b,j*2+1,i);
				if(j<3)
					printf("%c%c%c",177,179,32);
			}
			printf("%c%c %d\n",177,186,i+1);
			printf("%c    %c%c%c%c%c%c    %c%c%c%c%c%c    %c%c%c%c%c%c    %c%c%c%c%c%c\n",186,179,177,177,177,177,179,179,177,177,177,177,179,179,177,177,177,177,179,179,177,177,177,177,186);
		}
		else
		{
			printf("%c%c%c%c%c%c    %c%c%c%c%c%c    %c%c%c%c%c%c    %c%c%c%c%c%c    %c\n",186,177,177,177,177,179,179,177,177,177,177,179,179,177,177,177,177,179,179,177,177,177,177,179,186);
			for(j=0;j<4;j++)
			{
				if(j==0)
					printf("%c%c",186,177);
				piecesPrint(w,b,j*2,i);
				printf("%c%c%c",177,179,32);
				piecesPrint(w,b,j*2+1,i);
				if(j<3)
					printf(" %c%c",179,177);
			}
			printf(" %c %d\n",186,i+1);
			printf("%c%c%c%c%c%c    %c%c%c%c%c%c    %c%c%c%c%c%c    %c%c%c%c%c%c    %c\n",186,177,177,177,177,179,179,177,177,177,177,179,179,177,177,177,177,179,179,177,177,177,177,179,186);
		}
		if(i<7)
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",199,196,196,196,196,197,196,196,196,196,197,196,196,196,196,197,196,196,196,196,197,196,196,196,196,197,196,196,196,196,197,196,196,196,196,197,196,196,196,196,182);
	}
	
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,207,205,205,205,205,207,205,205,205,205,207,205,205,205,205,207,205,205,205,205,207,205,205,205,205,207,205,205,205,205,207,205,205,205,205,188);
	printf("  A    B    C    D    E    F    G    H\n");
}
int fixValues2(char*a)
{
	if(*a>47&&*a<58)
		*a-=49;
	else if(*a>64&&*a<91)
		*a-=65;
	else if(*a>96&&*a<123)
		*a-=97;
	else
		return 0;
	return 1;
}
int fixValues(char*h,char*v)
{
	char temp;
	if(*h<58&&*v>64)
	{
		temp=*h;
		*h=*v;
		*v=temp;
	}
	else if(!(*v<58&&*h>64))
		return 1;
	if(fixValues2(h)&&fixValues2(v))
		return 0;
	return 1;

}
int initValues(char*v1,char*v2,char*h1,char*h2)
{
	char a[6];
	do{
		gets(a);
		if(!strcmp(a,"move"))
			return 1;
		*h1=a[0];
		*v1=a[1];
		*h2=a[2];
		*v2=a[3];
		if(a[2]<49)
		{
			*h2=a[3];
			*v2=a[4];
		}
	}while(fixValues(h1,v1)||fixValues(h2,v2));
	return 0;
}
int checkPath(Pieces*a,Pieces*b,int h1,int v1,int h2,int v2)
{
	int i;
	if(h1>h2)
	{
		if(v1>v2)
		{
			if((v1-v2)==(h1-h2))
			{
				for(i=0;i<(h1-h2);i++)
					if(piecesFinder(a,h1-i-1,v1-i-1)||piecesFinder(b,h1-i,v1-i))
						return 0;
				return 1;
			}
		}
		else if(v1==v2)
		{
			for(i=h2;i<h1;i++)
				if(piecesFinder(a,i,v1)||piecesFinder(b,i+1,v1))
					return 0;
			return 1;
		}
		else
		{
			if((v1-v2)==-(h1-h2))
			{
				for(i=0;i<(h1-h2);i++)
					if(piecesFinder(a,h1-i-1,v1+i+1)||piecesFinder(b,h1-i,v1+i))
						return 0;
				return 1;
			}
		}
	}
	else if(h1==h2)
	{
		if(v1>v2)
		{
			for(i=v2;i<v1;i++)
				if(piecesFinder(a,h1,i)||piecesFinder(b,h1,i+1))
					return 0;
			return 1;
		}
		else if(v1==v2)
		{
			return 0;
		}
		else
		{
			for(i=v1;i<v2;i++)
				if(piecesFinder(a,h1,i+1)||piecesFinder(b,h1,i))
					return 0;
			return 1;
		}
	}
	else
	{
		if(v1>v2)
		{
			if((v1-v2)==-(h1-h2))
			{
				for(i=0;i<(h2-h1);i++)
					if(piecesFinder(a,h1+i+1,v1-i-1)||piecesFinder(b,h1+i,v1-i))
						return 0;
				return 1;
			}
		}
		else if(v1==v2)
		{
			for(i=h1;i<h2;i++)
				if(piecesFinder(a,i+1,v1)||piecesFinder(b,i,v1))
					return 0;
			return 1;
		}
		else
		{
			if((v1-v2)==(h1-h2))
			{
				for(i=0;i<(h2-h1);i++)
					if(piecesFinder(a,h1+i+1,v1+i+1)||piecesFinder(b,h1+i,v1+i))
						return 0;
				return 1;
			}
		}
	}
	return 0;
}
void takenRecord(Pieces*ptr,char*moves)
{
	static int i=0;
	static Taken*pin=NULL;
	pin=(Taken*)realloc(pin,(i+1)*sizeof(Taken));
	if(ptr!=NULL)
	{
		pin[i].ptr=ptr;
		pin[i].h=ptr->h;
		pin[i].v=ptr->v;
		pin[i].p=ptr->p;
		i++;
	}
	else if(i>0)
	{
		i--;
		pin[i].ptr->h=pin[i].h;
		pin[i].ptr->v=pin[i].v;
		pin[i].ptr->p=pin[i].p;
	}
	pin=(Taken*)realloc(pin,i*sizeof(Taken));
}
int piecesMove(Pieces*a,Pieces*b,int h1,int v1,int h2,int v2,int c,char*moves,int user)
{
	int i;
	for(i=0;i<16;i++)
	{
		if(a[i].h==h1&&a[i].v==v1)
			piecesCoords(a+i,h2,v2,(a+i)->p);
		if(b[i].h==h2&&b[i].v==v2)
		{
			takenRecord(b+i,NULL);
			piecesCoords(b+i,9,9,0);
			moves[c*8+4]='x';
		}
		if(user&&a[i].h==h2&&a[i].v==v2&&a[i].p=='P'&&(v2==0||v2==7))
			while(a[i].p!='R'&&a[i].p!='N'&&a[i].p!='B'&&a[i].p!='Q')
				a[i].p=getche();
	}
	return 1;
}
int checkLine(Pieces*a,Pieces*b,int h,int v,char p,char m)
{
	while(h>=0&&h<=7&&v>=0&&v<=7)
	{
		if(m&1)
			h++;
		else if(m&2)
			h--;
		if(m&4)
			v++;
		else if(m&8)
			v--;
		if(piecesFinder(b,h,v)==p||piecesFinder(b,h,v)=='Q')
			return 1;
		else if(piecesFinder(a,h,v)||piecesFinder(b,h,v))
			return 0;
	}
	return 0;
}
int checkKing(Pieces*a,Pieces*b,int c,int h,int v)
{
	int temp=0;
	if(piecesFinder(b,h-2,v-1)=='N'||piecesFinder(b,h-2,v+1)=='N'||piecesFinder(b,h-1,v-2)=='N'||piecesFinder(b,h-1,v+2)=='N'||piecesFinder(b,h+1,v-2)=='N'||piecesFinder(b,h+1,v-+2)=='N'||piecesFinder(b,h+2,v-1)=='N'||piecesFinder(b,h+2,v+1)=='N')
		temp++;
	if(c%2&&(piecesFinder(b,h+1,v+1)=='P'||piecesFinder(b,h-1,v+1))=='P'||!(c%2)&&(piecesFinder(b,h+1,v-1)=='P'||piecesFinder(b,h-1,v-1)=='P'))
		temp++;
	temp+=checkLine(a,b,h,v,'R',1);
	temp+=checkLine(a,b,h,v,'R',2);
	temp+=checkLine(a,b,h,v,'R',4);
	temp+=checkLine(a,b,h,v,'R',8);
	temp+=checkLine(a,b,h,v,'B',5);
	temp+=checkLine(a,b,h,v,'B',6);
	temp+=checkLine(a,b,h,v,'B',9);
	temp+=checkLine(a,b,h,v,'B',10);
	return temp;
}
int piecesMoveCheck(Pieces*a,Pieces*b,char*moves,int c,int h1,int v1,int h2,int v2,int user)
{
	int i;
	char piece=piecesFinder(a,h1,v1);
	if(piece==0)
	{
		printf("No piece there");
		getch();
		return 0;
	}
	else if(piece=='P')
	{
		if((((c+A)%2&&v2-v1==1||!((c+A)%2)&&v1-v2==1)&&(h2-h1==0&&!piecesFinder(b,h2,v2)||((h2-h1==1||h1-h2==1)&&piecesFinder(b,h2,v2))))||(((c+A)%2&&v2-v1==2||!((c+A)%2)&&v1-v2==2)&&((c+A)%2&&v1==1||!((c+A)%2)&&v1==6)&&(h2-h1==0)&&!piecesFinder(b,h2,v2)&&!piecesFinder(b,h2,(v2+v1)/2)))
			return piecesMove(a,b,h1,v1,h2,v2,c,moves,user);
		else if(((c+A)%2&&v2-v1==1||!((c+A)%2)&&v1-v2==1)&&(h2-h1==1||h1-h2==1)&&piecesFinder(b,h2,v1)=='P'&&(v2==2||v2==5)&&moves[(c-1)*8+5]-65==h2&&moves[(c-1)*8+6]-49==v1&&(moves[(c-1)*8+6]-moves[(c-1)*8+3]==2||moves[(c-1)*8+3]-moves[(c-1)*8+6]==2))
		{
			for(i=0;i<16;i++)
			{
				if(a[i].h==h1&&a[i].v==v1)
					piecesCoords(a+i,h2,v2,(a+i)->p);
				if(b[i].h==h2&&b[i].v==v1)
				{
					takenRecord(b+i,NULL);
					piecesCoords(b+i,9,9,0);
					moves[c*8+4]='x';
				}
			}
			return 1;
		}
	}
	else if(piece=='R')
	{
		if(checkPath(a,b,h1,v1,h2,v2)&&(!(h2-h1)&&(v2-v1)||(h2-h1)&&!(v2-v1)))
			return piecesMove(a,b,h1,v1,h2,v2,c,moves,user);
	}
	else if(piece=='N')
	{
		if(!piecesFinder(a,h2,v2)&&((h1-h2==2||h1-h2==-2)&&(v1-v2==1||v1-v2==-1)||(h1-h2==1||h1-h2==-1)&&(v1-v2==2||v1-v2==-2)))
			return piecesMove(a,b,h1,v1,h2,v2,c,moves,user);
	}
	else if(piece=='B')
	{
		if(checkPath(a,b,h1,v1,h2,v2)&&((h2-h1)&&(v2-v1)))
			return piecesMove(a,b,h1,v1,h2,v2,c,moves,user);
	}
	else if(piece=='Q')
	{
		if(checkPath(a,b,h1,v1,h2,v2)&&((h2-h1)&&(v2-v1)||!(h2-h1)&&(v2-v1)||(h2-h1)&&!(v2-v1)))
			return piecesMove(a,b,h1,v1,h2,v2,c,moves,user);
	}
	else if(piece=='K')
	{
		if(!piecesFinder(a,h2,v2)&&(v2-v1==0||v2-v1==1||v2-v1==-1)&&(h2-h1==0||h2-h1==1||h2-h1==-1))
			return piecesMove(a,b,h1,v1,h2,v2,c,moves,user);
		else if((v1==v2)&&(h1-h2==2)&&!piecesFinder(a,h1-1,v1)&&!piecesFinder(a,h1-2,v1)&&!piecesFinder(b,h1-1,v1)&&!piecesFinder(b,h1-2,v1)&&!checkKing(a,b,c,h1,v1)&&!checkKing(a,b,c,h1-1,v1)&&!checkKing(a,b,c,h1-2,v1)&&!checkKing(a,b,c,h1-3,v1)&&(!A||A&&!piecesFinder(a,h1-3,v1)&&!piecesFinder(b,h1-3,v1)&&!checkKing(a,b,c,h1-4,v1)))
		{
			for(i=0;i<c;i++)
				if(moves[i*8+2]=='A'&&moves[i*8+3]==(v1+49)||moves[i*8+5]=='A'&&moves[i*8+6]==(v1+49)||moves[i*8+2]==('D'+A)&&moves[i*8+3]==(v1+49)||moves[i*8+5]==('D'+A)&&moves[i*8+6]==(v1+49))
					return 0;
			moves[c*8+4]='0';
			piecesMove(a,b,0,v1,2+A,v2,c,moves,user);
			return piecesMove(a,b,h1,v1,h2,v2,c,moves,user);
		}
		else if((v1==v2)&&(h2-h1==2)&&!piecesFinder(a,h1+1,v1)&&!piecesFinder(a,h1+2,v1)&&!piecesFinder(b,h1+1,v1)&&!piecesFinder(b,h1+2,v1)&&!checkKing(a,b,c,h1,v1)&&!checkKing(a,b,c,h1+1,v1)&&!checkKing(a,b,c,h1+2,v1)&&!checkKing(a,b,c,h1+3,v1)&&(A||!A&&!piecesFinder(a,h1+3,v1)&&!piecesFinder(b,h1+3,v1)&&!checkKing(a,b,c,h1+4,v1)))
		{
			for(i=0;i<c;i++)
				if(moves[i*8+2]=='H'&&moves[i*8+3]==(v1+49)||moves[i*8+5]=='H'&&moves[i*8+6]==(v1+49)||moves[i*8+2]==('D'+A)&&moves[i*8+3]==(v1+49)||moves[i*8+5]==('D'+A)&&moves[i*8+6]==(v1+49))
					return 0;
			moves[c*8+4]='0';
			piecesMove(a,b,7,v1,4+A,v2,c,moves,user);
			return piecesMove(a,b,h1,v1,h2,v2,c,moves,user);
		}
	}
	return 0;
}
void movesRecord(char*moves,Pieces*a,Pieces*b,int c,int h1,int v1,int h2,int v2)
{
	if(c%2)
	{
		moves[c*8-1]=9;
		moves[c*8]=piecesFinder(b,h1,v1);
	}
	else
	{
		if(c)
			moves[c*8-1]=10;
		moves[c*8]=piecesFinder(a,h1,v1);
	}
	moves[c*8+1]=32;
	moves[c*8+2]=h1+65;
	moves[c*8+3]=v1+49;
	moves[c*8+4]='-';
	moves[c*8+5]=h2+65;
	moves[c*8+6]=v2+49;
	moves[c*8+7]=0;
}
int moveBack(Pieces*a,Pieces*b,int c,char*moves)
{
	int i;
	if(c%2)
		a=b;
	if(moves[c*8+4]=='x')
		takenRecord(NULL,moves);
	else if(moves[c*8+4]=='0')
	{
		if(moves[c*8+5]-65==1+A)
			a[8].h=0;
		else if(moves[c*8+5]-65==5+A)
			a[9].h=7;
	}
	for(i=0;i<16;i++)
		if(a[i].h==moves[c*8+5]-65&&a[i].v==moves[c*8+6]-49)
		{
			a[i].h=moves[c*8+2]-65;
			a[i].v=moves[c*8+3]-49;
		}
	return 0;
}
int checkMate2(Pieces*a,Pieces*b,Pieces*white,Pieces*black,int c,char*moves,int h1,int v1,int h2,int v2)
{
	int temp;
	movesRecord(moves,white,black,c,h1,v1,h2,v2);
	if(piecesMoveCheck(a,b,moves,c,h1,v1,h2,v2,0))
	{
		temp=checkKing(a,b,c,a[15].h,a[15].v);
		moveBack(white,black,c,moves);
	}
	if(!temp)
		return 1;
	return 0;
}
int checkMate(Pieces*a,Pieces*b,int c,char*moves)
{
	int i,j,k;
	Pieces*white=a,*black=b;
	if(c%2)
	{
		black=a;
		white=b;
	}
	for(i=0;i<16;i++)
	{
		if(a[i].p=='P')
		{
			if((c+A)%2)
				k=1;
			else
				k=-1;
			for(j=-1;j<2;j++)
				if(a[i].h+j>=0&&a[i].h+j<8&&checkMate2(a,b,white,black,c,moves,a[i].h,a[i].v,a[i].h+j,a[i].v+k))
					return 1;
				if(checkMate2(a,b,white,black,c,moves,a[i].h,a[i].v,a[i].h,a[i].v+2*k))
					return 1;
		}
		if(a[i].p=='R'||a[i].p=='Q')
		{
			for(j=0;j<=7;j++)
				if(j!=a[i].v&&checkMate2(a,b,white,black,c,moves,a[i].h,a[i].v,a[i].h,j)||j!=a[i].h&&checkMate2(a,b,white,black,c,moves,a[i].h,a[i].v,j,a[i].v))
					return 1;
		}
		if(a[i].p=='N')
		{
			for(j=-2;j<3;j++)
				for(k=-2;k<3;k++)
					if(j==0||k==0||!((j+k)%2))
						continue;
					else if(a[i].h+j>=0&&a[i].h+j<8&&a[i].v+k>=0&&a[i].v+k<8&&checkMate2(a,b,white,black,c,moves,a[i].h,a[i].v,a[i].h+j,a[i].v+k))
						return 1;
		}
		if(a[i].p=='B'||a[i].p=='Q')
		{
			for(j=-7;j<8;j++)
				for(k=-7;k<8;k++)
					if(!j||j+k&&j-k)
						continue;
					else if(a[i].h+j>=0&&a[i].h+j<8&&a[i].v+k>=0&&a[i].v+k<8&&checkMate2(a,b,white,black,c,moves,a[i].h,a[i].v,a[i].h+j,a[i].v+k))
						return 1;
		}
		if(a[i].p=='K')
		{
			for(j=-1;j<2;j++)
				for(k=-1;k<2;k++)
					if((j||k)&&a[i].h+j>=0&&a[i].h+j<8&&a[i].v+k>=0&&a[i].v+k<8&&checkMate2(a,b,white,black,c,moves,a[i].h,a[i].v,a[i].h+j,a[i].v+k))
						return 1;
		}
	}
	if(!checkKing(a,b,c,a[15].h,a[15].v))
		printf("Draw!");
	else if(c%2)
		printf("White wins!");
	else
		printf("Black wins!");
	getch();
	return 0;
}
int main()
{
	int a=0,i=0,check;
	char v1=0,v2=0,h1=0,h2=0,*moves=malloc(8);
	Pieces black[16],white[16];
	scanf("%d",&A);
	piecesSetup(black,white);
	boardPrint(black,white);
	while(!(i%2)&&checkMate(white,black,i,moves)||i%2&&checkMate(black,white,i,moves))
	{
		moves=(char*)realloc(moves,8*(i+2));
		if(i%2)
			printf("\nblack moves: ");
		else
			printf("\nwhite moves: ");
		if(initValues(&v1,&v2,&h1,&h2))
		{
			if(i)
			{
				i--;
				moveBack(white,black,i,moves);
				moves[i*8-1]=0;
			}
			boardPrint(black,white);
			printf("\nwhite\tblack\n%s\n",moves);
			continue;
		}
		movesRecord(moves,white,black,i,h1,v1,h2,v2);
		check=i%2&&piecesMoveCheck(black,white,moves,i,h1,v1,h2,v2,1)||!(i%2)&&piecesMoveCheck(white,black,moves,i,h1,v1,h2,v2,1);
		if(check==1&&(!(i%2)&&checkKing(white,black,i,white[15].h,white[15].v)||i%2&&checkKing(black,white,i,black[15].h,black[15].v)))
		{
			check=moveBack(white,black,i,moves);
			a=1;
		}
		boardPrint(black,white);
		if(a==1)
		{
			printf("\nYou are checked!\n");
			a=0;
		}
		if(!(i%2)&&checkKing(black,white,i,black[15].h,black[15].v)||i%2&&checkKing(white,black,i,white[15].h,white[15].v))
			printf("\ncheck!\n");
		
		printf("\nwhite\tblack\n%s\n",moves);
		if(check==1)
			i++;
	}
}