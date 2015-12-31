#include<conio.h>
#include<iostream.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<fstream.h>
#include<iomanip.h>
#include<string.h>
#include<process.h>
#include<math.h>
#include<ctype.h>
void start();
void showint(int,int,int,int);
void intro();       //The first introduction screen
int shootgame();  //The game
char highscore(int);  //Shows high score table and ask for playing again
void makebox(); //Makes box for high score table
void credits();
void showmenu(int[]);
int testgraph(void);
class PLAYER
{
  private:
    int ds,ms,ss,hs;
    int age,dd,mm,yy;
    char t1[5],admno[40],name[40],clas[3],sec[2],phone[10];
    int t2,rno,bno,page;
    char address[26];
    int d1,m1,y1,valid;
    int dt,mt,st,ht;
  public:
    void ADMIT(void);
    void DISPLAY(void);
};

void PLAYER::ADMIT(void)
{
  clrscr();
  struct time t;
  struct date d;
  getdate(&d);
  d1=d.da_day;
  m1=d.da_mon;
  y1=d.da_year;
  gettime(&t);
  dt=t.ti_hour;
  mt=t.ti_min;
  st=t.ti_sec;
  ht=t.ti_hund;
  int gdriver=DETECT, gmode;
  initgraph(&gdriver, &gmode, "d:\tc\bgi");
  setlinestyle(4,USERBIT_LINE,3);
  setcolor(1);
  rectangle(0,0,638,470);   //OUTER RECTANGLE
  setlinestyle(DASHED_LINE,USERBIT_LINE,1);
  setcolor(2);
  rectangle(1,1,637,469);   //INNER RECTANGLE
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  setcolor(4);
  outtextxy(180,20,"ABOUT PLAYER");
  setcolor(5);
  setlinestyle(4,USERBIT_LINE,3);
  line(170,60,430,60);
  line(160,65,440,65);
  settextstyle(1,HORIZ_DIR,2);
  setcolor(4);
  outtextxy(70,85,"PLEASE ENTER CORRECT DATA");
  gotoxy(11,9);
  cout<<"Current Date:"<<d1<<"\\"<<m1<<"\\"<<y1;
  gotoxy(44,9);
  cout<<"Current Time:"<<dt<<":"<<mt<<":"<<st<<"."<<ht;
  gotoxy(14,11);
  cout<<"Admission no.:";
  gotoxy(14,13);
  cout<<"Name         :";
  gotoxy(14,15);
  cout<<"Class        :";
  gotoxy(14,17);
  cout<<"Section      :";
  gotoxy(14,19);
  cout<<"Phone no.    :";
  gotoxy(14,21);
  cout<<"Age          :";
    do
    {
      valid=1;
      gotoxy(5,25);
      cout<<"Enter admission number of player:";
      gotoxy(34,11);
      gets(admno);
      strupr(admno);
      if(admno[0]=='0')
	      return;
      if(strlen(admno)<1||strlen(admno)>40)
      {
      	valid=0;
	      gotoxy(5,25);
        cout<<"Enter within range, 1-40";
	      getch();
      }
    }while(!valid);

    do
    {
      gotoxy(5,25);
      cout<<"Enter name of player"<<endl;
      gotoxy(34,13);
      gets(name);
      strupr(name);
      if(name[0]=='0')
	      return;
      if(strlen(name)<1||strlen(name)>40)
	    {
	       valid=0;
	       gotoxy(5,25);
	       cout<<"Enter within range, 1-40";
	       getch();
      }
    }while(!valid);

    do
    {
      valid=1;
      gotoxy(5,25);
      cout<<"Enter class of player";
      gotoxy(34,15);
      gets(clas);
      strupr(clas);
      if(clas[0]=='0')
      	return;
      if(strlen(clas)<1||strlen(clas)>3)
    	{
    	  valid=0;
    	  gotoxy(5,25);
    	  cout<<"Enter within range, 1-3";
    	  getch();
    	}
    }while(!valid);

    do
    {
      valid=1;
      gotoxy(5,25);
      cout<<"Enter section of player";
      gotoxy(34,17);
      gets(sec);
      strupr(sec);
      if(sec[0]=='0')
        return;
      if(strlen(sec)<1||strlen(sec)>2)
      {
        valid=0;
        gotoxy(5,25);
        cout<<"Enter within range, 1-2";
        getch();
      }
    }while(!valid);


    do
    {
      valid=1;
      gotoxy(5,25);
      cout<<"Enter Phone no. of player or <ENTER> for none ";
      gotoxy(34,19);
      gets(phone);
      if(phone[0]=='0')
        return;
      if(strlen(phone)<6&& strlen(phone)>0 ||(strlen(phone)>9))
      {
        valid=0;
        gotoxy(5,25);
        cout<<"Enter within range";
        getch();
      }
    }while(!valid);

    do
    {
      valid=1;
      gotoxy(5,25);
      cout<<"Enter age of player                             ";
      gotoxy(34,21);
      gets(t1);
      t2=atoi(t1);
      age=t2;
      if(t1[0]=='0')
        return;
      if(age<=0)
      {
        valid=0;
        gotoxy(5,25);
        cout<<"Enter correctly";
        getch();
      }
    }while(!valid);

    dd=d1;
    mm=m1;
    yy=y1;
    ds=dt;
    ms=mt;
    ss=st;
    hs=ht;
}  //end of admit (checked)

void PLAYER::DISPLAY(void)
{
  clrscr();
  int gdriver=DETECT,gmode;
  initgraph(&gdriver, &gmode, "d:\tc\bgi");
  setlinestyle(4,USERBIT_LINE,3);
  setcolor(15);
  rectangle(0,0,638,470); //OUTER RECTANGLE
  setlinestyle(DASHED_LINE, USERBIT_LINE,1);
  setcolor(2);
  rectangle(1,1,637,469);   //INNER RECTANGLE
  settextstyle(TRIPLEX_FONT, HORIZ_DIR,4);
  setcolor(4);
  outtextxy(180,20,"PLAYERS RECORD");
  setcolor(5);
  setlinestyle(4,USERBIT_LINE,3);
  line(170,60,460,60);
  line(160,65,470,65);
  gotoxy(11,9);
  printf("Date of play:%d/%d/%d",dd,mm,yy);
  gotoxy(44,9);
  printf("Time of play:%2d:%02d:%02d\n",ds,ms,ss,hs);
  gotoxy(14,11);
  cout<<"Admission no.        :"<<admno;
  gotoxy(14,13);
  cout<<"Name                 :"<<name;
  gotoxy(14,15);
  cout<<"Class                :"<<clas;
  gotoxy(14,17);
  cout<<"Section              :"<<sec;
  gotoxy(14,19);
  cout<<"Phone                :"<<phone;
  gotoxy(14,21);
  cout<<"Age                  :"<<age;
}

void main()
{
  int gdriver=DETECT,gmode;
    /* initialize graphics mode */
  initgraph(&gdriver, &gmode, "d:\tc\bgi");
  fstream f;
  PLAYER a;
  char cha='y';
  int y1[3]={150,200,250};
  int point=0,col,ch1,chk;
  char arr[100],arr1[100],msg[100];
  char ch;
  int corr=0;
  int counter;
  int x[1000],y[1000],r;
  int x_center=310,y_center=190,rad=100;
  int i,j;
  for(int s=0; s<=1200; s++)
  {
    int col=random(16);
    int x=random(630);
    int y=random(470);
    putpixel(x,y,col);
  }
  setlinestyle(4,USERBIT_LINE,3);
  setcolor(5);
  rectangle(0,0,638,470);   //OUTER RECTANGLE
  setlinestyle(DASHED_LINE,USERBIT_LINE,1);
  setcolor(2);
  rectangle(1,1,637,469);   //INNER RECTANGLE
  setlinestyle(SOLID_LINE,USERBIT_LINE,3);
  delay(1400);
  setcolor(4);//logo
  for(i=0;i<10;i++)
  {
    x[i]=x_center+rad*cos(36*i*3.14159/180);
    y[i]=y_center+rad*sin(36*i*3.14159/180);
  }
  for(i=0;i<10;i++)
  {
    for(j=0;j<10;j++)   //FOR DIAMOND
    {
      sound(i+1000);
      delay(6);
      line(x[i],y[i],x[j],y[j]);
      delay(6);
      line(4,4,x[i],y[i]);
      delay(6);
      line(4,4,x[j],y[j]);
    }
  }
  nosound();
  delay(150);
  int q;
  for(q=2;q<=235;q++)    //q=coordinate of x
  {
    sound(q+100);
    settextstyle(7,HORIZ_DIR,2);
    moveto(q,170);
    setcolor(q);
    outtext("  XII");
    delay(5);
    moveto(q,170);
    setcolor(BLACK);
    outtext("  XII");
  }
  nosound();
  moveto(q,170);
  setcolor(2);
  outtext("  XII");
  for(q=500;q>=335;q--)
  {
    sound(q-100);
    settextstyle(7,HORIZ_DIR,2);
    moveto(q,170);
    setcolor(q);
    outtext("PROJECT");
    delay(5);
    moveto(q,170);
    setcolor(BLACK);
    outtext("PROJECT");
  }
  nosound();
  moveto(q,170);
  setcolor(2);
  outtext("PROJECT");
  for(q=6;q<=160;q++)
  {
    sound(q+160);
    settextstyle(7,HORIZ_DIR,2);
    moveto(q,170);
    setcolor(q);
    outtext("CLASS");
    delay(5);
    moveto(q,170);
    setcolor(BLACK);
    outtext("CLASS");

  }
  nosound();
  moveto(q,170);
  setcolor(2);
  outtext("CLASS");   //for scrolling the name
  int npos=-380;
  char scroll[100];
  strcpy(scroll,"K.V C.L.R.I");
  for(int z=0,sp=315;z<760;z++,sp+=17)
  {
    setcolor(0);
    settextstyle(7,HORIZ_DIR,4);
    outtextxy(npos,420,scroll);
    setcolor(9);
    npos=npos+2;
    if(npos>=640)
      npos=-380;
    outtextxy(npos,420,scroll);
    sound(sp);
    delay(10);
    nosound();
  }
  setcolor(14);
  delay(200);
  outtextxy(50,370,"CREATED BY=>>");
  delay(150);
  int pos,color;
  while(!kbhit())
  {
    for(i=0,pos=315;i<=35;i++,pos+=15)
    {
      setcolor(i+rand());
      sound(pos);
      delay(10);
      outtextxy(315,370," B.DEEPAK ");
      nosound();
    }
  }
  cleardevice();
  clrscr();
  showmenu(y1);
  setcolor(12);
  ellipse(295,y1[point],0,360,80,20);
  chk=1;
  do
   {
    ch1=getch();
    if(ch1==72)
    {
      setcolor(0);
      ellipse(295,y1[point],0,360,80,20);
      if(point==0)
	      point=3;
      setcolor(col);
      ellipse(295,y1[--point],0,360,80,20);
    }
     else
     if(ch1==80)
     {
      setcolor(0);
      ellipse(295,y1[point],0,360,80,20);
      if(point==2)
	      point=-1;
      setcolor(col);
      ellipse(295,y1[++point],0,360,80,20);
     }
     else
     if(ch1==13)
     {
       switch(point)
       {
      	case 0:
      	  goto w;
      	case 1:
      	  goto r;
      	case 2:
      	  exit(1);
       }
	chk=0;
     }
     else
     if(ch1==27)
     {
       exit(0);
     }
   } while(chk);
  point++;
  w:
    {
      f.open("game.text",ios::app);
      a.ADMIT();
      f.write((char*)&a,sizeof(PLAYER));
      f.close();
    }
  outtextxy(50,400,"DO YOU WANT TO SEE PLAYER'S RECORDS IF YES PRESS Y");
  gotoxy(14,27);
  cin>>cha;
  if(cha!='y'&&cha!='Y')
    {
      goto gstart;
    }
  r:
    {
      f.open("game.txt",ios::in);
      f.read((char*)&a,sizeof(PLAYER));
      while(f)
      {
        a.DISPLAY();
        f.read((char*)&a,sizeof(PLAYER));
        settextstyle(1,HORIZ_DIR,2);
        setcolor(4);
	outtextxy(70,400,"PRESS ENTER FOR MORE RECORDS");
	getch();
      }
	f.close();
	goto gstart;
    }
  gstart:
  cleardevice();
  settextstyle(0,HORIZ_DIR,6);
  setcolor(GREEN);
  outtextxy(200,130,"GAME");
  outtextxy(240,220,"FOR");
  outtextxy(30,310,"INTELLIGENTS");
  getch();
  setlinestyle(4,USERBIT_LINE,3);
  setcolor(15);
  rectangle(3,10,637,400);    //OUTER RECTANGLE
  setlinestyle(DASHED_LINE,USERBIT_LINE,1);
  setcolor(2);
  rectangle(10,17,630,393);   //INNER RECTANGLE
  setlinestyle(TRIPLEX_FONT,HORIZ_DIR,4);
  setcolor(14);
  outtextxy(100,20,"SHOOT GAME");
  setcolor(5);
  setlinestyle(4,USERBIT_LINE,3);
  line(170,60,430,60);
  line(160,65,440,65);
  outtextxy(15,420,"PRESS ANY KEY");
  getch();
  cleardevice();
  settextstyle(0,0,4);
  sprintf(arr,"Ready To Play ?");
  setcolor(RED);
  outtextxy(100,50,arr);
  settextstyle(1,0,3);
  sprintf(arr,"(Please Read The Instruction)");
  setcolor(14);
  outtextxy(135,75,arr);
  settextstyle(2,0,6);
  sprintf(msg,"1)In this project you are presented with the famous game");
  setcolor(GREEN);
  outtextxy(30,170,msg);
  settextstyle(2,0,6);
  sprintf(msg,"called 'SHOOT GAME',but in the another way. ");
  setcolor(GREEN);
  outtextxy(55,190,msg);
  settextstyle(2,0,6);
  sprintf(msg,"2)You will be given chance to play only if you give ");
  setcolor(GREEN);
  outtextxy(30,210,msg);
  settextstyle(2,0,6);
  sprintf(msg,"correct answer, otherwise you will not be given a chance.");
  setcolor(GREEN);
  outtextxy(55,230,msg);
  settextstyle(2,0,6);
  sprintf(arr,"3)If you did't give the correct answer, please hand over");
  setcolor(GREEN);
  outtextxy(30,250,arr);
  settextstyle(2,0,6);
  sprintf(arr,"the Game.");
  setcolor(GREEN);
  outtextxy(55,270,arr);
  settextstyle(2,0,6);
  sprintf(arr,"4)Player who will give the correct first will be");
  setcolor(GREEN);
  outtextxy(30,290,arr);
  settextstyle(2,0,6);
  sprintf(arr,"given first chance in the game.");
  setcolor(GREEN);
  outtextxy(55,310,arr);
  settextstyle(2,0,6);
  sprintf(arr,"5)Please be INNOCENT in the game.");
  setcolor(GREEN);
  outtextxy(30,330,arr);
  settextstyle(6,0,1);
  sprintf(arr1,"Please press any key to proceed");
  setcolor(YELLOW);
  outtextxy(350,450,arr1);
  getch();
  cleardevice();
  setlinestyle(4,USERBIT_LINE,3);
  setcolor(15);
  rectangle(0,0,638,470); //OUTER RECTANGLE
  setlinestyle(DASHED_LINE,USERBIT_LINE,1);
  setcolor(2);
  rectangle(1,1,637,469);//inner rectangle
  settextstyle(2,0,5); // question section
  sprintf(arr,"Question[1]:");
  setcolor(RED);
  outtextxy(1,1,arr);
  gotoxy(1,2);
  cout<<"THE FIRST SATELLITE TO GO IN SPACE WAS:";
  settextstyle(2,0,5);
  sprintf(arr,"Options are:");
  setcolor(GREEN);
  outtextxy(30,30,arr);
  setlinestyle(0,SOLID_LINE,1);
  rectangle(26,47,44,64);
  gotoxy(5,4);
  cout<<"A";
  gotoxy(10,4);
  cout<<"EXPLORER";
  rectangle(26,79,44,96);
  gotoxy(5,6);
  cout<<"B";
  gotoxy(10,6);
  cout<<"LUNA";
  rectangle(26,111,44,128);
  gotoxy(5,8);
  cout<<"C";
  gotoxy(10,8);
  cout<<"SPUTNIK";
  rectangle(26,143,44,160);
  gotoxy(5,10);
  cout<<"D";
  gotoxy(10,10);
  cout<<"CHALLENGER";
  cout<<"\n\n\t\t***Enter your choice:";
  pre:
  {
      cin>>ch;
      if(ch=='c'||ch=='C')
      {
	settextstyle(7,HORIZ_DIR,1);
	setcolor(5);
	outtextxy(120,220,"CONGRATS!!!");
	settextstyle(1,HORIZ_DIR,1);
	outtextxy(70,250,"YOUE ANSWER IS CORRECT");
	for(counter=16;counter<=166;counter++)
	{
	  sound(100+(7*counter));
	  delay(10);
	}
	nosound();
	corr++;
  start();
      }
      else
      if(ch=='a'||ch=='b'||ch=='d' || ch == 'A' || ch == 'B' || ch == 'D' )
      {
	  settextstyle(7,HORIZ_DIR,1);
	  setcolor(5);
	  outtextxy(125,220,"SORRY!!!");
	  setcolor(5);
	  settextstyle(1,HORIZ_DIR,1);
	  outtextxy(70,250,"YOUR ANSWER IS WRONG");
	  outtextxy(70,280,"CORRECT ANSWER IS 'C'");
	  for(counter=16;counter<=166;counter++)
	  {
	    sound(1000+(100*counter));
	    delay(10);
	  }
	  nosound();
	  start();
      }
      else
      {
	  settextstyle(3,HORIZ_DIR,1);
	  setcolor(5);
	  outtextxy(70,190,"PLEASE ENTER CORRECT CHOICE:");
	  gotoxy(47,13);
	  goto pre;
      }
  } //  end of pre:
  getch();
  cleardevice();
  settextstyle(2,0,5);
  setlinestyle(4,USERBIT_LINE,3);
  setcolor(15);
  rectangle(0,0,638,470);
  setlinestyle(DASHED_LINE,USERBIT_LINE,1);
  setcolor(2);
  rectangle(1,1,637,469);   //INNER RECTANGLE
  sprintf(arr,"Question[2]:");
  setcolor(RED);
  outtextxy(1,1,arr);
  gotoxy(1,2);
  cout<<"THE FIRST WOMEN TO GO IN SPACE WAS:";
  settextstyle(2,0,5);
  sprintf(arr,"Options are:");
  setcolor(GREEN);
  outtextxy(30,30,arr);
  setlinestyle(0,SOLID_LINE,1);
  rectangle(26,47,44,64);
  gotoxy(5,4);
  cout<<"A";
  gotoxy(10,4);
  cout<<"YURI GAGARIN";
  rectangle(26,79,44,96);
  gotoxy(5,6);
  cout<<"B";
  gotoxy(10,6);
  cout<<"NADO COMONSESKHI";
  rectangle(26,111,44,128);
  gotoxy(5,8);
  cout<<"C";
  gotoxy(10,8);
  cout<<"RITA PHILLIPS";
  rectangle(26,143,44,160);
  gotoxy(5,10);
  cout<<"D";
  gotoxy(10,10);
  cout<<"VALENTINA TARESHKOV";
  cout<<"\n\n\t\t***Enter your choice:";
  pre1:
  {
    cin>>ch;
    if(ch=='d'||ch=='D')
    {
      settextstyle(7,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(120,220,"CONGRATS!!!");
      settextstyle(1,HORIZ_DIR,1);
      outtextxy(70,250,"YOUR ANSWER IS CORRECT");
      for(counter=16;counter<=166;counter++)
      {
      	sound(100+(7*counter));
      	delay(10);
      }
      nosound();
      corr++;
      start();
    }
    else
    if(ch=='b'||ch=='c'||ch=='a')
    {
      settextstyle(7,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(125,220,"SORRY!!!");
      setcolor(5);
      settextstyle(1,HORIZ_DIR,1);
      outtextxy(70,250,"YOUR ANSWER IS WRONG");
      outtextxy(70,280,"CORRECT ANSWER IS 'D'");
      for(counter=16;counter<=166;counter++)
      {
  	sound(1000+(100*counter));
	delay(10);
      }
      nosound();
      start();
    }
    else
    {
	settextstyle(3,HORIZ_DIR,1);
	setcolor(5);
	outtextxy(70,190,"PLEASE ENTER CORRECT CHOICE:");
	gotoxy(47,13);
	goto pre1;
    }
  }
  getch();
  cleardevice();
  settextstyle(2,0,5);
  setlinestyle(4,USERBIT_LINE,3);
  setcolor(15);
  rectangle(0,0,638,470);   //OUTER RECTANGLE
  setlinestyle(DASHED_LINE,USERBIT_LINE,1);
  setcolor(2);
  rectangle(1,1,637,469);   //INNER RECTANGLE
  sprintf(arr,"Question[3]:");
  setcolor(RED);
  outtextxy(1,1,arr);
  gotoxy(1,2);
  cout<<"INDIA'S RANGE OF GEOSTATIONARY SATELLITE IS:";
  settextstyle(2,0,5);
  sprintf(arr,"Options are:");
  setcolor(GREEN);
  outtextxy(30,30,arr);
  setlinestyle(0,SOLID_LINE,1);
  rectangle(26,47,44,64);
  gotoxy(5,4);
  cout<<"A";
  gotoxy(10,4);
  cout<<"IRS";
  rectangle(26,79,44,96);
  gotoxy(5,6);
  cout<<"B";
  gotoxy(10,6);
  cout<<"INSAT";
  rectangle(26,111,44,128);
  gotoxy(5,8);
  cout<<"C";
  gotoxy(10,8);
  cout<<"ROHINI";
  rectangle(26,143,44,160);
  gotoxy(5,10);
  cout<<"D";
  gotoxy(10,10);
  cout<<"BHASKARA";
  cout<<"\n\n\t\t***Enter your choice:";
  pre2:
  {
    cin>>ch;
    if(ch=='b'||ch=='B')
    {
      settextstyle(7,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(120,220,"CONGRATS!!!");
      settextstyle(1,HORIZ_DIR,1);
      outtextxy(70,250,"YOUR ANSWER IS  CORRECT");

      for(int counter=16;counter<=166;counter++);
      {
	sound(100+(7*counter));
	delay(10);
      }

      nosound();
      corr++;
      start();
    }
    else
    if(ch=='a'||ch=='c'||ch=='d')
    {
      settextstyle(7,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(125,220,"SORRY!!!");
      setcolor(5);
      settextstyle(1,HORIZ_DIR,1);
      outtextxy(70,250,"OUR ANSWER IS WRONG");
      outtextxy(70,280,"CORRECT ANSWER IS 'B'");
      for(int counter=16;counter<=166;counter++)
      {
	sound(1000+(100*counter));
	delay(10);
      }
      nosound();
      start();
    }
    else
    {
      settextstyle(3,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(70,190,"PLEASE ENTER CORRECT CHOICE:");
      gotoxy(47,13);
      goto pre2;
    }
  }
  getch();
  cleardevice();
  settextstyle(2,0,5);
  setlinestyle(4,USERBIT_LINE,3);
  setcolor(15);
  rectangle(0,0,638,470);   //OUTER RECTANGLE
  setlinestyle(DASHED_LINE,USERBIT_LINE,1);
  setcolor(2);
  rectangle(1,1,637,469);   //INNER RECTANGLE
  sprintf(arr,"Question[4]:");
  setcolor(RED);
  outtextxy(1,1,arr);
  gotoxy(1,2);
  cout<<"ORGAN RESPONSIBLE FOR REFLEX ACTION OF BODY IS:";
  settextstyle(2,0,5);
  sprintf(arr,"Options are:");
  setcolor(GREEN);
  outtextxy(30,30,arr);
  setlinestyle(0,SOLID_LINE,1);
  rectangle(26,47,44,64);
  gotoxy(5,4);
  cout<<"A";
  gotoxy(10,4);
  cout<<"BRAIN";
  rectangle(26,79,44,96);
  gotoxy(5,6);
  cout<<"B";
  gotoxy(10,6);
  cout<<"HEART";
  rectangle(26,111,44,128);
  gotoxy(5,8);
  cout<<"C";
  gotoxy(10,8);
  cout<<"PITUITARY GLAND";
  rectangle(26,143,44,160);
  gotoxy(5,10);
  cout<<"D";
  gotoxy(10,10);
  cout<<"SPINAL CORD";
  cout<<"\n\n\t\t***Enter your choice:";
  pre4:
  {
    cin>>ch;
    if(ch=='d'||ch=='D')
    {
      settextstyle(7,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(120,220,"CONGRATS!!!");
      settextstyle(1,HORIZ_DIR,1);
      outtextxy(70,250,"YOUR ANSWER IS CORRECT");
      for(int COUNTER=16;COUNTER<=166;COUNTER++)
      {
	sound(100+(7*counter));
	delay(10);
      }
      nosound();
      corr++;
      start();
    }
    else if(ch=='b'||ch=='c'||ch=='a')
    {
      settextstyle(7,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(125,220,"SORRY!!!");
      setcolor(5);
      settextstyle(1,HORIZ_DIR,1);
      outtextxy(70,250,"YOUR ANSWER IS WRONG");
      outtextxy(70,280," CORRECT ANSWER IS 'D'") ;
      for(counter=16;counter<=166;counter++)
      {
	sound(1000+(100*counter));
	delay(10);
      }
      nosound();
      start();
    }
    else
    {
      settextstyle(3,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(70,190,"PLEASE ENTER CORRECT CHOICE:");
      gotoxy(47,13);
      goto pre4;
    }
  }
  getch();
  cleardevice();
  settextstyle(2,0,5);
  setlinestyle(4,USERBIT_LINE,3);
  setcolor(15);
  rectangle(0,0,638,470);  //OUTER RECTANGLE
  setlinestyle(DASHED_LINE,USERBIT_LINE,1);
  setcolor(2);
  rectangle(1,1,637,469);   //INNER RECTANGLE
  sprintf(arr,"Question[5]:");
  setcolor(RED);
  outtextxy(1,1,arr);
  gotoxy(1,2);
  cout<<"METAL THAT FLOATS ON WATER IS:";
  settextstyle(2,0,5);
  sprintf(arr,"Options are :");
  setcolor(GREEN);
  outtextxy(30,30,arr);
  setlinestyle(0,SOLID_LINE,1);
  rectangle(26,47,44,64);
  gotoxy(5,4);
  cout<<"A";
  gotoxy(10,4);
  cout<<"SILVER";
  rectangle(26,79,44,96);
  gotoxy(5,6);
  cout<<"B";
  gotoxy(10,6);
  cout<<"SODIUM";
  rectangle(26,111,44,128);
  gotoxy(5,8);
  cout<<"C";
  gotoxy(10,8);
  cout<<"CALCIUM";
  rectangle(26,143,44,160);
  gotoxy(5,10);
  cout<<"D";
  gotoxy(10,10);
  cout<<"POTASSIUM";
  cout<<"\n\n\t\t***Enter your choice :";

  pre5:
  {
    cin>>ch;
    if (ch=='d' || ch=='D')
    {
      settextstyle(7,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(120,220,"CONGRATS!!!");
      settextstyle(1,HORIZ_DIR,1);
      outtextxy(70,250," YOUR ANSWER IS CORRECT");
      for (counter=16;counter<=166;counter++)
      {
	sound(100+(7*counter));
	delay(10);
      }
      nosound();
      corr++ ;
      start();
    }
    else if( ch == 'b' || ch == 'c' || ch == 'a')
    {
      settextstyle(7,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(125,220,"SORRY!!!");
      setcolor(5);
      settextstyle(1,HORIZ_DIR,1);
      outtextxy(70,250," YOUR ANSWER IS WRONG");
      outtextxy(70,280," CORRECT ANSWER IS 'D'");
      for (counter=16;counter<=166;counter++)
      {
	sound(1000+(100*counter));
  	delay(10);
      }
      nosound();
      start();
    }
    else
    {
      settextstyle(3,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(70,190,"PLEASE ENTER CORRECT CHOICE:");
      gotoxy(47,13);
      goto pre5;
    }
  }

  getch();
  cleardevice();
  settextstyle(2,0,5);
  setlinestyle(4,USERBIT_LINE,3);
  setcolor(15);
  rectangle(0,0,638,470); //OUTER RECTANGLE
  setlinestyle(DASHED_LINE,USERBIT_LINE,1);
  setcolor(2);
  rectangle(1,1,637,469); // INNER RECTANGLE
  sprintf(arr,"Question[6]:");
  setcolor(RED);
  outtextxy(1,1,arr);
  gotoxy(1,2);
  cout<<"PH FACTOR IS USED TO MEASURE:" ;
  settextstyle(2,0,5);
  sprintf(arr,"Options are :");
  setcolor(GREEN);
  outtextxy(30,30,arr);
  setlinestyle(0,SOLID_LINE,1);
  rectangle(26,47,44,64);
  gotoxy(5,4);
  cout<<"A";
  gotoxy(10,4);
  cout<<"COLOUR OF A LIQUID";
  rectangle(26,79,44,96);
  gotoxy(5,6);
  cout<<"B";
  gotoxy(10,6);
  cout<< "ACIDITY OF A LIQUID";
  rectangle(26,111,44,128);
  gotoxy(5,8);
  cout<<"C";
  gotoxy(10,8);
  cout<<"DENSITY OF A LIQUID";
  rectangle(26,143,44,160);
  gotoxy(5,10);
  cout<<"D";
  gotoxy(10,10);
  cout<<"TURBIDITY OF A LIQUID";
  cout<<"\n\n\t\t***Enter your choice :";

  pre6:
  {
    cin>>ch;
    if(ch=='b' || ch=='B')
    {
      settextstyle(7,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(120,220,"CONGRATS!!!");
      settextstyle(1,HORIZ_DIR,1);
      outtextxy(70,250," YOUR ANSWER IS CORRECT");
      for (counter=16;counter<=166;counter++)
      {
	sound(100+(7*counter));
	delay(10);
      }
      nosound();
      corr++;
      start();
    }
    else if( ch == 'a' || ch == 'c' || ch == 'd')
    {
      settextstyle(7,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(125,220,"SORRY!!!");
      setcolor(5);
      settextstyle(1,HORIZ_DIR,1);
      outtextxy(70,250," YOUR ANSWER IS WRONG");
      outtextxy(70,280," CORRECT ANSWER IS 'B'");
      for (counter=16;counter<=166;counter++)
      {
	sound(1000+(100*counter));
	delay(10);
      }
      nosound();
      start();
    }
    else
    {
      settextstyle(3,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(70,190,"PLEASE ENTER CORRECT CHOICE :");
      gotoxy(47,13);
      goto pre6;
    }
  }

  getch();
  cleardevice();
  settextstyle(2,0,5);
  setlinestyle(4,USERBIT_LINE,3);
  setcolor(15);
  rectangle(0,0,638,470); //OUTER RECTANGLE
  setlinestyle(DASHED_LINE,USERBIT_LINE,1);
  setcolor(2);
  rectangle(1,1,637,469); // INNER RECTANGLE
  sprintf(arr,"Question[7]:");
  setcolor(RED);
  outtextxy(1,1,arr);
  gotoxy(1,2);
  cout<<"MATERIAL USED TO FORM SEMI-CONDUCTORS" ;
  settextstyle(2,0,5);
  sprintf(arr,"Options are :");
  setcolor(GREEN);
  outtextxy(30,30,arr);
  setlinestyle(0,SOLID_LINE,1);
  rectangle(26,47,44,64);
  gotoxy(5,4);
  cout<<"A";
  gotoxy(10,4);
  cout<<"SILICON";
  rectangle(26,79,44,96);
  gotoxy(5,6);
  cout<<"B";
  gotoxy(10,6);
  cout<< "ZINC";
  rectangle(26,111,44,128);
  gotoxy(5,8);
  cout<<"C";
  gotoxy(10,8);
  cout<<"ALUMINIUM";
  rectangle(26,143,44,160);
  gotoxy(5,10);
  cout<<"D";
  gotoxy(10,10);
  cout<<"GALLIUM";
  cout<<"\n\n\t\t***Enter your choice :";

  pre7:
  {
    cin>>ch;
    if(ch=='A' || ch=='a')
    {
      settextstyle(7,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(120,220,"CONGRATS!!!");
      settextstyle(1,HORIZ_DIR,1);
      outtextxy(70,250," YOUR ANSWER IS CORRECT");
      for (counter=16;counter<=166;counter++)
      {
      	sound(100+(7*counter));
      	delay(10);
      }
      nosound();
      corr++;
      start();
    }
    else if( ch == 'b' || ch == 'c' || ch == 'd')
    {
      settextstyle(7,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(125,220,"SORRY!!!");
      setcolor(5);
      settextstyle(1,HORIZ_DIR,1);
      outtextxy(70,250," YOUR ANSWER IS WRONG");
      outtextxy(70,280," CORRECT ANSWER IS 'A'");
      for (counter=16;counter<=166;counter++)
      {
      	sound(1000+(100*counter));
      	delay(10);
      }
      nosound();
      start();
    }
    else
    {
      settextstyle(3,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(70,190,"PLEASE ENTER CORRECT CHOICE :");
      gotoxy(47,13);
      goto pre7;
    }
  }
  getch();
  cleardevice();
  settextstyle(2,0,5);
  setlinestyle(4,USERBIT_LINE,3);
  setcolor(15);
  rectangle(0,0,638,470); //OUTER RECTANGLE
  setlinestyle(DASHED_LINE,USERBIT_LINE,1);
  setcolor(2);
  rectangle(1,1,637,469); // INNER RECTANGLE
  sprintf(arr,"Question[8]:");
  setcolor(RED);
  outtextxy(1,1,arr);
  gotoxy(1,2);
  cout<<" WRITER OF BOOK 'MY MUSIC MY LIFE' :" ;
  settextstyle(2,0,5);
  sprintf(arr,"Options are :");
  setcolor(GREEN);
  outtextxy(30,30,arr);
  setlinestyle(0,SOLID_LINE,1);
  rectangle(26,47,44,64);
  gotoxy(5,4);
  cout<<"A";
  gotoxy(10,4);
  cout<<"RABINDRANATH TAGORE";
  rectangle(26,79,44,96);
  gotoxy(5,6);
  cout<<"B";
  gotoxy(10,6);
  cout<< "S.M. ALI";
  rectangle(26,111,44,128);
  gotoxy(5,8);
  cout<<"C";
  gotoxy(10,8);
  cout<<"RAVI SHANKAR";
  rectangle(26,143,44,160);
  gotoxy(5,10);
  cout<<"D";
  gotoxy(10,10);
  cout<<"PILOO MODY";
  cout<<"\n\n\t\t***Enter your choice :";

  pre8:
  {
    cin>>ch;
    if(ch=='c' || ch=='C')
    {
      settextstyle(7,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(120,220,"CONGRATS!!!");
      settextstyle(1,HORIZ_DIR,1);
      outtextxy(70,250," YOUR ANSWER IS CORRECT");
      for (counter=16;counter<=166;counter++)
      {
      	sound(100+(7*counter));
      	delay(10);
      }
      nosound();
      corr++;
      start();
    }
    else if( ch == 'b' || ch == 'a' || ch == 'd')
    {
      settextstyle(7,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(125,220,"SORRY!!!");
      setcolor(5);
      settextstyle(1,HORIZ_DIR,1);
      outtextxy(70,250," YOUR ANSWER IS WRONG");
      outtextxy(70,280," CORRECT ANSWER IS 'C'");
      for (counter=16;counter<=166;counter++)
      {
	      sound(1000+(100*counter));
	      delay(10);
      }
      nosound();
      start();
    }
    else
    {
      settextstyle(3,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(70,190,"PLEASE ENTER CORRECT CHOICE :");
      gotoxy(47,13);
      goto pre8;
    }
  }

  getch();
  cleardevice();
  settextstyle(2,0,5);
  setlinestyle(4,USERBIT_LINE,3);
  setcolor(15);
  rectangle(0,0,638,470); //OUTER RECTANGLE
  setlinestyle(DASHED_LINE,USERBIT_LINE,1);
  setcolor(2);
  rectangle(1,1,637,469); // INNER RECTANGLE
  sprintf(arr,"Question[9]:");
  setcolor(RED);
  outtextxy(1,1,arr);
  gotoxy(1,2);
  cout<<" THE No. OF HOLES IN GOLF ARE " ;
  settextstyle(2,0,5);
  sprintf(arr,"Options are :");
  setcolor(GREEN);
  outtextxy(30,30,arr);
  setlinestyle(0,SOLID_LINE,1);
  rectangle(26,47,44,64);
  gotoxy(5,4);
  cout<<"A";
  gotoxy(10,4);
  cout<<"8";
  rectangle(26,79,44,96);
  gotoxy(5,6);
  cout<<"B";
  gotoxy(10,6);
  cout<< "12";
  rectangle(26,111,44,128);
  gotoxy(5,8);
  cout<<"C";
  gotoxy(10,8);
  cout<<"15";
  rectangle(26,143,44,160);
  gotoxy(5,10);
  cout<<"D";
  gotoxy(10,10);
  cout<<"18";
  cout<<"\n\n\t\t***Enter your choice :";

  pre9:
  {
    cin>>ch;
    if(ch=='D' || ch=='d')
    {
      settextstyle(7,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(120,220,"CONGRATS!!!");
      settextstyle(1,HORIZ_DIR,1);
      outtextxy(70,250," YOUR ANSWER IS CORRECT");
      for (counter=16;counter<=166;counter++)
      {
	sound(100+(7*counter));
	delay(10);
      }
      nosound();
      corr++;
      start();
    }
    else if( ch == 'b' || ch == 'a' || ch == 'c')
    {
       settextstyle(7,HORIZ_DIR,1);
       setcolor(5);
       outtextxy(125,220,"SORRY!!!");
       setcolor(5);
       settextstyle(1,HORIZ_DIR,1);
       outtextxy(70,250," YOUR ANSWER IS WRONG");
       outtextxy(70,280," CORRECT ANSWER IS 'D'");
       for (counter=16;counter<=166;counter++)
       {
	 sound(1000+(100*counter));
	 delay(10);
       }
       nosound();
       start();
    }
    else
    {
       settextstyle(3,HORIZ_DIR,1);
       setcolor(5);
       outtextxy(70,190,"PLEASE ENTER CORRECT CHOICE :");
       gotoxy(47,13);
       goto pre9;
    }
  }

  getch();
  cleardevice();
  settextstyle(2,0,5);
  setlinestyle(4,USERBIT_LINE,3);
  setcolor(15);
  rectangle(0,0,638,470); //OUTER RECTANGLE
  setlinestyle(DASHED_LINE,USERBIT_LINE,1);
  setcolor(2);
  rectangle(1,1,637,469); // INNER RECTANGLE
  sprintf(arr,"Question[10]:");
  setcolor(RED);
  outtextxy(1,1,arr);
  gotoxy(1,2);
  cout<<" TERM 'LOANS' TO INDUSTRY IS PROVIDED BY " ;
  settextstyle(2,0,5);
  sprintf(arr,"Options are :");
  setcolor(GREEN);
  outtextxy(30,30,arr);
  setlinestyle(0,SOLID_LINE,1);
  rectangle(26,47,44,64);
  gotoxy(5,4);
  cout<<"A";
  gotoxy(10,4);
  cout<<"IDBI";
  rectangle(26,79,44,96);
  gotoxy(5,6);
  cout<<"B";
  gotoxy(10,6);
  cout<< "RBI";
  rectangle(26,111,44,128);
  gotoxy(5,8);
  cout<<"C";
  gotoxy(10,8);
  cout<<"UTI";
  rectangle(26,143,44,160);
  gotoxy(5,10);
  cout<<"D";
  gotoxy(10,10);
  cout<<"EXIM BANK";
  cout<<"\n\n\t\t***Enter your choice :";

  pre10:
  {
    cin>>ch;
    if(ch=='a' || ch=='A')
    {
      settextstyle(7,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(120,220,"CONGRATS!!!");
      settextstyle(1,HORIZ_DIR,1);
      outtextxy(70,250," YOUR ANSWER IS CORRECT");
      for (counter=16;counter<=166;counter++)
      {
	sound(100+(7*counter));
	delay(10);
      }
      nosound();
      corr++;
      sound(400);delay(600);nosound();
      sound(450);delay(600);nosound();
      sound(475);delay(400);nosound();
      sound(400);delay(400);nosound();
      sound(450);delay(400);nosound();
      sound(475);delay(400);nosound();
      sound(525);delay(400);nosound();
      sound(600);delay(1200);nosound();

    }
    else if( ch == 'b' || ch == 'd' || ch == 'c')
    {
      settextstyle(7,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(125,220,"SORRY!!!");
      setcolor(5);
      settextstyle(1,HORIZ_DIR,1);
      outtextxy(70,250," YOUR ANSWER IS WRONG");
      outtextxy(70,280," CORRECT ANSWER IS 'A'");
      for (counter=16;counter<=166;counter++)
      {
	sound(1000+(100*counter));
	delay(10);
      }
      nosound();
      sound(400);delay(600);nosound();
      sound(450);delay(600);nosound();
      sound(475);delay(400);nosound();
      sound(400);delay(400);nosound();
      sound(450);delay(400);nosound();
      sound(475);delay(400);nosound();
      sound(525);delay(400);nosound();
      sound(600);delay(1200);nosound();
    }
    else
    {
      settextstyle(3,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(70,190,"PLEASE ENTER CORRECT CHOICE :");
      gotoxy(47,13);
      goto pre10;
    }
  }
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  setcolor(8);
  outtextxy(180,420,"PRESS ANY KEY FOR RESULT");
  getch();
  cleardevice();
  if (corr>5)
  {
    setlinestyle(4,USERBIT_LINE,3);
    setcolor(15);
    rectangle(3,10,637,400);
    setlinestyle(DASHED_LINE,USERBIT_LINE,1)  ;
    setcolor(2);
    rectangle(10,17,630,393);
    settextstyle(4,HORIZ_DIR,4);
    setcolor(RED);
    outtextxy(230,100,"YOU ARE");
    settextstyle(0,HORIZ_DIR,7);
    setcolor(GREEN);
    outtextxy(140,150,"WINNER");
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
    setcolor(14);
    outtextxy(160,20,"CONGRATULATIONS");
    setcolor(5);
    setlinestyle(4,USERBIT_LINE,3);
    line(170,60,460,60);
    line(160,65,470,65);
    setcolor(5);
    settextstyle(1,HORIZ_DIR,1);
    outtextxy(250,240,"YOU GAVE");
    gotoxy(37,18);
    cout<<corr;
    outtextxy(180,290," CORRECT ANSWERS OUT OF 10");
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
    setcolor(3);
    outtextxy(65,340,"NOW YOU CAN PLAY SHOOT GAME");
    setcolor(8);
    outtextxy(180,420,"PRESS ANY KEY");
    getch();
    cleardevice();
    goto game;
  }
  else
  {
    setlinestyle(4,USERBIT_LINE,3);
    setcolor(15);
    rectangle(3,10,637,400);
    setlinestyle(DASHED_LINE,USERBIT_LINE,1) ;
    setcolor(2);
    rectangle(10,17,630,393);
    settextstyle(4,HORIZ_DIR,4);
    setcolor(RED);
    outtextxy(230,100,"YOU ARE");
    settextstyle(0,HORIZ_DIR,7);
    setcolor(GREEN);
    outtextxy(140,150,"LOOSER");
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
    setcolor(14);
    outtextxy(230,20,"SORRY");
    setcolor(5);
    setlinestyle(4,USERBIT_LINE,3);
    line(240,60,350,60);
    line(230,65,355,65);
    setcolor(5);
    settextstyle(1,HORIZ_DIR,1);
    outtextxy(250,240,"YOU GAVE");
    gotoxy(37,18);
    cout<<corr;
    outtextxy(180,290," CORRECT ANSWERS OUT OF 10");
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
    setcolor(3);
    outtextxy(45,340,"NO, YOU CAN'T PLAY SHOOT GAME");
    setcolor(2);
    outtextxy(180,420,"PRESS ANY KEY");
    getch();
    goto cred;
  }    // question section ends

  game:
  {
      int stime;
      char ch;
      intro();           // show the first introduction screen

      playagain:
      cleardevice();
      stime=shootgame();
      ch=highscore(stime);
      if ( ch == 'y' )
      goto playagain;
      settextstyle(7,HORIZ_DIR,3);
      setcolor(0);
      outtextxy(145,96,"You Did Not Play The Game");
      outtextxy(80,96, "Thank You For Playing UFO Shootout");
      setcolor(10);
      outtextxy(132,96,"Developed by  B.DEEPAK   KV CLRI Chennai");
      cred:
      credits();
      closegraph();
  }
}             //end of main()

void showmenu(int y1[])
{
    cleardevice();
    setlinestyle(4,USERBIT_LINE,3);
    setcolor(15);
    rectangle(3,10,630,400);
    setlinestyle(DASHED_LINE,USERBIT_LINE,1);
    setcolor(2);
    rectangle(10,17,623,393);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
    setcolor(14);
    outtextxy(180,20, "SHOOT GAME");
    setcolor(5);
    setlinestyle(4,USERBIT_LINE,3);
    line(170,60,430,60);
    line(160,65,440,65);
    settextstyle(SMALL_FONT,HORIZ_DIR,6);
    setcolor(13);
    char *str[3]=
    {  "Play Game",
       "About Player",
       "Exit"
    };
    for (int i=0; i<6; i++)
    {
       setcolor(i+11);
       outtextxy(250,y1[i]-10,str[i]);
    }
    settextstyle(SMALL_FONT,HORIZ_DIR,5);
    setcolor(5);
    outtextxy(15, 410,"ENTER key to select");
    outtextxy(490,410,"ESC key to exit");
    outtextxy(15, 440,"ARROW keys to traverse");
}  // SHOW MENU

void start(void)
{
    sound(400);delay(600);nosound();
    sound(450);delay(600);nosound();
    sound(475);delay(400);nosound();
    sound(400);delay(400);nosound();
    sound(450);delay(400);nosound();
    sound(475);delay(400);nosound();
    sound(525);delay(400);nosound();
    sound(600);delay(1200);nosound();
    settextstyle(0,HORIZ_DIR,1);
    outtextxy(330,390," LOADING...");
    settextstyle(3,HORIZ_DIR,1);
    outtextxy(240,410," PLEASE WAIT");
    outtextxy(130,440," COMPUTER IS LOADING NEXT QUESTION");
    setcolor(12);
    rectangle(168,366,425,376);
    int i,s;
    for (s=0; s<251; s=s+1)
    {
       for ( i=0; i<2 ; i++ )
       {
	  setcolor(7);
	  rectangle(171+s,369,171+i,373);
       }
       delay(15);
    }
    settextstyle(0,HORIZ_DIR,1);
    setcolor(0);
    outtextxy(330,390," LOADING....");
    setcolor(15);
    setfillstyle(1,15);
    outtextxy(330,390, "LOADING DONE");
}

void showint( int x, int y, int value, int col) // to convert int to strings
{
    int i,a;
    char integer[10],b='a';
    for(i = 0 ; value > 0 ; i++)
    {
      a = value % 10;
      if ( a==0) b='0';
      if ( a==1) b='1';
      if ( a==2) b='2';
      if ( a==3) b='3';
      if ( a==4) b='4';
      if ( a==5) b='5';
      if ( a==6) b='6';
      if ( a==7) b='7';
      if ( a==8) b='8';
      if ( a==9) b='9';
      integer[i]=b;
      value/=10;
    }
    integer[i]='\0';
    strrev(integer);
    if ( b=='a')
    {
       strcpy(integer,"0");
    }
    setcolor(col);
    outtextxy(x,y,integer);
}

void intro()     // THE FIRST INTRODUCTION SCREEN
{
    setcolor(15); // main lines
    setlinestyle(SOLID_LINE,1,3);
    rectangle(0,0,639,479);
    line(0,90,640,90);
    line(0,190,640,190);
    setlinestyle(SOLID_LINE,1,1);  // HEADING
    settextstyle(7,HORIZ_DIR,5);
    setcolor(12);
    outtextxy(160,10,"UFO Shootout");
    settextstyle(7,HORIZ_DIR,5);
    setcolor(10);
    outtextxy(80,100,"UFO Season Now Open");
    setcolor(14);   // TEXT
    settextstyle(8,HORIZ_DIR,1);
    setcolor(13);
    outtextxy(14,190,"The following game is presented as a EDUCATIONAL GAME");
    settextstyle(8,HORIZ_DIR,2);
    setcolor(11);
    outtextxy(10,219,"The objective of the game is simple. Shoot down as");
    outtextxy(10,241,"many UFO's as you can. The keys to be used in the ");
    outtextxy(10,262,"game are mentioned on the top of the game screen. ");
    outtextxy(10,284,"IF an UFO passes undestructed, one of your gun bases");
    outtextxy(10,306,"becomes unusable. Usage of all available gun bases is");
    outtextxy(10,328,"allowed.When all seven bases are destroyed the   ");
    outtextxy(10,350,"game gets over. The game statistics are displayed on ");
    outtextxy(10,372,"the top. You are scored on the basis of your survival");
    outtextxy(10,394,"time. UFO's for destruction shows how many more" )  ;
    outtextxy(10,416,"UFO's need to pass overhead before destruction.  ");
    setcolor(13);
    outtextxy(10,446,"Happy shooting and best of luck");
    setcolor(14);
    settextstyle(7,HORIZ_DIR,2);
    outtextxy(410,450,"B.DEEPAK");
    getch();
}

int shootgame()    // The game
{
    int x, colb, coli, sizex, sizey, dir, start, stop, i, miss=0, ship=0;
    int mis=0, col=12, pos=423, shot=0, dev, hit=0, snd=1, speed=13;
    int gunx=320, guny=426, casemiss, hitcolor, sx[1000], sy[1000];
    int acc=18+0, varyspeed=1, gunspeed=10, gamelength=1+0, vspeed=0;
    int speedgun=0, npos=-380, bonus=0;
    float y, tim=0;
    int stime=0; // for returning survival time
    char ch, pause='a', scroll[100];
    strcpy(scroll,"Done by B.DEEPAK");
    for (i=0;i<1000; i++)
    {
	sx[i]=random(640);
	sy[i]=random(318)+131;
    }
    // game title
    settextstyle(10,HORIZ_DIR,3);
    setfillstyle(SOLID_FILL,11);
    floodfill(100,10,11);
    floodfill(140,10,11);
    floodfill(180,10,11);
    floodfill(260,10,11);
    floodfill(310,10,11);
    floodfill(340,10,11);
    floodfill(420,10,11);
    floodfill(460,10,11);
    floodfill(490,10,11);
    floodfill(540,10,11);
     // UFO's at sides if the game title
    setlinestyle(SOLID_LINE,1,1);
    setcolor(10);
    setfillstyle(SOLID_FILL,0);
    fillellipse(45,25,40,10);
    fillellipse(595,25,40,10);
    setfillstyle(SOLID_FILL,9);
    fillellipse(45,25,40/3,10/3);
    fillellipse(595,25,40/3,10/3);
    setcolor(14);
    arc(45,25,0,180,40/3);
    arc(595,25,0,180,40/3);
    // screen text and lines
    setlinestyle(SOLID_LINE,1,3);
    setcolor(15);
    line(0,45,640,45);
    line(0,97,640,97);
    line(0,128,640,128);
    setcolor(14);
    settextstyle(11,HORIZ_DIR,1);
    outtextxy(4,50,"Ingame Keys:");
    outtextxy(410,50,"Game Statistics:");
    setcolor(3);
    outtextxy(4,59,  "(r),_: Gun Left/Right   " );
    outtextxy(4,68,  "Spc  : Shoot gun        " );
    outtextxy(4,77,  "+,-  : Inc/Dec Gun  Speed" );
    outtextxy(4,86,  "/,*  : Inc/Dec Game Speed" );
    outtextxy(210,59,"   P : Pause / Unpause " );
    outtextxy(210,68,"   S : Sound On / Off  " );
    outtextxy(210,77,"   D : Game Defaults   " );
    outtextxy(210,86,"Esc : Quit             " );
    outtextxy(410,59,"UFO's HIT              " );
    outtextxy(410,68,"UFO's missed           " );
    outtextxy(410,77,"Total Survival Time    " );
    outtextxy(410,86,"UFO's for Destruction  " );
    outtextxy(210,50,"BONUS POINTS           " );
    // Draw Gun bases
    setcolor(15);
    setfillstyle(SOLID_FILL,12);
    pieslice(320-270,477,0,180,30);
    pieslice(320+270,477,0,180,30);
    pieslice(320-180,477,0,180,30);
    pieslice(320+180,477,0,180,30);
    pieslice(320-90,477,0,180,30);
    pieslice(320+90,477,0,180,30);
    pieslice(320,477,0,180,30);
    setcolor(13);
    setfillstyle(SOLID_FILL,9);
    fillellipse(gunx-90,480,30,30);
    fillellipse(gunx-180,480,30,30);
    fillellipse(gunx-270,480,30,30);
    fillellipse(gunx,480,30,30);
    fillellipse(gunx+90,480,30,30);
    fillellipse(gunx+180,480,30,30);
    fillellipse(gunx+270,480,30,30);
    setcolor(0);
    setlinestyle(SOLID_LINE,1,3);
    line(gunx,480,gunx,guny);
    line(gunx-90,480,gunx-90,guny);
    line(gunx-180,480,gunx-180,guny);
    line(gunx-270,480,gunx-270,guny);
    line(gunx+90,480,gunx+90,guny);
    line(gunx+180,480,gunx+180,guny);
    line(gunx+270,480,gunx+270,guny);
    setcolor(15);
    rectangle(0,0,639,479);
    setcolor(12);
    settextstyle(5,HORIZ_DIR,4);
    outtextxy(60,180,"Just Remember");
    outtextxy(60,230,"Only one shot is allowed at a time");
    setcolor(3);
    settextstyle(2,HORIZ_DIR,8);
    outtextxy(85,350,"Press any key to start the game");
    ch=getch();       //Removes the above characters from the screen
    setcolor(0);
    settextstyle(5,HORIZ_DIR,4);
    outtextxy(60,180,"Just Remember");
    outtextxy(60,230,"Only one shot is allowed at a time");
    settextstyle(2,HORIZ_DIR,8);
    outtextxy(85,350,"Press any key to start the game");
    if(ch==char(27))
    {
       setcolor(10);
       settextstyle(7,HORIZ_DIR,3);
       outtextxy(145,96,"You Did Not Play the Game");
    }
    // Animation Randomizations
    animate:
    randomize();
    y=rand()%185+185;// Initial hight of UFO ( Y - Axis)
    colb=rand()%7+9;
    coli=rand()%7+9; //Colors of UFO
    sizex=rand()%20+30;
    sizey=sizex/4;
    dir=rand()%2;
    ship++;
    if (dir==1)
    {
    	dir=1;
    	start=-50;
    	stop=700;
    }
    if (dir==0)
    {
    	dir = -1;
    	start = 690;
    	stop = -60;
    }
    for ( x=start; ( x >= stop && dir==-1 ) || ( x <= stop && dir == 1) ;
	     x = x + varyspeed * dir)
    {
    	varyspeed = rand() % 15 + 1 ; //Variance in speed
    	tim = tim + 4 ;               // calculate time
    	miss = ship - hit - 1 ;       // Total misses
    	casemiss = miss / gamelength ; // misses out of 7 Destroy Gun bases
    	setcolor(15);
    	setfillstyle(SOLID_FILL,0);
    	switch(casemiss)
    	{
    	    case 1  : pieslice ( 320 - 270, 477, 0, 180,30);
    		      break;
    	    case 2  : pieslice ( 320 + 270, 477, 0, 180,30);
    		      break;
    	    case 3  : pieslice ( 320 - 180, 477, 0, 180,30);
    		      break;
    	    case 4  : pieslice ( 320 + 270, 477, 0, 180,30);
    		      break;
    	    case 5  : pieslice ( 320 - 90, 477, 0, 180,30);
    		      break;
    	    case 6  : pieslice ( 320 + 90, 477, 0, 180,30);
    		      break;
    	    case 7  : pieslice ( 320 , 477, 0, 180,30);
    	      	      settextstyle (11, HORIZ_DIR,1);
    	              showint (600, 68, miss-1,0);
  	              showint (600, 68, miss, 15);
  	              showint (660, 86, gamelength*7-miss+1, 0);
  	              showint (660, 86, gamelength*7-miss, 15);
  	              setcolor(15) ;
  	              setlinestyle(SOLID_LINE, 1, 3);
  	              rectangle(0, 0, 639, 479);
  	              delay(1000);
  	              goto  end;

	}
			  //  play sound on miss
	if(miss>mis &&  snd==1)
	{
	  sound(30);
	  delay(300);
	  nosound();
	}
	mis=miss;          // automatically move gun if base is already destroyed
	setcolor(0);
	setlinestyle(SOLID_LINE, 1, 3);
	line(gunx, 477, gunx, guny);
	if(miss==1*gamelength &&  gunx<=320-270)
	   gunx=320-180;
	if(miss==2*gamelength &&  gunx>=320+270)
	   gunx=320+180;
	if(miss==3*gamelength &&  gunx<=320-180)
	   gunx=320-90;
	if(miss==4*gamelength && gunx>=320+180)
	   gunx=320+90;
	if(miss==5*gamelength &&  gunx<=320-90)
	   gunx=320;
	if(miss==6*gamelength &&  gunx>=320+90)
	   gunx=320;
	if(miss==7*gamelength &&  gunx!=320-270 )
	{
	  gunx=320+420;
	  if(snd==1)
	    sound(70);
	  delay(300);
	  goto end;
	}
	setcolor(9) ;   //  Animation  Continued
	setlinestyle (SOLID_LINE, 1  , 3) ;
	line (gunx, 477, gunx, guny);
	setlinestyle (SOLID_LINE, 1  , 1);
	for(i=0;i<1000; i ++)
	putpixel (sx[i], sy[i], rand() %15 + 1) ; //  Put stars

	/// Calculate up and down movement of UFO
	dev=rand() %12 - 5;
	if (dev==0)
	  dev++;
	if (dev<0)
	  dev=dev-2;
	y+=.6*dev;
	if(y<155)
	   y=155;
	if( (hit==4)  || (hit==8) || (hit==12) || (hit==21) || (hit==25)||
	    (hit==29) || (hit==35) || (hit==44))
	{
	  setcolor(colb);
	  setfillstyle(CLOSE_DOT_FILL,coli);
	  fillellipse(x,y,sizex+30,sizey+10);
	  setcolor(coli);
	  setfillstyle(SOLID_FILL, coli);
	  fillellipse (x,y, (sizex+30)/3, sizey+10/3);
	  setfillstyle (SOLID_FILL, coli+2);
	  fillellipse(x,y, (sizex+5)/3, sizey/3);
	  setcolor(coli+5);
	  outtextxy(x-30, y-15, "LOOT" );
	  circle (x,y-25, 12);
	  circle (x,y-25, 10);
	  circle (x,y-25, 8);
	  circle (x,y-25, 6);
	  circle (x,y-25, 4);
	  circle (x,y-25, 2);
	}
	else
	if ( (hit==15) ||  (hit==16) ||  (hit==17) ||  (hit==30) ||
	    (hit==31) || (hit==32) ||  (hit==48) ||  (hit==49) ||  (hit==50) )
	{
	   setcolor(colb);
	   setfillstyle (CLOSE_DOT_FILL, coli);
	   fillellipse (x,y,sizex+40, sizey+15);
	   setcolor(coli);
	   setfillstyle(SOLID_FILL, coli) ;
	   fillellipse(x,y,(sizex+40)/3, (sizey+15)/3);
	   setfillstyle(SOLID_FILL, coli+2) ;
	   fillellipse (x,y, (sizex+10)/3, (sizey+5)/3) ;
	   setcolor (coli+5) ;
	   outtextxy (x-40, y-10, "DRAGAN" ) ;
	   line (x+50, y+25, x+50, y+90) ;
	   line (x+45, y+26, x+45, y+90) ;
	   line (x-55, y+25, x-55, y+90) ;
	   line (x-60, y+23, x-60, y+90) ;
	   circle (x-100, y, 12) ;
	   circle (x+100, y, 12) ;
	   circle (x-100, y, 10) ;
	   circle (x+100, y, 10) ;
	   circle (x-100, y, 8) ;
	   circle (x+100, y, 8) ;
	   circle (x-100, y, 6) ;
	   circle (x+100, y, 6) ;
	   circle (x,y-25, 16) ;
	   circle (x,y-25, 13) ;
	   circle (x,y-25, 10) ;
	   circle (x,y-25, 7) ;
	   circle (x,y-25, 4) ;
	   circle (x,y-25, 1) ;
	}
	   //  Draw SIMPLE UFO
	else
	{
	  setcolor (colb);
	  setfillstyle (CLOSE_DOT_FILL, coli) ;
	  fillellipse (x,y, sizex, sizey) ;
	  setcolor (coli) ;
	  setfillstyle (SOLID_FILL, coli) ;
	  fillellipse (x,y, sizex/3, sizey/3) ;
	  setcolor (15) ;
	  arc (x, y, 0, 180, sizex/3) ;
	}
	int dest=gamelength*7-miss;
	    //        Refresh screen variable 7s and lines
	setcolor(15);
	settextstyle (11, HORIZ_DIR, 1) ;
	showint (600, 59, hit-1, 0) ; //  Hits blank
	showint (600, 59, hit, 15) ;  // Hits show
	showint (600, 68, miss-1, 0) ;  // Misses blank
	showint (600, 77, miss, 15) ;  // Misses show
	showint (600, 77, int ((tim-4) /100) , 0) ; // Survival Time blank
	showint (600, 77, int (tim/100), 15) ;  //  Survival Time Show
	stime=int (tim/100)+bonus ; //  Store survival time for score table
	showint (600, 86, dest+1, 0) ;  // Destuction blank
	showint (600, 86, dest, 15) ; // Destruction show
	setlinestyle (SOLID_LINE, 1  , 3) ;
	rectangle (0, 0, 639, 479 ) ;   //  Border
	setlinestyle(SOLID_LINE, 1 , 1) ;

	//  Show scrolling  name
	setcolor (0) ;

	//settextstyle (npos, 96, scroll) ;
	outtextxy(npos,96,scroll);
	setcolor (10) ;
	npos=npos+2 ;
	if (npos>=640)
	   npos=-380 ;
	outtextxy (npos, 96, scroll) ;
	   //  Bullet animation
	if (shot==1)
	    pos -= gunspeed ;
	if (pos<=135) //  Hide Bullet After screen top is reached
	{
	    pos = 423 ;
	    shot = 0 ;
	    col =12 ;
	}
	setfillstyle (SOLID_FILL, col ) ;
	setcolor (col) ;
	fillellipse (gunx, pos, 2, 2) ;
	delay (abs (speed+vspeed)) ;  //  Refresh delay
	//  Game  Contols
	if (kbhit( ) )  // ketboard hit
	{
	   ch=getch ( ) ;
	   if  (ch==char (27)) //   Escape key
		goto end ;
	   if (( ch== 's'  || ch=='S')   && snd==1)     //  Sound Off
	   {
	       snd=0 ;
	       goto   skip ;
	   }
	   if  ((ch=='s'  ||  ch=='S')  && snd==0)   //       Sound On
	      snd-1 ;
	   skip :
	   if (ch=='p'  ||    ch=='P')  // Pause On / Off
	   {
	      do
	      {
		pause = getch( ) ;
		if (pause== 0x1b)
		  goto  end ;
	      } while (pause!='p' &&  pause !='P') ;
	      pause = 'a' ;
	   }
	   if (ch== '/' )   // VSpeed  - Increase
	   {
	      if (vspeed>=-10)
		  vspeed = vspeed-4 ;
	   }
	   if (ch=='*')  //  VSpeed  - Decrease
	   {
	      if (vspeed<=100)
	      vspeed =vspeed+4 ;
	   }
	   if (ch=='{')   //mmchange ship direction
	   {
	      if (dir==-1)
	      {
		 dir=1 ;
		 start =-50 ;
		 stop =700 ;
	      }
	      else
	      if (dir==1)
	      {
		 dir = -1;
		 start = 690 ;
		 stop = 60 ;
	      }
	   }
	   if   (ch=='d' ||  ch=='D') //  Restore Game  Defaults
	   {
	      snd = 1 ;
	      vspeed = 0 ;
	      varyspeed =1 ;
	      gunspeed =10 ;
	      speedgun =0 ;
	   }
	   if  (ch=='+' )  //  speed of shot - Increase
	   {
	      if (speedgun<=25)
		  speedgun++;
	      gunspeed=10+speedgun ;
	   }
	   if (ch=='-')  //  speed of shot - Decrease
	   {
	      if (speedgun>= -5)
		 speedgun-- ;
	      gunspeed=10+speedgun ;
	   }
	   if   (ch==char(75))  // Left Arrow
	   {
	      setcolor (0) ;
	      setlinestyle (SOLID_LINE, 1,   3) ;
	      line (gunx, 477, gunx, guny) ;
	      setfillstyle  (SOLID_FILL, 0) ;
	      fillellipse (gunx, pos, 2, 2) ;
	      if  (pos==423)
	      {
		if (gunx>50)
		   gunx =gunx-90 ;
		if ((casemiss==1  ||  casemiss==2 ) && ( gunx<=320-270 ))
		   gunx =320 - 180 ;
		if ((casemiss ==3  ||  casemiss == 4)  && gunx<=320 - 180)
		   gunx =320 - 90 ;
		if ((casemiss == 5  || casemiss == 6)  && gunx<= 320 - 90)
		   gunx = 320 ;
	      }
	      setcolor (9) ;
	      setlinestyle (SOLID_LINE, 1  , 3) ;
	      line (gunx, 477, gunx, guny) ;
	      setcolor (12) ;
	      setfillstyle (SOLID_FILL, 12) ;
	      setlinestyle (SOLID_LINE, 1  , 1) ;
	      fillellipse (gunx, pos , 2, 2) ;
	   }
	   if  (ch ==char (77))   // Right Arrow
	   {
	      setcolor  (0) ;
	      setlinestyle (SOLID_LINE, 1,  3) ;
	      line (gunx, 480, gunx, guny) ;
	      setfillstyle (SOLID_FILL, 0) ;
	      fillellipse (gunx,npos, 2, 2) ;
	      if (pos == 423 )
	      {
		if (gunx<320+270 )
		       gunx = gunx+90 ;
		if ((casemiss == 2 || casemiss == 3)  && gunx>= 320 + 270)
		       gunx = 320+180 ;
		if ((casemiss == 4 || casemiss == 5)  && gunx>= 320 +180)
		       gunx = 320 + 90 ;
		if ((casemiss == 6 || casemiss == 7)  && gunx>= 320 + 90)
		       gunx = 320 ;
	      }
	      setcolor (13) ;
	      setlinestyle (SOLID_LINE, 1,   3) ;
	      line (gunx, 477, gunx, guny);
	      setcolor (9) ;
	      setfillstyle (SOLID_FILL, 12) ;
	      setlinestyle(SOLID_LINE, 1,  1) ;
	      fillellipse (gunx, pos, 2,10);
	   }
	   if(ch ==' ')          //  Space Bar - Shoot
	   {
	     if(snd == 1 &&  pos == 423)
	     {
		sound(250) ;
		delay(50) ;
		nosound() ;
	     }
	     if ( snd == 1 && pos != 423)
	     {
		sound(100) ;
		delay(50) ;
		nosound() ;
	     }
	     col = 12 ;
	     shot = 1 ;
	   }
	} // END OF KBHIT

	  //  If UFO is hit
	if (( hit == 4)  || (hit == 8)  ||  (hit == 12) || (hit == 21) || (hit == 25) ||
	     (hit == 29)  ||(hit == 35) ||  (hit == 39) || (hit == 44) )
	{
	  setlinestyle (SOLID_LINE, 1,   1) ;
	  if (x>gunx-20-acc && x<gunx+20+acc  && y>pos - acc+10 && y<pos+acc+10)
	  {
	    hit ++ ;
	    setfillstyle (EMPTY_FILL, 0 ) ;
	    setcolor (0) ;
	    fillellipse (gunx, pos, 2, 2) ;
	    hitcolor = 16 ;
	    for (i = 120 ; i<=200 ; i = 1+10)
	    {
	      hitcolor--;
	      if ( i>=200)
		 hitcolor = 0 ;
	      setcolor (hitcolor) ;
	      setfillstyle (SOLID_FILL, hitcolor ) ;
	      fillellipse (x, y, sizex+30, sizey+10)   ;
	      circle(x, y-25, 12) ;
	      circle(x, y-25, 10) ;
	      circle(x, y-25, 8) ;
	      circle(x, y-25, 6) ;
	      circle(x, y-25, 4) ;
	      circle(x, y-25, 2) ;
	      arc(x, y,   0,   180,  sizex/3) ;
	      if (snd == 1)
	      {
		sound ( i ) ;
		delay (100) ;
	      }
	    }
	    nosound ( ) ;
	    fillellipse (x, y, sizex+30, sizey+10) ;
	    arc ( x,   y,  0,  180, sizex/3 ) ;
	    for ( int rg = 200 ; rg>= 0;  rg-= 1 )
	    {
	      setcolor (rg) ;
	      outtextxy (x - 50, y, "BONUS") ;
	      outtextxy (x - 30, y + 20,  "50") ;
	    }
	    bonus = bonus + 50 ;
	    setcolor (15) ;
	    settextstyle (11, HORIZ_DIR,1 ) ;
	    showint ( 320, 50, bonus - 50, 0 ) ;    //  Hits blank
	    showint (320, 50, bonus, 15) ;   // Hits show
	    pos = 423 ;
	    shot = 0 ;
	    col = 12 ;
	    goto animate ;
	  }
	}
	else
	if  (( hit == 15 )  ||  ( hit == 16 ) ||  ( hit == 17 ) ||  ( hit == 30 ) ||
	     (hit == 31)  ||  ( hit == 32 ) ||  ( hit == 48 ) ||  ( hit == 49 ) ||
	     ( hit == 50 ))
	{
	  setlinestyle (SOLID_LINE , 1 , 1 ) ;
	  if ( (x>gunx - 20 - acc + 20) && ( x<gunx + 20 + acc - 20 ) &&
	       (y>pos - acc + 10) &&  (y<pos + acc+ 10) )

	  {
	    hit ++ ;
	    setfillstyle (EMPTY_FILL, 0 ) ;
	    setcolor ( 0 ) ;
	    fillellipse (gunx, pos , 2 , 2 ) ;
	    hitcolor = 16 ;
	    for ( i=120 ; i<=200 ; i = i+10 )
	    {
	       hitcolor-- ;
	       if (i>= 200 )
		  hitcolor = 0 ;
	       setcolor (hitcolor ) ;
	       setfillstyle (SOLID_FILL, hitcolor ) ;
	       fillellipse ( x, y, sizex+40, sizey+15 ) ;
	       circle ( x, y - 25, 16 )  ;
	       circle ( x, y - 25, 13 )  ;
	       circle ( x, y - 25, 10 )  ;
	       circle ( x, y - 25, 7 ) ;
	       circle ( x, y - 25, 4 ) ;
	       circle ( x, y - 25, 1 ) ;
	       arc (x, y,   0,  180, sizex/3 ) ;
	       line ( x+50 , y+25, x+50, y+90 ) ;
	       line ( x+45 , y+26, x+45, y+90 ) ;
	       line ( x-55 , y+25, x-55, y+90 ) ;
	       line ( x-60 , y+23, x-60, y+90 ) ;
	       circle ( x-100 , y , 12 ) ;
	       circle ( x+100 , y , 12 ) ;
	       circle ( x-100 , y , 10 ) ;
	       circle ( x+100 , y , 10 ) ;
	       circle ( x-100 , y , 8 ) ;
	       circle ( x+100 , y , 8 ) ;
	       circle ( x-100 , y , 6 ) ;
	       circle ( x+100 , y , 6 ) ;
	       if  (snd == 1)
	       {
		 sound ( i ) ;
		 delay ( 100 ) ;
	       }
	    }
	    nosound ( ) ;
	    fillellipse (x, y, sizex+30 , sizey+10 ) ;
	    arc (x,  y,  0,  180,  sizex/3 ) ;


	  if( (hit == 16 )||(hit == 17 )||(hit == 31 )||(hit == 32)||
	      (hit == 49)||(hit == 50) )
	  {
	    for (int   rg = 200 ; rg>= 0 ;  rg-- )
	    {
	       setcolor ( rg) ;
	       outtextxy ( x - 60 , y, "HA - HA - HA" ) ;
	       outtextxy ( x - 60 , y + 20 , "TRY AGAIN" ) ;
	    }
	  }
	  else
	  if ( (hit==18 )||(hit == 33)||(hit == 51) )
	  {
	    for (int  rg = 200 ; rg>= 0 ; rg-- )
	    {
	      setcolor ( rg ) ;
	      if ( hit == 18 )
	      {
		outtextxy ( x - 60, y, "STAGE - 1 " ) ;
		varyspeed = varyspeed+10 ;
	      }
	      else  if (hit == 33 )
	      {
		outtextxy ( x - 60, y,  "STAGE-2 " ) ;
		varyspeed = varyspeed +10 ;
	      }
	      else  if (hit == 51 )
	      {
		outtextxy (x - 60 , y,  "STAGE - 3 " ) ;
		varyspeed = varyspeed+10 ;
	      }
	      outtextxy (x -65, y+20, "CLEAR" ) ;
	    }
	  }
	  bonus = bonus+50 ;
	  setcolor ( 15 ) ;
	  settextstyle (11, HORIZ_DIR, 1) ;
	  showint (320, 50, bonus-50, 0 ) ; //   Hits blank
	  showint (320, 50, bonus, 15 ) ;   //  Hits show
	  pos = 423 ;
	  shot = 0 ;
	  col = 12 ;
	  goto  animate ;
	}
    }

    else
    {
      setlinestyle ( SOLID_LINE ,   1, 1 ) ;
      if (x>gunx - 20 - acc  && x<gunx + 20 + acc  && y>pos - acc+10   && y<pos+acc+10 )
      {
	  hit ++ ;
	  setfillstyle (EMPTY_FILL, 0 ) ;
	  setcolor ( 0 ) ;
	  fillellipse ( gunx , pos, 2, 2 ) ;
	  hitcolor = 16 ;
	  for ( i = 120 ; i<=200 ;  i = i+10)
	  {
	      hitcolor-- ;
	      if (i>=200 )
		 hitcolor = 0 ;
	      setcolor ( hitcolor ) ;
	      setfillstyle ( SOLID_FILL, hitcolor ) ;
	      fillellipse ( x, y, sizex, sizey ) ;
	      arc ( x,   y,  0,  180,  sizex/3) ;
	      if ( snd == 1 )
		 sound ( i ) ;
	      delay ( 100 ) ;
	  }
	  nosound ( ) ;
	  fillellipse ( x, y, sizex, sizey ) ;
	  arc ( x,   y,  0, 180,  sizex/3 ) ;
	  pos = 423 ;
	  shot = 0 ;
	  col = 12 ;
	  goto animate ;
      }
    }
	       //      If UFO not hit, redraw with black
    setcolor ( 0 ) ;
    setfillstyle (EMPTY_FILL , 0 ) ;
    if((hit==4) || (hit==8) || (hit==12) || (hit==21) || (hit==25) ||
	   (hit==29) || (hit==35) || (hit==39) || (hit==44))
    {
	fillellipse (x, y, sizex+30, sizey+10) ;
	circle  (x, y-25, 12) ;
	circle  (x, y-25, 10) ;
	circle  (x, y-25, 8) ;
	circle  (x, y-25, 6) ;
	circle  (x, y-25, 4) ;
	circle  (x, y-25, 2) ;
    }
    else
    if  (    ( hit == 15 )  ||  ( hit == 16 ) || (hit == 17 ) ||  ( hit == 30 )
	    || ( hit == 31)  ||  ( hit == 32 ) ||  ( hit == 48 ) ||  ( hit == 49 )
	    ||  ( hit == 50 ))
	{
	   fillellipse ( x, y, sizex+40, sizey+15 ) ;
	   circle ( x, y - 25, 16 )  ;
	   circle ( x, y - 25, 13 )  ;
	   circle ( x, y - 25, 10 )  ;
	   circle ( x, y - 25, 7 ) ;
	   circle ( x, y - 25, 4 ) ;
	   circle ( x, y - 25, 1 ) ;
	   line ( x+50 , y+25, x+50, y+90 ) ;
	   line ( x+45 , y+26, x+45, y+90 ) ;
	   line ( x-55 , y+25, x-55, y+90 ) ;
	   line ( x-60 , y+23, x-60, y+90 );
	   circle ( x-100 ,  y , 12 ) ;
	   circle ( x+100 , y , 12 ) ;
	   circle ( x-100 ,  y , 10 ) ;
	   circle ( x+100 , y , 10 ) ;
	   circle ( x-100 ,  y , 8 ) ;
	   circle ( x+100 , y , 8 ) ;
	   circle ( x-100 ,  y , 6 ) ;
	   circle ( x+100 , y , 6 ) ;
	}
	else
	{
	   fillellipse(x ,y, sizex, sizey);
	}
	arc(x, y, 0, 180, sizex/3);
	fillellipse(gunx, pos , 2, 2);

	}
	goto animate;

	end:
		     //remove UFO from screen, if there and redraw border
	setcolor (0);
	setfillstyle (EMPTY_FILL, 0);
	fillellipse ( x, y, sizex, sizey);
	arc (x, y, 0, 180, sizex/3);
	fillellipse (gunx, pos, 2, 2);
	setcolor(15);
	setlinestyle(SOLID_LINE, 1, 3);
	rectangle(0, 0, 639, 479);
	setlinestyle(SOLID_LINE, 1, 1);
			 //show game over
	settextstyle(0, HORIZ_DIR, 8);
	setcolor(11);
	outtextxy(30, 250, "GAME OVER");
	getch();
	setcolor(0);
	outtextxy(30, 250, "GAME OVER");
	settextstyle(7, HORIZ_DIR, 3);
	outtextxy(npos, 96, scroll);
	setcolor(15);
	setlinestyle(SOLID_LINE, 1, 1);
	rectangle(0,0,639,479);
	setlinestyle(SOLID_LINE, 1, 3);
	setcolor(10);
	outtextxy(80,96,"Thank you for playing UFO shoot out");
	return (stime);
}
void makebox()
{
  setcolor(8);
  setlinestyle(SOLID_LINE, 1, 3);
  setfillstyle(SOLID_FILL, 8);
  rectangle(185, 135, 455, 421);
  floodfill(190+5, 150, 8);
  setfillstyle(SOLID_FILL, 0);
  floodfill(190+5, 150, 0);
  setcolor(12);
  rectangle(185, 135, 455, 421);
}


char highscore(int stime)
{
	  struct sur_t    // Structure for storing high scores
    {  int st;
       char sname[18];
    };

    char schar,sstring[2],ch;
    sstring[1]='\0';
    int si,sno,spos,scount=-1;
    sur_t scurr,sdat={30,"B.DEEPAK"};
    scurr.st=stime;
    fstream score;
    score.open("survival.scr",ios::binary|ios::in);
    if(!score)
    {
	score.close();
	score.open("survival.scr",ios::binary|ios::out);
	for(si=0;si<10;si++)
	   score.write((char*)&sdat,sizeof(sdat));
	score.close();
    }
    score.close();

    score.open("survival.scr",ios::binary|ios::in);
    for(si=0;si<10;si++)
    {
	score.read((char*)&sdat,sizeof(sdat));
	if(scurr.st>=sdat.st)
	{
	   spos=si;
	   break;
	}
    }
    score.close();
    if(si>9)
	goto cont;
    makebox();
    settextstyle(5,HORIZ_DIR,5);
    setcolor(10);
    outtextxy(190,119,"congratulations");
    settextstyle(7,HORIZ_DIR,3);
    setcolor(13);
    outtextxy(210,185,"You have become");
    outtextxy(200,215,"one of the top ten ");
    settextstyle(4,HORIZ_DIR,5);
    outtextxy(235,230,"survivors");
    settextstyle(7,HORIZ_DIR,3);
    setcolor(13);
    outtextxy(189,275,"with a survival time");
    outtextxy(192,301,"of");
    showint(227,301,scurr.st,13);
    outtextxy(280,301,"alien seconds");
    setcolor(10);
    settextstyle(2,HORIZ_DIR,7);
    outtextxy(192,355,"please enter your name");
    settextstyle(2,HORIZ_DIR,8);

    setcolor(14);
    sno=192;
    getletter:
    schar=getch();
    if(schar==char(27))
       goto cont;
    if(schar==char(13))
    {
      scurr.sname[scount+1]='\0';
      goto putscr;
    }
    backsp:
    if(schar==char(8)&&scount>=0) // check for bs
    {
      scount=scount-1;
      setcolor(0);
      sstring[0]=scurr.sname[scount+1];
      outtextxy(sno,379,sstring);
      setcolor(14);
      sno=sno-14;
      goto getletter;
    }
    sstring[0]=schar;

    if(scount>15)
    {
      while(schar!=char(8)&&schar!=char(13)&&schar!=(27))
      {
	schar=getch();
	if(schar==char(13))
	{
	  scurr.sname[scount+1]='\0';
	  goto putscr;
	}
	if(schar==char(8)&&scount>=0)
	  goto cont;
      }
    }
    if (int(schar)>=32 && int(schar)<=127)
	{
	    sno=sno+14;
	    scount++;
	    scurr.sname[scount]=schar;
	    outtextxy(sno,379,sstring);
	}
    goto getletter;

    putscr:

    score.open("survival.scr",ios::binary|ios::in|ios::out);

    for(si=8;si>=spos;si--)
    {
	score.seekg(si*sizeof(sdat),ios::beg);
	score.read((char*)&sdat,sizeof(sdat));
	score.seekp((si+1)*sizeof(sdat),ios::beg);
	score.write((char*)&sdat,sizeof(sdat));
    }
    score.seekp(spos*sizeof(scurr),ios::beg);
    score.write((char*)&scurr,sizeof(scurr));
    score.close();
    cont:
    makebox();
    line(190,208,450,208);
    line(190,235,450,235);
    line(265,208,265,421);
    settextstyle(4,HORIZ_DIR,5);
    setcolor(14);
    outtextxy(200,126,"The top ten");
    outtextxy(243,160,"survivors");
    settextstyle(6,HORIZ_DIR,3);
    setcolor(9);
    outtextxy(194,204,"T I M E");
    outtextxy(315,204,"N A M E");
    score.open("survival.scr",ios::binary|ios::in);
    settextstyle(2,HORIZ_DIR,6);
    setcolor(10);
    sno=219;
    for(si=0;si<10;si++)
    {

	score.read((char*)&sdat,sizeof(sdat));
	sno+=18;
	showint(210,sno,sdat.st,10);
	outtextxy(280,sno,sdat.sname);
    }
    score.close();
    settextstyle(4,HORIZ_DIR,5);
    setcolor(9);
    outtextxy(54,190,"YOU");
    outtextxy(500,190,"GET");
    showint(54,290,spos+1,13);
    outtextxy(120,290,"the");
    outtextxy(460,290,"POSITION");
    getch();
    makebox();
    settextstyle(4,HORIZ_DIR,6);
    setcolor(10);
    outtextxy(232,126,"Do you");
    outtextxy(225,180,"Wish to");
    outtextxy(195,230,"Play again");
    outtextxy(310,285,"?");
    setcolor(9);
    outtextxy(200,340,"(Y)es/(N)o");
    while(ch!='y' &&  ch!='Y' && ch!='n'  && ch!='N' && ch!=char(27))
    {
	ch=getch();
	if(ch=='y' || ch=='Y')
	  ch='y';
	else
	  ch='n';
    }
    return(ch);
}

void credits()
{
    int ypos,i;

    char cred[25][35]=
    {"I would like to thank our" ,
     "computer teacher for his" ,
     "support and ideas in" ,
     "completing the project."

	 };
    makebox();
    settextstyle(2,HORIZ_DIR,5);
    for(i=0;i<=22;i++)
    {
      for(ypos=400;ypos>=136+i*2;ypos=ypos-4)
      {
	setcolor(10);
	outtextxy(195,ypos,cred[i]);
	if(strlen(cred[i])!=0)
	   delay(20);
	if(ypos<=136+i*12)
	  continue;
	setcolor(0);
	outtextxy(195,ypos,cred[i]);
      }
    }
getch();
}











