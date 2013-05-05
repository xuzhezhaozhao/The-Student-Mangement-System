
/*
	���ļ��к�������Ϊ: ���漰����ѧ����¼
*/


#include "student.h"


/*
�� �ܣ�����¼���뵱ǰ�ļ����µ�Ĭ���ļ�stu info�л���ָ���ļ��С�
����: ��  
����ֵ���ɹ�0��ʧ��-1
������ʽ������records��������ָ���ļ���
��ӡ: ʧ�ܴ�ӡ"Saving records is wrong!",  �ɹ����ӡ"%d����¼�洢�ɹ�!"
 */
int saveRecords()  //�����¼ģ��
{
	FILE *fp;
	int i = 0;
	int count = 0;   //����,��¼�����˶�������¼
	char filename[20]; // Ҫ���浽���ļ���
	printf("\n���뱣���ļ���\n\n");
	printf("(�س���ʾ���浽Ĭ���ļ�stu info��):");
	fflush(stdin); //������뻺��
	gets(filename); // �����ļ���
	
	if('\0' == filename[0] ) // �������س�ʱ����Ĭ�ϴ���
	{
		
		if( (fp = fopen("stu info","wb+") ) == NULL )
		{
			printf("Opening file is wrong!\n");
			return -1;   // ��ʧ���򷵻�-1
		}

		while ( records[i].savetag == 1)   //��flagΪ1ʱ������¼����
		{
			if( fwrite(&records[i], sizeof(StuInfo), 1, fp) != 1 )
			{
				printf("Saving records is wrong!\n");
				return -1;             //д��ʧ�ܷ���-1
			}
			else
			{
				i++;
				count++;   //����ɹ����������1
			}
		}
		fclose(fp);
		printf("\n%d����¼�洢�ɹ�!\n", count);
	}

	else
	{
		if( (fp = fopen(filename,"wb+") ) == NULL )
		{
			printf("Saving records ss is wrong!\n");
			return -1;   // ��ʧ���򷵻�-1
		}

		while ( records[i].savetag == 1)   //��flagΪ1ʱ������¼����
		{
			if( fwrite(&records[i], sizeof(StuInfo), 1, fp) !=1 )
			{
				printf("Saving records is wrong!\n");
				return -1;             //д��ʧ�ܷ���-1
			}
			else
			{
				i++;
				count++;   //����ɹ����������1
			}
		}
		fclose(fp);
		printf("\n%d����¼�洢�ɹ�!\n", count);
	}

	
	return 0;
}

/* 
�� �ܣ���Ĭ���ļ�stu info����ָ���ļ���ļ�¼ȡ���ڴ档
�� ��:��
�� �� ֵ���ɹ�0��ʧ��-1
������ʽ��records��Ϊ��ָ���ļ��ж�ȡ���ļ�¼,���Ḳ�ǵ�ǰ�ڴ��еļ�¼
��ӡ: �ļ�������ʱ��ӡ "���޼�¼�ɶ�ȡ!", ��ȡ�ɹ����ӡ "��ȡ��%d����¼!" 
*/
int loadRecords()
{
	system("cls");
	FILE *fp;
	int count = 0;
	char filename[20];
	PRHEAD;
	printf(" �����ļ�: \n\n\n");
	printf("����Ҫ������ļ���\n\n");
	printf("�س���ʾ����Ĭ���ļ�stu info:");
	fflush(stdin);
	gets(filename);

	if('\0' == filename[0] )
	{
		initial(); // ��������֮ǰ�ȳ�ʼ���ڴ�
		if((fp=fopen("stu info","rb"))==NULL)
		{
			printf("\n���޼�¼�ɶ�ȡ!\n");
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
		initial(); // ��������֮ǰ�ȳ�ʼ���ڴ�
		if((fp=fopen(filename,"rb"))==NULL)
		{
			printf("\n���޼�¼�ɶ�ȡ!\n");
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
	printf("\n��ȡ�ɹ���%d����¼�����ڴ���!\n", count);
	return(0);
}


/*
����: ���ļ������¼���ڴ���,��׷���ڼ�¼δβ
�� ��:��
�� �� ֵ���ɹ�0��ʧ��-1
*/
int loadaddRecords()
{
	system("cls");
	FILE *fp;

	int count = countRecords();
	char filename[20];
	PRHEAD;
	printf(" �����ļ�(׷��): \n\n\n");
	printf("����Ҫ������ļ���\n\n");
	printf("�س���ʾ����Ĭ���ļ�stu info:");
	fflush(stdin);
	gets(filename);

	if('\0' == filename[0] )
	{
		if((fp=fopen("stu info","rb"))==NULL)
		{
			printf("\n���޼�¼�ɶ�ȡ!\n");
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
			printf("\n���޼�¼�ɶ�ȡ!\n");
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
	printf("\n��ȡ�ɹ���%d����¼׷�ӵ��ڴ���!\n", count);
	return(0);
}

/*
����:���ļ������¼ ����ڴ浼����¼ �˵�����
�� �� ֵ���ɹ�0��ʧ��-1
*/
int out_loadRecords()
{
	int flag = -1; // ����ֵ
	system("cls");
	PRHEAD;
	int choice;
	printf("  ���뵼����¼: \n\n");
	printf("                   1. ���ļ������¼(����ڴ��¼) \n\n");
	printf("                   2. ���ļ������¼(׷�ӵ������ڴ��¼֮��)\n\n");
	printf("                   3. ���ڴ��е�����¼��ָ���ļ�\n\n");
	printf("                   0. �������˵�\n\n");
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


