#include<stdio.h>
#include<stdlib.h>
void f1(int x1,int y1,int x2,int y2,double *m,double *b)
{
	if(x1-x2==0||x2-x1==0)
	{
		printf("x=1\n");
		return;
	}
	*m=((double)y1-y2)/((double)x1-x2);
	*b=((double)x2*y1-(double)x1*y2)/((double)x2-x1);
	int _m,_b;
	if((m-(int)m)>0)
        _m=2;
    else
        _m=0;
    if((b-(int)b)>0)
        _b=2;
    else
        _b=0;

	if(*m==0)
		printf("y=(%.(%d)f)\n",*b,_b);
	else
	{
		if(*m==1&&*b!=0)
        {
            if(*b>0)
                printf("y=x+%.(%f)\n",*b,_b);
            else
                printf("y=x%.(%f)\n",*b,_b);
        }
		else if(*m==1&&*b==0)
			printf("y=x\n");
		else if(*m!=1&&*b==0)
			printf("y=%.2fx\n",*m);
		else
        {
            if(*b>0)
                printf("y=%.2fx+%.0f\n",*m,*b);
            else
                printf("y=%.2fx%.0f\n",*m,*b);
        }

	}
}
void f2(int x1, int y1, int x2, int y2, int *m1, int *m2, int *b1, int *b2)
{
    if(x1-x2==0||x2-x1==0)
	{
		printf("x=1\n");
		return;
	}
	*m1=(y1-y2);
	*m2=(x1-x2);
	*b1=(x2*y1-x1*y2);
	*b2=(x2-x1);
	if((*m1/ *m2)==0&&(*m1)==0)
		printf("y=%d\n",(*b1/ *b2));
	else
	{
		if((*m1/ *m2)==1&&(*b1/ *b2)!=0)
			printf("y=x%d\n",(*b1/ *b2));
		else if((*m1/ *m2)==1&&(*b1/ *b2)==0)
			printf("y=x\n");
		else if((*m1/ *m2)!=1&&(*b1/ *b2)==0)
			printf("y=%dx\n",(*m1/ *m2));
		else
        {
            for (int j= 2;j<= *m1; j++)
            {
                if (*m1 % j== 0 && *m2 % j == 0)
                {
                *m1/= j;
                *m2 /= j;
                j--;
                continue;
                }
            }
            if((*b1/ *b2)>0)
                printf("y=%d/%dx+%d\n",*m1,*m2,(*b1/ *b2));
            else
                printf("y=%d/%dx%d\n",*m1,*m2,(*b1/ *b2));
        }
	}
}
int main()
{
	int x1,y1,x2,y2,m1,m2,b1,b2;
	double m,b;
	printf("Input x1,y1,x2,y2\n");
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	f1(x1,y1,x2,y2,&m,&b);
	f2(x1,y1,x2,y2,&m1,&m2,&b1,&b2);
	system("pause");
	return 0;
}

