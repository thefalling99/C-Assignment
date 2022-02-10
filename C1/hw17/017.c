/*017.回文結構數字
輸入兩整數，找出兩整數區間內所有具有回文結構的數字。 例如，輸入 80 100 ，則輸出為 88 99 。 例如，100 200 ，則輸出為 101 111 121 131 141 151 161 171 181 191 。若沒有則輸出 0 。
輸入說明： 輸入兩整數。
輸出說明： 輸出區間內所有具有回文結構的數字 。
input: 10 70
output: 11 22 33 44 55 66 ----------------------------------------input: 1300 2000
第 14 頁
c10401.txt
output: 1331 1441 1551 1661 1771 1881 1991 ----------------------------------------input: 17000 18000
output: 17071 17171 17271 17371 17471 17571 17671 17771 17871 17971
*/
#include<stdio.h>
#include<stdlib.h>
int ispal(int n)
{
	int t=n;
	int m=0;
	while(t!=0)
	{
		m=m*10+t%10;
		t/=10;
	}
	return m==n;
} 
int main()
{
	int start,end;
	printf("Input two number\n");
	scanf("%d %d",&start,&end);
	for(int i=start;i<=end;i++)
	{
		if(ispal(i))
		{
			printf("%d\n",i);
		}
	} 
	system("pause");
	return 0;
} 
