
/*
	本文件中函数功能为：查找及修改学生记录
*/

#include "student.h"


/*
功能:按姓名查找记录
参数: 姓名name,from 从第几个开始查找, 从0 到 count-1
返回值: int 型, 找到的记录在表中的位置, 没有找到则返回-1
打印: 无
*/
int name_findRecord(char *name, int from)
{
	int count = 0; //内存中学生记录数
	int index = -1;  // 位置标记
	int i = 0;
	int flag = 0; //找到与否的标志，找到记录后为1
	count = countRecords(); //调用记录统计函数，得出内存中当前的记录的条数
	for(i=from; i<count; i++)
	{
		if( strcmp(records[i].name, name) == 0 )  //将内存中的记录逐条与要查找的记录比较
		{
			flag = 1;       // 如果找到则flag置为1
			index = i + 1; // index 为该记录在内存中的位置，以1为起始
			break;          //退出循环
		}
	}

	if(flag == 0) // flag为0则表示没有找到指定的记录
	{
		return (index); 
	}
	else
		return (index);
}

/*
功能:按学号查找记录
参数: 姓名name,from 从第几个开始查找, 从0 到 count-1
返回值: int 型, 找到的记录在表中的位置, 没有找到则返回-1
打印: 无
*/
int num_findRecord(char *num, int from)
{
	int count = 0;
	int index = -1;
	int i = 0;
	int flag = 0; //找到与否的标志
	count = countRecords();
	for(i=from; i<count; i++)
	{
		if( strcmp(records[i].num, num) == 0 )  // 按指定的学号来查询
		{
			flag = 1;
			index = i + 1;
			break;
		}
	}

	if(flag == 0)
	{
		return (index);
	}
	else
		return (index);

}
/*
功能:按名次查找记录
参数: 姓名name,from 从第几个开始查找, 从0 到 count-1
返回值: int 型, 找到的记录在表中的位置, 没有找到则返回-1
打印: 无
*/
int rank_findRecord(int rank, int from)
{
	int i;
	int index = -1;
	int flag = 0;
	int count = countRecords();
	rank_Refresh();
	for(i=from; i<count; i++)
	{
		if( records[i].rank == rank)  // 按指定的名次来查询
		{
			flag = 1;
			index = i + 1;
			break;
		}
	}

	if(flag == 0)
	{
		return (index);
	}
	else
	{
		return (index);

	}
}


/*
功 能：查找指定的记录。
参 数：char* target：欲查找记录的某一项与target相同
int targetType：表明通过哪一项来查找，0为学号，1为姓名，2为名次
int from：从第from个记录开始找
返 回 值：int找到的记录的序号，若找不到则返回-1。
工作方式：根据给定的关键字，查找符合记录的序号。
打印 :无
*/
int findRecord(char*target, int targetType, int from)
{
	int index = -1;  // 初始化为－1， 若找不到则为－1
	int rank;  //因为target 为字符串形式,调用rank_findRecord时要转成十进制形式
	switch(targetType)
	{
		case 0:
			index = num_findRecord(target, from);  // 通过学号来查找
			break;
		case 1:
			index = name_findRecord(target, from);  //通过姓名来查找
			break;
		case 2:
			rank = target[0] - '0';  // 因为输入的排名的是字符串的形式，所以先将其转化成整数形式
			index = rank_findRecord(rank, from);  // 通过排名来查找
			break;
	}

	return (index);
}

/*
功 能：按要求查询指定学生信息 菜单函数
参 数：无
返 回 值：void
工作方式：可以按照学号、姓名或名次来查询。
*/
void queryInfo()
{
	do
	{
		system("cls"); // 清屏
		int choice;    //菜单选择参数
		char name[20]; 
		char num[15];
		int rank;
		int index;
		PRHEAD;
		printf("                                 查询学生记录\n\n\n");
		printf("                                1. 按学号查询\n\n");
		printf("                                2. 按姓名查询\n\n");
		printf("                                3. 按名次查询\n\n");
		printf("                                0. 返回主菜单\n\n");
		choice = menu_select(0,3);
		printf("\n");
		switch(choice)
		{
		case 1:
			printf("请输入学号:");
			scanf("%s", num);  //输入要查询的学号
			index = num_findRecord(num,  0);
			printf("\n");
			if(index == -1)  // 若index为－1则表示没有找到指定的记录
				printf("没有找到相关记录!\n");
			else
			{
				showTable();
				PR(index-1);  //宏定义， 将查询到的信息打印出来
			}
			break;
		case 2:
			printf("请输入姓名:");
			scanf("%s", name); //输入要查询的姓名
			index = name_findRecord(name,  0);
			printf("\n");
			if(index == -1)
				printf("没有找到相关记录!\n");
			else
			{
				showTable();
				PR(index-1);  //宏定义， 将查询到的信息打印出来
			}
			break;
		case 3:
			printf("请输入名次:");
			scanf("%d", &rank);  // 输入要查询的名次
			index = rank_findRecord(rank,  0);
			printf("\n");
			if(index == -1)
				printf("没有找到相关记录!\n");
			else
			{
				showTable();
				PR(index-1); //宏定义， 将查询到的信息打印出来  
			}
			break;
		case 0:
			break;
		}
		printf("\n是否继续查询(y/n)? ");
	}while(isContinue());
}


/*
功能：修改指定的记录，有确认功能，修改前打印出原记录，可以选择修改单独的一项，也可以选择修改全部，按回车则表示不修改
参数:des指向指定记录
返回:void
*/
void pmodify(StuInfo *des)
{
	int choice;
	char ctemp[20];
	system("cls");
	PRHEAD;
	printf("选择修改项目: \n\n\n");
	printf("                             1. 姓名\n");
	printf("                             2. 学号\n");
	printf("                             3. 性别\n");
	printf("                             4. English\n");
	printf("                             5. math\n");
	printf("                             6. physics\n");
	printf("                             7. 修改全部\n");

	choice = menu_select(1, 7);
	switch(choice)
	{
	case 1:
			strcpy(ctemp, des->name);
			printf("\n原学生姓名：%s\n", des->name);
			printf("\n请输入新学生姓名(回车则不修改):");
			fflush(stdin);  // 先清空输入缓存
			gets(des->name);
			if('\0' == des->name[0])  // 判断输入的是否是回车
			{
				strcpy(des->name, ctemp);
			}
		break;

	case 2:
			strcpy(ctemp, des->num); //保存原记录到ctemp 中
			printf("\n原学生学号：%s\n", des->num);	
			do{
				printf("\n请输入新十位学生学号(Uxxxxxxxxx)(回车则不修改):");
				fflush(stdin);
				gets(des->num);
				if('\0' == des->num[0])
				{
					strcpy(des->num, ctemp);  // 若是输入回车则不修改记录
					break;
				}
				do
				{
					if( 10 != strlen(des->num) || des->num[0] != 'U') // 判断输入的学号是否合法
					{
						printf("\n请输入正确的十位学生学号，并以'U'开头(如U201014072):");
						fflush(stdin);
						gets(des->num);
						if('\0' == des->num[0])
						{
							strcpy(des->num, ctemp); // 若是输入回车则不修改记录
							break;
						}
					}
				}while( 10 != strlen(des->num) || (des->num[0] != 'U')); // 若是输入不合法则重新输入
			}while(dunum(des));  //用dunum(des)判断输入的学号是否与内存中现有的学号重复，重复则给出提示，并重新输入
		break;

	case 3:
			strcpy(ctemp, des->sex);
			printf("\n原学生性别：%s\n", des->sex);
			printf("\n请输入新学生性别(男/女)(回车则不修改):");
			fflush(stdin);
			gets(des->sex);
			if('\0' == des->sex[0])
			{
				strcpy(des->sex, ctemp);
			}

			do
			{
				if( strcmp(des->sex, "男") != 0 && strcmp(des->sex, "女") != 0 )
				{
					printf("\n请输入正确的性别(男/女):");
					fflush(stdin);
					gets(des->sex);
					if('\0' == des->sex[0])
					{
						strcpy(des->sex, ctemp);
						break;
					}
				}
			}while(strcmp(des->sex, "男") != 0 && strcmp(des->sex, "女") != 0);
		break;

	case 4:
			printf("\n原学生English成绩：%-5.1f\n", des->sco.English);
			printf("\n输入新Englih成绩(0 ~ 100)(回车则不修改):");
			scoInput(des, 1);  // 用scoInput确定分数输入的合法性
			des->total  =des->sco.English  + des->sco .math + des->sco .physics;
			rank_Refresh();
		break;

	case 5:
			printf("\n原学生math成绩：%-5.1f\n", des->sco.math);
			printf("\n输入新math成绩(0 ~ 100)(回车则不修改): ");
			scoInput(des, 2);
			des->total  =des->sco.English  + des->sco .math + des->sco .physics;
			rank_Refresh();
		break;

	case 6:
			printf("\n原学生physics成绩：%-5.1f\n", des->sco.physics);
			printf("\n输入新physics成绩(0 ~ 100)(回车则不修改):");
			scoInput(des, 3);
			des->total  =des->sco.English  + des->sco .math + des->sco .physics;
			rank_Refresh();
		break;

	case 7:  // 综合前面6项
			strcpy(ctemp, des->name);
			printf("\n原学生姓名：%s\n", des->name);
			printf("\n请输入新学生姓名(回车则不修改):");
			fflush(stdin);
			gets(des->name);
			if('\0' == des->name[0])
			{
				strcpy(des->name, ctemp);
			}


			strcpy(ctemp, des->num);
			printf("\n原学生学号：%s\n", des->num);	
			do{
				printf("\n请输入新十位学生学号(Uxxxxxxxxx)(回车则不修改):");
				fflush(stdin);
				gets(des->num);
				if('\0' == des->num[0])
				{
					strcpy(des->num, ctemp);
					break;
				}
				do
				{
					if( 10 != strlen(des->num) || des->num[0] != 'U')
					{
						printf("\n请输入正确的十位学生学号，并以'U'开头(如U201014072):");
						fflush(stdin);
						gets(des->num);
						if('\0' == des->num[0])
						{
							strcpy(des->num, ctemp);
							break;
						}
					}
				}while( 10 != strlen(des->num) || (des->num[0] != 'U'));
			}while(dunum(des));

			strcpy(ctemp, des->sex);
			printf("\n原学生性别：%s\n", des->sex);
			printf("\n请输入新学生性别(男/女)(回车则不修改):");
			fflush(stdin);
			gets(des->sex);
			if('\0' == des->sex[0])
			{
				strcpy(des->sex, ctemp);
			}

			do
			{
				if( strcmp(des->sex, "男") != 0 && strcmp(des->sex, "女") != 0 )
				{
					printf("\n请输入正确的性别(男/女):");
					fflush(stdin);
					gets(des->sex);
					if('\0' == des->sex[0])
					{
						strcpy(des->sex, ctemp);
						break;
					}
				}
			}while(strcmp(des->sex, "男") != 0 && strcmp(des->sex, "女") != 0);

			printf("\n原学生English成绩：%-5.1f\n", des->sco.English);
			printf("\n输入新Englih成绩(0 ~ 100)(回车则不修改):");
			scoInput(des, 1);

			printf("\n原学生math成绩：%-5.1f\n", des->sco.math);
			printf("\n输入新math成绩(0 ~ 100)(回车则不修改): ");
			scoInput(des, 2);

			printf("\n原学生physics成绩：%-5.1f\n", des->sco.physics);
			printf("\n输入新physics成绩(0 ~ 100)(回车则不修改):");
			scoInput(des, 3);

			des->total = des->sco.English  + des->sco .math + des->sco .physics;
			rank_Refresh();

		break;
	}
}

/*
修改指定学生信息菜单函数
功 能：找到指定记录并修改
参 数：void
返 回 值：void
工作方式：可以按照学号、姓名或名次找到要修改的记录，确认后方可修改。
*/

void modifyRecord()
{

	int choice;
	char name[20];   // 指定的姓名
	char num[15];    //指定的学号
	int rank;             //指定的排名
	int index;         // 指定记录的序号
do{
			system("cls");
			PRHEAD;
			printf(" 修改学生记录: \n\n\n");
			printf("                            1. 按学号查询修改\n\n");
			printf("                            2. 按姓名查询修改\n\n");
			printf("                            3. 按名次查询修改\n\n");
			printf("                            0. 返回主菜单\n\n");

			choice = menu_select(0, 3);
			printf("\n");

		switch(choice)
			{
			case 1:
				printf("请输入要查询的学号(Uxxxxxxxxx):");
				scanf("%s", num);
				index = num_findRecord(num,  0); //查找
				printf("\n");
				if(index == -1)
					printf("没有找到相关学生记录!\n\n");  //找不到则给出提示
				else
				{
					index_disPlay(index);
					printf("\n");
					printf("确认修改记录(y/n)? ");
					printf("\n");
					if( isContinue() )
					{
						pmodify(&records[index-1]);
					}
				}
		break;
	case 2:
		printf("请输入姓名:");
		scanf("%s", name);
		index = name_findRecord(name,  0);
		printf("\n");
		if(index == -1)
			printf("没有找到相关记录!\n\n");
		else
		{
			index_disPlay(index);
			printf("\n");
			printf("确认修改记录(y/n)? ");
			printf("\n");
			if( isContinue() )
			{
				pmodify(&records[index-1]);
			}
		}
		break;
	case 3:
		printf("请输入名次:");
		scanf("%d", &rank);
		index = rank_findRecord(rank,  0);
		printf("\n");
		if(index == -1)
			printf("没有找到相关记录!\n");
		else
		{
			index_disPlay(index);
			printf("\n");
			printf("确认修改记录(y/n)? ");
			printf("\n");
			if( isContinue() )
			{
				pmodify(&records[index-1]);
			}
		}
		break;
	case 0:
		break;
	}
	printf("\n是否继续修改学生记录(y/n)?");
}while( isContinue() );
	total_sortRecords();
}
