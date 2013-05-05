
/*
	本文件中函数功能为：容错设置，判断有关输入是否合法，不合法则给出提示，并判断数据库大小是否足够，不够的话没自动增加
*/

#include "student.h"


/*
功能：判断输入的性别是否合法,若不合法则给出提示，并重新输入
参数：学生
返回：void
*/
void numInput(StuInfo *stu)
{

	fflush(stdin);
	gets(stu->num);

	do
	{
		if( strlen(stu->num) != 10 || stu->num[0] != 'U')
		{
			printf("\n请输入正确的十位学生学号，并以'U'开头(如U201014072):");
			fflush(stdin);
			gets(stu->num);
		}
	}while( strlen(stu->num) != 10 || stu->num[0] != 'U');
}

/*
功能：判断输入的性别是否合法,若不合法则给出提示，并重新输入
参数：学生
返回：void
*/
void sexInput(StuInfo *stu)
{
	scanf("%s", stu->sex);

	do
	{
		if( strcmp(stu->sex, "男") != 0 && strcmp(stu->sex, "女") != 0 )
		{
			printf("\n请输入正确的性别(男/女):");
			scanf("%s", stu->sex);
		}
	}while(strcmp(stu->sex, "男") != 0 && strcmp(stu->sex, "女") != 0);
}

/*
功能：判断输入的分数是否在0 ~ 100以内，若不是则给出相应提示并重新输入
参数：StuInfo 学生, int choice ,1表示输入English, 2 表示math, 3 表示 physics
返回：void
*/
void scoInput(StuInfo *stu, int choice)
{
	switch(choice)
	{
	case 1:	
		scanf("%f", &stu->sco.English);
		do
		{
			if(stu->sco.English < 0 || stu->sco.English > 100 )
			{
				printf("\n请输入正确的English分数(0 ~ 100):");
				scanf("%f", &stu->sco.English);
			}
		}while( stu->sco.English < 0 || stu->sco.English > 100 );
		break;
	case 2:
		scanf("%f", &stu->sco.math);
		do
		{
			if(stu->sco.math < 0 || stu->sco.math > 100 )
			{
				printf("\n请输入正确的math分数(0 ~ 100):");
				scanf("%f", &stu->sco.math);
			}
		}while( stu->sco.math < 0 || stu->sco.math > 100 );
		break;
	case 3:
		scanf("%f", &stu->sco.physics);
		do
		{
			if(stu->sco.physics < 0 || stu->sco.physics > 100 )
			{
				printf("\n请输入正确的physics分数(0 ~ 100):");
				scanf("%f", &stu->sco.physics);
			}
		}while( stu->sco.physics < 0 || stu->sco.physics > 100 );
		break;
	}

}

/*
功能：判断新增加的学生的学号是否与内存中已有的学生学号冲突，冲突时给出提示
参数：要判断的学生
返回：当没有与其他学生重复时返回0，有重复时返回1
*/
int dunum(StuInfo *stu)
{
	int count = countRecords();
	int i;
	int flag = 0;
	int du = 0;  // 要判断的学生的学号与已有学生学号（包括自己）相比较，学号重复的次数，若du最后大于或等于2，则说明有重复
	for(i=0; i<count; i++)
	{
		if( strcmp(stu->num, records[i].num) == 0)
		{
			++du;
		}
	}

	if(du == 2 || du > 2)
	{
		printf("\n输入的学号与其他学生重复!\n");
		flag = 1;
	}

	return flag;
}

/* 
功能: 判断用户是否想继续当前操作,输入为y或Y,返回YES, 输入n或N,返回NO
参数: 无
返回: YES表示想继续操作, NO表示不继续当前操作,不打印信息
*/
int isContinue()
{
	char select;

	while(1)
	{	
		fflush(stdin);
		scanf("%c", &select);
		if ( 'y' == select || 'Y' == select )
				return YES; //宏定义
			else if( 'n' == select || 'N' == select )
				return NO; 
			printf("请输入y或n!\n");
	}
}

/* 
功能: 判断用户是否想保存当前数据
参数: 无
返回: YES 表示保存, NO表示不保存, 不打印信息
*/
int isSave()
{
	char select;

	while(1)
	{	
		fflush(stdin);
		scanf("%c", &select);
		if ( 'y' == select || 'Y' == select )
				return YES; //宏定义
			else if( 'n' == select || 'N' == select )
				return NO; 
			printf("请输入y或n!\n");
	}
}

/*
功 能： 判断输入的选择序号是否合法
参 数： select_min, 可选择的序号最小值,select_max,可选择的序号的最大值
返 回 值： 用户输入的选择序号的整数值
工作方式：
*/
int menu_select(int select_min, int select_max)
{
	printf("请输入选择(%d ~ %d): ", select_min, select_max);
	char select;
	fflush(stdin);
	scanf("%c", &select);
	
	while( (select>select_max+'0') || (select<select_min+'0') )
	{
		printf("\n输入的数值错误,请重新输入一个在%d ~ %d 的整数: ", select_min, select_max);
		fflush(stdin);
		scanf("%c", &select);
	}
	return select-'0';
}

/*
功能：判断内存数组是否大小不够，不够的话自动增大INCR_SIZE
参数：无
返回：无
打印：使用条件编译，若定义了DEBUG则打印“数据库自动增大成功, 当前数据库大小为%d!”，便于调试
*/
void autoIncr()
{
	int count = countRecords();
	if(count >= arrSize)
	{
		records = (StuInfo*) realloc( records, (arrSize+INCR_SIZE)*sizeof(StuInfo) ); // 当数据库大小不够时，每次自动增加INCR_SIZE
		if(records == NULL)
		{
			printf("memory failed!");
			exit(-1);
		}
		arrSize = arrSize + INCR_SIZE;

		#ifdef DEBUG
		{
			printf("\n数据库自动增大成功, 当前数据库大小为%d! \n", arrSize);
		}
		#endif
	}


}