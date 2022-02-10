/*012. 請使用 while loop, 不可使用 array, for loop
第一個輸入為選擇二種圖形: 1 三角形方尖方面向右邊 2 三角形方尖方面向左邊
第二個輸入意義為畫幾行
input 1 (第一種圖形，三角形尖方面向右邊) 5 (共 5 行)
註: 符號為 * 和 .
第 10 頁
c10401.txt
output *.... **... ***.. ****. *****
---------------------------input 2 (第二種圖形，三角形尖方面向左邊) 3 (共 5 行)
output ..* .** ***
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int choose,line,line2,i=0,j,temp;
	printf("选择三角形：1、方尖方面向右 2、方尖方面向左\n");
	scanf("%d",&choose);
	printf("畫多少行？\n");
	scanf("%d",&line);
	temp=line;
	if(choose==1)
	{
		while(i!=line)
		{
			i++;
			line2=temp;
			j=0;
			while(line2)
			{
				if(j<i)
					printf("*");
				else
					printf(".");
				line2--;
				j++;
			}
			printf("\n");
		}
	}
	else if(choose==2)
	{
		while(line)
		{
			line2=temp;
			i=line2-(line2-(line-1));
			j=0;
			while(line2)
			{
				if(j<i)
					printf(".");
				else
					printf("*");
				j++;
				line2--;
			}
			line--;
			printf("\n");
		}
	}
}
