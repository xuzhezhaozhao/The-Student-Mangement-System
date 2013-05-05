
/*
	���ļ��к�������Ϊ��������������������˵����溯��
*/


#include "student.h"
StuInfo *records;  // ѧ����Ϣ����
int arrSize;  // ���ݿ��С������С����ʱ��ÿ���Զ�����INCR_SIZE

/*
������
*/

int main()
{
	system("color 1e"); // ����ǰ��������ɫ
	
	arrSize = INITIAL_SIZE;
	initial();
//	welcome();
	handle_menu();

	return 0;
}

/*
���ܣ���ӡ��ӭ����
��������
���أ�void
*/
void welcome()
{
	PRHEAD;
	PRROW6;
	printf("                            ��ӭ����ѧ������ϵͳ��");
	PRROW7;
	system("pause");

}

/*
�˵�������
�� �ܣ�����ѡ��Ĳ˵����
�� ������
�� �� ֵ��void
������ʽ��������ѡ��Ķ�Ӧ�����������Ӧ�ĺ���
*/
void handle_menu()
{			
	int menu;        //ѡ��˵��Ĳ���
	int child_menu; // �Ӳ˵�ѡ�����
	do{
			system("cls");
		//	system("Mode con: COLS=85 LINES=30");
			PRHEAD;
			printf("   ѧ������ϵͳ 2.00 ��   ");
			printf("\n");
			printf("                             1. �½�һ��ѧ����Ϣ�� \n\n");
			printf("                             2. ��ѯ���޸�ѧ����Ϣ \n\n");
			printf("                             3. ��Ӽ�ɾ��ѧ����Ϣ\n\n");
			printf("                             4. ������ʾѧ����Ϣ\n\n");
			printf("                             5. ���漰����ѧ����Ϣ\n\n");
			printf("                             6. ��յ�ǰ�ڴ��¼\n\n");
			printf("                             7. �ɼ�����\n\n");
			printf("                             8. ����\n\n");
			printf("                             0. �˳�ϵͳ\n\n");
		
			menu = menu_select(0, 8); 

			switch(menu)
		{
				case 1:
					newRecords();
					printf("\n�Ƿ�ص����˵�(y/n)? ");
			break;
				case 2:
					system("cls");
					PRHEAD;
					printf(" ��ѯ���޸ļ�¼: \n\n\n\n");
					printf("                            1. ��ѯ��¼\n\n");
					printf("                            2. �޸ļ�¼\n\n");
					printf("                            0. �������˵�\n\n");
					
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
					printf("\n�Ƿ�ص����˵�(y/n)? ");
			break;
				case 3:
					system("cls");
					PRHEAD;
					printf(" ��Ӽ�ɾ����¼: \n\n\n\n");
					printf("                      1. ��Ӽ�¼��׷�����ڴ��¼֮��\n\n");
					printf("                      2. ɾ����¼\n\n");
					printf("                      0. �������˵�\n\n");

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
					printf("\n�Ƿ�ص����˵�(y/n)? ");
			break;
				case 4:
					sort_disPlay();
					printf("\n�Ƿ�ص����˵�(y/n)? ");
			break;
				case 5:
					 out_loadRecords();
					printf("\n�Ƿ�ص����˵�(y/n)? ");
			break;
				case 6:
					system("cls");
					PRHEAD;
					initial();
					printf("\n����ڴ��¼�ɹ���\n\n");
					printf("�Ƿ�ص����˵�(y/n)? ");
					break;
				case 7:
					system("cls");
					PRHEAD;
					average();
					printf("\n");
					subfail();
					printf("\n�Ƿ�ص����˵�(y/n)? ");
					break;
				case 8:
					showHelp();
					printf("\n�Ƿ�ص����˵�(y/n)? ");
			break;	
				case 0:
					quit();
			break;
		}
	}while( isContinue() );

	system("cls");
	PRHEAD;
	printf(" �˳�ѧ������ϵͳ: \n\n\n");

	if(0 != countRecords())
	{
		printf(" �����˳�ѧ������ϵͳ, ");
		printf("�˳�ǰ�Ƿ񱣴浱ǰ�ڴ��еļ�¼��ָ���ļ�(y/n)? ");
		if( isSave() )
		{
			printf("\n");
			saveRecords();
		}
	}

	printf(" \n\n�ɹ��˳�ѧ������ϵͳ! \n\n");
	system("pause");
}


/*
�����������к���
�� �ܣ������������С�
�� ������
�� �� ֵ��void
������ʽ������Ҫ��������˳�ǰ�Ƿ��޸ĵļ�¼�����ļ�,��������֮ǰ��ѯ���Ƿ���޸ĵļ�¼���д洢��
*/
void quit()
{
	system("cls");
	PRHEAD;
	int count;
	count = countRecords();
	printf("�˳�ѧ������ϵͳ:\n\n\n\n");
	if(0 != count) // ����ڴ��д��ڼ�¼������ʾ�Ƿ��ȱ����¼������ֱ���˳�
	{
		printf("�˳�ǰ�Ƿ�洢�ڴ��еļ�¼��ָ���ļ�(y/n)?");
		if( isSave() )
		{
			printf("\n");
			saveRecords();
		}
	}
	printf(" \n\n�ɹ��˳�ѧ������ϵͳ! \n\n");
	system("pause");
	exit(0);
}