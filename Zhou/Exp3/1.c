#include <stdio.h>

#include <stdlib.h>

#include <time.h>



#define random_1(a, b) ((rand()%(b - a)) + a)

#define random_2(a, b) ((rand()%(b - a + 1)) + a)



int main(int argc, char **argv)

{

	    srand((int)time(NULL));                                               

	        int arr[10];

		    for(int i = 0; i < 10; i++){

			            arr[i] = random_1(1, 50);

				        }

		        for(int i = 0; i < 10; i++){

				        printf("%d\t", arr[i]);

						if(i==9)

									printf("\n");

						    }




				    return 0;

}
