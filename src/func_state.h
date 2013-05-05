
/*
	本文件中包含关于各函数声明的头文件
*/


/*add_del.cpp 中的函数声明*/
void copyRecord(StuInfo * src, StuInfo * dest);
void removeRecord();
void name_remove(char name[]);
void num_remove(char num[]);
void rank_Remove(int rank);
void addRecord();
void newRecords();

/*search_mod.cpp 中的函数声明*/
int name_findRecord(char *name, int from);
int num_findRecord(char *num, int from);
int rank_findRecord(int rank, int from);
int findRecord(char*target, int targetType, int from);
void queryInfo();
void pmodify(StuInfo *des);
void modifyRecord();

/*analyze.cpp 中的函数声明*/
void average();
void subfail();

/*charge.cpp 中的函数声明*/
void numInput(StuInfo *stu);
void sexInput(StuInfo *stu);
void scoInput(StuInfo *stu, int choice);
int dunum(StuInfo *stu);
int isContinue();
int isSave();
int menu_select(int select_min, int select_max);
void autoIncr();

/*display.cpp中的函数声明*/
void showTable();
void disPlay();
void index_disPlay(int index);
int getIndex(float sum);
void showHelp();
void sort_disPlay();


/*initial.cpp中的函数声明*/
void initial();
int countRecords();
int getRank(StuInfo stu);
void rank_Refresh();

/* save_load.cpp 中的函数声明 */
int saveRecords();
int loadRecords();
int loadaddRecords();
int out_loadRecords();

/* sort.cpp 中的函数声明 */
void total_sortRecords();
void num_sortRecords();
void name_sortRecords();

/* student.cpp 中的函数声明 */
void welcome();
void handle_menu();
void quit();