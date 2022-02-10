/*010. 請使用一個 while loop 和 function call
給定一些線段，求這些線段所覆蓋的長度，注意，重疊的部分只能算一次。
輸入說明 ：
第一列有一個正整數 n: 代表共有 n 組測試案例。
接下來每一組測試案例的第一列是一個整數 m 表示此測試案例有m個線段，
接著的m列每一列是一個線段的兩端點，
每一個端點是一個整數介於0~60000之間， 端點之間以一個空格區隔，線段個數不超過 5000。
起始端點小的先輸入。 此題不使用陣列。
輸出說明 ：
針對每一組測試案例，輸出其覆蓋的長度，每組測試案例輸出一列。
Input:
2     (共有2組次是案例) 2     (此組測試案例有2個線段) 0 1 2 3 3      (此組測試案例有3個線段) 0 20 10 30 40 50
Output: 2 40
Input:
3 3 10 111 150 3450 160 180 2 100 180 150 3333 1 150 150
第 8 頁
c10401.txt
Output:
3401 3233 0
-------------Input: 1 2 150 320 160 190
Output: 170
*/
#include<stdio.h>
#include<stdlib.h>
int fhead=0,fnail=0,sum=0;
void f(int head,int nail)
{
	if(head<fnail)
		head=fnail;
	fnail=nail;
	if((nail-head)<0)
        return;
	sum+=(nail-head);
}
int main()
{
	int n,m,head,nail;
	printf("Input n\n");
	scanf("%d",&n);
	while(n)
	{
		printf("Input m\n");
		scanf("%d",&m);
		while(m)
		{
			printf("Input head and nail\n");
			scanf("%d %d",&head,&nail);
			f(head,nail);
			m--;
		}
		printf("\n\nanswer is:%d\n\n",sum);
		fnail=0;
		sum=0;
		n--;
	}
	system("pause");
	return 0;
}
