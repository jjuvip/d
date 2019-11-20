#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define random_1(a, b) ((rand()%(b - a)) + a)
#define random_2(a, b) ((rand()%(b - a + 1)) + a)

# define N 500

# define SR 1001

void insort(int arr[],int n)


//int main(int argc, char **argv)
int main()

{
	srand((int)time(NULL));
	int arr[20];

	int i,a,b,j,num;


	for(int i = 0; i < 20; i++)
	{
		arr[i] = random_1(1, 50);
	}
//	for(int i = 0; i < 20; i++)
//	{
//		printf("%d\t", arr[i]);
//	}

//void InsertSort(int R[],int n)
//int i,j;
//	{	
	for(i=2,a++;i<=20;i++,a++)
		if(arr[i]<arr[i-1])
		{
			arr[0]=arr[i];
			for(a++,b++,j=i-1;arr[0]<arr[j];j--,a++,b++)
				arr[j=1]=arr[j];
			arr[j=1]=arr[0];
		}
//	}

	printf("请输入N [2,%d]:",N);

	    insort(&num,2,N);

	        for(i=0;i<num;i++)

			     printf("%d\t",arr[i]=rand()%SR);

	printf("\n直接插入排序:\n比较次数:%10d\t移动次数%10d\n\n",a,b);

	getchar(); 
	return 0; 
}
