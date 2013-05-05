
/*
	本文件中函数功能为：添加和删除记录
*/


#include "student.h"


/*
记录复制函数
功 能：将src指向的一条记录复制给dest指向的记录。
参 数：StuInfo * src：源记录StuInfo * dest： 目的记录。
返 回 值：void
工作方式：将原记录逐条复制到目的记录。
*/
void copyRecord(StuInfo * src, StuInfo * dest)
{
		strcpy(dest->name, src->name);
		strcpy(dest->num,  src->num);
		strcpy(dest->sex,  src->sex);
		dest->sco.English =  src->sco.English;
		dest->sco.math =  src->sco.math;
		dest->sco.physics = src->sco.physics;
		dest->total =  src->total;  
		dest->rank  = src->rank; 
		dest->savetag = src->savetag; // 逐条复制记录

}


/*
删除记录函数
功 能：删除内存数组中的指定记录, 可以选择以姓名还是学号的方式删除记录。
参 数：无
返 回 值：void
*/
void removeRecord()
{
	int index; // 指定要删除的记录的序号
	do{
			system("cls");  //清屏
			char name[20]; //指定删除记录的姓名
			char num[15];  //指定删除记录的学号
			int rank;      //指定删除记录的名次

			int choice;
			PRHEAD;
			printf("     删除记录 \n\n\n" );
			printf("                            1. 按姓名删除记录\n\n");
			printf("                            2. 按学号删除记录\n\n");
			printf("                            3. 按名次删除记录\n\n");
			printf("                            0. 返回主菜单\n\n");
			choice = menu_select(0, 3);
			printf("\n");
			switch(choice)
			{
				case 1:
					printf("输入要删除的姓名:");
					scanf("%s",name);
					printf("\n");
					index = name_findRecord(name, 0); // 从第0个开始查找，即查找全部

					if(index == -1)
					{
						printf("没有找到要删除的记录!\n\n");
					}
					else
					{
						index_disPlay(index);   // 打印出要删除的记录
						printf("\n");
						printf("确认删除该记录(y/n)? ");
						if( isContinue() )
							name_remove(name);
					}
					break;
				case 2:
					printf("输入要删除的学号:");
					scanf("%s",num);
					printf("\n");
					index = num_findRecord(num, 0);   
					if(index == -1)
					{
						printf("没有找到要删除的记录!\n\n");
					}
					else
					{
						index_disPlay(index);      // 打印出要删除的记录
						printf("\n");
						printf("确认删除该记录(y/n)? ");
						if( isContinue() )
							num_remove(num);
					}
					break;
				case 3:
					printf("输入要删除的名次:");
					scanf("%d", &rank);
					printf("\n");
					index = rank_findRecord(rank, 0);

					if(index == -1)
					{
						printf("没有找到要删除的记录!\n\n");
					}
					else
					{
						index_disPlay(index);     // 打印出要删除的记录
						printf("\n");
						printf("确认删除该记录(y/n)? ");
						if( isContinue() )
						rank_Remove(rank);
					}
					
				case 0:
					break;
			}

			printf("\n是否继续删除记录(y/n)? ");
		}while( isContinue() );

}



/*
功能: 按给定的姓名删除内存中的记录
参数: 给定的姓名name
返回值:void
打印:"没有找到符合的结果!", " 删除成功!"
*/
void name_remove(char name[])
{	
	int i = 0;
	int flag = -1; //作为找到的位置的标记
	int count = 0;   //记录内存中有多少记录
	count = countRecords();
	for(i=0; i<count; i++) 
	{
		if( strcmp(name, records[i].name) == 0)
		{
			flag = i;
			break;
		}
	}
	if(flag == -1)    // flag 为－1则表示没有找到
		printf("没有找到符合的结果!\n");
	else if(flag == (count-1))
	{
		records[flag].savetag = 0;   //如果是最后一位,就把最后一位的flag置为0,相当于删除
		rank_Refresh();  // 排名信息刷新
		printf("\n删除成功!\n");
	}
	else
	{
		for(i=flag; i<count-1;i++)        //后面的前移
		{
			copyRecord(&records[i+1], &records[i]);
		}
		records[count-1].savetag = 0;  
		rank_Refresh();
		printf("\n删除成功!\n");
	}
}

/*
功能:按学号删除内存中的记录
返回值:void
*/
void num_remove(char num[])
{	
	int i = 0;
	int flag = -1; //作为找到的位置的标记
	int count = 0;   //记录内存中有多少记录
	count = countRecords();
	for(i=0; i<count; i++)
	{
		if( strcmp(num, records[i].num) == 0 )
		flag = i;
	}
	if(flag == -1)
		printf("没有找到符合的结果!\n");
	else if(flag == (count-1))
	{
		records[flag].savetag = 0;   //如果是最后一位,就把最后一位的flag置为0,相当于删除
		rank_Refresh();
		printf("\n删除成功!\n");
	}
	else
	{
		for(i=flag; i<count-1;i++)        //后面的前移
		{
			copyRecord(&records[i+1], &records[i]);
		}
		records[count-1].savetag = 0;  
		rank_Refresh();
		printf("\n删除成功!\n");
	}
}

/*
功能：按名次删除内存中的记录
返回值：void
*/
void rank_Remove(int rank)
{
	int i = 0;
	int flag = -1; //作为找到的位置的标记
	int count = 0;   //记录内存中有多少记录
	count = countRecords();
	for(i=0; i<count; i++)
	{
		if(rank == records[i].rank)
		flag = i;
	}
	if(flag == -1)
		printf("没有找到符合的结果!\n");
	else if(flag == (count-1))
	{
		records[flag].savetag = 0;   //如果是最后一位,就把最后一位的flag置为0,相当于删除
		rank_Refresh();
		printf("\n删除成功!\n");
	}
	else
	{
		for(i=flag; i<count-1;i++)        //后面的前移
		{
			copyRecord(&records[i+1], &records[i]);
		}
		records[count-1].savetag = 0;  
		rank_Refresh();
		printf("\n删除成功!\n");
	}
}

/*
功 能：增加记录，将增加的记录追加在数组后面
参 数：无
返 回 值：void
工作方式：从尾部开始逐个追加记录。
打印: "添加成功" , "当前内存中共有%d条记录! "  
*/
void addRecord()
{
	int count = countRecords();
	autoIncr();
	do{
			system("cls");
			PRHEAD;
			printf("  添加学生信息:\n\n");
			records[count].savetag  = 1;  // 添加记录将记录的flag 置为1 , 将其标记为有效信息
			printf("请输入学生姓名:");
			scanf("%s", records[count].name);

			do{
				printf("\n请输入十位学生学号(Uxxxxxxxxx):");
				numInput(&records[count]);  // 用numInput输入学号，若与已有学号重复则会给出提示并重新输入
			}while(dunum(&records[count]));

			printf("\n请输入学生性别(男/女):");
			sexInput(&records[count]);

			printf("\n请输入学生成绩(0 ~ 100):\n\n");
			printf("English(0 ~ 100): ");
			scoInput(&records[count], 1);
			printf("\nmath(0 ~ 100): ");
			scoInput(&records[count], 2);
			printf("\nphysics(0 ~ 100): ");
			scoInput(&records[count], 3);
			records[count].total  = records[count].sco.English  + records[count].sco .math + records[count].sco .physics;
			rank_Refresh();
			
			count++;
			autoIncr(); // 判断是否需要自动增大内存数组

			printf("\n添加成功，");
			printf("当前内存中共有%d条学生记录!\n\n", count);
		
			printf("是否继续添加学生信息(y/n)? ");
	}while ( isContinue() );
}

/*
新建学生信息记录的函数
功 能：重新建立输入信息记录。新建完成之后可提示是否保存
参 数：无
返 回 值：void
工作方式：根据需要调用saveRecords函数。
*/
void newRecords()
{
	system("cls");
	if(records[0].savetag != 0) // 判断内存数组中是否有记录
	{
		PRHEAD;
		PRROW3;
		printf("当前内存中有记录,是否先保存当前数据(y/n)? ");
		if( isSave() )
			saveRecords();
		printf("\n\n");
		system("pause");
	}
	initial(); // 初始化内存数组

		system("cls");
		PRHEAD;
		printf(" 新建一个学生信息库: \n\n\n");
		addRecord();

	printf("\n是否保存新建的学生信息(y/n)? ");
	if( isSave() )
		saveRecords();
}

