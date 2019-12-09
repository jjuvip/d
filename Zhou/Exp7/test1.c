#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
typedef struct
{
    char name[20];
    char password[20];
} User;
//节点结构体
typedef   struct
{
    int num;
    char name[20];
    char features[100];
} Vertex;
//矩阵结构体
typedef struct
{
    Vertex vexs[100];
    int edges[500][500];
    int n,e;//点和边数
} Graph;
void write(User users[],int n)//将注册信息写入文件
{
    FILE *fp;
    if((fp=fopen("data.txt","wb+"))==NULL)
        printf("文件打开失败");
    else
    {
        //printf("%s",users[0].password);
        fwrite(users,sizeof(User),1,fp);
    }
    fclose(fp);
}
//构造图的矩阵存储
void create(Graph *G )
{
    int i,j;
    G->n=12;
    G->e=20;
    char str_name[50][50]= {"体检中心","邯郸音乐厅","网计学院","信息学部","操场","图书馆",
                            "花园景观","校门南口","校门北口","校门东口","银杏景观","餐厅"
                           };
    char str_features[100][200]= {"学生进行体检的地方","举办晚会的地方","C1楼","信息学部","操场","A6旁边的一栋楼","花园景观"
                                  "校门南口","校门北口","校门东口","银杏景观","餐厅"
                                 };
    int num[50]= {33,32,31,34,23,22,21,20,10,11,0,1};
    for(i=0; i<G->n; i++)//节点信息初始化
    {
        strcpy(G->vexs[i].name,str_name[i]);
        strcpy(G->vexs[i].features,str_features[i]);
        G->vexs[i].num=num[i];
    }
    //int rode[G->e][G->e];
    for(i=0; i<500; i++)
        for(j=0; j<500; j++)
            G->edges[i][j]=9999;
    G->edges[1][0]=G->edges[0][1]=200;
    G->edges[4][0]=G->edges[0][4]=350;
    G->edges[1][2]=G->edges[2][1]=500;
    G->edges[2][7]=G->edges[7][2]=400;
    G->edges[1][4]=G->edges[4][1]=480;
    G->edges[1][5]=G->edges[5][1]=400;
    G->edges[1][3]=G->edges[3][1]=500;
    G->edges[7][3]=G->edges[3][7]=500;
    G->edges[6][3]=G->edges[3][6]=300;
    G->edges[7][6]=G->edges[6][7]=500;
    G->edges[7][9]=G->edges[9][7]=600;
    G->edges[4][5]=G->edges[5][4]=280;
    G->edges[4][8]=G->edges[8][4]=200;
    G->edges[5][6]=G->edges[6][5]=200;
    G->edges[5][9]=G->edges[9][5]=300;
    G->edges[6][9]=G->edges[9][6]=200;
    G->edges[9][11]=G->edges[11][9]=100;
    G->edges[8][11]=G->edges[11][8]=100;
    G->edges[8][10]=G->edges[10][8]=100;
    G->edges[10][11]=G->edges[11][10]=100;
}
//遍历景点
int ergodic(Graph *G,int v)
{
    int i;
    for(i=0; i<G->n; i++)
    {
        if(G->vexs[i].num==v)
            return i;
    }
    return -1;
    //printf("%d",i);
}
void display(Graph *G)
{
    int k=-1;
    int i,j;
    printf("\n\n");
    printf("                                 有 %d 个景点,   有 %d 条路\n\n\n\n",G->n,G->e);
    for(i=0; i<G->n; i++)
    {
        //printf("                        有 %d 个景点,   有 %d 条边\n\n",G->n,G->e);
        printf("                        序号为:%d   \t名字为:%s\t    \t编号为：%d\n\n",i,G->vexs[i].name,G->vexs[i].num);//编号,名称
    }
    for(i=0; i<G->n; i++)
    {
        for(j=0; j<G->n; j++)
            if(G->edges[i][j]!=9999)
            {
             k++;
                if(k==3)
                {
                    k=0;
                    printf("\n\n");
                }
                printf("           \t%d   \t%d:  \t%d",i,j,G->edges[i][j]);
            }
    }
    printf("\n\n");
}
//任意景点的介绍
Vertex GetVex(Graph *G, int v)
{
    int j;
    j=ergodic(G,v);
    if(j==-1)
    {
        printf("                        无此景点\n\n\n\n");
        Sleep(1000);
        return ;
    }
    else
    {
        Vertex a=G->vexs[j];
        return a;
    }
    // printf("%s",G->vexs[v].name);
}
//修改景点信息
void PutVertex(Graph *G, int v)
{
    int j;
    j=ergodic(G,v);
    if(j==-1)
    {
        printf("                         无此景点\n\n\n\n\n");
        Sleep(1000);
    }
    else
    {
        char s[100];
        printf("\n");
        printf("                         请输入修改后的信息:\n\n");
        printf("                         ");
        scanf("%s",s);
        strcpy(G->vexs[j].features,s);
        //printf("%s",G->vexs[j].features);
        printf("\n");
        printf("                         修改成功\n\n\n\n\n");
    }
}
//增加景点
void InsertVertex(Graph*G, Vertex v)
{
    char str_name[20],str_features[100];
    int num,edge,a[100],i,a1[100],b;
    printf("                       请输入景点名称:\n\n");
    printf("                            ");
    scanf("%s",str_name);
    strcpy(v.name,str_name);
    printf("\n");
    printf("                       请输入景点编号:\n\n");
    printf("                           ");
    scanf("%d",&num);
    v.num=num;
    printf("\n");
    printf("                       请输入景点介绍：\n\n");
    printf("                            ");
    scanf("%s",str_features);
    strcpy(v.features,str_features);
    printf("\n");
    printf("                       请输入新增景点的边数：\n\n");
    printf("                            ");
    scanf("%d",&edge);
    printf("\n");
    printf("                       请输入与新增景点连通的景点编号以及路径长度：\n\n");
    G->e+=edge;
    G->n=G->n+1;
    G->vexs[G->n-1]=v;
    for(i=0; i<G->n; i++)
        G->edges[G->n-1][i]=G->edges[i][G->n-1]=9999;//初始化
    for(i=0; i<edge; i++)
    {
        printf("                            ");
        scanf("%d%d",&a1[i],&b);//编号和长度
        a[i]=ergodic(G,a1[i]);
        G->edges[G->n-1][a[i]]=G->edges[a[i]][G->n-1]=b;
        printf("\n");
    }
}
//删除景点,删除路
//判断是否有该点
void DeleteVertex(Graph *G, Vertex v)
{
    int num,a,b=0,i;
    printf("                       请输入要删除景点编号:\n\n");
    printf("                            ");
    scanf("%d",&num);
    a=ergodic(G,num);
    if(a==-1)
    {
        printf("                         无此景点\n\n\n\n\n");
        Sleep(1000);
    }
    else
    {
        strcpy(v.features,"");
        strcpy(v.name,"");
        v.num=-9999;//已删除节点的编号为负的
        for(i=0; i<G->n; i++)
        {
            if(G->edges[a][i]!=9999)
            {
                G->edges[a][i]=G->edges[i][a]=9999;
                b++;
            }
        }
        G->e=G->e-b;
        G->n=G->n-1;
        //printf("景点删除成功");
    }
}
//增加道路
void InsertArc(Graph *G,int v, int w)
{
    int length;
    printf("                       请输入新加道路的长度:\n\n");
    printf("                            ");
    scanf("%d",&length);
    int a=ergodic(G,v);
    printf("%d",a);
    int b=ergodic(G,w);
    G->edges[a][b]=G->edges[b][a]=length;
    //printf("道路添加成功");
}
//删除道路
void DeleteArc(Graph*G,int v,int w)
{
    int a=ergodic(G,v);
    int b=ergodic(G,w);
    if(a==-1||b==-1)
    {
        printf("                         无此景点\n\n\n\n\n");
        Sleep(1000);
    }
    else
        G->edges[a][b]=G->edges[b][a]=9999;
}
//查找某一景点到其他景点的最短路径
void ShortestPath(Graph *G, int P[ ], int D[ ])
{
    int i,k,j,pre=-1;
    printf("                       请输入要查找的景点的编号：\n\n");
    printf("                            ");
    int min;
    int a;
    scanf("%d",&a);
    int v=ergodic(G,a);
    if(v==-1)
    {
        printf("                         无此景点\n\n\n\n\n");
        Sleep(1000);
    }
    else
    {
        int flag[G->n];//标记是否找过
        for(i=0; i<G->n; i++) //初始化D[]
        {
            flag[i]=0;
            D[i]=G->edges[v][i];//初始化
            P[i]=-1;
        }
        flag[v]=1;
        for(i=0; i<G->n; i++)
        {
            min=10000;
            for(k=0; k<G->n; k++)
                if(flag[k]==0&&D[k]<min)
                {
                    min=D[k];
                    j=k;
                }//每次找到最小的那个
            flag[j]=1;
            for(k=0; k<G->n; k++)
                if(flag[k]==0&&D[k]>D[j]+G->edges[j][k])
                {
                    D[k]=D[j]+G->edges[j][k];
                    P[k]=j;//前驱节点
                }
        }
        system("cls");
        for(i=0; i<G->n; i++)
        {
            printf("\n\n");
            printf("                            %d:%s",D[i],G->vexs[i].name);
            pre=P[i];
            while(pre>=0)
            {
                //printf("<-%d",pre);
                printf("<-%s",G->vexs[pre].name);
                pre=P[pre];
            }
            printf("<-%s",G->vexs[v].name);
        }
        printf("\n\n");
    }
}
//查找任意俩点间的最短路径
void ToDestination(Graph *G, int v, int w)
{
    int flag[G->n];
    int D[G->n];
    int P[G->n];
    int a=ergodic(G,v);
    int b=ergodic(G,w);
    int i,min,j,k;
    for(i=0; i<G->n; i++) //初始化D[]
    {
        flag[i]=0;
        D[i]=G->edges[a][i];//初始化
        P[i]=-1;
    }
    flag[a]=1,P[a]=0;
    for(i=0; i<G->n; i++)
    {
        min=10000;
        for(k=0; k<G->n; k++)
            if(flag[k]==0&&D[k]<min)
            {
                min=D[k];
                j=k;
            }//每次找到最小的那个
        flag[j]=1;
        for(k=0; k<G->n; k++)
            if(flag[k]==0&&D[k]>D[j]+G->edges[j][k])
            {
                D[k]=D[j]+G->edges[j][k];
                P[k]=j;//前驱节点
            }
    }
    //printf("\n\n");
    int t;
    t=P[b];
    //printf("%d",P[b]);
    printf("%s",G->vexs[a].name);
    while(t!=a&&t!=-1)
    {
    printf("->%s",G->vexs[t].name);
    t=P[t];
    //printf("%d",t);
    }
    printf("->%s",G->vexs[b].name);
    printf("                       俩点间的最短距离为：%d\n\n",D[b]);
}

int  show()
{
    printf("                                       景点介绍请按                               1\n\n");
    printf("                                       修改景点信息请按                           2\n\n");
    printf("                                       增加景点请按                               3\n\n");
    printf("                                       删除景点请按                               4\n\n");
    printf("                                       增加道路请按                               5\n\n");
    printf("                                       删除道路请按                               6\n\n");
    printf("                                       查找某一景点到其他任意景点的最短路径请按   7\n\n");
    printf("                                       查找任意俩个景点的最短路径请按             8\n\n");
    printf("                                       退出导航请按                               9\n\n");
    printf("                                       请选择相应的功能:                          ");
    int data;
    scanf("%d",&data);
    return data;
}

int show_1()
{
    printf("                                       景点介绍请按                               1\n\n");
    printf("                                       查找某一景点到其他任意景点的最短路径请按   2\n\n");
    printf("                                       查找任意俩个景点的最短路径请按             3\n\n");
    printf("                                       退出导航请按                               9\n\n");
    printf("                                       请选择相应的功能:                          ");
    int data;
    scanf("%d",&data);
    return data;
}
int main()
{
    Graph G;
    create(&G);
    //printf("%d",G.edges[1][0]);
    //printf("%d",G.vexs[8].num);
    User users[20];
    char a;
    printf(" \n\n\n\n\n\n\n\n                                                 欢迎进入校园导航系统\n");
    printf("\n                     管理员注册请按A，游客注册请按B\n\n");
    printf("                     登录请按C\n\n");
    printf("                                  ");
    scanf(" %c",&a);
   //getchar();
    if(a=='B')
    {
        printf("                     用户名：");
        scanf("%s",users[0].name);
        printf("\n");
        printf("                     密码：");
        scanf("%s",users[0].password);
        write(users,2);
        //getchar();
        system("cls");
        printf("\n\n\n\n");
         printf("                   注册成功");
        main();
    }
    else if(a=='A')
    {
        printf("\n");
        printf("                     用户名：\n\n");
        printf("                      ");
        scanf("%s",users[0].name);
        strcpy(users[0].password,"12345");
        write(users,2);
        printf("\n\n\n");
        printf("                        注册成功");
        //getchar();
        main();
    }
    else if(a=='C')
    {
        char name_1[100];
        char password_1[100];
        FILE *fp;
        if((fp=fopen("data.txt","rb"))==NULL)
            printf("文件打开失败");
        else
        {
            fread(&users[0],sizeof(User),1,fp);
        }
        fclose(fp);
        printf("\n");
        printf("                      请输入用户名和密码:\n");
        printf("\n");
        printf("                      用户名：");
        scanf("%s",name_1);
        printf("\n");
        printf("                      密码：");
        scanf("%s",password_1);
        if(strcmp(name_1,users[0].name)==0&&strcmp(password_1,users[0].password)==0)
        {
            system("cls");
            printf("\n\n                                                  登陆成功\n\n\n");
            //管理员登录
            if(strcmp(password_1,"12345")==0)
            {
                int data;
                while(1)
                {
                    display(&G);
                    data=show();
                    printf("\n");
                    if(data==1)
                    {
                        //display(&G);
                        printf("                       请输入要查询的景点编号:       ");
                        int v;
                        scanf("%d",&v);
                        Vertex a=GetVex(&G,v);
                        system("cls");
                        printf("\n");
                        printf("                         ");
                        printf("%s\n\n\n\n",a.features);

                    }
                    else if(data==2)
                    {
                        //display(&G);
                        int nold;
                        printf("                       请输入要修改信息的景点编号:       ");
                        scanf("%d",&nold);
                        system("cls");
                        PutVertex(&G,nold);
                    }
                    else if(data==3)
                    {
                        Vertex d;
                        InsertVertex(&G,d);
                        //system("cls");
                        system("cls");
                       // display(&G);
                        printf("\n\n\n\n");
                        printf("                                           景点添加成功\n\n\n\n");
                    }
                    else if(data==4)
                    {
                        Vertex v;
                        DeleteVertex(&G,v);
                        system("cls");
                        //display(&G);
                        printf("\n\n\n\n");
                        //printf("                                           景点删除成功\n\n\n\n");
                    }
                    else if(data==5)
                    {
                        int v,w;
                        printf("                       请输入与新增路连接的景点编号:\n\n");
                        printf("                            ");
                        scanf("%d%d",&v,&w);
                        InsertArc(&G,v,w);
                        system("cls");
                        //display(&G);
                        printf("\n\n\n\n");
                        printf("                                            道路添加成功\n\n\n\n");

                    }
                    else if(data==6)
                    {
                        int v1,w1;
                        printf("                       请输入与要删除路连接的景点编号:\n\n");
                        printf("                            ");
                        scanf("%d%d",&v1,&w1);
                        DeleteArc(&G,v1,w1);
                        system("cls");
                        //display(&G);
                        printf("\n\n\n\n");
                        //printf("                                            道路删除成功\n\n\n\n");
                    }
                    else if(data==7)
                    {
                        int P[1000],D[1000];
                        ShortestPath(&G, P,D);
                    }
                    else if(data==8)
                    {

                        system("cls");
                        int v,w;
                        printf("                       请输入要查找最短距离的俩个点的编号：\n\n");
                        printf("                            ");
                        scanf("%d%d",&v,&w);
                        printf("\n");
                        ToDestination(&G,v,w);
                        printf("\n\n");
                    }
                    else if(data==9)
                    {
                        exit(0);
                    }
                }
            }
            //游客登录
            else
            {
                int data;
                while(1)
                {
                    display(&G);
                    data=show_1();
                    printf("\n");
                    if(data==1)
                    {
                        printf("                       请输入要查询的景点编号:       ");
                        int v;
                        scanf("%d",&v);
                        Vertex a=GetVex(&G,v);
                        system("cls");
                        printf("\n");
                        printf("                         ");
                        printf("%s\n\n",a.features);
                        printf("\n\n\n\n");
                    }
                    else if(data==2)
                    {
                        int P[1000],D[1000];
                        ShortestPath(&G, P,D);
                    }
                    else if(data==3)
                    {
                        system("cls");
                        int v,w;
                        printf("\n\n\n\n");
                        printf("                       请输入要查找最短距离的俩个点的编号：\n\n");
                        printf("                            ");
                        scanf("%d%d",&v,&w);
                        printf("\n");
                        ToDestination(&G,v,w);
                        printf("\n\n");
                    }
                    else if(data==9)
                    {
                        exit(0);
                    }
                }
            }
        }
        else
        {
            system("cls");
            printf("\n\n\n\n\n                                   登录失败，请重新登陆");
            //getchar();
            main();
        }
    }
    return 0;
}


