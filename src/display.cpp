
/*
	���ļ��к�������Ϊ����ӡ���ѧ����¼
*/


#include "student.h"


/*
�� �ܣ���ӡ��ͷ
�� ����void
�� �� ֵ��void
������ʽ�����һ�б�ͷ��Ϣ��
*/
void showTable(void)
{
	printf("       ����        ѧ��        �Ա�    math  English  physics  �ܷ�     ����\n");
	printf("\n");
}

/*
�� �ܣ���ʾ�ڴ���ļ�¼��Ϣ��
�� ������
�� �� ֵ��void
������ʽ����ͷ����ʼ�����ʾ��¼����, û�м�¼�� ��ӡ "û�м�¼" 
*/
void disPlay()
{
	system("cls");  // ����
	PRHEAD;
	rank_Refresh();
	printf(" ��ʾѧ����Ϣ: \n\n");
	showTable();
	int i = 0;
	while(records[i].savetag == 1)
	{
		PR(i);
		i++;
	}
	if(i == 0)
		printf("û�м�¼!\n");
}

/*
����:����ָ���������ʾ����¼��Ϣ
����:index,ָ�������
����:void
ָ������Ų�����ʱ�����Ҳ�������Ϣ
*/
void index_disPlay(int index)
{
	int count = countRecords();
	if( index >  count )   // ���벻�Ϸ�ʱ
	{
		printf("�ڴ���û�и�ɱ��¼!\n");
	}

	else if( index < 1 ) // ���벻�Ϸ�ʱ
		printf("��������Ų���Ϊ0����!\n");

	else
	{
		if(records[index-1].savetag == 1)
		{
			showTable();
			PR(index-1); // �궨��
		}
		else
		{
			printf("�ڴ���û�и�ɱ��¼!\n"); // �Ҳ���ʱ��Ӧ����
		}
	}
}

/*
����ڼ�¼�а����������λ��
�� �ܣ��ҳ��ܷ�Ϊsum�ڵ�0��numStus-1����¼�а����������λ�á�
�� ����float�����ҳ���λ�õ��ܷ�
�� �� ֵ��int��sum�ڵ�0��numStus-1����¼�а���������ġ�
������ʽ�����Ҳ�����
��ӡ: ��
*/
int getIndex(float sum)
{
	int i = 0;
	int count = 0;   //��¼�ڴ����ж��ټ�¼
	int index = 0; // ��¼λ��
	while(records[i].savetag == 1)
		i++;
	count = i;   // �ڴ��еļ�¼��
	for(i=0; i<count; i++)
	{
		if(sum>records[i].total)
			index++;
	}
	
	return (index);
}


/*
����:��ʾ�汾��������Ϣ
����:��
����:void
*/
void showHelp()
{
	system("cls");
	PRHEAD;
	PRROW3;
	int choice;
	printf("                          1.���ܼ��\n\n");
	printf("                          2.����\n\n");
	printf("                          0. �������˵�\n\n");

	choice = menu_select(0, 2);
	switch(choice)
	{
	case 1:
		system("cls");
		PRHEAD;
		printf("  ���ܼ��: \n\n\n");
		printf(" ѧ������ϵͳ\n");
		break;

	case 2:
		system("cls");
		PRHEAD; // �궨��,��ӡһ��***
		PRROW1;
		printf("                ���ߣ�\n");
		printf("                              U201014068  ����\n\n");
		printf("                              U201014072  ������\n\n");
		printf("                              U201014055  �춮��\n\n");
		printf("                              U201014052  �\n\n\n");
		printf("                               2012��6��7��\n\n");
		printf("                            ѧ������ϵͳ2.00��\n\n");
		PRHEAD;
		break;
	case 0:
		break;
	}
}


/*
����: �ɰ�������ѧ�š��������������¼
����: ��
����: void
*/
void sort_disPlay()
{
	system("cls");
	PRHEAD;
	printf(" ��ʾ��¼: \n");
	PRROW2;
	int choice;
	printf("                               1. ������˳����ʾ\n\n");
	printf("                               2. ��ѧ��˳����ʾ\n\n");
	printf("                               3. ������������ʾ\n\n");
	printf("                               0. �������˵�\n\n\n");

	choice = menu_select(0, 3);
	switch(choice)
	{
	case 1:
		total_sortRecords();
		disPlay();
		break;
	case 2:
		num_sortRecords();
		disPlay();
		break;
	case 3:
		name_sortRecords();
		disPlay();
		break;
	case 0:
		break;
	}
	
}
