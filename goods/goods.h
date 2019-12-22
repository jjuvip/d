#ifndef  __GOODS_H__
#define __GOODS_H__
#include <stdio.h>	
#include <stdlib.h>           	
#include <string.h>
#define  MAX_GOODS  30        //最大商品数 

void goods_scanf(int n);
void goods_printf(int n);
int goods_find_name(int n);
int goods_find_price(int n);
void goods_sort_price(int n);
void goods_sort_sum(int n);
int goods_alter_price(int n);
int goods_alter_name(int n);
int goods_delete_price(int n);
int goods_delete_name(int n);
//全局数组变量，用于存储商品信息 
char names[MAX_GOODS][50];
int price[MAX_GOODS];
int surpluse[MAX_GOODS];
int add[MAX_GOODS];
int sum[MAX_GOODS];
//以下变量用于商品信息数组排序，作为临时数组 
char temp_names[MAX_GOODS][50];
int temp_price[MAX_GOODS];
int temp_surpluse[MAX_GOODS];
int temp_add[MAX_GOODS];
int temp_sum[MAX_GOODS];
//sort数组存储排好序的价格或名称下标 
int sort[MAX_GOODS];

#endif
