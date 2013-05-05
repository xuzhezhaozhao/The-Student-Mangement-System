
/*
	本文件中函数功能为: 保存及导出学生记录
*/


#include "student.h"


/*
功 能：将记录存入当前文件夹下的默认文件stu info中或者指定文件中。
参数: 无  
返回值：成功0，失败-1
工作方式：数组records被保存至指定文件。
打印: 失败打印"Saving records is wrong!",  成功则打印"%d条记录存储成功!"
 */
int saveRecords()  //保存记录模块
{
	FILE *fp;
	int i = 0;
	int count = 0;   //记数,记录保存了多少条记录
	char filename[20]; // 要保存到的文件名
	printf("\n输入保存文件名\n\n");
	printf("(回车表示保存到默认文件stu info中):");
	fflush(stdin); //清空输入缓存
	gets(filename); // 输入文件名
	
	if('\0' == filename[0] ) // 如果输入回车时，则按默认处理
	{
		
		if( (fp = fopen("stu info","wb+") ) == NULL )
		{
			printf("Opening file is wrong!\n");
			return -1;   // 打开失败则返回-1
		}

		while ( records[i].savetag == 1)   //当flag为1时表明记录存在
		{
			if( fwrite(&records[i], sizeof(StuInfo), 1, fp) != 1 )
			{
				printf("Saving records is wrong!\n");
				return -1;             //写入失败返回-1
			}
			else
			{
				i++;
				count++;   //保存成功则记数器加1
			}
		}
		fclose(fp);
		printf("\n%d条记录存储成功!\n", count);
	}

	else
	{
		if( (fp = fopen(filename,"wb+") ) == NULL )
		{
			printf("Saving records ss is wrong!\n");
			return -1;   // 打开失败则返回-1
		}

		while ( records[i].savetag == 1)   //当flag为1时表明记录存在
		{
			if( fwrite(&records[i], sizeof(StuInfo), 1, fp) !=1 )
			{
				printf("Saving records is wrong!\n");
				return -1;             //写入失败返回-1
			}
			else
			{
				i++;
				count++;   //保存成功则记数器加1
			}
		}
		fclose(fp);
		printf("\n%d条记录存储成功!\n", count);
	}

	
	return 0;
}

/* 
功 能：将默认文件stu info或者指定文件里的记录取人内存。
参 数:无
返 回 值：成功0，失败-1
工作方式：records将为从指定文件中读取出的记录,将会覆盖当前内存中的记录
打印: 文件不存在时打印 "暂无记录可读取!", 读取成功则打印 "读取了%d条记录!" 
*/
int loadRecords()
{
	system("cls");
	FILE *fp;
	int count = 0;
	char filename[20];
	PRHEAD;
	printf(" 导入文件: \n\n\n");
	printf("输入要导入的文件名\n\n");
	printf("回车表示导入默认文件stu info:");
	fflush(stdin);
	gets(filename);

	if('\0' == filename[0] )
	{
		initial(); // 导入数据之前先初始化内存
		if((fp=fopen("stu info","rb"))==NULL)
		{
			printf("\n暂无记录可读取!\n");
			return -1 ;
		}
		while(feof(fp)==0)
		{
			if( fread(&records[count],sizeof(StuInfo),1,fp) != 1) 
				break;
			count++;
			autoIncr();
		}
	}

	else
	{
		initial(); // 导入数据之前先初始化内存
		if((fp=fopen(filename,"rb"))==NULL)
		{
			printf("\n暂无记录可读取!\n");
			return -1 ;
		}
		while(feof(fp)==0)
		{
			if( fread(&records[count],sizeof(StuInfo),1,fp) != 1) 
				break;
			count++;
			autoIncr();
		}
	}
	
	fclose(fp);
	printf("\n读取成功，%d条记录读到内存中!\n", count);
	return(0);
}


/*
功能: 从文件导入记录到内存中,并追加在记录未尾
参 数:无
返 回 值：成功0，失败-1
*/
int loadaddRecords()
{
	system("cls");
	FILE *fp;

	int count = countRecords();
	char filename[20];
	PRHEAD;
	printf(" 导入文件(追加): \n\n\n");
	printf("输入要导入的文件名\n\n");
	printf("回车表示导入默认文件stu info:");
	fflush(stdin);
	gets(filename);

	if('\0' == filename[0] )
	{
		if((fp=fopen("stu info","rb"))==NULL)
		{
			printf("\n暂无记录可读取!\n");
			return -1 ;
		}

		while(feof(fp)==0)
		{
			if( fread(&records[count],sizeof(StuInfo),1,fp) != 1) 
				break;

			count++;
			autoIncr();
		}
	}

	else
	{
		if((fp=fopen(filename,"rb"))==NULL)
		{
			printf("\n暂无记录可读取!\n");
			return -1 ;
		}

		while(feof(fp)==0)
		{
			if( fread(&records[count],sizeof(StuInfo),1,fp) != 1) 
				break;
			count++;
			autoIncr();
		}
	}
	fclose(fp);
	printf("\n读取成功，%d条记录追加到内存中!\n", count);
	return(0);
}

/*
功能:从文件导入记录 或从内存导出记录 菜单函数
返 回 值：成功0，失败-1
*/
int out_loadRecords()
{
	int flag = -1; // 返回值
	system("cls");
	PRHEAD;
	int choice;
	printf("  导入导出记录: \n\n");
	printf("                   1. 从文件导入记录(清空内存记录) \n\n");
	printf("                   2. 从文件导入记录(追加到现有内存记录之后)\n\n");
	printf("                   3. 从内存中导出记录到指定文件\n\n");
	printf("                   0. 返回主菜单\n\n");
	choice = menu_select(0, 3);
	switch(choice)
	{
	case 1:
		flag = loadRecords();
		break;
	case 2:
		loadaddRecords();
		break;
	case 3:
		flag = saveRecords();
		break;
	case 0:
		break;
	}
	return (flag);
}


