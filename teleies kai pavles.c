#include<stdio.h>
main()
{
	int i,j,k,l,player1,player2;
	char a[676],b[2],c[540],name1[20],name2[20];
	k=0;
	l=0;
	player1=0;
	player2=0;
	printf("1%c%c %c%c%c%c%c%c%c:",166,170,167,152,229,174,171,158,170);
	gets(name1);
	printf("2%c%c %c%c%c%c%c%c%c:",166,170,167,152,229,174,171,158,170);
	gets(name2);
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			a[i*62+j*3+k]=250;
			if(j!=9)
			{
				a[i*62+j*3+k+1]=32;
				a[i*62+j*3+k+2]=32;
			}
			else
			{
				a[i*62+j*3+k+1]=32;
				a[i*62+j*3+k+2]=32;
				a[i*62+j*3+k+3]=i+97;
				if(i!=9)
				{
					a[i*62+j*3+k+32]=32;
					a[i*62+j*3+k+33]=32;
					a[i*62+j*3+k+34]=32;
					a[i*62+j*3+k+35]=32;
					a[i*62+j*3+k+36]=i+49;
				}
				else
				{
					a[i*62+j*3+k+4]=10;
					a[i*62+j*3+k+5]=10;
				}
			}
			if(i!=9)
			{
				a[i*62+j*3+k+29]=32;
				a[i*62+j*3+k+30]=32;
				a[i*62+j*3+k+31]=32;
			}
			else
			{
				a[i*62+j*3+k+33]=j+97;
				a[i*62+j*3+k+34]=32;
				a[i*62+j*3+k+35]=32;
				if(j!=9)
				{
					a[i*62+j*3+k+62]=32;
					a[i*62+j*3+k+63]=32;
					a[i*62+j*3+k+64]=j+49;
				}
				else
				{
					a[i*62+j*3+k+34]=10;
					a[i*62+j*3+k+62]=0;
				}

			}
		}
		if(i!=9)
		{
			k+=3;
			a[(i*2+1)*31+k-3]=10;
			a[(i*2+2)*31+k-1]=10;
		}
	}
	system("cls");
	puts(a);
	printf("%c%c%c%c%c%c %c %s.",143,152,229,157,156,160,166,name1);
	printf("\n%s\t%s\n%d\t%d\n",name1,name2,player1,player2);
	i=0;
	j=0;
	c[540]=1;
	while(c[540]!=0)
	{
		gets(b);
		if(b[0]>48&&b[0]<58&&b[1]>96&&b[1]<107||b[1]>48&&b[1]<58&&b[0]>96&&b[0]<107)
		{
			if(b[0]<58)
			{
				k=(b[0]-49)*3+(b[1]-97)*65+1;
				if(a[k]==32)
				{
					a[k]=196;
					a[k+1]=196;
					c[i]=b[0];
					c[i+1]=b[1];
					c[i+2]=10;
					c[i+3]=0;
					i+=3;
					j++;
				}
				else
					k=101;
			}
			else
			{
				k=(b[0]-97)*3+(b[1]-49)*65+32;
				if(a[k]==32)
				{
					a[k]=179;
					c[i]=b[0];
					c[i+1]=b[1];
					c[i+2]=10;
					c[i+3]=0;
					i+=3;
					j++;
				}
				else
					k=101;
			}
		}
		else
			k=102;
		system("cls");
		puts(a);
		if(k==101)
			printf("%c %c%c%c%c %c%c %c%c%c%c%c %c%c%c%c%c%c%c%c.",134,159,226,169,158,b[0],b[1],156,229,164,152,160,167,160,152,169,163,226,164,158);
		else if(k==102)
			printf("%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c.",138,225,159,166,170,169,172,164,171,156,171,152,154,163,226,164,156,170);
		if(a[k+3]==179-256&&a[k-31]==196-256&&a[k+34]==196-256)
		{
			if(j%2==1)
				player1++;
			else
				player2++;
			l=1;
		}
		if(a[k-3]==179-256&&a[k-34]==196-256&&a[k+31]==196-256)
		{
			if(j%2==1)
				player1++;
			else
				player2++;
			l=1;
		}
		if(a[k+65]==196-256&&a[k+31]==179-256&&a[k+34]==179-256)
		{
			if(j%2==1)
				player1++;
			else
				player2++;
			l=1;
		}
		if(a[k-65]==196-256&&a[k-31]==179-256&&a[k-34]==179-256)
		{
			if(j%2==1)
				player1++;
			else
				player2++;
			l=1;
		}
		if(l==1)
		{
			j--;
			l=0;
		}
		if(j%2==0)
			printf("%c%c%c%c%c%c %c %s.",143,152,229,157,156,160,166,name1);
		else
			printf("%c%c%c%c%c%c %c %s.",143,152,229,157,156,160,166,name2);
		printf("\n%s\t%s\n%d\t%d\n",name1,name2,player1,player2);
	}
	printf("Press any key to continue, or 'enter' to view the list of the moves you made\n");
	i=getch();
	if(i==13)
	{
		puts(c);
		printf("Press any key to continue");
		getch();
	}
}