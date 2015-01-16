#include "febo.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

int fibo(int numberOfTerms,int **arrayOfFibo){
	int firstTerm = 0,secondTerm = 1,i,temp;
	
	*arrayOfFibo = malloc(sizeof(int)*numberOfTerms);	
	
	if(numberOfTerms <= 0 ){
		return 0;
	}

	(*arrayOfFibo)[0]=0;
	(*arrayOfFibo)[1]=1;

	for(i=2;i < numberOfTerms;i++){
		(*arrayOfFibo)[i] = firstTerm+secondTerm;
		temp = secondTerm;
		secondTerm = firstTerm+secondTerm;
		firstTerm = temp;
	};
	return 1;
}

int concat(int *array1, int len_of_array1, int *array2, int len_of_array2, int **result_array){
	int i,j=0;
	
	int totalLength = len_of_array1+len_of_array2;

	*result_array = malloc(sizeof(int)*totalLength);
	
	if(len_of_array1 <= 0 && len_of_array2 <= 0){
		return 0;
	};

	for(i=0;i < len_of_array1;i++){
		(*result_array)[i] = array1[i];
	};

	for(i = len_of_array1;i<totalLength;i++){
		(*result_array)[i] = array2[j];
		j++;
	}
	return 1;
}

int filter(int *array, int length, int threshold, int **result_array){

	int i,j=0;

	*result_array = (int*)malloc(sizeof(int)*length);

	for(i=0;i<length;i++){
		if(array[i] > threshold){
			(*result_array)[j] = array[i];
			j++;
		}
	}
	return 1;
}

int reverse(int *array, int length, int **result_array){
	int i,j=0;
	*result_array = (int *)malloc(sizeof(int)*length);

	for(i=length-1 ;i >=0 ;i--){
		(*result_array)[j]=array[i];
		j++;
	}
	return 1;
}

int slice(int *array,int len_of_array,int start_index, int end_index, int **result_array){
	int i,j=0;
	*result_array = (int *)malloc(sizeof(int));
	if(end_index > len_of_array){
		return 0;
	}
	for(i=start_index;i < end_index;i++){
		(*result_array)[j]=array[i];
		j++;
	};

	return 1;

}

int checkPrime(int num){
	int i,flag = 1,scope=sqrt(num);
	if(num<=1) return 0;
	for(i=2;i<=scope;i++){
	 if(num%i==0)
	 	flag = 0;
	}
	return flag;
}

int primeNumber(int start,int end,int **array){
	int i,j=0,size=0;

	for(i=start;i<=end;i++){
		if(checkPrime(i) == 1){
			size++;
		}
	};

	*array = (int *)malloc(sizeof(int)*size);

	for(i=start;i<=end;i++){
		if(checkPrime(i) == 1){	
		*array[j]=i;
		}
	};
	return size;
}

int my_strcmp(char *str1,char *str2){
	int len1 = strlen(str1),len2 = strlen(str1),i;
	int grater = (len1>len2)?len1:len2;

	for(i=0;i<grater;i++){
		if(str1[i]!=str2[i]){
			return str1[i]-str2[i];
		}
	}
	return 0;
}

int forEach(int *array,int length,int (*fun)(int)){
	int i,flag=1;
	for(i=0;i<length;i++){
		array[i] = (*fun)(array[i]);
	};
	return flag;
}

int char_forEach(char *array,int length,int (*fun)(char)){
	int i,flag=1;;

	for(i=0;i<length;i++){
		if(!(*fun)(array[i])){
			flag=0;
		};
		array[i] = (*fun)(array[i]);
	};
	return flag;
};


int myFilter(int *array, int length, int (*fun)(int), int **result){
	int i,j=0;	
	*result = calloc(length,sizeof(int));	
	
	for(i=0;i<length;i++){
		if((*fun)(array[i])){
			(*result)[j] = array[i];
			j++;
		};
	};
	return j;
};

int floatFilter(float *array, int length, int (*fun)(float), float **result){
	int i,j=0;
	*result = calloc(length,sizeof(int));	
	
	for(i=0;i<length;i++){
		if((*fun)(array[i])){
			(*result)[j] = array[i];
			j++;
		};
	};
	return j;
};

int stringFilter(char **src,int length,int (*fun)(char *),char ***result){
	int i,count=0,predicate;

	*result = calloc(length,sizeof(char*));	

	for(i=0;i<length;i++){
		predicate = (*fun)(src[i]);
		if(predicate){
			(*result)[count] = src[i];
			count++;
		};
	};
	return count;
};

