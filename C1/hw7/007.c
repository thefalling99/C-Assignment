/*007. ����Y�M�x��
ݔ��ÿ�¾W�ȡ��W�⡢��Ԓ��ͨԒ�r�g(��)���W�ȡ��W�⺆Ӎ�t����������Y�M��
�M�����±�:
�Y�M���        183��     383��     983��  �����M          183Ԫ     383Ԫ     983Ԫ  ���݃���        �� �� �M �� �� �� �~ ͨ �� �M �Z���M�� �W��   0.08      0.07      0.06 (Ԫ/��)  �W��   0.139     0.130     0.108 ��Ԓ            0.135     0.121     0.101 (Ԫ/��) ��Ӎ�M�� �W��   1.128     1.128     1.128 (Ԫ/�t)  �W��   1.483     1.483     1.483
--------------------------------ݔ���f��
�� 4 �
c10401.txt
--------------�W���Z��(��)������ �W���Z��(��)������ ��Ԓ    (��)������ �W�Ⱥ�Ӎ�������� �W�Ⱥ�Ӎ��������
--------------------------------ݔ���f�� --------------------------------����Y�M��ͣ�(183, 383, 983) ����Y�M����С���c����λ
--------------------------------�yԇ�Y�ϣ�(Test Case)
input 120 150 20 10 5
output 183 183.000
input 3000 4000 200 5 5
output 383 767.255*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	//��A,B,C�ֱ�Ϊ183��383��983���ײ͵��ܻ���
	float A=0,B=0,C=0;
	//�ֱ�Ϊ���������������������л������ڼ�Ѷ���������Ѷ��
	float iCall,oCall,cCall,iM,oM;
	float iCall2,oCall2,cCall2,iM2,oM2;
	int choose;
	float cost;
	printf("Ոݔ��W���Z�����W���Z������Ԓ���W�Ⱥ�Ӎ�����W�⺆Ӎ��\n");
	scanf("%f %f %f %f %f",&iCall,&oCall,&cCall,&iM,&oM);
	iCall2=iCall*0.08;
	oCall2=oCall*0.139;
	cCall2=cCall*0.135;
	iM2=iM*1.128;
	oM2=oM*1.483;
	A=iCall2+oCall2+cCall2+iM2+oM2;
	if(A<183)
		A=183;

	iCall2=iCall*0.07;
	oCall2=oCall*0.130;
	cCall2=cCall*0.121;
	iM2=iM*1.128;
	oM2=oM*1.483;
	B=iCall2+oCall2+cCall2+iM2+oM2;
	if(B<383)
		B=383;

	iCall2=iCall*0.06;
	oCall2=oCall*0.108;
	cCall2=cCall*0.101;
	iM2=iM*1.128;
	oM2=oM*1.483;
	C=iCall2+oCall2+cCall2+iM2+oM2;
	if(C<983)
		C=983;

	if(A<383)
	{
		choose=183;
		cost=A;
	}
	if(B>383&&B<983)
	{
		choose=383;
		cost=B;
	}
	if(C>983)
	{
		choose=983;
		cost=C;
	}
	printf("�x%d��\n���M%2.f\n",choose,cost);
    system("pause");
}
