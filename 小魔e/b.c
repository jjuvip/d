#include<stdio.h>

#include<string.h>

#include<stdlib.h>

#include<windows.h>

#include"state.h"

#define change 3

int iCount;

int n;

//*****************注册*****************//

void router_registe(pAccout ahead)

{

	system("cls");

	char username[20];

	char password[13];

	char pass[13]; 

	char q;

	int i;

	FILE *fp;

	loop2:

	printf("\n\n\n\n");

	printf("\t\t\t\t账号:");

	scanf("%s",username);

		getchar();

		printf("\t\t\t\t密码:");

		i=0;

		while (1)

		{

			q = getch();

			if (q != 13)

			 {

				printf("*");

				password[i++] = q;

			}

			else {

				password[i] = '\0';

				printf("\n");

				break;

				}

			}

		printf("\t\t\t\t请确认密码：");

			i=0;

		while (1) 

		{

			q = getch();

			if (q != 13)

			 {

				printf("*");

				pass[i++] = q;

			}

			else {

				pass[i] = '\0';

				printf("\n");

				break;

				}

			}

	if(strcmp(pass,password)==0)

	{

	fp=fopen("e:\\课设\\Accout1.txt", "ab+");

    fprintf(fp," %s %s",username,password);  //把内存中的文件输入到硬盘中

	fclose(fp);

	system("cls");

	printf("\n\n\n\n注册成功\n");

	}

	else goto loop2;

}

//*****************登录*****************//

pAccout router_acc(pAccout ahead)

{

	pAccout p1,p2;

	FILE *fp;

	int m=0;

	if((fp=fopen("e:\\课设\\Accout.txt", "rw"))==NULL)

	{

		printf("读取失败!");

		return ahead;

	 }

	ahead==NULL;

	p1=(pAccout)malloc(sizeof(Accout));

	while(fscanf(fp,"%s %s",p1->name,p1->pass)==2)

	{

		//printf("%s\n",p1->name);                  //读进去了 

		m=m+1;

		if(m==1)

		{

			ahead->next=p1;

			p2=p1;

			p2->next = NULL;

		}

		else

		{

			p2->next=p1;

			p2=p1;

			p2->next=NULL;

		}

		p1=(pAccout)malloc(sizeof(Accout));

	}

	fclose(fp);

	return ahead;

}

pAccout router_acc1(pAccout ahead)

{

	pAccout p1,p2;

	FILE *fp;

	int m=0;

	if((fp=fopen("e:\\课设\\Accout1.txt", "rw"))==NULL)

	{

		printf("读取失败!");

		return ahead;

	 }

	ahead==NULL;

	p1=(pAccout)malloc(sizeof(Accout));

	while(fscanf(fp,"%s %s",p1->name,p1->pass)==2)

	{

	

	//printf("%s\n",p1->name);     //由于文件没有读入换行，读出的时候将先一个人的密码和 

	//printf("%s",p1->pass);      //后一个人的名称 

		m=m+1;

		if(m==1)

		{

			ahead->next=p1;

			p2=p1;

			p2->next = NULL;

		}

		else

		{

			p2->next=p1;

			p2=p1;

			p2->next=NULL;

		}

		p1=(pAccout)malloc(sizeof(Accout));

	}

	fclose(fp);

	return ahead;

}

void login_printf()

{

	system("cls");

	printf("\n\n\n\n");

	printf("\t\t\t★☆★☆★☆★☆★☆★☆★☆★☆\n");

	printf("\t\t\t☆                            ★\n");

	printf("\t\t\t☆         1.登录             ★\n");

	printf("\t\t\t☆         2.注册             ★\n");

	printf("\t\t\t★         0.退出             ☆\n");

 	printf("\t\t\t☆                            ★\n");

	printf("\t\t\t★☆★☆★☆★☆★☆★☆★☆★☆\n");

}

void login_printf1()

{

	system("cls");

	printf("\n\n\n\n");

	printf("\t\t\t********************************\n");

	printf("\t\t\t||                            ||\n");

	printf("\t\t\t||         1.管理员登录       ||\n");

	printf("\t\t\t||         2.用户登录         ||\n");

	printf("\t\t\t||         0.退出             ||\n");

 	printf("\t\t\t||                            ||\n");

	printf("\t\t\t********************************\n");

}

void login_acc()

 {

 	system("cls");

 	int bk;

 	int bb;

 	pAccout ahead,p1;

 	ahead=(pAccout)malloc(sizeof(Accout));

 	ahead->next=NULL;

 	while(1)

 	{

 		char a[200]; 

 		char b[200];

 		loop:

 		login_printf();

		printf("请输入:");

		scanf("%s",a);

		bk=back(a);

		switch(bk)

		{

			case 1:{

					login_printf1();

					 printf("请输入：");

					 scanf("%s",b);

					 bb=back(b);

					 switch(bb)

					 {

					 	case 1:{

					 			router_acc(ahead);

					 			ahead=login_panduan(ahead);//管理员登录 

					 			meun();

								break;

								 } 

						case 2:{

									router_acc1(ahead);

									ahead=login_panduan(ahead);//用户登陆 

									menu1();

									break;

								} 

						case 0:

							{

								print2();

								exit(0);

								break;

							}

						default:printf("输入错误！");

								Sleep(1000);

								system("cls");

									break;

					 }

					 if(bb!=0)//丢失此处则会无法跳出循环 

						 break;

					}

			case 2:{

						router_registe(ahead);

			            goto loop;

						break;

			}

			case 0:{

				//	printf("BUG！！！！\n");测试bug！！！！！ 

					print2();

					exit(0);

					break;

					}

			default:printf("输入错误！");

					Sleep(1000);

					system("cls");

					break;

		}

		if(bk!=0)

		break;

	}

}

pAccout login_panduan(pAccout ahead)

{

	char name1[20],pass1[20];

	char q;

	pAccout p1;

	int i=0,j=0;

	system("cls");

	printf("\n\n\n\n");

	loop1:

	while(1)

	{

		j++;

		p1=ahead->next;

		printf("\t\t\t\t账号:");

		scanf("%s",name1);

		getchar();

		printf("\t\t\t\t密码:");

		i=0;

		while (1) 

		{

			j++;

			q = getch();

			if (q != 13)

			 {

				printf("*");

				pass1[i++] = q;

			}

			else {

				pass1[i] = '\0';

				printf("\n");

				break;

				}

			}

			//printf("%s",pass1);密码正确（加密最初出现问题） 

		while(p1!=NULL)

		{

			if(strcmp(name1,p1->name)==0)

			{

				if(strcmp(pass1,p1->pass)==0)

				{

					printf("\n\n\t\t\t\t登录成功！");

					Sleep(2000);

					return ahead;

				 } 

				else

				{

					p1=p1->next;

				}

			}

			else

			{

				p1=p1->next;

			}

			if(p1==NULL)

			{

				printf("\n\n\n\n\t\t\t\t输入有误");

				system("cls");

				printf("\n\n\n\n\t\t\t\t请重新输入\n");	

				Sleep(2000);

				goto loop1;

				break; 

			}

		}

		if(j>=change)

		{

			system("cls");

			printf("\n\n\n\n");

			printf("\t\t\t\t***************\n");

			printf("\t\t\t\t你完蛋了!!!!!\n");

			printf("\t\t\t\t***************\n");

			Sleep(2000);

			print2();

			exit (0);

		}

	}

	return ahead;

}//登录成功 

int panduan(char choice)

{

	while(1)

	{	

		fflush(stdin);

		choice=getchar();

		if(choice == 'y'|| choice =='Y')

		return 1;

		else if(choice == 'n'||choice == 'N')

		return 0;

		while(getchar() != '\n')    

			continue;

		printf("输入错误！请重新输入您的选择:\n");

	}

}

int back(char *a)

{

	if(strlen(a)==1)

	{

		if(a[0]>='0'&&a[0]<='9')

		return ((int)a[0]-48);

	}

	else

	    return 10;

}

 

void print1()

{

	int i;

	system("cls");

	printf("\n\n\n\n");

	printf("\t\t\t\t|******************************|\n");

	printf("\t\t\t\t||****************************||\n");

	printf("\t\t\t\t|||                          |||\n");

	printf("\t\t\t\t|||   欢迎来到影院管理系统   |||\n");

	printf("\t\t\t\t|||                          |||\n");

	printf("\t\t\t\t||****************************||\n");

	printf("\t\t\t\t|******************************|\n");

	printf("\n\t\t\t\t系统开始启动.........\n");

  	printf("===================================================================================================\r");

	for(i=1;i<100;i++) 

  {

   Sleep(40);

   printf(">");

	}

}

void print()        //主界面 

{

	system("cls");

	printf("\t\t\t|*******************************|\n");

	printf("\t\t\t|  欢迎来到影院管理系统(主菜单) |\n");

	printf("\t\t\t|*******************************|\n");

	printf("\t\t\t|          1.插入信息           |\n");

	printf("\t\t\t|          2.查看信息           |\n");

	printf("\t\t\t|          3.查询信息           |\n");

	printf("\t\t\t|          4.修改信息           |\n");

	printf("\t\t\t|          5.排序信息           |\n");

	printf("\t\t\t|          6.删除信息           |\n");

	printf("\t\t\t|-------------------------------|\n");

	printf("\t\t\t|-------------------------------|\n");

	printf("\t\t\t|          0.退出程序           |\n");

	printf("\t\t\t|===============================|\n");

}

void print2()

{

	system("cls");

	printf("\n\n\n\n");

	printf("\t\t\t|******************************|\n");

	printf("\t\t\t||****************************||\n");

	printf("\t\t\t|||                          |||\n");

	printf("\t\t\t|||        谢谢使用          |||\n");

	printf("\t\t\t|||                          |||\n");

	printf("\t\t\t||****************************||\n");

	printf("\t\t\t|******************************|\n");

	Sleep(2000);

}

void print3()

{

		system("cls");

	printf("\t\t\t|*******************************|\n");

	printf("\t\t\t|  欢迎来到影院购票系统(主菜单) |\n");

	printf("\t\t\t|*******************************|\n");

	printf("\t\t\t|          1.主页信息           |\n");

	printf("\t\t\t|          2.查询信息           |\n");

	printf("\t\t\t|          3.排序信息           |\n");

	printf("\t\t\t|          4.打印报表           |\n");

	printf("\t\t\t|-------------------------------|\n");

	printf("\t\t\t|-------------------------------|\n");

	printf("\t\t\t|          0.退出程序           |\n");

	printf("\t\t\t|===============================|\n");

}

/*******************查询模块********************/ 

pticket searchmenu(pticket phead)     //查询子系统菜单 

{

	fflush(stdin);

	system("cls");

	int bk;

	while(1)

	{

		char P[200];

		system("cls");

	   	printf("\t\t\t|*******************************|\n");

	   	printf("\t\t\t|        查询子系统菜单         |\n");

	   	printf("\t\t\t|*******************************|\n");

		printf("\t\t\t|         1.按影院查询          |\n");

		printf("\t\t\t|         2.按电影查找          |\n"); 

		printf("\t\t\t|         3.按价格区间查找      |\n"); 

		printf("\t\t\t|-------------------------------|\n");

		printf("\t\t\t|         0.返回上一层          |\n");

		printf("\t\t\t|*******************************|\n\n");

		printf("请输入指令:");

		scanf("%s",P);

		bk=back(P);

		switch(bk)

		{

			case 1:

			    {

			    	phead=search1(phead);//按影院查询 

			    	break;

			    }

			case 2:

				{

					phead=search2(phead);//按电影查询 

					break;

				}

			case 3:{

				phead=search3(phead);//按价格区间查询 

				break;

			} 

			case 0:break;

			default:printf("输入错误！请重新输入\n");

					system("pause");

					break;

		}

		if(bk==0)

		break;

	}

	return phead;

}

pticket search1(pticket phead)          //影院查询 

{

	system("cls");

	char cinema1[30],choice;

	pticket p;

	int flag=0;

	char q;

	p=(pticket)malloc(sizeof(ticket));

	while(1)

	{

		system("cls");

		printf("\n\n\n\t\t\t请输入影院名称:"); 

		scanf("%s",cinema1);

		if(strlen(cinema1)>=30)

		{

			system("cls");

			printf("**************\n");

			printf("请输入正确的名字!\n");

			printf("**************\n");

			Sleep(1000);

		}

		else

		break;

	}

	while(1)

	{

		system("cls");

		if(phead->next==NULL)

		{

			printf("\n\n\n\t\t\t没有信息!\n");

			system("pause");

			break;

		}

		p=phead->next;

		print_stu2();

    	do

    	{

			if(strcmp(p->cinema,cinema1)==0)

			{	

				printf("   %-4s     ",p->number);

				printf("%-12s  ",p->name);

				printf("%-16s",p->cinema);

				printf("  %4d     ",p->time);

				printf("%.2lf   ",p->price);

				printf("  %.1lf   ",p->grade);

				printf("\n");

				flag=1;

				}

				p=p->next;

		}while(p!=NULL);

		if(flag==0)

		{

			printf("不存在的！\n");

		}

		printf("是否继续查找?（Y or N）");

		q=getchar();

		if(panduan(q)==1)

		{

			while(1)

			{

				system("cls");

				printf("\n\n\n\t\t\t请输入影院名称:"); 

				scanf("%s",cinema1);

				if(strlen(cinema1)>=30)

				{

					system("cls");

					printf("**************\n");

					printf("请输入正确的名字!\n");

					printf("**************\n");

					Sleep(1000);

				}

				else

					break;

			}

		}

		else if(panduan(choice)==0)

			break;	

	}

	return phead;	

}

pticket search2(pticket phead)         //按电影名称查询 

{

 	system("cls");

	char name1[30],choice;

	pticket p;

	int flag=0;

	char q;

	while(1)

	{

		system("cls");

		printf("\n\n\n\t\t\t请输入电影名称:"); 

		scanf("%s",name1);

		if(strlen(name1)>=30)

		{

			system("cls");

			printf("**************\n");

			printf("请输入正确的名字!\n");

			printf("**************\n");

			Sleep(1000);

		}

		else

		break;

	}

	while(1)

	{

		system("cls");

		if(phead->next==NULL)

		{

			printf("没有信息!\n");

			system("pause");

			break;

		}

		p=phead->next;

		print_stu2();

    

	 	do{		

		if(strcmp(p->name,name1)==0)

		{

			printf("   %-4s     ",p->number);

			printf("%-12s  ",p->name);

			printf("%-16s",p->cinema);

			printf("  %4d     ",p->time);

			printf("%.2lf   ",p->price);

			printf("  %.1lf   ",p->grade);

			printf("\n");

			flag=1;

		}

			p=p->next;

		}while(p!=NULL);

		if(flag==0)

		{

			printf("不存在的！\n");

			

		}

		printf("是否继续查找?（Y or N）\n");

		q=getchar();

		if(panduan(q)==1)

		{

			while(1)

			{

				system("cls");

				printf("请输入电影名称:"); 

				scanf("%s",name1);

				if(strlen(name1)>=30)

				{

					system("cls");

					printf("**************\n");

					printf("请输入正确的名字!\n");

					printf("**************\n");

					Sleep(1000);

				}

				else

					break;

			}

		}

		else if(panduan(choice)==0)

			break;	

	

}

	return phead;	

} 

pticket search3(pticket phead)         //按价格区间名称查询 

{

 	system("cls");

 	int count=0;

	char choice;

	float x,y;

	pticket p;

	int flag=0;

	char q;

	loop2: 

		system("cls");

		printf("\n\n\n\t\t\t请输入价格下限:"); 

		scanf("%f",&x);

		printf("\n\t\t\t请输入价格上限：");

		scanf("%f",&y);

		while(1)

		{

			

		system("cls");

		if(phead->next==NULL)

		{

			printf("没有信息!\n");

			system("pause");

			break;

		}

		p=phead->next;

		print_stu2();

    

	 	do{		

		if(p->price>x&&p->price<y)

		{

			printf("   %-4s     ",p->number);

			printf("%-12s  ",p->name);

			printf("%-16s",p->cinema);

			printf("  %4d     ",p->time);

			printf("%.2lf   ",p->price);

			printf("  %.1lf   ",p->grade);

			printf("\n");

			count++;

			flag=1;

		}

			p=p->next;

		}while(p!=NULL);

		printf("\t\t\t此价格区间内的电影共有%d场\n",count);

		if(flag==0)

		{

			printf("不存在的！\n");

			

		}

		system("pause");

		printf("是否继续查找?（Y or N）\n");

		q=getchar();

		if(panduan(q)==1)

		{

			count=0;

			goto loop2;

		}

		else if(panduan(choice)==0)

			break;	

	}

	return phead;	

} 

/******************排序模块*******************/ 

pticket sortmenu(pticket phead)     //排序子系统菜单

{

	fflush(stdin);

	system("cls");

	int bk;

	while(1)

	{

		system("cls");

		char P[200];

		printf("\t\t\t|*******************************|\n");

		printf("\t\t\t|        排序子系统菜单         |\n");

		printf("\t\t\t|*******************************|\n");

		printf("\t\t\t|         1.按价格排序          |\n");

		printf("\t\t\t|         2.按时长排序          |\n");

		printf("\t\t\t|         3.按评分排序          |\n");

		printf("\t\t\t|-------------------------------|\n");

		printf("\t\t\t|         0.返回上一层          |\n");

		printf("\t\t\t|*******************************|\n\n");

		printf("请输入指令:");

		scanf("%s",P);

		bk=back(P);

		printf("%d",bk);

		switch(bk)

		{

			case 1:phead=sort1(phead);//按价格排序 

				   break;

			case 2:phead=sort2(phead);//按时长排序 

				   break;

			case 3:phead=sort3(phead);// 按评分排序 

				   break;

			case 0:break;

			default:printf("输入错误，重新输入！");

					Sleep(1000);

					system("cls");

					break; 

	    }

	    if(bk==0)

	    break;

    }

    Save_Stu(phead);

	return phead;

}

pticket sort(pticket phead) 

{

	pticket pTemp,pj,pj_f,pj_b;

	int i,j,flag; 

    for(i=0;i<iCount;i++)

	 for(j=0,flag=0,pj=phead;j<iCount-1-i;j++)

	 {

	 	if(flag==0)

	 	{

	 		pj_f=pj;

	 		pj=pj->next;

	 		pj_b=pj->next;

		 }

		if(flag==1)

		{

			pj_f=pj_f->next;

			pj_b=pj->next;

		}

		flag=0;

		if(pj->price>pj_b->price)

		{

			pTemp=pj->next;

			pj->next=pj_b->next;

			pj_b->next=pTemp;

			

			pTemp=pj_f->next;

			pj_f->next=pj_b->next;

			pj_b->next=pTemp;

			flag=1;

		}

	 }

	 return phead;

}

pticket sort22(pticket phead) 

{

	pticket pTemp,pj,pj_f,pj_b;

	int i,j,flag; 

    for(i=0;i<iCount;i++)

	 for(j=0,flag=0,pj=phead;j<iCount-1-i;j++)

	 {

	 	if(flag==0)

	 	{

	 		pj_f=pj;

	 		pj=pj->next;

	 		pj_b=pj->next;

		 }

		if(flag==1)

		{

			pj_f=pj_f->next;

			pj_b=pj->next;

		}

		flag=0;

		if(pj->time<pj_b->time)

		{

			pTemp=pj->next;

			pj->next=pj_b->next;

			pj_b->next=pTemp;

			

			pTemp=pj_f->next;

			pj_f->next=pj_b->next;

			pj_b->next=pTemp;

			flag=1;

		}

	 }

	 return phead;

}

pticket sort11(pticket phead) 

{

	pticket pTemp,pj,pj_f,pj_b;

	int i,j,flag; 

    for(i=0;i<iCount;i++)

	 for(j=0,flag=0,pj=phead;j<iCount-1-i;j++)

	 {

	 	if(flag==0)

	 	{

	 		pj_f=pj;

	 		pj=pj->next;

	 		pj_b=pj->next;

		 }

		if(flag==1)

		{

			pj_f=pj_f->next;

			pj_b=pj->next;

		}

		flag=0;

		if(pj->grade<pj_b->grade)

		{

			pTemp=pj->next;

			pj->next=pj_b->next;

			pj_b->next=pTemp;

			

			pTemp=pj_f->next;

			pj_f->next=pj_b->next;

			pj_b->next=pTemp;

			flag=1;

		}

	 }

	 return phead;

}

pticket sort1(pticket phead)        //按价格排序 

{

	system("cls");

	if(phead->next==NULL)

		{

			printf("没有信息!\n");

			Sleep(1000);

			return phead;

		}

	sort(phead);

	print_stu1(phead);

	return phead; 

}       

pticket sort2(pticket phead)        //按时长排序 

{

	system("cls");

	if(phead->next==NULL)

		{

			printf("没有信息!\n");

			Sleep(1000);

			return phead;

		}

	sort22(phead);

	print_stu1(phead);

	return phead;

}

pticket sort3(pticket phead)        //评分排序 

{

	system("cls");

	if(phead->next==NULL)

		{

			printf("没有信息!\n");

			Sleep(1000);

			return phead;

		}

	sort11(phead);

	print_stu1(phead);

	return phead;

}

 

/********************增加模块**********************/ 

pticket Insert(pticket phead)

{

	system("cls");

	pticket pNew,p=phead;

	/*if(phead->next==NULL)

	{

		printf("无信息!");

		Sleep(1000);

		return phead;

	}*/

	char choice;

	while(p->next!=NULL)

	p=p->next;

    do

    {

    	pNew=(pticket)malloc(sizeof(ticket));

		printf("请输入序号:");

		scanf("%s",pNew->number);

		printf("请输入名称:");

		scanf("%s",pNew->name);

		printf("请输入影院:"); 

		scanf("%s",&pNew->cinema);

		printf("请输入时长:");

		scanf("%d",&pNew->time);

		printf("请输入价格:");

		scanf("%lf",&pNew->price);

		printf("请输入评分:");

		scanf("%lf",&pNew->grade);

    	p->next=pNew;

    	p=pNew;

    	p->next=NULL;

    	iCount++;

    	printf("是否继续添加信息(Y or N):");

		choice=getchar();

	}while(panduan(choice)==1);

    printf("已增加电影信息.\n");

	Sleep(1000);

	Save_Stu(phead);    

	return phead;

}

/*****************输出模块******************/ 

void print_stu1(pticket phead)

{

	system("cls");

	if(phead->next==NULL)

		{

			printf("没有信息!\n");

			Sleep(1000);

			return ;

		}

	print_stu2();

	pticket p;

	p=phead->next;

	while(p != NULL)

	{

		printf("   %-4s     ",p->number);

		printf("%-12s  ",p->name);

		printf("%-16s",p->cinema);

		printf("  %4d     ",p->time);

		printf("%.2lf   ",p->price);

		printf("  %.1lf   ",p->grade);

		printf("\n");

		p=p->next;

	}

    system("pause");

}

void print_stu2()

{

	printf("信息如下:\n");

	printf("-----------------------------------------------------------------------\n");

	printf("****序号******名称*************影院**********时间*****价格*****评分****\n");

	printf("-----------------------------------------------------------------------\n");

} 

void print_stu3()

{

	printf("\t\t\t价格评分报表如下\n"); 

	printf("-----------------------------------------------------------------------\n");

	printf("*********名称******************价格*******************评分*************\n");

	printf("-----------------------------------------------------------------------\n");

	

}

void print_stu4(pticket phead)

{

	system("cls");

	if(phead->next==NULL)

		{

			printf("没有信息!\n");

			Sleep(1000);

			return ;

		}

	print_stu3();

	pticket p;

	p=phead->next;

	while(p != NULL)

	{

		printf("\t%-20s    ",p->name);

		printf("%.2f\t\t\t",p->price);

		printf("  %.1lf   ",p->grade);

		printf("\n");

		p=p->next;

	}

    system("pause");

}

/*****************保存模块***************/ 

void Save_Stu(pticket phead)                    //定义保存函数

{

	system("cls");

    FILE *fp;                            

    if((fp=fopen("e:\\课设\\Student", "wt"))==NULL)

    {

       printf("不能打开文件\n");

       exit(1);

    }

    pticket p;

    p=phead->next;

    while(p!=NULL)

    {

        fprintf(fp,"%s %s %s %d %lf %lf ",

		 p->number,p->name,p->cinema,p->time,p->price,p->grade);  //把内存中的文件输入到硬盘中

        p=p->next;

    }

    fclose(fp);                   //关闭文件

    //printf("文件已保存\n");     //成功保存，显示提示

    Sleep(1000);

}

/******************读取模块**********************/ 

pticket router_Stu(pticket phead)

{

	system("cls");

	FILE *fp;

	int m=0;

	if((fp=fopen("e:\\课设\\Student", "rw"))==NULL)

	{

		printf("读取失败!");

		return;

	 }

	pticket p1,p2;

	

	p1=(pticket)malloc(sizeof(ticket));

	while(fscanf(fp,"%s %s %s %d %lf %lf ",

		 &p1->number, &p1->name, &p1->cinema,&p1->time,&p1->price,&p1->grade)==6)

	{

		m=m+1;

		if(m==1)

		{

			phead->next=p1;

			p2=p1;

			p2->next = NULL;

		}

		else

		{

			p2->next=p1;

			p2=p1;

			p2->next=NULL;

		}

		p1=(pticket)malloc(sizeof(ticket));

	}

	fclose(fp);

	//printf("读取成功！");

	iCount=m;

	//Sleep(1000);

	return phead;

} 

/******************删除模块**********************/ 

pticket delete_Stu(pticket phead)

{

	system("cls");

	if(phead->next==NULL)

	{

		printf("\n\n\n\n\n\t\t\t\t没有可删除的信息!\n");

		system("pause");

		return phead;

	}

	char name1[30];

	pticket pTemp,p;

	printf("\n\n\n\n\t\t\t\t输入即将下线的电影名称:");

	scanf("%s",name1);

	pTemp=phead;

	while(strcmp(pTemp->name,name1)!=0&&pTemp->next!=NULL)

	{

		p=pTemp; 

		pTemp=pTemp->next;

	}

	if(strcmp(pTemp->name,name1)==0)

	{

		if(p!=phead)

		{

			p->next=pTemp->next;

		}

		else

		{

			phead=pTemp->next;

		}

		printf("已删除");

		system("pause");

	}

	else

	{

		printf("没找到");

		Sleep(1000);

	}

	getchar();

	Save_Stu(phead);

	return phead;

}

/********************修改*******************/

pticket revise(pticket phead)

{

	system("cls");

	char P[200];

	int bk; 

	char name[30];

	pticket pTemp;

	if(phead->next==NULL)

	{

		printf("没有可修改的信息!\n");

		system("pause");

		return phead;

	}

	pTemp=phead->next;

	printf("\n\n\n\n\t\t\t请输入你要修改的电影名称:");

	scanf("%s",name);

	while(strcmp(pTemp->name,name)!=0&&pTemp->next!=NULL)

	{

		pTemp=pTemp->next;

	}

	if(strcmp(pTemp->name,name)==0)

	{

		while(1)

		{

			system("cls");

			printf("\t\t\t请输入你要修改的信息:\n");

			printf("\t\t\t********************************\t\t\t\n");

			printf("\t\t\t   1.修改代码      2.修改名称   \t\t\t\n");

			printf("\t\t\t   3.修改影院      4.修改时长   \t\t\t\n");

			printf("\t\t\t   5.修改价格      6.修改评分   \t\t\t\n");

			printf("\t\t\t          0.返回上一层          \t\t\t\n");

			printf("\t\t\t********************************\t\t\t\n");

			printf("请输入您的选择:");

			scanf("%s",P);

			bk=back(P);

			switch(bk)

			{

				case 1:{

						system("cls");

			       		printf("请输入新代码:");

			       		scanf("%s",pTemp->number);

				   		system("cls");

				   		printf("修改成功!");

				   		Sleep(1000);

				   		break;

				   		}

				case 2:{

						system("cls");

						printf("请输入新的名称:");

						scanf("%s",pTemp->name);

						system("cls");

						printf("修改成功!");

						Sleep(1000);

				    	break;

			       		}

				case 3:{

						system("cls");

						printf("请输入新的影院:");

						scanf("%s",&pTemp->cinema);

			       		printf("请输入正确的影院:");

			       		scanf("%s",&pTemp->cinema);

					   	

						system("cls");

						printf("修改成功!");

						Sleep(1000);

				    	break;

			       		}

				case 4:{

						system("cls");

						printf("请输入新的时长:");

						getchar();

						scanf("%d",&pTemp->time);

						system("cls");

						printf("修改成功!");

						Sleep(1000);

				    	break;

			       		}

				case 5:{

						system("cls");

						printf("请输入新的价格：");

						scanf("%lf",&pTemp->price);

						system("cls");

						printf("修改成功!");

						Sleep(1000);

				    	break;

			       		}

				case 6:{

						system("cls");

						printf("请输入新的评分:");

						scanf("%lf",&pTemp->grade);

						system("cls");

						printf("修改成功!");

						Sleep(1000);

				    	break;

			       		}

				case 0:break;

				default:printf("输入错误,请重新输入");

						system("pause");

			}

			if(bk==0)

			break;

	   }

	   Save_Stu(phead);

	   return phead;

	}

	else 

	{

		printf("无该电影信息!");

		Sleep(1000);

		return phead;

	}

}

void menu1()

{

	pticket phead;

	phead = (pticket)malloc(sizeof(ticket));

	phead->next = NULL;

	router_Stu(phead); 

	char P,a[200];

	char choice; 

	int bk;

	while(1)

	{

		system("cls");

		print3();

		fflush(stdin);

		printf("请输入指令:");

		scanf("%s",a);

		bk=back(a);

		switch(bk)

		{

			case 1: {print_stu1(phead);  //查看 

			       system("cls");

			       break;}

			case 2:{phead=searchmenu(phead);   //查找 

			       system("cls");

			        break;}

			case 3:{phead=sortmenu(phead);    //排序 

				   system("cls");

			        break;}

			case 4:{

				print_stu4(phead);

				system("cls");//打印报表 

				break;

			}

			case 0:{

    				print2();

    				exit(1);

			       	}

		    default:{printf("输入错误！请重新输入\n");

		    		system("pause");}

		}

	}

}

void meun()

{

	pticket phead;

	phead = (pticket)malloc(sizeof(ticket));

	phead->next = NULL;

	router_Stu(phead); 

	char P,a[200];

	char choice; 

	int bk;

	while(1)

	{

		system("cls");

		print();

		fflush(stdin);

		printf("请输入指令:");

		scanf("%s",a);

		bk=back(a);

		switch(bk)

		{

		    case 1:{phead=Insert(phead);     //插入 

				   system("cls");

				 	 break;}

			case 2:{print_stu1(phead);  //查看 

			       system("cls");

			       break;}

			case 3:{phead=searchmenu(phead);   //查找 

			       system("cls");

			        break;}

			case 4:{phead=revise(phead);      // 修改 

			       system("cls");

			       break;}

			case 5:{phead=sortmenu(phead);    //排序 

				   system("cls");

			        break;}

			case 6:{phead=delete_Stu(phead); //删除 

			       system("cls");

			       break;}

		    case 0:{

    				print2();

					exit(1);

			       	}

		    default:{printf("输入错误！请重新输入\n");

		    		system("pause");}

		 }

	}

	free(phead);

}

void main()               //主函数 

{

	system("color 3A");

	print1();

	login_acc();

}

 

 

pticket Create(pticket pHead)            //创建链表  

{

    fflush(stdin);

    system("cls"); 

    char choice;

    while(1)

	{ 

    	printf("确定重新输入所有信息麽？\n如果重新输入，之前所有信息会被删除！\n请谨慎选择！（Y or N）\n");

    	if(panduan(choice)==1)

    	break;

    	else

    	return pHead;

	}

	pticket pNew,pEnd;

	iCount=0;

	fflush(stdin);

	pEnd=pHead;

	do         

	{

		pNew=(pticket)malloc(sizeof(ticket));

		if(pNew==NULL)

			return pHead;

		printf("请输入代码:");

	    scanf("%s",pNew->number);

		printf("请输入名称:");

		scanf("%s",pNew->name);

		printf("请输入影院:"); 

		scanf("%s",&pNew->cinema);

		printf("请输入时长:");

		scanf("%d",&pNew->time);

		printf("请输入价格:");

		scanf("%lf",&pNew->price);

		printf("请输入评分:");

		scanf("%lf",&pNew->grade);

		pEnd->next=pNew;                  

		pEnd=pNew;

		iCount++;

		fflush(stdin);

		printf("是否继续? Y or N\n"); 

		choice=getchar();

		getchar();

		while(choice!='y'&&choice!='Y'&&choice!='n'&&choice!='N')

		{

			printf("输入错误！请重新输入您的选择:\n");

		  	choice=getchar();

		  	getchar();

		}

		getchar();

	}while(choice=='y'||choice=='Y');

	pEnd->next=NULL;

	system("cls");

	return pHead;

}

 

