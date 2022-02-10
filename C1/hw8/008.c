/*請檢查輸入的三門課程是否衝堂 依序輸入課程編號(數字)、上課小時數(1-2小時)、上課時間(依小時數輸入上課時間, 星期 1-5, 第1-9節)
--------------------------------輸入說明 --------------------------------1001 (課程編號)
第 5 頁
c10401.txt
2    (2小時) 11   (星期1 第1節課) 59   (星期5 第9節課) ...  (第二門課) ...  (第三門課)
--------------------------------輸出說明 --------------------------------課程編號,課程編號,衝突時間 (課程編號輸出順序與輸入順序相同，即12,13,23) (每次列出兩個衝突課程編號，一個衝突時間) (若沒有衝突則輸出 correct)
--------------------------------測試資料： --------------------------------
input
1001 2 12 13 1002 2 13 21 1003 2 25 21 --------output
1001,1002,13 1002,1003,21
--------------------------------input
1001 1 21 1002 2 33 32 1003 2 45 46 --------output
correct*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int classId[3];
	int classTime[3];
	int time[6];
	int i,j,isClash=0;
	int t=0;
	for(i=0;i<3;i++)
	{
		printf("what's the class%d ID?\n",i+1);
		scanf("%d",&classId[i]);
		printf("How long a lesson%d?\n",i+1);
		scanf("%d",&classTime[i]);
		for(int k=0;k<classTime[i];k++)
        {
            printf("what's the class time?\n");
            scanf("%d",&time[t++]);
        }
	}
	for(i=0;i<t;i++)
	{
		for(j=0;j<t;j++)
		{
			if(i!=j&&time[i]==time[j])
			{
                if(isClash%2==0)
				{
					printf("%d ",classId[i/2]);
					printf("%d ",classId[j/2]);
					printf("%d\n",time[i]);
				}
				isClash++;
			}
		}
	}
	if(isClash==0)
		printf("corrcet\n");
	system("pause");
	return 0;
}
