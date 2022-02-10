#include<stdio.h>
#include<stdlib.h>
int c=-1,sum=0;
int b_d(int b)
{
	int num = 0,j=1;
	while(b)
	{
	num +=(b%10)*j;
	b /= 10;
	j *= 2;
	}
	return num;
}
void d_b(int d)
{
	int bnum[11]={0},i=0;
	if(d!=0)
    {
        while(d!=1)
        {
            bnum[i++]=d%2;
            d/=2;
        }
        bnum[i]=1;
    }
	for(int j=10;j>=0;j--)
	{
		printf("%d",bnum[j]);
	}
	printf("\n");
}
int f(int m)
{
	c++;
	if(m==0||m==1)
	{
		sum+=c;
		return m;
	}
	else if(m%2==0)
	{
		sum+=c;
		return f(m/2);
	}
	else if(m%2==1)
	{
		sum+=c;
		return f((m+1)/2);
	}
}
int main()
{
	int nnum[10];
	int b,d,i=0;
	while(1)
	{
		printf("Input binary\n");
		scanf("%d",&b);
		if(b==-1)
			break;
		else
		{
			d=b_d(b);
			f(d);
			nnum[i++]=sum;
			//printf("c:%d sum:%d",c,sum);
			c=-1;
			sum=0;
		}
	}
	for(int j=0;j<i;j++)
	{
		d_b(nnum[j]);
	}
    system("pause");
    return 0;
}

