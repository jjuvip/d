#include <stdio.h>  	//直接、起泡、简单、快速、希尔

# include <stdlib.h>

# include <time.h>

# define N 500

# define SR 1001

int A[N];

int a,aa,num;   

void charu(int A[],int n);

void insort(int A[],int n)

{  

    int i,j,temp;  

    for(i=1,a++;i<n;i++,a++)  

        if (A[i]<A[i-1])  

        {   

            temp=A[i];

            for(a++,aa++,j=i-1;j>=0&& A[j]>temp;j--,a++,aa++)

            	A[j+1]=A[j];

            A[j+1]=temp;

        }  

}  

}  
#define random_1(a, b) ((rand()%(b - a)) + a)
#define random_2(a, b) ((rand()%(b - a + 1)) + a)

int main(){    

    int i,t; 

   // srand(time(0));

	srand((int)time(NULL));                                               
	int arr[10];
	for(int i = 0; i < 10; i++){
	arr[i] = random_1(1, 20);
	}
	for(int i = 0; i < 10; i++){
	printf("%d\t", arr[i]);
    }
    printf("请输入N [2,%d]:",N);

    insort(&num,2,N);

    for(i=0;i<num;i++)

     printf("%d\t",A[i]=rand()%SR);

    charu(A,num);

    printf("\n直接插入排序:\n比较次数:%10d\t移动次数%10d\n\n",a,aa);

    
	getchar(); 

    return 0;  

}  


