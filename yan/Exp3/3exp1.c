# include <stdio.h>  
# include <stdlib.h>
# include <time.h>
# define N 50

int A[N],B[N],C[N],D[N],E[N],F[N],G[N];
int a,aa,b,bb,d,dd,e,ee,f,ff,num;   
long long c,cc;
void charu(int A[],int n);
void xuanzepai(int A[],int n);
void maopao(int A[],int n);  
void Quicksort(int A[],int L,int R);
void shell(int A[],int n);
void GBPX(int S[],int L,int R,int T[]);
int GB(int S[],int L,int M,int R,int T[]);
int gainint(int *p,int min,int max);
int change(int *a,int *b);
void charu(int A[],int n)
{  
    int i,j,temp;  
    for (i=1,a++;i<n;i++,a++)  
        if (A[i]<A[i-1])  
        {   
            temp=A[i];
            for(a++,aa++,j=i-1;j>=0&& A[j]>temp;j--,a++,aa++)
            	A[j+1]=A[j];
            A[j+1]=temp;
        }  
}  
void xuanzepai(int A[],int n) 
{  
    int i,j,k;  
    for(i=0,b++;i<n-1;i++,b++)  
    {  
       k=i;  
       for(j=i+1,b++;j<n;j++,b++)  
          if(A[j]<A[k])  
              { k=j;b++;}  
       if(k!=i)    
       {
          bb+=change(&A[i],&A[k]);   
       }
    }   
} 
void maopao(int A[],int n)  
{  
    int i,j;  
    for (i = n -1 ; i>=0 ;i--)  
    {  
        for (j = 0; j<i; j++)  
        {  
            if(A[j]>A[j+1])
              cc+=change(&A[j],&A[j+1]);
        }  
    }  
}  
void Quicksort(int A[],int L,int R)
{  
    int i=L,j=R,T=A[L];  
    if(L>R)  return;  
    while(i!=j) 
    {  
        while(A[j]>=T&&i<j){j--;d++;}  
        while(A[i]<=T&&i<j){i++;d++;}  
        if(i<j)dd+=change(&A[i],&A[j]);   
    }  
    if(L!=i)
        dd+=change(&A[L],&A[i]);       
    Quicksort(A,L,i-1);          
    Quicksort(A,i+1,R);           
}  
void shell(int A[],int n) 
{
	int i,j,k;
	for(k=n>>1,e++;k>0;k=k>>1,e++)
	{
		for(i=k,e++;i<n;i++,e++)
		{
			for(j=i-k,e++;j>=0;j-=k,e++)
			    if(A[j]>A[j+k])
			       ee+=change(&A[j],&A[j+k]);
		}
	}
}
int change(int *a,int *b) 
{  
    int c=*a;  
    *a=*b;  
    *b=c;  
    return 0;
}  
int gainint(int *p,int min,int max)         
{	scanf("%d",p);
    return *p; 
}
int main(int argc,char **argv)
{    
    int i,t,g; 
	srand((int)time(NULL));
	printf("请输入N [2,%d]:",N);
	gainint(&num,2,N);
    	for(g=0;g<6;g++){
	printf("第%d次排序：\n\n",g+1);
	for(i=0;i<num;i++)
	printf("%d\t",A[i]=B[i]=C[i]=D[i]=E[i]=F[i]=rand()%50);
	printf("\n排序算法\t比较次数\t移动次数\n");
	charu(A,num);
	printf("直接插入\t%-10d\t%-10d\n",a,aa);
	xuanzepai(B,num);
	printf("简单选择\t%-10d\t%-10d\n",b+bb/3,bb);
	c=(num-1)*num/2;
	maopao(C,num); 
	printf("冒泡排序\t%-10lld\t%-10lld\n",c+cc/3,cc);
	Quicksort(D,0,num-1);
	printf("快速排序\t%-10d\t%-10d\n",d+dd/3,dd);
		}
    return 0;  
}  

