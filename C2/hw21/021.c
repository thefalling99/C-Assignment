#include<stdio.h>
#include<stdlib.h>
int binary[8];
void d_b(int d)
{
	int i=0;
	for(i=0;i<8;i++)
	{
		binary[i]=0;
	}
	i=7;
	while(d!=1)
	{
		binary[i--]=d%2;
		d/=2;
	}
	binary[i]=1;
}
int main()
{
	int c,num;
	FILE *fp;
	char name[10],buffer;
	int read[32];
	printf("Input control:\n");
	scanf("%d",&c);
	while(c!=5)
	{
		switch(c)
		{
			case 1:
				while(1)
				{
					printf("Input number:\n");
					scanf("%d",&num);
					if(num==-1)
						break;
					d_b(num);
					fp= fopen(name, "ab"); // ���ļ�д����
    				fwrite(binary,1,sizeof(binary),fp); // �Ѹ�������д���ļ� myfile.bin
    				fclose(fp);
				}
			    fp = fopen(name, "rb"); // ���´��ļ�������
			    fread(read , 1 , sizeof(read) , fp); // ���ļ��ж�����
			    for(int i=0;i<32;i++)
			    {
			    	if(i%8==0)
			    		printf("\n");
			    	printf("%d ",read[i]);
			    }
			    printf("\n");
			    fclose(fp); // �ر��ļ�
				break;
			case 2:
				printf("Input filename:\n");
				scanf("%c",&buffer);
				scanf("%s",name);
				fp=fopen(name,"wb");
				if(fp==NULL)
				{
					printf("file open error\n");
					exit(0);
				}
				break;
			case 3:break;
			case 4:
				int location,change,len;
				printf("Input location\n");
				scanf("%d",&location);
				printf("Input change number:\n");
				scanf("%d",&change);
				len=31-((3-(location/8))*8)-(location%8);
				printf("len:%d\n",len);
				for(int i=0;i<31;i++)
				{
					if(i==len)
					{
						read[i]=change;
						break;
					}
				}
				fp= fopen(name, "wb"); // ���ļ�д����
    			fwrite(read,1,sizeof(read),fp); // �Ѹ�������д���ļ� myfile.bin
    			fclose(fp);
			    fp = fopen(name, "rb"); // ���´��ļ�������
			    fread(read , 1 , sizeof(read) , fp); // ���ļ��ж�����
			    for(int i=0;i<32;i++)
			    {
			    	if(i%8==0)
			    		printf("\n");
			    	printf("%d ",read[i]);
			    }
			    printf("\n");
			    fclose(fp); // �ر��ļ�
				break;
		} 
		
		printf("Input control:\n");
		scanf("%d",&c);
	}
    system("pause");
    return 0;
}

