/*009 判斷何種三角形
當三個邊長能夠構成三角形時，再判斷該三角形為鈍角、銳角或是直角三角形，其判別方法 如下： 1. 直角三角形：其中有兩個邊的平方和等於第三邊的平方。 2. 鈍角三角形：其中有兩個邊的平方和小於第三邊的平方。 3. 銳角三角形：任兩邊的平方和大於第三邊的平方。 輸入三個整數
輸出：顯示直角三角形(Right Triangle)、鈍角三角形(Obtuse Triangle)、 銳角三角形(Acute Triangle)或無法構成三角形(Not Triangle)。
此題必須寫一個運算的function
int compute(int a, int b, int c); a, b, b 為三角形三個邊 回傳值 0:Not Triangle 1:Right Triangle 2:Obtuse Triangle 3:Acute Triangle
測試資料：
input 5 12 13
output Right Triangle
input 3 4 5
output Right Triangle
input 1 2 3
output Not Triangle*/
#include<stdio.h>
#include<stdlib.h>
int compute(int a,int b,int c)
{
	if(!(a+b>c&&a+c>b&&b+c>a))
		return 0;
	if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a)
		return 1;
	if(a*a+b*b<c*c || a*a+c*c<b*b || b*b+c*c<a*a)
		return 2;
	if(a*a+b*b>c*c && a*a+c*c>b*b && b*b+c*c>a*a)
		return 3;
}
int main()
{
	int a,b,c,t;
	printf("Input a,b,c\n");
	scanf("%d %d %d",&a,&b,&c);
	t=compute(a,b,c);
	if(t==0)
		printf("Not Triangle\n");
	if(t==1)
		printf("Right Triangle\n");
	if(t==2)
		printf("Obtuse Triangle\n");
	if(t==3)
		printf("Acute Triangle\n");
    system("pause");
}
