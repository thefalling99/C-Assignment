/*007. 最佳資費選擇
輸入每月網內、網外、市話、通話時間(秒)及網內、網外簡訊則數，求最佳資費。
費率如下表:
資費類型        183型     383型     983型  月租費          183元     383元     983元  優惠內容        月 租 費 可 抵 等 額 通 信 費 語音費率 網內   0.08      0.07      0.06 (元/秒)  網外   0.139     0.130     0.108 市話            0.135     0.121     0.101 (元/秒) 簡訊費率 網內   1.128     1.128     1.128 (元/則)  網外   1.483     1.483     1.483
--------------------------------輸入說明
第 4 頁
c10401.txt
--------------網內語音(秒)，整數 網外語音(秒)，整數 市話    (秒)，整數 網內簡訊數，整數 網內簡訊數，整數
--------------------------------輸入說明 --------------------------------最佳資費類型，(183, 383, 983) 最佳資費，到小數點第三位
--------------------------------測試資料：(Test Case)
input 120 150 20 10 5
output 183 183.000
input 3000 4000 200 5 5
output 383 767.255*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	//设A,B,C分别为183、383、983型套餐的总花费
	float A=0,B=0,C=0;
	//分别为网内语音、网外语音、市话、网内简讯数、网外简讯数
	float iCall,oCall,cCall,iM,oM;
	float iCall2,oCall2,cCall2,iM2,oM2;
	int choose;
	float cost;
	printf("請輸入網內語音、網外語音、市話、網內簡訊數、網外簡訊數\n");
	scanf("%f %f %f %f %f",&iCall,&oCall,&cCall,&iM,&oM);
	iCall2=iCall*0.08;
	oCall2=oCall*0.139;
	cCall2=cCall*0.135;
	iM2=iM*1.128;
	oM2=oM*1.483;
	A=iCall2+oCall2+cCall2+iM2+oM2;
	if(A<183)
		A=183;

	iCall2=iCall*0.07;
	oCall2=oCall*0.130;
	cCall2=cCall*0.121;
	iM2=iM*1.128;
	oM2=oM*1.483;
	B=iCall2+oCall2+cCall2+iM2+oM2;
	if(B<383)
		B=383;

	iCall2=iCall*0.06;
	oCall2=oCall*0.108;
	cCall2=cCall*0.101;
	iM2=iM*1.128;
	oM2=oM*1.483;
	C=iCall2+oCall2+cCall2+iM2+oM2;
	if(C<983)
		C=983;

	if(A<383)
	{
		choose=183;
		cost=A;
	}
	if(B>383&&B<983)
	{
		choose=383;
		cost=B;
	}
	if(C>983)
	{
		choose=983;
		cost=C;
	}
	printf("選%d型\n花費%2.f\n",choose,cost);
    system("pause");
}
