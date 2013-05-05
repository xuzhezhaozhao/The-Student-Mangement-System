
/*
	���ļ��а������ڸ�����������ͷ�ļ�
*/


/*add_del.cpp �еĺ�������*/
void copyRecord(StuInfo * src, StuInfo * dest);
void removeRecord();
void name_remove(char name[]);
void num_remove(char num[]);
void rank_Remove(int rank);
void addRecord();
void newRecords();

/*search_mod.cpp �еĺ�������*/
int name_findRecord(char *name, int from);
int num_findRecord(char *num, int from);
int rank_findRecord(int rank, int from);
int findRecord(char*target, int targetType, int from);
void queryInfo();
void pmodify(StuInfo *des);
void modifyRecord();

/*analyze.cpp �еĺ�������*/
void average();
void subfail();

/*charge.cpp �еĺ�������*/
void numInput(StuInfo *stu);
void sexInput(StuInfo *stu);
void scoInput(StuInfo *stu, int choice);
int dunum(StuInfo *stu);
int isContinue();
int isSave();
int menu_select(int select_min, int select_max);
void autoIncr();

/*display.cpp�еĺ�������*/
void showTable();
void disPlay();
void index_disPlay(int index);
int getIndex(float sum);
void showHelp();
void sort_disPlay();


/*initial.cpp�еĺ�������*/
void initial();
int countRecords();
int getRank(StuInfo stu);
void rank_Refresh();

/* save_load.cpp �еĺ������� */
int saveRecords();
int loadRecords();
int loadaddRecords();
int out_loadRecords();

/* sort.cpp �еĺ������� */
void total_sortRecords();
void num_sortRecords();
void name_sortRecords();

/* student.cpp �еĺ������� */
void welcome();
void handle_menu();
void quit();