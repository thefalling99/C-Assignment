#include<stdio.h>
#include<stdlib.h>
#define shapeText(type) \
	char name[10];		\
	int (*perimeter)(struct TYPE*);
//������
typedef struct _T{
	shapeText(_T);
	int a;
	int b;
	int c;
}T;
//������
typedef struct _S{
	shapeText(_S);
	int a;
}S;
//������
typedef struct _R{
	shapeText(_R);
	int a;
	int b;
}R;
//Բ��
typedef struct _C{
	shapeText(_C);
	int a;
}C;
int Tperimeter(T *obj)
{
	return (obj->a+obj->b+obj->c);
}
int Sperimeter(S *obj)
{
	return ((obj->a)*4);
}
int Rperimeter(R *obj)
{
	return ((obj->a+obj->b)*2);
}
int Cperimeter(C *obj)
{
	return (2*3.14*obj->a);
}
void newT(T *obj,int a,int b,int c)
{
	obj->a=a;
	obj->b=b;
	obj->c=c;
	//obj->perimeter=Tperimeter;
}
void newS(S *obj,int a)
{
	obj->a=a;
	//obj->perimeter=Sperimeter;
}
void newR(R *obj,int a,int b)
{
	obj->a=a;
	obj->b=b;
	//obj->perimeter=Rperimeter;
}
void newC(C *obj,int a)
{
	obj->a=a;
	//obj->perimeter=Cperimeter;
}

int main()
{
	char type;
	int num[10],n=0,sum=0;
	int a,b,c;
	char buffer;
	while(1)
	{
		printf("ݔ�����T��S��R��C(ݔ��E�Y��)\n");
		scanf("%c",&type);
		if(type=='E')
			break;
		else if(type=='T')
		{
			T t;
			scanf("%d %d %d",&a,&b,&c);
			scanf("%c",&buffer);
			newT(&t,a,b,c);
			num[n++]=Tperimeter(&t);
		}
		else if(type=='S')
		{
			S s;
			scanf("%d",&a);
			scanf("%c",&buffer);
			newS(&s,a);
			num[n++]=Sperimeter(&s);
		}
		else if(type=='R')
		{
			R r;
			scanf("%d %d",&a,&b);
			scanf("%c",&buffer);
			newR(&r,a,b);
			num[n++]=Rperimeter(&r);
		}
		else if(type=='C')
		{
			C c;
			scanf("%d",&a);
			scanf("%c",&buffer);
			newC(&c,a);
			num[n++]=Cperimeter(&c);
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d\n",num[i]);
		sum+=num[i];
	}
	printf("%d\n",sum);
    system("pause");
    return 0;
}

