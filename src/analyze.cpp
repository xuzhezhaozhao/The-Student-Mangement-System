
/*
	���ļ��к�������Ϊ������ѧ���ɼ�
*/


#include "student.h"


/*
���ܣ�ͳ�Ƹ��Ƴɼ���ƽ���֣�����ӡ����
��������
���أ�void
��ӡ����ӡ������ƽ�������
*/

void average()
{
	printf("\n �ɼ�������\n\n");
	int count;
	int i;
	float math_sum = 0;
	float Eng_sum = 0; 
	float physics_sum = 0;
	float total_sum = 0;
	float math_avg, Eng_avg, physics_avg, total_avg;
	count = countRecords(); // �ڴ��еļ�¼��

	if(count > 0)   //����ڴ����м�¼
	{
		for(i=0; i<count; i++)
		{
			math_sum = math_sum + records[i].sco.math;
			Eng_sum = Eng_sum + records[i].sco.English;
			physics_sum = physics_sum + records[i].sco.physics;
			total_sum = total_sum + records[i].total;
		}

		math_avg = math_sum / count;
		Eng_avg = Eng_sum / count;
		physics_avg = physics_sum / count;
		total_avg = total_sum / count;    // �����ƽ����

		printf("����ƽ����:       math        English       physics     ��ƽ����\n\n");
		printf("            %10.2lf%15.2lf%12.2lf%10.2f\n", math_avg, Eng_avg, physics_avg, total_avg);
	}

	else
	{
		printf("��ǰ�ڴ���û�гɼ���¼��\n");
	}

}

/*
���ܣ�ͳ�Ƹ��ƹҿ�����
��������
���أ���
��ӡ�����ƹҿ�����
*/
void subfail()
{
	int count;
	int i;
	int Engfail = 0;
	int mathfail = 0;
	int physicsfail = 0;
	int stufail = 0;
	count = countRecords();
	if(count > 0)   //����ڴ����м�¼
	{
		for(i=0; i<count; i++)
		{
			if( records[i].sco.English<60 || records[i].sco.math<60 || records[i].sco.physics<60 )
				stufail++;
			if( records[i].sco.English<60 )
				Engfail++;
			if( records[i].sco.math<60 )
				mathfail++;
			if( records[i].sco.physics<60 )
				physicsfail++;
		}

		printf("���ƹҿ�����:     math        English       physics     �ҿ�����\n\n");
		printf("           %10.2ld%15.2ld%12.2ld%10.2d\n", mathfail, Engfail, physicsfail, stufail);
	}

	else
	{	
		printf("��ǰ�ڴ���û�гɼ���¼��\n");
	}

}