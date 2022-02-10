#include <stdio.h>
#include <stdlib.h>
int g_s[9][9];//={
//{0,2,3,4,5,6,7,8,9},
//{4,5,6,7,8,9,1,2,3},
//{7,8,9,1,2,3,4,5,6},
//{2,3,1,5,6,4,8,9,7},
//{5,6,4,8,9,7,2,3,1},
//{8,9,7,2,3,1,5,6,4},
//{3,1,2,6,0,5,9,7,8},
//{6,4,5,9,7,8,3,1,2},
//{9,0,8,3,1,2,6,4,5},
//};
/*��ӡ��ǰ����״̬*/
int prt()
{
    int i = 0;
    int j = 0;
    for(i = 0;i < 9;i++)
    {
        for(j = 0;j < 9;j++)
        {
            printf("%d ",g_s[i][j]);
        }
        printf("\n");
    }

    getchar();
}

/*��ȡһ��λ�õ�ǰ���п��ܵĽ�*/
int get_all_num(int i,int j,int a[9])
{
    int s[9] = {1,2,3,4,5,6,7,8,9};
    int row,col,k;

    /*ɾ����ǰ�����ѳ��ֵ�ֵ*/
    for(col = 0;col < 9;col++)
    {
        k = g_s[i][col];
        if(k != 0)
        {
            s[k-1] = 0;
        }
    }

    /*ɾ����ǰ�����ѳ��ֵ�ֵ*/
    for(row = 0;row < 9;row++)
    {
        k = g_s[row][j];
        if(k != 0)
        {
            s[k-1] = 0;
        }
    }

    /*ɾ����ǰ�Ź������ѳ��ֵ�ֵ*/
    row = (i/3)*3;
    col = (j/3)*3;
    for(i = row;i < (row+3);i++)
    {
        for(j = col;j < (col+3);j++)
        {
            k = g_s[i][j];
            if(k != 0)
            {
                s[k-1] = 0;
            }
        }
    }

    i = 0;
    for(k = 0;k < 9;k++)
    {
        if(s[k] != 0)
        {
            a[i] = s[k];
            i++;
        }
    }

    return i;
}

/*�жϵ�ǰ���Ƿ�Ϸ�*/
int check_row(int i,int num)
{
    int j = 0;
    for(j = 0;j < 9;j++)
    {
        if(g_s[i][j] == num)
        {
            return 0;
        }
    }

    return 1;
}

/*�жϵ�ǰ���Ƿ�Ϸ�*/
int check_col(int j,int num)
{
    int i = 0;
    for(i = 0;i < 9;i++)
    {
        if(g_s[i][j] == num)
        {
            return 0;
        }
    }

    return 1;

}

/*�жϵ�ǰ�Ź����Ƿ�Ϸ�*/
int check_block(int i,int j,int num)
{
    int row = (i/3)*3;
    int col = (j/3)*3;
    int k = 0;
    int l = 0;

    for(k = row;k < (row+3);k++)
    {
        for(l = col;l < (col+3);l++)
        {
            if(g_s[k][l] == num)
            {
                return 0;
            }
        }
    }


    return 1;
}

/*����һ����*/
int try_one(int i,int j,int num)
{
    if(check_row(i,num) && check_col(j,num) &&
        check_block(i,j,num))
    {
        g_s[i][j] = num;
        //prt();
        return 1;
    }

    return 0;
}

/*��ȡ��һ��Ҫ��յ�λ��*/
int get_next(int *pi,int *pj)
{
    int i = *pi;
    int j = *pj;
    int r = i;
    int c = 0;
    j++;

    for(;r < 9;r++)
    {
        for(c = j;c < 9;c++)
        {
            if(g_s[r][c] == 0)
            {
                *pi = r;
                *pj = c;
                return 1;
            }
        }
        j = 0;
    }

    if(r == 9)
    {
        return 0;
    }

    *pi = r;
    *pj = c;
    return 1;

}

/*�ҵ�һ����*/
void finish()
{
    printf("\n find a solution: \n");
    prt();
}

/*����һ��λ��*/
void do_one(int i,int j)
{
    int row = i;
    int col = j;
    int n = 0;
    int k = 0;
    int a[9] = {0};

    /*��ǰλ���н�,��һ��λ��*/
    if(g_s[row][col] != 0)
    {
        /*��ȡ��һ���޽��λ��*/
        if(get_next(&row,&col))
        {
            /*��һ�¸�λ�õݹ����*/
            do_one(row,col);
        }
        /*���н���,�ɹ�*/
        else
        {
            finish();
        }

        /*��ǰλ���н⣬ֱ�ӻ���*/
        return;
    }

    /*��ǰλ���޽�*/
    else
    {
        /*��ȡ��ǰλ�õ����п��ܽ�*/
        n = get_all_num(i,j,a);

        for(k = 0;k < n;k++)
        {
            /*�������п��ܵĽ⣬�������ظ��������Ͳ�����*/
            if(try_one(i,j,a[k]))
            {
                row = i;
                col = j;
                /*��λ���ҵ����ʵ��ˣ���һ��*/
                if(get_next(&row,&col))
                {
                    do_one(row,col);
                }
                /*��ǰλ�����н���û����һ����,����*/
                else
                {
                    finish();
                }
            }
        }

        /*Ҫ��ǰ����,�����λ���ҵ��Ľ���Ч,����ǰ��0*/
        g_s[i][j] = 0;
        //prt();
        return ;
    }


}

int main()
{
	printf("����9x9���־���\n");
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			scanf("%d",&g_s[i][j]);
	}
    do_one(0,0);
    system("pause");
    return 0;

}
