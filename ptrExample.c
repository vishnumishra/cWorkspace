#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// void assignMemory(int *a){
	// a[0]=23;
	// b[0] = 15;
	// *a = (int*)malloc(sizeof(int)*4);

// printf("%d\n", *a);
	// *a = 12;
// printf("%d\n", **b);
// 	**b = 15;
// }
// int isPrime(int num){
// 	int i,limit = sqrt(num),totalPrime=0;
// 	printf("number is:%d\n",num );
// 	// int arr[] = {2,3,5,7,11,13,17,19,23,31,37,41,43,47,53,59,6110003};
// 	// for(i=0;i<=19;i++){
// 	// 	if(num%arr[i]==0)
// 	// 		return 0;
// 	// }
// 	for(i=2;i<=num;i++) {
// 		if(num%i!=0) {
// 			totalPrime++;
// 			// return 0;
// 		}
// 	}
// 	printf("============%d\n",totalPrime);
// 	return 1;
// }

// int main()
// {
// 	int num;
// 	scanf("%d", &num);
// 	isPrime( num);
	// printf("%d\n",isPrime(num));
/*	int a=26,c,***b,*y,**q,****m;
	y=&a;
	q=&y;
	b=&q;
	// c=b;
	m=&b;

	printf("%d\n",*y );
	printf("%d\n",**q );
	printf("%d\n",*b );
	printf("%d\n",c );
	printf("%d\n",****m );

	return 0;
// };*/

int fabo(int numberOfTerms,int **arrayOfFibo){
	int firstTerm = 0,secondTerm = 1,i,temp;
	
	*arrayOfFibo = malloc(sizeof(int)*numberOfTerms);	
	
	if(numberOfTerms <= 0 ){
		return 0;
	}

	(*arrayOfFibo)[0]=firstTerm;
	(*arrayOfFibo)[1]=secondTerm;

	for(i=2;i < numberOfTerms;i++){
		printf("===========================%d\t%d\t%d\n",i,(firstTerm+secondTerm),temp);
		(*arrayOfFibo)[i] = firstTerm+secondTerm;
		temp = secondTerm;
		secondTerm = firstTerm+secondTerm;
		firstTerm = temp;
	};
	return 1;
};
int main()
{
	int *array,i;
	int n=6;
	for(i=0;i<n;i++){
		printf("valuse of array[%d] is:%d\n",i,array[i]);
	};
	printf("\n\n" );
	fabo(6,&array);
	for(i=0;i<n;i++){

		printf("valuse of array[%d] is:%d\n",i,array[i]);
	};
	return 0;
};