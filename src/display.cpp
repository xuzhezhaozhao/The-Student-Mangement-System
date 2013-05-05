
/*
	本文件中函数功能为：打印相关学生记录
*/


#include "student.h"


/*
功 能：打印表头
参 数：void
返 回 值：void
工作方式：输出一行表头信息。
*/
void showTable(void)
{
	printf("       姓名        学号        性别    math  English  physics  总分     排名\n");
	printf("\n");
}

/*
功 能：显示内存里的记录信息。
参 数：无
返 回 值：void
工作方式：从头部开始逐个显示记录内容, 没有记录则 打印 "没有记录" 
*/
void disPlay()
{
	system("cls");  // 清屏
	PRHEAD;
	rank_Refresh();
	printf(" 显示学生信息: \n\n");
	showTable();
	int i = 0;
	while(records[i].savetag == 1)
	{
		PR(i);
		i++;
	}
	if(i == 0)
		printf("没有记录!\n");
}

/*
功能:根据指定的序号显示出记录信息
参数:index,指定的序号
返回:void
指定的序号不存在时给出找不到的信息
*/
void index_disPlay(int index)
{
	int count = countRecords();
	if( index >  count )   // 输入不合法时
	{
		printf("内存中没有该杀记录!\n");
	}

	else if( index < 1 ) // 输入不合法时
		printf("给定的序号不能为0或负数!\n");

	else
	{
		if(records[index-1].savetag == 1)
		{
			showTable();
			PR(index-1); // 宏定义
		}
		else
		{
			printf("内存中没有该杀记录!\n"); // 找不到时相应处理
		}
	}
}

/*
输出在记录中按升序排序的位置
功 能：找出总分为sum在第0至numStus-1个记录中按升序排序的位置。
参 数：float，欲找出其位置的总分
返 回 值：int，sum在第0至numStus-1个记录中按升序排序的。
工作方式：查找并计数
打印: 无
*/
int getIndex(float sum)
{
	int i = 0;
	int count = 0;   //记录内存中有多少记录
	int index = 0; // 记录位置
	while(records[i].savetag == 1)
		i++;
	count = i;   // 内存中的记录数
	for(i=0; i<count; i++)
	{
		if(sum>records[i].total)
			index++;
	}
	
	return (index);
}


/*
功能:显示版本及帮助信息
参数:无
返回:void
*/
void showHelp()
{
	system("cls");
	PRHEAD;
	PRROW3;
	int choice;
	printf("                          1.功能简介\n\n");
	printf("                          2.关于\n\n");
	printf("                          0. 返回主菜单\n\n");

	choice = menu_select(0, 2);
	switch(choice)
	{
	case 1:
		system("cls");
		PRHEAD;
		printf("  功能简介: \n\n\n");
		printf(" 学生管理系统\n");
		break;

	case 2:
		system("cls");
		PRHEAD; // 宏定义,打印一排***
		PRROW1;
		printf("                作者：\n");
		printf("                              U201014068  杜林\n\n");
		printf("                              U201014072  徐哲钊\n\n");
		printf("                              U201014055  朱懂斌\n\n");
		printf("                              U201014052  李波\n\n\n");
		printf("                               2012年6月7日\n\n");
		printf("                            学生管理系统2.00版\n\n");
		PRHEAD;
		break;
	case 0:
		break;
	}
}


/*
功能: 可按排名、学号、姓名排序输出记录
参数: 无
返回: void
*/
void sort_disPlay()
{
	system("cls");
	PRHEAD;
	printf(" 显示记录: \n");
	PRROW2;
	int choice;
	printf("                               1. 按排名顺序显示\n\n");
	printf("                               2. 按学号顺序显示\n\n");
	printf("                               3. 按姓名排序显示\n\n");
	printf("                               0. 返回主菜单\n\n\n");

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
