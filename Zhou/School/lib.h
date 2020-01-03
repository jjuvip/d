#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INFINITY 32767
#define MAX_VERTEX_NUM 50
#define MAX 30

typedef struct st_llnode {
	char id[20];
	char pass[20];
	struct st_llnode *next;
} LLNode;

void initRegSystem();
LLNode *findUser(const char *id);
void userRegister();
bool userLogin();

typedef unsigned char byte;

typedef struct {
	int adj; //路径长度
} ArCell, ArcNode[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

//图中顶点表示主要景点，存放景点的编号、名称、简介等信息
typedef struct {
	char name[30];
	int num;
	char info[100]; //简介
} VexNode;

typedef struct {
	VexNode vertex[MAX_VERTEX_NUM];
	ArcNode arcs;
	int vexnum, arcnum;
} AdjMatrix;

#endif
