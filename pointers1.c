#include <stdio.h>
#include <stdlib.h>

int *memory_created() {

	int *a;

	a=(int *)malloc(sizeof(int));
	return a;
}

int main(void) {
	int *a;
	int *b;

	a=memory_created();
	printf("Value of A is: %p\n", a );
	
	*a=10;
	printf("*A has been assigned the value %d\n",*a);
	
	b=memory_created();
	*b=20;

	printf("*A contains the value %d\n",*a);
	printf("*B contains the value %d\n",*b);

	free(a);
	free(b);

	printf("Value of A is: %p\n", a );
	printf("*A after freeing memory is %d\n",*a);
}