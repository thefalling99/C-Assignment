#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char num[10];
    char temp[10];
    int prime=0,bigPrime=0;
    printf("Input number:");
    scanf("%s",num);
    int n=strlen(num);
    int i=0,t=1,x=0,j,o;
    int p1,p2;
    for(i=0;i<n;i++)
    {
        p1=0;
        p2=p1+t;
        t++;
        while(p2<=n)
        {
            for(j=p1;j<p2;j++)
            {
                temp[x++]=num[j];
            }
            temp[x]='\0';
            x=0;
            prime=atoi(temp);
            int k=(int)sqrt(prime);
           for(o=2;o<=k;o++)
           {
               if(prime%o==0)
                 break;
           }
           if(o>k)
            {
                if(prime>bigPrime)
                {
                    bigPrime=prime;
                }
            }
            p1++;
            p2++;
        }
    }
    if(bigPrime)
        printf("%d\n",bigPrime);
    else
        printf("No prime found\n");
}
