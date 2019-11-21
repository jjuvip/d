#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

//定义结构存储排序名称，比较次数，移动次数和排序时间。
struct node{
    char* name;
    int cmp;
    int mov;
    int time; 
}S[6];

class Sort
{
public:
    int *r;
    int *a; //数组首地址，开辟空间以存储待排序数据。 
    int n; // 待排序数据个数 
    int MoveNum; 
    int CompNum;
public:
    void ini();
    void insert();
    void bubble();
    void quick(int,int);
    void select();
    void shell();
    int partion(int,int);
    void Qsort(int,int);
    void HeapSort();
    void CreateHeap(int& ,int&);
    void HeapAdjust(int,int,int&,int&); 
    ~ Sort();
};
//析构函数,释放内存。 
Sort::~Sort()
{
    delete []r;
    delete []a;
}

void Sort::ini() 
{
    n=1000;
    r=new int[n+1];
    a=new int[n+1];
    for (int i=1;i<=n;i++)
        a[i]=rand();
}

void Sort::insert()
{
    memcpy(r,a, (n+1)*sizeof(int));
    int i,j;
    MoveNum=0; CompNum=0;
    clock_t p1=clock();
    for(i=2;i<=n;i++)
        if(r[i]<r[i-1])
        {
            r[0]=r[i];
            for(j=i-1;r[j]>r[0];j--)
            {   
                r[j+1]=r[j];
                MoveNum++;
            }
            r[j+1]=r[0];
            CompNum+=2;
        }
        else CompNum+=1;
    clock_t p2=clock();
    CompNum=MoveNum+CompNum;
    cout<<"插入排序: "<<MoveNum<<"  "<<CompNum<<endl;
    S[0].cmp+=CompNum;
    S[0].mov+=MoveNum;
    S[0].time+=(p2-p1);
}

void Sort::bubble()
{
    memcpy(r,a, (n+1)*sizeof(int));
    int count=0;
     MoveNum=0;
     CompNum=0;
    int pos=n;
    clock_t p1=clock();
    while(pos!=0)
    {
        int bound=pos;
        pos=0;
        for(int i=1;i<bound;i++)
        {
            CompNum++;
            if(r[i]>r[i+1])
            {
                r[0]=r[i];
                r[i]=r[i+1];
                r[i+1]=r[0];
                pos=i;
                count++;
            }
        }
    }
    clock_t p2=clock();
    MoveNum=count*3;
     cout<<"冒泡排序: "<<MoveNum<<"  "<<CompNum<<endl;
    S[1].cmp+=CompNum;
    S[1].mov+=MoveNum;
    S[1].time+=(p2-p1);
}              

void Sort::quick(int i,int j){
    if(i<j){
        int loc=partion(i,j);
        quick(i,loc-1);
        quick(loc+1,j);
    }
}

void Sort::Qsort(int i,int j){
    memcpy(r,a, (n+1)*sizeof(int));
    MoveNum=0; CompNum=0;
    clock_t p1=clock();
    quick(i,j);
    clock_t p2=clock();
 cout<<"快速排序: "<<MoveNum<<"  "<<CompNum<<endl;
    S[2].cmp+=CompNum;
    S[2].mov+=MoveNum;
    S[2].time+=(p2-p1);
}

int Sort::partion(int first,int end){
    int i=first;
    int j=end;
    int pivot=r[i];
    while(i<j){
        MoveNum++;
        while((i<j)&&r[j]>=pivot){
            j--;  
            CompNum++;
        }   
        r[i]=r[j]; MoveNum++;
        while((i<j)&&r[i]<=pivot){
            i++; CompNum++;
        }
        r[j]=r[i]; MoveNum++;
    }
    r[i]=pivot;
    return i;
}

void Sort::select()
{
    memcpy(r,a, (n+1)*sizeof(int));
    int count=0;
    int MoveNum=0;int CompNum=0;
    clock_t p1=clock();
    for(int i=1;i<n;i++){
        int index=i;
        for(int j=i+1;j<=n;j++){
            if(r[j]<r[index])
                index=j;
            CompNum++;
        }
        if(index!=i){
            r[0]=r[i];
            r[i]=r[index];
            r[index]=r[0];
            count++;
        }
    }
    clock_t p2=clock();
    MoveNum=count*3;
     cout<<"选择排序: "<<MoveNum<<"  "<<CompNum<<endl;
    S[3].cmp+=CompNum;
    S[3].mov+=MoveNum;
    S[3].time+=(p2-p1);
}
void  Sort::shell()
{
    memcpy(r,a, (n+1)*sizeof(int));
    MoveNum=0; CompNum=0;
    clock_t p1=clock();
    for(int d=n/2;d>=1;d=d/2)
    {
        for(int k=d+1;k<=n;k++)
        {
            CompNum++;
            if(r[k]<r[k-d])
            {
                r[0]=r[k];
                int j=k-d;
                for(;j>0&&r[0]<r[j];j=j-d)
                {
                    CompNum++;
                    r[j+d]=r[j];
                    MoveNum++;
                }
                r[j+d]=r[0];               
            }        
        }
    }
    clock_t p2=clock();
    cout<<"希尔排序: "<<MoveNum<<"  "<<CompNum<<endl;
    S[4].cmp+=CompNum;
    S[4].mov+=MoveNum;
    S[4].time+=(p2-p1);
}

void Sort::CreateHeap(int &mov,int &cmp){
    for(int i=n/2;i>0;--i)
        HeapAdjust(i,n,mov,cmp);
}

void Sort::HeapAdjust(int s,int m,int &mov,int &cmp){//将r[s...m]调整为以r[s]为根的大根堆 
    int rc=r[s];
    for(int j=2*s;j<=m;j*=2){
        if(j<m&&r[j]<r[j+1])
            ++j;
        if(rc>=r[j]) break;
        r[s]=r[j];
        s=j;
        mov+=1;
        cmp+=3;
    }
    r[s]=rc;
    mov+=2;
}

void Sort::HeapSort(){
    memcpy(r,a, (n+1)*sizeof(int));
    MoveNum=0; CompNum=0;
    clock_t p1=clock();
    CreateHeap(MoveNum,CompNum);
    for(int i=n;i>1;--i){
        r[1]^=r[i]^=r[1]^=r[i];//位运算， 交换 r[1]与r[i]的值。 
        HeapAdjust(1,i-1,MoveNum,CompNum);
        MoveNum+=3; 
    }
    clock_t p2=clock();
    cout<<"堆排序:   "<<MoveNum<<"  "<<CompNum<<endl;
    S[5].cmp+=CompNum;
    S[5].mov+=MoveNum;
    S[5].time+=(p2-p1);
}
// 定义qsort的比较函数，对结构体以某个关键字进行排序。
int Comp(const void *p1,const void *p2){
    return(*(struct node*)p2).cmp>(*(struct node *)p1).cmp?-1:1;
}
int Comp1(const void *p1,const void *p2){
    return(*(struct node*)p2).mov>(*(struct node *)p1).mov?-1:1;
}
int Comp2(const void *p1,const void *p2){
    return(*(struct node*)p2).time>(*(struct node *)p1).time?-1:1;
}

int main()
{
    memset(S,0,sizeof(S));//memset函数用于内存初始化
    S[0].name="插入排序"; S[1].name="冒泡排序"; S[2].name="快速排序"; S[3].name="选择排序"; S[4].name="希尔排序"; S[5].name="堆排序"; 
    srand((unsigned)time(NULL)); //srand函数是随机数发生器的初始化函数。srand和rand()配合使用产生伪随机数序列。
    Sort sort;
    cout<<"   \t"<<"移动次数  "<<"比较次数 "<<endl; 
    for(int i=0;i<5;i++){
        cout<<"第"<<i+1<<"组："<<endl;
        sort.ini();
        sort.insert();
        sort.bubble();
        sort.Qsort(1,sort.n);
        sort.select();
        sort.shell();
        sort.HeapSort();
//        for(int h=1;h<=100;h++)
//            printf("%d ",sort.r[h]);
    }
    cout<<endl<<"总计\t"<<S[0].name<<"\t"<<S[1].name<<"\t"<<S[2].name<<"\t"<<S[3].name<<"\t"<<S[4].name<<"\t"<<S[5].name<<endl;
    cout<<"移动\t"<<S[0].mov<<"\t\t"<<S[1].mov<<"\t\t"<<S[2].mov<<"\t\t"<<S[3].mov<<"\t\t"<<S[4].mov<<"\t\t"<<S[5].mov<<endl;
    cout<<"比较\t"<<S[0].cmp<<"\t\t"<<S[1].cmp<<"\t\t"<<S[2].cmp<<"\t\t"<<S[3].cmp<<"\t\t"<<S[4].cmp<<"\t\t"<<S[5].cmp<<endl;
    cout<<"用时\t"<<S[0].time<<"\t\t"<<S[1].time<<"\t\t"<<S[2].time<<"\t\t"<<S[3].time<<"\t\t"<<S[4].time<<"\t\t"<<S[5].time<<endl<<endl;
    qsort(S,6,sizeof(struct node),Comp);
    cout<<"比较次数从少到多依次为： "<<S[0].name<<" "<< S[1].name<<" "<< S[2].name<<" "<< S[3].name<<" "<< S[4].name<<" "<< S[5].name<<endl; 
    qsort(S,6,sizeof(struct node),Comp1);
    cout<<"移动次数从少到多依次为： "<<S[0].name<<" "<< S[1].name<<" "<< S[2].name<<" "<< S[3].name<<" "<< S[4].name<<" "<< S[5].name<<endl;
    qsort(S,6,sizeof(struct node),Comp2);
    cout<<"用时从少到多依次为：     "<<S[0].name<<" "<< S[1].name<<" "<< S[2].name<<" "<< S[3].name<<" "<< S[4].name<<" "<< S[5].name<<endl; 

    return 0;
}

