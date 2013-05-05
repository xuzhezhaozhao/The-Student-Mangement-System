
/*
	���ļ��к�������Ϊ����ʼ���ڴ漰ͳ��ѧ����¼����ѧ��������Ϣ
*/


#include "student.h"

/*
  ��ʼ���ڴ��¼����
����:���ڴ��еļ�¼��ʼ��, ������
����: ��
��ӡ: ��
*/
void initial()
{
	records=(StuInfo*)malloc(sizeof(StuInfo)*arrSize);
	if (records==NULL)
	{
		printf("memory fail!");
		exit(-1);
	}

	int i;

	for (i=0; i<arrSize;i++)
	{
		records[i].savetag = 0;  // ���ڴ��м�¼���
	}
}

/*	
����: ͳ���ڴ����ж�������¼
����:��¼������
��ӡ:   ��       
*/
int countRecords()
{
	int i = 0;
	int count = 0;   //��¼�ڴ����ж��ټ�¼
	while(records[i].savetag == 1)
		i++;
	count = i;   // �ڴ��еļ�¼��
	return (count);
}



/*
���ܣ��õ�ѧ����������Ϣ
������stuΪһ��ѧ����¼
����ֵ����ѧ������������ֵ
��ӡ����
*/
int getRank(StuInfo stu)
{
	int i = 0;
	int j = 0;
	int rank = 1; // ������Ϣ
	while(1 == records[i].savetag)
	{
		records[i].total  = records[i].sco.English  + records[i].sco .math + records[i].sco .physics;	
		i++;
	}

	for(i=0; i<countRecords(); i++)
	{
		if(records[i].num != stu.num )
		{
			if(records[i].total > stu.total )
			rank++;  // �бȸü�¼���ѧ��ʱ�� ����rank��1
		}
	}

	return(rank);
}

/*
���ܣ����ڴ������ݱ仯ʱ��ˢ��������Ϣ
��������
���أ�void
��ӡ����
*/
void rank_Refresh()
{
	int i = 0;
	for(i=0; i<countRecords(); i++)
	{
		records[i].rank = getRank(records[i]);
	}
}