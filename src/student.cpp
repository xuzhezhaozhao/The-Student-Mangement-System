
/*
	本文件中函数功能为：程序入口主函数，主菜单界面函数
*/


#include "student.h"
StuInfo *records;  // 学生信息数组
int arrSize;  // 数据库大小，当大小不够时，每次自动增加INCR_SIZE

/*
主函数
*/

int main()
{
	system("color 1e"); // 设置前景背景颜色
	
	arrSize = INITIAL_SIZE;
	initial();
//	welcome();
	handle_menu();

	return 0;
}

/*
功能：打印欢迎界面
参数：无
返回：void
*/
void welcome()
{
	PRHEAD;
	PRROW6;
	printf("                            欢迎光临学生管理系统！");
	PRROW7;
	system("pause");

}

/*
菜单处理函数
功 能：处理选择的菜单命令。
参 数：无
返 回 值：void
工作方式：根据所选择的对应的命令，调用相应的函数
*/
void handle_menu()
{			
	int menu;        //选择菜单的参数
	int child_menu; // 子菜单选择参数
	do{
			system("cls");
		//	system("Mode con: COLS=85 LINES=30");
			PRHEAD;
			printf("   学生管理系统 2.00 版   ");
			printf("\n");
			printf("                             1. 新建一个学生信息库 \n\n");
			printf("                             2. 查询及修改学生信息 \n\n");
			printf("                             3. 添加及删除学生信息\n\n");
			printf("                             4. 排序显示学生信息\n\n");
			printf("                             5. 保存及导入学生信息\n\n");
			printf("                             6. 清空当前内存记录\n\n");
			printf("                             7. 成绩分析\n\n");
			printf("                             8. 帮助\n\n");
			printf("                             0. 退出系统\n\n");
		
			menu = menu_select(0, 8); 

			switch(menu)
		{
				case 1:
					newRecords();
					printf("\n是否回到主菜单(y/n)? ");
			break;
				case 2:
					system("cls");
					PRHEAD;
					printf(" 查询及修改记录: \n\n\n\n");
					printf("                            1. 查询记录\n\n");
					printf("                            2. 修改记录\n\n");
					printf("                            0. 返回主菜单\n\n");
					
					child_menu = menu_select(0, 2);
					switch(child_menu)
					{
					case 1:
						queryInfo();
						break;
					case 2:
						modifyRecord();
						break;
					case 0:
						break;
					}
					printf("\n是否回到主菜单(y/n)? ");
			break;
				case 3:
					system("cls");
					PRHEAD;
					printf(" 添加及删除记录: \n\n\n\n");
					printf("                      1. 添加记录（追加在内存记录之后）\n\n");
					printf("                      2. 删除记录\n\n");
					printf("                      0. 返回主菜单\n\n");

					child_menu = menu_select(0, 2);
					switch(child_menu)
					{
					case 1:
						addRecord();
						break;
					case 2:
						removeRecord();
						break;
					}
					printf("\n是否回到主菜单(y/n)? ");
			break;
				case 4:
					sort_disPlay();
					printf("\n是否回到主菜单(y/n)? ");
			break;
				case 5:
					 out_loadRecords();
					printf("\n是否回到主菜单(y/n)? ");
			break;
				case 6:
					system("cls");
					PRHEAD;
					initial();
					printf("\n清空内存记录成功！\n\n");
					printf("是否回到主菜单(y/n)? ");
					break;
				case 7:
					system("cls");
					PRHEAD;
					average();
					printf("\n");
					subfail();
					printf("\n是否回到主菜单(y/n)? ");
					break;
				case 8:
					showHelp();
					printf("\n是否回到主菜单(y/n)? ");
			break;	
				case 0:
					quit();
			break;
		}
	}while( isContinue() );

	system("cls");
	PRHEAD;
	printf(" 退出学生管理系统: \n\n\n");

	if(0 != countRecords())
	{
		printf(" 您将退出学生管理系统, ");
		printf("退出前是否保存当前内存中的记录到指定文件(y/n)? ");
		if( isSave() )
		{
			printf("\n");
			saveRecords();
		}
	}

	printf(" \n\n成功退出学生管理系统! \n\n");
	system("pause");
}


/*
结束程序运行函数
功 能：结束程序运行。
参 数：无
返 回 值：void
工作方式：根据要求决定在退出前是否将修改的记录存人文件,结束运行之前，询问是否对修改的记录进行存储。
*/
void quit()
{
	system("cls");
	PRHEAD;
	int count;
	count = countRecords();
	printf("退出学生管理系统:\n\n\n\n");
	if(0 != count) // 如果内存中存在记录，则提示是否先保存记录，否则直接退出
	{
		printf("退出前是否存储内存中的记录到指定文件(y/n)?");
		if( isSave() )
		{
			printf("\n");
			saveRecords();
		}
	}
	printf(" \n\n成功退出学生管理系统! \n\n");
	system("pause");
	exit(0);
}