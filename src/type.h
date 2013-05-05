
/*
	本文件中包含 宏定义及自定义数据结构头文件
*/

#define DEBUG // 条件编译时，用作调试作用
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


//定义各科分数结构体
typedef struct type_score
{
	float math;
	float English;
	float physics;
} SCORE,*LPSCORE;

//定义学生结构体
typedef struct type_student
{
	char name[20];   // 学生姓名
	char num[15];             // 学号
	char sex[5];           //性别
	SCORE sco;  //各门成绩,math,English,physics
	float total;         // 总分
	int rank;   // 学生排名
	int savetag;    // 把一条学生信息放入内存后该学生信息的savetag置为1
} StuInfo;


