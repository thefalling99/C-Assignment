/*011.判斷何種三角形
當三個邊長能夠構成三角形時，再判斷該三角形為正三角形(Regular Triangle)、 等腰三角形(Isoscceles Triangle )、鈍角、銳角或是直角三角形， 其判別方法如下：
依序判斷是否為正三角形、直角三角形、等腰三角形。 若都沒有符合，再判斷是否為銳角或鈍角。
1. 直角三角形：短邊的平方和等於最長邊的平方。 2. 鈍角三角形：短邊的平方和小於最長邊的平方。其中有一個角大於90度。 3. 銳角三角形：短邊的平方和大於最長邊的平方。所有內角均為銳角，小於90度。
輸入說明
輸入數個三角形三個邊，直到 -1 停止輸入。 三個邊為三個整數。
scanf 用法請參考 http://www.cplusplus.com/reference/cstdio/scanf/
輸出說明
印出 直角三角形(Right Triangle)、 正三角形(Regular Triangle)、 等腰三角形(Isoscceles Triangle)、 鈍角三角形(Obtuse Triangle)、 銳角三角形(Acute Triangle)、 或無法構成三角形(Not a Triangle)。
input
第 9 頁
c10401.txt
4 12 13 5 12 13 1 2 3 3 4 5 2 2 2 2 2 3 -1
output
Obtuse Triangle Right Triangle Not a Triangle Right Triangle Regular Triangle Isoscceles Triangle
input:
80 90 160 5 5 5 7 7 6 30 50 40 1 8 7 30 31 29 -1
Output:
Obtuse Triangle Regular Triangle Isoscceles Triangle Right Triangle Not a Triangle Acute Triangle*/
#include<stdio.h>
#include<stdlib.h>
void f(int a,int b,int c)
{
	if(!(a+b>c&&a+c>b&&b+c>a))
    {
        printf("Not a Triangl\n");
        return;
    }
	if(a==b&&a==c&&b==c)
    {
        printf("Regular Triangl\n");
        return;
    }
	if(a==b||a==c||b==c)
    {
        printf("Isoscceles Triangl\n");
        return;
    }
	if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a)
    {
        printf("Right Triangl\n");
        return;
    }
	if(a*a+b*b<c*c || a*a+c*c<b*b || b*b+c*c<a*a)
    {
        printf("Obtuse Triangle\n");
        return;
    }
	if(a*a+b*b>c*c && a*a+c*c>b*b && b*b+c*c>a*a)
    {
        printf("Acute Triangl\n");
        return;
    }
}
int main()
{
	int a[10],b[10],c[10],t=0,n=1,in=0;
	while(in!=-1)
	{
		printf("Input number\n");
		scanf("%d",&in);
		if(n%3==1)
			a[t]=in;
		else if(n%3==2)
			b[t]=in;
		else if(n%3==0)
		{
			c[t]=in;
			t++;
		}
		n++;
	}
	for(int i=0;i<t;i++)
	{
		f(a[i],b[i],c[i]);
	}
	system("pause");
	return 0;
}
