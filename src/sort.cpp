
/*
	本文件中函数功能为：按总分、学号、姓名排序学生记录
*/

#include "student.h"


/*
功能: 排序,将内存中的记录按总分排名,分数高的在前
返回值:void
*/
void total_sortRecords()
{
	int i = 0;
	int j = 0;
	StuInfo stemp;
	int count = 0;   //记录内存中有多少记录
	count = countRecords();
	/*选择法 排序 */
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
功能: 排序,将内存中的记录按学号排序,学号高低的在前
返回值:void
*/
void num_sortRecords()
{
	int i = 0;
	int j = 0;

	StuInfo stemp;
	int count = 0;   //记录内存中有多少记录
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
功能: 排序,将内存中的记录按姓名排序
返回值:void
*/
void name_sortRecords()
{
	int i = 0;
	int j = 0;

	StuInfo stemp;
	int count = 0;   //记录内存中有多少记录
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