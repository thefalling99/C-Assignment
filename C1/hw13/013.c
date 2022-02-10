/*013. 停車費計算
假設某個停車場的費率是停車2小時以內，每半小時30元，未滿半小時部分以半小時計費。 超過2小時，但未滿4小時，每半小時40元，未滿半小時以半小時計費。 超過4小時以上的部份，每半小時60元，未滿半小時部分以半小時計費。
請撰寫程式計算輸入數筆資料，共需繳交的停車費。 本程式不考慮隔夜情況。
輸入說明： 輸入多組時間，每組分別為開始與離開時間，24小時制。 輸入 -1 停止輸入，若輸入格式錯誤，則顯示錯誤訊息。
輸出說明： 輸出總停車費。
input:
10:23 15:20 25:25 10:70 -1
output:
340 error
第 11 頁
c10401.txt
input:
10:23 13:20 21:25 25:70 -1
output:
200 error*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int h,m,h1,m1,p=0,cost,e=0;
	int t[10];
	while(1)
	{
		printf("输入开始停车时间\n");
		scanf("%d:",&h);
		if(h==-1)
			break;
        if(h<0||h>24)
            e=1;
		scanf("%d",&m);
		if(m<0||m>60)
            e=1;
		printf("输入结束停车时间\n");
		scanf("%d:",&h1);
		if(h1<0||h1>24)
            e=1;
		scanf("%d",&m1);
		if(m1<0||m1>60)
            e=1;
        if(e==1)
        {
            t[p++]=-1;
            e=0;
        }
        else
            t[p++]=(h1*60+m1)-(h*60+m);
	}
	for(int i=0;i<p;i++)
	{
	    if(t[i]==-1)
        {
            printf("error");
        }
		if(t[i]<120)
		{
			cost=(t[i]/30+1)*30;
		}
		else if(t[i]>=120&&t[i]<=240)
		{
			cost=120+((t[i]-120)/30+1)*40;
		}
		else
		{
			cost=280+((t[i]-240)/30+1)*60;
		}
		if(t[i]==-1)
            printf("\n");
        else
            printf("%d\n",cost);
	}
	system("pause");
	return 0;
}
