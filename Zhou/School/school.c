#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "lib.h"

void clearScreen() {
	printf("\033[H\033[J");
}

int LocateVex(AdjMatrix G, char *v) {
	int m = -1, i;
	for (i = 0; i < G.vexnum; i++) {
		if (strcmp(v, G.vertex[i].name) == 0) {
			m = i;
			break;
		}
	}
	return m;
}

AdjMatrix CreateDN() {
	AdjMatrix G;
	int i, j;
	G.vexnum = 25;
	G.arcnum = 31;
	for (i = 0; i < G.vexnum; i++)
		G.vertex[i].num = i;
	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
			G.arcs[i][j].adj = INFINITY;
	//所有位置组合
	G.arcs[0][3].adj = 400;
	G.arcs[0][4].adj = 150;
	G.arcs[1][2].adj = 150;
	G.arcs[1][6].adj = 500;
	G.arcs[2][3].adj = 50;
	G.arcs[3][5].adj = 100;
	G.arcs[4][5].adj = 200;
	G.arcs[4][6].adj = 100;
	G.arcs[6][7].adj = 50;
	G.arcs[6][11].adj = 80;
	G.arcs[7][8].adj = 5;
	G.arcs[7][15].adj = 5;
	G.arcs[8][9].adj = 5;
	G.arcs[9][10].adj = 35;
	G.arcs[9][14].adj = 20;
	G.arcs[10][11].adj = 20;
	G.arcs[10][12].adj = 5;
	G.arcs[10][14].adj = 30;
	G.arcs[11][12].adj = 5;
	G.arcs[12][13].adj = 10;
	G.arcs[15][16].adj = 20;
	G.arcs[15][17].adj = 10;
	G.arcs[16][19].adj = 100;
	G.arcs[16][18].adj = 250;
	G.arcs[18][20].adj = 20;
	G.arcs[19][21].adj = 50;
	G.arcs[20][22].adj = 30;
	G.arcs[22][23].adj = 100;
	G.arcs[19][24].adj = 400;
	G.arcs[21][24].adj = 400;
	G.arcs[22][24].adj = 450;
	//所有景点信息
	strcpy(G.vertex[0].name, "西门");
	strcpy(G.vertex[0].info, "大门之一，主要进出通道");
	strcpy(G.vertex[1].name, "教工食堂");
	strcpy(G.vertex[1].info, "教职、教工食堂，学生也可就餐");
	strcpy(G.vertex[2].name, "主图书馆");
	strcpy(G.vertex[2].info, "馆藏丰富，包含了各种类型的书籍");
	strcpy(G.vertex[3].name, "校医院");
	strcpy(G.vertex[3].info, "校医院有着比较先进的设备，并且学生，教职工看病十分便宜");
	strcpy(G.vertex[4].name, "教务处");
	strcpy(G.vertex[4].info, "是安排学校教学工作的部门，门前的校训'竞知向学，厚德笃行'");
	strcpy(G.vertex[5].name, "财务中心");
	strcpy(G.vertex[5].info, "主要管理学生的各种缴费");
	strcpy(G.vertex[6].name, "红楼");
	strcpy(G.vertex[6].info, "红楼一栋标志性建筑，旁边就是游泳池");
	strcpy(G.vertex[7].name, "游泳池");
	strcpy(G.vertex[7].info, "目前还未开放给学生使用");
	strcpy(G.vertex[8].name, "竞知楼");
	strcpy(G.vertex[8].info, "九江学院最高的建筑，是三个学院学习、上课的地方");
	strcpy(G.vertex[9].name, "男生宿舍15栋");
	strcpy(G.vertex[9].info, "是电子工程学院男生的主要休息的地方");
	strcpy(G.vertex[10].name, "女生宿舍11栋");
	strcpy(G.vertex[10].info, "是电子工程学院女生的主要休息的地方");
	strcpy(G.vertex[11].name, "顺丰快递点");
	strcpy(G.vertex[11].info, "学校顺丰快递的寄存点");
	strcpy(G.vertex[12].name, "四食堂服务楼");
	strcpy(G.vertex[12].info, "简称四服楼，提供买东西，拿快递，拍照片等服务");
	strcpy(G.vertex[13].name, "学生五食堂");
	strcpy(G.vertex[13].info, "主校区食物种类最多的食堂");
	strcpy(G.vertex[14].name, "学生三食堂");
	strcpy(G.vertex[14].info, "主校区最适合吃饭的地方");
	strcpy(G.vertex[15].name, "公用机房");
	strcpy(G.vertex[15].info, "提供上网服务，可供学生学习计算机软件，查资料");
	strcpy(G.vertex[16].name, "文友楼");
	strcpy(G.vertex[16].info, "主要是信息学院和马克思学院的教学楼");
	strcpy(G.vertex[17].name, "厚德楼");
	strcpy(G.vertex[17].info, "主要是老师办公的地方");
	strcpy(G.vertex[18].name, "室内田径馆");
	strcpy(G.vertex[18].info, "室内田径馆美观大方，同时也是新生报到点");
	strcpy(G.vertex[19].name, "逸夫图书馆");
	strcpy(G.vertex[19].info, "主要收藏关于理工科的书籍");
	strcpy(G.vertex[20].name, "中通快递点");
	strcpy(G.vertex[20].info, "中通快递寄存点");
	strcpy(G.vertex[21].name, "学生一食堂");
	strcpy(G.vertex[21].info, "主校区食堂，距离教学楼较近");
	strcpy(G.vertex[22].name, "南区操场");
	strcpy(G.vertex[22].info, "校运会举办的地方");
	strcpy(G.vertex[23].name, "西南门");
	strcpy(G.vertex[23].info, "学校主要的一个大门，出入的人数较多");
	strcpy(G.vertex[24].name, "北门");
	strcpy(G.vertex[24].info, "学校主要的一个大门，距离艺术学院较近");
	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
			G.arcs[j][i].adj = G.arcs[i][j].adj;
	return G;
}

// 计算出起点到各个顶点之间的最短路径,v0为起点
void ShortestPath_DIJ(AdjMatrix G) {
	int v, w, i, min, c = 0, x, ex = 1, v0;
	int last[MAX], D[MAX], p[MAX][MAX];
	while (ex) {
		printf("请输入一个起始景点编号:");
		scanf("%d", &v0);
		if (v0 < 0 || v0 > G.vexnum) {
			printf("景点编号不存在!请重新输入景点编号:");
			scanf("%d", &v0);
		}
		if (v0 >= 0 && v0 < G.vexnum) {
			ex = 0;
		}
	}
	for (v = 0; v < G.vexnum; v++) {
		last[v] = false;
		D[v] = G.arcs[v0][v].adj;
		for (w = 0; w < G.vexnum; w++)
			p[v][w] = false;
		if (D[v] < INFINITY) {
			p[v][v0] = true;
			p[v][v] = true;
		}
	}
	D[v0] = false;
	last[v0] = true;
	for (i = 1; i < G.vexnum; i++)
	{
		min = INFINITY;
		for (w = 0; w < G.vexnum; w++)
			if (!last[w])
				if (D[w] < min)
				{
					v = w;
					min = D[w];
				}
		last[v] = 1;
		for (w = 0; w < G.vexnum; w++)
			if (!last[w] && (min + G.arcs[v][w].adj < D[w]))
			{
				D[w] = min + G.arcs[v][w].adj;
				for (x = 0; x < G.vexnum; x++)
					p[w][x] = p[v][x];
				p[w][w] = true;
			}
	}
	for (v = 0; v < G.vexnum; v++)
	{
		if (v0 != v)
			printf("%s", G.vertex[v0].name);
		for (w = 0; w < G.vexnum; w++)
		{
			if (p[v][w] && w != v0)
				printf("-->%s", G.vertex[w].name);
			c++;
		}
		if (c > G.vexnum - 1 && v0 != v)
			printf("       最短总路线长%dm\n\n", D[v]);
	}
}

typedef int PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef int DistancMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

void ShortestPath_Floyd(AdjMatrix G, PathMatrix *P, DistancMatrix *D) { /* 求有向网G中各对顶点v和w之间的最短路径P[v][w]及其 */
	/* 带权长度D[v][w]。若P[v][w][u]为true,则u是从v到w当前求得最短 */
	/* 路径上的顶点。算法7.16 */
	int u, v, w, i, k, j, ex = 1;
	for (v = 0; v < G.vexnum; v++) /* 各对结点之间初始已知路径及距离 */
		for (w = 0; w < G.vexnum; w++)
		{
			(*D)[v][w] = G.arcs[v][w].adj;
			for (u = 0; u < G.vexnum; u++)
				(*P)[v][w][u] = false;
			if ((*D)[v][w] < INFINITY) /* 从v到w有直接路径 */
			{
				(*P)[v][w][v] = true;
				(*P)[v][w][w] = true;
			}
		}
	for (u = 0; u < G.vexnum; u++)
		for (v = 0; v < G.vexnum; v++)
			for (w = 0; w < G.vexnum; w++)
				if ((*D)[v][u] + (*D)[u][w] < (*D)[v][w]) /* 从v经u到w的一条路径更短 */
				{
					(*D)[v][w] = (*D)[v][u] + (*D)[u][w];
					for (i = 0; i < G.vexnum; i++)
						(*P)[v][w][i] = (*P)[v][u][i] || (*P)[u][w][i];
				}
	while (ex)
	{
		printf("请输入出发点和目的地的编号(以空格分开):\n\n");
		scanf("%d%d", &k, &j);
		if (k < 0 || k > G.vexnum || j < 0 || j > G.vexnum)
		{
			printf("景点编号不存在!请重新输入出发点和目的地的编号:\n\n");
			scanf("%d%d", &k, &j);
		}
		if (k >= 0 && k < G.vexnum && j >= 0 && j < G.vexnum)
			ex = 0;
	}
	printf("%s", G.vertex[k].name);
	for (u = 0; u < G.vexnum; u++)
		if ((*P)[k][j][u] && k != u && j != u)
			printf("-->%s", G.vertex[u].name);
	printf("--->%s", G.vertex[j].name);
	printf("      最短总路线长%dm\n", (*D)[k][j]);
}

//显示所有的景点信息
void ShowAll(AdjMatrix G) {
	int v;
	printf("       —————————————————————————————————————————————————————————————————————————————————————————\n\n");
	printf("       * 编号  	 *景点名称    	 	    *简介                                          \n\n");
	for (v = 0; v < G.vexnum; v++)
		printf("       *%-3d	 *%-15s		     %-80s\n", G.vertex[v].num, G.vertex[v].name, G.vertex[v].info);
	printf("       —————————————————————————————————————————————————————————————————————————————————————————\n\n");
}

//查询景点
void Find(AdjMatrix G) {
	int k, ex = 1;
	while (ex)
	{
		printf("请输入要查询的景点标号:\n\n");
		scanf("%d", &k);
		if (k < 0 || k > G.vexnum)
		{
			printf("请重新输入景点标号:\n\n");
			scanf("%d", &k);
		}
		if (k >= 0 && k < G.vexnum)
			ex = 0;
	}
	printf("\n\n景点编号:%d \n", G.vertex[k].num);
	printf("\n\n景点名称:%s \n", G.vertex[k].name);
	printf("\n\n景点简介:%s \n\n\n", G.vertex[k].info);
}

bool loginMenu() {
	int ch;
	while (1) {
		printf("\n");
		printf("输入1注册用户，输入2用已有用户登录，输入0退出程序\n");
		scanf("%d", &ch);
		switch (ch) {
		case 1:
			userRegister();
			break;
		case 2:
			if (userLogin()) return true;
			break;
		case 0:
			exit(0);
		default:
			printf("输入错误，请重新输入！\n");
		}
	}
}

void Display() {
	printf("\n                                      九江学院电子工程学院迎新校园导游\n\n");
	printf("                                                      \n");
	printf("                                —————————————————————————————————————————————— \n\n");
	printf("                                *            1.浏览校园全部主要地点          *\n\n");
	printf("                                *            2.查询地点信息                  *\n\n");
	printf("                                *            3.查看全部游览最短路线          *\n\n");
	printf("                                *            4.查询任意两点的最短路线        *\n\n");
	printf("                                *            5.退出系统                      *\n\n");
	printf("                                —————————————————————————————————————————————— \n\n");
	printf("选择功能如下:\n\n");
}

int main() {
	AdjMatrix g;
	PathMatrix a;
	DistancMatrix b;
	g = CreateDN();

	initRegSystem();
	while (1) {
		clearScreen();
		bool isLogin = loginMenu();
		if (!isLogin) continue;

		while (1) {
			Display();
			int i;
			scanf("%d", &i);
			if (i == 1) {
				clearScreen(); //清屏
				ShowAll(g); //显示全景
				printf("\n\n您可以继续使用本系统的其他服务，输入5退出系统!\n\n");
				continue;
			} else if (i == 2) {
				clearScreen();
				Find(g);
				printf("\n\n您可以继续使用本系统的其他服务，输入5退出系统!\n\n");
				continue;
			} else if (i == 3) {
				clearScreen();
				ShortestPath_DIJ(g);
				printf("\n\n您可以继续使用本系统的其他服务，输入5退出系统!\n\n");
				continue;
			} else if (i == 4) {
				clearScreen();
				ShortestPath_Floyd(g, &a, &b);
				printf("\n\n您可以继续使用本系统的其他服务，输入5退出系统!\n\n");
				continue;
			} else if (i == 5) {
				break;
			}
		}
	}
}

