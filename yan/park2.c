#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <conio.h>
#define STACKSIZE 5
int OVERFLOW=0;
/*-----------车辆数据结构定义-------------*/
typedef struct{
   int BNo;             //车辆编号
   int type;            //车辆类型
   int arrivetime;      //到达车场时间
   int pushtime;        //进入停车场时间
   int departuretime;   //离开车场时间
   }BUSINF;
 
/*------------顺序栈结构定义----------------*/
struct SqStack{
  BUSINF elm[STACKSIZE];
  int  top;
  }stack;
/*------------链队列结点结构定义-----------*/
typedef struct QNODE{
   BUSINF elm;
   struct QNODE *next;
   }QNODE;
/*-------------链队列结构定义---------------*/
struct LinkQueue{
   QNODE *front;
   QNODE *rear;
   }Queue;
/*-----------车辆收费标准定义----------------*/
int pay[]={0,2,3,5};
/*-------------------------------------------*/
/*             判栈空函数                    */
/*  参  数：struct SqStack stack--指定栈     */
/*  返回值：0--栈不空； 1--栈空              */
/*-------------------------------------------*/
int StackEmpty(struct SqStack stack)
{
  if(stack.top==0) return 1;
	else return 0;
   //（学生完成）
}
/*-------------------------------------------*/
/*             判栈满函数                    */
/*  参  数：struct SqStack stack--指定栈     */
/*  返回值：0--栈不满； 1--栈满              */
/*-------------------------------------------*/
int StackFull()
{
   if(stack.top==STACKSIZE) return 1;
	else return 0;
    //（学生完成）
}
/*-------------------------------------------*/
/*             顺序栈入栈函数                */
/*  参  数：struct SqStack *stack--栈指针    */
/*          BUSINF Bus--入栈车辆数据         */
/*  返回值：无                               */
/*-------------------------------------------*/
void push(struct SqStack *stack,BUSINF Bus)
{
    stack->elm[stack->top++]=Bus;
   //（学生完成）
}
/*-------------------------------------------*/
/*             顺序栈出栈函数                */
/*  参  数：struct SqStack *stack--栈指针    */
/*          BUSINF *Bus--返回车辆数据指针    */
/*  返回值：无                               */
/*-------------------------------------------*/
void pop(struct SqStack *stack,BUSINF *Bus)
{   
    if(StackEmpty(*stack))
      return;
    else
    {   
        *Bus=stack->elm[--stack->top];
        
    }
 
    //（学生完成）
}
/*-------------------------------------------*/
/*             链栈入栈函数                  */
/*  参  数：QNODE *stack--栈指针             */
/*          QNODE *p--入栈结点指针           */
/*  返回值：无                               */
/*-------------------------------------------*/
void LPush(QNODE *stack,QNODE *p)
{   p->next=stack->next;
    stack->next=p;
}
/*-------------------------------------------*/
/*             链栈出栈函数                  */
/*  参  数：QNODE *stack--栈指针             */
/*          QNODE **p--返回结点指针          */
/*  返回值：无                               */
/*-------------------------------------------*/
void LPop(QNODE *stack,QNODE **p)
{  (*p)=stack->next;
    stack->next=(*p)->next;
}
/*-------------------------------------------*/
/*             链队列初始化函数              */
/*  参数：无                                 */
/*  返回值：无                               */
/*-------------------------------------------*/
void InitQueue(void)
{
 	Queue.front=Queue.rear=(QNODE *)malloc(sizeof(QNODE));
	if(!Queue.front) exit(OVERFLOW);
	Queue.front->next=NULL;
   //（学生完成）
}
/*-------------------------------------------*/
/*             判队列空函数                  */
/*  参  数：无                               */
/*  返回值：0--队列不空； 1--队列空          */
/*-------------------------------------------*/
int QueueEmpty(void)
{
    if(Queue.front==Queue.rear) return 1;
	 else return 0;
  //（学生完成）
}
/*-------------------------------------------*/
/*             入队操作函数                  */
/*  参  数：BUSINF Businf--入队车辆数据      */
/*  返回值：无                               */
/*-------------------------------------------*/
void EnQueue(BUSINF Businf)
 { QNODE *p;
   p=(QNODE *)malloc(sizeof(QNODE));
      if(!p) exit(OVERFLOW);
	  p->elm=Businf;
	  p->next=NULL;
	  Queue.rear->next=p;
	  Queue.rear=p;
    //  （学生完成）
   }
/*-------------------------------------------*/
/*             出队操作函数                  */
/*  参  数：BUSINF *Businf--返回车辆数据指针 */
/*  返回值：无                               */
/*-------------------------------------------*/
void DeQueue(BUSINF *BusInf)
{  QNODE *p;
  if(QueueEmpty()) return;
  p=Queue.front->next;
  *BusInf=p->elm;
  Queue.front->next=p->next;
  if(Queue.rear==p) Queue.rear=Queue.front;
  free(p);
  //（学生完成）
  }
/*-------------------------------------------*/
/*             栈数据查找函数                */
/*  参  数：int BusNo--待查找的车辆编号      */
/*  返回值：int:>=0--数据在栈中的位置        */
/*              -1--查找失败                 */
/*-------------------------------------------*/
int SearchStack(int BusNo)
{ int k;
  k=stack.top-1;
  while(k>=0&&BusNo!=stack.elm[k].BNo) k--;
  return(k);
  }
/*-------------------------------------------*/
/*             队列数据查找函数              */
/*  参  数：int BusNo--待查找的车辆编号      */
/*  返回值：队列结点指针:NULL--查找失败      */
/*              非空--查找成功，数据结点指针 */
/*-------------------------------------------*/
QNODE *SearchQueue(int BusNo)
{ QNODE *p;
  p=Queue.front->next;
  while(p!=NULL&&p->elm.BNo!=BusNo) p=p->next;
  return(p);
  }
/*-------------------------------------------*/
/*             收费计算与显示函数            */
/*  参  数：BUSINF BusInf--离开车辆的数据    */
/*  返回值：无                               */
/*-------------------------------------------*/
void CalcultPay(BUSINF BusInf)
{ int payment;
  if(BusInf.arrivetime!=0&&BusInf.pushtime==0)
   payment=(BusInf.departuretime-BusInf.arrivetime)*pay[BusInf.type]/3.0;
  else if(BusInf.arrivetime!=0&&BusInf.pushtime!=0)
     payment=(BusInf.pushtime-BusInf.arrivetime)*pay[BusInf.type]/3.0+
      (BusInf.departuretime-BusInf.pushtime)*pay[BusInf.type];
  else payment=(BusInf.departuretime-BusInf.pushtime)*pay[BusInf.type];
  printf(" \n    ************************\n");
  printf("    *      payment=%4d    *\n",payment);
  printf("    ************************\n");
  getch();
  }
/*-------------------------------------------*/
/*        进场车辆数据录入与管理函数         */
/*  参  数：无                               */
/*  返回值：无                               */
/*-------------------------------------------*/
void InputArrialData()
{ int BusNo,arrivetime,BusType;
  BUSINF arrive;
  int i=0;
 do
  {
     do
     {
         printf("Input BusNo:");
         scanf("%d",&BusNo);
         if((SearchStack(BusNo)!=-1)||(SearchQueue(BusNo)!=NULL))
         {
			 printf("The Bus is in BusData:\n");
                  }
		 else i=1;
              }while(!i);
	 arrive.BNo=BusNo;
     printf("Input arrivetime:");
     scanf("%d",&arrivetime);
     arrive.arrivetime=arrivetime;
     printf("1.Car  2.Bus  3.Truck  ");
     printf("\nInput Type:");
     scanf("%d",&BusType);
     arrive.type=BusType;
  }while(!(BusNo>0&&arrivetime>0&&0<BusType<=3));
 
  if(StackFull())
  {
      arrive.pushtime=-1;
	  EnQueue(arrive);
 
  }
  else
  {
       arrive.pushtime=arrive.arrivetime;
       push(&stack,arrive);
  }
  
   }//（学生完成）
/*-------------------------------------------*/
/*        离场车辆数据录入与管理函数         */
/*  参  数：无                               */
/*  返回值：无                               */
/*-------------------------------------------*/
void InputDepartData()
{ int BusNo,departtime;
  int f=0,bn;
  BUSINF depart,temp;
  QNODE *p,*pri,*q;
  QNODE *LStack;
  struct SqStack TempStack;
  if(StackEmpty(stack)&&QueueEmpty())
  {
	  printf("Iput error!");
	  getch();
      return;
  }
   printf("Input the BusNo:");
  do
  {
    scanf("%d",&BusNo);
  }while(BusNo<0);
  if(SearchStack(BusNo)==-1&&SearchQueue(BusNo)==NULL)
	  printf("\nThe BusNo is not in Data!");
  else
  {
	 if(SearchStack(BusNo)!=-1)    //说明在停车场上
	 {
	     f=1;
	     bn=SearchStack(BusNo);
         printf("Input deparetime:");
	     do
		 {
	       scanf("%d",&stack.elm[bn].departuretime);
		 }while(stack.elm[bn].departuretime<stack.elm[bn].pushtime);
		 if(QueueEmpty())    //说明链队列为空
		 {
            if(stack.top==bn+1)    //在栈顶
			{
	          pop(&stack,&depart);
            }
	        else                    //不在栈顶
			{
                   int flg=0;
	               while(stack.top>bn+1)
				    {
 
					  pop(&stack,&depart);
			          TempStack.elm[flg++]=depart;
				    }
                      pop(&stack,&depart);
					do
					{
					  push(&stack,TempStack.elm[flg-1]);
					  flg--;
					}while(flg);
			}
		}
		else       //说明链队列不为空
		{
		   if(stack.top==bn+1)    //在栈顶
			{
	          pop(&stack,&depart);
			  DeQueue(&temp);
			  temp.pushtime=depart.departuretime;
              push(&stack,temp);
 
            }
	        else                    //不在栈顶
			{
				   int flg=0;
	                while(stack.top>bn+1)
				   {
 
					 pop(&stack,&depart);
			         TempStack.elm[flg++]=depart;
				   }
                    pop(&stack,&depart);
					do
					{
					 push(&stack,TempStack.elm[flg-1]);
					 flg--;
					}while(flg);
                     DeQueue(&temp);
					 temp.pushtime=depart.departuretime;
                     push(&stack,temp);
 
			}
		}
	 }
	else              //说明在暂停车道上
	 {
	  p=SearchQueue(BusNo);
	  printf("Input departuretime:");
	  do
	  {
	   scanf("%d",&p->elm.departuretime);
	  }while(p->elm.departuretime<p->elm.arrivetime);
	    if(p==Queue.front->next)       //在队列头部
	      DeQueue(&depart);
		else                           //不在队列头部
		{
		    while(p!=Queue.front->next)
			{
		     DeQueue(&depart);
			 q=(QNODE *)malloc(sizeof(QNODE));
			 q->elm=depart;
             LPush(LStack,q);
			 }
             DeQueue(&depart);
			 while(LStack->next)
			 {
			    LPop(LStack,&pri);
			    if(QueueEmpty())
			    {
				   pri->next=Queue.front->next;
				   Queue.front->next=pri;
				   Queue.rear=Queue.front;
                 }
                 else
                 {
			       pri->next=Queue.front->next;
				   Queue.front->next=pri;
			     }
			 }
		}
	}
 	       printf("\nThe car:\n");
	       if(f)
	       {
             printf(" CarNo        Arrivetime        Pushtime        departuretime\n");
			 printf(" %-13d%-18d%-16d%-d",depart.BNo,depart.arrivetime,depart.pushtime,depart.departuretime);
 
	       }
		   else
		   {
		     printf(" CarNo        Arrivetime        departuretime\n");
			 printf(" %-13d%-18d%-d",depart.BNo,depart.arrivetime,depart.departuretime);
 
		   }
		    CalcultPay(depart);
  }
  }//(学生完成)
/*-------------------------------------------*/
/*        列表显示车场车辆数据函数           */
/*  参  数：无                               */
/*  返回值：无                               */
/*-------------------------------------------*/
void OutputBusData(void)
{ int i;
  QNODE *p;
  printf("\n    stop:\n");
  printf("     CarNo   Arrivetime    Pushtime\n");
  getch();
  for(i=0;i<stack.top;i++)
    printf("%8d%8d%10d\n",stack.elm[i].BNo,stack.elm[i].arrivetime,
       stack.elm[i].pushtime);
  if(Queue.front->next)
   { printf("\n    path:\n");
     p=Queue.front->next;
     while(p)
       { printf("    %d     %d\n",p->elm.BNo,p->elm.arrivetime);
	 p=p->next;
	 }
     }
  }
/*-------------------------------------------*/
/*               撤销队列函数                */
/*  参  数：无                               */
/*  返回值：无                               */
/*-------------------------------------------*/
void DestroyQue()
  { QNODE *p,*q;
    p=Queue.front;
    while(p)
     { q=p;
       p=p->next;
       free(q);
       }
    }
/*-------------------------------------------*/
/*               菜单选择函数                */
/*  参  数：无                               */
/*  返回值：int:取值1--3                     */
/*-------------------------------------------*/
int nemu()
{
    char m;
    printf("\n    ************* BUS Manage **************\n");
    printf("    *%15c1---Arrival%12c\n",' ','*');
    printf("    *%15c2---Departure%10c\n",' ','*');
    printf("    *%15c3---End%16c\n",' ','*');
    printf("    ***************************************\n");
    printf("%15cSelcet 1,2,3: ",' ');
    do{
	     m=getch();
	     }while(m<'1' || m>'3');
     printf("\n");
     return(m-48);
}
void main()
{ stack.top=0;
  InitQueue();
  while(1)
    {
	switch(nemu())
	    {
	     case 1:
		    InputArrialData();
		    OutputBusData();
		    break;
	     case 2:
		    InputDepartData();
		    OutputBusData();
		    break;
	     case 3:
		    OutputBusData();
		    DestroyQue();
		    return;
	     }
    }
}
