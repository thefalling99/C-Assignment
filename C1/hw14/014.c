/*014. Ոʹ��һ�� while loop �� function call
�o��һ��ʮ�Mλ������Ո׫��һ��ʽ���Ԍ���ʮ�Mλ�����D�Q��ָ�����M�Ƶ�������
ݔ���f��: ݔ��֞�ɲ��ݣ�����ָ�����M�Ɣ� (2 ~ 16) �cʮ�Mλ����(0 ~ 1000000000)
16 �Mλ���֞� 0 1 2 3 4 5 6 7 8 9 A B C D E F
ݔ���f��: ���D�Q������Mλ�Ƶ�����( y )
input:
16 1234
output: 4D2
Input:
8 56456456
Output:
327272410
----------------------
Input:
11 17489465
Output:
9966104
�� 12 �
c10401.txt
----------------------Input:
4 17489
Output:
10101101
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int dec,base,i=0;
	char ch[20];
	printf("ݔ��ʮ�Mλ��\n");
	scanf("%d",&dec);
	printf("�D�Q������M��\n");
	scanf("%d",&base);
	while(dec!=0)
	{
		ch[i]=dec%base;
		if(ch[i]>=10)
			ch[i]=ch[i]-10+'A';
		if(ch[i]<10)
			ch[i]+=48;
		dec/=base;
		i++;
	}
	i--;
	while(i>=0)
	{
		printf("%c",ch[i]);
		i--;
	}
	printf("\n");
	system("pause");
	return 0;
}
