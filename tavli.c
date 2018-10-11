#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void start(int*a,int*b)
{
	int i,j;
	printf("1. portes\n2. plakoto\n3. fevga");
	j=getche();
	switch(j)
	{
	case 49:
		for(i=0;i<2;i++)
		{
			a[i]=23;
			b[i]=0;
		}
		for(;i<7;i++)
		{
			a[i]=5;
			b[i]=18;
		}
		for(;i<10;i++)
		{
			a[i]=7;
			b[i]=16;
		}
		for(;i<15;i++)
		{
			a[i]=12;
			b[i]=11;
		}
		break;
	case 50:
		for(i=0;i<15;i++)
		{
			a[i]=0;
			b[i]=23;
		}
		break;
	case 51:
		for(i=0;i<15;i++)
		{
			a[i]=23;
			b[i]=11;
		}
		break;
	case 52:
		for(i=0;i<14;i++)
			a[i]=22;
		a[i]=4;
		for(i=0;i<2;i++)
			b[i]=16;
		for(i=2;i<4;i++)
			b[i]=18;
		for(i=4;i<6;i++)
			b[i]=16;
		for(i=6;i<8;i++)
			b[i]=20;
		for(i=8;i<10;i++)
			b[i]=21;
		for(i=10;i<12;i++)
			b[i]=18;
		for(i=12;i<15;i++)
			b[i]=15;
	}
}
void print(int*a,int*b,int zari1,int zari2)
{
	int i,j,k,r[24];
	for(i=0;i<24;i++)
	r[i]=0;
	system("cls");
	printf("| - - - - - - || - - - - - - |\n");
	for(i=0;i<15;i++)
	for(j=0;j<24;j++)
	if(a[i]==j || b[i]==j)
	r[j]++;
	for(i=0;i<8;i++)
	{
		printf("|");
		for(j=12;j<24;j++)
		{
			if(j==18)
			printf(" ||");
			if(r[j]>0)
			{
				for(k=0;k<15;k++)
				if(a[k]==j)
				{
					printf(" %c",1);
					r[j]--;
					break;
				}
				else if(b[k]==j)
				{
					printf(" %c",2);
					r[j]--;
					break;
				}
			}
			else
			printf("  ");
		}
		printf(" |\n");
	}
	printf("|\t      ||\t     |\n");
	for(i=7;i>=0;i--)
	{
		printf("|");
		for(j=11;j>=0;j--)
		{
			if(j==5)
			printf(" ||");
			if(r[j]>i)
			{
				for(k=0;k<15;k++)
				if(a[k]==j)
				{
					printf(" %c",1);
					r[j]--;
					break;
				}
				else if(b[k]==j)
				{
					printf(" %c",2);
					r[j]--;
					break;
				}
			}
			else
			printf("  ");
			}
			printf(" |\n");
	}
	printf("| - - - - - - || - - - - - - |\n\n");
	printf("%c%c%c%c%c %c%c%c%c%c\n",218,196,196,196,191,218,196,196,196,191);
	if(zari1==1)
		printf("%c   %c ",179,179);
	else if(zari1==2||zari1==3)
		printf("%c%c  %c ",179,254,179);
	else
		printf("%c%c %c%c ",179,254,254,179);
	if(zari2==1)
		printf("%c   %c\n",179,179);
	else if(zari2==2||zari2==3)
		printf("%c%c  %c\n",179,254,179);
	else
		printf("%c%c %c%c\n",179,254,254,179);
	if(zari1==6)
		printf("%c%c %c%c ",179,254,254,179);
	else if(zari1==2||zari1==4)
		printf("%c   %c ",179,179);
	else
		printf("%c %c %c ",179,254,179);
	if(zari2==6)
		printf("%c%c %c%c\n",179,254,254,179);
	else if(zari2==2||zari2==4)
		printf("%c   %c\n",179,179);
	else
		printf("%c %c %c\n",179,254,179);
	if(zari1==1)
		printf("%c   %c ",179,179);
	else if(zari1==2||zari1==3)
		printf("%c  %c%c ",179,254,179);
	else
		printf("%c%c %c%c ",179,254,254,179);
	if(zari2==1)
		printf("%c   %c\n",179,179);
	else if(zari2==2||zari2==3)
		printf("%c  %c%c\n",179,254,179);
	else
		printf("%c%c %c%c\n",179,254,254,179);
	printf("%c%c%c%c%c %c%c%c%c%c\n",192,196,196,196,217,192,196,196,196,217);
}
void doublecheck()
{
     int l,start,k,zari1,j,b[1];
	if(l<=1&&start<4)
	{
		l=0;
		start++;
		k-=zari1;
		for(j=0;j<15;j++)
			if(b[j]==k&&k!=-1)
				l++;
		if(l<=1&&start<4)
		{
			l=0;
			start++;
			k-=zari1;
			for(j=0;j<15;j++)
				if(b[j]==k&&k!=-1)
					l++;
			if(l<=1&&start<4)
			{
				l=0;
				start++;
				k-=zari1;
				for(j=0;j<15;j++)
					if(b[j]==k&&k!=-1)
						l++;
				if(l<=1&&start<4)
					start++;
			}
		}
	}
}
void move(int*a,int*b,int zari1,int zari2)
{
	int i,j=0,k,l,m,start=0,end=0,zari=0,piasmena=0,exo=0;
	for(i=0;i<15;i++)
	{
		if(a[i]==24)
			piasmena++;
		if(a[i]>5)
			exo++;
	}
	if(zari1!=zari2)
	{
		zari=2;
		if(piasmena>0)
		{
			k=0;
			l=0;
			for(i=0;i<15;i++)
			{
				if(b[i]==24-zari1)
					k++;
				if(b[i]==24-zari2)
					l++;
			}
			if(k>1&&l>1)
			{
				printf("Den mporeis na mpeis\n");
				zari=0;
			}
			else if(j>1&&k>1)
			{
				printf("Den mporeis na mpeis sto %d\n",zari1);
				zari=1;
			}
			else if(j>1&&l>1)
			{
				printf("Den mporeis na mpeis sto %d\n",zari2);
				zari=1;
			}
		}
		if(zari==2)
		{
			for(i=0;i<15;i++)
			{
				k=0;
				l=0;
				for(j=0;j<15;j++)
				{
					if(a[i]-zari1==b[j]&&a[i]-zari1!=-1)
						k++;
					else if(a[i]-zari1<0)
						for(m=0;m<15;m++)
							if(a[m]>5)
							{
								k+=2;
								break;
							}
					if(a[i]-zari2==b[j]&&a[i]-zari2!=-1)
						l++;
					else if(a[i]-zari2<0)
						for(m=0;m<15;m++)
							if(a[m]>5)
							{
								l+=2;
								break;
							}
				}
				if(k>1)
					start++;
				if(l>1)
					end++;
			}
			if(start==15&&end==15)
			{
				printf("Den eheis na paixeis\n");
				zari=0;
			}
			else if(start==15)
			{
				for(i=0;i<15;i++)
				{
					l=0;
					for(j=0;j<15;j++)
						if(a[i]-zari2==b[j]&&a[i]-zari2!=-1)
							l++;
						else if(a[i]-zari2<0)
							for(m=0;m<15;m++)
								if(a[m]>5)
								{
									l+=2;
									break;
								}
					if(l<=1)
					{
						l=0;
						for(j=0;j<15;j++)
							if(a[i]-zari1-zari2==b[j]&&a[i]-zari1-zari2!=-1)
								l++;
							else if(a[i]-zari1-zari2<0)
								for(m=0;m<15;m++)
									if(a[m]>5&&m!=i)
									{
										l+=2;
										break;
									}
						if(l<=1)
							break;
					}
				}
				printf("Den eheis na paixeis %d\n",zari1);
				zari=1;
			}
			else if(end==15)
			{
				for(i=0;i<15;i++)
				{
					l=0;
					for(j=0;j<15;j++)
						if(a[i]-zari1==b[j]&&a[i]-zari1!=-1)
							l++;
						else if(a[i]-zari1<0)
							for(m=0;m<15;m++)
								if(a[m]>5)
								{
									l+=2;
									break;
								}
					if(l<=1)
					{
						l=0;
						for(j=0;j<15;j++)
							if(a[i]-zari1-zari2==b[j]&&a[i]-zari1-zari2!=-1)
								l++;
							else if(a[i]-zari1-zari2<0)
								for(m=0;m<15;m++)
									if(a[m]>5&&m!=i)
									{
										l+=2;
										break;
									}
						if(l<=1)
							break;
					}
				}
				printf("Den eheis na paixeis %d\n",zari2);
				zari=1;
			}
		}
	}	
	if(zari1==zari2)
	{
		zari=4;
		if(piasmena>0)
		{
			k=0;
			for(i=0;i<15;i++)
				if(b[i]==24-zari1)
					k++;
			if(k>1)
			{
				printf("Den mporeis na mpeis\n");
				zari=0;
			}
		}
		if(zari==4)
		{
			for(i=0;i<15;i++)
			{
				k=a[i]-zari1;
				l=0;
				for(j=0;j<15;j++)
					if(b[j]==k&&k!=-1)
						l++;
				doublecheck();
			}
			if(start==0)
			{
				printf("Den eheis na paixeis\n");
				zari=0;
			}
			else if(start<4)
			{
				printf("Eheis mono %d kiniseis\n",start);
				zari=start;
			}
		}
	}
	k=zari;
	zari=0;
	for(i=0;i<k;i++)
	{
start:
		scanf("%d%d",&start,&end);
		for(j=0;j<15;j++)
			if(a[j]==24&&start!=24)
			{
				printf("eheis piasmeno pouli\n");
				goto start;
			}
		if(zari1!=zari2&&start-end!=zari1&&start-end!=zari2&&start-end!=zari1+zari2||zari1==zari2&&start-end!=zari1&&start-end!=zari1*2&&start-end!=zari1*3&&start-end!=zari1*4)
		{
			printf("lathos metrima\n");
			goto start;
		}
		l=0;
		for(j=0;j<15;j++)
		{
			if(b[j]==end)
				l++;
			if(l==2)
			{
				printf("I thesi ehei porta tou antipalou\n");
				goto start;
			}
		}
		if(l==1)
			for(j=0;j<15;j++)
				if(b[j]==end)
				{
					b[j]=-1;
					break;
				}
		if(end<0)
		{
			for(j=0;j<15;j++)
				if(a[j]>5)
					break;
			if(j!=15)
			{
				printf("Iparhoun akoma poulia exo\n");
				goto start;
			}
		}
		if(start-end==zari)
		{
			printf("epaixes idi to %d\n",zari);
			goto start;
		}
		for(j=0;j<15;j++)
			if(a[j]==start)
			{
				a[j]=end;
				break;
			}
		if(j==15)
		{
			printf("den eheis pouli sti thesi %d\n",start);
			goto start;
		}
		if(start-end==zari1+zari2)
			i++;
		else if(start-end==zari1*3&&zari1==zari2)
			i+=2;
		else if(start-end==zari1*4&&zari1==zari2)
			i+=3;
		if(zari1!=zari2)
			if(start-end==zari1)
				zari=zari1;
			else
				zari=zari2;
		print(a,b,zari1,zari2);
	}
end:
	getch();
}
main()
{
	int a[15],b[15],zari1,zari2;
	srand(time(0));
	start(a,b);
	while(1)
	{
		zari1=rand()%6+1;
		zari2=rand()%6+1;
		print(a,b,zari1,zari2);
		move(a,b,zari1,zari2);
	}
}
