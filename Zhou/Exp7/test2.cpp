
#include <algorithm>

#include <iostream>

#include <cstring>

#include <cstdlib>

#include <cmath>

#include <cstdio>

#include <string>

#include <stack>

#include <deque>

using namespace std;

#define MAX 0x3f3f3f

stack<int> S;

deque <int> dq;

deque <deque<int> > dd;

int mapp[16][16];//步行;

int mapp1[16][16];//驾车

int dis[16],vis[16];

int path[20];

int flag[200]= {0};

int e=0;

int aa[20]= {0};

void init();//最初将长度存好

void Query();//查询景点编号，信息，简介

void Query1();//查询两点任意最短路径及长度;

void DIS(int a,int b,int c);//计算dis数组

void dijstra(int b,int a,int c);//回溯求最短路径

void Query2();//查询两点所有路径

void QQ(int a);//最佳路径

void Query3();//查询途经多点的最短路径

void menu();//实现菜单功能

void init()

{

    memset(mapp,MAX,sizeof(mapp));

    memset(mapp1,MAX,sizeof(mapp));

    memset(dis,MAX,sizeof(dis));

    memset(vis,0,sizeof(vis));

    mapp[1][2]=mapp[2][1]=80;

    mapp[1][3]=mapp[3][1]=100;

    mapp[1][12]=mapp[12][1]=80;

    mapp[1][15]=mapp[15][1]=30;

    mapp[2][3]=mapp[3][2]=100;

    mapp[3][4]=mapp[4][3]=70;

    mapp[3][12]=mapp[12][3]=100;

    mapp[4][5]=mapp[5][4]=40;

    mapp[4][7]=mapp[7][4]=100;

    mapp[5][6]=mapp[6][5]=150;

    mapp[6][8]=mapp[8][6]=200;

    mapp[7][8]=mapp[8][7]=50;

    mapp[7][10]=mapp[10][7]=50;

    mapp[7][11]=mapp[11][7]=20;

    mapp[8][9]=mapp[9][8]=20;

    mapp[8][10]=mapp[10][8]=30;

    mapp[9][10]=mapp[10][9]=40;

    mapp[9][14]=mapp[14][9]=40;

    mapp[10][11]=mapp[11][10]=20;

    mapp[10][14]=mapp[14][10]=30;

    mapp[11][12]=mapp[12][11]=70;

    mapp[12][13]=mapp[13][12]=20;

    mapp[12][15]=mapp[15][12]=50;

    mapp[13][14]=mapp[14][13]=20;

    mapp1[1][3]=mapp1[3][1]=120;

    mapp1[1][12]=mapp1[12][1]=80;

    mapp1[12][11]=mapp1[11][12]=70;

    mapp1[1][13]=mapp1[13][1]=100;

    mapp1[1][15]=mapp1[15][1]=30;

    mapp1[3][4]=mapp1[4][3]=70;

    mapp1[4][5]=mapp1[5][4]=40;

    mapp1[5][6]=mapp1[6][5]=150;

    mapp1[6][8]=mapp1[8][6]=200;

    mapp1[6][9]=mapp1[9][6]=300;

    mapp1[9][14]=mapp1[14][9]=40;

    mapp1[13][14]=mapp1[14][13]=20;

//    int i,j,k;

//    for(k=1;k<=15;k++)

//        for(i=1;i<=15;i++)

//           for(j=1;j<=15;j++)

//              if(mapp[i][j]>mapp[i][k]+mapp[k][j])

//                  mapp[i][j]=mapp[i][k]+mapp[k][j];

//    for(k=1;k<=15;k++)

//        for(i=1;i<=15;i++)

//           for(j=1;j<=15;j++)

//              if(mapp1[i][j]>mapp1[i][k]+mapp1[k][j])

//                  mapp1[i][j]=mapp1[i][k]+mapp1[k][j];

 

}

void Query()

{

    int a;

    cout<<"=========景点编号========="<<endl;

    cout<<"= 1. 东门       2. 操场  ="<<endl;

    cout<<"= 3. 一餐       4. 二餐  ="<<endl;

    cout<<"= 5. 三餐       6. 南门  ="<<endl;

    cout<<"= 7. 图书馆     8. 大活  ="<<endl;

    cout<<"= 9. 办公楼     10.四教  ="<<endl;

    cout<<"= 11.二教       12.一教  ="<<endl;

    cout<<"= 13.三教       14.五教  ="<<endl;

    cout<<"=15. 体育馆              ="<<endl;

    cout<<"========================="<<endl;

    cout<<"输入你想查询景点信息的编号(1 ~ 15)：";

    cin>>a;

    if(a==1)

        cout<<"* 山东工商学院大门，因面朝东面被称为东门!"<<endl;

    if(a==2)

        cout<<"* 操场有400米跑道，足球场，可以进行户外活动！"<<endl;

    if(a==3)

        cout<<"* 山东工商学院第一餐厅！"<<endl;

    if(a==4)

        cout<<"* 山东工商学院第二餐厅！"<<endl;

    if(a==5)

        cout<<"* 山东工商学院第三餐厅（东苑餐厅）！"<<endl;

    if(a==6)

        cout<<"* 山东工商学院南门，面朝南面得名！"<<endl;

    if(a==7)

        cout<<"* 图书馆可以借书，上自习，进入需刷校园卡！"<<endl;

    if(a==8)

        cout<<"* 大学生艺术活动中心，举办大型活动！"<<endl;

    if(a==9)

        cout<<"* 俗称七教，学校领导办公的地方！"<<endl;

    if(a==10)

        cout<<"* 马克思主义学院！"<<endl;

    if(a==11)

        cout<<"* 计算机科学与技术学院！"<<endl;

    if(a==12)

        cout<<"* 最古老的一栋楼，现用来办公！"<<endl;

    if(a==13)

        cout<<"* 数学院！"<<endl;

    if(a==14)

        cout<<"* 统计学院！"<<endl;

    if(a==15)

        cout<<"* 可以打乒乓球，排球，羽毛球，篮球……注意进门登记哦！"<<endl;

}

void Query1()

{

    int a,b,c;

    cout<<"======出行方式====="<<endl;

    cout<<"1.步行."<<endl;

    cout<<"2.驾车."<<endl;

    cout<<"================="<<endl;

    cout<<"输入你的选择(1 or 2)：";

    cin>>a;

    cout<<"输入起点编号：";

    cin>>b;

    cout<<"输入终点编号：";

    cin>>c;

    if(b<=0&&b>=16||c<=0&&c>=16)

        cout<<"输入错误，景点不存在。"<<endl;

    else

        dijstra(b,a,c);

}

void DIS(int a,int b,int c)//计算dis数组

{

    memset(path,0,sizeof(path));

    int i,j,pos=1,minn,sum=0;

    memset(vis,0,sizeof(vis));

    for(i=1; i<=15; i++)

    {

        if(a==1)

            dis[i]=mapp[b][i];

        if(a==2)

            dis[i]=mapp1[b][i];

    }

    vis[b]=1;

    dis[b]=0;

    for(i=1; i<=15; i++)

    {

        minn=MAX;

        for(j=1; j<=15; j++)

        {

            if(vis[j]==0&&minn>dis[j])

            {

                minn=dis[j];

                pos=j;

            }

        }

        vis[pos]=1;

        for(j=1; j<=15; j++)

        {

            if(a==1)

            {

                if(vis[j]==0&&dis[j]>dis[pos]+mapp[pos][j])

                {

                    dis[j]=dis[pos]+mapp[pos][j];

                    path[j]=pos;

                }

            }

            if(a==2)

            {

                if(vis[j]==0&&dis[j]>dis[pos]+mapp1[pos][j])

                {

                    dis[j]=dis[pos]+mapp1[pos][j];

                    path[j]=pos;

                }

            }

        }

    }

}

void dijstra(int b,int a,int c)

{

    DIS(a,b,c);

    int x=c;

    while(!S.empty())

        S.pop();

//    for(i=1;i<=15;i++)

//        cout<<i<<" "<<path[i]<<endl;

//    cout<<endl;

    while(1)

    {

        if(x==0)

            break;

        S.push(x);

        x=path[x];

    }

    S.push(b);

    if(dis[c]>=100000)

        cout<<"没有直达的路，请选择步行。"<<endl;

    else

    {

        cout<<"从"<<b<<"到"<<c<<"的最短路径为：";

        while(!S.empty())

        {

            if(S.size()>1)

                cout<<S.top()<<"->";

            else

                cout<<S.top();

            S.pop();

        }

        cout<<endl<<"其最短距离为："<<dis[c]<<endl;

    }

 

}

void DFS1(int b,int c)

{

    int i,j;

    vis[b] = 1;

    dq.push_back(b);

    for (j = 1; j <=15; j++)

    {

        if (j==c&&mapp[j][b]<=2000)

        {

            dd.push_back(dq);

            //return ;

        }

        if (vis[j]==0&&mapp[b][j]<=2000)

            DFS1(j,c);

    }

    vis[dq.back()] = 0;

    dq.pop_back();

}

void DFS2(int b,int c)

{

    int i,j;

    vis[b] = 1;

    dq.push_back(b);

    for (j = 1; j <=15; j++)

    {

        if (j==c&&mapp1[j][b]<=2000)

        {

            dd.push_back(dq);

//            return;

        }

        if (vis[j]==0&&mapp1[b][j]<=2000)

            DFS2(j,c);

    }

    vis[dq.back()] = 0;

    dq.pop_back();

}

void Query2()

{

    init();

    int a,b,c,i,j;

    cout<<"======出行方式====="<<endl;

    cout<<"    1.步行."<<endl;

    cout<<"    2.驾车."<<endl;

    cout<<"==================="<<endl;

    cout<<"输入你的选择(1 or 2)：";

    cin>>a;

    cout<<"输入起点编号：";

    cin>>b;

    cout<<"输入终点编号：";

    cin>>c;

    // 队列 数组清零

    while(!dq.empty())

        dq.pop_front();

    while(!dd.empty())

        dd.pop_front();

    memset(vis,0,sizeof(vis));

    if(a==1)

        DFS1(b,c);

    else

        DFS2(b,c);

    if(dd.size()>=3)

    {

        cout<<"有三条以上（含3条），只输出前三条较短的路径:"<<endl;

        int p=0;

        for(i=1;; i++)

        {

            int g=dd.size();

            for(j=0; j<g; j++)

            {

                if(dd.front().size()==i)

                {

                    while(!dd.front().empty())

                    {

                        cout<<dd.front().front()<<" ";

                        dd.front().pop_front();

                    }

                    cout<<c<<endl;

                    p++;

                    if(p==3)

                        return;

                    dd.pop_front();

                    continue;

                }

                dd.push_back(dd.front());

                dd.pop_front();

            }

        }

    }

    else if(dd.size()!=0)

    {

 

        while(!dd.empty())

        {

            while(!dd.front().empty())

            {

                cout<<dd.front().front()<<" ";

                dd.front().pop_front();

            }

            cout<<c<<endl;

            dd.pop_front();

        }

    }

    else

        cout<<"没有直接相连的路径!!!"<<endl;

 

}

/*int Prim(int a,int x)

{

    init();

    int i,j,now;

    int sum=0;

    for(i=1; i<=15; i++)

    {

        dis[i]=MAX;

        vis[i]=0;

    }

    for(i=1; i<=15; i++)

    {

        if(a==1)

            dis[i]=mapp[x][i];

        else

            dis[i]=mapp1[x][i];

    }

    dis[x]=0;

    vis[x]=1;

    for(i=1; i<15; i++)

    {

        now=MAX;

        int min1=MAX;

        for(j=1; j<=15; j++)

        {

            if(vis[j]==0&&dis[j]<min1)

            {

                now=j;

                min1=dis[j];

            }

        }

        if(now==MAX)

            break;//防止不成图

        vis[now]=1;

        sum+=min1;

        if(a==1)

        {

            for(j=1; j<=15; j++)//添入新点后更新最小距离

            {

                if(vis[j]==0&&dis[j]>mapp1[now][j])

                {

                    dis[j]=mapp[now][j];

                    path[j]=now;

                }

            }

        }

        else

        {

            for(j=1; j<=15; j++)//添入新点后更新最小距离

            {

                if(vis[j]==0&&dis[j]>mapp1[now][j])

                {

                    dis[j]=mapp1[now][j];

                    path[j]=now;

                }

            }

        }

    }

}*/

void QQ(int a)

{

    int i,j,k,flag1=0;

    // 队列 数组清零

    while(!dq.empty())

        dq.pop_front();

    while(!dd.empty())

        dd.pop_front();

    memset(vis,0,sizeof(vis));

    //cout<<aa[e-1]<<"**"<<endl;

    if(a==1)

        DFS1(aa[0],aa[e-1]);

    else

        DFS2(aa[0],aa[e-1]);

    int n=dd.size();

    int yang=0;

    //DIS(a,aa[0],aa[e-1]);

    //cout<<" *****"<<n<<endl;

    for(k=1;k<=20; k++)

    {

        for(i=0; i<n; i++)

        {

            int m=dd.front().size();

            int sum=0;

            //cout<<"******"<<m<<endl;

            for(j=0; j<m; j++)

            {

                int hh=dd.front().front();

                if(flag[hh]==1)

                    sum++;

                dd.front().pop_front();

                dd.front().push_back(hh);

            }

            //cout<<"++++++"<<e-1<<endl;

            //cout<<"******"<<sum<<endl;

            if(sum>=e-1&&m==k)

            {

                flag1=1;

                yang++;

                if(yang==2)

                    return ;

                cout<<"路径为：";

                for(j=0;j<m;j++)

               // while(!dd.front().empty())

                {

                    cout<<dd.front().front()<<" ";

                    dd.front().push_back(dd.front().front());

                    dd.front().pop_front();

                }

                cout<<aa[e-1]<<" ";

                cout<<endl;

                //cout<<"其路径长度为："<<dis[aa[e-1]]<<endl;

 

            }

            dd.push_back(dd.front());

            dd.pop_front();

        }

 

    }if(flag1==0)

            cout<<"**不存在这样的路径"<<endl;

}

void Query3()

{

    init();

    int a;

    memset(aa,0,sizeof(aa));

    memset(flag,0,sizeof(flag));

    cout<<"======出行方式====="<<endl;

    cout<<"    1.步行."<<endl;

    cout<<"    2.驾车."<<endl;

    cout<<"==================="<<endl;

    cout<<"输入你的选择(1 or 2)：";

    cin>>a;

    cout<<"输入经过的点（以0结束,默认开始为起始点）：";

    int b;

    while(1)

    {

        cin>>b;

        if(b==0)

            break;

        else

        {

            aa[e++]=b;

            flag[b]=1;

        }

    }

    aa[e]=0;

    // Prim(a,aa[0]);

    QQ(a);

}

void PP()

{

    cout<<"==================================山商平面图===================================="<<endl;

    cout<<"--------------------------------------------------------------------------------"<<endl;

    cout<<"|                             | 6.南门 |--------------------------------|      |"<<endl;

    cout<<"|        ...........              |   |                                 |      |"<<endl;

    cout<<"|        | 5.三餐 |---------------   ---------------------|             |      |"<<endl;

    cout<<"|        ```````````  |                                ---------        |      |"<<endl;

    cout<<"|        ...........  |                                |  8    |        |      |"<<endl;

    cout<<"|        | 4.二餐 |---                                 | 大活  |        |      |"<<endl;

    cout<<"|        ```````````  |           -----------          |       |        |      |"<<endl;

    cout<<"|                     |           |   7     |          ---------        |      |"<<endl;

    cout<<"|                     |-----------| 图书馆  |--------|      |           |      |"<<endl;

    cout<<"|    ..........       |           |         |        |      |         -------  |"<<endl;

    cout<<"| ---| 3.一餐 |-------|           -----------        |      |         |     |  |"<<endl;

    cout<<"| |  ``````````                                      |      |         |  9  |  |"<<endl;

    cout<<"| |       |-------                                   --------         |  办 |  |"<<endl;

    cout<<"| |              |   --------         ----------     | 10    |--------|  公 |  |"<<endl;

    cout<<"| |   ------     |  |  12   |         |   11    |----| 四教 |         |  楼 |  |"<<endl;

    cout<<"| |  |  2  |--------| 一教  |---------|  二教  |     --------         |     |  |"<<endl;

    cout<<"| |  | 操场|        --------          ----------           |          -------  |"<<endl;

    cout<<"| |   ------            |                                  |              |    |"<<endl;

    cout<<"|-----|----------------------------|-----------------------|--------------|    |"<<endl;

    cout<<"|  1  |    -----------  |      ----------              ----------              |"<<endl;

    cout<<"| 东门|----|  15     |--|      |   13    |             |   14   |              |"<<endl;

    cout<<"|-----|    |  体育馆 |         |  三教   |             |  五教  |              |"<<endl;

    cout<<"|          |         |         ----------              ----------              |"<<endl;

    cout<<"--------------------------------------------------------------------------------"<<endl;

}

void menu()

{

    int a;

    init();

    while(1)

    {

        cout<<"============菜单============"<<endl;

        cout<<"0.退出."<<endl;

        cout<<"1.查询所有景点信息."<<endl;

        cout<<"2.查询两景点的最短路径."<<endl;

        cout<<"3.查询两景点的所有路径."<<endl;

        cout<<"4.查询多景点的最佳路径."<<endl;

cout<<"5.山东工商学院平面图."<<endl;

        cout<<"==========================="<<endl;

        cout<<"输入你的选择(0 ~ 4)：";

        cin>>a;

        if(a==0)

            break;

        if(a==1)

            Query();

        if(a==2)

            Query1();

        if(a==3)

            Query2();

        if(a==4)

            Query3();

        if(a==5)

            PP();

    }

}

int main()

{

    menu();

    return 0;

}

