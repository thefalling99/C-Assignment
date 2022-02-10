/*計算矩形覆蓋的面積
輸入兩個矩形的對角兩點x、y座標 計算兩個矩形重疊的面積為多少 例如輸入 1 5 9 7 2 5 10 11 表示 一個矩形的有其中對角兩點為(1,5)與(9,7) 另一個矩形的有其中對角兩點為(2,5)與(10,11)
而重疊面積為(2,5)與(9,7)構成的矩形 所以面積為(9-2)*7(-5)=14 input: 1 5 9 7 2 5 10 11
output: 14*/
#include<stdio.h>
#include<stdlib.h>
int min(int a,int b)
{
	return a<b?a:b;
} 
int max(int a,int b)
{
	return a>b?a:b;
} 
int square(int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4)
{
	if((min(x2,x4)-max(x1,x3)>0)&&(min(y2,y4)-max(y1,y3)>0))
	{
		return ((min(x2,x4)-max(x1,x3))*(min(y2,y4)-max(y1,y3)));
	}
	else
		return 0;
}
int main()
{
	int x1,x2,x3,x4,y1,y2,y3,y4,r;
	printf("Input 第一个矩形第一个顶点\n");
	scanf("%d %d",&x1,&y1);
	printf("Input 第一个矩形第二个顶点\n");
	scanf("%d %d",&x2,&y2);
	printf("Input 第二个矩形第一个顶点\n");
	scanf("%d %d",&x3,&y3);
	printf("Input 第二个矩形第二个顶点\n");
	scanf("%d %d",&x4,&y4);
	r=square(x1,x2,x3,x4,y1,y2,y3,y4);
	if(r)
		printf("%d\n",r);
	else
		printf("不重叠!\n"); 
	system("pause");
	return 0;
}
