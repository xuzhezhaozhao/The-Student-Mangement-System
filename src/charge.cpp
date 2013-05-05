
/*
	���ļ��к�������Ϊ���ݴ����ã��ж��й������Ƿ�Ϸ������Ϸ��������ʾ�����ж����ݿ��С�Ƿ��㹻�������Ļ�û�Զ�����
*/

#include "student.h"


/*
���ܣ��ж�������Ա��Ƿ�Ϸ�,�����Ϸ��������ʾ������������
������ѧ��
���أ�void
*/
void numInput(StuInfo *stu)
{

	fflush(stdin);
	gets(stu->num);

	do
	{
		if( strlen(stu->num) != 10 || stu->num[0] != 'U')
		{
			printf("\n��������ȷ��ʮλѧ��ѧ�ţ�����'U'��ͷ(��U201014072):");
			fflush(stdin);
			gets(stu->num);
		}
	}while( strlen(stu->num) != 10 || stu->num[0] != 'U');
}

/*
���ܣ��ж�������Ա��Ƿ�Ϸ�,�����Ϸ��������ʾ������������
������ѧ��
���أ�void
*/
void sexInput(StuInfo *stu)
{
	scanf("%s", stu->sex);

	do
	{
		if( strcmp(stu->sex, "��") != 0 && strcmp(stu->sex, "Ů") != 0 )
		{
			printf("\n��������ȷ���Ա�(��/Ů):");
			scanf("%s", stu->sex);
		}
	}while(strcmp(stu->sex, "��") != 0 && strcmp(stu->sex, "Ů") != 0);
}

/*
���ܣ��ж�����ķ����Ƿ���0 ~ 100���ڣ��������������Ӧ��ʾ����������
������StuInfo ѧ��, int choice ,1��ʾ����English, 2 ��ʾmath, 3 ��ʾ physics
���أ�void
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
				printf("\n��������ȷ��English����(0 ~ 100):");
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
				printf("\n��������ȷ��math����(0 ~ 100):");
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
				printf("\n��������ȷ��physics����(0 ~ 100):");
				scanf("%f", &stu->sco.physics);
			}
		}while( stu->sco.physics < 0 || stu->sco.physics > 100 );
		break;
	}

}

/*
���ܣ��ж������ӵ�ѧ����ѧ���Ƿ����ڴ������е�ѧ��ѧ�ų�ͻ����ͻʱ������ʾ
������Ҫ�жϵ�ѧ��
���أ���û��������ѧ���ظ�ʱ����0�����ظ�ʱ����1
*/
int dunum(StuInfo *stu)
{
	int count = countRecords();
	int i;
	int flag = 0;
	int du = 0;  // Ҫ�жϵ�ѧ����ѧ��������ѧ��ѧ�ţ������Լ�����Ƚϣ�ѧ���ظ��Ĵ�������du�����ڻ����2����˵�����ظ�
	for(i=0; i<count; i++)
	{
		if( strcmp(stu->num, records[i].num) == 0)
		{
			++du;
		}
	}

	if(du == 2 || du > 2)
	{
		printf("\n�����ѧ��������ѧ���ظ�!\n");
		flag = 1;
	}

	return flag;
}

/* 
����: �ж��û��Ƿ��������ǰ����,����Ϊy��Y,����YES, ����n��N,����NO
����: ��
����: YES��ʾ���������, NO��ʾ��������ǰ����,����ӡ��Ϣ
*/
int isContinue()
{
	char select;

	while(1)
	{	
		fflush(stdin);
		scanf("%c", &select);
		if ( 'y' == select || 'Y' == select )
				return YES; //�궨��
			else if( 'n' == select || 'N' == select )
				return NO; 
			printf("������y��n!\n");
	}
}

/* 
����: �ж��û��Ƿ��뱣�浱ǰ����
����: ��
����: YES ��ʾ����, NO��ʾ������, ����ӡ��Ϣ
*/
int isSave()
{
	char select;

	while(1)
	{	
		fflush(stdin);
		scanf("%c", &select);
		if ( 'y' == select || 'Y' == select )
				return YES; //�궨��
			else if( 'n' == select || 'N' == select )
				return NO; 
			printf("������y��n!\n");
	}
}

/*
�� �ܣ� �ж������ѡ������Ƿ�Ϸ�
�� ���� select_min, ��ѡ��������Сֵ,select_max,��ѡ�����ŵ����ֵ
�� �� ֵ�� �û������ѡ����ŵ�����ֵ
������ʽ��
*/
int menu_select(int select_min, int select_max)
{
	printf("������ѡ��(%d ~ %d): ", select_min, select_max);
	char select;
	fflush(stdin);
	scanf("%c", &select);
	
	while( (select>select_max+'0') || (select<select_min+'0') )
	{
		printf("\n�������ֵ����,����������һ����%d ~ %d ������: ", select_min, select_max);
		fflush(stdin);
		scanf("%c", &select);
	}
	return select-'0';
}

/*
���ܣ��ж��ڴ������Ƿ��С�����������Ļ��Զ�����INCR_SIZE
��������
���أ���
��ӡ��ʹ���������룬��������DEBUG���ӡ�����ݿ��Զ�����ɹ�, ��ǰ���ݿ��СΪ%d!�������ڵ���
*/
void autoIncr()
{
	int count = countRecords();
	if(count >= arrSize)
	{
		records = (StuInfo*) realloc( records, (arrSize+INCR_SIZE)*sizeof(StuInfo) ); // �����ݿ��С����ʱ��ÿ���Զ�����INCR_SIZE
		if(records == NULL)
		{
			printf("memory failed!");
			exit(-1);
		}
		arrSize = arrSize + INCR_SIZE;

		#ifdef DEBUG
		{
			printf("\n���ݿ��Զ�����ɹ�, ��ǰ���ݿ��СΪ%d! \n", arrSize);
		}
		#endif
	}


}