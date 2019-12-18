#ifndef tree_h
#define tree_h
#include<stdio.h>
#include<stdlib.h>
typedef char datatype;//链式储存结构//
typedef struct node{
datatype data; 
struct node *lchild, *rchild;}bintnode;
 typedef bintnode *bintree;
typedef struct stack//栈结构定义//
 { bintree data [100];
     int top;
 }seqstack;

 void push(seqstack *s, bintree t);
bintree pop(seqstack *s);
 void createbintree(bintree *t);
 void inorder1(bintree t);

 #endif 


