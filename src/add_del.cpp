
/*
	���ļ��к�������Ϊ����Ӻ�ɾ����¼
*/


#include "student.h"


/*
��¼���ƺ���
�� �ܣ���srcָ���һ����¼���Ƹ�destָ��ļ�¼��
�� ����StuInfo * src��Դ��¼StuInfo * dest�� Ŀ�ļ�¼��
�� �� ֵ��void
������ʽ����ԭ��¼�������Ƶ�Ŀ�ļ�¼��
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
		dest->savetag = src->savetag; // �������Ƽ�¼

}


/*
ɾ����¼����
�� �ܣ�ɾ���ڴ������е�ָ����¼, ����ѡ������������ѧ�ŵķ�ʽɾ����¼��
�� ������
�� �� ֵ��void
*/
void removeRecord()
{
	int index; // ָ��Ҫɾ���ļ�¼�����
	do{
			system("cls");  //����
			char name[20]; //ָ��ɾ����¼������
			char num[15];  //ָ��ɾ����¼��ѧ��
			int rank;      //ָ��ɾ����¼������

			int choice;
			PRHEAD;
			printf("     ɾ����¼ \n\n\n" );
			printf("                            1. ������ɾ����¼\n\n");
			printf("                            2. ��ѧ��ɾ����¼\n\n");
			printf("                            3. ������ɾ����¼\n\n");
			printf("                            0. �������˵�\n\n");
			choice = menu_select(0, 3);
			printf("\n");
			switch(choice)
			{
				case 1:
					printf("����Ҫɾ��������:");
					scanf("%s",name);
					printf("\n");
					index = name_findRecord(name, 0); // �ӵ�0����ʼ���ң�������ȫ��

					if(index == -1)
					{
						printf("û���ҵ�Ҫɾ���ļ�¼!\n\n");
					}
					else
					{
						index_disPlay(index);   // ��ӡ��Ҫɾ���ļ�¼
						printf("\n");
						printf("ȷ��ɾ���ü�¼(y/n)? ");
						if( isContinue() )
							name_remove(name);
					}
					break;
				case 2:
					printf("����Ҫɾ����ѧ��:");
					scanf("%s",num);
					printf("\n");
					index = num_findRecord(num, 0);   
					if(index == -1)
					{
						printf("û���ҵ�Ҫɾ���ļ�¼!\n\n");
					}
					else
					{
						index_disPlay(index);      // ��ӡ��Ҫɾ���ļ�¼
						printf("\n");
						printf("ȷ��ɾ���ü�¼(y/n)? ");
						if( isContinue() )
							num_remove(num);
					}
					break;
				case 3:
					printf("����Ҫɾ��������:");
					scanf("%d", &rank);
					printf("\n");
					index = rank_findRecord(rank, 0);

					if(index == -1)
					{
						printf("û���ҵ�Ҫɾ���ļ�¼!\n\n");
					}
					else
					{
						index_disPlay(index);     // ��ӡ��Ҫɾ���ļ�¼
						printf("\n");
						printf("ȷ��ɾ���ü�¼(y/n)? ");
						if( isContinue() )
						rank_Remove(rank);
					}
					
				case 0:
					break;
			}

			printf("\n�Ƿ����ɾ����¼(y/n)? ");
		}while( isContinue() );

}



/*
����: ������������ɾ���ڴ��еļ�¼
����: ����������name
����ֵ:void
��ӡ:"û���ҵ����ϵĽ��!", " ɾ���ɹ�!"
*/
void name_remove(char name[])
{	
	int i = 0;
	int flag = -1; //��Ϊ�ҵ���λ�õı��
	int count = 0;   //��¼�ڴ����ж��ټ�¼
	count = countRecords();
	for(i=0; i<count; i++) 
	{
		if( strcmp(name, records[i].name) == 0)
		{
			flag = i;
			break;
		}
	}
	if(flag == -1)    // flag Ϊ��1���ʾû���ҵ�
		printf("û���ҵ����ϵĽ��!\n");
	else if(flag == (count-1))
	{
		records[flag].savetag = 0;   //��������һλ,�Ͱ����һλ��flag��Ϊ0,�൱��ɾ��
		rank_Refresh();  // ������Ϣˢ��
		printf("\nɾ���ɹ�!\n");
	}
	else
	{
		for(i=flag; i<count-1;i++)        //�����ǰ��
		{
			copyRecord(&records[i+1], &records[i]);
		}
		records[count-1].savetag = 0;  
		rank_Refresh();
		printf("\nɾ���ɹ�!\n");
	}
}

/*
����:��ѧ��ɾ���ڴ��еļ�¼
����ֵ:void
*/
void num_remove(char num[])
{	
	int i = 0;
	int flag = -1; //��Ϊ�ҵ���λ�õı��
	int count = 0;   //��¼�ڴ����ж��ټ�¼
	count = countRecords();
	for(i=0; i<count; i++)
	{
		if( strcmp(num, records[i].num) == 0 )
		flag = i;
	}
	if(flag == -1)
		printf("û���ҵ����ϵĽ��!\n");
	else if(flag == (count-1))
	{
		records[flag].savetag = 0;   //��������һλ,�Ͱ����һλ��flag��Ϊ0,�൱��ɾ��
		rank_Refresh();
		printf("\nɾ���ɹ�!\n");
	}
	else
	{
		for(i=flag; i<count-1;i++)        //�����ǰ��
		{
			copyRecord(&records[i+1], &records[i]);
		}
		records[count-1].savetag = 0;  
		rank_Refresh();
		printf("\nɾ���ɹ�!\n");
	}
}

/*
���ܣ�������ɾ���ڴ��еļ�¼
����ֵ��void
*/
void rank_Remove(int rank)
{
	int i = 0;
	int flag = -1; //��Ϊ�ҵ���λ�õı��
	int count = 0;   //��¼�ڴ����ж��ټ�¼
	count = countRecords();
	for(i=0; i<count; i++)
	{
		if(rank == records[i].rank)
		flag = i;
	}
	if(flag == -1)
		printf("û���ҵ����ϵĽ��!\n");
	else if(flag == (count-1))
	{
		records[flag].savetag = 0;   //��������һλ,�Ͱ����һλ��flag��Ϊ0,�൱��ɾ��
		rank_Refresh();
		printf("\nɾ���ɹ�!\n");
	}
	else
	{
		for(i=flag; i<count-1;i++)        //�����ǰ��
		{
			copyRecord(&records[i+1], &records[i]);
		}
		records[count-1].savetag = 0;  
		rank_Refresh();
		printf("\nɾ���ɹ�!\n");
	}
}

/*
�� �ܣ����Ӽ�¼�������ӵļ�¼׷�����������
�� ������
�� �� ֵ��void
������ʽ����β����ʼ���׷�Ӽ�¼��
��ӡ: "��ӳɹ�" , "��ǰ�ڴ��й���%d����¼! "  
*/
void addRecord()
{
	int count = countRecords();
	autoIncr();
	do{
			system("cls");
			PRHEAD;
			printf("  ���ѧ����Ϣ:\n\n");
			records[count].savetag  = 1;  // ��Ӽ�¼����¼��flag ��Ϊ1 , ������Ϊ��Ч��Ϣ
			printf("������ѧ������:");
			scanf("%s", records[count].name);

			do{
				printf("\n������ʮλѧ��ѧ��(Uxxxxxxxxx):");
				numInput(&records[count]);  // ��numInput����ѧ�ţ���������ѧ���ظ���������ʾ����������
			}while(dunum(&records[count]));

			printf("\n������ѧ���Ա�(��/Ů):");
			sexInput(&records[count]);

			printf("\n������ѧ���ɼ�(0 ~ 100):\n\n");
			printf("English(0 ~ 100): ");
			scoInput(&records[count], 1);
			printf("\nmath(0 ~ 100): ");
			scoInput(&records[count], 2);
			printf("\nphysics(0 ~ 100): ");
			scoInput(&records[count], 3);
			records[count].total  = records[count].sco.English  + records[count].sco .math + records[count].sco .physics;
			rank_Refresh();
			
			count++;
			autoIncr(); // �ж��Ƿ���Ҫ�Զ������ڴ�����

			printf("\n��ӳɹ���");
			printf("��ǰ�ڴ��й���%d��ѧ����¼!\n\n", count);
		
			printf("�Ƿ�������ѧ����Ϣ(y/n)? ");
	}while ( isContinue() );
}

/*
�½�ѧ����Ϣ��¼�ĺ���
�� �ܣ����½���������Ϣ��¼���½����֮�����ʾ�Ƿ񱣴�
�� ������
�� �� ֵ��void
������ʽ��������Ҫ����saveRecords������
*/
void newRecords()
{
	system("cls");
	if(records[0].savetag != 0) // �ж��ڴ��������Ƿ��м�¼
	{
		PRHEAD;
		PRROW3;
		printf("��ǰ�ڴ����м�¼,�Ƿ��ȱ��浱ǰ����(y/n)? ");
		if( isSave() )
			saveRecords();
		printf("\n\n");
		system("pause");
	}
	initial(); // ��ʼ���ڴ�����

		system("cls");
		PRHEAD;
		printf(" �½�һ��ѧ����Ϣ��: \n\n\n");
		addRecord();

	printf("\n�Ƿ񱣴��½���ѧ����Ϣ(y/n)? ");
	if( isSave() )
		saveRecords();
}

