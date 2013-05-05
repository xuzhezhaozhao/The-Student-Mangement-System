
/*
	本文件中函数功能为：分析学生成绩
*/


#include "student.h"


/*
功能：统计各科成绩的平均分，并打印出来
参数：无
返回：void
打印：打印出各科平均分情况
*/

void average()
{
	printf("\n 成绩分析：\n\n");
	int count;
	int i;
	float math_sum = 0;
	float Eng_sum = 0; 
	float physics_sum = 0;
	float total_sum = 0;
	float math_avg, Eng_avg, physics_avg, total_avg;
	count = countRecords(); // 内存中的记录数

	if(count > 0)   //如果内存中有记录
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
		total_avg = total_sum / count;    // 求各科平均分

		printf("各科平均分:       math        English       physics     总平均分\n\n");
		printf("            %10.2lf%15.2lf%12.2lf%10.2f\n", math_avg, Eng_avg, physics_avg, total_avg);
	}

	else
	{
		printf("当前内存中没有成绩纪录！\n");
	}

}

/*
功能：统计各科挂科人数
参数：无
返回：无
打印：各科挂科人数
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
	if(count > 0)   //如果内存中有记录
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

		printf("各科挂科人数:     math        English       physics     挂科人数\n\n");
		printf("           %10.2ld%15.2ld%12.2ld%10.2d\n", mathfail, Engfail, physicsfail, stufail);
	}

	else
	{	
		printf("当前内存中没有成绩纪录！\n");
	}

}