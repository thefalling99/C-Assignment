#include<stdio.h>
int main()
{
	float a=0,b=0,temp,withdraw,deposit,gg;
	int p=0,percentA=0,percentB=0;
	char c;
	char buffer;
	while((c=getchar())!='e')
	{
		scanf("%c",&buffer);
		switch(c)
		{
			case 'a':
				printf("select A\n");
				p=1;
				break;
			case 'b':
				printf("select B\n");
				p=-1;
				break;
			case 'v':
				if(p==1)
				{
					printf("A:%0.f\n",a);
					break;
				}
				else if(p==-1)
				{
					printf("B:%0.f\n",b);
					break;
				}
			case 'w':
				if(p==1)
				{
					scanf("%f",&withdraw);
					scanf("%c",&buffer);
					a-=withdraw;
					printf("A:withdraw,%0.f\n",withdraw);
					printf("A:%0.f\n",a);
					break;
				}
				else if(p==-1)
				{
					scanf("%f",&withdraw);
					scanf("%c",&buffer);
					b-=withdraw;
					printf("B:withdraw,%0.f\n",withdraw);
					printf("B:%0.f\n",b);
					break;
				}
				
			case 's':
				if(p==1)
				{
					scanf("%f",&deposit);
					scanf("%c",&buffer);
					a+=deposit;
					printf("A:deposit,%0.f\n",deposit);
					printf("A:%0.f\n",a);
					break;
				}
				else if(p==-1)
				{
					scanf("%f",&deposit);
					scanf("%c",&buffer);
					b+=deposit;
					printf("B:deposit,%0.f\n",deposit);
					printf("B:%0.f\n",b);
					break;
				}
				break;
			case 'p':
				if(a==b)
				{
					printf("A:50%%,B:50%%\n");
				}
				else if(a<0&&b>0)
				{
					printf("A:0%%,B:100%%\n");
				}
				else if(a>0&&b<0)
				{
					printf("A:100%%,B:0%%\n");
				}
				else
				{
					temp=(a/(a+b))*100;
					percentA=(int)temp;
					percentB=100-percentA;
					printf("A:%d%%,B:%d%%\n",percentA,percentB);
				}
				break;
		}
	} 
}
