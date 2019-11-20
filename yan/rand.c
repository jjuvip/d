#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int array[20],*point;
	for(point=array;point<array+20;point++)
	{
	//	*point=srand((int)time(NULL));
		*point=rand()%90+10;
		printf("%4d",*point);
	}

		printf("\n");
		return 0;
}
	

