
/*
	���ļ��к�������Ϊ�����ܷ֡�ѧ�š���������ѧ����¼
*/

#include "student.h"


/*
����: ����,���ڴ��еļ�¼���ܷ�����,�����ߵ���ǰ
����ֵ:void
*/
void total_sortRecords()
{
	int i = 0;
	int j = 0;
	StuInfo stemp;
	int count = 0;   //��¼�ڴ����ж��ټ�¼
	count = countRecords();
	/*ѡ�� ���� */
	for(i=0; i<count-1; i++) 
		for(j=i+1; j<count; j++)
		{
			if(records[i].total < records[j].total)
			{
				copyRecord(&records[i], &stemp);
				copyRecord(&records[j], &records[i]);
				copyRecord(&stemp, &records[j]);
			}
		}
}

/*
����: ����,���ڴ��еļ�¼��ѧ������,ѧ�Ÿߵ͵���ǰ
����ֵ:void
*/
void num_sortRecords()
{
	int i = 0;
	int j = 0;

	StuInfo stemp;
	int count = 0;   //��¼�ڴ����ж��ټ�¼
	count = countRecords();
	for(i=0; i<count-1; i++)
		for(j=i+1; j<count; j++)
		{
			if( strcmp(records[i].num, records[j].num) > 0 )
			{
				copyRecord(&records[i], &stemp);
				copyRecord(&records[j], &records[i]);
				copyRecord(&stemp, &records[j]);
			}
		}
}

/*
����: ����,���ڴ��еļ�¼����������
����ֵ:void
*/
void name_sortRecords()
{
	int i = 0;
	int j = 0;

	StuInfo stemp;
	int count = 0;   //��¼�ڴ����ж��ټ�¼
	count = countRecords();
	for(i=0; i<count-1; i++)
		for(j=i+1; j<count; j++)
		{
			if( strcmp(records[i].name, records[j].name) > 0 )
			{
				copyRecord(&records[i], &stemp);
				copyRecord(&records[j], &records[i]);
				copyRecord(&stemp, &records[j]);
			}
		}
}