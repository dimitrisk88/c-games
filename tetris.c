#include <Windows.h>
int top=0,score,level,next,t,a[9],nowa[19]={50595086,84807449,67964431,68030232,84875289,51187215,67440152,50595087,68032537,50595085,67440409,84741647,68032546,50595078,68030233,67439886,84807448,50597391,67440143};
unsigned int now;
void printris()
{
     int i=0,j,row;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){0,0});
     printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
     printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\t\t%c\n",186,218,196,196,196,196,196,196,196,196,196,196,191,186);
     for(i=0;i<200;i++)
     {
                       if(!(i%10))
                       printf("%c%c",186,179);
                       if(a[i/30]&1<<i%30||now%256==i||(now>>8)%256==i||(now>>16)%256==i||now>>24==i)
                       printf("%c",254);
                       else
                       printf(" ");
                       if(i%10==9)
                       {
                                  printf("%c",179);
                                  if(i==9)
                                  printf(" top score ");
                                  else if(i==29)
                                  printf("%10d ",top);
                                  else if(i==49)
                                  printf("     score ");
                                  else if(i==69)
                                  printf("%10d ",score);
                                  else if(i==89)
                                  printf("  next     ");
                                  else if(i==109)
                                  printf(" %c%c%c%c%c%c    ",218,196,196,196,196,191);
                                  else if(i>109&&i<159)
                                  {
                                       printf(" %c",179);
                                       j=(i/10-11)*4;
                                       row=i==119+j/4*10;
                                       printf("%c%c%c%c",(row&&next&1<<j)*222+32,(row&&next&2<<j)*222+32,(row&&next&4<<j)*222+32,(row&&next&8<<j)*222+32);
                                       printf("%c    ",179);
                                  }
                                  else if(i==159)
                                  printf(" %c%c%c%c%c%c    ",192,196,196,196,196,217);
                                  else if(i==179)
                                  printf(" Level %2d  ",level/10+1);
                                  else
                                  printf("\t\t");
                                  printf("%c\n",186);
                       }
     }
     printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\t\t%c\n",186,192,196,196,196,196,196,196,196,196,196,196,217,186);
     printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}
int randomt()
{
    int b=rand()%7;
    if(b<3)
    return b*4+rand()%4;
    else if(b<6)
    return 12+(b-3)*2+rand()%2;
    else
    return 18;
}
int checkPlace(int i)
{
    int b=0,j;
    b+=(a[(now%256+i)/30]&1<<(now%256+i)%30);
    if((int)(now>>8)%256+i>=0)
    b+=a[((now>>8)%256+i)/30]&1<<((now>>8)%256+i)%30;
    if((int)(now>>16)%256+i>=0)
    b+=a[((now>>16)%256+i)/30]&1<<((now>>16)%256+i)%30;
    if((int)(now>>24)+i>=0)
    b+=a[((now>>24)+i)/30]&1<<((now>>24)+i)%30;
    return !b;
}
void checkStage()
{
     int tempscore=0,i,j,k;
     for(i=(now>>24)/10;i<=now%256/10;i++)
     {
                                         k=0;
                                         if((a[i/3]&(1023<<(i%3*10)))==(1023<<(i%3*10)))
                                         k=1;
                                         if(k)
                                         {
                                              k=i/3;
                                              if(i%3==0&&k)
                                              a[k]=a[k]/1024*1024+a[k-1]/1048576;
                                              else if(i%3==1&&k)
                                              a[k]=a[k]/1048576*1048576+(a[k]%1024*1024)+a[k-1]/1048576;
                                              else if(k)
                                              k++;
                                              for(--k;k>0;k--)
                                              a[k]=a[k]%1048576*1024+a[k-1]/1048576;
                                              if(i>1)
                                              a[0]=(a[0]%1048576)*1024;
                                              else if(i==0)
                                              a[0]=a[0]/1024*1024;
                                              else
                                              a[0]=a[0]/1048576*1048576+a[0]%1024*1024;
                                              tempscore=100+tempscore*2;
                                              level++;
                                              }
                                         }
     score+=tempscore;
}
int moveDown()
{
    if(now%256<190&&checkPlace(10))
    {
     now+=168430090;
     return 1;
     }
    else
    {
        a[now%256/30]=a[now%256/30]|1<<now%256%30;
        a[(now>>8)%256/30]=a[(now>>8)%256/30]|1<<(now>>8)%256%30;
        a[(now>>16)%256/30]=a[(now>>16)%256/30]|1<<(now>>16)%256%30;
        a[(now>>24)/30]=a[(now>>24)/30]|1<<(now>>24)%30;
        checkStage();
        return 0;
        }
}
void moveLeft()
{
     if(now%256%10>0&&(now>>8)%256%10>0&&(now>>16)%256%10>0&&(now>>24)%10>0&&checkPlace(-1))
     now-=16843009;
}
void moveRight()
{
     if(now%256%10<9&&(now>>8)%256%10<9&&(now>>16)%256%10<9&&(now>>24)%10<9&&checkPlace(1))
     now+=16843009;
}
void rotate()
{
     int tempa=now,tempb=t;
     if(t<3||t>3&&t<7||t>7&&t<11||t==12||t==14||t==16)
     now-=nowa[t]-nowa[++t];
     else if(t==3||t==7||t==11)
     {
          now-=nowa[t]-nowa[t-3];
          t-=3;
          }
     else if(t==13||t==15||t==17)
     now-=nowa[t]-nowa[--t];
     if((t==0||t==5||t==7||t==9||t==13||t==17)&&(now>>24)%10==9||(t==2||t==11)&&(now>>16)%256%10==9||t==15&&(now>>8)%256%10==9)
     now+=16843009;
     else if(t==13&&now%256%10==0)
     now-=16843009;
     else if(t==13&&now%256%10==1)
     now-=16843009*2;
     if(now%256>199||!checkPlace(0))
     {
                       now=tempa;
                       t=tempb;
                       }
}
void move()
{
     int i;
     static int b=0;
     do{
	 	printris();
        for(i=0;i<20-level/10;i++)
        {
                                  if(GetAsyncKeyState(VK_UP)||GetAsyncKeyState('W')||GetAsyncKeyState(VK_RIGHT)||GetAsyncKeyState('D')||GetAsyncKeyState(VK_LEFT)||GetAsyncKeyState('A')||GetAsyncKeyState(VK_DOWN)||GetAsyncKeyState('S'))
                                  {
					   			  if(!b||b>4)
					   			  i++;
                                  if((!b||b>4)&&(GetAsyncKeyState(VK_UP)||GetAsyncKeyState('W')))
                                  rotate();
                                  if((!b||b>4)&&(GetAsyncKeyState(VK_RIGHT)||GetAsyncKeyState('D')))
                                  moveRight();
                                  else if((!b||b>4)&&(GetAsyncKeyState(VK_LEFT)||GetAsyncKeyState('A')))
                                  moveLeft();
                                  if((!b||b>4)&&(GetAsyncKeyState(VK_DOWN)||GetAsyncKeyState('S'))&&!moveDown())
                                  goto end;
		   						  b++;
		   						  printris();
                                  }
                                  else
                                  b=0;
                                  sleep(25);
        }
     }while(GetAsyncKeyState(VK_DOWN)||GetAsyncKeyState('S')||moveDown());
     end:;
}
int endGame()
{
    int b=0,i;
    if(t==0||t==2||t==5||t==7||t==9||t==11||t==15||t==17||t==18)
    b=1;
    else if(t==1||t==3||t==4||t==6||t==8||t==10||t==14||t==16)
    b=2;
    else if(t==12)
    b=3;
    for(i=b;i>=0;i--)
    if(!checkPlace(-10*i))
    return i+1;
    return 0;
}
int main()
{
    char asdf[50];
    int b,end,nexta[19]={624,1124,1824,610,1604,1808,550,1136,1570,368,1094,1856,8738,240,1122,864,612,1584,1632};
    srand(time(0));
    start:
    score=0;
    level=0;
    for(b=0;b<9;b++)
    a[b]=0;
    b=randomt();
    while(1)
    {
            now=nowa[b];
            t=b;
            end=endGame();
            if(end)
            {
                   now-=168430090*end;
                   printris();
                   break;
                   }
            b=randomt();
            next=nexta[b];
            move();
            }
    while(getch()!=' ');
    goto start;
}
