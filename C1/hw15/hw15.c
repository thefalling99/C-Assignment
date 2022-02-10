#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define RADIUS1 30
#define RADIUS2 60
#define STEP 10
#define DELAY_TIME 50
int main()
{
    srand(time(NULL));
    initwindow(800,600);
    int stepx1=10,stepy1=-10;
    int stepx2=10,stepy2=10;
    int x1=RADIUS1,y1=600-RADIUS1;
    int x2=RADIUS2,y2=RADIUS2;
    circle(x2,y2,RADIUS2);
    circle(x1,y1,RADIUS1);
    int t=0;
    int maxcolor=getmaxcolor();
    int c=0;
    while(1)
    {
        //移動一百步換?色
        if(t>100)
        {
            setcolor((rand()%13)+1);
            t=0;
        }
        else
        {
            t++;
        }
        //覆蓋
        cleardevice();
//        setcolor(BLACK);
//        circle(x2,y2,RADIUS2);
//        circle(x1,y1,RADIUS1);
//        setcolor(WHITE);
        //移動
        x1+=stepx1;
        y1+=stepy1;
        x2+=stepx2;
        y2+=stepy2;
        //碰撞偵測
        if(x1<0||x1>800)
        {
            stepx1=-stepx1;
            x1+=stepx1;
        }
        if(y1<0||y1>600)
        {
            stepy1=-stepy1;
            y1+=stepy1;
        }
        if(x2<0||x2>800)
        {
            stepx2=-stepx2;
            x2+=stepx2;
        }
        if(y2<0||y2>600)
        {
            stepy2=-stepy2;
            y2+=stepy2;
        }
        circle(x2,y2,RADIUS2);
        circle(x1,y1,RADIUS1);
        delay(50);
    }
    getch();
    closegraph( );
}
