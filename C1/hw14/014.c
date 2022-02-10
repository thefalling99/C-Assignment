/*014. 請使用一個 while loop 和 function call
給予一個十進位整數，請撰寫一程式可以將此十進位整數轉換為指定的進制的整數。
輸入說明: 輸入分為兩部份，包括指定的進制數 (2 ~ 16) 與十進位整數(0 ~ 1000000000)
16 進位數字為 0 1 2 3 4 5 6 7 8 9 A B C D E F
輸出說明: 經轉換後的新進位制的整數( y )
input:
16 1234
output: 4D2
Input:
8 56456456
Output:
327272410
----------------------
Input:
11 17489465
Output:
9966104
第 12 頁
c10401.txt
----------------------Input:
4 17489
Output:
10101101
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int dec,base,i=0;
	char ch[20];
	printf("輸入十進位數\n");
	scanf("%d",&dec);
	printf("轉換為多少進制\n");
	scanf("%d",&base);
	while(dec!=0)
	{
		ch[i]=dec%base;
		if(ch[i]>=10)
			ch[i]=ch[i]-10+'A';
		if(ch[i]<10)
			ch[i]+=48;
		dec/=base;
		i++;
	}
	i--;
	while(i>=0)
	{
		printf("%c",ch[i]);
		i--;
	}
	printf("\n");
	system("pause");
	return 0;
}
