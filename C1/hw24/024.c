#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void compute(int x1, int y1, int x2, int y2, int *perimeter, int *area)
{
	int l,h,t1,t2;
	t1=*perimeter;
	t2=*area;
	l=abs(x1-x2);
	h=abs(y1-y2);
	*perimeter=2*(l+h);
	*area=l*h;
	*perimeter=*perimeter>t1?*perimeter:t1;
	*area=*area>t2?*area:t2;
}
int main()
{
	int x1[10],x2[10],y1[10],y2[10];
	int i=0,perimeter=0,area=0;
	while(1)
	{
		printf("Input x1,y1,x2,y2\n");
		scanf("%d",&x1[i]);
		if(x1[i]==-1)
			break;
		scanf("%d %d %d",&y1[i],&x2[i],&y2[i]);
		i++;
	} 
	for(int j=0;j<i;j++)
	{
		compute(x1[j],y1[j],x2[j],y2[j],&perimeter,&area);
	}
	printf("%d\n",area);
	printf("%d\n",perimeter);
    system("pause");
    return 0;
}

