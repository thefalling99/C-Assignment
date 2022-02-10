/*026.整數的交集聯集
請設計程式，利用兩個一維整數陣列儲存兩個正整數集合 A, B ， 兩個集合 A, B 的陣列大小為 20，正整數 1~100； 程式功能為： (1) 新增集合元素：輸入一集合與一正整數，若新增的元素與該集合內元素有重複，    則無法新增。 (2) 刪除集合元素：輸入一集合與一正整數，若集合中無該元素，無法刪除。 (3) 計算集合是否空集合。 (4) 計算兩個集合的交集。 (5) 計算兩個集合的聯集。 (6) 計算集合是否為另一個集合的子集合。
-----------------------------輸入說明:
每一行第一數字輸入整數指令選項，意義如下: 0: 結束exit 1: 清空 A，輸出 A 和 B 的內容。 2: 清空 B，輸出 A 和 B 的內容。 3: 新增元素到 A，後面接一個正整數為要插入的元素，   輸出 A 和 B 的內容。 4: 新增元素到 B，後面接一個正整數為要新增的元素，   輸出 A 和 B 的內容。
第 25 頁
c10401.txt 5: 從 A 刪除一個元素，後面接一個正整數為要刪除的元素，   輸出 A 和 B 的內容。 6: 從 B 刪除一個元素，後面接一個正整數為要刪除的元素。    輸出 A 和 B 的內容。 7: 輸出 A, B 聯集。 8: 輸出 A, B 交集。 9: 輸出 A 是否為 B 的子集合，若是則輸出 1 ，否則輸出 0。
輸出說明:
輸出集合格式 集合名稱:[集合元素,集合元素,...]，中間沒有空白， 元素順序依照輸入先後順序。 交集與聯集的元素順序，先以A的元素順序再以B的元素順序。 每一指令輸出一行。
---------------Input: 3 4 3 7 4 8 4 9 5 4 6 8 3 8 7 8 9 0
Output: A:[4,]B:[] A:[4,7,]B:[] A:[4,7,]B:[8,] A:[4,7,]B:[8,9,] A:[7,]B:[8,9,] A:[7,]B:[9,] A:[7,8,]B:[9,] [7,8,9,] [] 0
*/
#include<stdio.h>
#include<stdlib.h>
int arear=0,brear=0;
int a[20],b[20];
void prtA()
{
	printf("a:[");
	for(int i=0;i<arear;i++)
		printf("%d,",a[i]);
	printf("]\n");
}
void prtB()
{
	printf("b:[");
	for(int i=0;i<brear;i++)
		printf("%d,",b[i]);
	printf("]\n");
}
void case1()
{
	printf("a:[]");
	arear=0;
	prtB();
}
void case2()
{
	printf("b:[]");
	brear=0;
	prtA();
}
void case3(int n)
{
	a[arear++]=n;
	prtA();
	prtB();
}
void case4(int n)
{
	b[brear++]=n;
	prtA();
	prtB();
}
void case5(int n)
{
	for(int i=0;i<arear;i++)
	{
		if(a[i]==n)
		{
			for(int j=i;j<(arear-1);j++)
			{
				a[j]=a[j+1];
			}
			arear--;
			break;
		}
	}
	prtA();
	prtB();
}
void case6(int n)
{
	for(int i=0;i<brear;i++)
	{
		if(b[i]==n)
		{
			for(int j=i;j<(brear-1);j++)
			{
				b[j]=b[j+1];
			}
			brear--;
			break;
		}
	}
	prtA();
	prtB();
}
void case7()
{
	printf("[");
	for(int i=0;i<arear;i++)
		printf("%d,",a[i]);
	for(int i=0;i<brear;i++)
		printf("%d,",b[i]);
	printf("]\n");
}
void case8()
{
	int i,j;
	printf("[");
	for(i=0;i<arear;i++)
	{
		for(j=0;j<brear;j++)
		{
			if(a[i]==b[j])
			{
				printf("%d,",a[i]);
			}
		}
	}
	printf("]\n");
}
int main()
{
	int c1,c2;
	while(1)
	{
		printf("輸入操作碼\n");
		scanf("%d",&c1);
		if(c1==0)
			break;
		if(c1>=3&&c1<7)
		{
			printf("輸入數字\n");
			scanf("%d",&c2);
		}
		switch(c1)
		{
			case 0:exit(1);
			//清空a,输出a和b的内容
			case 1:case1();break;
			//清空b,输出a和b的内容
			case 2:case2();break;
			//新增元素到A
			case 3:case3(c2);break;
			//新增元素到B
			case 4:case4(c2);break;
			//从A删除元素
			case 5:case5(c2);break;
			//从B删除元素
			case 6:case6(c2);break;
			//输出A,B联集
			case 7:case7();break;
			//输出A,B交集
			case 8:case8();break;
			case 9:printf("0\n");break;
		}
	}
    system("pause");
    return 0;
}

