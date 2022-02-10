#include<stdio.h>
#define GateText(TYPE)\
	int x,y;\
	int  (*gateValue)(struct TYPE*);

typedef struct notGate_s
{
	GateText(notGate_s);
}notGate;
typedef struct andGate_s
{
	GateText(andGate_s);
}andGate;
typedef struct orGate_s
{
	GateText(orGate_s);
}orGate;

int notGateValue(notGate *obj)
{
	return (1-(obj->x));
}
int andGateValue(andGate *obj)
{
	return (obj->x&&obj->y);
}
int orGateValue(orGate *obj)
{
	return (obj->x||obj->y);
}

void newNotGate(notGate *obj,int x)
{
	obj->x=x;
	obj->gateValue=notGateValue;
}
void newAndGate(andGate *obj,int x,int y)
{
	obj->x=x;
	obj->y=y;
	obj->gateValue=andGateValue;
}
void newOrGate(orGate *obj,int x,int y)
{
	obj->x=x;
	obj->y=y;
	obj->gateValue=orGateValue;
}
int main()
{
	int result,x,y;
	int numin[3];
	char gatein[3],buffer;
	printf("Input gate value\n");
	for(int i=0;i<3;i++)
	{
		scanf("%d,",&numin[i]);
	} 
	printf("Input gate\n");
	scanf("%c,",&buffer);
	for(int i=0;i<3;i++)
	{
		scanf("%c",&gatein[i]);
		scanf("%c",&buffer);
	}
	for(int i=0;i<3;i++)
	{
		if(gatein[i]=='N')
		{
			notGate n;
			newNotGate(&n,numin[i]);
			result=n.gateValue(&n);
			printf("%d ",result);
		}
		else if(gatein[i]=='O')
		{
			orGate o;
			newOrGate(&o,result,numin[i]);
			result=o.gateValue(&o);
			printf("%d ",result);
		}
		else if(gatein[i]=='A')
		{
			andGate a;
			newAndGate(&a,result,numin[i]);
			result=a.gateValue(&a);
			printf("%d ",result);
		}
	}
}
