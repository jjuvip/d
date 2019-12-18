#include"tree.h"
#include<malloc.h>
 void main(){
bintree root;
printf("input the tree as preorder:");
createbintree(&root);
printf("\n中序遍历的结果是:");
inorder1(root);
		     }
void push(seqstack *s, bintree t){
 (s -> data)[s -> top] = t;
 s -> top ++;
}

bintree pop(seqstack *s){
 if (s -> top != 0){
  s -> top --;
  return  (s -> data)[s -> top];
 }
 else
  return NULL;
}

void createbintree(bintree *t){
 char ch;
 if ((ch = getchar()) == ' ')
 *t = NULL;
 else{
  *t = (bintnode *)malloc(sizeof(bintnode));
  (*t) -> data = ch;
  createbintree(&(*t) -> lchild);
  createbintree(&(*t) -> rchild);
 }
}
void inorder1(bintree t){
 seqstack s;
 s.top = 0;
 while((t != NULL) || (s.top != 0)){
  while(t){
   push(&s, t);
   t = t -> lchild;
  }
  if (s.top != 0){
   t = pop(&s);
   printf("%c", t -> data);
   t = t -> rchild;
  }
 }
}
