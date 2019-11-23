# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>
//# include <conio.h>
# include <string.h>
 
# define MAX_STOP 5
# define MAX_PAVE 100
 
typedef struct 
{
	char plate[10];				//汽车牌照号码，定义为一个字符指针类型
}CAR;
 
typedef struct 
{
	CAR STOP[MAX_STOP];			//各汽车信息的存储空间
	int top;					//用来指示栈顶位置的静态指针
}STOPING;
 
typedef struct 
{
	int count;					//用来指示队中的数据个数
	CAR PAVE[MAX_PAVE];			//各汽车信息的存储空间
	int front,rear;				//用来指示队头和队尾位置的静态指针
}PAVEMENT;
 
typedef struct 
{
	CAR HELP[MAX_STOP];		//各汽车信息的存储空间
	int top;					//用来指示栈顶位置的静态指针
}BUFFER;
 
STOPING S;						
PAVEMENT P;
BUFFER B;
char C[10];
 
void stop_to_pave()					//车停入便道
{
	if(P.count > 0 && P.front == P.rear)		//队满判断
		printf("便道已满,请下次再来;\n");
	else	
	{
		strcpy(P.PAVE[P.rear].plate,C);	
		P.rear = (P.rear + 1) % MAX_PAVE;		//队尾指示器加1
		P.count ++;								//计数器加1
		printf("牌照为%s的汽车停入便道上的%d位置;\n",C,P.rear);
	}
}
 
void car_come()						//车停入停车位
{
	printf("请输入即将停车的车牌号: ");		//输入车牌号
	scanf("%s",&C);
	if(S.top >= MAX_STOP)			//如果停车位已满，停入便道
		stop_to_pave();				//停车位 -> 便道 函数
	else							//否则车停入停车位
	{
		strcpy(S.STOP[S.top].plate,C);			//将车牌号登记
		S.top ++;								//停车位栈顶指针加1
		printf("牌照为%s的汽车停入停车位的%d车位;\n",C,S.top);
	}
	return ;
}
 
void stop_to_buff()
{
	while(S.top > 0)		//停车位栈压入临时栈，为需要出栈的车辆让道
	{
		S.top--;
		if(strcmp(S.STOP[S.top].plate,C) == 0)
			break;
		strcpy(B.HELP[B.top].plate,S.STOP[S.top].plate);
		B.top++;
		printf("牌照为%s的汽车暂时退出停车位;\n",S.STOP[S.top].plate);
	}
	if(S.top <= 0)					//如果停车位中的车都让了道，说明停车位中无车辆需要出行
		printf("停车位上无此车消息.\n");
	else							//否则则输出车辆号
		printf("牌照为%s的汽车从停车场开走;\n",S.STOP[S.top].plate);
	while(B.top > 0)				//将辅助栈中的车辆信息压入停车位栈
	{
		B.top --;
		strcpy(S.STOP[S.top].plate,B.HELP[B.top].plate);
		S.top ++;
		printf("牌照为%s的汽车停回停车位%d车位;\n",B.HELP[B.top].plate,S.top);		
	}
	while(S.top < MAX_STOP)			//从便道中 -> 停车位
	{
		if(P.count == 0)			//判断队列是否为空
			break;
		else						//不为空，将便道中优先级高的车辆停入停车位
		{
			strcpy(S.STOP[S.top].plate,P.PAVE[P.front].plate);
			S.top++;
			printf("牌照为%s的汽车从便道进入停车位的%d车位;\n",P.PAVE[P.front].plate,S.top);
			P.front = (P.front+1) % MAX_PAVE;
			P.count --;
		}
	}
}
 
void car_leave()
{
	printf("请输入即将离开的车牌号: ");
	scanf("%s",&C);
	if(S.top <= 0)					//判断停车位是否有车辆信息
		printf("车位已空,无车辆信息!\n");
	else
		stop_to_buff();
}
 
void welcome()						//主界面函数
{
	printf("\n\n");
	printf("\t**欢迎使用本程序**\n");
	printf("\t本程序为停车场的模拟管理程序，有车到来时请按【C】键。\n");
	printf("\t然后根据屏幕提示进行相关操作，有车要走时请按【L】键。\n");
	printf("\t然后根据屏幕提示进行相关操作，要退出程序请按【Q】键。\n");
	printf("\t请选择你要做的操作!\n\n\n");
	return ;
}
 
int main()
{
	char x,y;
	S.top = 0 ;					//初始化“停车位栈”
	B.top = 0;					//初始化“辅助栈”
	P.rear = 0;					//初始化“便道队列
	P.count = 0;
	P.front = 0;
	while(1)					//界面操作
	{
		system("cls");
		welcome();
		x = getch();
		if(x == 'C' || x == 'c') car_come();
		if(x == 'L' || x == 'l') car_leave();
		if(x == 'Q' || x == 'q') break;
		printf("按【Enter】键继续程序的运行。\n");	
		y = getch();
	}
	return 0;
}
