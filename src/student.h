
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"type.h"
#include"func_state.h"

extern StuInfo *records; // 学生信息数组
extern arrSize; // 数据库大小，当大小不够时，每次自动增加INCR_SIZE

