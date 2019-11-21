#include<stdio.h>
#include<stdlib.h>
/******************************宏定义**************************************/
#define LEN sizeof(struct Queue)
#define LENS sizeof(struct SqQueue)
#define LEN1 sizeof(struct Stack)
#define LEN1S sizeof(struct SqStack)
#define INISIZE 3
/******************************结构体定义*********************************/
struct Queue{                        /*定义队列*/
         int status;                     /*状态*/
         int ord;                          /*编号*/
         int time;                        /*时间*/
         struct Queue *next;      /*下一个节点的地址*/
};
struct SqQueue{           /*定义指向队列的指针*/
         struct Queue *head;     /*队头指针*/
         struct Queue *end;       /*队尾指针*/
};
struct Stack{                          /*定义栈*/
         int status;                     /*状态*/
         int ord;                          /*编号*/
         int time;                        /*时间*/
};
struct SqStack{            /*定义指向栈的指针*/
         struct Stack *head;       /*栈头指针*/
         struct Stack *end;         /*栈尾指针*/
         int stacksize;                /*栈的大小*/
};
/*****************************队列函数声明********************************/
int InitQueue(struct SqQueue *sq);                                     /*初始化队列，即构造头指针*/
struct Queue InputQueue();                                                 /*输入临时变量*/
int EnQueue(struct SqQueue *sq,struct Queue e);              /*入队操作*/
void PrintQueue(struct SqQueue *h);                                  /*打印队列*/
int QueueEmpty(struct SqQueue *p);                                 /*判断队列是否为空*/
int GetQueueTop(struct SqQueue *p,struct Queue *q);     /*取得队头元素*/
int QueueLocation(struct SqQueue *p);                              /*取得队列中的位置*/
/******************************栈函数声明*********************************/
int InitStack(struct SqStack *sq);                                        /*初始化栈，即构造头指针*/
struct Stack InputStack();                                                             /*输入临时变量*/
int EnStack(struct SqStack *sq,struct Stack e);                            /*入栈操作*/
void PrintStack(struct SqStack *h);                                              /*打印栈*/
int StackEmpty(struct SqStack *p);                                             /*判断栈是否为空*/
int StackFull(struct SqStack *p);                                                  /*判断栈是否满*/
int GetStackTop(struct SqStack *p,struct Stack *q);                   /*取得栈头元素*/
int StackLocation(struct SqStack *p);                                           /*取得栈中的位置*/
/******************************其他函数声明*******************************/
void Exec(struct SqQueue *sq,struct SqStack *st,struct SqStack *st1,struct Queue temp);                                                                                                   /*操作*/
void Operator1(struct SqQueue *sq,struct SqStack *st,struct Queue temp);
void Operator2(struct SqQueue *sq,struct SqStack *st,struct SqStack *st1,struct Queue temp);
/*********************************main()***********************************/
void main()
{
         struct Queue temp;                         /*定义临时变量*/
         struct SqQueue *squeue;                /*定义队列*/
         struct SqStack *sStack;                   /*定义栈一*/
         struct SqStack *sStack1;                /*定义栈二*/
         squeue=(struct SqQueue *)malloc(LENS);
         sStack=(struct SqStack *)malloc(LENS);
         sStack1=(struct SqStack *)malloc(LENS);
         system("cls");
         InitQueue(squeue);                                   /*初始化队列*/
         InitStack(sStack);                                     /*初始化栈一*/
         InitStack(sStack1);                                   /*初始化栈栈二*/
         temp=InputQueue();                      /*输入*/
         while(temp.status!=69)
         {
                   Exec(squeue,sStack,sStack1,temp);/*操作*/
                   temp=InputQueue();                      /*输入*/
         }
}
/**********************************InitQueue*******************************/
int InitQueue(struct SqQueue *sq)          /*初始化队列，,即构造头指针*/
{
         sq->head=sq->end=(struct Queue *)malloc(LEN);             /*申请空间*/
         if(!sq->head)
                   return 0;
         sq->head->next= NULL;                                                               /*将指针置空*/
         return 1;
}
/*********************************InputQueue******************************/
struct Queue InputQueue()                                                                    /*输入临时变量*/
{
         struct Queue temp;
         printf("please input status order and time end of /'E/':");
         scanf("%d%d%d",&(temp.status),&(temp.ord),&(temp.time));
         return temp;
}
/*********************************EnQueue******************************/
int EnQueue(struct SqQueue *sq,struct Queue e)                                 /*入队操作*/
{
         struct Queue *s,*p;
         p=(struct Queue *)malloc(LEN);
         *p=e;
         if(QueueEmpty(sq))                                                                      /*是否为空队*/
         {
                   sq->head->next=p;
                   p->next=NULL;
                   sq->end=p;
                   return 1;
         }
         else
         {
                   for(s=sq->head;s->next!=NULL;s=s->next);
                   s->next=p;
                   p->next = NULL;
                   sq->end=p;
                   return 1;
         }
}
/********************************PrintQueue*******************************/
void PrintQueue(struct SqQueue *h)       /*打印队列，程序编写时作为测试*/
{
         struct Queue *p;
         p=h->head;
         p=p->next;
         do
         {
                   printf("%c %d %d/n",p->status,p->ord,p->time);
                   p=p->next;
         }while(p!=NULL);
}
/**********************************QueueEmpty****************************/
int QueueEmpty(struct SqQueue *p)               /*判断队列是否为空*/
{
         if(p->head->next==NULL)
                   return 1;
         else
                   return 0;
}
/*********************************GetQueueTop*****************************/
int GetQueueTop(struct SqQueue *p,struct Queue *q)                        /*取得队头元素*/
{
         struct Queue *tem;
         tem=p->head;
         if(p->head->next!=NULL)
         {
                   tem=tem->next;
                   *q=*tem;
                   p->head->next=p->head->next->next;
                   free(tem);
                   return 1;
         }
         else
                   return 0;
}
/**********************取得入队元素队列中的位置***************************/
int QueueLocation(struct SqQueue *p)
{
         int i=0;
         struct Queue *q;
         q=p->head;
         while(q->next!=NULL)
         {
                   q=q->next;
                   i++;
         }
         return i;
}
/**********************************InitStack********************************/
int InitStack(struct SqStack *sq)             /*初始化栈，,即构造头指针*/
{
         sq->head=(struct Stack *)malloc(INISIZE*LEN1);            /*申请空间*/
         if(!sq->head)
                   return 0;
         sq->end=sq->head;
         sq->stacksize=INISIZE;
         return 1;
}
/*********************************InputStack******************************/
struct Stack InputStack()                                                                        /*输入临时变量，测试之用*/
{
         struct Stack temp;
         printf("please input status order and time end of /'E/':");
         scanf("%d%d%d",&(temp.status),&(temp.ord),&(temp.time));
         return temp;
}
/*********************************EnStack*******************************/
int EnStack(struct SqStack *sq,struct Stack e)                    /*入栈操作*/
{
         if(StackFull(sq)) return 0;
         else
                   *(sq->head)++=e;
         return 1;
}
/********************************PrintStack******************************/
void PrintStack(struct SqStack *h)                                                /*打印栈，测试之用*/
{
         struct SqStack *p;
         int i=0;
         p=h;
         (p->head)--;
         do
         {
                   printf("%c %d %d/n",p->head->status,p->head->ord,p->head->time);
                   (p->head)--;
                   i++;
         }while(i<2);
}
/**********************************StackEmpty*****************************/
int StackEmpty(struct SqStack *p)                  /*判断栈是否为空*/
{
         if((p->head-p->end)==0)
                   return 1;
         else
                   return 0;
}
/*********************************StackFull******************************/
int StackFull(struct SqStack *p)              /*判断栈是否满*/
{
         return ((p->head-p->end>=INISIZE)?1:0);
}
/*********************************GetStackTop*****************************/
int GetStackTop(struct SqStack *p,struct Stack *q)                    /*取得栈头元素*/
{
         if(StackEmpty(p))
                   return 0;
         (p->head)--;
         *q=*(p->head);
         return 1;
}
/*********************************StackLocation****************************/
int StackLocation(struct SqStack *p)
{
         return (p->head-p->end);
}
/**********************************Exec***********************************/
void Exec(struct SqQueue *sq,struct SqStack *st,struct SqStack *st1,struct Queue temp)                                                               /*执行*/
{
         switch(temp.status)
         {
                   case 65:Operator1(sq,st,temp);break;
                   case 68:Operator2(sq,st,st1,temp);break;
         }
}
/*********************************Operator1******************************/
void Operator1(struct SqQueue *sq,struct SqStack *st,struct Queue temp)
{
         struct Stack t;
         if(QueueEmpty(sq))                       /*判断是否队列为空*/
         {
                   if(StackFull(st))                     /*判断是否栈满*/
                   {
                            EnQueue(sq,temp);                         /*入队*/
                            printf("在Queue中的位置是：%d/n",QueueLocation(sq));
                            /*PrintQueueOrd();      /*打印输出队列中的编号*/
                   }
                   else
                   {
                            t.ord=temp.ord;
                            t.status=temp.status;
                            t.time=temp.time;
                            EnStack(st,t);      /*??*/
                            printf("元素Stack中的位置是：%d/n",StackLocation(st));
                            /*PrintStackOrd();        /*打印输出栈中编号*/
                   }
         }
         else
         {
                   EnQueue(sq,temp);                                                                                                   /*入队*/
                   printf("在Queue中的位置是：%d/n",QueueLocation(sq));               /*打印输出队列编号*/
         }
}
/*********************************Operator2*****************************/
void Operator2(struct SqQueue *sq,struct SqStack *st,struct SqStack *st1,struct Queue temp)
{
         struct Stack *q;
         struct Queue *p;
         q=(struct Stack *)malloc(LEN1);
         p=(struct Queue *)malloc(LEN);
         GetStackTop(st,q);
         while(q->ord!=temp.ord)               /*取出栈顶元素与临时变量中的车牌号比较*/
         {
                   if(StackEmpty(st))
                            break;
                   EnStack(st1,*q);                    /*将出栈元素入栈二*/
                   GetStackTop(st,q);                         /*栈一栈顶元素出栈*/
         }
         if(!(StackEmpty(st)))
         {
                   GetStackTop(st,q);                         /*取得满足条件的元素让其出栈*/
                   printf("车辆%d停留时间是%d,费用是 %d./n",q->ord,temp.time-q->time,(temp.time-q->time)*5);
         }
         while(!(StackEmpty(st1)))             /*将栈二元素全部入栈一*/
         {
                   GetStackTop(st1,q);              /*出栈二入栈一*/
                   EnStack(st,*q);
         }
         if(!(QueueEmpty(sq)))                            /*判断队列是否为空*/
         {
                   GetQueueTop(sq,p);             /*取得队头元素*/
                   q->ord=p->ord;
                   q->status=p->status;
                   q->time=p->time;
                   EnStack(st,*q);                      /*入栈一*/
         }
}
