
/*
	���ļ��а��� �궨�弰�Զ������ݽṹͷ�ļ�
*/

#define DEBUG // ��������ʱ��������������
#define INITIAL_SIZE 50
#define INCR_SIZE 50
#define YES 1
#define NO 0
#define  PR(i) printf(" %3d.  %-11s%-14s%-7s%-7.1f%-7.1f %-9.1f%-7.1f%5d\n", i+1, records[i].name, records[i].num, records[i].sex, records[i].sco.math, records[i].sco.English, records[i].sco.physics, records[i].total, records[i].rank)

#define PRHEAD printf("\n********************************************************************************\n")

#define PRROW1 printf("\n")
#define PRROW2 printf("\n\n")
#define PRROW3 printf("\n\n\n")
#define PRROW4 printf("\n\n\n\n")
#define PRROW5 printf("\n\n\n\n\n")
#define PRROW6 printf("\n\n\n\n\n\n")
#define PRROW7 printf("\n\n\n\n\n\n\n")
#define PRROW8 printf("\n\n\n\n\n\n\n\n")
#define PRROW9 printf("\n\n\n\n\n\n\n\n\n")


//������Ʒ����ṹ��
typedef struct type_score
{
	float math;
	float English;
	float physics;
} SCORE,*LPSCORE;

//����ѧ���ṹ��
typedef struct type_student
{
	char name[20];   // ѧ������
	char num[15];             // ѧ��
	char sex[5];           //�Ա�
	SCORE sco;  //���ųɼ�,math,English,physics
	float total;         // �ܷ�
	int rank;   // ѧ������
	int savetag;    // ��һ��ѧ����Ϣ�����ڴ���ѧ����Ϣ��savetag��Ϊ1
} StuInfo;


