
/*
	���ļ��к�������Ϊ�����Ҽ��޸�ѧ����¼
*/

#include "student.h"


/*
����:���������Ҽ�¼
����: ����name,from �ӵڼ�����ʼ����, ��0 �� count-1
����ֵ: int ��, �ҵ��ļ�¼�ڱ��е�λ��, û���ҵ��򷵻�-1
��ӡ: ��
*/
int name_findRecord(char *name, int from)
{
	int count = 0; //�ڴ���ѧ����¼��
	int index = -1;  // λ�ñ��
	int i = 0;
	int flag = 0; //�ҵ����ı�־���ҵ���¼��Ϊ1
	count = countRecords(); //���ü�¼ͳ�ƺ������ó��ڴ��е�ǰ�ļ�¼������
	for(i=from; i<count; i++)
	{
		if( strcmp(records[i].name, name) == 0 )  //���ڴ��еļ�¼������Ҫ���ҵļ�¼�Ƚ�
		{
			flag = 1;       // ����ҵ���flag��Ϊ1
			index = i + 1; // index Ϊ�ü�¼���ڴ��е�λ�ã���1Ϊ��ʼ
			break;          //�˳�ѭ��
		}
	}

	if(flag == 0) // flagΪ0���ʾû���ҵ�ָ���ļ�¼
	{
		return (index); 
	}
	else
		return (index);
}

/*
����:��ѧ�Ų��Ҽ�¼
����: ����name,from �ӵڼ�����ʼ����, ��0 �� count-1
����ֵ: int ��, �ҵ��ļ�¼�ڱ��е�λ��, û���ҵ��򷵻�-1
��ӡ: ��
*/
int num_findRecord(char *num, int from)
{
	int count = 0;
	int index = -1;
	int i = 0;
	int flag = 0; //�ҵ����ı�־
	count = countRecords();
	for(i=from; i<count; i++)
	{
		if( strcmp(records[i].num, num) == 0 )  // ��ָ����ѧ������ѯ
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
����:�����β��Ҽ�¼
����: ����name,from �ӵڼ�����ʼ����, ��0 �� count-1
����ֵ: int ��, �ҵ��ļ�¼�ڱ��е�λ��, û���ҵ��򷵻�-1
��ӡ: ��
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
		if( records[i].rank == rank)  // ��ָ������������ѯ
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
�� �ܣ�����ָ���ļ�¼��
�� ����char* target�������Ҽ�¼��ĳһ����target��ͬ
int targetType������ͨ����һ�������ң�0Ϊѧ�ţ�1Ϊ������2Ϊ����
int from���ӵ�from����¼��ʼ��
�� �� ֵ��int�ҵ��ļ�¼����ţ����Ҳ����򷵻�-1��
������ʽ�����ݸ����Ĺؼ��֣����ҷ��ϼ�¼����š�
��ӡ :��
*/
int findRecord(char*target, int targetType, int from)
{
	int index = -1;  // ��ʼ��Ϊ��1�� ���Ҳ�����Ϊ��1
	int rank;  //��Ϊtarget Ϊ�ַ�����ʽ,����rank_findRecordʱҪת��ʮ������ʽ
	switch(targetType)
	{
		case 0:
			index = num_findRecord(target, from);  // ͨ��ѧ��������
			break;
		case 1:
			index = name_findRecord(target, from);  //ͨ������������
			break;
		case 2:
			rank = target[0] - '0';  // ��Ϊ��������������ַ�������ʽ�������Ƚ���ת����������ʽ
			index = rank_findRecord(rank, from);  // ͨ������������
			break;
	}

	return (index);
}

/*
�� �ܣ���Ҫ���ѯָ��ѧ����Ϣ �˵�����
�� ������
�� �� ֵ��void
������ʽ�����԰���ѧ�š���������������ѯ��
*/
void queryInfo()
{
	do
	{
		system("cls"); // ����
		int choice;    //�˵�ѡ�����
		char name[20]; 
		char num[15];
		int rank;
		int index;
		PRHEAD;
		printf("                                 ��ѯѧ����¼\n\n\n");
		printf("                                1. ��ѧ�Ų�ѯ\n\n");
		printf("                                2. ��������ѯ\n\n");
		printf("                                3. �����β�ѯ\n\n");
		printf("                                0. �������˵�\n\n");
		choice = menu_select(0,3);
		printf("\n");
		switch(choice)
		{
		case 1:
			printf("������ѧ��:");
			scanf("%s", num);  //����Ҫ��ѯ��ѧ��
			index = num_findRecord(num,  0);
			printf("\n");
			if(index == -1)  // ��indexΪ��1���ʾû���ҵ�ָ���ļ�¼
				printf("û���ҵ���ؼ�¼!\n");
			else
			{
				showTable();
				PR(index-1);  //�궨�壬 ����ѯ������Ϣ��ӡ����
			}
			break;
		case 2:
			printf("����������:");
			scanf("%s", name); //����Ҫ��ѯ������
			index = name_findRecord(name,  0);
			printf("\n");
			if(index == -1)
				printf("û���ҵ���ؼ�¼!\n");
			else
			{
				showTable();
				PR(index-1);  //�궨�壬 ����ѯ������Ϣ��ӡ����
			}
			break;
		case 3:
			printf("����������:");
			scanf("%d", &rank);  // ����Ҫ��ѯ������
			index = rank_findRecord(rank,  0);
			printf("\n");
			if(index == -1)
				printf("û���ҵ���ؼ�¼!\n");
			else
			{
				showTable();
				PR(index-1); //�궨�壬 ����ѯ������Ϣ��ӡ����  
			}
			break;
		case 0:
			break;
		}
		printf("\n�Ƿ������ѯ(y/n)? ");
	}while(isContinue());
}


/*
���ܣ��޸�ָ���ļ�¼����ȷ�Ϲ��ܣ��޸�ǰ��ӡ��ԭ��¼������ѡ���޸ĵ�����һ�Ҳ����ѡ���޸�ȫ�������س����ʾ���޸�
����:desָ��ָ����¼
����:void
*/
void pmodify(StuInfo *des)
{
	int choice;
	char ctemp[20];
	system("cls");
	PRHEAD;
	printf("ѡ���޸���Ŀ: \n\n\n");
	printf("                             1. ����\n");
	printf("                             2. ѧ��\n");
	printf("                             3. �Ա�\n");
	printf("                             4. English\n");
	printf("                             5. math\n");
	printf("                             6. physics\n");
	printf("                             7. �޸�ȫ��\n");

	choice = menu_select(1, 7);
	switch(choice)
	{
	case 1:
			strcpy(ctemp, des->name);
			printf("\nԭѧ��������%s\n", des->name);
			printf("\n��������ѧ������(�س����޸�):");
			fflush(stdin);  // ��������뻺��
			gets(des->name);
			if('\0' == des->name[0])  // �ж�������Ƿ��ǻس�
			{
				strcpy(des->name, ctemp);
			}
		break;

	case 2:
			strcpy(ctemp, des->num); //����ԭ��¼��ctemp ��
			printf("\nԭѧ��ѧ�ţ�%s\n", des->num);	
			do{
				printf("\n��������ʮλѧ��ѧ��(Uxxxxxxxxx)(�س����޸�):");
				fflush(stdin);
				gets(des->num);
				if('\0' == des->num[0])
				{
					strcpy(des->num, ctemp);  // ��������س����޸ļ�¼
					break;
				}
				do
				{
					if( 10 != strlen(des->num) || des->num[0] != 'U') // �ж������ѧ���Ƿ�Ϸ�
					{
						printf("\n��������ȷ��ʮλѧ��ѧ�ţ�����'U'��ͷ(��U201014072):");
						fflush(stdin);
						gets(des->num);
						if('\0' == des->num[0])
						{
							strcpy(des->num, ctemp); // ��������س����޸ļ�¼
							break;
						}
					}
				}while( 10 != strlen(des->num) || (des->num[0] != 'U')); // �������벻�Ϸ�����������
			}while(dunum(des));  //��dunum(des)�ж������ѧ���Ƿ����ڴ������е�ѧ���ظ����ظ��������ʾ������������
		break;

	case 3:
			strcpy(ctemp, des->sex);
			printf("\nԭѧ���Ա�%s\n", des->sex);
			printf("\n��������ѧ���Ա�(��/Ů)(�س����޸�):");
			fflush(stdin);
			gets(des->sex);
			if('\0' == des->sex[0])
			{
				strcpy(des->sex, ctemp);
			}

			do
			{
				if( strcmp(des->sex, "��") != 0 && strcmp(des->sex, "Ů") != 0 )
				{
					printf("\n��������ȷ���Ա�(��/Ů):");
					fflush(stdin);
					gets(des->sex);
					if('\0' == des->sex[0])
					{
						strcpy(des->sex, ctemp);
						break;
					}
				}
			}while(strcmp(des->sex, "��") != 0 && strcmp(des->sex, "Ů") != 0);
		break;

	case 4:
			printf("\nԭѧ��English�ɼ���%-5.1f\n", des->sco.English);
			printf("\n������Englih�ɼ�(0 ~ 100)(�س����޸�):");
			scoInput(des, 1);  // ��scoInputȷ����������ĺϷ���
			des->total  =des->sco.English  + des->sco .math + des->sco .physics;
			rank_Refresh();
		break;

	case 5:
			printf("\nԭѧ��math�ɼ���%-5.1f\n", des->sco.math);
			printf("\n������math�ɼ�(0 ~ 100)(�س����޸�): ");
			scoInput(des, 2);
			des->total  =des->sco.English  + des->sco .math + des->sco .physics;
			rank_Refresh();
		break;

	case 6:
			printf("\nԭѧ��physics�ɼ���%-5.1f\n", des->sco.physics);
			printf("\n������physics�ɼ�(0 ~ 100)(�س����޸�):");
			scoInput(des, 3);
			des->total  =des->sco.English  + des->sco .math + des->sco .physics;
			rank_Refresh();
		break;

	case 7:  // �ۺ�ǰ��6��
			strcpy(ctemp, des->name);
			printf("\nԭѧ��������%s\n", des->name);
			printf("\n��������ѧ������(�س����޸�):");
			fflush(stdin);
			gets(des->name);
			if('\0' == des->name[0])
			{
				strcpy(des->name, ctemp);
			}


			strcpy(ctemp, des->num);
			printf("\nԭѧ��ѧ�ţ�%s\n", des->num);	
			do{
				printf("\n��������ʮλѧ��ѧ��(Uxxxxxxxxx)(�س����޸�):");
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
						printf("\n��������ȷ��ʮλѧ��ѧ�ţ�����'U'��ͷ(��U201014072):");
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
			printf("\nԭѧ���Ա�%s\n", des->sex);
			printf("\n��������ѧ���Ա�(��/Ů)(�س����޸�):");
			fflush(stdin);
			gets(des->sex);
			if('\0' == des->sex[0])
			{
				strcpy(des->sex, ctemp);
			}

			do
			{
				if( strcmp(des->sex, "��") != 0 && strcmp(des->sex, "Ů") != 0 )
				{
					printf("\n��������ȷ���Ա�(��/Ů):");
					fflush(stdin);
					gets(des->sex);
					if('\0' == des->sex[0])
					{
						strcpy(des->sex, ctemp);
						break;
					}
				}
			}while(strcmp(des->sex, "��") != 0 && strcmp(des->sex, "Ů") != 0);

			printf("\nԭѧ��English�ɼ���%-5.1f\n", des->sco.English);
			printf("\n������Englih�ɼ�(0 ~ 100)(�س����޸�):");
			scoInput(des, 1);

			printf("\nԭѧ��math�ɼ���%-5.1f\n", des->sco.math);
			printf("\n������math�ɼ�(0 ~ 100)(�س����޸�): ");
			scoInput(des, 2);

			printf("\nԭѧ��physics�ɼ���%-5.1f\n", des->sco.physics);
			printf("\n������physics�ɼ�(0 ~ 100)(�س����޸�):");
			scoInput(des, 3);

			des->total = des->sco.English  + des->sco .math + des->sco .physics;
			rank_Refresh();

		break;
	}
}

/*
�޸�ָ��ѧ����Ϣ�˵�����
�� �ܣ��ҵ�ָ����¼���޸�
�� ����void
�� �� ֵ��void
������ʽ�����԰���ѧ�š������������ҵ�Ҫ�޸ĵļ�¼��ȷ�Ϻ󷽿��޸ġ�
*/

void modifyRecord()
{

	int choice;
	char name[20];   // ָ��������
	char num[15];    //ָ����ѧ��
	int rank;             //ָ��������
	int index;         // ָ����¼�����
do{
			system("cls");
			PRHEAD;
			printf(" �޸�ѧ����¼: \n\n\n");
			printf("                            1. ��ѧ�Ų�ѯ�޸�\n\n");
			printf("                            2. ��������ѯ�޸�\n\n");
			printf("                            3. �����β�ѯ�޸�\n\n");
			printf("                            0. �������˵�\n\n");

			choice = menu_select(0, 3);
			printf("\n");

		switch(choice)
			{
			case 1:
				printf("������Ҫ��ѯ��ѧ��(Uxxxxxxxxx):");
				scanf("%s", num);
				index = num_findRecord(num,  0); //����
				printf("\n");
				if(index == -1)
					printf("û���ҵ����ѧ����¼!\n\n");  //�Ҳ����������ʾ
				else
				{
					index_disPlay(index);
					printf("\n");
					printf("ȷ���޸ļ�¼(y/n)? ");
					printf("\n");
					if( isContinue() )
					{
						pmodify(&records[index-1]);
					}
				}
		break;
	case 2:
		printf("����������:");
		scanf("%s", name);
		index = name_findRecord(name,  0);
		printf("\n");
		if(index == -1)
			printf("û���ҵ���ؼ�¼!\n\n");
		else
		{
			index_disPlay(index);
			printf("\n");
			printf("ȷ���޸ļ�¼(y/n)? ");
			printf("\n");
			if( isContinue() )
			{
				pmodify(&records[index-1]);
			}
		}
		break;
	case 3:
		printf("����������:");
		scanf("%d", &rank);
		index = rank_findRecord(rank,  0);
		printf("\n");
		if(index == -1)
			printf("û���ҵ���ؼ�¼!\n");
		else
		{
			index_disPlay(index);
			printf("\n");
			printf("ȷ���޸ļ�¼(y/n)? ");
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
	printf("\n�Ƿ�����޸�ѧ����¼(y/n)?");
}while( isContinue() );
	total_sortRecords();
}
