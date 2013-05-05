
/*
	本文件中函数功能为：初始化内存及统计学生记录数及学生排名信息
*/


#include "student.h"

/*
  初始化内存记录函数
功能:将内存中的记录初始化, 即清零
参数: 无
打印: 无
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
		records[i].savetag = 0;  // 将内存中记录清空
	}
}

/*	
功能: 统计内存中有多少条记录
返回:记录的条数
打印:   无       
*/
int countRecords()
{
	int i = 0;
	int count = 0;   //记录内存中有多少记录
	while(records[i].savetag == 1)
		i++;
	count = i;   // 内存中的记录数
	return (count);
}



/*
功能：得到学生的排名信息
参数：stu为一条学生记录
返回值：该学生排名的整数值
打印：无
*/
int getRank(StuInfo stu)
{
	int i = 0;
	int j = 0;
	int rank = 1; // 排名信息
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
			rank++;  // 有比该记录大的学生时则 名次rank加1
		}
	}

	return(rank);
}

/*
功能：当内存中数据变化时，刷新排名信息
参数：无
返回：void
打印：无
*/
void rank_Refresh()
{
	int i = 0;
	for(i=0; i<countRecords(); i++)
	{
		records[i].rank = getRank(records[i]);
	}
}