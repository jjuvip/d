#include "goods.h"
//循环全局变量 
int i, j;
//main主函数
int main(void)
{    
int choice,n;    
while (1)    
{
        printf("\t*******************************************   \n");
        printf("\t*       自动售货机后台管理系统            *   \n");
        printf("\t*     [1]  输入商品信息                   *   \n");
        printf("\t*     [2]  输出所有商品信息               *   \n");
        printf("\t*     [3]  按价格查找某个商品信息         *   \n");
        printf("\t*     [4]  按名称查找某个商品信息         *   \n");
        printf("\t*     [5]  按价格对商品排序               *   \n");
        printf("\t*     [6]  按总库存对商品排序             *   \n");
        printf("\t*     [7]  按价格修改某个商品信息         *   \n");
        printf("\t*     [8]  按名称修改某个商品信息         *   \n");
        printf("\t*     [9]  按价格删除某个商品信息         *   \n");
        printf("\t*     [10] 按名称删除某个商品信息         *   \n");
        printf("\t*     [0]  退出程序                       *   \n");
        printf("\t*******************************************   \n");  
        printf("      \t请输入您的选择（0 - 10）:");           
        scanf("%d",&choice);

        switch (choice)
        {
        case 1://录入;
            printf("请输入录入的商品个数： ");
            scanf("%d",&n); 
            goods_scanf(n);
            break;
        case 2://输出;
            goods_printf(n);
            break;
        case 3://根据价格查找
            goods_find_price(n);
            break;
        case 4://根据名称查找
            goods_find_name(n);
            break;
        case 5://按价格排序
            goods_sort_price(n);
            break;
        case 6://按名称排序 
            goods_sort_sum(n);
            break;
        case 7://按价格修改 
            goods_alter_price(n);
            break;
        case 8://按名称修改 
            goods_alter_name(n);
            break;
        case 9://按价格删除 
            goods_delete_price(n);
            n--;
            break;
        case 10://按名称删除 
            goods_delete_name(n);
            n--;
            break;
        case 0://退出程序 
            printf("退出程序\n");
            printf("程序结束，谢谢使用!\n");
            exit(0);
        default:
            printf("您输入的菜单有误。请重新输入！\n");
        }

    }
    return 0;
}

//1.输入信息
void goods_scanf(int n)
{
    for (i = 0; i<n; ++i)
    {
        printf("\n请输入第%d个商品的信息:\n", i + 1);
        printf("\n名称:");
        scanf("%s", names[i]);
        printf("\n价格:");
        scanf("%d", &price[i]);
        printf("\n当前余量:");
        scanf("%d", &surpluse[i]);
        printf("\n添加货量:");
        scanf("%d", &add[i]);
        //计算总库存
        sum[i] = surpluse[i] + add[i] ;
    }
}

//2.输出信息        
void goods_printf(int n)
{

    printf("\t名称\t价格\t当前余量\t添加货量\t总库存\n");
    printf("\t------------------------------------------------------\n");
    for (i = 0; i<n; ++i)
    {
        printf("\t%s\t %d\t %d\t\t %d\t\t %d\t\n",names[i], price[i], surpluse[i], add[i], sum[i]);
    }
    printf("\t------------------------------------------------------\n");
}

//3.按价格查找
int goods_find_price(int n)
{
    int prices;
    int result;
    printf("请输入待查找的商品价格:");
    scanf("%d",&prices);
    result= -1;
    for (i = 0; i<n; ++i)
    {
        if (prices == price[i])
        {
            result = i;
            break;
        }
    }
    //最后判断q值
    if (result == -1)
    {
        printf("没有该商品信息!\n");
        return 0;
    }
    //打印出查找结果!
    else
    {
        printf("\t名称\t价格\t当前余量\t添加货量\t总库存\n");
        printf("\t------------------------------------------------------\n");
        printf("\t%s\t %d\t %d\t\t %d\t\t %d\t\n",names[result],price[result],surpluse[result],add[result],sum[result]);
        printf("\t------------------------------------------------------\n");
        printf("\n");
    }
    return 1;
}

//4.用名称查找商品
int goods_find_name(int n)
{
    char name[200];
    int result;
    printf("请输入待查找的商品名称:");
    scanf("%s", name);
    result = -1;
    for (i = 0; i<n; ++i)
    {
        if (strcmp(name, names[i]) == 0)
        {
            result = i;
            break;
        }
    }
    if (result == -1)
    {//未找到结果
        printf("没有该商品信息!\n");
        return 0;
    }
    else//找到结果
    {
        printf("\t名称\t价格\t当前余量\t添加货量\t总库存\n");
        printf("\t------------------------------------------------------\n");
        printf("\t%s\t %d\t %d\t\t %d\t\t %d\t\n", names[result], price[result], surpluse[result], add[result], sum[result]);
        printf("\t------------------------------------------------------\n");
    }
    return 1;
}

//5.按价格排序
void goods_sort_price(int n)
{
    int min,max;
    for(i=0; i<n; ++i)  //复制临时数组 
    {
        temp_price[i] = price[i];
    }

    max = 0;        //查找价格最大值，将其下标存至sort数组的最后一个值中 
    for(j=1; j<n; j++)
    {
        if(temp_price[max]<temp_price[j])
            max = j;
    } 
    sort[n-1] = max;    //sort数组的最后一个数 
    for(i=0; i<n-1; ++i)
    {
        min = i;        //查找价格最小值
        for(j=0; j<n; ++j)
        {
            if(temp_price[min]>temp_price[j])
                min = j;
        } 
        //sort数组记录排序的商品信息的下标 
        sort[i] = min;
        temp_price[min] = temp_price[max];      //利用临时数组将查找过的商品信息的价格设为最大值，排除查找干扰        
    }
    for(i=0; i<n; ++i)  //再复制一次临时数组 
    {
        temp_price[i] = price[i];
        strcpy(temp_names[i],names[i]);
        temp_surpluse[i] = surpluse[i];
        temp_add[i] = add[i];
        temp_sum[i] = sum[i];
    }
    for(i=0; i<n; i++)  //按照下标对原数组进行修改 
    {
        price[i] = temp_price[sort[i]]; 
        strcpy(names[i],temp_names[sort[i]]); 
        surpluse[i] = temp_surpluse[sort[i]]; 
        add[i] = temp_add[sort[i]]; 
        sum[i] = temp_sum[sort[i]];
    }
    printf("排序结果：\n");
    goods_printf(n);
    return ;
}

//6.按总库存排序
void goods_sort_sum(int n)
{
    int min,max;
    for(i=0; i<n; ++i)  //复制临时数组 
    {
        temp_sum[i] = sum[i];
    }

    max = 0;        //查找总库存最大值，将其下标存至sort数组的最后一个值中 
    for(j=1; j<n; j++)
    {
        if(temp_sum[max]<temp_sum[j])
            max = j;
    } 
    sort[n-1] = max;    //sort数组的最后一个数 
    for(i=0; i<n-1; ++i)
    {
        min = i;        //查找总库存最小值
        for(j=0; j<n; ++j)
        {
            if(temp_sum[min]>temp_sum[j])
                min = j;
        } 
        //sort数组记录排序的商品信息的下标 
        sort[i] = min;
        temp_sum[min] = temp_sum[max];      //利用临时数组将查找过的商品信息的总库存设为最大值，排除查找干扰       
    }
    for(i=0; i<n; ++i)  //再复制一次临时数组 
    {
        temp_price[i] = price[i];
        strcpy(temp_names[i],names[i]);
        temp_surpluse[i] = surpluse[i];
        temp_add[i] = add[i];
        temp_sum[i] = sum[i];
    }
    for(i=0; i<n; i++)  //按照下标对原数组进行修改 
    {
        price[i] = temp_price[sort[i]]; 
        strcpy(names[i],temp_names[sort[i]]); 
        surpluse[i] = temp_surpluse[sort[i]]; 
        add[i] = temp_add[sort[i]]; 
        sum[i] = temp_sum[sort[i]];
    }
    printf("排序结果：\n");
    goods_printf(n);
    return ;
}

//7.按价格修改商品信息
int goods_alter_price(int n) 
{
    int prices;
    int result;
    printf("请输入待修改的商品价格:");
    scanf("%d",&prices);
    result= -1;
    for (i = 0; i<n; ++i)
    {
        if (prices == price[i])
        {
            result = i;
            break;
        }
    }
    if (result == -1)
    {
        printf("没有该商品信息!\n");
        return 0;
    }
    else    //修改信息值 
    {
        printf("请重新输入该商品信息：\n");
        printf("名称：\n");
        scanf("%s",names[result]); 
        printf("价格：\n");
        scanf("%d",&price[result]);
        printf("当前余量：\n");
        scanf("%d",&surpluse[result]);
        printf("添加货量：\n");
        scanf("%d",&add[result]);
        sum[result] = surpluse[result] + add[result];
    }
    return 1;
} 

//8.按名称修改商品信息
int goods_alter_name(int n) 
{
    char name[50];
    int result;
    printf("请输入待修改的商品名称:");
    scanf("%s",name);
    result= -1;
    for (i = 0; i<n; ++i)
    {
        if (strcmp(name,names[i])==0)
        {
            result = i;
            break;
        }
    }
    if (result == -1)
    {
        printf("没有该商品信息!\n");
        return 0;
    }
    else        //修改信息值 
    {
        printf("请重新输入该商品信息：\n");
        printf("名称：\n");
        scanf("%s",names[result]); 
        printf("价格：\n");
        scanf("%d",&price[result]);
        printf("当前余量：\n");
        scanf("%d",&surpluse[result]);
        printf("添加货量：\n");
        scanf("%d",&add[result]);
        sum[result] = surpluse[result] + add[result];
    }
    return 1;
} 


//9.按价格删除商品信息
int goods_delete_price(int n) 
{
    int prices;
    int result;
    printf("请输入待删除的商品价格:");
    scanf("%d",&prices);
    result= -1;
    for (i = 0; i<n; ++i)
    {
        if (prices == price[i])
        {
            result = i;
            break;
        }
    }
    if (result == -1)
    {
        printf("没有该商品信息!\n");
        return 0;
    }
    else    //删除当前商品信息即为将数组从result的位置依次前挪一个位置 
    {
        for(i=result; i<n-1; ++i)   //最后在main函数中，要将n的值减1 
        {
            price[i] = price[i+1]; 
            strcpy(names[i],names[i+1]); 
            surpluse[i] = surpluse[i+1]; 
            add[i] = add[i+1]; 
            sum[i] = sum[i+1];
        } 
    }
    return 1;
} 

//10.按名称删除商品信息
int goods_delete_name(int n) 
{
    char name[50];
    int result;
    printf("请输入待删除的商品名称:");
    scanf("%s",name);
    result= -1;
    for (i = 0; i<n; ++i)
    {
        if (strcmp(name,names[i])==0)
        {
            result = i;
            break;
        }
    }
    if (result == -1)
    {
        printf("没有该商品信息!\n");
        return 0;
    }
    else    //删除当前商品信息即为将数组从result的位置依次前挪一个位置 
    {
        for(i=result; i<n-1; ++i)       //最后在main函数中，要将n的值减1 
        {
            price[i] = price[i+1]; 
            strcpy(names[i],names[i+1]); 
            surpluse[i] = surpluse[i+1]; 
            add[i] = add[i+1]; 
            sum[i] = sum[i+1];
        } 
    }
    return 1;
} 

