#include<stdio.h>
#include<stdlib.h>
void f(int* a,int *b)
{
    int j=0;
    int aa=0,bb=0;
    if(*a<0)
    {
        *a=-*a;
        aa=1;
    }
    if(*b<0)
    {
        *b=-*b;
        bb=1;
    }
    for (j= 2;j<= *a; j++)
    {
        if (*a % j== 0 && *b % j == 0)
        {
            *a/= j;
            *b /= j;
            j--;
            continue;
        }
    }
    if(aa==1)
    {
        *a=-*a;
    }
    if(bb==1)
    {
        *b=-*b;
    }
}
int main()
{
	int a1,a2,b1,b2,c1,c2,u=0,d=0,carry;
	printf("input a1/a2 b1/b2 c1/c2\n");
	scanf("%d/%d %d/%d %d/%d",&a1,&a2,&b1,&b2,&c1,&c2);
		for(int j=1;j<5;j++)
		{
			u=0;d=0;carry=0;
			switch(j)
			{
				case 1:if(a1==0||a2==0||b1==0||b2==0)
					   {
					   		printf("Error\n");
					   		break;
					   }
					   u=a1*b2+a2*b1;
					   d=a2*b2;
					   if(u>d)
					   {
					   		carry=u/d;
					   		u=u%d;
					   		f(&u,&d);
					   		printf("%d(%d/%d)\n",carry,u,d);
					   }
					   else
                        {
                            f(&u,&d);
					   		printf("%d/%d\n",u,d);
                        }
					   break;
				case 2:if(a1==0||a2==0||b1==0||b2==0)
					   {
					   		printf("Error\n");
					   		break;
					   }
					   u=a1*b2-a2*b1;
					   d=a2*b2;
					   if(u>d)
					   {
					   		carry=u/d;
					   		u=u%d;
					   		f(&u,&d);
					   		printf("%d(%d/%d)\n",carry,u,d);
					   }
					   else
                        {
                            f(&u,&d);
					   		printf("%d/%d\n",u,d);
                        }
					   	break;
				case 3:if(a1==0||a2==0||b1==0||b2==0)
					   {
					   		printf("Error\n");
					   		break;
					   }
					   u=a1*b1;
					   d=a2*b2;
					   if(u>d)
					   {
					   		carry=u/d;
					   		u=u%d;
					   		f(&u,&d);
					   		printf("%d(%d/%d)\n",carry,u,d);
					   }
					   else
                        {
                            f(&u,&d);
					   		printf("%d/%d\n",u,d);
                        }
					   	break;
				case 4:if(a1==0||a2==0||b1==0||b2==0)
					   {
					   		printf("Error\n");
					   		break;
					   }
					   u=a1*b2;
				       d=a2*b1;
				       if(u>d)
					   {
					   		carry=u/d;
					   		u=u%d;
					   		f(&u,&d);
					   		printf("%d(%d/%d)\n",carry,u,d);
					   }
					   else
                        {
                            f(&u,&d);
					   		printf("%d/%d\n",u,d);
                        }
					   	break;
			}
		}
		for(int j=1;j<5;j++)
		{
			u=0;d=0;carry=0;
			switch(j)
			{
				case 1:if(a1==0||a2==0||c1==0||c2==0)
					   {
					   		printf("Error\n");
					   		break;
					   }
						u=a1*c2+a2*c1;
					   d=a2*c2;
					   if(u>d)
					   {
					   		carry=u/d;
					   		u=u%d;
					   		f(&u,&d);
					   		printf("%d(%d/%d)\n",carry,u,d);
					   }
					   else
                        {
                            f(&u,&d);
					   		printf("%d/%d\n",u,d);
                        }
					   	break;
				case 2:if(a1==0||a2==0||c1==0||c2==0)
					   {
					   		printf("Error\n");
					   		break;
					   }
				 		u=a1*c2-a2*c1;
					   d=a2*c2;
					   if(u>d)
					   {
					   		carry=u/d;
					   		u=u%d;
					   		f(&u,&d);
					   		printf("%d(%d/%d)\n",carry,u,d);
					   }
					   else
                        {
                            f(&u,&d);
					   		printf("%d/%d\n",u,d);
                        }
					   	break;
				case 3:if(a1==0||a2==0||c1==0||c2==0)
					   {
					   		printf("Error\n");
					   		break;
					   }
						u=a1*c1;
					   d=a2*c2;
					   if(u>d)
					   {
					   		carry=u/d;
					   		u=u%d;
					   		f(&u,&d);
					   		printf("%d(%d/%d)\n",carry,u,d);
					   }
					   else
                        {
                            f(&u,&d);
					   		printf("%d/%d\n",u,d);
                        }
					   	break;
				case 4:if(a1==0||a2==0||c1==0||c2==0)
					   {
					   		printf("Error\n");
					   		break;
					   }
						u=a1*c2;
				       d=a2*c1;
				       if(u>d)
					   {
					   		carry=u/d;
					   		u=u%d;
					   		f(&u,&d);
					   		printf("%d(%d/%d)\n",carry,u,d);
					   }
                        else
                        {
                            f(&u,&d);
					   		printf("%d/%d\n",u,d);
                        }
					   	break;
			}
		}
		for(int j=1;j<5;j++)
		{
			u=0;d=0;carry=0;
			switch(j)
			{
				case 1:if(b1==0||b2==0||c1==0||c2==0)
					   {
					   		printf("Error\n");
					   		break;
					   }
						u=b1*c2+b2*c1;
					   d=b2*c2;
					   if(u>d)
					   {
					   		carry=u/d;
					   		u=u%d;
					   		f(&u,&d);
					   		printf("%d(%d/%d)\n",carry,u,d);
					   }
					   else
                        {
                            f(&u,&d);
					   		printf("%d/%d\n",u,d);
                        }
					   	break;
				case 2:if(b1==0||b2==0||c1==0||c2==0)
					   {
					   		printf("Error\n");
					   		break;
					   }
						u=b1*c2-b2*c1;
					   d=b2*c2;
					   if(u>d)
					   {
					   		carry=u/d;
					   		u=u%d;
					   		f(&u,&d);
					   		printf("%d(%d/%d)\n",carry,u,d);
					   }
					   else
                        {
                            f(&u,&d);
					   		printf("%d/%d\n",u,d);
                        }
					   	break;
				case 3:if(b1==0||b2==0||c1==0||c2==0)
					   {
					   		printf("Error\n");
					   		break;
					   }
						u=b1*c1;
					   d=b2*c2;
					   if(u>d)
					   {
					   		carry=u/d;
					   		u=u%d;
					   		f(&u,&d);
					   		printf("%d(%d/%d)\n",carry,u,d);
					   }
					   else
                        {
                            f(&u,&d);
					   		printf("%d/%d\n",u,d);
                        }
					   	break;
				case 4:if(b1==0||b2==0||c1==0||c2==0)
					   {
					   		printf("Error\n");
					   		break;
					   }
						u=b1*c2;
				       d=b2*c1;
				       if(u>d)
					   {
					   		carry=u/d;
					   		u=u%d;
					   		f(&u,&d);
					   		printf("%d(%d/%d)\n",carry,u,d);
					   }
					   else
                       {
                           f(&u,&d);
					   		printf("%d/%d\n",u,d);
                       }
					   	break;
			}
		}
	system("pause");
    return 0;
}

