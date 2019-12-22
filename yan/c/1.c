
#include <stdio.h>
#include <stdlib.h>//包含背景颜色和清空
void a();//购买
void b();//显示库存
void c();//设备维护
int z=1;//状态，z=1时设备没有维修。z=0时，设备维修中
struct huowu//定义货物信息
{
float jiage;//价格
int kucun;//库存
}yp[4]={1,10,2.5,10,3.5,10,5,10};//s水kl可乐nc奶茶cj橙汁
 
int main()
{	char sr;//定义电脑接受的字符
//	system("color 2E");//背景颜色为绿色，库函数是stdlib
//	printf("QQ:1179307527莫言制作\n");//声明作者信息

start://起始位置
printf("				自动售货机\n\n   ");
printf("				a-----  购买   \n");
printf("				b-----显示库存 \n  ");
printf("				c-----设备维护 \n  " );
printf("				d-----退出系统 \n  " );
scanf("%c",&sr);
switch(sr)
 {
 case 'a' : a();break;
 case 'b' : b();break;
 case 'c': c();break;
 case 'd': exit(0);break;
}
goto start;//回到起始位置
}//main括号
 
 
 
void a()//购买
{
	float j;
	int i;
	system("cls");//清空，库函数是stdlib
 
printf("					饮品\n    ");
printf("					1-----矿泉水\n ");
printf("					2-----可乐 \n   ");
printf("					3-----橙汁 \n   ");
printf("					4-----橙汁 \n   ");
printf("					你买啥？  \n     ");
if(z==0) {printf("\n\n\n					正处于维修状态\n\n\n"); 
		  printf("\n\n\n					暂时无法购买\n\n\n");	
		  main();
			};
scanf("%d",&i);
switch(i)
{
case 1:{
		if(yp[0].kucun !=0) //判断库存是否为0
		  {
			printf("矿泉水1元，请付费\n");
			while(1)//循环，保证j<1时的循环
			{
				scanf("%f",&j);
				if(j>1) {printf("付款成功，找零钱%.1f元，请收好\n",j-1);yp[0].kucun=yp[0].kucun-1;break;}//你给的钱>=1,则购买成功且相应库存-1
				if(j==1) {printf("付款成功\n");yp[0].kucun=yp[0].kucun-1;break;}//你给的钱>=1,则购买成功且相应库存-1
				if(j<1) printf("金额不足，请重新付款\n");
			};
		  }
		else printf("				库存为0\n			请购买其他饮品");
		break;
	   }
case 2:{if(yp[1].kucun !=0) //判断库存是否为0
	   {
		printf("可乐2.5元，请付费\n");
		while(1)//循环，保证j<2.55时的循环
		{
		scanf("%f",&j);
		if(j>2.5) {printf("付款成功，找零钱%.1f元，请收好\n",j-2.5);yp[1].kucun=yp[1].kucun-1;break;}//你给的钱>=2.5,则购买成功且相应库存-1
		if(j==2.5) {printf("付款成功\n");yp[1].kucun=yp[1].kucun-1;break;}//你给的钱>=2.5,则购买成功且相应库存-1
        if(j<2.5) printf("金额不足，请重新付款\n");
	   };
	   }
	 	else printf("				库存为0\n			请购买其他饮品");
		break;
	   }
case 3:{if(yp[2].kucun !=0)//判断库存是否为0
	   {
		   printf("橙汁3.5元，请付费\n");
			while(1)//循环，保证j<3.5时的循环
			{
			scanf("%f",&j);
			if(j>3.5) {printf("付款成功，找零钱%.1f元，请收好\n",j-3.5);yp[2].kucun=yp[2].kucun-1;break;}//你给的钱>=3.5,则购买成功且相应库存-1
			if(j==3.5) {printf("付款成功\n");yp[2].kucun=yp[2].kucun-1;break;}//你给的钱>=3.5,则购买成功且相应库存-1
		    if(j<3.5) printf("金额不足，请重新付款\n");
			};
	   }
		else printf("				库存为0\n			请购买其他饮品");
		break;
	   }
case 4:{
			if(yp[3].kucun !=0)//判断库存是否为0
	   {
	printf("奶茶5元，请付费\n");
		while(1)//循环，保证j<5时的循环
		{
		scanf("%f",&j);
		if(j>5) {printf("付款成功，找零钱%.1f元，请收好\n",j-5);yp[3].kucun=yp[3].kucun-1;break;}//你给的钱>=5,则购买成功且相应库存-1
		if(j==5) {printf("付款成功\n");yp[3].kucun=yp[3].kucun-1;break;}//你给的钱>=5,则购买成功且相应库存-1
        if(j<5) printf("金额不足，请重新付款\n");
		};
	   }
	else printf("				库存为0\n			请购买其他饮品");
	break;
} //case4大括号
}//switch大括号
}//a()大括号
 
 
void b()
{
system("cls"); //清空屏幕
printf("				矿泉水库存：%d\n",yp[0].kucun);
printf("				可乐库存：%d\n",yp[1].kucun );
printf("				橙汁库存：%d\n",yp[2].kucun);
printf("				奶茶库存：%d\n", yp[3].kucun);
}
 
 
void c()
{
		int q;//临时弄得变量
        system("cls"); //清空屏幕
        printf("						进入系统维修状态\n\n\n");
		z=0;//系统维修状态
		printf("						你可以添加库存\n");
		printf("				是否添加库存，是则按1，否则按其他键返回\n");
		scanf("%d",&q);
		if(q==1)
		{
				yp[0].kucun=10;//添加库存，即库存都为10
				yp[1].kucun=10;//添加库存，即库存都为10
				yp[1].kucun=10;//添加库存，即库存都为10
				yp[2].kucun=10;//添加库存，即库存都为10
				system("cls");//清空屏幕
				printf("				库存已添加满\n\n\n");
				z=1;//库存添加完毕，进入正常售货状态
		}
		main();//回到主函数
}
