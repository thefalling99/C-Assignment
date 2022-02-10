/*028. 計算 N 邊形面積 (請參考課本 chapter 7, 習題二)
n 個點連成 n 邊形，n<=20， 點的座標為 (x_(0), y_(0)), (x_(1), y_(1)),....,(x_(n), y_(n))。
Area = fabs(sum)/2
sum =   (x_(1)+x_(0))*(y_(1)-y_(0))+ ...       + (x_(i+1)+x_(i))*(y_(i+1)-y_(i))+ ...      + (x_(n)+x_(n-1))*(y_(n)-y_(n-1))
-------------------輸入說明: 每兩個數字為一個座標，最後以-999結束， 數字中間以逗號隔開。
第 28 頁
c10401.txt
輸出說明: 計算多邊形面積求到小數第一位。
---------------------------------input: 4,0,4,7.5,7,7.5,7,3,9,0,7,0,-999
--------------------------------output: 25.5*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	float x[20],y[20];
	int i=0,sum=0;
	float area=0;
	printf("輸入n個頂點座標(n<=20)\n");
	while(1)
	{
		scanf("%f,",&x[i]);
		if(x[i]==-999)
			break;
		scanf("%f,",&y[i]);
		i++;
	}
	for(int j=0;j<(i-1);j++)
	{
		sum+=(x[j+1]+x[j])*(y[j+1]-y[j]);
	}
	area=fabs(sum)/2;
	printf("%.1f\n",area);
    system("pause");
    return 0;
}

